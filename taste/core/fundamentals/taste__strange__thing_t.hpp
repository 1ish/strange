#ifndef COM_ONEISH__TASTE__STRANGE__THING_T_H
#define COM_ONEISH__TASTE__STRANGE__THING_T_H

namespace taste
{
	void testp(ptr<symbol_a>& symbol)
	{
		symbol.first_char();
	}

	var<symbol_a> testfun(con<symbol_a> const& a, con<symbol_a> const& b)
	{
		return a.add(b);
	}

	void testr(var<symbol_a>& param)
	{
		param.first_char();
	}

	void testcr(var<symbol_a> const& param)
	{
		param.first_char();
	}

	void test()
	{
		auto v = var(symbol_t::create("auto"));
		auto tv = var(v.type());
		tv = v;
		auto s = sym("test");
		auto t = s.type();
		auto u = s.add(t);
		u.add(sym("y"));

		std__cout << u.char_star() << "\n";

		auto p = ptr<symbol_a>{ symbol_t::create("pointer") };
		auto q = ptr<symbol_a>(symbol_t::create("q"));
		p.first_char();
		p = q;
		p.first_char();
		testp(p);
		testp(q);
		testr(sym("pointer").reference<var<symbol_a>>());
		testcr(sym("pointer"));
		auto const c = con<symbol_a>{ sym("const") };
		//NO testr(c);
		//NO testcr(c.reference<var<symbol_a>>());
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
		anysym.dynamic<con<symbol_a>>();
		anysym.dynamic<ptr<symbol_a>>();

		con<symbol_a> sss = sym("sss");
		auto res = sss.add(sym("2"));
		res = sss.add(sym("2"));
		res = sss.add(sym("2"));
		std__cout << "result: " << res.char_star() << "\n";
		con<any_a> aaa = sym("aaa");
		aaa.type();
		sss.type();
		res = sss.type();
		std__cout << "result: " << res.char_star() << "\n";
		auto vvv = sym("vvv");
		vvv.set_error(sym("error1"));
		vvv.set_error(sym("error2"));
		vvv.set_error(sym("error3"));
		res = vvv.error().reference<var<symbol_a>>();
		std__cout << "result: " << res.char_star() << "\n";
		vvv.something();
		vvv.not_equal(sym("other"));

		auto conul = con<forward_extractor_a<int64_t>>();
		conul.o->type(conul); //TODO
		auto nul = var<forward_extractor_a<int64_t>>();
		nul.o->type(nul); //TODO
		auto fwd = fit<forward_extractor_a<int64_t>>(nul);
		fwd.o->type(fwd); //TODO

		auto lock = create_lock<var<lock_a>>();
		auto unlock = create_lock<var<unlock_a>>();

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

		auto number = num<int64_t>(123);
		auto uns = num<uint64_t>(123);
		auto flt = num(1.23);
		auto number_data = number.data();
		auto uns_data = uns.data();
		auto flt_data = flt.data();

		int64_t an_int = 1;
		uint64_t a_uint = 2;
		double a_float = 3.45;
		auto number_ref = num_ref(an_int);
		auto uns_ref = num_ref(a_uint);
		auto flt_ref = num_ref(a_float);
		auto number_ref_data = number_ref.data();
		auto uns_ref_data = uns_ref.data();
		auto flt_ref_data = flt_ref.data();

		auto e1 = num<int64_t>(1).perform(&number_o<int64_t>::extractor);
		auto e11 = e1 + 10;
		std__cout << *e1 << "!=" << *e11 << "=" << (e1 != e11) << "\n";
		for (auto it = e1; it != e11; ++it)
		{
			std__cout << *it << "\n";
		}

		con<number_a<int64_t>> nc = num<int64_t>(123);
		var<number_a<int64_t>> nv{ nc };
		ptr<number_a<int64_t>> np{ nv };
		ptr<number_a<int64_t>> np2{ np };
		nc.extract();
		nv.extract();
		nv.mutate();
		np.extract();
		np.mutate();

		auto aoc = nc.address();
		auto aov = adr<var<number_a<int64_t>>>{ nv };
		auto aop = adr<ptr<number_a<int64_t>>>{ np };
		auto ff = fit<forward_extractor_a<int64_t>>{};
		auto aof = ff.address();
		auto bb = bit<bidirectional_extractor_a<int64_t>>{};
		auto aob = bb.address();
		auto rr = rat<random_access_extractor_a<int64_t>>{};
		auto aor = rr.address();

		auto oc = aoc.value();
		auto ov = aov.value();
		auto op = aop.value();
		auto of = aof.value();
		auto ob = aob.value();
		auto rv = aor.value();

		std::vector<int64_t> vec_int{ 1, 2, 3 };
		rat<contiguous_mutator_a<int64_t>> rvi = contiguous_mutator_t<std::vector<int64_t>::iterator, int64_t>::create(vec_int.begin());
		rat<contiguous_mutator_a<int64_t>> rve = contiguous_mutator_t<std::vector<int64_t>::iterator, int64_t>::create(vec_int.end());
		for (; rvi != rve; ++rvi)
		{
			std__cout << "*rvi" << *rvi << "\n";
		}

		auto col = queue_t<std::vector<int64_t>, int64_t>::create(vec_int);
		for (auto el : col.o->range(col))
		{
			std__cout << "qel:" << el << "\n";
		}

		auto lis = list_t<std::vector<int64_t>, int64_t>::create(vec_int);
		for (auto el : lis.o->range(lis))
		{
			std__cout << "lel:" << el << "\n";
		}

		auto tab = strange::table<int64_t, int64_t>();
		tab.o->update(tab, 1, 5);
		tab.o->update(tab, 3, 4);
		tab.o->update(tab, 2, 3);
		tab.o->update(tab, 1, 2);
		for (auto tup : tab.o->range(tab))
		{
			int64_t x1;
			int64_t y2;
			tup.o->destruct(tup, x1, y2);
			std__cout << "tup:" << x1 << "," << y2 << "\n";
		}
		for (auto pr : tab.o->pair_range(tab))
		{
			std__cout << "pr:" << pr.first << "," << pr.second << "\n";
		}

		auto otab = strange::ordered_table<int64_t, int64_t>();
		otab.o->update(otab, 1, 5);
		otab.o->update(otab, 3, 4);
		otab.o->update(otab, 2, 3);
		otab.o->update(otab, 1, 2);
		for (auto tup : otab.o->range(otab))
		{
			int64_t x1;
			int64_t y2;
			tup.o->destruct(tup, x1, y2);
			std__cout << "otup:" << x1 << "," << y2 << "\n";
		}
		for (auto pr : otab.o->pair_range(otab))
		{
			std__cout << "opr:" << pr.first << "," << pr.second << "\n";
		}

		auto utab = otab.o->pair_table(otab);
		for (auto tup : utab.o->range(utab))
		{
			int64_t x1;
			int64_t y2;
			tup.o->destruct(tup, x1, y2);
			std__cout << "utup:" << x1 << "," << y2 << "\n";
		}
		for (auto pr : utab.o->pair_range(utab))
		{
			std__cout << "upr:" << pr.first << "," << pr.second << "\n";
		}

		auto hut = text("hello universe");
		auto hwt = text("hello world");

		for (int xx = 0; xx < 3; ++xx)
		{
			for (auto ch : hut.o->range(hut))
			{
				std__cout << ch;
			}
			std__cout << " ";
			for (auto ch : hwt.o->range(hwt))
			{
				std__cout << ch;
			}
			std__cout << "\n";
			std::swap(hut, hwt);
		}
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
