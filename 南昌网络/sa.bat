
:loop
mkdt.py > B.in
B.exe < B.in > B.out
B2.exe < B.in > B.ans
fc B.out B.ans
if not errorlevel 1 goto loop
pause 
goto loop