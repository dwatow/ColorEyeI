# Microsoft Developer Studio Generated NMAKE File, Based on ColorEyeI.dsp
!IF "$(CFG)" == ""
CFG=ColorEyeI - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ColorEyeI - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ColorEyeI - Win32 Release" && "$(CFG)" != "ColorEyeI - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ColorEyeI - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ColorEyeI.exe" "$(OUTDIR)\ColorEyeI.tlb" "$(OUTDIR)\ColorEyeI.pch" "$(OUTDIR)\ColorEyeI.bsc"


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
	-@erase "$(INTDIR)\ColorEyeI.obj"
	-@erase "$(INTDIR)\ColorEyeI.pch"
	-@erase "$(INTDIR)\ColorEyeI.res"
	-@erase "$(INTDIR)\ColorEyeI.sbr"
	-@erase "$(INTDIR)\ColorEyeI.tlb"
	-@erase "$(INTDIR)\ColorEyeIDoc.obj"
	-@erase "$(INTDIR)\ColorEyeIDoc.sbr"
	-@erase "$(INTDIR)\ColorEyeIView.obj"
	-@erase "$(INTDIR)\ColorEyeIView.sbr"
	-@erase "$(INTDIR)\DataChain.obj"
	-@erase "$(INTDIR)\DataChain.sbr"
	-@erase "$(INTDIR)\EnterValueDlg.obj"
	-@erase "$(INTDIR)\EnterValueDlg.sbr"
	-@erase "$(INTDIR)\excel.obj"
	-@erase "$(INTDIR)\excel.sbr"
	-@erase "$(INTDIR)\FileDlg.obj"
	-@erase "$(INTDIR)\FileDlg.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MsrItemDlg.obj"
	-@erase "$(INTDIR)\MsrItemDlg.sbr"
	-@erase "$(INTDIR)\OmdFile1.obj"
	-@erase "$(INTDIR)\OmdFile1.sbr"
	-@erase "$(INTDIR)\PatternDlg.obj"
	-@erase "$(INTDIR)\PatternDlg.sbr"
	-@erase "$(INTDIR)\SelExcelDlg.obj"
	-@erase "$(INTDIR)\SelExcelDlg.sbr"
	-@erase "$(INTDIR)\StaticText.obj"
	-@erase "$(INTDIR)\StaticText.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\Table.obj"
	-@erase "$(INTDIR)\Table.sbr"
	-@erase "$(INTDIR)\TxtFile.obj"
	-@erase "$(INTDIR)\TxtFile.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\xlef.obj"
	-@erase "$(INTDIR)\xlef.sbr"
	-@erase "$(INTDIR)\XlsGamma.obj"
	-@erase "$(INTDIR)\XlsGamma.sbr"
	-@erase "$(INTDIR)\XlsOQC1.obj"
	-@erase "$(INTDIR)\XlsOQC1.sbr"
	-@erase "$(INTDIR)\XlsRA1.obj"
	-@erase "$(INTDIR)\XlsRA1.sbr"
	-@erase "$(INTDIR)\XlsSEC1.obj"
	-@erase "$(INTDIR)\XlsSEC1.sbr"
	-@erase "$(OUTDIR)\ColorEyeI.bsc"
	-@erase "$(OUTDIR)\ColorEyeI.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\ColorEyeI.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ColorEyeI.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Bolt.sbr" \
	"$(INTDIR)\Bullet.sbr" \
	"$(INTDIR)\ca200srvr.sbr" \
	"$(INTDIR)\CA210.sbr" \
	"$(INTDIR)\Cartridge.sbr" \
	"$(INTDIR)\Circle.sbr" \
	"$(INTDIR)\CircleArc.sbr" \
	"$(INTDIR)\ColorEyeI.sbr" \
	"$(INTDIR)\ColorEyeIDoc.sbr" \
	"$(INTDIR)\ColorEyeIView.sbr" \
	"$(INTDIR)\DataChain.sbr" \
	"$(INTDIR)\EnterValueDlg.sbr" \
	"$(INTDIR)\excel.sbr" \
	"$(INTDIR)\FileDlg.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MsrItemDlg.sbr" \
	"$(INTDIR)\OmdFile1.sbr" \
	"$(INTDIR)\PatternDlg.sbr" \
	"$(INTDIR)\SelExcelDlg.sbr" \
	"$(INTDIR)\StaticText.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\Table.sbr" \
	"$(INTDIR)\TxtFile.sbr" \
	"$(INTDIR)\xlef.sbr" \
	"$(INTDIR)\XlsGamma.sbr" \
	"$(INTDIR)\XlsOQC1.sbr" \
	"$(INTDIR)\XlsRA1.sbr" \
	"$(INTDIR)\XlsSEC1.sbr"

