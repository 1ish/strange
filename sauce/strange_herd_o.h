#ifndef COM_ONEISH_STRANGE_HERD_O_H
#define COM_ONEISH_STRANGE_HERD_O_H

namespace strange
{

template<>
class abstraction<herd_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::herd"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<collection_a<>>::operations();
	}
};

}

#endif
