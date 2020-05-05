TEST_CASE("strange parse and generate cpp file brook abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_brook_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_brook_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_brook_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_brook_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
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
			"core/collections/abstractions/strange_collection_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_collection_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_collection_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_collection_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file container abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_container_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_container_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_container_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_container_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file container_data abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_container_data_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_container_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_container_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_container_data_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
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
			"core/collections/abstractions/strange_flock_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_flock_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_flock_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_flock_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
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
			"core/collections/abstractions/strange_herd_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file inventory abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_inventory_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_inventory_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_inventory_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_inventory_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file lake abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_lake_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_lake_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_lake_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_lake_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file list abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_list_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_list_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_list_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_list_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file ordered_herd abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_ordered_herd_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_ordered_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_ordered_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_ordered_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file ordered_shoal abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_ordered_shoal_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_ordered_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_ordered_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_ordered_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file shoal abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_shoal_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file squad abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_squad_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_squad_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_squad_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_squad_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file unordered_herd abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_unordered_herd_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_unordered_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_unordered_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_unordered_herd_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}

TEST_CASE("strange parse and generate cpp file unordered_shoal abstraction", "[parse_t]")
{
	try
	{
		auto parser = parser_t<>::create_();
		auto expression = parser.parse_(tokenizer_t<>::create_(river_t<>::file(abstractions_dir +
			"core/collections/abstractions/strange_unordered_shoal_a.str")));
		auto river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/declarations/declare_strange_unordered_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, false); // declare
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/definitions/define_strange_unordered_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, true, true); // define
		river = river_t<>::file(generate_cpp_dir +
			"core/collections/abstractions/generated/implementations/implement_strange_unordered_shoal_a.hpp", false, true, true); // in, out, trunc
		expression.generate_cpp(1, 1, river, false, true); // implement
	}
	catch (misunderstanding_a<>& m)
	{
		throw std::runtime_error(m.to_string());
	}
}
