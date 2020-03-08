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
		expression.generate_cpp(1, 1, river, false, false);
		std__cout << "generated cpp execute: " << river.to_string() << std::endl;
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
*/
TEST_CASE("strange parse and generate cpp file bidirectional_const_iterator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_const_iterator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_const_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_const_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file bidirectional_const_iterator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_const_iterator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_const_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_const_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file bidirectional_iterator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_iterator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file bidirectional_iterator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_bidirectional_iterator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_bidirectional_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_bidirectional_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_const_iterator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_const_iterator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_const_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_const_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_const_iterator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_const_iterator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_const_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_const_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_iterator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_iterator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file forward_iterator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_forward_iterator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_forward_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_forward_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_const_iterator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_const_iterator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_const_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_const_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_const_iterator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_const_iterator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_const_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_const_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_iterator abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_iterator_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_iterator_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file random_access_iterator_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_random_access_iterator_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_random_access_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_random_access_iterator_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
