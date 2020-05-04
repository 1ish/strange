TEST_CASE("strange river create input boole", "[river_t]")
{
	try
	{
		auto river = river_t<>::create("true");
		REQUIRE(river.good());
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange tokenize boole", "[tokenizer_t]")
{
	try
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create("true"));
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

TEST_CASE("strange parse and generate boole", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("true")));
			auto river = river_t<>::create();
			expression.generate(1, 1, river);
			std__cout << "generated: " << river.to_string() << std::endl;
		}
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("false")));
			auto river = river_t<>::create();
			expression.generate(1, 1, river);
			std__cout << "generated: " << river.to_string() << std::endl;
		}
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("if(1,'yes','no')")));
			auto river = river_t<>::create();
			expression.generate(1, 1, river);
			std__cout << "generated: " << river.to_string() << std::endl;
		}
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and evaluate boole", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("true")));
		auto result = expression.evaluate_();
		REQUIRE(result);
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and evaluate booles", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("true"))).evaluate_();
			REQUIRE(result.type_() == yes().type_());
			REQUIRE(result.something());
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("false"))).evaluate_();
			REQUIRE(result.type_() == no().type_());
			REQUIRE(result.nothing());
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("if(1,'yes')"))).evaluate_();
			REQUIRE(result.is("yes"));
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("if(false,'yes')"))).evaluate_();
			REQUIRE(result.nothing());
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("if(1,'yes','no')"))).evaluate_();
			REQUIRE(result.is("yes"));
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("if(false,'yes','no')"))).evaluate_();
			REQUIRE(result.is("no"));
		}
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
