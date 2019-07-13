#ifndef COM_ONEISH_STRANGE_CREATURE_R_H
#define COM_ONEISH_STRANGE_CREATURE_R_H

namespace strange
{

template<>
class reflection<creature_c<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::creature");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::creature::val", native_function_t<>::val(&creature_c<>::val__));
	}
};

}

#endif
