#include "CRecordCreator.h"
#include "ui_RecordCreator.h"

#include "Common/CExtSelectClipRgnWidget.h"
#include "Common/CPaletteEntriesWidget.h"
#include "Common/CLogBrushExWidget.h"
#include "Common/CLogPaletteWidget.h"
#include "Common/CExtTextOutWidget.h"
#include "Common/CRectangleWidget.h"
#include "Common/CPolyDrawWidget.h"
#include "Common/CFillRgnWidget.h"
#include "Common/CPointsWidget.h"
#include "Common/CLogPenWidget.h"
#include "Common/CPolyTextOut.h"
#include "Common/CLogFontExDv.h"
#include "Common/CPointWidget.h"
#include "Common/CColorWidget.h"
#include "Common/CEmptyWidget.h"
#include "Common/CSizeWidget.h"
#include "Common/CPolyWidget.h"
#include "Common/CFormWidget.h"
#include "Common/CInvertRgn.h"
#include "Common/CFrameRgn.h"
#include "Common/Common.h"

#include <QLabel>

CRecordCreator::CRecordCreator(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::CRecordCreator),
        m_pMainWindow(NULL),
        m_pNewItem(NULL),
        m_nSelectedRecord(-1)
{
        ui->setupUi(this);
        this->setWindowTitle("Create");

        QPushButton *pOkButton =  ui->buttonBox->button(QDialogButtonBox::Ok);
        if (NULL != pOkButton)
        {
                 pOkButton->setEnabled(false);
                 connect(pOkButton, &QPushButton::clicked, this, &QDialog::accept);
        }
}

CRecordCreator::~CRecordCreator()
{
        delete ui;
}

void CRecordCreator::SetMainWindow(MainWindow *pMainWindow)
{
        m_pMainWindow = pMainWindow;

        if(NULL != pMainWindow)
                pMainWindow->setEnabled(false);
}

