#ifndef COM_ONEISH_STRANGE_COLLECTION_R_H
#define COM_ONEISH_STRANGE_COLLECTION_R_H

namespace strange
{

template<>
class reflection<collection_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::collection");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<range_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<range_a<>>::operations();
			operations.update_string("has", native_extraction_t<collection_a<>>::val(&collection_a<>::has__));
			operations.update_string("at", native_extraction_t<collection_a<>>::val(&collection_a<>::at__));
			operations.update_string("update", native_mutation_t<collection_a<>>::val(&collection_a<>::update__));
			operations.update_string("insert", native_mutation_t<collection_a<>>::val(&collection_a<>::insert__));
			operations.update_string("erase", native_mutation_t<collection_a<>>::val(&collection_a<>::erase__));
			operations.update_string("clear", native_mutation_t<collection_a<>>::val(&collection_a<>::clear__));
			operations.update_string("size", native_extraction_t<collection_a<>>::val(&collection_a<>::size__));
			operations.update_string("empty", native_extraction_t<collection_a<>>::val(&collection_a<>::empty__));
			operations.update_string("push_front", native_mutation_t<collection_a<>>::val(&collection_a<>::push_front__));
			operations.update_string("pop_front", native_mutation_t<collection_a<>>::val(&collection_a<>::pop_front__));
			operations.update_string("push_back", native_mutation_t<collection_a<>>::val(&collection_a<>::push_back__));
			operations.update_string("pop_back", native_mutation_t<collection_a<>>::val(&collection_a<>::pop_back__));
			operations.update_string("self_add", native_mutation_t<collection_a<>>::val(&collection_a<>::self_add__));
			operations.update_string("add", native_extraction_t<collection_a<>>::val(&collection_a<>::add__));
			operations.update_string("self_subtract", native_mutation_t<collection_a<>>::val(&collection_a<>::self_subtract__));
			operations.update_string("subtract", native_extraction_t<collection_a<>>::val(&collection_a<>::subtract__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___collection_a_share___
{
	static inline bool ___share___()
	{
		return collection_a<>::___share___;
	}
};

}

#endif
