#ifndef COM_ONEISH_STRANGE_EXPRESSION_XNOR_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_XNOR_R_H

namespace strange
{

template<>
class reflection<expression_xnor_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_xnor");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_xnor::val", native_function_t<>::val(&expression_xnor_t<>::over::val__));
	}
};

class ___expression_xnor_t_share___
{
	static inline bool ___share___()
	{
		return expression_xnor_t<>::___share___;
	}
};

}

#endif