QStandardItem* CRecordCreator::CreateRecord()
{
        this->show();

        if (exec() == QDialog::Accepted)
        {
                switch (m_nSelectedRecord)
                {
                        case -1: break;
                        case 0: ConvertWidgets("EMR_POLYBEZIER");               break;
                        case 1: ConvertWidgets("EMR_POLYGON");                  break;
                        case 2: ConvertWidgets("EMR_POLYLINE");                 break;
                        case 3: ConvertWidgets("EMR_POLYBEZIERTO");             break;
                        case 4: ConvertWidgets("EMR_POLYLINETO");               break;
                        case 5: ConvertWidgets("EMR_POLYPOLYLINE");             break;
                        case 6: ConvertWidgets("EMR_POLYPOLYGON");              break;
                        case 7: ConvertWidgets("EMR_SETWINDOWEXTEX");           break;
                        case 8: ConvertWidgets("EMR_SETWINDOWORGEX");           break;
                        case 9: ConvertWidgets("EMR_SETVIEWPORTEXTEX");         break;
                        case 10: ConvertWidgets("EMR_SETVIEWPORTEXTEX");        break;
                        case 11: ConvertWidgets("EMR_SETBRUSHORGEX");           break;
                        case 12: ConvertWidgets("EMR_SETPIXELV");               break;
                        case 13: ConvertWidgets("EMR_SETMAPPERFLAGS");          break;
                        case 14: ConvertWidgets("EMR_SETMAPMODE");              break;
                        case 15: ConvertWidgets("EMR_SETBKMODE");               break;
                        case 16: ConvertWidgets("EMR_SETPOLYFILLMODE");         break;
                        case 17: ConvertWidgets("EMR_SETROP2");                 break;
                        case 18: ConvertWidgets("EMR_SETSTRETCHBLTMODE");       break;
                        case 19: ConvertWidgets("EMR_SETTEXTALIGN");            break;
                        case 20: ConvertWidgets("EMR_SETCOLORADJUSTMENT");      break;
                        case 21: ConvertWidgets("EMR_SETTEXTCOLOR");            break;
                        case 22: ConvertWidgets("EMR_SETBKCOLOR");              break;
                        case 23: ConvertWidgets("EMR_OFFSETCLIPRGN");           break;
                        case 24: ConvertWidgets("EMR_MOVETOEX");                break;
                        case 25: ConvertWidgets("EMR_SETMETARGN");              break;
                        case 26: ConvertWidgets("EMR_EXCLUDECLIPRECT");         break;
                        case 27: ConvertWidgets("EMR_INTERSECTCLIPRECT");       break;
                        case 28: ConvertWidgets("EMR_SCALEVIEWPORTEXTEX");      break;
                        case 29: ConvertWidgets("EMR_SCALEWINDOWEXTEX");        break;
                        case 30: ConvertWidgets("EMR_SAVEDC");                  break;
                        case 31: ConvertWidgets("EMR_RESTOREDC");               break;
                        case 32: ConvertWidgets("EMR_SETWORLDTRANSFORM");       break;
                        case 33: ConvertWidgets("EMR_MODIFYWORLDTRANSFORM");    break;
                        case 34: ConvertWidgets("EMR_SELECTOBJECT");            break;
                        case 35: ConvertWidgets("EMR_CREATEPEN");               break;
                        case 36: ConvertWidgets("EMR_CREATEBRUSHINDIRECT");     break;
                        case 37: ConvertWidgets("EMR_DELETEOBJECT");            break;
                        case 38: ConvertWidgets("EMR_ANGLEARC");                break;
                        case 39: ConvertWidgets("EMR_ELLIPSE");                 break;
                        case 40: ConvertWidgets("EMR_RECTANGLE");               break;
                        case 41: ConvertWidgets("EMR_ROUNDRECT");               break;
                        case 42: ConvertWidgets("EMR_ARC");                     break;
                        case 43: ConvertWidgets("EMR_CHORD");                   break;
                        case 44: ConvertWidgets("EMR_PIE");                     break;
                        case 45: ConvertWidgets("EMR_SELECTPALETTE");           break;
                        case 46: ConvertWidgets("EMR_CREATEPALETTE");           break;
                        case 47: ConvertWidgets("EMR_SETPALETTEENTRIES");       break;
                        case 48: ConvertWidgets("EMR_RESIZEPALETTE");           break;
                        case 49: ConvertWidgets("EMR_REALIZEPALETTE");          break;
                        case 50: ConvertWidgets("EMR_EXTFLOODFILL");            break;
                        case 51: ConvertWidgets("EMR_LINETO");                  break;
                        case 52: ConvertWidgets("EMR_ARCTO");                   break;
                        case 53: ConvertWidgets("EMR_POLYDRAW");                break;
                        case 54: ConvertWidgets("EMR_SETARCDIRECTION");         break;
                        case 55: ConvertWidgets("EMR_SETMITERLIMIT");           break;
                        case 56: ConvertWidgets("EMR_BEGINPATH");               break;
                        case 57: ConvertWidgets("EMR_ENDPATH");                 break;
                        case 58: ConvertWidgets("EMR_CLOSEFIGURE");             break;
                        case 59: ConvertWidgets("EMR_FILLPATH");                break;
                        case 60: ConvertWidgets("EMR_STROKEANDFILLPATH");       break;
                        case 61: ConvertWidgets("EMR_STROKEPATH");              break;
                        case 62: ConvertWidgets("EMR_FLATTENPATH");             break;
                        case 63: ConvertWidgets("EMR_WIDENPATH");               break;
                        case 64: ConvertWidgets("EMR_SELECTCLIPPATH");          break;
                        case 65: ConvertWidgets("EMR_ABORTPATH");               break;
                        case 66: ConvertWidgets("EMR_FILLRGN");                 break;
                        case 67: ConvertWidgets("EMR_FRAMERGN");                break;
                        case 68: ConvertWidgets("EMR_INVERTRGN");               break;
                        case 69: ConvertWidgets("EMR_PAINTRGN");                break;
                        case 70: ConvertWidgets("EMR_EXTSELECTCLIPRGN");        break;
                        case 71: ConvertWidgets("EMR_BITBLT");                  break;
                        case 72: ConvertWidgets("EMR_STRETCHBLT");              break;
                        case 73: ConvertWidgets("EMR_MASKBLT");                 break;
                        case 74: ConvertWidgets("EMR_PLGBLT");                  break;
                        case 75: ConvertWidgets("EMR_SETDIBITSTODEVICE");       break;
                        case 76: ConvertWidgets("EMR_STRETCHDIBITS");           break;
                        case 77: ConvertWidgets("EMR_EXTCREATEFONTINDIRECTW");  break;
                        case 78: ConvertWidgets("EMR_EXTTEXTOUTA");             break;
                        case 79: ConvertWidgets("EMR_EXTTEXTOUTW");             break;
                        case 80: ConvertWidgets("EMR_POLYBEZIER16");            break;
                        case 81: ConvertWidgets("EMR_POLYGON16");               break;
                        case 82: ConvertWidgets("EMR_POLYLINE16");              break;
                        case 83: ConvertWidgets("EMR_POLYBEZIERTO16");          break;
                        case 84: ConvertWidgets("EMR_POLYLINETO16");            break;
                        case 85: ConvertWidgets("EMR_POLYPOLYLINE16");          break;
                        case 86: ConvertWidgets("EMR_POLYPOLYGON16");           break;
                        case 87: ConvertWidgets("EMR_POLYDRAW16");              break;
                        case 88: ConvertWidgets("EMR_CREATEMONOBRUSH");         break;
                        case 89: ConvertWidgets("EMR_EXTCREATEPEN");            break;
                        case 90: ConvertWidgets("EMR_POLYTEXTOUTA");            break;
                        case 91: ConvertWidgets("EMR_POLYTEXTOUTW");            break;
                };
        }

        Close();

        return m_pNewItem;
}

