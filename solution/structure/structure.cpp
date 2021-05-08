// structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "str.h"
#include "str_core_value_c.hpp"

#include <iostream>

extern "C"
{
    void testp(void const* const symbol)
    {
        auto param = (str_core_symbol_a const* const)(symbol);
    }

    void test()
    {
        auto v = var(sym("auto"));
        testp(v);
        auto tv = var(v.a.o->type(v));
        tv = v;
        auto s = val(sym("test"));
        auto t = val(s.a.o->type(s));
        auto u = val(s.a.o->add(s, t));
        val(u.a.o->add(u, val(sym("y"))));

        std::cout << ((str_core_symbol_d*)(u.a.d))->symbol << "\n";
    }
}

int main()
{
    std::cout << "\nbefore test\n";
    test();
    std::cout << "\nafter test\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
