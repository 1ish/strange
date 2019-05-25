#ifndef COM_ONEISH_STRANGE_FORWARD_CONST_ITERATOR_R_H
#define COM_ONEISH_STRANGE_FORWARD_CONST_ITERATOR_R_H

namespace strange
{

template<>
class reflection<forward_const_iterator_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::forward_const_iterator"));
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
			operations.update("get", native_extraction_t<forward_const_iterator_a<>>::val(&forward_const_iterator_a<>::get__));
			operations.update("increment", native_mutation_t<forward_const_iterator_a<>>::val(&forward_const_iterator_a<>::increment__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
