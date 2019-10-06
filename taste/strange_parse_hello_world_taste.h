TEST_CASE("strange parse hello world", "[parse_t]")
{
	std::cout << "parse" << std::endl;
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::create_file(taste_dir + "strange_taste_hello_world.str")));
		std::cout << "parsed" << std::endl;
		auto river = river_t<>::create();
		expression.generate(1, 1, river);
		std::cout << "generated: " << river.to_string() << std::endl;
		auto result = expression.evaluate_();
		std::cout << "evaluated" << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		std::cout << "misunderstanding: " << m.to_string() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
}

TEST_CASE("strange river create_file input", "[river_t]")
{
	auto river = river_t<>::create_file(taste_dir + "strange_taste_hello_world.str");
	REQUIRE(river.good());
}

TEST_CASE("strange tokenizer create", "[tokenizer_t]")
{
	auto tokenizer = tokenizer_t<>::create_(river_t<>::create_file(taste_dir + "strange_taste_hello_world.str"));
	for (auto const token : tokenizer)
	{
		std::cout << "token: " << cast<token_a<>>(token).report();
	}
}