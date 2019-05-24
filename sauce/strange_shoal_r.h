#ifndef COM_ONEISH_STRANGE_SHOAL_R_H
#define COM_ONEISH_STRANGE_SHOAL_R_H

namespace strange
{

template<>
class reflection<shoal_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::shoal"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<collection_a<>>::operations();
			operations.update("begin", native_mutation_t<shoal_a<>>::val(&shoal_a<>::begin__));
			operations.update("end", native_mutation_t<shoal_a<>>::val(&shoal_a<>::end__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
