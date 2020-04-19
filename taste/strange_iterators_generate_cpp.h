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
		expression.generate_cpp(1, 1, river, true, true); // define
		std__cout << "generated cpp define: " << river.to_string() << std::endl;
		river = river_t<>::create();
		expression.generate_cpp(1, 1, river, false, true); // implement
		std__cout << "generated cpp implement: " << river.to_string() << std::endl;
		river = river_t<>::create();
		expression.generate_cpp(1, 1, river, false, false);
		std__cout << "generated cpp execute: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}
*/
TEST_CASE("strange parse and generate cpp file bidirectional_extractor abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_extractor_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_bidirectional_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file bidirectional_extractor_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_extractor_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_bidirectional_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file bidirectional_mutator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_mutator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_bidirectional_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file bidirectional_mutator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_mutator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_bidirectional_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_extractor abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_extractor_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_forward_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_extractor_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_extractor_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_forward_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_mutator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_mutator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_forward_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_mutator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_mutator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_forward_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_extractor abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_extractor_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_random_access_extractor_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_extractor_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_extractor_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_random_access_extractor_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_mutator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_mutator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_random_access_mutator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_mutator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_mutator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_random_access_mutator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}
