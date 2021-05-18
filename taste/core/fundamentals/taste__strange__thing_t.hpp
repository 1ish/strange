#ifndef COM_ONEISH__TASTE__STRANGE__THING_T_H
#define COM_ONEISH__TASTE__STRANGE__THING_T_H

namespace taste
{
	void testp(void* const symbol)
	{
		auto const param = reinterpret_cast<symbol_a* const>(symbol);
	}

	void test()
	{
		auto v = var(symbol_t::symbol__create_f("auto"));
		testp(v);
		auto tv = var(v.a.o->type(v));
		tv = v;
		auto s = val("test");
		auto t = val(s.a.o->type(s));
		auto u = val(s.a.o->add(s, t));
		val(u.a.o->add(u, val("y")));

		std__cout << ((symbol_t*)(u.a.d))->symbol << "\n";

		auto p = ptr(symbol_t::symbol__create_f("pointer"));
		auto q = ptr(symbol_t::symbol__create_f("q"));
		p = q;
		testp(p);
		testp(q);

		tv = s;
		//NO s = v;
		//NO s = t;
	}
}

TEST_CASE("strange thing", "[memory]")
{
	std__cout << "\nbefore test\n";
	taste::test();
	std__cout << "\nafter test\n";
}

#endif
