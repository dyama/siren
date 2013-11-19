@echo off

REM OpenCASCADE 6.70 と mruby のインストールパスを設定します。

SET "SCRIPTPATH=%~dp0"
SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"
SET "OCCT670CASROOT=E:\occ\670\opencascade-6.7.0"

%OCCT670CASROOT%\msvc.bat vc9 win32 Release %SCRIPTPATH%\..\src\siren.sln