void CRecordCreator::on_selectButton_clicked()
{
        m_nSelectedRecord = ui->recordsBox->currentIndex();
        ClearData();

        switch (m_nSelectedRecord)
        {
                case 0: CreatePointWidgets("EMR_POLYBEZIER");                           break;
                case 1: CreatePointWidgets("EMR_POLYGON");                              break;
                case 2: CreatePointWidgets("EMR_POLYLINE");                             break;
                case 3: CreatePointWidgets("EMR_POLYBEZIERTO");                         break;
                case 4: CreatePointWidgets("EMR_POLYLINETO");                           break;
                case 5: CreatePolyWidgets("EMR_POLYPOLYLINE");                          break;
                case 6: CreatePolyWidgets("EMR_POLYPOLYGON");                           break;
                case 7: CreateEXTEX("EMR_SETWINDOWEXTEX");                              break;
                case 8: CreateORGEX("EMR_SETWINDOWORGEX");                              break;
                case 9: CreateEXTEX("EMR_SETVIEWPORTEXTEX");                            break;
                case 10: CreateORGEX("EMR_SETVIEWPORTORGEX");                           break;
                case 11: CreateORGEX("EMR_SETBRUSHORGEX");                              break;
                case 12: CreateColorWidgets("EMR_SETPIXELV", true);                     break;
                case 13: CreateFormWidget("EMR_SETMAPPERFLAGS",   "Flags");             break;
                case 14: CreateFormWidget("EMR_SETMAPMODE",       "MapMode");           break;
                case 15: CreateFormWidget("EMR_SETBKMODE",        "BackgroundMode");    break;
                case 16: CreateFormWidget("EMR_SETPOLYFILLMODE",  "PolygonFillMode");   break;
                case 17: CreateFormWidget("EMR_SETROP2",          "ROP2Mode");          break;
                case 18: CreateFormWidget("EMR_SETSTRETCHBLTMODE", "StretchMode");      break;
                case 19: CreateFormWidget("EMR_SETTEXTALIGN",      "TextAlignmentMode");break;
                case 20: Create_Widgets_EMR_SETCOLORADJUSTMENT();                       break;
                case 21: CreateColorWidgets("EMR_SETTEXTCOLOR");                        break;
                case 22: CreateColorWidgets("EMR_SETBKCOLOR");                          break;
                case 23: CreatePointWidgets("EMR_OFFSETCLIPRGN");                       break;
                case 24: CreatePointWidgets("EMR_MOVETOEX");                            break;
                case 25: CreateEmptyWidgets("EMR_SETMETARGN");                          break;
                case 26: CreateRectangleWidgets("EMR_EXCLUDECLIPRECT", "Clip");         break;
                case 27: CreateRectangleWidgets("EMR_INTERSECTCLIPRECT", "Clip");       break;
                case 28: CreateScaleWidgets("EMR_SCALEVIEWPORTEXTEX");                  break;
                case 29: CreateScaleWidgets("EMR_SCALEWINDOWEXTEX");                    break;
                case 30: CreateEmptyWidgets("EMR_SAVEDC");                              break;
                case 31: CreateFormWidget("EMR_RESTOREDC", "SavedDC");                  break;
                case 32: Create_Widgets_EMR_SETWORLDTRANSFORM();                        break;
                case 33: Create_Widgets_EMR_MODIFYWORLDTRANSFORM();                     break;
                case 34: CreateFormWidget("EMR_SELECTOBJECT",      "Index");            break;
                case 35: Create_Widgets_EMR_CREATEPEN();                                break;
                case 36: Create_Widgets_EMR_CREATEBRUSHINDIRECT();                      break;
                case 37: CreateFormWidget("EMR_DELETEOBJECT", "ihObject");              break;
                case 38: Create_Widgets_EMR_ANGLEARC();                                 break;
                case 39: CreateRectangleWidgets("EMR_ELLIPSE", "Box");                  break;
                case 40: CreateRectangleWidgets("EMR_RECTANGLE", "Box");                break;
                case 41: Create_Widgets_EMR_ROUNDRECT();                                break;
                case 42: CreateArcWidgets("EMR_ARC");                                   break;
                case 43: CreateArcWidgets("EMR_CHORD");                                 break;
                case 44: CreateArcWidgets("EMR_PIE");                                   break;
                case 45: CreateFormWidget("EMR_SELECTPALETTE", "ihPal");                break;
                case 46: Create_Widgets_EMR_CREATEPALETTE();                            break;
                case 47: Create_Widgets_EMR_SETPALETTEENTRIES();                        break;
                case 48: Create_Widgets_EMR_RESIZEPALETTE();                            break;
                case 49: CreateEmptyWidgets("EMR_REALIZEPALETTE");                      break;
                case 50: Create_Widgets_EMR_EXTFLOODFILL();                             break;
                case 51: Create_Widgets_EMR_LINETO();                                   break;
                case 52: CreateArcWidgets("EMR_ARCTO");                                 break;
                case 53: CreatePolyDrawWidgets("EMR_POLYDRAW");                         break;
                case 54: CreateFormWidget("EMR_SETARCDIRECTION", "ArcDirection");       break;
                case 55: CreateFormWidget("EMR_SETMITERLIMIT",   "MiterLimit");         break;
                case 56: CreateEmptyWidgets("EMR_BEGINPATH");                           break;
                case 57: CreateEmptyWidgets("EMR_ENDPATH");                             break;
                case 58: CreateEmptyWidgets("EMR_CLOSEFIGURE");                         break;
                case 59: CreateRectangleWidgets("EMR_FILLPATH",          "Bounds");     break;
                case 60: CreateRectangleWidgets("EMR_STROKEANDFILLPATH", "Bounds");     break;
                case 61: CreateRectangleWidgets("EMR_STROKEPATH",        "Bounds");     break;
                case 62: CreateEmptyWidgets("EMR_FLATTENPATH");                         break;
                case 63: CreateEmptyWidgets("EMR_WIDENPATH");                           break;
                case 64: CreateFormWidget("EMR_SELECTCLIPPATH", "RegionMode");          break;
                case 65: CreateEmptyWidgets("EMR_ABORTPATH");                           break;
                case 66: Create_Widgets_EMR_FILLRGN();                                  break;
                case 67: Create_Widgets_EMR_FRAMERGN();                                 break;
                case 68: Create_Widgets_EMR_INVERTRGN();                                break;
                case 69: Create_Widgets_EMR_PAINTRGN();                                 break;
                case 70: Create_Widgets_EMR_EXTSELECTCLIPRGN();                         break;
                case 71: CreateNotSupportedWidgets("EMR_BITBLT");                       break;
                case 72: CreateNotSupportedWidgets("EMR_STRETCHBLT");                   break;
                case 73: CreateNotSupportedWidgets("EMR_MASKBLT");                      break;
                case 74: CreateNotSupportedWidgets("EMR_PLGBLT");                       break;
                case 75: CreateNotSupportedWidgets("EMR_SETDIBITSTODEVICE");            break;
                case 76: CreateNotSupportedWidgets("EMR_STRETCHDIBITS");                break;
                case 77: Create_Widgets_EMR_EXTCREATEFONTINDIRECTW();                   break;
                case 78: CreateExtTextOutWidget("EMR_EXTTEXTOUTA");                     break;
                case 79: CreateExtTextOutWidget("EMR_EXTTEXTOUTW");                     break;
                case 80: CreatePointWidgets("EMR_POLYBEZIER16");                        break;
                case 81: CreatePointWidgets("EMR_POLYGON16");                           break;
                case 82: CreatePointWidgets("EMR_POLYLINE16");                          break;
                case 83: CreatePointWidgets("EMR_POLYBEZIERTO16");                      break;
                case 84: CreatePointWidgets("EMR_POLYLINETO16");                        break;
                case 85: CreatePolyWidgets("EMR_POLYPOLYLINE16");                       break;
                case 86: CreatePolyWidgets("EMR_POLYPOLYGON16");                        break;
                case 87: CreatePolyDrawWidgets("EMR_POLYDRAW16");                       break;
                case 88: CreateEmptyWidgets("EMR_CREATEMONOBRUSH");                     break;
                case 89: CreateEmptyWidgets("EMR_CREATEDIBPATTERNBRUSHPT");             break;
                case 90: CreateEmptyWidgets("EMR_EXTCREATEPEN");                        break;
                case 91: CreatePolyTextOutWidget("EMR_POLYTEXTOUTA");                   break;
                case 92: CreatePolyTextOutWidget("EMR_POLYTEXTOUTW");                   break;
        }

        QPushButton *pOkButton =  ui->buttonBox->button(QDialogButtonBox::Ok);
        if (NULL != pOkButton)
                pOkButton->setEnabled(true);
}

