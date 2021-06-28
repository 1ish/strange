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

		std__cout << u.o->char_star(u) << "\n";

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

		auto const creator = symbol_a::creator(sym("strange"), sym("symbol"), sym("create_from_range"));
		REQUIRE(creator);
		auto const created = creator(con<range_a<>>{});

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
		std__cout << "result: " << res.o->char_star(res) << "\n";
		con<any_a> aaa = sym("aaa");
		aaa.pfm(&any_o::type);
		sss.pfm(&symbol_o::type);
		res = sss.pfm(&con<symbol_a>::operations::type);
		std__cout << "result: " << res.o->char_star(res) << "\n";
		auto vvv = sym("vvv");
		vvv.o->set_error(vvv, sym("error1"));
		vvv.pfm(&any_o::set_error, sym("error2"));
		vvv.pfm(&symbol_o::set_error, sym("error3"));
		res = vvv.pfm(&symbol_o::error).ref<var<symbol_a>>();
		std__cout << "result: " << res.o->char_star(res) << "\n";
		vvv.pfm(&symbol_o::something);
		vvv.pfm(&any_o::not_equal, sym("other"));

		auto nul = var<forward_extractor_a<int64_t>>();
		auto fwd = fit<forward_extractor_a<int64_t>>(nul);
		fwd.o->type(fwd);

		auto lock = lock_a::create();
		auto unlock = unlock_a::create();

		auto dv = dat<int64_t>();
		auto dv1 = dat(int64_t{ 1 });
		int64_t number_one = 1;
		auto dr = dat_ref(number_one);
		auto dp = dat_ptr(new int64_t(1));
		auto dd = dat_def<std::string>();

		REQUIRE(sym("this") == sym("this"));
		REQUIRE(sym("this") != sym("that"));
		std::unordered_set<var<symbol_a>> names = { sym("minime"), sym("pigsy") };
		std::set<var<symbol_a>> names2 = { sym("minime"), sym("pigsy") };

		auto number = num(123LL);
		auto uns = num(123ULL);
		auto flt = num(1.23);
		auto number_data = number.o->data(number);
		auto uns_data = uns.o->data(uns);
		auto flt_data = flt.o->data(flt);

		int64_t an_int = 1;
		uint64_t a_uint = 2;
		double a_float = 3.45;
		auto number_ref = num_ref(an_int);
		auto uns_ref = num_ref(a_uint);
		auto flt_ref = num_ref(a_float);
		auto number_ref_data = number_ref.o->data(number_ref);
		auto uns_ref_data = uns_ref.o->data(uns_ref);
		auto flt_ref_data = flt_ref.o->data(flt_ref);


	}
}

template <typename dim = int>
struct s0
{
	dim d_ = 0;
};

template <typename dim = int>
struct s1
{
	dim d_ = 1;
};

template <typename dim = int>
struct s2 : s1<dim>
{
	float d_ = 2.3f;
};

template <typename dim = int>
struct s3 : s0<dim>, s2<dim>
{
};

TEST_CASE("strange thing", "[memory]")
{
	std__cout << "\nbefore test\n";
	taste::test();
	std__cout << "\nafter test\n";

	s1 si1;
	s2 si2;
	s3 si3;
	s1<>& s1r2 = si2;
	s1<>& s1r3 = si3;

	std__cout << si1.d_ << " " << si2.d_ << " " << "si3.d_" << " " << s1r2.d_ << " " << s1r3.d_ << "\n";
}

#endif
