
TEST_CASE("strange parse and generate cpp abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_any_a.str")));
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

TEST_CASE("strange parse and generate cpp file any abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_any_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_any_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_any_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_any_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file cat abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_cat_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_cat_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_cat_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_cat_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file expression abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_expression_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_expression_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_expression_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_expression_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file kind abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_kind_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_kind_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_kind_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_kind_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file misunderstanding abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_misunderstanding_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_misunderstanding_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_misunderstanding_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_misunderstanding_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file number abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_number_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_number_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_number_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_number_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file number_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_number_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_number_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_number_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_number_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file operation abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_operation_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_operation_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_operation_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_operation_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file parser abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_parser_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_parser_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_parser_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_parser_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file range abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_range_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_range_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_range_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_range_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file river abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_river_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_river_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_river_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_river_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file symbol abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_symbol_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_symbol_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_symbol_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_symbol_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file token abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"strange_token_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"declare_strange_token_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"define_strange_token_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"implement_strange_token_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std_runtime_error(m.to_string());
	}
}
