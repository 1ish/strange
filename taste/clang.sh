export PATH=/c/sdavis3/clang/clang_9.0.0/bin:$PATH
export LD_LIBRARY_PATH=/c/sdavis3/clang/clang_9.0.0/lib:$LD_LIBRARY_PATH
clang++ -std=c++14 strange_taste.cpp ../sauce/core/fundamentals/abstractions/strange__any_a.cpp ../sauce/core/fundamentals/abstractions/strange__symbol_a.cpp ../sauce/core/fundamentals/things/strange__symbol_t.cpp ../sauce/core/fundamentals/things/strange__thing_t.cpp -lpthread -I../../GSL/include
