#ifndef COM_ONEISH__TASTE__STRANGE__THING_T_H
#define COM_ONEISH__TASTE__STRANGE__THING_T_H

namespace taste
{
	void testp(ptr<symbol_a>& symbol)
	{
		symbol.o->first_char(symbol.val<con<symbol_a>>());
	}

	var<symbol_a> testfun(con<symbol_a> const& a, con<symbol_a> const& b)
	{
		return a.o->add(a, b);
	}

	void testr(var<symbol_a>& param)
	{
		param.o->first_char(param);
	}

	void testcr(var<symbol_a> const& param)
	{
		param.o->first_char(param);
	}

	void test()
	{
		auto v = var(symbol_t::create("auto"));
		auto tv = var(v.o->type(v));
		tv = v;
		auto s = sym("test");
		auto t = s.o->type(s);
		auto u = s.o->add(s, t);
		u.o->add(u, sym("y"));

		std__cout << u.o->to_char_star(u) << "\n";

		auto p = ptr<symbol_a>{ symbol_t::create("pointer") };
		auto q = ptr<symbol_a>(symbol_t::create("q"));
		p.o->first_char(p.val<con<symbol_a>>());
		p = q;
		p.o->first_char(p.val<con<symbol_a>>());
		testp(p);
		testp(q);
		testr(sym("pointer").ref<var<symbol_a>>());
		testcr(sym("pointer"));
		auto const c = con<symbol_a>{ sym("const") };
		//NO testr(c);
		//NO testcr(c.ref<var<symbol_a>>());
		//NO testcr(c);

		tv = s;
		//NO s = v;
		//NO s = t;
		auto value = con<>{ symbol_t::create("auto") };

		auto n = con<symbol_a>();
		auto no = con<any_a>();

		auto const creator = symbol_a::creator(sym("strange"), sym("symbol"), sym("create_empty"));
		REQUIRE(creator);
		auto const created = creator();
		var<any_a> anything = sym("symbol");
		//NO var<symbol_a> symbol = thing_t::create();
		auto const test_fun = testfun(sym("test"), sym("fun"));

		var<> anysym = sym("s");
		anysym.dyn<con<symbol_a>>();
		anysym.dyn<ptr<symbol_a>>();

		con<symbol_a> sss = sym("sss");
		auto res = sss.pfm(&con<symbol_a>::operations::add, sym("2"));
		res = sss.pfm(&symbol_a::operations::add, sym("2"));
		res = sss.pfm(&symbol_o::add, sym("2"));
		std__cout << "result: " << res.o->to_char_star(res) << "\n";
		con<any_a> aaa = sym("aaa");
		aaa.pfm(&any_o::type);
		sss.pfm(&symbol_o::type);
		res = sss.pfm(&con<symbol_a>::operations::type);
		std__cout << "result: " << res.o->to_char_star(res) << "\n";
		auto vvv = sym("vvv");
		vvv.o->set_error(vvv, sym("error1"));
		vvv.pfm(&any_o::set_error, sym("error2"));
		vvv.pfm(&symbol_o::set_error, sym("error3"));
		res = vvv.pfm(&symbol_o::error).ref<var<symbol_a>>();
		std__cout << "result: " << res.o->to_char_star(res) << "\n";
		vvv.pfm(&symbol_o::something);
		vvv.pfm(&any_o::not_equal, sym("other"));
		auto nul = var<forward_extractor_a<int64_t>>();
		auto fwd = fit<forward_extractor_a<int64_t>>(nul);
		fwd.o->type(fwd);
	}
}

TEST_CASE("strange thing", "[memory]")
{
	std__cout << "\nbefore test\n";
	taste::test();
	std__cout << "\nafter test\n";
}

#endif
