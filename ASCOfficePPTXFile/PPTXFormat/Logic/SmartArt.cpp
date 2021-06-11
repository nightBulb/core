﻿/*
 * (c) Copyright Ascensio System SIA 2010-2019
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */

#include "SmartArt.h"
#include "../Slide.h"
#include "../SlideLayout.h"
#include "../SlideMaster.h"

#include "../../ASCOfficeDrawingConverter.h"

#include "../../../XlsxSerializerCom/Reader/BinaryWriter.h"

#include "../../../ASCOfficeDocxFile2/DocWrapper/XlsxSerializer.h"
#include "../../../ASCOfficeDocxFile2/DocWrapper/FontProcessor.h"
#include "../../../ASCOfficeDocxFile2/BinWriter/BinWriters.h"

#include "../../../Common/DocxFormat/Source/DocxFormat/Diagram/DiagramData.h"
#include "../../../Common/DocxFormat/Source/DocxFormat/Diagram/DiagramDrawing.h"
#include "../../../Common/DocxFormat/Source/DocxFormat/Diagram/DiagramColors.h"
#include "../../../Common/DocxFormat/Source/DocxFormat/Diagram/DiagramQuickStyle.h"
#include "../../../Common/DocxFormat/Source/DocxFormat/Diagram/DiagramLayout.h"

#include "../../../Common/OfficeFileFormatChecker.h"

