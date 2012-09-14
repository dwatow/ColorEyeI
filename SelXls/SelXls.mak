# Microsoft Developer Studio Generated NMAKE File, Based on SelXls.dsp
!IF "$(CFG)" == ""
CFG=SelXls - Win32 Debug
!MESSAGE No configuration specified. Defaulting to SelXls - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "SelXls - Win32 Release" && "$(CFG)" != "SelXls - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SelXls.mak" CFG="SelXls - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SelXls - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SelXls - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "SelXls - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\SelXls.exe" "$(OUTDIR)\SelXls.tlb" "$(OUTDIR)\SelXls.pch"


CLEAN :
	-@erase "$(INTDIR)\Bullet.obj"
	-@erase "$(INTDIR)\Cartridge.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\excel.obj"
	-@erase "$(INTDIR)\FileDlg.obj"
	-@erase "$(INTDIR)\OmdFile1.obj"
	-@erase "$(INTDIR)\SelExcelDlg.obj"
	-@erase "$(INTDIR)\SelXls.obj"
	-@erase "$(INTDIR)\SelXls.pch"
	-@erase "$(INTDIR)\SelXls.res"
	-@erase "$(INTDIR)\SelXls.tlb"
	-@erase "$(INTDIR)\SelXlsDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TxtFile.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\xlef.obj"
	-@erase "$(INTDIR)\XlsFile2.obj"
	-@erase "$(INTDIR)\XlsOQC1.obj"
	-@erase "$(INTDIR)\XlsRA1.obj"
	-@erase "$(INTDIR)\XlsSEC1.obj"
	-@erase "$(OUTDIR)\SelXls.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\SelXls.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SelXls.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\SelXls.pdb" /machine:I386 /out:"$(OUTDIR)\SelXls.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\excel.obj" \
	"$(INTDIR)\FileDlg.obj" \
	"$(INTDIR)\OmdFile1.obj" \
	"$(INTDIR)\SelExcelDlg.obj" \
	"$(INTDIR)\SelXls.obj" \
	"$(INTDIR)\SelXlsDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TxtFile.obj" \
	"$(INTDIR)\xlef.obj" \
	"$(INTDIR)\XlsFile2.obj" \
	"$(INTDIR)\XlsOQC1.obj" \
	"$(INTDIR)\XlsRA1.obj" \
	"$(INTDIR)\XlsSEC1.obj" \
	"$(INTDIR)\SelXls.res"

"$(OUTDIR)\SelXls.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\SelXls.exe" "$(OUTDIR)\SelXls.tlb" "$(OUTDIR)\SelXls.pch" "$(OUTDIR)\SelXls.bsc"


CLEAN :
	-@erase "$(INTDIR)\Bullet.obj"
	-@erase "$(INTDIR)\Bullet.sbr"
	-@erase "$(INTDIR)\Cartridge.obj"
	-@erase "$(INTDIR)\Cartridge.sbr"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\DlgProxy.sbr"
	-@erase "$(INTDIR)\excel.obj"
	-@erase "$(INTDIR)\excel.sbr"
	-@erase "$(INTDIR)\FileDlg.obj"
	-@erase "$(INTDIR)\FileDlg.sbr"
	-@erase "$(INTDIR)\OmdFile1.obj"
	-@erase "$(INTDIR)\OmdFile1.sbr"
	-@erase "$(INTDIR)\SelExcelDlg.obj"
	-@erase "$(INTDIR)\SelExcelDlg.sbr"
	-@erase "$(INTDIR)\SelXls.obj"
	-@erase "$(INTDIR)\SelXls.pch"
	-@erase "$(INTDIR)\SelXls.res"
	-@erase "$(INTDIR)\SelXls.sbr"
	-@erase "$(INTDIR)\SelXls.tlb"
	-@erase "$(INTDIR)\SelXlsDlg.obj"
	-@erase "$(INTDIR)\SelXlsDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TxtFile.obj"
	-@erase "$(INTDIR)\TxtFile.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\xlef.obj"
	-@erase "$(INTDIR)\xlef.sbr"
	-@erase "$(INTDIR)\XlsFile2.obj"
	-@erase "$(INTDIR)\XlsFile2.sbr"
	-@erase "$(INTDIR)\XlsOQC1.obj"
	-@erase "$(INTDIR)\XlsOQC1.sbr"
	-@erase "$(INTDIR)\XlsRA1.obj"
	-@erase "$(INTDIR)\XlsRA1.sbr"
	-@erase "$(INTDIR)\XlsSEC1.obj"
	-@erase "$(INTDIR)\XlsSEC1.sbr"
	-@erase "$(OUTDIR)\SelXls.bsc"
	-@erase "$(OUTDIR)\SelXls.exe"
	-@erase "$(OUTDIR)\SelXls.ilk"
	-@erase "$(OUTDIR)\SelXls.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\SelXls.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SelXls.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Bullet.sbr" \
	"$(INTDIR)\Cartridge.sbr" \
	"$(INTDIR)\DlgProxy.sbr" \
	"$(INTDIR)\excel.sbr" \
	"$(INTDIR)\FileDlg.sbr" \
	"$(INTDIR)\OmdFile1.sbr" \
	"$(INTDIR)\SelExcelDlg.sbr" \
	"$(INTDIR)\SelXls.sbr" \
	"$(INTDIR)\SelXlsDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TxtFile.sbr" \
	"$(INTDIR)\xlef.sbr" \
	"$(INTDIR)\XlsFile2.sbr" \
	"$(INTDIR)\XlsOQC1.sbr" \
	"$(INTDIR)\XlsRA1.sbr" \
	"$(INTDIR)\XlsSEC1.sbr"

