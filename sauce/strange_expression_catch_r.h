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
		shoal.update_string("strange::expression_catch::create", native_function_t<>::create(&expression_catch_t<>::over::create__));
		shoal.update_string("catch!", native_function_t<>::create(&expression_catch_t<>::over::create__));
	}
};

class ___expression_catch_t_share___
{
	static inline bool ___share___()
	{
		return expression_catch_t<>::___share___;
	}
};

}

#endif
