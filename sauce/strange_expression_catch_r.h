#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_CATCH_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_CATCH_R_H

namespace strange
{

template<>
class reflection<expression_catch_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_catch");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_catch::val", native_function_t<>::val(&expression_catch_t<>::over::val__));
		shoal.update_string("strange::catch_", native_function_t<>::val(&expression_catch_t<>::over::val__));
	}
};

}

#endif
