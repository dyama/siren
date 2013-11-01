@ECHO OFF
echo occenv.bat

REM "�o�[�W�����̐ݒ�"

IF /I ["%1"] == [""] (
    SET "VERSION=654"
) ELSE (
    SET "VERSION=%1"
)
IF /I ["%2"] == ["DEBUG"] (
    SET "DEBUG=d"
) ELSE (
    SET "DEBUG="
)

REM "OCCT�{�̂ւ̃p�X��ݒ�"

SET "OCCBASE=C:\occ"
SET "CASROOT=%OCCBASE%\%VERSION%\ros"
SET "CSF_OPT_INC=%CASROOT%\inc"


IF /I ["%3"] == [""] (
    SET "PATH=%CASROOT%\win32\vc9\bin%DEBUG%;%PATH%"
    SET "CSF_OPT_LIB32=%CASROOT%\win32\vc9\lib"
    SET "CSF_OPT_LIB32D=%CASROOT%\win32\vc9\libd"
    SET "LIB=%CASROOT%\win32\vc9\lib%DEBUG%"
) ELSE (
    SET "PATH=%CASROOT%\win32\vc%3\bin%DEBUG%;%PATH%"
    SET "CSF_OPT_LIB32=%CASROOT%\win32\vc%3\lib"
    SET "CSF_OPT_LIB32D=%CASROOT%\win32\vc%3\libd"
    SET "LIB=%CASROOT%\win32\vc%3\lib%DEBUG%"
)
SET "INCLUDE=%CASROOT%\inc;%INCLUDE%""

REM "�T�[�h�p�[�e�B���C�u�����̃p�X"

SET "TPDIR=%CASROOT%\..\3rdparty"

SET "PATH=%TPDIR%\tcltk-85-32\bin;%PATH%"
SET "PATH=%TPDIR%\tbb30_018oss\bin\ia32\vc9;%PATH%"
SET "PATH=%TPDIR%\freeimage-vc9-32\bin;%PATH%"
SET "PATH=%TPDIR%\tcltk-85-32\bin;%PATH%"
SET "PATH=%TPDIR%\gl2ps-1.3.5-vc9-32\bin;%PATH%"

IF /I ["%VERSION%"] == ["654"] GOTO HOGE
IF /I ["%VERSION%"] == ["660"] GOTO HOGE
    REM OpenCASCADE 6.5.4 �ȊO
    SET "PATH=%TPDIR%\ftgl-2.1.2-vc9-32\bin;%PATH%"
    GOTO FUGA
:HOGE
    REM OpenCASCADE 6.5.4 �̏ꍇ
    SET "PATH=%TPDIR%\ftgl-2.1.3-vc9-32\bin;%PATH%"
    SET "PATH=%TPDIR%\freetype-2.4.10-vc9-32\bin;%PATH%"
:FUGA

REM 654�̎��A���̃R�[�h��freetype�̕��͊��ϐ�PATH�ɐݒ肳��邪
REM ftgl�̕��̓��[�J���ϐ��̕��ɐݒ肳��Ă���͗l�B���҂�����������Ȃ��B
REM IF /I ["%VERSION%"] == ["654"] (
REM     ECHO THIS IS VERSION 6.5.4
REM     SET "PATH=%TPDIR%\ftgl-2.1.3-vc9-32\bin;%PATH%"
REM     SET "PATH=%TPDIR%\freetype-2.4.10-vc9-32\bin;%PATH%"
REM ) ELSE (
REM     SET "PATH=%TPDIR%\ftgl-2.1.2-vc9-32\bin;%PATH%"
REM )

IF /I ["%DEBUG%"] == ["d"] (
    SET "COND=Debug"
) ELSE (
    SET "COND=Release"
)

ECHO OpenCASCADE%VERSION% %COND%
ECHO CASROOT is %CASROOT%.
ECHO Current PATH vars are:
ECHO %PATH% | sed s/;/\n/g


