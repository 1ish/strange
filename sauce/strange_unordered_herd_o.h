#ifndef COM_ONEISH_STRANGE_UNORDERED_HERD_O_H
#define COM_ONEISH_STRANGE_UNORDERED_HERD_O_H

namespace strange
{

template<>
class reflection<unordered_herd_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::unordered_herd"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<herd_a<>>::operations();
	}
};

}

#endif
