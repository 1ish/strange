#ifndef COM_ONEISH_STRANGE_FLOCK_O_H
#define COM_ONEISH_STRANGE_FLOCK_O_H

namespace strange
{

template<>
class reflection<flock_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::flock"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<inventory_a<>>::operations();
	}
};

}

#endif
