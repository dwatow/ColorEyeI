; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ColorEyeI.h"
ODLFile=ColorEyeI.odl
LastPage=0

ClassCount=13
Class1=CColorEyeIApp
Class2=CColorEyeIDoc
Class3=CColorEyeIView
Class4=CMainFrame

ResourceCount=10
Resource1=IDD_EDIT_DIALOG
Class5=CAboutDlg
<<<<<<< HEAD
Resource2=IDD_OMDTOEXCEL
Resource3=IDD_DIALOG_BARCODE
Resource4=IDD_ABOUTBOX
Resource5="IDD_OMDTOEXCEL"
Class6=CEnterValueDlg
Resource6=IDR_MAINFRAME
Resource7=IDD_MSR_ITEM
Class7=CCaSetupDlg
Resource8=IDD_CASETUP_DIALOG
=======
Resource2=IDD_OMDTOEXCEL
Resource3=IDD_DIALOG_BARCODE
Resource4=IDD_ABOUTBOX
Resource5="IDD_OMDTOEXCEL"
Class6=CEnterValueDlg
Resource6=IDR_MAINFRAME
Resource7=IDD_MSR_ITEM
Class7=CCaSetupDlg
Resource8=IDD_CASETUP_DIALOG
>>>>>>> DNA
Class8=CReadBarCodeDialog
Class9=CSelExcelDlg
Class10=CMsrItemDlg
Class11=CPatternDlg
Resource9=IDD_PATTERN_DIALOG
Class12=CMsrTableDlg
Class13=CBtm
Resource10=IDD_MSR_TABLE

[CLS:CColorEyeIApp]
Type=0
HeaderFile=ColorEyeI.h
ImplementationFile=ColorEyeI.cpp
Filter=N
LastObject=ID_MSR_ITEM
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
LastObject=ID_MSR_TABLE
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
Command9=ID_MSR_TABLE
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
Command3=ID_MSR_TABLE
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
Class=CSelExcelDlg
ControlCount=11
Control1=IDC_COMBO_EXCELSELER,combobox,1344339971
Control2=IDC_RADIO_NOWFILE,button,1342308361
Control3=IDC_RADIO_HDFILE,button,1342308361
Control4=IDC_BUTTON_FINDFILE,button,1476460544
Control5=IDOK,button,1476460545
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC_XLSDESCRIP,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_LIST_SELFILELIST,listbox,1488011521
Control10=IDC_STATIC_HDFILELIST,button,1342177543
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_PATTERN_DIALOG]
Type=1
Class=CPatternDlg
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
Class=CMsrItemDlg
ControlCount=95
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
Control16=IDC_CHECK_CDP9,button,1342242819
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
Control28=IDC_EDIT_P21FE,edit,1350631552
Control29=IDC_CHECK_CWP25,button,1476460547
Control30=IDC_CHECK_CRP25,button,1476460547
Control31=IDC_CHECK_CGP25,button,1476460547
Control32=IDC_CHECK_CBP25,button,1476460547
Control33=IDC_CHECK_CDP25,button,1342242819
Control34=IDC_EDIT_P25RECTSIDE,edit,1350631552
Control35=IDC_EDIT_P25FE,edit,1350631552
Control36=IDC_CHECK_CWP49,button,1342242819
Control37=IDC_CHECK_CRP49,button,1476460547
Control38=IDC_CHECK_CGP49,button,1476460547
Control39=IDC_CHECK_CBP49,button,1476460547
Control40=IDC_CHECK_CDP49,button,1476460547
Control41=IDC_CHECK_CWGM,button,1342242819
Control42=IDC_CHECK_CRGM,button,1342242819
Control43=IDC_CHECK_CGGM,button,1342242819
Control44=IDC_CHECK_CBGM,button,1342242819
Control45=IDC_CHECK_CDGM,button,1476460547
Control46=IDC_EDIT_GM1,edit,1350631552
Control47=IDC_EDIT_GM2,edit,1350631552
Control48=IDC_EDIT_GM3,edit,1350631552
Control49=IDC_CHECK_NITS,button,1342242819
Control50=IDC_EDIT_NITS,edit,1350631552
Control51=IDC_CHECK_CROSSTALK,button,1342242819
Control52=IDC_EDIT_CROSSTALK1,edit,1350631552
Control53=IDC_BUTTON_ADD,button,1342242816
Control54=IDC_BUTTON_DEL,button,1476460544
Control55=IDC_LIST_MSRITEMS,listbox,1353779585
Control56=IDC_CHECK_QUICKMSR,button,1342242819
Control57=IDOK,button,1476460545
Control58=IDCANCEL,button,1342242816
Control59=IDC_STATIC,static,1342308352
Control60=IDC_STATIC,static,1342308352
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
Control74=IDC_STATIC_W,static,1342308352
Control75=IDC_STATIC_R,static,1342308352
Control76=IDC_STATIC_G,static,1342308352
Control77=IDC_STATIC_B,static,1342308352
Control78=IDC_STATIC_D,static,1342308352
Control79=IDC_STATIC,button,1342177287
Control80=IDC_STATIC,button,1342177287
Control81=IDC_STATIC,static,1342308352
Control82=IDC_STATIC,static,1342308352
Control83=IDC_STATIC,static,1342308352
Control84=IDC_STATIC,static,1342308352
Control85=IDC_STATIC,button,1342177287
Control86=IDC_STATIC,button,1342177287
Control87=IDC_BUTTON_SELALL,button,1342242816
Control88=IDC_BUTTON_SELNO,button,1342242816
Control89=IDC_COMBO_SEL_NITS_KIND,combobox,1342242819
Control90=IDC_EDIT_P13FE,edit,1350631552
Control91=IDC_STATIC,static,1342308352
Control92=IDC_SW_P9FE,msctls_updown32,1342177441
Control93=IDC_STATIC_P9FECM,static,1476526080
Control94=IDC_STATIC_P9FE1OVER,static,1342308352
Control95=IDC_STATIC_P9,button,1342177287

[DLG:IDD_EDIT_DIALOG]
Type=1
Class=CEnterValueDlg
ControlCount=4
Control1=IDC_EDIT_VALUE,edit,1350639744
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
LastObject=CReadBarCodeDialog
VirtualFilter=dWC

[CLS:CSelExcelDlg]
Type=0
HeaderFile=SelExcelDlg.h
ImplementationFile=SelExcelDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSelExcelDlg
VirtualFilter=dWC

[CLS:CMsrItemDlg]
Type=0
HeaderFile=MsrItemDlg.h
ImplementationFile=MsrItemDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMsrItemDlg
VirtualFilter=dWC

[CLS:CPatternDlg]
Type=0
HeaderFile=PatternDlg.h
ImplementationFile=PatternDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPatternDlg

[DLG:IDD_MSR_TABLE]
Type=1
Class=CMsrTableDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BTN_SECF,button,1342242816
Control4=IDC_BTN_OQC_TPV,button,1342251008
Control5=IDC_BTN_RA,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,button,1342177287
Control10=IDC_TABLE_DESCRIP,static,1342308352
Control11=IDC_BTN_OQC_SEC,button,1342251008
Control12=IDC_STATIC,button,1342177287
Control13=IDC_BTN_OQC_TEST,button,1342251008

[CLS:CMsrTableDlg]
Type=0
HeaderFile=msrtabledlg.h
ImplementationFile=msrtabledlg.cpp
BaseClass=CDialog
LastObject=IDC_BTN_OQC_TEST
Filter=D
VirtualFilter=dWC

[CLS:CBtm]
Type=0
HeaderFile=Btm.h
ImplementationFile=Btm.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CBtm

