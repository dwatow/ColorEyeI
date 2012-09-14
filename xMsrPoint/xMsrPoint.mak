# Microsoft Developer Studio Generated NMAKE File, Based on xMsrPoint.dsp
!IF "$(CFG)" == ""
CFG=xMsrPoint - Win32 Debug
!MESSAGE No configuration specified. Defaulting to xMsrPoint - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "xMsrPoint - Win32 Release" && "$(CFG)" != "xMsrPoint - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xMsrPoint.mak" CFG="xMsrPoint - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xMsrPoint - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "xMsrPoint - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "xMsrPoint - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\xMsrPoint.exe" "$(OUTDIR)\xMsrPoint.tlb" "$(OUTDIR)\xMsrPoint.bsc"


CLEAN :
	-@erase "$(INTDIR)\Bolt.obj"
	-@erase "$(INTDIR)\Bolt.sbr"
	-@erase "$(INTDIR)\Bullet.obj"
	-@erase "$(INTDIR)\Bullet.sbr"
	-@erase "$(INTDIR)\ca200srvr.obj"
	-@erase "$(INTDIR)\ca200srvr.sbr"
	-@erase "$(INTDIR)\CA210.obj"
	-@erase "$(INTDIR)\CA210.sbr"
	-@erase "$(INTDIR)\Cartridge.obj"
	-@erase "$(INTDIR)\Cartridge.sbr"
	-@erase "$(INTDIR)\Circle.obj"
	-@erase "$(INTDIR)\Circle.sbr"
	-@erase "$(INTDIR)\CircleArc.obj"
	-@erase "$(INTDIR)\CircleArc.sbr"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\DlgProxy.sbr"
	-@erase "$(INTDIR)\PatternDlg.obj"
	-@erase "$(INTDIR)\PatternDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\xMsrPoint.obj"
	-@erase "$(INTDIR)\xMsrPoint.pch"
	-@erase "$(INTDIR)\xMsrPoint.res"
	-@erase "$(INTDIR)\xMsrPoint.sbr"
	-@erase "$(INTDIR)\xMsrPoint.tlb"
	-@erase "$(INTDIR)\xMsrPointDlg.obj"
	-@erase "$(INTDIR)\xMsrPointDlg.sbr"
	-@erase "$(OUTDIR)\xMsrPoint.bsc"
	-@erase "$(OUTDIR)\xMsrPoint.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /vd0 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\xMsrPoint.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\xMsrPoint.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\xMsrPoint.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Bolt.sbr" \
	"$(INTDIR)\Bullet.sbr" \
	"$(INTDIR)\ca200srvr.sbr" \
	"$(INTDIR)\CA210.sbr" \
	"$(INTDIR)\Cartridge.sbr" \
	"$(INTDIR)\Circle.sbr" \
	"$(INTDIR)\CircleArc.sbr" \
	"$(INTDIR)\DlgProxy.sbr" \
	"$(INTDIR)\PatternDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\xMsrPoint.sbr" \
	"$(INTDIR)\xMsrPointDlg.sbr"

"$(OUTDIR)\xMsrPoint.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\xMsrPoint.pdb" /machine:I386 /out:"$(OUTDIR)\xMsrPoint.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bolt.obj" \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\ca200srvr.obj" \
	"$(INTDIR)\CA210.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\Circle.obj" \
	"$(INTDIR)\CircleArc.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\PatternDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\xMsrPoint.obj" \
	"$(INTDIR)\xMsrPointDlg.obj" \
	"$(INTDIR)\xMsrPoint.res"

"$(OUTDIR)\xMsrPoint.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "xMsrPoint - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\xMsrPoint.exe" "$(OUTDIR)\xMsrPoint.tlb" "$(OUTDIR)\xMsrPoint.bsc"