#include "../../../OfficeUtils/src/OfficeUtils.h"
namespace PPTX
{
	namespace Logic
	{
		bool SmartArt::LoadDrawing(OOX::IFileContainer* pRels)
		{
			if (m_oDrawing.IsInit())
				return true;

			if (false == id_drawing.IsInit())
			{
				if (id_data.IsInit() == false) return false;
				if (pRels == NULL) return false;

				bool result = false;

				smart_ptr<OOX::File> oFileData = pRels->Find(*id_data);
				OOX::CDiagramData* pDiagramData = dynamic_cast<OOX::CDiagramData*>(oFileData.GetPointer());

				if (pDiagramData)
				{
					result = true; // это smart art ..есть у него drawing или нет - неважно

					if ((pDiagramData->m_oDataModel.IsInit()) & (pDiagramData->m_oDataModel->m_oExtLst.IsInit()))
					{
						for (size_t i = 0; i < pDiagramData->m_oDataModel->m_oExtLst->m_arrExt.size(); i++)
						{
							if (pDiagramData->m_oDataModel->m_oExtLst->m_arrExt[i]->m_oDataModelExt.IsInit())
							{
								id_drawing = pDiagramData->m_oDataModel->m_oExtLst->m_arrExt[i]->m_oDataModelExt->m_oRelId;
								break;
							}
						}
					}
				}
			}
			smart_ptr<OOX::File> oFileDrawing;
			OOX::CDiagramDrawing* pDiagramDrawing = NULL;

			if (id_drawing.IsInit())
			{
				if (parentFileIs<OOX::IFileContainer>()) oFileDrawing = parentFileAs<OOX::IFileContainer>().Find(*id_drawing);
				else if (pRels != NULL) oFileDrawing = pRels->Find(*id_drawing);
			}
			else
			{
				//Monetizing_Innovation.pptx (слайд 13) - diagrams/data1.xml не ссылается на diagrams/drawing1.xml
				//пробуем по тому же пути с номером data.xml - ниже			
			}
			pDiagramDrawing = dynamic_cast<OOX::CDiagramDrawing*>(oFileDrawing.GetPointer());

			if (!pDiagramDrawing)
			{
				smart_ptr<OOX::File> oFileData = pRels->Find(*id_data);
				OOX::CDiagramData* pDiagramData = dynamic_cast<OOX::CDiagramData*>(oFileData.GetPointer());

				if (pDiagramData)
				{
					// easy4cargo1.pptx - слайд 2 - в диаграмме Smart вместо ссылки на drawing.xml ссылка на стороннюю картинку
					OOX::CPath pathDiagramData = pDiagramData->m_strFilename;

					int a1 = (int)pathDiagramData.GetFilename().find(L".");
					std::wstring strId = pathDiagramData.GetFilename().substr(4, pathDiagramData.GetFilename().length() - 8);

					OOX::CPath pathDiagramDrawing = pathDiagramData.GetDirectory() + FILE_SEPARATOR_STR + L"drawing" + strId + L".xml";

					oFileDrawing = smart_ptr<OOX::File>(dynamic_cast<OOX::File*>(new OOX::CDiagramDrawing(NULL, pathDiagramDrawing)));
					if (oFileDrawing.IsInit())
						pDiagramDrawing = dynamic_cast<OOX::CDiagramDrawing*>(oFileDrawing.GetPointer());
				}
			}

			if ((pDiagramDrawing) && (pDiagramDrawing->m_oShapeTree.IsInit()))
			{
				m_oDrawing = pDiagramDrawing->m_oShapeTree;
				FillParentPointersForChilds();

				m_pDrawingContainer = oFileDrawing.smart_dynamic_cast<OOX::IFileContainer>();

				if (!m_oDrawing->grpSpPr.xfrm.IsInit())
					m_oDrawing->grpSpPr.xfrm = new PPTX::Logic::Xfrm;
			}
			else
			{
				//parse pDiagramData !!
			}
			return true;
		}
		void SmartArt::LoadDrawing(NSBinPptxRW::CBinaryFileWriter* pWriter)
		{
			if (m_oDrawing.IsInit())
				return;

			OOX::IFileContainer	& pRelsPPTX = parentFileAs<OOX::IFileContainer>();
			OOX::IFileContainer	* pRels = NULL;

			if (pWriter)
			{
				if (pWriter->m_pCurrentContainer->is_init())
					pRels = pWriter->m_pCurrentContainer->operator ->();
			}

			bool result = LoadDrawing(&pRelsPPTX);
			if (!result)
				result = LoadDrawing(pRels);
		}
		void SmartArt::toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
		{
			OOX::IFileContainer* pRels = pWriter->m_pCurrentContainer->is_init() ? pWriter->m_pCurrentContainer->operator ->() : NULL;

			if (id_data.IsInit())
			{
				smart_ptr<OOX::File> oFileData;

				if (parentFileIs<OOX::IFileContainer>()) oFileData = parentFileAs<OOX::IFileContainer>().Find(*id_data);
				else if (pRels != NULL) oFileData = pRels->Find(*id_data);

				OOX::CDiagramData* pDiagramData = dynamic_cast<OOX::CDiagramData*>(oFileData.GetPointer());

				if (pDiagramData)
				{
					pWriter->StartRecord(0);
					pDiagramData->toPPTY(pWriter);
					pWriter->EndRecord();
				
					if (false == id_drawing.IsInit())
					{
						for (size_t i = 0; ((pDiagramData->m_oDataModel.IsInit()) && (pDiagramData->m_oDataModel->m_oExtLst.IsInit())) && (i < pDiagramData->m_oDataModel->m_oExtLst->m_arrExt.size()); i++)
						{
							if (pDiagramData->m_oDataModel->m_oExtLst->m_arrExt[i]->m_oDataModelExt.IsInit())
							{
								id_drawing = pDiagramData->m_oDataModel->m_oExtLst->m_arrExt[i]->m_oDataModelExt->m_oRelId;
								break;
							}
						}
					}
				}
			}

			if (id_color.IsInit())
			{
				smart_ptr<OOX::File> oFileColors;

				if (parentFileIs<OOX::IFileContainer>())	oFileColors = parentFileAs<OOX::IFileContainer>().Find(*id_color);
				else if (pRels != NULL)						oFileColors = pRels->Find(*id_color);

				OOX::CDiagramColors* pDiagramColors = dynamic_cast<OOX::CDiagramColors*>(oFileColors.GetPointer());

				if (pDiagramColors)
				{
					pWriter->StartRecord(1);
					pDiagramColors->toPPTY(pWriter);
					pWriter->EndRecord();
				}
			}
			if (id_layout.IsInit())
			{
				smart_ptr<OOX::File> oFileLayout;

				if (parentFileIs<OOX::IFileContainer>())	oFileLayout = parentFileAs<OOX::IFileContainer>().Find(*id_layout);
				else if (pRels != NULL)						oFileLayout = pRels->Find(*id_layout);

				OOX::CDiagramLayout* pDiagramLayout = dynamic_cast<OOX::CDiagramLayout*>(oFileLayout.GetPointer());

				if (pDiagramLayout)
				{
					pWriter->StartRecord(2);
					pDiagramLayout->toPPTY(pWriter);
					pWriter->EndRecord();
				}
			}
			if (id_style.IsInit())
			{
				smart_ptr<OOX::File> oFileStyle;

				if (parentFileIs<OOX::IFileContainer>())	oFileStyle = parentFileAs<OOX::IFileContainer>().Find(*id_style);
				else if (pRels != NULL)						oFileStyle = pRels->Find(*id_style);

				OOX::CDiagramQuickStyle* pDiagramStyle = dynamic_cast<OOX::CDiagramQuickStyle*>(oFileStyle.GetPointer());
				if (pDiagramStyle)
				{
					pWriter->StartRecord(3);
					pDiagramStyle->toPPTY(pWriter);
					pWriter->EndRecord();
				}
			}
			if (id_drawing.IsInit())
			{
				smart_ptr<OOX::File> oFileDrawing;
				if (parentFileIs<OOX::IFileContainer>()) oFileDrawing = parentFileAs<OOX::IFileContainer>().Find(*id_drawing);
				else if (pRels != NULL) oFileDrawing = pRels->Find(*id_drawing);

				OOX::CDiagramDrawing* pDiagramDrawing = dynamic_cast<OOX::CDiagramDrawing*>(oFileDrawing.GetPointer());
				if (pDiagramDrawing)
				{
					pWriter->StartRecord(4);
					pDiagramDrawing->toPPTY(pWriter);
					pWriter->EndRecord();
				}			
			}
		}
		void SmartArt::fromPPTY(NSBinPptxRW::CBinaryFileReader* pReader)
		{
			int nCountDiagram = pReader->m_nCountDiagram;
			pReader->m_nCountDiagram++;
			
			std::wstring strDstDiagram = pReader->m_pRels->m_pManager->GetDstDiagram();

			if (strDstDiagram.empty())
			{
				strDstDiagram = pReader->m_pRels->m_pManager->GetDstFolder() + FILE_SEPARATOR_STR + L"diagrams";
				pReader->m_pRels->m_pManager->SetDstCharts(strDstDiagram);
			}
			NSDirectory::CreateDirectory(strDstDiagram);
			NSDirectory::CreateDirectory(strDstDiagram  + FILE_SEPARATOR_STR + L"_rels");
			//--------------------------------------------------------------------------------------------------			
			smart_ptr<OOX::CDiagramData> pDiagramData;

			LONG end = pReader->GetPos() + pReader->GetRecordSize() + 4;

			while (pReader->GetPos() < end)
			{
				BYTE _rec = pReader->GetUChar();

				switch (_rec)
				{
					case 0:
					{
						pReader->SetDstContentRels();
						
						pDiagramData = new OOX::CDiagramData(NULL);
						pDiagramData->m_sOutputFilename = L"data" + std::to_wstring(nCountDiagram) + L".xml";

						pDiagramData->fromPPTY(pReader);						
						
						pReader->SaveDstContentRels(strDstDiagram + FILE_SEPARATOR_STR + L"_rels" + FILE_SEPARATOR_STR + pDiagramData->m_sOutputFilename + L".rels");
					}break;
					case 1:
					{
						smart_ptr<OOX::CDiagramColors> pDiagramColors = new OOX::CDiagramColors(NULL);
						pDiagramColors->m_sOutputFilename = L"colors" + std::to_wstring(nCountDiagram) + L".xml";
						pDiagramColors->fromPPTY(pReader);
						
						pDiagramColors->write(strDstDiagram + FILE_SEPARATOR_STR + pDiagramColors->m_sOutputFilename, pDiagramColors->DefaultDirectory(), *pReader->m_pRels->m_pManager->m_pContentTypes);

						pDiagramColors->m_sOutputFilename = std::wstring(L"diagrams/") + pDiagramColors->m_sOutputFilename;

						unsigned int nRId = pReader->m_pRels->WriteRels(pDiagramColors->type().RelationType(), pDiagramColors->m_sOutputFilename, L"");
						id_color = new OOX::RId(nRId);
					}break;
					case 2:
					{
						smart_ptr<OOX::CDiagramLayout> pDiagramLayout = new OOX::CDiagramLayout(NULL);
						pDiagramLayout->m_sOutputFilename = L"layout" + std::to_wstring(nCountDiagram) + L".xml";
						pDiagramLayout->fromPPTY(pReader);

						pDiagramLayout->write(strDstDiagram + FILE_SEPARATOR_STR + pDiagramLayout->m_sOutputFilename, pDiagramLayout->DefaultDirectory(), *pReader->m_pRels->m_pManager->m_pContentTypes);

						pDiagramLayout->m_sOutputFilename = std::wstring(L"diagrams/") + pDiagramLayout->m_sOutputFilename;

						unsigned int nRId = pReader->m_pRels->WriteRels(pDiagramLayout->type().RelationType(), pDiagramLayout->m_sOutputFilename, L"");
						id_layout = new OOX::RId(nRId);
					}break;
					case 3:
					{
						smart_ptr<OOX::CDiagramQuickStyle> pDiagramStyle = new OOX::CDiagramQuickStyle(NULL);
						pDiagramStyle->m_sOutputFilename = L"quickStyle" + std::to_wstring(nCountDiagram) + L".xml";
						pDiagramStyle->fromPPTY(pReader);
						
						pDiagramStyle->write(strDstDiagram + FILE_SEPARATOR_STR + pDiagramStyle->m_sOutputFilename, pDiagramStyle->DefaultDirectory(), *pReader->m_pRels->m_pManager->m_pContentTypes);

						pDiagramStyle->m_sOutputFilename = std::wstring(L"diagrams/")  + pDiagramStyle->m_sOutputFilename;

						unsigned int nRId = pReader->m_pRels->WriteRels(pDiagramStyle->type().RelationType(), pDiagramStyle->m_sOutputFilename, L"");
						id_style = new OOX::RId(nRId);
					}break;
					case 4:
					{
						pReader->SetDstContentRels();
						
						smart_ptr<OOX::CDiagramDrawing> pDiagramDrawing = new OOX::CDiagramDrawing(NULL);
						pDiagramDrawing->m_sOutputFilename = L"drawing" + std::to_wstring(nCountDiagram) + L".xml";
						pDiagramDrawing->fromPPTY(pReader);
						
						pDiagramDrawing->write(strDstDiagram + FILE_SEPARATOR_STR + pDiagramDrawing->m_sOutputFilename, pDiagramDrawing->DefaultDirectory(), *pReader->m_pRels->m_pManager->m_pContentTypes);
						pReader->SaveDstContentRels(strDstDiagram + FILE_SEPARATOR_STR + L"_rels" + FILE_SEPARATOR_STR + L"drawing" + std::to_wstring(nCountDiagram) + L".xml.rels");
						
						pDiagramDrawing->m_sOutputFilename = std::wstring(L"diagrams/") + pDiagramDrawing->m_sOutputFilename;

						unsigned int nRId = pReader->m_pRels->WriteRels(pDiagramDrawing->type().RelationType(), pDiagramDrawing->m_sOutputFilename, L"");
						id_drawing = new OOX::RId(nRId);
					}break;
					default:
					{
						pReader->SkipRecord();
					}break;
				}
			}
			pReader->Seek(end);
//----------------------------------------------------------------------------
			if (pDiagramData.IsInit())
			{
				if (id_drawing.IsInit() && pDiagramData.IsInit() && pDiagramData->m_oDataModel.IsInit())
				{
					pDiagramData->m_oDataModel->m_oExtLst.Init();
					pDiagramData->m_oDataModel->m_oExtLst->m_arrExt.push_back(new OOX::Drawing::COfficeArtExtension());
					pDiagramData->m_oDataModel->m_oExtLst->m_arrExt[0]->m_oDataModelExt.Init();

					pDiagramData->m_oDataModel->m_oExtLst->m_arrExt[0]->m_oDataModelExt->m_oRelId = id_drawing->ToString();
				}
				pDiagramData->write(strDstDiagram + FILE_SEPARATOR_STR + pDiagramData->m_sOutputFilename, pDiagramData->DefaultDirectory(), *pReader->m_pRels->m_pManager->m_pContentTypes);

				pDiagramData->m_sOutputFilename = std::wstring(L"diagrams/")  + pDiagramData->m_sOutputFilename;
				
				unsigned int nRId = pReader->m_pRels->WriteRels(pDiagramData->type().RelationType(), pDiagramData->m_sOutputFilename, L"");
				id_data = new OOX::RId(nRId);
			}
		}
		std::wstring SmartArt::toXML() const
		{
			if (!id_data.is_init())
				return L"";

			std::wstring strData = L"<dgm:relIds xmlns:dgm=\"http://schemas.openxmlformats.org/drawingml/2006/diagram\"";
			strData += L" xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\"";
			strData += L" r:dm=\"" + id_data->ToString() + L"\"";
			if (id_color.IsInit()) strData += L" r:cs=\"" + id_color->ToString() + L"\"";
			if (id_layout.IsInit()) strData += L" r:lo=\"" + id_layout->ToString() + L"\"";
			if (id_style.IsInit()) strData += L" r:qs=\"" + id_style->ToString() + L"\"";
			strData += L"/>";

			return strData;
		}
		void SmartArt::toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
		{
			pWriter->WriteString(toXML());
		}
		void ChartRec::toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
		{
			OOX::IFileContainer* pRels = NULL;
			if (pWriter->m_pCurrentContainer->is_init())
				pRels = pWriter->m_pCurrentContainer->operator ->();

			smart_ptr<OOX::File> file;
			if(id_data.IsInit())
			{
				if(parentFileIs<OOX::IFileContainer>())	file = parentFileAs<OOX::IFileContainer>().Find(*id_data);
				else if (pRels != NULL)					file = pRels->Find(*id_data);
			}
			smart_ptr<OOX::Spreadsheet::CChartFile> pChart = file.smart_dynamic_cast<OOX::Spreadsheet::CChartFile>();
			smart_ptr<OOX::Spreadsheet::CChartExFile> pChartEx = file.smart_dynamic_cast<OOX::Spreadsheet::CChartExFile>();

			if (false == pChart.IsInit() && false == pChartEx.IsInit()) return;		

	//----------------------------------------------------------------
			std::wstring id;
			if ((pChart.IsInit()) && (pChart->m_oChartSpace.m_externalData) && (pChart->m_oChartSpace.m_externalData->m_id))
				id = *pChart->m_oChartSpace.m_externalData->m_id;
			else if ((pChartEx.IsInit()) && (true == pChartEx->m_oChartSpace.m_chartData.m_externalData.IsInit()))
				id = pChartEx->m_oChartSpace.m_chartData.m_externalData->m_id.get_value_or(L"");
			
			if (false == id.empty())
			{
				smart_ptr<OOX::File> oFile = pChart.IsInit() ? pChart->Find(id) : pChartEx->Find(id);
				smart_ptr<OOX::Media> oMediaFile = oFile.smart_dynamic_cast<OOX::Media>();

				if (oMediaFile.IsInit())
				{
					OOX::CPath oox_file = oMediaFile->filename();
					OOX::CPath embed_folder = oox_file.GetDirectory(true);
					OOX::CPath oox_unpacked = embed_folder + L"Temp_unpacked";
					NSDirectory::CreateDirectory(oox_unpacked.GetPath());

					COfficeUtils oOfficeUtils(NULL);
					oOfficeUtils.ExtractToDirectory(oox_file.GetPath(), oox_unpacked.GetPath(), NULL, 0);

					COfficeFileFormatChecker office_checker;
					office_checker.isOOXFormatFile(oox_file.GetPath());

					if (office_checker.nFileType == AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX ||
						office_checker.nFileType == AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSM)
					{
						DocWrapper::FontProcessor oFontProcessor;
						NSBinPptxRW::CDrawingConverter oDrawingConverter;

						NSCommon::smart_ptr<OOX::IFileContainer>	old_rels = *pWriter->m_pCurrentContainer;
						NSCommon::smart_ptr<PPTX::Theme>            old_theme = *pWriter->m_pTheme;

						NSShapeImageGen::CMediaManager* old_manager = oDrawingConverter.m_pBinaryWriter->m_pCommon->m_pMediaManager;
						oDrawingConverter.m_pBinaryWriter->m_pCommon->m_pMediaManager = pWriter->m_pCommon->m_pMediaManager;

						oDrawingConverter.SetFontPicker(pWriter->m_pCommon->m_pFontPicker);

						BinXlsxRW::BinaryFileWriter xlsxBinaryWriter(oFontProcessor);
//----------------------------
						OOX::Spreadsheet::CXlsx oXlsxEmbedded(oox_unpacked);

						//startheader for test
						//oDrawingConverter.m_pBinaryWriter->WriteStringUtf8(xlsxBinaryWriter.WriteFileHeader(0, BinXlsxRW::g_nFormatVersionNoBase64));
						
						xlsxBinaryWriter.intoBindoc(&oXlsxEmbedded, *oDrawingConverter.m_pBinaryWriter, NULL, &oDrawingConverter);
//------------------------------
						*pWriter->m_pCurrentContainer = old_rels;
						*pWriter->m_pTheme = old_theme;
						oDrawingConverter.m_pBinaryWriter->m_pCommon->m_pMediaManager = old_manager;
						
						pWriter->StartRecord(/*c_oserct_chartspaceXLSX*/16);
						
						BYTE* pbBinBuffer = oDrawingConverter.m_pBinaryWriter->GetBuffer();
						int nBinBufferLen = oDrawingConverter.m_pBinaryWriter->GetPosition();

						pWriter->WriteBYTEArray(pbBinBuffer, nBinBufferLen);

						pWriter->EndRecord();

						//for test
						//NSFile::CFileBinary oFile;
						//oFile.CreateFileW(L"d:\\Editor.bin");
						//oFile.WriteFile(pbBinBuffer, nBinBufferLen);
						//oFile.CloseFile();
					}

					NSDirectory::DeleteDirectory(oox_unpacked.GetPath());
				}
			}
	//----------------------------------------------------------------
			NSBinPptxRW::CDrawingConverter oDrawingConverter;
			NSBinPptxRW::CBinaryFileWriter *pOldDrawingWriter = oDrawingConverter.m_pBinaryWriter;
			BinDocxRW::CDocxSerializer *pOldMainDocument = pWriter->m_pMainDocument;
			
			pWriter->m_pMainDocument = NULL;
			oDrawingConverter.m_pBinaryWriter = pWriter;
			smart_ptr<OOX::IFileContainer> oldRels = oDrawingConverter.GetRels();
			oDrawingConverter.SetRels(file.smart_dynamic_cast<OOX::IFileContainer>());
		
			BinXlsxRW::BinaryChartWriter oBinaryChartWriter(*pWriter, &oDrawingConverter);	
			if (pChart.IsInit())
			{
				oBinaryChartWriter.WriteCT_ChartFile(*pChart);
			}
			else if (pChartEx.IsInit())
			{
				oBinaryChartWriter.WriteCT_ChartExFile(*pChartEx);
			}
	//----------------------------------------------------------------
			std::vector<smart_ptr<OOX::File>>& container = pChartEx.IsInit() ? pChartEx->GetContainer() : pChart->GetContainer();

			for (size_t i = 0; i < container.size(); ++i)
			{
				if (OOX::FileTypes::ThemeOverride == container[i]->type())
				{
					PPTX::Theme* pThemeOverride = dynamic_cast<PPTX::Theme*>(container[i].GetPointer());

					pWriter->StartRecord(/*c_oserct_chartspaceTHEMEOVERRIDE = */15);
					pThemeOverride->toPPTY(pWriter);
					pWriter->EndRecord();
					break;
				}
				else if (OOX::FileTypes::ChartStyle == container[i]->type())
				{
					OOX::Spreadsheet::CChartStyleFile* pChartStyle = dynamic_cast<OOX::Spreadsheet::CChartStyleFile*>(container[i].GetPointer());

					pWriter->StartRecord(/*c_oserct_chartspaceSTYLES = */17);
					oBinaryChartWriter.WriteCT_ChartStyle(*pChartStyle);
					pWriter->EndRecord();
				}
				else if (OOX::FileTypes::ChartColors == container[i]->type())
				{
					OOX::Spreadsheet::CChartColorsFile* pChartColors = dynamic_cast<OOX::Spreadsheet::CChartColorsFile*>(container[i].GetPointer());

					pWriter->StartRecord(/*c_oserct_chartspaceCOLORS = */18);
					oBinaryChartWriter.WriteCT_ChartColor(*pChartColors);
					pWriter->EndRecord();
				}
			}
	//----------------------------------------------------------------
			oDrawingConverter.SetRels(oldRels);
			
			oDrawingConverter.m_pBinaryWriter = pOldDrawingWriter;
			pWriter->m_pMainDocument = pOldMainDocument;

		}
		std::wstring ChartRec::toXML() const
		{
			if (!id_data.is_init())
				return L"";

			std::wstring strData;
			if (m_bChartEx)
			{
				strData = L"<cx:chart xmlns:cx=\"http://schemas.microsoft.com/office/drawing/2014/chartex\"";
			}
			else
			{
				strData = L"<c:chart xmlns:c=\"http://schemas.openxmlformats.org/drawingml/2006/chart\"";
			}
			strData += L" xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\" r:id=\"" + id_data->ToString() + L"\"/>";
			return strData;
		}
		void ChartRec::toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
		{
			pWriter->WriteString(toXML());
		}