"$(OUTDIR)\ColorEyeI.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ColorEyeI.pdb" /machine:I386 /out:"$(OUTDIR)\ColorEyeI.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Bolt.obj" \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\ca200srvr.obj" \
	"$(INTDIR)\CA210.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\Circle.obj" \
	"$(INTDIR)\CircleArc.obj" \
	"$(INTDIR)\ColorEyeI.obj" \
	"$(INTDIR)\ColorEyeIDoc.obj" \
	"$(INTDIR)\ColorEyeIView.obj" \
	"$(INTDIR)\DataChain.obj" \
	"$(INTDIR)\EnterValueDlg.obj" \
	"$(INTDIR)\excel.obj" \
	"$(INTDIR)\FileDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MsrItemDlg.obj" \
	"$(INTDIR)\OmdFile1.obj" \
	"$(INTDIR)\PatternDlg.obj" \
	"$(INTDIR)\SelExcelDlg.obj" \
	"$(INTDIR)\StaticText.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Table.obj" \
	"$(INTDIR)\TxtFile.obj" \
	"$(INTDIR)\xlef.obj" \
	"$(INTDIR)\XlsGamma.obj" \
	"$(INTDIR)\XlsOQC1.obj" \
	"$(INTDIR)\XlsRA1.obj" \
	"$(INTDIR)\XlsSEC1.obj" \
	"$(INTDIR)\ColorEyeI.res"

"$(OUTDIR)\ColorEyeI.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ColorEyeI - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ColorEyeI.exe" "$(OUTDIR)\ColorEyeI.tlb" "$(OUTDIR)\ColorEyeI.pch" "$(OUTDIR)\ColorEyeI.bsc"


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
	-@erase "$(INTDIR)\ColorEyeI.obj"
	-@erase "$(INTDIR)\ColorEyeI.pch"
	-@erase "$(INTDIR)\ColorEyeI.res"
	-@erase "$(INTDIR)\ColorEyeI.sbr"
	-@erase "$(INTDIR)\ColorEyeI.tlb"
	-@erase "$(INTDIR)\ColorEyeIDoc.obj"
	-@erase "$(INTDIR)\ColorEyeIDoc.sbr"
	-@erase "$(INTDIR)\ColorEyeIView.obj"
	-@erase "$(INTDIR)\ColorEyeIView.sbr"
	-@erase "$(INTDIR)\DataChain.obj"
	-@erase "$(INTDIR)\DataChain.sbr"
	-@erase "$(INTDIR)\EnterValueDlg.obj"
	-@erase "$(INTDIR)\EnterValueDlg.sbr"
	-@erase "$(INTDIR)\excel.obj"
	-@erase "$(INTDIR)\excel.sbr"
	-@erase "$(INTDIR)\FileDlg.obj"
	-@erase "$(INTDIR)\FileDlg.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MsrItemDlg.obj"
	-@erase "$(INTDIR)\MsrItemDlg.sbr"
	-@erase "$(INTDIR)\OmdFile1.obj"
	-@erase "$(INTDIR)\OmdFile1.sbr"
	-@erase "$(INTDIR)\PatternDlg.obj"
	-@erase "$(INTDIR)\PatternDlg.sbr"
	-@erase "$(INTDIR)\SelExcelDlg.obj"
	-@erase "$(INTDIR)\SelExcelDlg.sbr"
	-@erase "$(INTDIR)\StaticText.obj"
	-@erase "$(INTDIR)\StaticText.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\Table.obj"
	-@erase "$(INTDIR)\Table.sbr"
	-@erase "$(INTDIR)\TxtFile.obj"
	-@erase "$(INTDIR)\TxtFile.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\xlef.obj"
	-@erase "$(INTDIR)\xlef.sbr"
	-@erase "$(INTDIR)\XlsGamma.obj"
	-@erase "$(INTDIR)\XlsGamma.sbr"
	-@erase "$(INTDIR)\XlsOQC1.obj"
	-@erase "$(INTDIR)\XlsOQC1.sbr"
	-@erase "$(INTDIR)\XlsRA1.obj"
	-@erase "$(INTDIR)\XlsRA1.sbr"
	-@erase "$(INTDIR)\XlsSEC1.obj"
	-@erase "$(INTDIR)\XlsSEC1.sbr"
	-@erase "$(OUTDIR)\ColorEyeI.bsc"
	-@erase "$(OUTDIR)\ColorEyeI.exe"
	-@erase "$(OUTDIR)\ColorEyeI.ilk"
	-@erase "$(OUTDIR)\ColorEyeI.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MTd /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x404 /fo"$(INTDIR)\ColorEyeI.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ColorEyeI.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Bolt.sbr" \
	"$(INTDIR)\Bullet.sbr" \
	"$(INTDIR)\ca200srvr.sbr" \
	"$(INTDIR)\CA210.sbr" \
	"$(INTDIR)\Cartridge.sbr" \
	"$(INTDIR)\Circle.sbr" \
	"$(INTDIR)\CircleArc.sbr" \
	"$(INTDIR)\ColorEyeI.sbr" \
	"$(INTDIR)\ColorEyeIDoc.sbr" \
	"$(INTDIR)\ColorEyeIView.sbr" \
	"$(INTDIR)\DataChain.sbr" \
	"$(INTDIR)\EnterValueDlg.sbr" \
	"$(INTDIR)\excel.sbr" \
	"$(INTDIR)\FileDlg.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MsrItemDlg.sbr" \
	"$(INTDIR)\OmdFile1.sbr" \
	"$(INTDIR)\PatternDlg.sbr" \
	"$(INTDIR)\SelExcelDlg.sbr" \
	"$(INTDIR)\StaticText.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\Table.sbr" \
	"$(INTDIR)\TxtFile.sbr" \
	"$(INTDIR)\xlef.sbr" \
	"$(INTDIR)\XlsGamma.sbr" \
	"$(INTDIR)\XlsOQC1.sbr" \
	"$(INTDIR)\XlsRA1.sbr" \
	"$(INTDIR)\XlsSEC1.sbr"

