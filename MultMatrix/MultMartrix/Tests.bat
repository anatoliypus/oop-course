REM @echo off

SET Program="%~1"
if Program=="" (
	echo "Bad program argument"
	exit /B 1
)

REM Good test
%Program% goodMatrix1.txt goodMatrix2.txt > %TEMP%\output.txt
fc goodResult.txt %TEMP%\output.txt > nul || goto err
echo Test 1 passed

REM Good test with big matrix
%Program% goodMatrix1.txt goodMatrix3.txt > %TEMP%\output.txt
fc goodResult.txt %TEMP%\output.txt > nul || goto err
echo Test 2 passed

REM Alphabetic values
%Program% goodMatrix1.txt badMatrix1.txt > nul && goto err
echo Test 3 passed

REM Wrong parameters
%Program% goodMatrix1.txt > nul && goto err
echo Test 4 passed

REM Lack of cols
%Program% goodMatrix1.txt badMatrix2.txt > nul && goto err
echo Test 5 passed

REM Lack of rows
%Program% goodMatrix1.txt badMatrix3.txt > nul && goto err
echo Test 6 passed

echo All tests passed
exit /B 0

:err
echo Tests failed
exit /B 1