		void ChartRec::fromPPTY(NSBinPptxRW::CBinaryFileReader* pReader)
		{
			ULONG lLen = pReader->GetLong();

			m_nCountCharts = pReader->m_nCountCharts;
			pReader->m_nCountCharts++;

			BinXlsxRW::CXlsxSerializer		oXlsxSerializer;
			NSBinPptxRW::CDrawingConverter	oDrawingConverter;

			NSBinPptxRW::CImageManager2*	pOldImageManager	= oDrawingConverter.m_pImageManager;
			NSBinPptxRW::CBinaryFileReader* pOldReader			= oDrawingConverter.m_pReader;
 			
			oDrawingConverter.m_pImageManager = pReader->m_pRels->m_pManager;
			oDrawingConverter.m_pReader = pReader;

			oXlsxSerializer.setDrawingConverter(&oDrawingConverter);

			std::wstring strDstChart = pReader->m_pRels->m_pManager->GetDstCharts();

			if (strDstChart.empty())
			{
				strDstChart = pReader->m_pRels->m_pManager->GetDstFolder() + FILE_SEPARATOR_STR + L"charts";
				pReader->m_pRels->m_pManager->SetDstCharts(strDstChart);
			}
			NSDirectory::CreateDirectory(strDstChart);

			smart_ptr<OOX::File> file;
			if (m_bChartEx)
			{
				smart_ptr<OOX::Spreadsheet::CChartExFile> chartEx = new OOX::Spreadsheet::CChartExFile(NULL);
				chartEx->SetGlobalNumber(m_nCountCharts);
				file = chartEx.smart_dynamic_cast<OOX::File>();
			}
			else
			{
				smart_ptr<OOX::Spreadsheet::CChartFile> chart = new OOX::Spreadsheet::CChartFile(NULL);
				chart->SetGlobalNumber(m_nCountCharts);
				file = chart.smart_dynamic_cast<OOX::File>();
			}
			if (true == oXlsxSerializer.saveChart(pReader, lLen, file))
			{
				if (m_bChartEx)
				{
					unsigned int nRId = pReader->m_pRels->WriteRels(L"http://schemas.microsoft.com/office/2014/relationships/chartEx", file->m_sOutputFilename, L"");
					id_data = new OOX::RId(nRId);
				}
				else
				{
					unsigned int nRId = pReader->m_pRels->WriteRels(L"http://schemas.openxmlformats.org/officeDocument/2006/relationships/chart", file->m_sOutputFilename, L"");
					id_data = new OOX::RId(nRId);
				}
			}
			oDrawingConverter.m_pReader			= pOldReader;
			oDrawingConverter.m_pImageManager	= pOldImageManager;
		}
	} // namespace Logic
} // namespace PPTX
