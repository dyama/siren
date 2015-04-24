@echo off

SET "SIRENSCRIPTPATH=%~dp0"
CALL "%SIRENSCRIPTPATH%\env-mruby.bat"

SET "OCCTCASROOT=E:\occ\680\opencascade-6.8.0"

CALL %OCCTCASROOT%\env.bat

echo Starting siren cad system ...

start %SIRENSCRIPTPATH%\..\src\siren_dotnet\bin\x86\Release\siren_dotnet.exe

