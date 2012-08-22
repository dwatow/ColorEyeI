; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CXMsrPointDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "xMsrPoint.h"
ODLFile=xMsrPoint.odl

ClassCount=5
Class1=CXMsrPointApp
Class2=CXMsrPointDlg
Class3=CAboutDlg
Class4=CXMsrPointDlgAutoProxy

ResourceCount=4
Resource1=IDD_XMSRPOINT_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class5=CPatternDlg
Resource4=IDD_PATTERN_DIALOG

[CLS:CXMsrPointApp]
Type=0
HeaderFile=xMsrPoint.h
ImplementationFile=xMsrPoint.cpp
Filter=N

[CLS:CXMsrPointDlg]
Type=0
HeaderFile=xMsrPointDlg.h
ImplementationFile=xMsrPointDlg.cpp
Filter=D
LastObject=CXMsrPointDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=xMsrPointDlg.h
ImplementationFile=xMsrPointDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CXMsrPointDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_XMSRPOINT_DIALOG]
Type=1
Class=CXMsrPointDlg
ControlCount=21
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_SX,static,1342308352
Control3=IDC_STATIC_SY,static,1342308352
Control4=IDC_STATIC_L,static,1342308352
Control5=IDC_STATIC_T,static,1342308352
Control6=IDC_STATIC_DUV,static,1342308352
Control7=IDC_STATIC_DU,static,1342308352
Control8=IDC_STATIC_DV,static,1342308352
Control9=IDC_STATIC_X,static,1342308352
Control10=IDC_STATIC_Y,static,1342308352
Control11=IDC_STATIC_Z,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_BUTTON_MSR,button,1342242816
Control14=IDC_SLIDER1,msctls_trackbar32,1342242821
Control15=IDC_BUTTON1,button,1342242816
Control16=IDC_BUTTON2,button,1342242816
Control17=IDC_STATIC_ORIG,static,1342308352
Control18=IDC_STATIC_AREA,static,1342308352
Control19=IDC_STATIC_BKCLR,static,1342308352
Control20=IDC_STATIC_FLOWNUM,static,1342308352
Control21=IDC_STATIC_FLOWNO,static,1342308352

[CLS:CPatternDlg]
Type=0
HeaderFile=PatternDlg.h
ImplementationFile=PatternDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPatternDlg
VirtualFilter=dWC

[DLG:IDD_PATTERN_DIALOG]
Type=1
Class=CPatternDlg
ControlCount=0

