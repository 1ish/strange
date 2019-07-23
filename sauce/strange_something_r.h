#ifndef COM_ONEISH_STRANGE_SOMETHING_R_H
#define COM_ONEISH_STRANGE_SOMETHING_R_H

namespace strange
{

template<>
class reflection<something_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::something");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::something::val", native_function_t<>::val(&something_t<>::val__));
	}
};

class ___something_t_share___
{
	static inline bool ___share___()
	{
		return something_t<>::___share___;
	}
};

}

#endif
