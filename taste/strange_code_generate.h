TEST_CASE("strange parse and generate any abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(taste_dir + "strange_any_abstraction.str")));
		auto river = river_t<>::create();
		expression.generate(1, 1, river);
		std__cout << "generated: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}