"$(OUTDIR)\SelXls.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\SelXls.pdb" /debug /machine:I386 /out:"$(OUTDIR)\SelXls.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\excel.obj" \
	"$(INTDIR)\FileDlg.obj" \
	"$(INTDIR)\OmdFile1.obj" \
	"$(INTDIR)\SelExcelDlg.obj" \
	"$(INTDIR)\SelXls.obj" \
	"$(INTDIR)\SelXlsDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TxtFile.obj" \
	"$(INTDIR)\xlef.obj" \
	"$(INTDIR)\XlsFile2.obj" \
	"$(INTDIR)\XlsOQC1.obj" \
	"$(INTDIR)\XlsRA1.obj" \
	"$(INTDIR)\XlsSEC1.obj" \
	"$(INTDIR)\SelXls.res"

"$(OUTDIR)\SelXls.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("SelXls.dep")
!INCLUDE "SelXls.dep"
!ELSE 
!MESSAGE Warning: cannot find "SelXls.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "SelXls - Win32 Release" || "$(CFG)" == "SelXls - Win32 Debug"
SOURCE=..\xMsrPoint\Bullet.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\Bullet.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\Bullet.obj"	"$(INTDIR)\Bullet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\xMsrPoint\Cartridge.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\Cartridge.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\Cartridge.obj"	"$(INTDIR)\Cartridge.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\DlgProxy.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\DlgProxy.obj"	"$(INTDIR)\DlgProxy.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\excel.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\excel.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\excel.obj"	"$(INTDIR)\excel.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\FileDlg.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\FileDlg.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\FileDlg.obj"	"$(INTDIR)\FileDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=..\OmdFile\OmdFile1.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\OmdFile1.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\OmdFile1.obj"	"$(INTDIR)\OmdFile1.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\SelExcelDlg.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\SelExcelDlg.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\SelExcelDlg.obj"	"$(INTDIR)\SelExcelDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\SelXls.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\SelXls.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\SelXls.obj"	"$(INTDIR)\SelXls.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\SelXls.odl

!IF  "$(CFG)" == "SelXls - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\SelXls.tlb" /mktyplib203 /win32 

"$(OUTDIR)\SelXls.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\SelXls.tlb" /mktyplib203 /win32 

"$(OUTDIR)\SelXls.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\SelXls.rc

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\SelXls.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\SelXls.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\SelXls.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\SelXls.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\SelXlsDlg.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\SelXlsDlg.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\SelXlsDlg.obj"	"$(INTDIR)\SelXlsDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\SelXls.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\SelXls.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\SelXls.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\SelXls.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=..\OmdFile\TxtFile.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\TxtFile.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\TxtFile.obj"	"$(INTDIR)\TxtFile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\xlef.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\xlef.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\xlef.obj"	"$(INTDIR)\xlef.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XlsFile2.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\XlsFile2.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\XlsFile2.obj"	"$(INTDIR)\XlsFile2.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XlsOQC1.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\XlsOQC1.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\XlsOQC1.obj"	"$(INTDIR)\XlsOQC1.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XlsRA1.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\XlsRA1.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\XlsRA1.obj"	"$(INTDIR)\XlsRA1.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XlsSEC1.cpp

!IF  "$(CFG)" == "SelXls - Win32 Release"


"$(INTDIR)\XlsSEC1.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "SelXls - Win32 Debug"


"$(INTDIR)\XlsSEC1.obj"	"$(INTDIR)\XlsSEC1.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

