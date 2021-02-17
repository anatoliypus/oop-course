SET Program="%~1"

if Program=="" (
	echo "You have to specify program`s path in the first argument"
	exit /B 1
)

REM Empty file test
%Program% Empty.txt %Temp%\output.txt
fc Empty.txt %Temp%\output.txt > nul || goto err
echo Test 1 passed

REM Non empty file test
%Program% Data.txt %Temp%\output.txt
fc Data.txt %Temp%\output.txt > nul || goto err
echo Test 2 passed

REM Missing output file test
%Program% Data.txt && goto err
echo Test 3 passed

REM Missing arguments test
%Program% && goto err
echo Test 4 passed

REM Incorrect input file test
%Program% MissingFile.txt %Temp%\output.txt && goto err
echo Test 5 passed

echo Tests succesfully passed
exit /B 0

:err
echo Tests failed
exit /B 1