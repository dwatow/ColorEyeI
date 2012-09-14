# Microsoft Developer Studio Generated NMAKE File, Based on MsrItems.dsp
!IF "$(CFG)" == ""
CFG=MsrItems - Win32 Debug
!MESSAGE No configuration specified. Defaulting to MsrItems - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "MsrItems - Win32 Release" && "$(CFG)" != "MsrItems - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "MsrItems - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\MsrItems.exe" "$(OUTDIR)\MsrItems.tlb"


CLEAN :
	-@erase "$(INTDIR)\Bolt.obj"
	-@erase "$(INTDIR)\Bullet.obj"
	-@erase "$(INTDIR)\ca200srvr.obj"
	-@erase "$(INTDIR)\CA210.obj"
	-@erase "$(INTDIR)\Cartridge.obj"
	-@erase "$(INTDIR)\Circle.obj"
	-@erase "$(INTDIR)\CircleArc.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\MsrItemDlg.obj"
	-@erase "$(INTDIR)\MsrItems.obj"
	-@erase "$(INTDIR)\MsrItems.pch"
	-@erase "$(INTDIR)\MsrItems.res"
	-@erase "$(INTDIR)\MsrItems.tlb"
	-@erase "$(INTDIR)\MsrItemsDlg.obj"
	-@erase "$(INTDIR)\PatternDlg.obj"
	-@erase "$(INTDIR)\StaticText.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MsrItems.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\MsrItems.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\MsrItems.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MsrItems.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\MsrItems.pdb" /machine:I386 /out:"$(OUTDIR)\MsrItems.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bolt.obj" \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\ca200srvr.obj" \
	"$(INTDIR)\CA210.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\Circle.obj" \
	"$(INTDIR)\CircleArc.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\MsrItemDlg.obj" \
	"$(INTDIR)\MsrItems.obj" \
	"$(INTDIR)\MsrItemsDlg.obj" \
	"$(INTDIR)\PatternDlg.obj" \
	"$(INTDIR)\StaticText.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MsrItems.res"

"$(OUTDIR)\MsrItems.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MsrItems - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\MsrItems.exe" "$(OUTDIR)\MsrItems.tlb"


CLEAN :
	-@erase "$(INTDIR)\Bolt.obj"
	-@erase "$(INTDIR)\Bullet.obj"
	-@erase "$(INTDIR)\ca200srvr.obj"
	-@erase "$(INTDIR)\CA210.obj"
	-@erase "$(INTDIR)\Cartridge.obj"
	-@erase "$(INTDIR)\Circle.obj"
	-@erase "$(INTDIR)\CircleArc.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\MsrItemDlg.obj"
	-@erase "$(INTDIR)\MsrItems.obj"
	-@erase "$(INTDIR)\MsrItems.pch"
	-@erase "$(INTDIR)\MsrItems.res"
	-@erase "$(INTDIR)\MsrItems.tlb"
	-@erase "$(INTDIR)\MsrItemsDlg.obj"
	-@erase "$(INTDIR)\PatternDlg.obj"
	-@erase "$(INTDIR)\StaticText.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\MsrItems.exe"
	-@erase "$(OUTDIR)\MsrItems.ilk"
	-@erase "$(OUTDIR)\MsrItems.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\MsrItems.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\MsrItems.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MsrItems.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\MsrItems.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MsrItems.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Bolt.obj" \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\ca200srvr.obj" \
	"$(INTDIR)\CA210.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\Circle.obj" \
	"$(INTDIR)\CircleArc.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\MsrItemDlg.obj" \
	"$(INTDIR)\MsrItems.obj" \
	"$(INTDIR)\MsrItemsDlg.obj" \
	"$(INTDIR)\PatternDlg.obj" \
	"$(INTDIR)\StaticText.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\MsrItems.res"

"$(OUTDIR)\MsrItems.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MsrItems.dep")
!INCLUDE "MsrItems.dep"
!ELSE 
!MESSAGE Warning: cannot find "MsrItems.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MsrItems - Win32 Release" || "$(CFG)" == "MsrItems - Win32 Debug"
SOURCE=..\xMsrPoint\Bolt.cpp

"$(INTDIR)\Bolt.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\xMsrPoint\Bullet.cpp

"$(INTDIR)\Bullet.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\xMsrPoint\ca200srvr.cpp

"$(INTDIR)\ca200srvr.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\xMsrPoint\CA210.cpp

"$(INTDIR)\CA210.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\xMsrPoint\Cartridge.cpp

"$(INTDIR)\Cartridge.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\xMsrPoint\Circle.cpp

"$(INTDIR)\Circle.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\xMsrPoint\CircleArc.cpp

"$(INTDIR)\CircleArc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\DlgProxy.cpp

"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"


SOURCE=.\MsrItemDlg.cpp

"$(INTDIR)\MsrItemDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"


SOURCE=.\MsrItems.cpp

"$(INTDIR)\MsrItems.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"


SOURCE=.\MsrItems.odl

!IF  "$(CFG)" == "MsrItems - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\MsrItems.tlb" /mktyplib203 /win32 

"$(OUTDIR)\MsrItems.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MsrItems - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\MsrItems.tlb" /mktyplib203 /win32 

"$(OUTDIR)\MsrItems.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\MsrItems.rc

!IF  "$(CFG)" == "MsrItems - Win32 Release"


"$(INTDIR)\MsrItems.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\MsrItems.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "MsrItems - Win32 Debug"


"$(INTDIR)\MsrItems.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\MsrItems.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\MsrItemsDlg.cpp

"$(INTDIR)\MsrItemsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"


SOURCE=..\xMsrPoint\PatternDlg.cpp

"$(INTDIR)\PatternDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StaticText.cpp

"$(INTDIR)\StaticText.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\MsrItems.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "MsrItems - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\MsrItems.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MsrItems.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MsrItems - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\MsrItems.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MsrItems.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

