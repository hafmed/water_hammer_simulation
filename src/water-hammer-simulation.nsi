Name "water-hammer-simulation HAFIANE Mohamed"
OutFile "water-hammer-simulation_win64_install_3.0.9.exe"

Icon "water-hammer-simulation.ico"
UninstallIcon "water-hammer-simulation.ico"


DirText "Uninstall previous version if exist and Choose directory for installing Simulation Coup de Belier (water-hammer-simulation) Ver "3.0.9 du 25-7-2021"

InstallDir "$PROGRAMFILES\water-hammer-simulation"

Section "Install"
  SetOutPath $INSTDIR
  File "C:\Qt6\6.1.1\mingw81_64\bin\libgcc_s_seh-1.dll"
  File "C:\Qt6\6.1.1\mingw81_64\bin\libstdc++-6.dll"
  File "C:\Qt6\6.1.1\mingw81_64\bin\libwinpthread-1.dll"
  File "C:\Qt6\6.1.1\mingw81_64\bin\Qt6Core.dll"
  File "C:\Qt6\6.1.1\mingw81_64\bin\Qt6Gui.dll"
  File "C:\Qt6\6.1.1\mingw81_64\bin\Qt6PrintSupport.dll"
  File "C:\Qt6\6.1.1\mingw81_64\bin\Qt6Widgets.dll"
CreateDirectory $INSTDIR\platforms
SetOutPath $INSTDIR\platforms
  File "C:\Qt6\6.1.1\mingw81_64\plugins\platforms\qwindows.dll"
SetOutPath $INSTDIR 
 File "..\CompilationWin\release\water-hammer-simulation.exe"
 File "water-hammer-simulation.ico"

  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\water-hammer-simulation" "DisplayName" "water-hammer-simulation"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\water-hammer-simulation" "UninstallString" "$INSTDIR\uninstall.exe"
  WriteUninstaller "uninstall.exe"
SectionEnd

Section "Shortcuts"
  CreateDirectory "$SMPROGRAMS\water-hammer-simulation"
  SetOutPath $INSTDIR
  CreateShortCut "$SMPROGRAMS\water-hammer-simulation\water-hammer-simulation.lnk""$INSTDIR\water-hammer-simulation.exe"
  SetOutPath $INSTDIR
  CreateShortCut "$DESKTOP\water-hammer-simulation.lnk""$INSTDIR\water-hammer-simulation.exe"
  CreateShortCut "$QUICKLAUNCH\water-hammer-simulation.lnk""$INSTDIR\water-hammer-simulation.exe"
  CreateShortCut "$SMPROGRAMS\water-hammer-simulation\uninstall_water-hammer-simulation.lnk""$INSTDIR\uninstall.exe"
SectionEnd

UninstallText "Close water-hammer-simulation if running ; This will uninstall water-hammer-simulation from your system"

Section "Uninstall"
DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\water-hammer-simulation"
Delete "$SMPROGRAMS\water-hammer-simulation\water-hammer-simulation.lnk"
Delete "$SMPROGRAMS\water-hammer-simulation\uninstall_water-hammer-simulation.lnk"
RmDir "$SMPROGRAMS\water-hammer-simulation"
Delete "$DESKTOP\water-hammer-simulation.lnk"
Delete "$QUICKLAUNCH\water-hammer-simulation.lnk"
Delete "$INSTDIR\libgcc_s_seh-1.dll"
Delete "$INSTDIR\libstdc++-6.dll"
Delete "$INSTDIR\libwinpthread-1.dll"
Delete "$INSTDIR\Qt6Core.dll"
Delete "$INSTDIR\Qt6Gui.dll"
Delete "$INSTDIR\Qt6PrintSupport.dll"
Delete "$INSTDIR\Qt6Widgets.dll"
Delete "$INSTDIR\platforms\qwindows.dll"
RMDir $INSTDIR\platforms
Delete "$INSTDIR\water-hammer-simulation.exe"
Delete "$INSTDIR\water-hammer-simulation.ico"
Delete "$INSTDIR\uninstall.exe"
RmDir "$INSTDIR"
SectionEnd
