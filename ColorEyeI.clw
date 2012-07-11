; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColorEyeIDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ColorEyeI.h"
ODLFile=ColorEyeI.odl
LastPage=0

ClassCount=5
Class1=CColorEyeIApp
Class2=CColorEyeIDoc
Class3=CColorEyeIView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Resource3=IDD_PATTERN_DIALOG

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
LastObject=ID_MSR_ITEM

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
LastObject=CMainFrame
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
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

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

[DLG:IDD_PATTERN_DIALOG]
Type=1
Class=?
ControlCount=0

