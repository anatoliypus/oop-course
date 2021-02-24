@echo off

SET Program="%~1"

REM Wrong parameters given 1
%Program% 101 101 > nul && goto err
echo Test 1 passed

REM Wrong parameters given 2
%Program% > nul && goto err
echo Test 2 passed

REM Wrong parameters given 3
%Program% 101abc > nul && goto err
echo Test 3 passed

REM Wrong parameters given 4
%Program% 123 > nul && goto err
echo Test 4 passed

REM Good input 1
%Program% 1 > %TEMP%\output.txt
fc Good1.txt %TEMP%\output.txt > nul || goto err
echo Test 5 passed

REM Good input 2
%Program% 0 > %TEMP%\output.txt
fc Good2.txt %TEMP%\output.txt > nul || goto err
echo Test 6 passed

REM Good input 3
%Program% 101 > %TEMP%\output.txt
fc Good3.txt %TEMP%\output.txt > nul || goto err
echo Test 7 passed

echo Tests passed
exit /B 0

:err
echo Tests failed
exit /B 1
