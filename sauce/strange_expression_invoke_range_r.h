#ifndef COM_ONEISH_STRANGE_EXPRESSION_INVOKE_RANGE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_INVOKE_RANGE_R_H

namespace strange
{

template<>
class reflection<expression_invoke_range_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_invoke_range");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_invoke_range::val", native_function_t<>::val(&expression_invoke_range_t<>::val__));
	}
};

}

#endif
