TEST_CASE("strange river create input int", "[river_t]")
{
	try
	{
		auto river = river_t<>::create("42");
		REQUIRE(river.good());
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange tokenize int", "[tokenizer_t]")
{
	try
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create("42"));
		for (auto const token : tokenizer)
		{
			std__cout << "token: " << cast<token_a<>>(token).report();
			REQUIRE(cast<token_a<>>(token));
		}
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate int", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("42")));
		auto river = river_t<>::create();
		expression.generate(1, 1, river);
		std__cout << "generated: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and evaluate int", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("42")));
		auto result = expression.evaluate_();
		REQUIRE(check<number_data_a<int64_t>>(result));
		REQUIRE(cast<number_data_a<int64_t>>(result).extract() == 42);
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
