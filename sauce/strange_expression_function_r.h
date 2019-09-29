#ifndef COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_R_H

namespace strange
{

template<>
class reflection<expression_function_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_function");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_function::val", native_function_t<>::val(&expression_function_t<>::over::val__));
		shoal.update_string("function", native_function_t<>::val(&expression_function_t<>::over::val__));
	}
};

class ___expression_function_t_share___
{
	static inline bool ___share___()
	{
		return expression_function_t<>::___share___;
	}
};

}

#endif
