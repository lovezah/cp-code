g++ -std=c++17 data.cpp -o data -g
g++ -std=c++17 std.cpp -o std -g
g++ -std=c++17 slow.cpp -o slow -g
:loop
	data.exe > data.in
	std.exe < data.in > std.out
	slow.exe < data.in > slow.out
	fc std.out slow.out
if not errorlevel 1 goto loop
pause
goto loop