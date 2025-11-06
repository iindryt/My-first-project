cmake CMakeLists.txt
cmake --install .
cmake -- build .
copy src\studentai_*.txt Debug\studentai_*.txt
cd Debug\
Studentu_programa.exe
pause