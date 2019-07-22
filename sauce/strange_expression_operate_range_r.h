#ifndef COM_ONEISH_STRANGE_EXPRESSION_OPERATE_RANGE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_OPERATE_RANGE_R_H

namespace strange
{

template<>
class reflection<expression_operate_range_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_operate_range");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_operate_range::val", native_function_t<>::val(&expression_operate_range_t<>::over::val__));
	}
};

class ___expression_operate_range_t_share___
{
	static inline bool ___share___()
	{
		return expression_operate_range_t<>::___share___;
	}
};

}

#endif
