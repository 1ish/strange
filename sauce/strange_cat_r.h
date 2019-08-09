#ifndef COM_ONEISH_STRANGE_CAT_R_H
#define COM_ONEISH_STRANGE_CAT_R_H

namespace strange
{

template<>
class reflection<cat_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val(1, "strange::cat");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<symbol_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = cat_to_kind(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = cats_to_kinds(cats());
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<symbol_a<>>::operations();
			operations.update_string("order", native_extraction_t<cat_a<>>::val(&cat_a<>::order__));
			operations.update_string("name", native_extraction_t<cat_a<>>::val(&cat_a<>::name__));
			operations.update_string("dimensions", native_extraction_t<cat_a<>>::val(&cat_a<>::dimensions__));
			operations.update_string("parameterss", native_extraction_t<cat_a<>>::val(&cat_a<>::parameters__));
			operations.update_string("result", native_extraction_t<cat_a<>>::val(&cat_a<>::result__));
			operations.update_string("reference", native_extraction_t<cat_a<>>::val(&cat_a<>::reference__));
			operations.update_string("optional", native_extraction_t<cat_a<>>::val(&cat_a<>::optional__));
			operations.update_string("code", native_extraction_t<cat_a<>>::val(&cat_a<>::code__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___cat_a_share___
{
	static inline bool ___share___()
	{
		return cat_a<>::___share___;
	}
};

template<>
class reflection<cat_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::cat");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::cat::val", native_function_t<>::val(&cat_t<>::val__));
	}
};

class ___cat_t_share___
{
	static inline bool ___share___()
	{
		return cat_t<>::___share___;
	}
};

}

#endif
