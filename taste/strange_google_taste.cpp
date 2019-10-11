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

TEST(TestCaseName, Parse)
{
	auto p = parser_t<>::create_();
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

	cat_a<> c = cat_t<>::create_();
	kind_a<> k = kind_t<>::create_();

	any_a<> f = native_function_t<>::create(fun, kind_t<>::create_(), "x", kind_t<>::create_(), "y", kind_t<>::create_(), "z", kind_t<>::create_());
	any_a<> g = native_function_t<>::create(&nothing_t<>::create__, kind_t<>::create_(), "x", kind_t<>::create_(), "y", kind_t<>::create_(), "z");
	any_a<> h = native_extraction_t<range_a<>>::create(&range_a<>::cbegin__);
	any_a<> i = native_mutation_t<flock_a<>>::create(&flock_a<>::begin__);
	any_a<> j = attribute_mutation_t<>::create_(sym("yes"), no());
	any_a<> l = attribute_extraction_t<>::create_(no());
	any_a<> m = description_t<>::create_();
	any_a<> o = abstraction_t<>::create_();
	any_a<> p = incarnation_t<>::create_(unordered_shoal_t<>::create_(), flock_t<>::create_(), k.aspects_(), flock_t<>::create_());

	ordered_shoal_a<> ordered_shoal = ordered_shoal_t<>::create_();
	unordered_shoal_a<> unordered_shoal = unordered_shoal_t<>::create_();
	flock_a<> flock = flock_t<>::create_();
	squad_a<> squad = squad_t<>::create_();
	ordered_herd_a<> ordered_herd = ordered_herd_t<>::create_();
	unordered_herd_a<> unordered_herd = unordered_herd_t<>::create_();

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

	number_a<> num = number_int_64_t<>::create(-123);

	try
	{
		auto bad = num.to_uint_64_();
	}
	catch (misunderstanding_a<> & m)
	{
		std::cout << "caught: " << m.to_string() << std::endl;
	}

	inventory_a<> lake = lake_float_64_t<>::create_();
	inventory_a<> brook = brook_float_32_t<>::create_();

	river_a<> river = river_t<>::create(" x y z ");
	/*
	for (auto const& c : river)
	{
		if (check<number_a<>>(c))
		{
			std::cout << "char: " << cast<number_a<>>(c).to_int_64() << std::endl;
		}
	}
	*/
	token_a<> token = token_t<>::create_(sym("filename"), number_int_64_t<>::create(1), number_int_64_t<>::create(2), sym("symbol"), sym("xyz"));
	range_a<> tokenizer = tokenizer_t<>::create_(river);

	for (auto const& tok : tokenizer)
	{
		if (check<token_a<>>(tok))
		{
			auto t = cast<token_a<>>(tok);
			std::cout << "token: " << t.symbol() << std::endl;
		}
	}

	expression_a<> expression = expression_t<>::create_(token, flock);
	flock.push_back(sym("hello"));
	expression = expression_local_at_t<>::create_(token, flock);
	auto const expression_kind = expression_kind_t<>::create_(token, flock_t<>::create_());

	brook_a<int8_t> concurrent_brook = brook_t<int8_t, true>::create_();
	flock_a<> concurrent_flock = flock_t<true>::create_();
	lake_a<int8_t> concurrent_lake = lake_t<int8_t, true>::create_();
	ordered_herd_a<> concurrent_ordered_herd = ordered_herd_t<true>::create_();
	ordered_shoal_a<> concurrent_ordered_shoal = ordered_shoal_t<true>::create_();
	squad_a<> concurrent_squad = squad_t<true>::create_();
	unordered_herd_a<> concurrent_unordered_herd = unordered_herd_t<true>::create_();
	unordered_shoal_a<> concurrent_unordered_shoal = unordered_shoal_t<true>::create_();

	range_a<> range_operator = range_operator_t<>::create_(concurrent_flock, concurrent_lake, concurrent_ordered_herd);

	brook_a<int64_t> brk = brook_t<int64_t>::create_(1, 2, 3);
	flock_a<> var = flock_t<>::create_(concurrent_brook, "hello", concurrent_flock);
	ordered_shoal_a<> ors = ordered_shoal_t<>::create_(std::make_pair(concurrent_ordered_herd, concurrent_ordered_shoal), std::make_pair(concurrent_squad, concurrent_unordered_herd));
	unordered_shoal_a<> uos = unordered_shoal_t<>::create_(std::make_pair(concurrent_ordered_herd, concurrent_ordered_shoal), std::make_pair(concurrent_squad, concurrent_unordered_herd));

	expression_a<> exp = cast<expression_a<>>(expression_o<expression_break_t<>>::create__(token.ranged_()));
	exp.shared_();

	auto conception = conception_t<>::create_();

	any_a<> creature = any_c<>::create_(conception);
	operation_a<> operation_creature = operation_c<>::create_(ordered_shoal);
	expression_a<> expression_creature = expression_c<>::create_(ordered_shoal);

	auto shared_scope = shared();
	std::cout << "shared().size() = " << shared_scope.size() << std::endl;

	flock_a<> const fl = flock_t<>::create_();
	flock_a<>(fl, true).push_back(no());

	range_of_a<> rof = range_of_t<>::create_();
	auto rofs = range_of_t<symbol_a<>>::create_();

	auto f1 = flock_t<>::create_(number_int_64_t<>::create(1), number_int_64_t<>::create(2), number_int_64_t<>::create(3));
	auto a1 = f1 | native_function_t<>::create(fun);
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
		symbol->invoke("nonexistent");
	}, Thing::Dismemberment);
}

TEST(StrangeThing, Mutilation) {
	EXPECT_THROW({
		const Ptr symbol = Thing::sym_("symbol");
		symbol->invoke("next");
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
		const Ptr to_lake = err->invoke("to_lake");
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
		const Ptr to_lake = err->invoke("to_lake");
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
		const Ptr to_lake = thing->invoke("to_lake");
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
		const Ptr to_lake = err->invoke("to_lake");
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
		const Ptr to_lake = thing->invoke("to_lake");
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