void CRecordCreator::CreatePointWidgets(const QString& qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CreateRectangleWidget("Bounds");
        CreatePointsWidget();
}

void CRecordCreator::CreateFormWidget(const QString& qsName, const QString& qsFormName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CFormWidget *pFormWidget = new CFormWidget(qsFormName, "0");
        ui->dataLayout->addWidget(pFormWidget);

        m_arWidgets.push_back(pFormWidget);
}

void CRecordCreator::CreateColorWidgets(const QString& qsName, bool bBounds)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        if (bBounds)
                CreateRectangleWidget("Bounds");

        CreateColorWidget();
}

void CRecordCreator::CreateEmptyWidgets(const QString& qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CEmptyWidget *pEmptyWidget = new CEmptyWidget(qsName);

        QLabel *pLabel = new QLabel("Запись не содержит параметров");
        ui->dataLayout->addWidget(pLabel);

        m_arWidgets.push_back(pEmptyWidget);
}

void CRecordCreator::CreateRectangleWidgets(const QString &qsName, const QString &qsReactangleName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CRectangleWidget *pRectangleWidget = new CRectangleWidget(qsReactangleName);
        ui->dataLayout->addWidget(pRectangleWidget);

        m_arWidgets.push_back(pRectangleWidget);
}

void CRecordCreator::CreateScaleWidgets(const QString &qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CFormWidget *pXNumWidget    = new CFormWidget("xNum",   "1");
        CFormWidget *pXDenomWidget  = new CFormWidget("xDenom", "1");
        CFormWidget *pYNumWidget    = new CFormWidget("YNum",   "1");
        CFormWidget *pYDenomWidget  = new CFormWidget("YDenom", "1");

        m_arWidgets.push_back(pXNumWidget);
        m_arWidgets.push_back(pXDenomWidget);
        m_arWidgets.push_back(pYNumWidget);
        m_arWidgets.push_back(pYDenomWidget);

        QGridLayout *pLayout = new QGridLayout;

        pLayout->addWidget(pXNumWidget, 0, 0);
        pLayout->addWidget(new QLabel("≠0"), 0, 1);

        pLayout->addWidget(pXDenomWidget, 1, 0);
        pLayout->addWidget(new QLabel("≠0"), 1, 1);

        pLayout->addWidget(pYNumWidget, 2, 0);
        pLayout->addWidget(new QLabel("≠0"), 2, 1);

        pLayout->addWidget(pYDenomWidget, 3, 0);
        pLayout->addWidget(new QLabel("≠0"), 3, 1);

        ui->dataLayout->addLayout(pLayout);
}

