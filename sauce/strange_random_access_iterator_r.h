#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_R_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_R_H

namespace strange
{

template<>
class reflection<random_access_iterator_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::create(1, "strange::random_access_iterator");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<bidirectional_iterator_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<bidirectional_iterator_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<bidirectional_iterator_a<>>::operations();
			operations.update_string("self_add_", native_mutation_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::self_add__));
			operations.update_string("add_", native_extraction_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::add__));
			operations.update_string("self_subtract_", native_mutation_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::self_subtract__));
			operations.update_string("subtract_", native_extraction_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::subtract__));
			operations.update_string("less_than_", native_extraction_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::less_than__));
			operations.update_string("greater_than_", native_extraction_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::greater_than__));
			operations.update_string("less_or_equal_", native_extraction_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::less_or_equal__));
			operations.update_string("greater_or_equal_", native_extraction_t<random_access_iterator_a<>>::create(&random_access_iterator_a<>::greater_or_equal__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
	}
};

class ___random_access_iterator_a_share___
{
	static inline bool ___share___()
	{
		return random_access_iterator_a<>::___share___;
	}
};

}

#endif
