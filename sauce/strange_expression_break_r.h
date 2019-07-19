#ifndef COM_ONEISH_STRANGE_EXPRESSION_BREAK_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_BREAK_R_H

namespace strange
{

template<>
class reflection<expression_break_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_break");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_break::val", native_function_t<>::val(&expression_break_t<>::over::val__));
		shoal.update_string("strange::break_", native_function_t<>::val(&expression_break_t<>::over::val__));
	}
};

}

#endif
