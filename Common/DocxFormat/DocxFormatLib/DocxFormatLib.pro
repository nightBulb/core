#-------------------------------------------------
#
# Project created by QtCreator 2014-07-03T15:22:54
#
#-------------------------------------------------

QT       -= core gui

TARGET = DocxFormatLib
TEMPLATE = lib
CONFIG += staticlib

DEFINES += UNICODE

LIBS += -lxml2

INCLUDEPATH += \
    /usr/include/libxml2

SOURCES += docxformatlib.cpp \
    ../Source/Common/Align.cpp \
    ../Source/Common/Color.cpp \
    ../Source/Common/Index.cpp \
    ../Source/Common/NumFormat.cpp \
    ../Source/Common/Position.cpp \
    ../Source/Common/Utils.cpp \
    ../Source/Common/Wrap.cpp \
    ../Source/Common/ZIndex.cpp \
    ../Source/DocxFormat/Drawing/DrawingCoreInfo.cpp \
    ../Source/DocxFormat/Drawing/DrawingEffects.cpp \
    ../Source/DocxFormat/Logic/AlternateContent.cpp \
    ../Source/DocxFormat/Logic/Annotations.cpp \
    ../Source/DocxFormat/Logic/Bdo.cpp \
    ../Source/DocxFormat/Logic/Dir.cpp \
    ../Source/DocxFormat/Logic/FldSimple.cpp \
    ../Source/DocxFormat/Logic/Hyperlink.cpp \
    ../Source/DocxFormat/Logic/Paragraph.cpp \
    ../Source/DocxFormat/Logic/ParagraphProperty.cpp \
    ../Source/DocxFormat/Logic/RunProperty.cpp \
    ../Source/DocxFormat/Logic/Sdt.cpp \
    ../Source/DocxFormat/Logic/SectionProperty.cpp \
    ../Source/DocxFormat/Logic/SmartTag.cpp \
    ../Source/DocxFormat/Logic/Table.cpp \
    ../Source/DocxFormat/Logic/TableProperty.cpp \
    ../Source/DocxFormat/Logic/Vml.cpp \
    ../Source/DocxFormat/Math/oMath.cpp \
    ../Source/DocxFormat/Math/oMathContent.cpp \
    ../Source/DocxFormat/Math/oMathPara.cpp \
    ../Source/DocxFormat/Docx.cpp \
    ../Source/DocxFormat/FileFactory.cpp \
    ../Source/DocxFormat/IFileContainer.cpp \
    ../Source/SystemUtility/FileSystem/Directory.cpp \
    ../Source/SystemUtility/FileSystem/File.cpp \
    ../Source/SystemUtility/Solution/FileSystemTest/AssemblyInfo.cpp \
    ../Source/SystemUtility/Solution/FileSystemTest/DirectoryTest.cpp \
    ../Source/SystemUtility/Solution/FileSystemTest/stdafx.cpp \
    ../Source/SystemUtility/SystemUtility.cpp \
    ../Source/Utility/codecvt.cpp \
    ../Source/Utility/DateTime.cpp \
    ../Source/Utility/Encoding.cpp \
    ../Source/Utility/TxtFile.cpp \
    ../Source/XlsxFormat/Chart/ChartSerialize.cpp \
    ../Source/XlsxFormat/Common.cpp \
    ../Source/XlsxFormat/FileFactory_Spreadsheet.cpp \
    ../Source/XlsxFormat/IFileContainer_Spreadsheet.cpp \
    ../Source/XML/libxml2/XML/macos/src/libxml2_GUSIConfig.cp \
    ../Source/XML/libxml2/XML/doc/examples/io1.c \
    ../Source/XML/libxml2/XML/doc/examples/io2.c \
    ../Source/XML/libxml2/XML/doc/examples/parse1.c \
    ../Source/XML/libxml2/XML/doc/examples/parse2.c \
    ../Source/XML/libxml2/XML/doc/examples/parse3.c \
    ../Source/XML/libxml2/XML/doc/examples/parse4.c \
    ../Source/XML/libxml2/XML/doc/examples/reader1.c \
    ../Source/XML/libxml2/XML/doc/examples/reader2.c \
    ../Source/XML/libxml2/XML/doc/examples/reader3.c \
    ../Source/XML/libxml2/XML/doc/examples/reader4.c \
    ../Source/XML/libxml2/XML/doc/examples/testWriter.c \
    ../Source/XML/libxml2/XML/doc/examples/tree1.c \
    ../Source/XML/libxml2/XML/doc/examples/tree2.c \
    ../Source/XML/libxml2/XML/doc/examples/xpath1.c \
    ../Source/XML/libxml2/XML/doc/examples/xpath2.c \
    ../Source/XML/libxml2/XML/doc/tutorial/includeaddattribute.c \
    ../Source/XML/libxml2/XML/doc/tutorial/includeaddkeyword.c \
    ../Source/XML/libxml2/XML/doc/tutorial/includeconvert.c \
    ../Source/XML/libxml2/XML/doc/tutorial/includegetattribute.c \
    ../Source/XML/libxml2/XML/doc/tutorial/includekeyword.c \
    ../Source/XML/libxml2/XML/doc/tutorial/includexpath.c \
    ../Source/XML/libxml2/XML/example/gjobread.c \
    ../Source/XML/libxml2/XML/macos/src/macos_main.c \
    ../Source/XML/libxml2/XML/python/libxml.c \
    ../Source/XML/libxml2/XML/python/types.c \
    ../Source/XML/libxml2/XML/win32/wince/wincecompat.c \
    ../Source/XML/libxml2/XML/buf.c \
    ../Source/XML/libxml2/XML/c14n.c \
    ../Source/XML/libxml2/XML/catalog.c \
    ../Source/XML/libxml2/XML/chvalid.c \
    ../Source/XML/libxml2/XML/debugXML.c \
    ../Source/XML/libxml2/XML/dict.c \
    ../Source/XML/libxml2/XML/DOCBparser.c \
    ../Source/XML/libxml2/XML/encoding.c \
    ../Source/XML/libxml2/XML/entities.c \
    ../Source/XML/libxml2/XML/error.c \
    ../Source/XML/libxml2/XML/globals.c \
    ../Source/XML/libxml2/XML/hash.c \
    ../Source/XML/libxml2/XML/HTMLparser.c \
    ../Source/XML/libxml2/XML/HTMLtree.c \
    ../Source/XML/libxml2/XML/legacy.c \
    ../Source/XML/libxml2/XML/list.c \
    ../Source/XML/libxml2/XML/nanoftp.c \
    ../Source/XML/libxml2/XML/nanohttp.c \
    ../Source/XML/libxml2/XML/parser.c \
    ../Source/XML/libxml2/XML/parserInternals.c \
    ../Source/XML/libxml2/XML/pattern.c \
    ../Source/XML/libxml2/XML/relaxng.c \
    ../Source/XML/libxml2/XML/rngparser.c \
    ../Source/XML/libxml2/XML/runsuite.c \
    ../Source/XML/libxml2/XML/runtest.c \
    ../Source/XML/libxml2/XML/runxmlconf.c \
    ../Source/XML/libxml2/XML/SAX.c \
    ../Source/XML/libxml2/XML/SAX2.c \
    ../Source/XML/libxml2/XML/schematron.c \
    ../Source/XML/libxml2/XML/testapi.c \
    ../Source/XML/libxml2/XML/testAutomata.c \
    ../Source/XML/libxml2/XML/testC14N.c \
    ../Source/XML/libxml2/XML/testchar.c \
    ../Source/XML/libxml2/XML/testdict.c \
    ../Source/XML/libxml2/XML/testdso.c \
    ../Source/XML/libxml2/XML/testHTML.c \
    ../Source/XML/libxml2/XML/testlimits.c \
    ../Source/XML/libxml2/XML/testModule.c \
    ../Source/XML/libxml2/XML/testOOM.c \
    ../Source/XML/libxml2/XML/testOOMlib.c \
    ../Source/XML/libxml2/XML/testReader.c \
    ../Source/XML/libxml2/XML/testrecurse.c \
    ../Source/XML/libxml2/XML/testRegexp.c \
    ../Source/XML/libxml2/XML/testRelax.c \
    ../Source/XML/libxml2/XML/testSAX.c \
    ../Source/XML/libxml2/XML/testSchemas.c \
    ../Source/XML/libxml2/XML/testThreads.c \
    ../Source/XML/libxml2/XML/testThreadsWin32.c \
    ../Source/XML/libxml2/XML/testURI.c \
    ../Source/XML/libxml2/XML/testXPath.c \
    ../Source/XML/libxml2/XML/threads.c \
    ../Source/XML/libxml2/XML/tree.c \
    ../Source/XML/libxml2/XML/trio.c \
    ../Source/XML/libxml2/XML/trionan.c \
    ../Source/XML/libxml2/XML/triostr.c \
    ../Source/XML/libxml2/XML/uri.c \
    ../Source/XML/libxml2/XML/valid.c \
    ../Source/XML/libxml2/XML/xinclude.c \
    ../Source/XML/libxml2/XML/xlink.c \
    ../Source/XML/libxml2/XML/xmlcatalog.c \
    ../Source/XML/libxml2/XML/xmlIO.c \
    ../Source/XML/libxml2/XML/xmllint.c \
    ../Source/XML/libxml2/XML/xmlmemory.c \
    ../Source/XML/libxml2/XML/xmlmodule.c \
    ../Source/XML/libxml2/XML/xmlreader.c \
    ../Source/XML/libxml2/XML/xmlregexp.c \
    ../Source/XML/libxml2/XML/xmlsave.c \
    ../Source/XML/libxml2/XML/xmlschemas.c \
    ../Source/XML/libxml2/XML/xmlschemastypes.c \
    ../Source/XML/libxml2/XML/xmlstring.c \
    ../Source/XML/libxml2/XML/xmlunicode.c \
    ../Source/XML/libxml2/XML/xmlwriter.c \
    ../Source/XML/libxml2/XML/xpath.c \
    ../Source/XML/libxml2/XML/xpointer.c \
    ../Source/XML/libxml2/XML/xzlib.c

