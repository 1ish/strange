#ifndef COM_ONEISH_STRANGE_EXPRESSION_CONTINUE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_CONTINUE_R_H

namespace strange
{

template<>
class reflection<expression_continue_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_continue");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::expression_continue::val", native_function_t<>::val(&expression_continue_t<>::val__));
	}
};

}

#endif