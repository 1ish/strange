#ifndef COM_ONEISH_STRANGE_FORWARD_ITERATOR_R_H
#define COM_ONEISH_STRANGE_FORWARD_ITERATOR_R_H

namespace strange
{

template<>
class reflection<forward_iterator_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val("strange::forward_iterator");
		return CAT;
	}

	static inline unordered_herd_a<> cats()
	{
		static unordered_herd_a<> CATS = []()
		{
			auto cats = reflection<any_a<>>::cats();
			cats.insert(cat());
			return cats;
		}();
		return CATS;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update_string("get", native_extraction_t<forward_iterator_a<>>::val(&forward_iterator_a<>::get__));
			operations.update_string("set", native_extraction_t<forward_iterator_a<>>::val(&forward_iterator_a<>::set__));
			operations.update_string("increment", native_mutation_t<forward_iterator_a<>>::val(&forward_iterator_a<>::increment__));
			return operations;
		}();
		return OPERATIONS;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(cat(), operations());
	}
};

class ___forward_iterator_a_share___
{
	static inline bool ___share___()
	{
		return forward_iterator_a<>::___share___;
	}
};

}

#endif
