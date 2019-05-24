#ifndef COM_ONEISH_STRANGE_INVENTORY_O_H
#define COM_ONEISH_STRANGE_INVENTORY_O_H

namespace strange
{

template<>
class abstraction<inventory_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::inventory"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = abstraction<collection_a<>>::operations();
			operations.update("begin", native_mutation_t<inventory_a<>>::val(&inventory_a<>::begin__));
			operations.update("end", native_mutation_t<inventory_a<>>::val(&inventory_a<>::end__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
