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
		static cat_a<> CAT = cat_t<>::create(1, "strange::token");
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

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<any_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("filename", native_extraction_t<token_a<>>::create(&token_a<>::filename__));
			operations.update_string("line", native_extraction_t<token_a<>>::create(&token_a<>::line__));
			operations.update_string("position", native_extraction_t<token_a<>>::create(&token_a<>::position__));
			operations.update_string("tag", native_extraction_t<token_a<>>::create(&token_a<>::tag__));
			operations.update_string("symbol", native_extraction_t<token_a<>>::create(&token_a<>::symbol__));
			operations.update_string("literal", native_extraction_t<token_a<>>::create(&token_a<>::literal__));
			operations.update_string("precedence", native_extraction_t<token_a<>>::create(&token_a<>::precedence__));
			operations.update_string("report", native_extraction_t<token_a<>>::create(&token_a<>::report__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___token_a_share___
{
	static inline bool ___share___()
	{
		return token_a<>::___share___;
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
		shoal.update_string("strange::token::create", native_function_t<>::create(&token_t<>::create__));
		shoal.update_string("strange::token::create_symbol", native_function_t<>::create(&token_t<>::create_symbol__));
		shoal.update_string("strange::token::create_lake", native_function_t<>::create(&token_t<>::create_lake__));
		shoal.update_string("strange::token::create_int", native_function_t<>::create(&token_t<>::create_int__));
		shoal.update_string("strange::token::create_float", native_function_t<>::create(&token_t<>::create_float__));
		shoal.update_string("strange::token::create_name", native_function_t<>::create(&token_t<>::create_name__));
		shoal.update_string("strange::token::create_punctuation", native_function_t<>::create(&token_t<>::create_punctuation__));
		shoal.update_string("strange::token::create_error", native_function_t<>::create(&token_t<>::create_error__));
	}
};

class ___token_t_share___
{
	static inline bool ___share___()
	{
		return token_t<>::___share___;
	}
};

}

#endif
