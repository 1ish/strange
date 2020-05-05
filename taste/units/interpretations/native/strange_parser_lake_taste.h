TEST_CASE("strange river create input lake", "[river_t]")
{
	try
	{
		auto river = river_t<>::create("\"Lake Atitlan\"");
		REQUIRE(river.good());
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange tokenize lake", "[tokenizer_t]")
{
	try
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create("\"Lake Atitlan\""));
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

TEST_CASE("strange parse and generate lake", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("\"Lake Atitlan\"")));
		auto river = river_t<>::create();
		expression.generate(1, 1, river);
		std__cout << "generated: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and evaluate lake", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("\"Lake Atitlan\"")));
		auto result = expression.evaluate_();
		REQUIRE(check<lake_a<int8_t>>(result));
		REQUIRE(lake::to_string(cast<lake_a<int8_t>>(result)) == "Lake Atitlan");
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
