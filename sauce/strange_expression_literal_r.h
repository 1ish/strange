#ifndef COM_ONEISH_STRANGE_EXPRESSION_LITERAL_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_LITERAL_R_H

namespace strange
{

template<>
class reflection<expression_literal_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_literal");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::expression_literal::val", native_function_t<>::val(&expression_literal_t<>::val__));
	}
};

}

#endif