CLEAN :
	-@erase "$(INTDIR)\Bolt.obj"
	-@erase "$(INTDIR)\Bolt.sbr"
	-@erase "$(INTDIR)\Bullet.obj"
	-@erase "$(INTDIR)\Bullet.sbr"
	-@erase "$(INTDIR)\ca200srvr.obj"
	-@erase "$(INTDIR)\ca200srvr.sbr"
	-@erase "$(INTDIR)\CA210.obj"
	-@erase "$(INTDIR)\CA210.sbr"
	-@erase "$(INTDIR)\Cartridge.obj"
	-@erase "$(INTDIR)\Cartridge.sbr"
	-@erase "$(INTDIR)\Circle.obj"
	-@erase "$(INTDIR)\Circle.sbr"
	-@erase "$(INTDIR)\CircleArc.obj"
	-@erase "$(INTDIR)\CircleArc.sbr"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\DlgProxy.sbr"
	-@erase "$(INTDIR)\PatternDlg.obj"
	-@erase "$(INTDIR)\PatternDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\xMsrPoint.obj"
	-@erase "$(INTDIR)\xMsrPoint.pch"
	-@erase "$(INTDIR)\xMsrPoint.res"
	-@erase "$(INTDIR)\xMsrPoint.sbr"
	-@erase "$(INTDIR)\xMsrPoint.tlb"
	-@erase "$(INTDIR)\xMsrPointDlg.obj"
	-@erase "$(INTDIR)\xMsrPointDlg.sbr"
	-@erase "$(OUTDIR)\xMsrPoint.bsc"
	-@erase "$(OUTDIR)\xMsrPoint.exe"
	-@erase "$(OUTDIR)\xMsrPoint.ilk"
	-@erase "$(OUTDIR)\xMsrPoint.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\xMsrPoint.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\xMsrPoint.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\xMsrPoint.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Bolt.sbr" \
	"$(INTDIR)\Bullet.sbr" \
	"$(INTDIR)\ca200srvr.sbr" \
	"$(INTDIR)\CA210.sbr" \
	"$(INTDIR)\Cartridge.sbr" \
	"$(INTDIR)\Circle.sbr" \
	"$(INTDIR)\CircleArc.sbr" \
	"$(INTDIR)\DlgProxy.sbr" \
	"$(INTDIR)\PatternDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\xMsrPoint.sbr" \
	"$(INTDIR)\xMsrPointDlg.sbr"

"$(OUTDIR)\xMsrPoint.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\xMsrPoint.pdb" /debug /machine:I386 /out:"$(OUTDIR)\xMsrPoint.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Bolt.obj" \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\ca200srvr.obj" \
	"$(INTDIR)\CA210.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\Circle.obj" \
	"$(INTDIR)\CircleArc.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\PatternDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\xMsrPoint.obj" \
	"$(INTDIR)\xMsrPointDlg.obj" \
	"$(INTDIR)\xMsrPoint.res"

"$(OUTDIR)\xMsrPoint.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("xMsrPoint.dep")
!INCLUDE "xMsrPoint.dep"
!ELSE 
!MESSAGE Warning: cannot find "xMsrPoint.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "xMsrPoint - Win32 Release" || "$(CFG)" == "xMsrPoint - Win32 Debug"
SOURCE=.\Bolt.cpp

"$(INTDIR)\Bolt.obj"	"$(INTDIR)\Bolt.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\Bullet.cpp

"$(INTDIR)\Bullet.obj"	"$(INTDIR)\Bullet.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\ca200srvr.cpp

"$(INTDIR)\ca200srvr.obj"	"$(INTDIR)\ca200srvr.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\CA210.cpp

"$(INTDIR)\CA210.obj"	"$(INTDIR)\CA210.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\Cartridge.cpp

"$(INTDIR)\Cartridge.obj"	"$(INTDIR)\Cartridge.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\Circle.cpp

"$(INTDIR)\Circle.obj"	"$(INTDIR)\Circle.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\CircleArc.cpp

"$(INTDIR)\CircleArc.obj"	"$(INTDIR)\CircleArc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\DlgProxy.cpp

"$(INTDIR)\DlgProxy.obj"	"$(INTDIR)\DlgProxy.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\PatternDlg.cpp

"$(INTDIR)\PatternDlg.obj"	"$(INTDIR)\PatternDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "xMsrPoint - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /vd0 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\xMsrPoint.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\xMsrPoint.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "xMsrPoint - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\xMsrPoint.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\xMsrPoint.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\xMsrPoint.cpp

"$(INTDIR)\xMsrPoint.obj"	"$(INTDIR)\xMsrPoint.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"


SOURCE=.\xMsrPoint.odl

!IF  "$(CFG)" == "xMsrPoint - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\xMsrPoint.tlb" /mktyplib203 /win32 

"$(OUTDIR)\xMsrPoint.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "xMsrPoint - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\xMsrPoint.tlb" /mktyplib203 /win32 

"$(OUTDIR)\xMsrPoint.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\xMsrPoint.rc

!IF  "$(CFG)" == "xMsrPoint - Win32 Release"


"$(INTDIR)\xMsrPoint.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\xMsrPoint.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "xMsrPoint - Win32 Debug"


"$(INTDIR)\xMsrPoint.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\xMsrPoint.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\xMsrPointDlg.cpp

"$(INTDIR)\xMsrPointDlg.obj"	"$(INTDIR)\xMsrPointDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\xMsrPoint.pch"



!ENDIF 

