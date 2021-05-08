#ifndef COM_ONEISH__TASTE__STRANGE__THING_T_H
#define COM_ONEISH__TASTE__STRANGE__THING_T_H

extern "C"
{
    void testp(void const* const symbol)
    {
        auto const param = reinterpret_cast<strange__symbol_a const* const>(symbol);
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

        std__cout << ((strange__symbol_d*)(u.a.d))->symbol << "\n";
    }
}

TEST_CASE("strange thing", "[memory]")
{
    std__cout << "\nbefore test\n";
    test();
    std__cout << "\nafter test\n";
}

#endif
