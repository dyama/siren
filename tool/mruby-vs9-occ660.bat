@echo off

SET "SCRIPTPATH=%~dp0"
SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"

%SCRIPTPATH%\vs9-occ660.bat %SCRIPTPATH%\..\src\siren.sln
