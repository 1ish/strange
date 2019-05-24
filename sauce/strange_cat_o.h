#ifndef COM_ONEISH_STRANGE_CAT_O_H
#define COM_ONEISH_STRANGE_CAT_O_H

namespace strange
{

template<>
class abstraction<cat_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::cat"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = abstraction<symbol_a<>>::operations();
			operations.update("name", native_extraction_t<cat_a<>>::val(&cat_a<>::name__));
			operations.update("arguments", native_extraction_t<cat_a<>>::val(&cat_a<>::arguments__));
			operations.update("parameters", native_extraction_t<cat_a<>>::val(&cat_a<>::parameters__));
			operations.update("result", native_extraction_t<cat_a<>>::val(&cat_a<>::result__));
			operations.update("includes", native_extraction_t<cat_a<>>::val(&cat_a<>::includes__));
			operations.update("conforms", native_extraction_t<cat_a<>>::val(&cat_a<>::conforms__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
