#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_R_H

namespace strange
{

template<>
class reflection<expression_local_at_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_local_at");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::expression_local_at::val", native_function_t<>::val(&expression_local_at_t<>::val__));
	}
};

}

#endif
