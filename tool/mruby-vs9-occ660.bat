@echo off

SET "SCRIPTPATH=%~dp0"

REM mruby �̃C���X�g�[���p�X�� MRUBYROOT �ɐݒ肵�܂��B
REM ���ɍ��킹�āA�K�X�ύX���Ă��������B

SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"

%SCRIPTPATH%\vs9-occ660.bat %SCRIPTPATH%\..\src\siren.sln
