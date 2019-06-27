#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_AT_R_H

namespace strange
{

template<>
class reflection<expression_shared_at_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_at");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_shared_at::val", native_function_t<>::val(&expression_shared_at_t<>::over::val__));
	}
};

}

#endif
