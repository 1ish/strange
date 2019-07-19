#ifndef COM_ONEISH_STRANGE_EXPRESSION_RETURN_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_RETURN_R_H

namespace strange
{

template<>
class reflection<expression_return_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_return");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_return::val", native_function_t<>::val(&expression_return_t<>::over::val__));
		shoal.update_string("strange::return_", native_function_t<>::val(&expression_return_t<>::over::val__));
	}
};

}

#endif