void CRecordCreator::CreateArcWidgets(const QString &qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CRectangleWidget *pBoxWidget    = new CRectangleWidget("Box");
        CPointWidget *pStartPointWidget = new CPointWidget("Start");
        CPointWidget *pEndPointWidget   = new CPointWidget("End");

        m_arWidgets.push_back(pBoxWidget);
        m_arWidgets.push_back(pStartPointWidget);
        m_arWidgets.push_back(pEndPointWidget);

        ui->dataLayout->addWidget(pBoxWidget);
        ui->dataLayout->addWidget(pStartPointWidget);
        ui->dataLayout->addWidget(pEndPointWidget);
}

void CRecordCreator::CreateNotSupportedWidgets(const QString &qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        QLabel *pLabel = new QLabel("На данный момент создание данной записи не поддерживается");

        ui->dataLayout->addWidget(pLabel);
}

void CRecordCreator::CreateExtTextOutWidget(const QString &qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CExtTextOutWidget *pEmrTextWidget = new CExtTextOutWidget();
        m_arWidgets.push_back(pEmrTextWidget);

        ui->dataLayout->addWidget(pEmrTextWidget);
}

void CRecordCreator::CreatePolyTextOutWidget(const QString &qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CPolyTextOut *pPolyTextWidget = new CPolyTextOut();
        m_arWidgets.push_back(pPolyTextWidget);

        ui->dataLayout->addWidget(pPolyTextWidget);
}

