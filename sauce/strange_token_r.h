#ifndef COM_ONEISH_STRANGE_TOKEN_R_H
#define COM_ONEISH_STRANGE_TOKEN_R_H

namespace strange
{

template<>
class reflection<token_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::token");
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
			operations.update("filename", native_extraction_t<token_a<>>::val(&token_a<>::filename__));
			operations.update("line", native_extraction_t<token_a<>>::val(&token_a<>::line__));
			operations.update("position", native_extraction_t<token_a<>>::val(&token_a<>::position__));
			operations.update("tag", native_extraction_t<token_a<>>::val(&token_a<>::tag__));
			operations.update("symbol", native_extraction_t<token_a<>>::val(&token_a<>::symbol__));
			operations.update("literal", native_extraction_t<token_a<>>::val(&token_a<>::literal__));
			operations.update("precedence", native_extraction_t<token_a<>>::val(&token_a<>::precedence__));
			operations.update("report", native_extraction_t<token_a<>>::val(&token_a<>::report__));
			return operations;
		}();
		return OPERATIONS;
	}
};

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
