#ifndef COM_ONEISH_STRANGE_EXPRESSION_IF_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_IF_R_H

namespace strange
{

template<>
class reflection<expression_if_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_if");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_if::create", native_function_t<>::create(&expression_if_t<>::over::create__));
		shoal.update_string("if!", native_function_t<>::create(&expression_if_t<>::over::create__));
	}
};

class ___expression_if_t_share___
{
	static inline bool ___share___()
	{
		return expression_if_t<>::___share___;
	}
};

}

#endif
