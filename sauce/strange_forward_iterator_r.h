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
		static cat_a<> CAT = cat_t<>::val_(sym("strange::forward_iterator"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<any_a<>>::operations();
			operations.update("get", native_extraction_t<forward_iterator_a<>>::val(&forward_iterator_a<>::get__));
			operations.update("set", native_extraction_t<forward_iterator_a<>>::val(&forward_iterator_a<>::set__));
			operations.update("increment", native_mutation_t<forward_iterator_a<>>::val(&forward_iterator_a<>::increment__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
