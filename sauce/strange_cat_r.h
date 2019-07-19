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
		static cat_a<> CAT = cat_t<>::val("strange::cat");
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

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<symbol_a<>>::operations();
			operations.update_string("name", native_extraction_t<cat_a<>>::val(&cat_a<>::name__));
			operations.update_string("args", native_extraction_t<cat_a<>>::val(&cat_a<>::args__));
			operations.update_string("params", native_extraction_t<cat_a<>>::val(&cat_a<>::params__));
			operations.update_string("result", native_extraction_t<cat_a<>>::val(&cat_a<>::result__));
			operations.update_string("ref", native_extraction_t<cat_a<>>::val(&cat_a<>::ref__));
			operations.update_string("subs", native_extraction_t<cat_a<>>::val(&cat_a<>::subs__));
//TODO			operations.update_string("includes", native_extraction_t<cat_a<>>::val(&cat_a<>::includes__));
			return operations;
		}();
		return OPERATIONS;
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
//TODO		shoal.update_string("strange::cat::conforms", native_function_t<>::val(&cat_t<>::conforms__));
	}
};

}

#endif
