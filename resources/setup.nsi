; Define the application name, version, and the output file
!define APP_NAME "NFOBuilder"
!define APP_VERSION "1.3.2"
!define INSTALLER_NAME "${APP_NAME}-windows.exe"

Name "${APP_NAME} Setup"
Caption "${APP_NAME} Setup"

; The directory where your application files are located
!define SOURCE_DIR "C:\Users\Admin\Desktop\NFOBuilder\release"

; Name of the executable
!define EXECUTABLE "NFO-Creator.exe"

; Outfile defines the name of the installer
OutFile "${INSTALLER_NAME}"

; Define default installation directory
InstallDir "$PROGRAMFILES\${APP_NAME}"

; Set a modern interface
!include "MUI2.nsh"

; Pages for the installer
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

; Uninstall page
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

; Sections define what to install
Section "MainSection" SEC01
  ; Set output path for installation files
  SetOutPath "$INSTDIR"

  ; Copy executable to installation directory
  File "${SOURCE_DIR}\${EXECUTABLE}"

  ; Copy other necessary files (Qt libraries, resources, etc.)
  File /r "${SOURCE_DIR}\*.*"

  ; Create shortcuts
  CreateShortcut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${EXECUTABLE}"
  CreateShortcut "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk" "$INSTDIR\${EXECUTABLE}"
  ; Uninstaller
  WriteUninstaller "$INSTDIR\uninstall.exe"

SectionEnd

; Uninstaller Section
Section "Uninstall"
  ; Delete files
  Delete "$INSTDIR\${EXECUTABLE}"
  Delete "$INSTDIR\*.*"

  ; Remove directories
  RMDir "$INSTDIR"

  ; Remove shortcuts
  Delete "$DESKTOP\${APP_NAME}.lnk"
  Delete "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk"

  ; Remove uninstaller
  Delete "$INSTDIR\uninstall.exe"
SectionEnd

; Installer Icon and Branding
Icon "C:\Users\Admin\Desktop\NFOBuilder\resources\plex-nfo.ico"
UninstallIcon "C:\Users\Admin\Desktop\NFOBuilder\resources\plex-nfo.ico"

