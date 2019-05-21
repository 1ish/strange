#ifndef COM_ONEISH_STRANGE_SYMBOL_O_H
#define COM_ONEISH_STRANGE_SYMBOL_O_H

namespace strange
{

template<>
class abstraction<symbol_a<>>
{
public:
	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = abstraction<any_a<>>::operations();
			operations.update("add", native_extraction_t<symbol_a<>>::val(&symbol_a<>::add__, sym("symbol")));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
