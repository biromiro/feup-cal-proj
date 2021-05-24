
mkdir winbuild > nul

Xcopy view winbuild\view /E /H /C /I /Y > nul

cd winbuild
cmake ../  -G  "MinGW Makefiles"
cmake --build .

