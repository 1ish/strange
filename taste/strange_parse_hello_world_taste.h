TEST_CASE("strange river create_file input hello world", "[river_t]")
{
	try
	{
		auto river = river_t<>::create_file(taste_dir + "strange_taste_hello_world.str");
		REQUIRE(river.good());
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange tokenize hello world", "[tokenizer_t]")
{
	try
	{
		auto tokenizer = tokenizer_t<>::create_(river_t<>::create_file(taste_dir + "strange_taste_hello_world.str"));
		for (auto const token : tokenizer)
		{
			std::cout << "token: " << cast<token_a<>>(token).report();
		}
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
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
		throw std::runtime_error(m.to_string());
	}
}

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
		throw std::runtime_error(m.to_string());
	}
}
