#ifndef COM_ONEISH_STRANGE_FUNCTION_R_H
#define COM_ONEISH_STRANGE_FUNCTION_R_H

namespace strange
{

template<>
class reflection<function_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::function");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
//TODO		shoal.update_string("strange::function::val", native_function_t<>::val(&function_t<>::over::val__));
	}
};

class ___function_t_share___
{
	static inline bool ___share___()
	{
		return function_t<>::___share___;
	}
};

}

#endif
