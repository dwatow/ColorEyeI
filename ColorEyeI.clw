; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CReadBarCodeDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ColorEyeI.h"
ODLFile=ColorEyeI.odl
LastPage=0

ClassCount=8
Class1=CColorEyeIApp
Class2=CColorEyeIDoc
Class3=CColorEyeIView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_PATTERN_DIALOG
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Resource3=IDD_OMDTOEXCEL
Resource4=IDR_MAINFRAME
Resource5="IDD_OMDTOEXCEL"
Class6=CEnterValueDlg
Resource6=IDD_MSR_ITEM
Resource7=IDD_EDIT_DIALOG
Class7=CCaSetupDlg
Resource8=IDD_CASETUP_DIALOG
Class8=CReadBarCodeDialog
Resource9=IDD_DIALOG_BARCODE

[CLS:CColorEyeIApp]
Type=0
HeaderFile=ColorEyeI.h
ImplementationFile=ColorEyeI.cpp
Filter=N
LastObject=CColorEyeIApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CColorEyeIDoc]
Type=0
HeaderFile=ColorEyeIDoc.h
ImplementationFile=ColorEyeIDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CColorEyeIDoc

[CLS:CColorEyeIView]
Type=0
HeaderFile=ColorEyeIView.h
ImplementationFile=ColorEyeIView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=CColorEyeIView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SETUP_CA210
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=ColorEyeI.cpp
ImplementationFile=ColorEyeI.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDOK,button,1342373889
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308480
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_OMDTOXLS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_MSR_CONNECTCA210
Command9=ID_MSR_FORM
Command10=ID_MSR_ITEM
Command11=ID_MSR_POINT
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_SETUP_SOFT
Command15=ID_SETUP_MSR
Command16=ID_SETUP_SPEC
Command17=ID_SETUP_CA210
Command18=ID_SETUP_CAL
Command19=ID_APP_ABOUT
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_MSR_CONNECTCA210
Command2=ID_MSR_ITEM
Command3=ID_MSR_FORM
Command4=ID_FILE_NEW
Command5=ID_FILE_OPEN
Command6=ID_MSR_POINT
Command7=ID_FILE_SAVE
Command8=ID_FILE_OMDTOXLS
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_OMDTOEXCEL]
Type=1
Class=?
ControlCount=11
Control1=IDC_COMBO_EXCELSELER,combobox,1344339971
Control2=IDC_RADIO_NOWFILE,button,1342312201
Control3=IDC_RADIO_HDFILE,button,1342308361
Control4=IDC_BUTTON_FINDFILE,button,1476460544
Control5=IDOK,button,1476460545
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC_ITEMLIST,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_LIST_SELFILELIST,listbox,1488011521
Control10=IDC_STATIC_HDFILELIST,button,1342177543
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_PATTERN_DIALOG]
Type=1
Class=?
ControlCount=0

