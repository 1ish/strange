#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_R_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_R_H

namespace strange
{

template<>
class reflection<random_access_const_iterator_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::random_access_const_iterator");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<bidirectional_const_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<bidirectional_const_iterator_a<>>::operations();
			operations.update_string("self_add", native_mutation_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::self_add__));
			operations.update_string("add", native_extraction_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::add__));
			operations.update_string("self_subtract", native_mutation_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::self_subtract__));
			operations.update_string("subtract", native_extraction_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::subtract__));
			operations.update_string("less_than", native_extraction_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::less_than__));
			operations.update_string("greater_than", native_extraction_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::greater_than__));
			operations.update_string("less_or_equal", native_extraction_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::less_or_equal__));
			operations.update_string("greater_or_equal", native_extraction_t<random_access_const_iterator_a<>>::val(&random_access_const_iterator_a<>::greater_or_equal__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___random_access_const_iterator_a_share___
{
	static inline bool ___share___()
	{
		return random_access_const_iterator_a<>::___share___;
	}
};

}

#endif