"$(OUTDIR)\ColorEyeI.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ColorEyeI.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ColorEyeI.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Bolt.obj" \
	"$(INTDIR)\Bullet.obj" \
	"$(INTDIR)\ca200srvr.obj" \
	"$(INTDIR)\CA210.obj" \
	"$(INTDIR)\Cartridge.obj" \
	"$(INTDIR)\Circle.obj" \
	"$(INTDIR)\CircleArc.obj" \
	"$(INTDIR)\ColorEyeI.obj" \
	"$(INTDIR)\ColorEyeIDoc.obj" \
	"$(INTDIR)\ColorEyeIView.obj" \
	"$(INTDIR)\DataChain.obj" \
	"$(INTDIR)\EnterValueDlg.obj" \
	"$(INTDIR)\excel.obj" \
	"$(INTDIR)\FileDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MsrItemDlg.obj" \
	"$(INTDIR)\OmdFile1.obj" \
	"$(INTDIR)\PatternDlg.obj" \
	"$(INTDIR)\SelExcelDlg.obj" \
	"$(INTDIR)\StaticText.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Table.obj" \
	"$(INTDIR)\TxtFile.obj" \
	"$(INTDIR)\xlef.obj" \
	"$(INTDIR)\XlsGamma.obj" \
	"$(INTDIR)\XlsOQC1.obj" \
	"$(INTDIR)\XlsRA1.obj" \
	"$(INTDIR)\XlsSEC1.obj" \
	"$(INTDIR)\ColorEyeI.res"

"$(OUTDIR)\ColorEyeI.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ColorEyeI.dep")
!INCLUDE "ColorEyeI.dep"
!ELSE 
!MESSAGE Warning: cannot find "ColorEyeI.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ColorEyeI - Win32 Release" || "$(CFG)" == "ColorEyeI - Win32 Debug"
SOURCE=.\xMsrPoint\Bolt.cpp

