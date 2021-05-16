export PATH=/c/sdavis3/clang/clang_9.0.0/bin:$PATH
export LD_LIBRARY_PATH=/c/sdavis3/clang/clang_9.0.0/lib:$LD_LIBRARY_PATH
clang++ -std=c++17 `find .. -name \*.cpp` -lpthread -I../../GSL/include
