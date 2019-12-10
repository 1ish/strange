#ifndef COM_ONEISH_STRANGE_EXPRESSION_CHECK_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_CHECK_R_H

namespace strange
{

template<>
class reflection<expression_check_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_check");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_check::create", native_function_t<>::create(&expression_check_t<>::over::create__));
		shoal.update_string("check!", native_function_t<>::create(&expression_check_t<>::over::create__));
	}
};

class ___expression_check_t_share___
{
	static inline bool ___share___()
	{
		return expression_check_t<>::___share___;
	}
};

}

#endif
