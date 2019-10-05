#ifndef COM_ONEISH_STRANGE_EXPRESSION_FOR_RANGE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_FOR_RANGE_R_H

namespace strange
{

template<>
class reflection<expression_for_range_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_for_range");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_for_range::create", native_function_t<>::create(&expression_for_range_t<>::over::create__));
		shoal.update_string("for_range!", native_function_t<>::create(&expression_for_range_t<>::over::create__));
	}
};

class ___expression_for_range_t_share___
{
	static inline bool ___share___()
	{
		return expression_for_range_t<>::___share___;
	}
};

}

#endif
