
:loop
maker.py > B.in
J.exe < B.in > B.out
bl.exe < B.in > B.ans
fc B.out B.ans
if not errorlevel 1 goto loop
pause 
goto loop