void CRecordCreator::Create_Widgets_EMR_SETCOLORADJUSTMENT()
{
        this->setWindowTitle("Create: EMR_SETCOLORADJUSTMENT");

        CFormWidget *pSizeWidget            = new CFormWidget("Size",                   "0");
        CFormWidget *pValuesWidget          = new CFormWidget("Values",                 "0");
        CFormWidget *pIndexWidget           = new CFormWidget("IlluminantIndex",        "0");
        CFormWidget *pRGammaWidget          = new CFormWidget("RedGamma",               "0");
        CFormWidget *pGGammaWidget          = new CFormWidget("GreenGamma",             "0");
        CFormWidget *pBGammaWidget          = new CFormWidget("BlueGamma",              "0");
        CFormWidget *pReferenceBWidget      = new CFormWidget("ReferenceBlack",         "0");
        CFormWidget *pReferenceWWidget      = new CFormWidget("ReferenceWhite",         "0");
        CFormWidget *pConstrastWidget       = new CFormWidget("Constrast",              "0");
        CFormWidget *pBrightnessWidget      = new CFormWidget("Brightness",             "0");
        CFormWidget *pColorfulnessWidget    = new CFormWidget("Colorfulness",           "0");
        CFormWidget *pRedGreenTintWidget    = new CFormWidget("RedGreenTint",           "0");

        ui->dataLayout->addWidget(pSizeWidget);
        ui->dataLayout->addWidget(pValuesWidget);
        ui->dataLayout->addWidget(pIndexWidget);
        ui->dataLayout->addWidget(pRGammaWidget);
        ui->dataLayout->addWidget(pGGammaWidget);
        ui->dataLayout->addWidget(pBGammaWidget);
        ui->dataLayout->addWidget(pReferenceBWidget);
        ui->dataLayout->addWidget(pReferenceWWidget);
        ui->dataLayout->addWidget(pConstrastWidget);
        ui->dataLayout->addWidget(pBrightnessWidget);
        ui->dataLayout->addWidget(pColorfulnessWidget);
        ui->dataLayout->addWidget(pRedGreenTintWidget);

        m_arWidgets.push_back(pSizeWidget);
        m_arWidgets.push_back(pValuesWidget);
        m_arWidgets.push_back(pIndexWidget);
        m_arWidgets.push_back(pRGammaWidget);
        m_arWidgets.push_back(pGGammaWidget);
        m_arWidgets.push_back(pBGammaWidget);
        m_arWidgets.push_back(pReferenceBWidget);
        m_arWidgets.push_back(pReferenceWWidget);
        m_arWidgets.push_back(pConstrastWidget);
        m_arWidgets.push_back(pBrightnessWidget);
        m_arWidgets.push_back(pColorfulnessWidget);
        m_arWidgets.push_back(pRedGreenTintWidget);
}

void CRecordCreator::Create_Widgets_EMR_SETWORLDTRANSFORM()
{
        this->setWindowTitle("Create: EMR_SETWORLDTRANSFORM");

        CreateXForm();
}

void CRecordCreator::Create_Widgets_EMR_MODIFYWORLDTRANSFORM()
{
        this->setWindowTitle("Create: EMR_MODIFYWORLDTRANSFORM");

        CreateXForm();

        CFormWidget *pMode = new CFormWidget("ModifyWorldTransformMode", "1");
        ui->dataLayout->addWidget(pMode);

        m_arWidgets.push_back(pMode);
}

void CRecordCreator::Create_Widgets_EMR_CREATEPEN()
{
        this->setWindowTitle("Create: EMR_CREATEPEN");

        CFormWidget *pIhPen = new CFormWidget("ihPen", "1");
        CLogPenWidget *pLogPenWidget = new CLogPenWidget();

        ui->dataLayout->addWidget(pIhPen);
        ui->dataLayout->addWidget(pLogPenWidget);

        m_arWidgets.push_back(pIhPen);
        m_arWidgets.push_back(pLogPenWidget);
}

void CRecordCreator::Create_Widgets_EMR_CREATEBRUSHINDIRECT()
{
        this->setWindowTitle("Create: EMR_CREATEBRUSHINDIRECT");

        CFormWidget *pIhBrush  = new CFormWidget("ihBrush", "1");
        CLogBrushExWidget *pLogBrushExWidget = new CLogBrushExWidget();

        ui->dataLayout->addWidget(pIhBrush);
        ui->dataLayout->addWidget(pLogBrushExWidget);

        m_arWidgets.push_back(pIhBrush);
        m_arWidgets.push_back(pLogBrushExWidget);
}

void CRecordCreator::Create_Widgets_EMR_ANGLEARC()
{
        this->setWindowTitle("Create: EMR_ANGLEARC");

        CPointWidget *pCenterPointWidget    = new CPointWidget("Center");
        CFormWidget *pRadiusWidget          = new CFormWidget("Radius");
        CFormWidget *pStartAngleWidget      = new CFormWidget("StartAngle");
        CFormWidget *pSweepAngleWidget      = new CFormWidget("SweepAngle");

        m_arWidgets.push_back(pCenterPointWidget);
        m_arWidgets.push_back(pRadiusWidget);
        m_arWidgets.push_back(pStartAngleWidget);
        m_arWidgets.push_back(pSweepAngleWidget);

        ui->dataLayout->addWidget(pCenterPointWidget);
        ui->dataLayout->addWidget(pRadiusWidget);
        ui->dataLayout->addWidget(pStartAngleWidget);
        ui->dataLayout->addWidget(pSweepAngleWidget);
}

