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
			auto cats = reflection<operation_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<operation_a<>>::operations();
			operations.update_string("evaluate", native_extraction_t<expression_a<>>::val(&expression_a<>::evaluate__));
			operations.update_string("token", native_extraction_t<expression_a<>>::val(&expression_a<>::token__));
			operations.update_string("generate", native_extraction_t<expression_a<>>::val(&expression_a<>::generate__));
			operations.update_string("generate_cpp", native_extraction_t<expression_a<>>::val(&expression_a<>::generate_cpp__));
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
		shoal.update_string("strange::expression::val", native_function_t<>::val(&expression_t<>::val__));
	}
};

}

#endif
