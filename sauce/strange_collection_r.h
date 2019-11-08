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
		static cat_a<> CAT = cat_t<>::create(1, "strange::collection");
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

	static inline kind_a<> kind()
	{
		static kind_a<> KIND = kind_from_cat(cat());
		return KIND;
	}

	static inline unordered_herd_a<> kinds()
	{
		static unordered_herd_a<> KINDS = []()
		{
			auto kinds = reflection<range_a<>>::kinds();
			kinds.insert(kind());
			return kinds;
		}();
		return KINDS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<range_a<>>::operations();
			operations.update_string("has_", native_extraction_t<collection_a<>>::create(&collection_a<>::has__));
			operations.update_string("at_", native_extraction_t<collection_a<>>::create(&collection_a<>::at__));
			operations.update_string("update_", native_mutation_t<collection_a<>>::create(&collection_a<>::update__));
			operations.update_string("insert_", native_mutation_t<collection_a<>>::create(&collection_a<>::insert__));
			operations.update_string("erase_", native_mutation_t<collection_a<>>::create(&collection_a<>::erase__));
			operations.update_string("clear_", native_mutation_t<collection_a<>>::create(&collection_a<>::clear__));
			operations.update_string("size_", native_extraction_t<collection_a<>>::create(&collection_a<>::size__));
			operations.update_string("empty_", native_extraction_t<collection_a<>>::create(&collection_a<>::empty__));
			operations.update_string("push_front_", native_mutation_t<collection_a<>>::create(&collection_a<>::push_front__));
			operations.update_string("pop_front_", native_mutation_t<collection_a<>>::create(&collection_a<>::pop_front__));
			operations.update_string("push_back_", native_mutation_t<collection_a<>>::create(&collection_a<>::push_back__));
			operations.update_string("pop_back_", native_mutation_t<collection_a<>>::create(&collection_a<>::pop_back__));
			operations.update_string("self_add_", native_mutation_t<collection_a<>>::create(&collection_a<>::self_add__));
			operations.update_string("add_", native_extraction_t<collection_a<>>::create(&collection_a<>::add__));
			operations.update_string("self_subtract_", native_mutation_t<collection_a<>>::create(&collection_a<>::self_subtract__));
			operations.update_string("subtract_", native_extraction_t<collection_a<>>::create(&collection_a<>::subtract__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(kind(), operations());
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
