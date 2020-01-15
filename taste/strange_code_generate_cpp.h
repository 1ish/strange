TEST_CASE("strange parse and generate cpp any abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(taste_dir + "strange_any_abstraction.str")));
		auto river = river_t<>::create();
		expression.generate_cpp(1, 1, river, true); // def = true
		std__cout << "generated cpp def: " << river.to_string() << std::endl;
		river = river_t<>::create();
		expression.generate_cpp(1, 1, river, false); // def = false
		std__cout << "generated cpp non-def: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}