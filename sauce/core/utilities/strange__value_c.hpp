#ifndef COM_ONEISH__STRANGE__VALUE_C_H
#define COM_ONEISH__STRANGE__VALUE_C_H

#include <cstdlib>
#include <iostream>

template <typename A>
struct strange__value_c
{
    explicit inline strange__value_c(A const& abstraction) :a(abstraction)
    {
    }

    inline ~strange__value_c()
    {
        rel();
    }

    inline strange__value_c(strange__value_c const& original) :a(original.a)
    {
        ref();
    }

    inline strange__value_c& operator=(strange__value_c const& original)
    {
        if (a.d != original.a.d)
        {
            rel();
            a = original.a;
            ref();
        }
        return *this;
    }

    inline strange__value_c& operator=(A const& abstraction)
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
            a.o->free(&a);
            std::free(a.d); std::cout << "free\n";
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
inline strange__value_c<A const> val(A const& a)
{
    return strange__value_c<A const>(a);
}

template <typename A>
inline strange__value_c<A> var(A const& a)
{
    return strange__value_c<A>(a);
}

#endif
