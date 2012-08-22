# Microsoft Developer Studio Project File - Name="MsrItems" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MsrItems - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MsrItems.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MsrItems.mak" CFG="MsrItems - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MsrItems - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MsrItems - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MsrItems - Win32 Release"

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
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
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

!ELSEIF  "$(CFG)" == "MsrItems - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# SUBTRACT CPP /Fr
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

# Name "MsrItems - Win32 Release"
# Name "MsrItems - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\xMsrPoint\Bolt.cpp
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\Bullet.cpp
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\ca200srvr.cpp
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\CA210.cpp
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\Cartridge.cpp
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\Circle.cpp
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\CircleArc.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\MsrItemDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MsrItems.cpp
# End Source File
# Begin Source File

SOURCE=.\MsrItems.odl
# End Source File
# Begin Source File

SOURCE=.\MsrItems.rc
# End Source File
# Begin Source File

SOURCE=.\MsrItemsDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\PatternDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StaticText.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\xMsrPoint\Bolt.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\Bullet.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\ca200srvr.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\CA210.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\Cartridge.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\Circle.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\CircleArc.h
# End Source File
# Begin Source File

SOURCE=.\DlgProxy.h
# End Source File
# Begin Source File

SOURCE=..\Enum.h
# End Source File
# Begin Source File

SOURCE=.\MsrItemDlg.h
# End Source File
# Begin Source File

SOURCE=.\MsrItems.h
# End Source File
# Begin Source File

SOURCE=.\MsrItemsDlg.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\PatternDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StaticText.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\StdAfx.h
# End Source File
# Begin Source File

SOURCE=..\xMsrPoint\xMsrPoint.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\MsrItems.ico
# End Source File
# Begin Source File

SOURCE=.\res\MsrItems.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\MsrItems.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
