# Microsoft Developer Studio Project File - Name="ColorEyeI" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ColorEyeI - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ColorEyeI.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ColorEyeI.mak" CFG="ColorEyeI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ColorEyeI - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ColorEyeI - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ColorEyeI - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "ColorEyeI - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ColorEyeI - Win32 Release"
# Name "ColorEyeI - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\xMsrPoint\Bolt.cpp
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\Bullet.cpp
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\ca200srvr.cpp
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\CA210.cpp
# End Source File
# Begin Source File

SOURCE=.\Ca210sim.cpp
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\Cartridge.cpp
# End Source File
# Begin Source File

SOURCE=.\CaSetupDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\Circle.cpp
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\CircleArc.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorEyeI.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorEyeI.odl
# End Source File
# Begin Source File

SOURCE=.\ColorEyeI.rc
# End Source File
# Begin Source File

SOURCE=.\ColorEyeIDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorEyeIView.cpp
# End Source File
# Begin Source File

SOURCE=.\DataChain.cpp
# End Source File
# Begin Source File

SOURCE=.\EnterValueDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\excel.cpp
# End Source File
# Begin Source File

SOURCE=.\SelXls\FileDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MsrItems\MsrItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OmdFile\OmdFile1.cpp
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\PatternDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SelXls\SelExcelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MsrItems\StaticText.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Table.cpp
# End Source File
# Begin Source File

SOURCE=.\OmdFile\TxtFile.cpp
# End Source File
# Begin Source File

SOURCE=.\SelXls\xlef.cpp
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsGamma.cpp
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsOQC1.cpp
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsRA1.cpp
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsSEC1.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\xMsrPoint\Bolt.h
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\Bullet.h
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\ca200srvr.h
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\CA210.h
# End Source File
# Begin Source File

SOURCE=.\Ca210sim.h
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\Cartridge.h
# End Source File
# Begin Source File

SOURCE=.\CaSetupDlg.h
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\Circle.h
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\CircleArc.h
# End Source File
# Begin Source File

SOURCE=.\ColorEyeI.h
# End Source File
# Begin Source File

SOURCE=.\ColorEyeIDoc.h
# End Source File
# Begin Source File

SOURCE=.\ColorEyeIView.h
# End Source File
# Begin Source File

SOURCE=.\DataChain.h
# End Source File
# Begin Source File

SOURCE=.\EnterValueDlg.h
# End Source File
# Begin Source File

SOURCE=.\Enum.h
# End Source File
# Begin Source File

SOURCE=.\excel.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\FileDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MsrItems\MsrItemDlg.h
# End Source File
# Begin Source File

SOURCE=.\OmdFile\OmdFile1.h
# End Source File
# Begin Source File

SOURCE=.\xMsrPoint\PatternDlg.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\SelExcelDlg.h
# End Source File
# Begin Source File

SOURCE=.\MsrItems\StaticText.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Table.h
# End Source File
# Begin Source File

SOURCE=.\OmdFile\TxtFile.h
# End Source File
# Begin Source File

SOURCE=.\VersionNo.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\xlef.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsFile2.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsGamma.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsOQC1.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsRA1.h
# End Source File
# Begin Source File

SOURCE=.\SelXls\XlsSEC1.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ColorEye.ico
# End Source File
# Begin Source File

SOURCE=.\res\ColorEyeI.ico
# End Source File
# Begin Source File

SOURCE=.\res\ColorEyeI.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ColorEyeIDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ColorEyeI.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\VerCtrl.dsm
# End Source File
# End Target
# End Project
