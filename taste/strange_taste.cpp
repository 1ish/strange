#include "gtest/gtest.h"

#include "../sauce/strange.h"

using namespace strange;

TEST(TestCaseName, TestName)
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

any_a<> fun(range_a<> const& x)
{
	return no();
}

TEST(TestCaseName, ForLoop)
{
	any_a<> n{ no() };

	for (auto const& v : n.ranged_())
	{
	}

	any_a<> e{ yes() };

	for (auto const& v : e.ranged_())
	{
	}

	e = n;

	symbol_a<> s = sym("strange");

	EXPECT_EQ(s.to_string(), "strange");
	EXPECT_FALSE(e.is("strange"));
	EXPECT_TRUE(s.is("strange"));

	cat_a<> c = cat_t<>::val_();

	any_a<> f = native_function_t<>::val(fun, "x", "y", "z");
	any_a<> g = native_function_t<>::val(&nothing_t<>::val__, "x", "y", "z");
	any_a<> h = native_extraction_t<range_a<>>::val(&range_a<>::cbegin__);
	any_a<> i = native_mutation_t<flock_a<>>::val(&flock_a<>::begin__);

	ordered_shoal_a<> ordered_shoal = ordered_shoal_t<>::val_();
	unordered_shoal_a<> unordered_shoal = unordered_shoal_t<>::val_();
	flock_a<> flock = flock_t<>::val_();
	squad_a<> squad = squad_t<>::val_();
	ordered_herd_a<> ordered_herd = ordered_herd_t<>::val_();
	unordered_herd_a<> unordered_herd = unordered_herd_t<>::val_();

	try
	{
		unordered_shoal = cast<unordered_shoal_a<>>(c);
	}
	catch (misunderstanding_a<>& m)
	{
		std::cout << "caught: " << m.to_string() << std::endl;
	}

	auto it = flock.cbegin_();
	if (check<random_access_const_iterator_data_a<std::vector<any_a<>>::const_iterator>>(it))
	{
		std::cout << "checked ok" << std::endl;
		random_access_const_iterator_data_a<std::vector<any_a<>>::const_iterator> data =
			cast<random_access_const_iterator_data_a<std::vector<any_a<>>::const_iterator>>(it);
		std::cout << "data: " << (data == flock.cend_()) << std::endl;
	}

	number_a<> num = number_int_64_t<>::val(-123);

	try
	{
		auto bad = num.to_uint_64_();
	}
	catch (misunderstanding_a<> & m)
	{
		std::cout << "caught: " << m.to_string() << std::endl;
	}

	inventory_a<> lake = lake_float_64_t<>::val_();
	inventory_a<> brook = brook_float_32_t<>::val_();

	river_a<> river = river_t<>::val();

	any_a<> token = token_t<>::val_(sym("filename"), number_int_64_t<>::val(1), number_int_64_t<>::val(2), sym("symbol"), sym("xyz"));
}
/*
//#define STRANGE_TEST_VERBOSE 1
//using Ptr = Thing::Ptr;
namespace
{
	const std::string test_dir = "../../strange/taste/";
}

TEST(StrangeThing, Dismemberment) {
	EXPECT_THROW({
		const Ptr symbol = Thing::sym_("symbol");
		symbol->invoke_("nonexistent");
	}, Thing::Dismemberment);
}

TEST(StrangeThing, Mutilation) {
	EXPECT_THROW({
		const Ptr symbol = Thing::sym_("symbol");
		symbol->invoke_("next");
	}, Thing::Mutilation);
}

TEST(StrangeRiver, Get) {
	const Ptr river = River::mut_(test_dir + "strange_test_source.str", true);
	const auto r = Thing::dynamic_<River>(river);
	ASSERT_NE(r, std::shared_ptr<River>(0));
	EXPECT_EQ(r->good_(), true);
	while (r->good_())
	{
		const int c = r->get_();
		if (!r->good_())
		{
			break;
		}
#ifdef STRANGE_TEST_VERBOSE
		std::cout << "got:" << c << std::endl;
#endif
	}
}

TEST(StrangeRiver, Out) {
	const Ptr river = River::out_();
	const auto r = Thing::dynamic_<River>(river);
	ASSERT_NE(r, std::shared_ptr<River>(0));
	EXPECT_EQ(r->good_(), true);
	r->write_("river out\n");
}

TEST(StrangeTokenizer, Next) {
	const Ptr river = River::mut_(test_dir + "strange_test_source.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	const auto t = Thing::dynamic_<Tokenizer>(tokenizer);
	ASSERT_NE(t, std::shared_ptr<Tokenizer>(0));
	EXPECT_EQ(t->good_(), true);
	for (Ptr n = tokenizer->next_(); !n->is_stop_(); n = tokenizer->next_())
	{
		const auto token = Thing::dynamic_<Token>(n);
		ASSERT_NE(token, std::shared_ptr<Token>(0));
		const auto symbol = Thing::dynamic_<symbol_t>(token->symbol());
		ASSERT_NE(symbol, std::shared_ptr<symbol_t>(0));
#ifdef STRANGE_TEST_VERBOSE
		std::cout << "got: " << symbol->get_() << std::endl;
#endif
	}
}

TEST(StrangeParser, HelloWorld) {
	const Ptr river = River::mut_(test_dir + "strange_test_hello_world.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	const Ptr parser = Parser::mut_(tokenizer);
	const Ptr expression = Thing::dynamic_<Parser>(parser)->parse_();
	const auto exp = Thing::dynamic_<Expression>(expression);
	ASSERT_NE(exp, std::shared_ptr<Expression>(0));
	std::string error;
	try
	{
		const Ptr result = Expression::immediate_(expression);
	}
	catch (const std::exception& err)
	{
		error = err.what();
		std::cout << error << std::endl;
	}
	EXPECT_EQ(error, "");
}

TEST(StrangeParser, TokenError) {
	const Ptr river = River::mut_(test_dir + "strange_test_token_error.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	const Ptr parser = Parser::mut_(tokenizer);
	std::string error;
	try
	{
		const Ptr expression = Thing::dynamic_<Parser>(parser)->parse_();
	}
	catch (const Ptr& err)
	{
		const Ptr to_lake = err->invoke_("to_lake");
		const auto lake = Thing::dynamic_<Lake>(to_lake);
		ASSERT_NE(lake, std::shared_ptr<Lake>(0));
		error = lake->get_();
		std::cout << error << std::endl;
	}
	EXPECT_NE(error, "");
}

TEST(StrangeParser, ParseError) {
	const Ptr river = River::mut_(test_dir + "strange_test_parse_error.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	const Ptr parser = Parser::mut_(tokenizer);
	std::string error;
	try
	{
		const Ptr expression = Thing::dynamic_<Parser>(parser)->parse_();
	}
	catch (const Ptr& err)
	{
		const Ptr to_lake = err->invoke_("to_lake");
		const auto lake = Thing::dynamic_<Lake>(to_lake);
		ASSERT_NE(lake, std::shared_ptr<Lake>(0));
		error = lake->get_();
		std::cout << error << std::endl;
	}
	EXPECT_NE(error, "");
}

TEST(StrangeParser, EvaluateError) {
	const Ptr river = River::mut_(test_dir + "strange_test_evaluate_error.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	const Ptr parser = Parser::mut_(tokenizer);
	const Ptr expression = Thing::dynamic_<Parser>(parser)->parse_();
	const auto exp = Thing::dynamic_<Expression>(expression);
	ASSERT_NE(exp, std::shared_ptr<Expression>(0));
	std::string error;
	try
	{
		const Ptr result = Expression::immediate_(expression);
	}
	catch (const Ptr& thing)
	{
		const Ptr to_lake = thing->invoke_("to_lake");
		const auto lake = Thing::dynamic_<Lake>(to_lake);
		if (lake)
		{
			error = lake->get_();
			std::cout << error << std::endl;
		}
	}
	catch (const std::exception& err)
	{
		error = err.what();
		std::cout << error << std::endl;
	}
	EXPECT_NE(error, "");
}

TEST(StrangeParser, Evaluate) {
	const Ptr river = River::mut_(test_dir + "strange_test_source.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	const Ptr parser = Parser::mut_(tokenizer);
	std::string error;
	Ptr expression;
	try
	{
		expression = Thing::dynamic_<Parser>(parser)->parse_();
	}
	catch (const Ptr& err)
	{
		const Ptr to_lake = err->invoke_("to_lake");
		const auto lake = Thing::dynamic_<Lake>(to_lake);
		ASSERT_NE(lake, std::shared_ptr<Lake>(0));
		error = lake->get_();
		std::cout << error << std::endl;
	}
	ASSERT_EQ(error, "");

	const auto exp = Thing::dynamic_<Expression>(expression);
	ASSERT_NE(exp, std::shared_ptr<Expression>(0));
	try
	{
		const Ptr result = Expression::immediate_(expression);
	}
	catch (const std::exception& err)
	{
		error = err.what();
		std::cout << error << std::endl;
	}
	catch (const Ptr& thing)
	{
		const Ptr to_lake = thing->invoke_("to_lake");
		const auto lake = Thing::dynamic_<Lake>(to_lake);
		if (lake)
		{
			error = lake->get_();
			std::cout << error << std::endl;
		}
	}
	EXPECT_EQ(error, "");
}
*/