[DLG:"IDD_OMDTOEXCEL"]
Type=1
Class=?
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO_EXCELSELER,combobox,1344339971
Control4=IDC_STATIC_ITEMLIST,static,1342308352
Control5=IDC_RADIO_NOWFILE,button,1342312201
Control6=IDC_RADIO_HDFILE,button,1342308361
Control7=IDC_STATIC,button,1342177287
Control8=IDC_BUTTON_FINDFILE,button,1476460544
Control9=IDC_LIST_SELFILELIST,listbox,1487995137
Control10=IDC_STATIC_HDFILELIST,button,1342177543
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_MSR_ITEM]
Type=1
Class=?
ControlCount=97
Control1=IDC_CHECK_CWP1,button,1342242819
Control2=IDC_CHECK_CRP1,button,1342242819
Control3=IDC_CHECK_CGP1,button,1342242819
Control4=IDC_CHECK_CBP1,button,1342242819
Control5=IDC_CHECK_CDP1,button,1342242819
Control6=IDC_CHECK_CWP5,button,1342242819
Control7=IDC_CHECK_CRP5,button,1476460547
Control8=IDC_CHECK_CGP5,button,1476460547
Control9=IDC_CHECK_CBP5,button,1476460547
Control10=IDC_CHECK_CDP5,button,1476460547
Control11=IDC_EDIT_P5FE,edit,1350631552
Control12=IDC_CHECK_CWP9,button,1342242819
Control13=IDC_CHECK_CRP9,button,1476460547
Control14=IDC_CHECK_CGP9,button,1476460547
Control15=IDC_CHECK_CBP9,button,1476460547
Control16=IDC_CHECK_CDP9,button,1476460547
Control17=IDC_EDIT_P9FE,edit,1350631552
Control18=IDC_CHECK_CWP13,button,1476460547
Control19=IDC_CHECK_CRP13,button,1476460547
Control20=IDC_CHECK_CGP13,button,1476460547
Control21=IDC_CHECK_CBP13,button,1476460547
Control22=IDC_CHECK_CDP13,button,1342242819
Control23=IDC_CHECK_CWP21,button,1476460547
Control24=IDC_CHECK_CRP21,button,1476460547
Control25=IDC_CHECK_CGP21,button,1476460547
Control26=IDC_CHECK_CBP21,button,1476460547
Control27=IDC_CHECK_CDP21,button,1342242819
Control28=IDC_EDIT_P21HAVG,edit,1350631552
Control29=IDC_EDIT_P21VAVG,edit,1350631552
Control30=IDC_EDIT_P21FE,edit,1350631552
Control31=IDC_CHECK_CWP25,button,1476460547
Control32=IDC_CHECK_CRP25,button,1476460547
Control33=IDC_CHECK_CGP25,button,1476460547
Control34=IDC_CHECK_CBP25,button,1476460547
Control35=IDC_CHECK_CDP25,button,1342242819
Control36=IDC_EDIT_P25RECTSIDE,edit,1350631552
Control37=IDC_EDIT_P25FE,edit,1350631552
Control38=IDC_CHECK_CWP49,button,1342242819
Control39=IDC_CHECK_CRP49,button,1476460547
Control40=IDC_CHECK_CGP49,button,1476460547
Control41=IDC_CHECK_CBP49,button,1476460547
Control42=IDC_CHECK_CDP49,button,1476460547
Control43=IDC_CHECK_CWGM,button,1342242819
Control44=IDC_CHECK_CRGM,button,1342242819
Control45=IDC_CHECK_CGGM,button,1342242819
Control46=IDC_CHECK_CBGM,button,1342242819
Control47=IDC_CHECK_CDGM,button,1476460547
Control48=IDC_EDIT_GM1,edit,1350631552
Control49=IDC_EDIT_GM2,edit,1350631552
Control50=IDC_EDIT_GM3,edit,1350631552
Control51=IDC_CHECK_NITS,button,1342242819
Control52=IDC_EDIT_NITS,edit,1350631552
Control53=IDC_CHECK_CROSSTALK,button,1342242819
Control54=IDC_EDIT_CROSSTALK1,edit,1350631552
Control55=IDC_BUTTON_ADD,button,1342242816
Control56=IDC_BUTTON_DEL,button,1476460544
Control57=IDC_LIST_MSRITEMS,listbox,1353779585
Control58=IDC_CHECK_QUICKMSR,button,1342242819
Control59=IDOK,button,1476460545
Control60=IDCANCEL,button,1342242816
Control61=IDC_STATIC,static,1342308352
Control62=IDC_STATIC,static,1342308352
Control63=IDC_STATIC,static,1342308352
Control64=IDC_STATIC,static,1342308352
Control65=IDC_STATIC,static,1342308352
Control66=IDC_STATIC,static,1342308352
Control67=IDC_STATIC,static,1342308352
Control68=IDC_STATIC,static,1342308352
Control69=IDC_STATIC,static,1342308352
Control70=IDC_STATIC,static,1342308352
Control71=IDC_STATIC,static,1342308352
Control72=IDC_STATIC,static,1342308352
Control73=IDC_STATIC,static,1342308352
Control74=IDC_STATIC,static,1342308352
Control75=IDC_STATIC,static,1342308352
Control76=IDC_STATIC_W,static,1342308352
Control77=IDC_STATIC_R,static,1342308352
Control78=IDC_STATIC_G,static,1342308352
Control79=IDC_STATIC_B,static,1342308352
Control80=IDC_STATIC_D,static,1342308352
Control81=IDC_STATIC,button,1342177287
Control82=IDC_STATIC,button,1342177287
Control83=IDC_STATIC,static,1342308352
Control84=IDC_STATIC,static,1342308352
Control85=IDC_STATIC,static,1342308352
Control86=IDC_STATIC,static,1342308352
Control87=IDC_STATIC,static,1342308352
Control88=IDC_STATIC,static,1342308352
Control89=IDC_STATIC,static,1342308352
Control90=IDC_CHECK_JND,button,1342242819
Control91=IDC_EDIT_JND_GRAYVALUE,edit,1350631552
Control92=IDC_STATIC,static,1342308352
Control93=IDC_STATIC,button,1342177287
Control94=IDC_STATIC,button,1342177287
Control95=IDC_BUTTON_SELALL,button,1342242816
Control96=IDC_BUTTON_SELNO,button,1342242816
Control97=IDC_COMBO_SEL_NITS_KIND,combobox,1342242819

