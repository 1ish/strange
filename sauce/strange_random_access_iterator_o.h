#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_O_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_O_H

namespace strange
{

template<>
class reflection<random_access_iterator_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::random_access_iterator"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<bidirectional_iterator_a<>>::operations();
			operations.update("self_add", native_mutation_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::self_add__));
			operations.update("add", native_extraction_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::add__));
			operations.update("self_subtract", native_mutation_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::self_subtract__));
			operations.update("subtract", native_extraction_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::subtract__));
			operations.update("less_than", native_extraction_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::less_than__));
			operations.update("greater_than", native_extraction_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::greater_than__));
			operations.update("less_or_equal", native_extraction_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::less_or_equal__));
			operations.update("greater_or_equal", native_extraction_t<random_access_iterator_a<>>::val(&random_access_iterator_a<>::greater_or_equal__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
