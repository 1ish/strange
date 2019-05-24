#ifndef COM_ONEISH_STRANGE_COLLECTION_O_H
#define COM_ONEISH_STRANGE_COLLECTION_O_H

namespace strange
{

template<>
class abstraction<collection_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::collection"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = abstraction<range_a<>>::operations();
			operations.update("has", native_extraction_t<collection_a<>>::val(&collection_a<>::has__));
			operations.update("at", native_extraction_t<collection_a<>>::val(&collection_a<>::at__));
			operations.update("update", native_mutation_t<collection_a<>>::val(&collection_a<>::update__));
			operations.update("insert", native_mutation_t<collection_a<>>::val(&collection_a<>::insert__));
			operations.update("erase", native_mutation_t<collection_a<>>::val(&collection_a<>::erase__));
			operations.update("clear", native_mutation_t<collection_a<>>::val(&collection_a<>::clear__));
			operations.update("size", native_extraction_t<collection_a<>>::val(&collection_a<>::size__));
			operations.update("empty", native_extraction_t<collection_a<>>::val(&collection_a<>::empty__));
			operations.update("push_front", native_mutation_t<collection_a<>>::val(&collection_a<>::push_front__));
			operations.update("pop_front", native_mutation_t<collection_a<>>::val(&collection_a<>::pop_front__));
			operations.update("push_back", native_mutation_t<collection_a<>>::val(&collection_a<>::push_back__));
			operations.update("pop_back", native_mutation_t<collection_a<>>::val(&collection_a<>::pop_back__));
			operations.update("self_add", native_mutation_t<collection_a<>>::val(&collection_a<>::self_add__));
			operations.update("add", native_extraction_t<collection_a<>>::val(&collection_a<>::add__));
			operations.update("self_subtract", native_mutation_t<collection_a<>>::val(&collection_a<>::self_subtract__));
			operations.update("subtract", native_extraction_t<collection_a<>>::val(&collection_a<>::subtract__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
