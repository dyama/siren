@ECHO OFF
echo occcmd.bat

CALL occenv.bat %1 %2

START cmd.exe /k cd "%CASROOT%"