void CRecordCreator::Create_Widgets_EMR_ROUNDRECT()
{
        this->setWindowTitle("Create: EMR_ROUNDRECT");

        CRectangleWidget *pBoxWidget = new CRectangleWidget("Box");
        CSizeWidget *pCornerWidget = new CSizeWidget("Corner");

        m_arWidgets.push_back(pBoxWidget);
        m_arWidgets.push_back(pCornerWidget);

        ui->dataLayout->addWidget(pBoxWidget);
        ui->dataLayout->addWidget(pCornerWidget);
}

void CRecordCreator::Create_Widgets_EMR_CREATEPALETTE()
{
        this->setWindowTitle("Create: EMR_CREATEPALETTE");

        CFormWidget *pIhPalWidget = new CFormWidget("ihPal", "1");
        CLogPaletteWidget *pLogPaletteWidget = new CLogPaletteWidget();

        m_arWidgets.push_back(pIhPalWidget);
        m_arWidgets.push_back(pLogPaletteWidget);

        ui->dataLayout->addWidget(pIhPalWidget);
        ui->dataLayout->addWidget(pLogPaletteWidget);
}

void CRecordCreator::Create_Widgets_EMR_SETPALETTEENTRIES()
{
        this->setWindowTitle("Create: EMR_SETPALETTEENTRIES");

        CPaletteEntriesWidget *pPaletteEntriesWidget = new CPaletteEntriesWidget();
        ui->dataLayout->addWidget(pPaletteEntriesWidget);

        m_arWidgets.push_back(pPaletteEntriesWidget);
}

void CRecordCreator::Create_Widgets_EMR_RESIZEPALETTE()
{
        this->setWindowTitle("Create: EMR_RESIZEPALETTE");

        CFormWidget *pIhPalWidget = new CFormWidget("ihPal", "1");
        CFormWidget *pCountNumber = new CFormWidget("NumberOfEntries", "1");

        m_arWidgets.push_back(pIhPalWidget);
        m_arWidgets.push_back(pCountNumber);

        ui->dataLayout->addWidget(pIhPalWidget);
        ui->dataLayout->addWidget(pCountNumber);
}

void CRecordCreator::Create_Widgets_EMR_EXTFLOODFILL()
{
        this->setWindowTitle("Create: EMR_EXTFLOODFILL");

        CPointWidget *pStartPointWidget = new CPointWidget("Start");
        CColorWidget *pColorWidget      = new CColorWidget("Color");
        CFormWidget *pModeWidget        = new CFormWidget("FloodFillMode", "1");

        m_arWidgets.push_back(pStartPointWidget);
        m_arWidgets.push_back(pColorWidget);
        m_arWidgets.push_back(pModeWidget);

        ui->dataLayout->addWidget(pStartPointWidget);
        ui->dataLayout->addWidget(pColorWidget);
        ui->dataLayout->addWidget(pModeWidget);
}

void CRecordCreator::Create_Widgets_EMR_LINETO()
{
        this->setWindowTitle("Create: EMR_LINETO");

        CPointWidget *pPointWidget = new CPointWidget("Point");

        m_arWidgets.push_back(pPointWidget);
        ui->dataLayout->addWidget(pPointWidget);
}

void CRecordCreator::Create_Widgets_EMR_FILLRGN()
{
        this->setWindowTitle("Create: EMR_FILLRGN");

        CFillRgnWidget *pFillRgnWidget = new CFillRgnWidget();
        m_arWidgets.push_back(pFillRgnWidget);

        ui->dataLayout->addWidget(pFillRgnWidget);
}

void CRecordCreator::Create_Widgets_EMR_FRAMERGN()
{
        this->setWindowTitle("Create: EMR_FRAMERGN");

        CFrameRgn *pFrameRgnWidget = new CFrameRgn();
        m_arWidgets.push_back(pFrameRgnWidget);

        ui->dataLayout->addWidget(pFrameRgnWidget);
}

void CRecordCreator::Create_Widgets_EMR_INVERTRGN()
{
        this->setWindowTitle("Create: EMR_INVERTRGN");

        CInvertRgn *pInvertRgnWidget = new CInvertRgn();
        m_arWidgets.push_back(pInvertRgnWidget);

        ui->dataLayout->addWidget(pInvertRgnWidget);
}

void CRecordCreator::Create_Widgets_EMR_PAINTRGN()
{
        this->setWindowTitle("Create: EMR_PAINTRGN");

        CPaintRgn *pPaintRgnWidget = new CPaintRgn();
        m_arWidgets.push_back(pPaintRgnWidget);

        ui->dataLayout->addWidget(pPaintRgnWidget);
}

