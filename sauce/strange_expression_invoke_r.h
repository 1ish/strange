#ifndef COM_ONEISH_STRANGE_EXPRESSION_INVOKE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_INVOKE_R_H

namespace strange
{

template<>
class reflection<expression_invoke_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_invoke");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::expression_invoke::val", native_function_t<>::val(&expression_invoke_t<>::val__));
	}
};

}

#endif
