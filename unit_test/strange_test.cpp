#include "gtest/gtest.h"

#include "../src/strange.h"

namespace
{
	const std::string test_dir = "../../strange/unit_test/";
}

using namespace strange;
using Ptr = Thing::Ptr;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(StrangeThing, Dismemberment) {
	EXPECT_THROW({
		const Ptr symbol = Thing::sym_("symbol");
		symbol->invoke_("nonexistent");
	}, Thing::Dismemberment);
}

TEST(StrangeThing, Mutation) {
	EXPECT_THROW({
		const Ptr symbol = Thing::sym_("symbol");
		symbol->invoke_("next");
	}, Thing::Mutation);
}

TEST(StrangeRiver, Get) {
	const Ptr river = River::mut_(test_dir + "strange_test_source.str", true);
	River* const r = Thing::dynamic_<River>(river);
	ASSERT_NE(r, (River*)(0));
	EXPECT_EQ(r->good_(), true);
	while (r->good_())
	{
		const int c = r->get_();
		if (!r->good_())
		{
			break;
		}
		std::cout << "got:" << c << std::endl;
	}
}

TEST(StrangeTokenizer, Next) {
	const Ptr river = River::mut_(test_dir + "strange_test_source.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	Tokenizer* const t = Thing::dynamic_<Tokenizer>(tokenizer);
	ASSERT_NE(t, (Tokenizer*)(0));
	EXPECT_EQ(t->good_(), true);
	for (Ptr n = tokenizer->next_(); !n->is_("."); n = tokenizer->next_())
	{
		Token* const token = Thing::dynamic_<Token>(n);
		ASSERT_NE(token, (Token*)(0));
		Symbol* const symbol = Thing::dynamic_<Symbol>(token->symbol());
		ASSERT_NE(symbol, (Symbol*)(0));
		std::cout << "got: " << symbol->get_() << std::endl;
	}
}

TEST(StrangeParser, Execute) {
	const Ptr river = River::mut_(test_dir + "strange_test_source.str", true);
	const Ptr tokenizer = Tokenizer::mut_(river);
	const Ptr parser = Parser::mut_(tokenizer);
	const Ptr expression = Thing::dynamic_<Parser>(parser)->parse_();
	Expression* const exp = Thing::dynamic_<Expression>(expression);
	ASSERT_NE(exp, (Expression*)(0));
	const Ptr result = Expression::immediate_(expression);
	EXPECT_NE(result.get(), (Thing*)(0));
}
