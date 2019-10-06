TEST_CASE("strange parse and evaluate hello world", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create_file(taste_dir + "strange_taste_hello_world.str")));
		auto result = expression.evaluate_();
	}
	catch (misunderstanding_a<>& m)
	{
		std::cout << "misunderstanding: " << m.to_string() << std::endl;
		throw;
	}
	catch (std::exception & e)
	{
		std::cout << "exception: " << e.what() << std::endl;
		throw;
	}
}

TEST_CASE("strange parse and generate hello world", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create_file(taste_dir + "strange_taste_hello_world.str")));
		auto river = river_t<>::create();
		expression.generate(1, 1, river);
		std::cout << "generated: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		std::cout << "misunderstanding: " << m.to_string() << std::endl;
		throw;
	}
	catch (std::exception & e)
	{
		std::cout << "exception: " << e.what() << std::endl;
		throw;
	}
}

TEST_CASE("strange river create_file input hello world", "[river_t]")
{
	auto river = river_t<>::create_file(taste_dir + "strange_taste_hello_world.str");
	REQUIRE(river.good());
}

TEST_CASE("strange tokenize hello world", "[tokenizer_t]")
{
	auto tokenizer = tokenizer_t<>::create_(river_t<>::create_file(taste_dir + "strange_taste_hello_world.str"));
	for (auto const token : tokenizer)
	{
		std::cout << "token: " << cast<token_a<>>(token).report();
	}
}