#ifndef COM_ONEISH_STRANGE_EXPRESSION_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_R_H

namespace strange
{

template<>
class reflection<expression_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::expression");
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
			operations.update("token", native_extraction_t<expression_a<>>::val(&expression_a<>::token__));
			operations.update("pure", native_extraction_t<expression_a<>>::val(&expression_a<>::pure__));
			operations.update("literal", native_extraction_t<expression_a<>>::val(&expression_a<>::literal__));
			operations.update("generate", native_extraction_t<expression_a<>>::val(&expression_a<>::generate__));
			operations.update("generate_cpp", native_extraction_t<expression_a<>>::val(&expression_a<>::generate_cpp__));
			return operations;
		}();
		return OPERATIONS;
	}
};

template<>
class reflection<expression_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::expression::val", native_function_t<>::val(&expression_t<>::val__));
	}
};

}

#endif
