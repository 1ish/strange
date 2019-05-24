#ifndef COM_ONEISH_STRANGE_SQUAD_O_H
#define COM_ONEISH_STRANGE_SQUAD_O_H

namespace strange
{

template<>
class abstraction<squad_a<>>
{
public:
	static inline cat_a<> cat()
	{
		static cat_a<> CAT = cat_t<>::val_(sym("strange::squad"));
		return CAT;
	}

	static inline unordered_shoal_a<> operations()
	{
		return abstraction<inventory_a<>>::operations();
	}
};

}

#endif
