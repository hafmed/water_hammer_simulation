Name "water-hammer-simulation HAFIANE Mohamed"
OutFile "water-hammer-simulation_win64_install_1.9.0.exe"

Icon "water-hammer-simulation.ico"
UninstallIcon "water-hammer-simulation.ico"


DirText "Uninstall previous version if exist and Choose directory for installing Simulation Coup de Belier (water-hammer-simulation) Ver 1.9.0 du 1-9-2020"

InstallDir "$PROGRAMFILES\water-hammer-simulation"

Section "Install"
  SetOutPath $INSTDIR
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\libgcc_s_seh-1.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\libstdc++-6.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\libwinpthread-1.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Core.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Gui.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5PrintSupport.dll"
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\bin\Qt5Widgets.dll"
CreateDirectory $INSTDIR\platforms
SetOutPath $INSTDIR\platforms
  File "C:\Qt\Qt5.12.0\5.12.0\mingw73_64\plugins\platforms\qwindows.dll"
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
Delete "$INSTDIR\Qt5Core.dll"
Delete "$INSTDIR\Qt5Gui.dll"
Delete "$INSTDIR\Qt5PrintSupport.dll"
Delete "$INSTDIR\Qt5Widgets.dll"
Delete "$INSTDIR\platforms\qwindows.dll"
RMDir $INSTDIR\platforms
Delete "$INSTDIR\water-hammer-simulation.exe"
Delete "$INSTDIR\water-hammer-simulation.ico"
Delete "$INSTDIR\uninstall.exe"
RmDir "$INSTDIR"
SectionEnd
