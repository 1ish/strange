#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_R_H

namespace strange
{

template<>
class reflection<expression_intimate_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_intimate");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_intimate::val", native_function_t<>::val(&expression_intimate_t<>::over::val__));
	}
};

}

#endif