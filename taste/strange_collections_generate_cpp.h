/*
TEST_CASE("strange parse and generate cpp brook", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_brook_a.str")));
		auto river = river_t<>::create();
		expression.generate_cpp(1, 1, river, true, false); // declare
		std__cout << "generated cpp declare: " << river.to_string() << std::endl;
		river = river_t<>::create();
		expression.generate_cpp(1, 1, river, false, true); // define
		std__cout << "generated cpp define: " << river.to_string() << std::endl;
		river = river_t<>::create();
		expression.generate_cpp(1, 1, river, false, false);
		std__cout << "generated cpp execute: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
*/
TEST_CASE("strange parse and generate cpp file brook abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_brook_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_brook_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_brook_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file collection abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_collection_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_collection_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_collection_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file flock abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_flock_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_flock_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_flock_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file herd abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_herd_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
