; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSelExcelDlg
LastTemplate=CFileDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SelXls.h"
ODLFile=SelXls.odl

ClassCount=6
Class1=CSelXlsApp
Class2=CSelXlsDlg
Class3=CAboutDlg
Class4=CSelXlsDlgAutoProxy

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SELXLS_DIALOG
Class5=CSelExcelDlg
Class6=CFileDlg
Resource4=IDD_OMDTOEXCEL

[CLS:CSelXlsApp]
Type=0
HeaderFile=SelXls.h
ImplementationFile=SelXls.cpp
Filter=N
LastObject=IDC_STATIC_ITEMLIST

[CLS:CSelXlsDlg]
Type=0
HeaderFile=SelXlsDlg.h
ImplementationFile=SelXlsDlg.cpp
Filter=D
LastObject=IDC_BUTTON1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SelXlsDlg.h
ImplementationFile=SelXlsDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CSelXlsDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_SELXLS_DIALOG]
Type=1
Class=CSelXlsDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816

[CLS:CSelExcelDlg]
Type=0
HeaderFile=SelExcelDlg.h
ImplementationFile=SelExcelDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO_EXCELSELER
VirtualFilter=dWC

[CLS:CFileDlg]
Type=0
HeaderFile=FileDlg.h
ImplementationFile=FileDlg.cpp
BaseClass=CFileDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_OMDTOEXCEL]
Type=1
Class=CSelExcelDlg
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

