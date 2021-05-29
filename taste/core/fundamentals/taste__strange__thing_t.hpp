#ifndef COM_ONEISH__TASTE__STRANGE__THING_T_H
#define COM_ONEISH__TASTE__STRANGE__THING_T_H

namespace taste
{
	void testp(ptr<symbol_a>& symbol)
	{
		symbol.o->first_char(symbol);
	}

	var<symbol_a> testfun(con<symbol_a> const& a, con<symbol_a> const& b)
	{
		return a.o->add(a, b);
	}

	void test()
	{
		auto v = var(symbol_t::create_f("auto"));
		auto tv = var(v.o->type(v));
		tv = v;
		auto s = sym("test");
		auto t = s.o->type(s);
		auto u = s.o->add(s, t);
		u.o->add(u, sym("y"));

		std__cout << ((symbol_t*)(u.t))->symbol << "\n";

		auto p = ptr<symbol_a>{ symbol_t::create_f("pointer") };
		auto q = ptr<symbol_a>(symbol_t::create_f("q"));
		p.o->first_char(p);
		p = q;
		p.o->first_char(p);
		testp(p);
		testp(q);

		tv = s;
		//NO s = v;
		//NO s = t;
		auto value = con<>{ symbol_t::create_f("auto") };

		auto n = con<symbol_a>();
		auto no = con<any_a>();

		auto const creator = symbol_a::creator_f(sym("strange"), sym("symbol"), sym("create_empty"));
		REQUIRE(creator);
		auto const created = creator();
		var<any_a> anything = sym("symbol");
		//NO var<symbol_a> symbol = thing_t::create_f();
		auto const test_fun = testfun(sym("test"), sym("fun"));
	}
}

TEST_CASE("strange thing", "[memory]")
{
	std__cout << "\nbefore test\n";
	taste::test();
	std__cout << "\nafter test\n";
}

#endif
