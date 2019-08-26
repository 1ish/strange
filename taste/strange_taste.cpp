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
	kind_a<> k = kind_t<>::val_();

	any_a<> f = native_function_t<>::val(fun, kind_t<>::val_(), "x", kind_t<>::val_(), "y", kind_t<>::val_(), "z", kind_t<>::val_());
	any_a<> g = native_function_t<>::val(&nothing_t<>::val__, kind_t<>::val_(), "x", kind_t<>::val_(), "y", kind_t<>::val_(), "z");
	any_a<> h = native_extraction_t<range_a<>>::val(&range_a<>::cbegin__);
	any_a<> i = native_mutation_t<flock_a<>>::val(&flock_a<>::begin__);
	any_a<> j = attribute_mutation_t<>::val_(no());
	any_a<> l = attribute_extraction_t<>::val_(no());
	any_a<> m = description_t<>::val_();
	any_a<> o = abstraction_t<>::val_();
	any_a<> p = incarnation_t<>::val_(unordered_shoal_t<>::val_(), flock_t<>::val_(), k.aspects_());
	any_a<> q = attribution_t<>::val_(no());

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

	river_a<> river = river_t<>::val(" x y z ");
	/*
	for (auto const& c : river)
	{
		if (check<number_a<>>(c))
		{
			std::cout << "char: " << cast<number_a<>>(c).to_int_64() << std::endl;
		}
	}
	*/
	token_a<> token = token_t<>::val_(sym("filename"), number_int_64_t<>::val(1), number_int_64_t<>::val(2), sym("symbol"), sym("xyz"));
	range_a<> tokenizer = tokenizer_t<>::val_(river);

	for (auto const& tok : tokenizer)
	{
		if (check<token_a<>>(tok))
		{
			auto t = cast<token_a<>>(tok);
			std::cout << "token: " << t.symbol() << std::endl;
		}
	}

	expression_a<> expression = expression_t<>::val_(token, flock);
	flock.push_back(sym("hello"));
	expression = expression_local_at_t<>::val_(token, flock);
	auto const expression_kind = expression_kind_t<>::val_(token, flock_t<>::val_());

	brook_a<int8_t> concurrent_brook = brook_t<int8_t, true>::val_();
	flock_a<> concurrent_flock = flock_t<true>::val_();
	lake_a<int8_t> concurrent_lake = lake_t<int8_t, true>::val_();
	ordered_herd_a<> concurrent_ordered_herd = ordered_herd_t<true>::val_();
	ordered_shoal_a<> concurrent_ordered_shoal = ordered_shoal_t<true>::val_();
	squad_a<> concurrent_squad = squad_t<true>::val_();
	unordered_herd_a<> concurrent_unordered_herd = unordered_herd_t<true>::val_();
	unordered_shoal_a<> concurrent_unordered_shoal = unordered_shoal_t<true>::val_();

	range_a<> range_operator = range_operator_t<>::val_(concurrent_flock, concurrent_lake, concurrent_ordered_herd);

	brook_a<int64_t> brk = brook_t<int64_t>::val_(1, 2, 3);
	flock_a<> var = flock_t<>::val_(concurrent_brook, "hello", concurrent_flock);
	ordered_shoal_a<> ors = ordered_shoal_t<>::val_(std::make_pair(concurrent_ordered_herd, concurrent_ordered_shoal), std::make_pair(concurrent_squad, concurrent_unordered_herd));
	unordered_shoal_a<> uos = unordered_shoal_t<>::val_(std::make_pair(concurrent_ordered_herd, concurrent_ordered_shoal), std::make_pair(concurrent_squad, concurrent_unordered_herd));

	expression_a<> exp = cast<expression_a<>>(expression_o<expression_break_t<>>::val__(token.ranged_()));
	exp.shared_();

	auto creation = creation_t<>::val_();

	any_a<> creature = any_c<>::val_(creation);
	operation_a<> operation_creature = operation_c<>::val_(ordered_shoal);
	expression_a<> expression_creature = expression_c<>::val_(ordered_shoal);

	auto shared_scope = shared();
	std::cout << "shared().size() = " << shared_scope.size() << std::endl;

	flock_a<> const fl = flock_t<>::val_();
	flock_a<>(fl, true).push_back(no());

	range_of_a<> rof = range_of_t<>::val_();
	auto rofs = range_of_t<symbol_a<>>::val_();
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