[DLG:IDD_EDIT_DIALOG]
Type=1
Class=CEnterValueDlg
ControlCount=4
Control1=IDC_EDIT_VALUE,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDC_STATIC_SOMETHING,static,1342308352
Control4=IDC_STATIC,static,1342308352

[CLS:CEnterValueDlg]
Type=0
HeaderFile=EnterValueDlg.h
ImplementationFile=EnterValueDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEnterValueDlg
VirtualFilter=dWC

[DLG:IDD_CASETUP_DIALOG]
Type=1
Class=CCaSetupDlg
ControlCount=43
Control1=IDOK,button,1073807361
Control2=IDCANCEL,button,1073807360
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMBO_DISPLAY_MODE,combobox,1344339971
Control10=IDC_COMBO_SYNC_MODE,combobox,1478557699
Control11=IDC_COMBO_AVERAGING_MODE,combobox,1478557699
Control12=IDC_COMBO_DISPLAY_DIGITS_MODE,combobox,1478557699
Control13=IDC_STATIC_CA_TYPE,static,1342312962
Control14=IDC_STATIC,button,1342177287
Control15=IDC_COMBO_DISPLAY_DEFAULT_STD,combobox,1478557699
Control16=IDC_STATIC_CA_VERSION,static,1342312962
Control17=IDC_STATIC_PROB_SNO,static,1342312962
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,button,1342177287
Control23=IDC_EDIT_DISPLAY_RANGE_COLOR1,edit,1484849280
Control24=IDC_STATIC,button,1342177287
Control25=IDC_STATIC,button,1342177287
Control26=IDC_EDIT_DISPLAY_RANGE_COLOR2,edit,1484849280
Control27=IDC_EDIT_DISPLAY_RANGE_FLICKER,edit,1484849280
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC_REF_PROB,static,1342312962
Control34=IDC_STATIC_CAL_PROB,static,1342312962
Control35=IDC_STATIC_REF_LV,static,1342312962
Control36=IDC_STATIC,static,1342308352
Control37=IDC_STATIC,static,1342308352
Control38=IDC_COMBO_CHANNEL_ID,combobox,1344339971
Control39=IDC_COMBO_CHANNEL_NUMBER,combobox,1344339971
Control40=IDC_STATIC_CAL_MODE,static,1342312962
Control41=IDC_STATIC_REF_X,static,1342312962
Control42=IDC_STATIC_REF_Y,static,1342312962
Control43=IDC_COMBO_BRIG_UNIT,combobox,1478557699

[CLS:CCaSetupDlg]
Type=0
HeaderFile=CaSetupDlg.h
ImplementationFile=CaSetupDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CCaSetupDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_BARCODE]
Type=1
Class=CReadBarCodeDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_COMBO_SELNO,combobox,1344339971
Control3=IDC_STATIC_BARCODE,static,1342308352

[CLS:CReadBarCodeDialog]
Type=0
HeaderFile=ReadBarCodeDialog.h
ImplementationFile=ReadBarCodeDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO_SELNO
VirtualFilter=dWC

