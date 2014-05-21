@echo off

SET "SIRENVCVER=vc9"
SET "SIRENPLATFORM=win32"
SET "OCCTCASROOT=E:\occ\670\opencascade-6.7.0"

REM ----------------------------------------------

SET "SIRENSCRIPTPATH=%~dp0"
CALL "%SIRENSCRIPTPATH%\env-mruby.bat"

SET "OCCTCASROOT=E:\occ\671\opencascade-6.7.1"

%OCCTCASROOT%\msvc.bat %SIRENVCVER% %SIRENPLATFORM% Release %SIRENSCRIPTPATH%\..\src\siren.sln

