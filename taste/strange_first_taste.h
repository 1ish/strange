class A
{
public:
	A(char const*const lab)
		:label{ lab }
	{
		std__cout << "construct " << label << std::endl;
	}
	~A()
	{
		std__cout << "destruct " << label << std::endl;
	}
	char const*const label;
};

A make(char const*const label)
{
	return A{ label };
}

void fun(A& a, A& b)
{
	std__cout << "fun " << a.label << b.label << std::endl;
}

TEST_CASE("first", "[first]")
{
	std__cout << "first taste" << std::endl;
	A a{ "a" };
	auto x = make("1");
	auto y = make("2");
	fun(x, y);
	A b{ "b" };
	auto const brook = brook_t<int64_t>::create_();
	for (auto const& b : brook)
	{
		b.something();
	}
}

TEST_CASE("strange parse and generate cpp cat abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_cat_a.str")));
		auto river = river_t<>::create();
		expression.generate_cpp(1, 1, river, true, false); // declare
		std__cout << "generated cpp declare: " << river.to_string() << std::endl;
		river = river_t<>::create();
		expression.generate_cpp(1, 1, river, false, true); // define
		std__cout << "generated cpp define: " << river.to_string() << std::endl;
		river = river_t<>::create();
		expression.generate_cpp(1, 1, river, false, false);
		std__cout << "generated cpp execute: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}