void CRecordCreator::Create_Widgets_EMR_EXTSELECTCLIPRGN()
{
        this->setWindowTitle("Create: EMR_EXTSELECTCLIPRGN");

        CExtSelectClipRgnWidget *pExtSelectClipRgnWidget = new CExtSelectClipRgnWidget();
        m_arWidgets.push_back(pExtSelectClipRgnWidget);

        ui->dataLayout->addWidget(pExtSelectClipRgnWidget);
}

void CRecordCreator::Create_Widgets_EMR_EXTCREATEFONTINDIRECTW()
{
        this->setWindowTitle("Create: EMR_EXTCREATEFONTINDIRECTW");

        CFormWidget *pIhFonts       = new CFormWidget("ihFonts", "1");
        CLogFontExDv *pLogFontExDv  = new CLogFontExDv();

        m_arWidgets.push_back(pIhFonts);
        m_arWidgets.push_back(pLogFontExDv);

        ui->dataLayout->addWidget(pIhFonts);
        ui->dataLayout->addWidget(pLogFontExDv);
}

void CRecordCreator::CreatePolyWidgets(const QString& qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CreateRectangleWidget("Bounds");
        CreatePolyWidget();
}

void CRecordCreator::CreatePolyDrawWidgets(const QString &qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CPolyDrawWidget *pPolyDrawWidget = new CPolyDrawWidget();
        m_arWidgets.push_back(pPolyDrawWidget);

        ui->dataLayout->addWidget(pPolyDrawWidget);
}

void CRecordCreator::CreateRectangleWidget(const QString& qsName)
{
        CRectangleWidget *pRectanleWidget = new CRectangleWidget(qsName);
        ui->dataLayout->addWidget(pRectanleWidget);

        m_arWidgets.push_back(pRectanleWidget);
}

void CRecordCreator::CreatePointsWidget()
{
        CPointsWidget *pPointsWidget = new CPointsWidget();
        ui->dataLayout->addWidget(pPointsWidget);

        m_arWidgets.push_back(pPointsWidget);
}

void CRecordCreator::CreateColorWidget()
{
        CColorWidget *pColorWidget = new CColorWidget("Color");
        ui->dataLayout->addWidget(pColorWidget);

        m_arWidgets.push_back(pColorWidget);
}

void CRecordCreator::CreatePolyWidget()
{
        CPolyWidget *pPolyWidget = new CPolyWidget;
        ui->dataLayout->addWidget(pPolyWidget);

        m_arWidgets.push_back(pPolyWidget);
}

void CRecordCreator::CreateXForm()
{
        CFormWidget *pM11 = new CFormWidget("M11", "0");
        CFormWidget *pM12 = new CFormWidget("M12", "0");
        CFormWidget *pM21 = new CFormWidget("M21", "0");
        CFormWidget *pM22 = new CFormWidget("M22", "0");
        CFormWidget *pDx  = new CFormWidget("Dx",  "0");
        CFormWidget *pDy  = new CFormWidget("Dy",  "0");

        m_arWidgets.push_back(pM11);
        m_arWidgets.push_back(pM12);
        m_arWidgets.push_back(pM21);
        m_arWidgets.push_back(pM22);
        m_arWidgets.push_back(pDx);
        m_arWidgets.push_back(pDy);

        ui->dataLayout->addWidget(pM11);
        ui->dataLayout->addWidget(pM12);
        ui->dataLayout->addWidget(pM21);
        ui->dataLayout->addWidget(pM22);
        ui->dataLayout->addWidget(pDx);
        ui->dataLayout->addWidget(pDy);
}

void CRecordCreator::CreateEXTEX(const QString& qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CSizeWidget *pSizeWidget = new CSizeWidget("Size");
        ui->dataLayout->addWidget(pSizeWidget);

        m_arWidgets.push_back(pSizeWidget);
}

void CRecordCreator::CreateORGEX(const QString& qsName)
{
        this->setWindowTitle(QString("Create: %1").arg(qsName));

        CPointWidget *pPointWidget = new CPointWidget("Extent");
        ui->dataLayout->addWidget(pPointWidget);

        m_arWidgets.push_back(pPointWidget);
}

void CRecordCreator::ConvertWidgets(const QString& qsName)
{
        if (qsName.isEmpty() || m_arWidgets.empty())
                return;

        m_pNewItem = new QStandardItem(QString("<%1>").arg(qsName));

        for (const CSharedWidget* pWidget : m_arWidgets)
                m_pNewItem->appendRows(pWidget->GetData());
}

void CRecordCreator::ClearData()
{
        ClearLayout(ui->dataLayout);

        m_pNewItem = NULL;
        m_arWidgets.clear();
}

void CRecordCreator::Close()
{
        if (NULL != m_pMainWindow)
                m_pMainWindow->setEnabled(true);

        close();
}
