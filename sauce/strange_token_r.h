#ifndef COM_ONEISH_STRANGE_TOKEN_R_H
#define COM_ONEISH_STRANGE_TOKEN_R_H

namespace strange
{
/*
template<>
class reflection<range_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::range");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update("cbegin", native_extraction_t<range_a<>>::val(&range_a<>::cbegin__));
			operations.update("cend", native_extraction_t<range_a<>>::val(&range_a<>::cend__));
			return operations;
		}();
		return OPERATIONS;
	}
};
*/
template<>
class reflection<token_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::token");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::token::val", native_function_t<>::val(&token_t<>::val__));
		shoal.update("strange::token::symbol_val", native_function_t<>::val(&token_t<>::symbol_val__));
		shoal.update("strange::token::lake_val", native_function_t<>::val(&token_t<>::lake_val__));
		shoal.update("strange::token::int_val", native_function_t<>::val(&token_t<>::int_val__));
		shoal.update("strange::token::float_val", native_function_t<>::val(&token_t<>::float_val__));
		shoal.update("strange::token::name_val", native_function_t<>::val(&token_t<>::name_val__));
		shoal.update("strange::token::punctuation_val", native_function_t<>::val(&token_t<>::punctuation_val__));
		shoal.update("strange::token::error_val", native_function_t<>::val(&token_t<>::error_val__));
	}
};

}

#endif
