#pragma once

#include <cstdlib>
#include <iostream>

template <typename A>
struct str_core_value_c
{
    explicit inline str_core_value_c(A const& abstraction) :a(abstraction) {}

    inline ~str_core_value_c()
    {
        rel();
    }

    inline str_core_value_c(str_core_value_c const& original) :a(original.a)
    {
        ref();
    }

    inline str_core_value_c& operator=(str_core_value_c const& original)
    {
        if (a.d != original.a.d)
        {
            rel();
            a = original.a;
            ref();
        }
        return *this;
    }

    inline str_core_value_c& operator=(A const& abstraction)
    {
        if (a.d != abstraction.d)
        {
            rel();
            a = abstraction;
        }
        return *this;
    }

    inline operator A* ()
    {
        return &a;
    }

    inline void ref()
    {
        ++(a.d->refs);
    }

    inline void rel()
    {
        if (!--(a.d->refs))
        {
            a.o->free(&a); std::cout << "free\n";
            std::free(a.d);
        }
    }

    inline A ret()
    {
        ++(a.d->refs);
        return a;
    }

    A a;
};

template <typename A>
str_core_value_c<A const> val(A const& a)
{
    return str_core_value_c<A const>(a);
}

template <typename A>
str_core_value_c<A> var(A const& a)
{
    return str_core_value_c<A>(a);
}
