#ifndef COM_ONEISH_STRANGE_SQUAD_R_H
#define COM_ONEISH_STRANGE_SQUAD_R_H

namespace strange
{

template<>
class reflection<squad_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::squad"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return reflection<inventory_a<>>::operations();
	}
};

}

#endif
