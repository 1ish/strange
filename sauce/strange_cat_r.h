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
		static cat_a<> CAT = cat_t<>::create(1, "strange::cat");
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
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<symbol_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<symbol_a<>>::operations();
			operations.update_string("order_", native_extraction_t<cat_a<>>::create(&cat_a<>::order__));
			operations.update_string("name_", native_extraction_t<cat_a<>>::create(&cat_a<>::name__));
			operations.update_string("dimensions_", native_extraction_t<cat_a<>>::create(&cat_a<>::dimensions__));
			operations.update_string("parameters_", native_extraction_t<cat_a<>>::create(&cat_a<>::parameters__));
			operations.update_string("result_", native_extraction_t<cat_a<>>::create(&cat_a<>::result__));
			operations.update_string("fixed_", native_extraction_t<cat_a<>>::create(&cat_a<>::fixed__));
			operations.update_string("optional_", native_extraction_t<cat_a<>>::create(&cat_a<>::optional__));
			operations.update_string("code_", native_extraction_t<cat_a<>>::create(&cat_a<>::code__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
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
		shoal.update_string("strange::cat::create", native_function_t<>::create(&cat_t<>::create__));
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
