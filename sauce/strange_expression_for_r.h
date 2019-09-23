#ifndef COM_ONEISH_STRANGE_EXPRESSION_FOR_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_FOR_R_H

namespace strange
{

template<>
class reflection<expression_for_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_for");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_for::val", native_function_t<>::val(&expression_for_t<>::over::val__));
		shoal.update_string("strange::for", native_function_t<>::val(&expression_for_t<>::over::val__));
	}
};

class ___expression_for_t_share___
{
	static inline bool ___share___()
	{
		return expression_for_t<>::___share___;
	}
};

}

#endif