HEADERS += docxformatlib.h \
    #../Source/Base/Base.h \
    ../Source/Base/Nullable.h \
    ../Source/Base/SmartPtr.h \
    ../Source/Common/AbstractConverter.h \
    ../Source/Common/Align.h \
    ../Source/Common/Color.h \
    ../Source/Common/Common.h \
    ../Source/Common/ComplexTypes.h \
    ../Source/Common/Encoding.h \
    ../Source/Common/Index.h \
    ../Source/Common/NumFormat.h \
    ../Source/Common/Point.h \
    ../Source/Common/Position.h \
    ../Source/Common/SimpleTypes_Base.h \
    ../Source/Common/SimpleTypes_Drawing.h \
    ../Source/Common/SimpleTypes_OMath.h \
    ../Source/Common/SimpleTypes_Shared.h \
    ../Source/Common/SimpleTypes_Vml.h \
    ../Source/Common/SimpleTypes_Word.h \
    ../Source/Common/Size.h \
    ../Source/Common/Unit.h \
    ../Source/Common/Utils.h \
    ../Source/Common/Wrap.h \
    ../Source/Common/ZIndex.h \
    ../Source/DocxFormat/Drawing/Drawing.h \
    ../Source/DocxFormat/Drawing/Drawing3D.h \
    ../Source/DocxFormat/Drawing/DrawingBody.h \
    ../Source/DocxFormat/Drawing/DrawingColors.h \
    ../Source/DocxFormat/Drawing/DrawingCoreInfo.h \
    ../Source/DocxFormat/Drawing/DrawingEffects.h \
    ../Source/DocxFormat/Drawing/DrawingExt.h \
    ../Source/DocxFormat/Drawing/DrawingGraphic.h \
    ../Source/DocxFormat/Drawing/DrawingParagraph.h \
    ../Source/DocxFormat/Drawing/DrawingParagraphElements.h \
    ../Source/DocxFormat/Drawing/DrawingPicture.h \
    ../Source/DocxFormat/Drawing/DrawingRun.h \
    ../Source/DocxFormat/Drawing/DrawingShape.h \
    ../Source/DocxFormat/Drawing/DrawingShared.h \
    ../Source/DocxFormat/Drawing/DrawingStyles.h \
    ../Source/DocxFormat/Drawing/DrawingStyles2.h \
    ../Source/DocxFormat/Drawing/DrawingTables.h \
    ../Source/DocxFormat/Drawing/DrawingTransform.h \
    ../Source/DocxFormat/External/External.h \
    ../Source/DocxFormat/External/ExternalAudio.h \
    ../Source/DocxFormat/External/ExternalImage.h \
    ../Source/DocxFormat/External/ExternalVideo.h \
    ../Source/DocxFormat/External/HyperLink.h \
    ../Source/DocxFormat/Logic/AlternateContent.h \
    ../Source/DocxFormat/Logic/Annotations.h \
    ../Source/DocxFormat/Logic/BaseLogicSettings.h \
    ../Source/DocxFormat/Logic/Bdo.h \
    ../Source/DocxFormat/Logic/Dir.h \
    ../Source/DocxFormat/Logic/FldChar.h \
    ../Source/DocxFormat/Logic/FldSimple.h \
    ../Source/DocxFormat/Logic/Hyperlink.h \
    ../Source/DocxFormat/Logic/Paragraph.h \
    ../Source/DocxFormat/Logic/ParagraphProperty.h \
    ../Source/DocxFormat/Logic/Pict.h \
    ../Source/DocxFormat/Logic/Run.h \
    ../Source/DocxFormat/Logic/RunContent.h \
    ../Source/DocxFormat/Logic/RunProperty.h \
    ../Source/DocxFormat/Logic/Sdt.h \
    ../Source/DocxFormat/Logic/SectionProperty.h \
    ../Source/DocxFormat/Logic/Shape.h \
    ../Source/DocxFormat/Logic/SmartTag.h \
    ../Source/DocxFormat/Logic/Table.h \
    ../Source/DocxFormat/Logic/TableProperty.h \
    ../Source/DocxFormat/Logic/Vml.h \
    ../Source/DocxFormat/Logic/VmlOfficeDrawing.h \
    ../Source/DocxFormat/Logic/VmlWord.h \
    ../Source/DocxFormat/Math/OMath.h \
    ../Source/DocxFormat/Math/oMathBottomNodes.h \
    ../Source/DocxFormat/Math/oMathContent.h \
    ../Source/DocxFormat/Math/oMathPara.h \
    ../Source/DocxFormat/Media/Audio.h \
    ../Source/DocxFormat/Media/Image.h \
    ../Source/DocxFormat/Media/Media.h \
    ../Source/DocxFormat/Media/OleObject.h \
    ../Source/DocxFormat/Media/Video.h \
    ../Source/DocxFormat/Settings/Settings.h \
    ../Source/DocxFormat/Settings/WebSettings.h \
    ../Source/DocxFormat/Theme/Theme.h \
    ../Source/DocxFormat/Theme/ThemeOverride.h \
    ../Source/DocxFormat/App.h \
    ../Source/DocxFormat/Bibliography.h \
    ../Source/DocxFormat/Comments.h \
    ../Source/DocxFormat/ContentTypes.h \
    ../Source/DocxFormat/Core.h \
    ../Source/DocxFormat/CustomXml.h \
    ../Source/DocxFormat/Document.h \
    ../Source/DocxFormat/Docx.h \
    ../Source/DocxFormat/Endnote.h \
    ../Source/DocxFormat/File.h \
    ../Source/DocxFormat/FileFactory.h \
    ../Source/DocxFormat/FileType.h \
    ../Source/DocxFormat/FileTypes.h \
    ../Source/DocxFormat/Font.h \
    ../Source/DocxFormat/FontTable.h \
    ../Source/DocxFormat/Footnote.h \
    ../Source/DocxFormat/FtnEdn.h \
    ../Source/DocxFormat/HeaderFooter.h \
    ../Source/DocxFormat/IFileBuilder.h \
    ../Source/DocxFormat/IFileContainer.h \
    ../Source/DocxFormat/NamespaceOwn.h \
    ../Source/DocxFormat/Namespaces.h \
    ../Source/DocxFormat/Numbering.h \
    ../Source/DocxFormat/Rels.h \
    ../Source/DocxFormat/RId.h \
    ../Source/DocxFormat/Styles.h \
    ../Source/DocxFormat/Unit.h \
    ../Source/DocxFormat/UnknowTypeFile.h \
    ../Source/DocxFormat/WritingElement.h \
    ../Source/DocxFormat/WritingVector.h \
    ../Source/SystemUtility/FileSystem/Directory.h \
    ../Source/SystemUtility/FileSystem/File.h \
    ../Source/SystemUtility/FileSystem/FileSystem.h \
    ../Source/SystemUtility/FileSystem/Settings.h \
    ../Source/SystemUtility/Solution/FileSystemTest/resource.h \
    ../Source/SystemUtility/Solution/FileSystemTest/stdafx.h \
    ../Source/SystemUtility/File.h \
    ../Source/SystemUtility/SystemUtility.h \
    ../Source/Utility/codecvt.h \
    ../Source/Utility/DateTime.h \
    ../Source/Utility/Encoding.h \
    ../Source/Utility/TxtFile.h \
    ../Source/Utility/Unit.h \
    ../Source/Utility/Utility.h \
    ../Source/XlsxFormat/CalcChain/CalcChain.h \
    ../Source/XlsxFormat/Chart/Chart.h \
    ../Source/XlsxFormat/Chart/ChartSerialize.h \
    ../Source/XlsxFormat/Comments/Comments.h \
    ../Source/XlsxFormat/Drawing/CellAnchor.h \
    ../Source/XlsxFormat/Drawing/Drawing.h \
    ../Source/XlsxFormat/Drawing/FromTo.h \
    ../Source/XlsxFormat/Drawing/GraphicFrame.h \
    ../Source/XlsxFormat/Drawing/Image.h \
    ../Source/XlsxFormat/Drawing/Pic.h \
    ../Source/XlsxFormat/Drawing/Pos.h \
    ../Source/XlsxFormat/Drawing/Shape.h \
    ../Source/XlsxFormat/SharedStrings/PhoneticPr.h \
    ../Source/XlsxFormat/SharedStrings/rPr.h \
    ../Source/XlsxFormat/SharedStrings/Run.h \
    ../Source/XlsxFormat/SharedStrings/SharedStrings.h \
    ../Source/XlsxFormat/SharedStrings/Si.h \
    ../Source/XlsxFormat/SharedStrings/Text.h \
    ../Source/XlsxFormat/Styles/Borders.h \
    ../Source/XlsxFormat/Styles/CellStyles.h \
    ../Source/XlsxFormat/Styles/Colors.h \
    ../Source/XlsxFormat/Styles/dxf.h \
    ../Source/XlsxFormat/Styles/Fills.h \
    ../Source/XlsxFormat/Styles/Fonts.h \
    ../Source/XlsxFormat/Styles/NumFmts.h \
    ../Source/XlsxFormat/Styles/rPr.h \
    ../Source/XlsxFormat/Styles/Styles.h \
    ../Source/XlsxFormat/Styles/TableStyles.h \
    ../Source/XlsxFormat/Styles/Xfs.h \
    ../Source/XlsxFormat/Table/Autofilter.h \
    ../Source/XlsxFormat/Table/Table.h \
    ../Source/XlsxFormat/Workbook/BookViews.h \
    ../Source/XlsxFormat/Workbook/DefinedNames.h \
    ../Source/XlsxFormat/Workbook/Sheets.h \
    ../Source/XlsxFormat/Workbook/Workbook.h \
    ../Source/XlsxFormat/Workbook/WorkbookPr.h \
    ../Source/XlsxFormat/Worksheets/Cols.h \
    ../Source/XlsxFormat/Worksheets/ConditionalFormatting.h \
    ../Source/XlsxFormat/Worksheets/Hyperlinks.h \
    ../Source/XlsxFormat/Worksheets/MergeCells.h \
    ../Source/XlsxFormat/Worksheets/SheetData.h \
    ../Source/XlsxFormat/Worksheets/Worksheet.h \
    ../Source/XlsxFormat/Worksheets/WorksheetChildOther.h \
    ../Source/XlsxFormat/Common.h \
    ../Source/XlsxFormat/CommonInclude.h \
    ../Source/XlsxFormat/ComplexTypes_Spreadsheet.h \
    ../Source/XlsxFormat/FileFactory_Spreadsheet.h \
    ../Source/XlsxFormat/FileTypes_Spreadsheet.h \
    ../Source/XlsxFormat/IFileContainer_Spreadsheet.h \
    ../Source/XlsxFormat/SimpleTypes_Spreadsheet.h \
    ../Source/XlsxFormat/Workbook.h \
    ../Source/XlsxFormat/WritingElement.h \
    ../Source/XlsxFormat/Xlsx.h \
    #../Source/XML/libxml2/win_build/config.h \
    #../Source/XML/libxml2/win_build/stdint.h \
    #../Source/XML/libxml2/XML/include/libxml/c14n.h \
    #../Source/XML/libxml2/XML/include/libxml/catalog.h \
    #../Source/XML/libxml2/XML/include/libxml/chvalid.h \
    #../Source/XML/libxml2/XML/include/libxml/debugXML.h \
    #../Source/XML/libxml2/XML/include/libxml/dict.h \
    #../Source/XML/libxml2/XML/include/libxml/DOCBparser.h \
    #../Source/XML/libxml2/XML/include/libxml/encoding.h \
    #../Source/XML/libxml2/XML/include/libxml/entities.h \
    #../Source/XML/libxml2/XML/include/libxml/globals.h \
    #../Source/XML/libxml2/XML/include/libxml/hash.h \
    #../Source/XML/libxml2/XML/include/libxml/HTMLparser.h \
    #../Source/XML/libxml2/XML/include/libxml/HTMLtree.h \
    #../Source/XML/libxml2/XML/include/libxml/list.h \
    #../Source/XML/libxml2/XML/include/libxml/nanoftp.h \
    #../Source/XML/libxml2/XML/include/libxml/nanohttp.h \
    #../Source/XML/libxml2/XML/include/libxml/parser.h \
    #../Source/XML/libxml2/XML/include/libxml/parserInternals.h \
    #../Source/XML/libxml2/XML/include/libxml/pattern.h \
    #../Source/XML/libxml2/XML/include/libxml/relaxng.h \
    #../Source/XML/libxml2/XML/include/libxml/SAX.h \
    #../Source/XML/libxml2/XML/include/libxml/SAX2.h \
    #../Source/XML/libxml2/XML/include/libxml/schemasInternals.h \
    #../Source/XML/libxml2/XML/include/libxml/schematron.h \
    #../Source/XML/libxml2/XML/include/libxml/threads.h \
    #../Source/XML/libxml2/XML/include/libxml/tree.h \
    #../Source/XML/libxml2/XML/include/libxml/uri.h \
    #../Source/XML/libxml2/XML/include/libxml/valid.h \
    #../Source/XML/libxml2/XML/include/libxml/xinclude.h \
    #../Source/XML/libxml2/XML/include/libxml/xlink.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlautomata.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlerror.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlexports.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlIO.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlmemory.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlmodule.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlreader.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlregexp.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlsave.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlschemas.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlschemastypes.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlstring.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlunicode.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlversion.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlwin32version.h \
    #../Source/XML/libxml2/XML/include/libxml/xmlwriter.h \
    #../Source/XML/libxml2/XML/include/libxml/xpath.h \
    #../Source/XML/libxml2/XML/include/libxml/xpathInternals.h \
    #../Source/XML/libxml2/XML/include/libxml/xpointer.h \
    #../Source/XML/libxml2/XML/include/win32config.h \
    #../Source/XML/libxml2/XML/include/wsockcompat.h \
    #../Source/XML/libxml2/XML/macos/src/config-mac.h \
    #../Source/XML/libxml2/XML/macos/src/XMLTestPrefix.h \
    #../Source/XML/libxml2/XML/macos/src/XMLTestPrefix2.h \
    #../Source/XML/libxml2/XML/python/libxml_wrap.h \
    #../Source/XML/libxml2/XML/win32/VC10/config.h \
    #../Source/XML/libxml2/XML/win32/wince/wincecompat.h \
    #../Source/XML/libxml2/XML/buf.h \
    #../Source/XML/libxml2/XML/elfgcchack.h \
    #../Source/XML/libxml2/XML/enc.h \
    #../Source/XML/libxml2/XML/libxml.h \
    #../Source/XML/libxml2/XML/save.h \
    #../Source/XML/libxml2/XML/testOOMlib.h \
    #../Source/XML/libxml2/XML/timsort.h \
    #../Source/XML/libxml2/XML/trio.h \
    #../Source/XML/libxml2/XML/triodef.h \
    #../Source/XML/libxml2/XML/trionan.h \
    #../Source/XML/libxml2/XML/triop.h \
    #../Source/XML/libxml2/XML/triostr.h \
    #../Source/XML/libxml2/XML/xzlib.h \
    #../Source/XML/libxml2/libxml2.h \
    ../Source/XML/StringWriter.h \
    ../Source/XML/Utils.h \
    ../Source/XML/XmlSimple.h \
    ../Source/XML/xmlutils.h \
    ../Source/Base/ASCString.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