"$(INTDIR)\Bolt.obj"	"$(INTDIR)\Bolt.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\xMsrPoint\Bullet.cpp

"$(INTDIR)\Bullet.obj"	"$(INTDIR)\Bullet.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\xMsrPoint\ca200srvr.cpp

"$(INTDIR)\ca200srvr.obj"	"$(INTDIR)\ca200srvr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\xMsrPoint\CA210.cpp

"$(INTDIR)\CA210.obj"	"$(INTDIR)\CA210.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\xMsrPoint\Cartridge.cpp

"$(INTDIR)\Cartridge.obj"	"$(INTDIR)\Cartridge.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\xMsrPoint\Circle.cpp

"$(INTDIR)\Circle.obj"	"$(INTDIR)\Circle.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\xMsrPoint\CircleArc.cpp

"$(INTDIR)\CircleArc.obj"	"$(INTDIR)\CircleArc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\ColorEyeI.cpp

"$(INTDIR)\ColorEyeI.obj"	"$(INTDIR)\ColorEyeI.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ColorEyeI.odl

!IF  "$(CFG)" == "ColorEyeI - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\ColorEyeI.tlb" /mktyplib203 /win32 

"$(OUTDIR)\ColorEyeI.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ColorEyeI - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\ColorEyeI.tlb" /mktyplib203 /win32 

"$(OUTDIR)\ColorEyeI.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ColorEyeI.rc

!IF  "$(CFG)" == "ColorEyeI - Win32 Release"


"$(INTDIR)\ColorEyeI.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\ColorEyeI.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "ColorEyeI - Win32 Debug"


"$(INTDIR)\ColorEyeI.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x404 /fo"$(INTDIR)\ColorEyeI.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\ColorEyeIDoc.cpp

"$(INTDIR)\ColorEyeIDoc.obj"	"$(INTDIR)\ColorEyeIDoc.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ColorEyeIView.cpp

"$(INTDIR)\ColorEyeIView.obj"	"$(INTDIR)\ColorEyeIView.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\DataChain.cpp

"$(INTDIR)\DataChain.obj"	"$(INTDIR)\DataChain.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\EnterValueDlg.cpp

"$(INTDIR)\EnterValueDlg.obj"	"$(INTDIR)\EnterValueDlg.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\excel.cpp

"$(INTDIR)\excel.obj"	"$(INTDIR)\excel.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SelXls\FileDlg.cpp

"$(INTDIR)\FileDlg.obj"	"$(INTDIR)\FileDlg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MsrItems\MsrItemDlg.cpp

"$(INTDIR)\MsrItemDlg.obj"	"$(INTDIR)\MsrItemDlg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\OmdFile\OmdFile1.cpp

"$(INTDIR)\OmdFile1.obj"	"$(INTDIR)\OmdFile1.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\xMsrPoint\PatternDlg.cpp

"$(INTDIR)\PatternDlg.obj"	"$(INTDIR)\PatternDlg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\SelXls\SelExcelDlg.cpp

"$(INTDIR)\SelExcelDlg.obj"	"$(INTDIR)\SelExcelDlg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MsrItems\StaticText.cpp

"$(INTDIR)\StaticText.obj"	"$(INTDIR)\StaticText.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ColorEyeI - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GR /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ColorEyeI.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ColorEyeI.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ColorEyeI - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\ColorEyeI.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ColorEyeI.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Table.cpp

"$(INTDIR)\Table.obj"	"$(INTDIR)\Table.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\OmdFile\TxtFile.cpp

"$(INTDIR)\TxtFile.obj"	"$(INTDIR)\TxtFile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\SelXls\xlef.cpp

"$(INTDIR)\xlef.obj"	"$(INTDIR)\xlef.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\SelXls\XlsGamma.cpp

"$(INTDIR)\XlsGamma.obj"	"$(INTDIR)\XlsGamma.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\SelXls\XlsOQC1.cpp

"$(INTDIR)\XlsOQC1.obj"	"$(INTDIR)\XlsOQC1.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\SelXls\XlsRA1.cpp

"$(INTDIR)\XlsRA1.obj"	"$(INTDIR)\XlsRA1.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\SelXls\XlsSEC1.cpp

"$(INTDIR)\XlsSEC1.obj"	"$(INTDIR)\XlsSEC1.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

