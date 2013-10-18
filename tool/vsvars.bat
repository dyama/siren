@ECHO OFF
echo vsvars.bat

SET "VSTOOL="
IF /I ["%1"] == [""]   SET "VSTOOL=%VS100COMNTOOLS%"
IF /I ["%1"] == ["10"] SET "VSTOOL=%VS100COMNTOOLS%"
IF /I ["%1"] == ["9"]  SET "VSTOOL=%VS90COMNTOOLS%"
IF /I ["%1"] == ["8"]  SET "VSTOOL=%VS80COMNTOOLS%"
IF /I ["%1"] == ["2010"] SET "VSTOOL=%VS100COMNTOOLS%"
IF /I ["%1"] == ["2008"]  SET "VSTOOL=%VS90COMNTOOLS%"
IF /I ["%1"] == ["2005"]  SET "VSTOOL=%VS80COMNTOOLS%"

IF /I ["%VSTOOL%"] == [""] GOTO END

IF NOT EXIST "%VSTOOL%\vsvars32.bat" GOTO END
CALL "%VSTOOL%\vsvars32.bat" > NUL

