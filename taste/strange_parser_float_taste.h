TEST_CASE("strange river create input float", "[river_t]")
{
	try
	{
		auto river = river_t<>::create("29.7");
		REQUIRE(river.good());
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange tokenize float", "[tokenizer_t]")
{
	try
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create("29.7"));
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

TEST_CASE("strange parse and generate float", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("29.7")));
		auto river = river_t<>::create();
		expression.generate(1, 1, river);
		std__cout << "generated: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and evaluate float", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("29.7")));
		auto result = expression.evaluate_();
		REQUIRE(check<number_data_a<double>>(result));
		REQUIRE(cast<number_data_a<double>>(result).extract() == 29.7);
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
