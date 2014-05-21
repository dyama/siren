@echo off

SET "SIRENSCRIPTPATH=%~dp0"
CALL "%SIRENSCRIPTPATH%\env-mruby.bat"

CALL "C:\Program Files\Microsoft Visual Studio 9.0\Common7\Tools\vsvars32.bat"

cd "%MRUBYROOT%"

ruby minirake clean
ruby minirake all

