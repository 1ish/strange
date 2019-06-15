#ifndef COM_ONEISH_STRANGE_EXPRESSION_OPERATE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_OPERATE_R_H

namespace strange
{

template<>
class reflection<expression_operate_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_operate");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_operate::val", native_function_t<>::val(&expression_operate_t<>::val__));
	}
};

}

#endif
