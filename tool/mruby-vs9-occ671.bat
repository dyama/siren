@echo off

REM OpenCASCADE 6.7.1 �� mruby �̃C���X�g�[���p�X��ݒ肵�܂��B

SET "SCRIPTPATH=%~dp0"
SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"
SET "OCCT671CASROOT=E:\occ\671\opencascade-6.7.1"

%OCCT671CASROOT%\msvc.bat vc9 win32 Release %SCRIPTPATH%\..\src\siren.sln
