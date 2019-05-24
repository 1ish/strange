#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_DATA_R_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_DATA_R_H

namespace strange
{

template<>
class reflection<bidirectional_iterator_data_a<std::map<any_a<>, any_a<>>::iterator>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::bidirectional_iterator_data_shoal"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<bidirectional_iterator_a<>>::operations();
	}
};

}

#endif
