#ifndef COM_ONEISH_STRANGE_THING_R_H
#define COM_ONEISH_STRANGE_THING_R_H

namespace strange
{

template<>
class reflection<thing_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::thing");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::thing::invoke", native_function_t<>::create(&thing_t<>::invoke__));
		shoal.update_string("strange::thing::operate", native_function_t<>::create(&thing_t<>::operate__));
	}
};

class ___thing_t_share___
{
	static inline bool ___share___()
	{
		return thing_t<>::___share___;
	}
};

}

#endif
