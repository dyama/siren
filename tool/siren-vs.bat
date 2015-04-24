@echo off

SET "SIRENVCVER=vc9"
SET "SIRENPLATFORM=win32"

SET "SIRENSCRIPTPATH=%~dp0"
CALL "%SIRENSCRIPTPATH%\env-mruby.bat"

SET "OCCTCASROOT=E:\occ\680\opencascade-6.8.0"

%OCCTCASROOT%\msvc.bat %SIRENVCVER% %SIRENPLATFORM% Release %SIRENSCRIPTPATH%\..\src\siren.sln

