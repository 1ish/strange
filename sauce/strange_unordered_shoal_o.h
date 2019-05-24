#ifndef COM_ONEISH_STRANGE_UNORDERED_SHOAL_O_H
#define COM_ONEISH_STRANGE_UNORDERED_SHOAL_O_H

namespace strange
{

template<>
class abstraction<unordered_shoal_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::unordered_shoal"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<shoal_a<>>::operations();
	}
};

}

#endif
