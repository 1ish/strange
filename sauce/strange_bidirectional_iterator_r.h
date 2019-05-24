#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_O_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_O_H

namespace strange
{

template<>
class reflection<bidirectional_iterator_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::bidirectional_iterator"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		static unordered_shoal_a<> OPERATIONS = []()
		{
			auto operations = reflection<forward_iterator_a<>>::operations();
			operations.update("decrement", native_mutation_t<bidirectional_iterator_a<>>::val(&bidirectional_iterator_a<>::decrement__));
			return operations;
		}();
		return OPERATIONS;
	}
};

}

#endif
