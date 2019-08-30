#ifndef COM_ONEISH_STRANGE_PARSER_R_H
#define COM_ONEISH_STRANGE_PARSER_R_H

namespace strange
{

template<>
class reflection<parser_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::parser");
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
//TODO			operations.update_string("parse", native_extraction_t<parser_a<>>::val(&parser_a<>::parse__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___parser_a_share___
{
	static inline bool ___share___()
	{
		return parser_a<>::___share___;
	}
};

template<>
class reflection<parser_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::parser");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
//TODO		shoal.update_string("strange::parser::val", native_function_t<>::val(&parser_t<>::val__));
	}
};

class ___parser_t_share___
{
	static inline bool ___share___()
	{
		return parser_t<>::___share___;
	}
};

}

#endif