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
		auto v = var(symbol_t::create_f("auto"));
		testp(v);
		auto tv = var(v.o->type(v));
		tv = v;
		auto s = sym("test");
		auto t = val(s.o->type(s));
		auto u = val(s.o->add(s, t));
		val(u.o->add(u, sym("y")));

		std__cout << ((symbol_t*)(u.t))->symbol << "\n";

		auto p = ptr(symbol_t::create_f("pointer"));
		auto q = ptr(symbol_t::create_f("q"));
		p = q;
		testp(p);
		testp(q);

		tv = s;
		//NO s = v;
		//NO s = t;
		auto value = val{ symbol_t::create_f("auto") };

		auto n = no<symbol_a>();
	}
}

TEST_CASE("strange thing", "[memory]")
{
	std__cout << "\nbefore test\n";
	taste::test();
	std__cout << "\nafter test\n";
}

#endif
