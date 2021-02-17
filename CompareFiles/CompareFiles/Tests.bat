@echo off

SET Program="%~1"
if Program=="" (
	echo "Empty program argument"
	exit /B 1
)

REM Empty files test
%Program% Empty.txt Empty.txt > %TEMP%\output.txt
fc SuccessSample.txt %TEMP%\output.txt > null || goto err
echo Test 1 passed

REM Multiline equal file test
%Program% File1.txt File2.txt > %TEMP%\output.txt
fc SuccessSample.txt %TEMP%\output.txt > null || goto err
echo Test 2 passed

REM Multiline non equal file test
%Program% File3.txt File4.txt > %TEMP%\output.txt
fc FailSample.txt %TEMP%\output.txt > null || goto err
echo Test 3 passed

REM Only one file given test
%Program% File1.txt > nul && goto err
echo Test 4 passed

REM Without parameters test
%Program% > nul && goto err
echo Test 5 passed

REM Incorrect file test
%Program% File1.txt File123.txt > nul && goto err
echo Test 6 passed


echo Tests passed
exit /B 0

:err
echo Tests Failed
exit /B 1