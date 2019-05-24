#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_DATA_O_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_DATA_O_H

namespace strange
{

template<>
class abstraction<bidirectional_iterator_data_a<std::map<any_a<>, any_a<>>::iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::bidirectional_iterator_data_shoal"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<bidirectional_iterator_a<>>::operations();
	}
};

}

#endif
