TEST_CASE("strange river create input symbol", "[river_t]")
{
	try
	{
		auto river = river_t<>::create("'this is symbolic'");
		REQUIRE(river.good());
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange tokenize symbol", "[tokenizer_t]")
{
	try
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create("'this is symbolic'"));
		for (auto const token : tokenizer)
		{
			std__cout << "token: " << cast<token_a<>>(token).report();
			REQUIRE(cast<token_a<>>(token));
		}
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate symbol", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("'this is symbolic'")));
		auto river = river_t<>::create();
		expression.generate(1, 1, river);
		std__cout << "generated: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and evaluate symbol", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("'this is symbolic'")));
		auto result = expression.evaluate_();
		REQUIRE(result.is("this is symbolic"));
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}
