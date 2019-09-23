#ifndef COM_ONEISH_STRANGE_EXPRESSION_WHILE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_WHILE_R_H

namespace strange
{

template<>
class reflection<expression_while_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_while");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_while::val", native_function_t<>::val(&expression_while_t<>::over::val__));
		shoal.update_string("strange::while", native_function_t<>::val(&expression_while_t<>::over::val__));
	}
};

class ___expression_while_t_share___
{
	static inline bool ___share___()
	{
		return expression_while_t<>::___share___;
	}
};

}

#endif
