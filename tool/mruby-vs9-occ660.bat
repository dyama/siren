@echo off

SET "SCRIPTPATH=%~dp0"

REM mruby のインストールパスを MRUBYROOT に設定します。
REM 環境に合わせて、適宜変更してください。

SET "MRUBYROOT=%SCRIPTPATH%\..\..\mruby_w32"

%SCRIPTPATH%\vs9-occ660.bat %SCRIPTPATH%\..\src\siren.sln
