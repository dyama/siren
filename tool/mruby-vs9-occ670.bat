@echo off

REM OpenCASCADE 6.70 �� mruby �̃C���X�g�[���p�X��ݒ肵�܂��B

SET "SCRIPTPATH=%~dp0"
SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"
SET "OCCT670CASROOT=E:\occ\670\opencascade-6.7.0"

%OCCT670CASROOT%\msvc.bat vc9 win32 Release %SCRIPTPATH%\..\src\siren.sln
