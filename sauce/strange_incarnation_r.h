#ifndef COM_ONEISH_STRANGE_INCARNATION_R_H
#define COM_ONEISH_STRANGE_INCARNATION_R_H

namespace strange
{

template<>
class reflection<incarnation_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::incarnation");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::incarnation::create", native_function_t<>::create(&incarnation_t<>::create__));
	}
};

class ___incarnation_t_share___
{
	static inline bool ___share___()
	{
		return incarnation_t<>::___share___;
	}
};

}

#endif
