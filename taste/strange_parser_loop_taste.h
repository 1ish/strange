TEST_CASE("strange tokenize loop", "[tokenizer_t]")
{
	try
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create("for(x:=1,x<=10,x++,$$strange::river::out[].write_[\"ab\"])"));
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

TEST_CASE("strange parse and generate loops", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("while(true, break())")));
			auto river = river_t<>::create();
			expression.generate(1, 1, river);
			std__cout << "generated: " << river.to_string() << std::endl;
		}
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("do(true, false)")));
			auto river = river_t<>::create();
			expression.generate(1, 1, river);
			std__cout << "generated: " << river.to_string() << std::endl;
		}
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("for(true,false,true,false)")));
			auto river = river_t<>::create();
			expression.generate(1, 1, river);
			std__cout << "generated: " << river.to_string() << std::endl;
		}
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("for_range(thing :# [\"x\",\"y\",\"z\"], $$strange::river::out[].write_[thing])")));
			auto river = river_t<>::create();
			expression.generate(1, 1, river);
			std__cout << "generated: " << river.to_string() << std::endl;
		}
		{
			auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("for_range(thing := [\"x\",\"y\",\"z\"], $$strange::river::out[].write_[thing])")));
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

TEST_CASE("strange parse and evaluate loop", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create("while(true, break())")));
		auto result = expression.evaluate_();
		REQUIRE(!result);
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and evaluate loops", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("while(true, break())"))).evaluate_();
			REQUIRE(!result);
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("do(true, false)"))).evaluate_();
			REQUIRE(result);
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create("for(true,false,true,false)"))).evaluate_();
			REQUIRE(!result);
		}
		//TODO local mutation
/*		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create(
				"for(x:=1,x<=10,x++,$$strange::river::out[].write_[\"abc \"])"
			))).evaluate_();
			REQUIRE(result);
			std__cout << std::endl;
		}
*/		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create(
				"for_range(thing :# [\"x\",\"y\",\"z\"], $$strange::river::out[].write_[thing])"
			))).evaluate_();
			REQUIRE(result);
			std__cout << std::endl;
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create(
				"for_range(thing := [\"x\",\"y\",\"z\"], $$strange::river::out[].write_[thing])"
			))).evaluate_();
			REQUIRE(result);
			std__cout << std::endl;
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create(
				"(xyz :# [\"x\",\"y\",\"z\"],"
				"abc := xyz,"
				"abc@=1:\"Y\","
				"for_range(thing := abc, thing += \"+\")," // mutation of copy only
				"for_range(thing :# xyz, $$strange::river::out[].write_[thing]),"
				"for_range(thing :# abc, $$strange::river::out[].write_[thing]))"
			))).evaluate_();
			REQUIRE(result);
			std__cout << std::endl;
		}
		{
			auto result = parser.parse_(tokenizer_t<>::create_(river_t<>::create(
				"(xyz := [\"x\",\"y\",\"z\"],"
				"abc :# xyz,"
				"xyz@=1:\"Y\","
				"for_range(thing :# abc, thing += \"+\")," //TODO should not be able to mutate thing at all
				"for_range(thing :# xyz, $$strange::river::out[].write_[thing]),"
				"for_range(thing :# abc, $$strange::river::out[].write_[thing]))"
			))).evaluate_();
			REQUIRE(result);
			std__cout << std::endl;
		}
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
