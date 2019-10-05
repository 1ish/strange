#ifndef COM_ONEISH_STRANGE_EXPRESSION_DO_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_DO_R_H

namespace strange
{

template<>
class reflection<expression_do_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_do");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_do::create", native_function_t<>::create(&expression_do_t<>::over::create__));
		shoal.update_string("do!", native_function_t<>::create(&expression_do_t<>::over::create__));
	}
};

class ___expression_do_t_share___
{
	static inline bool ___share___()
	{
		return expression_do_t<>::___share___;
	}
};

}

#endif
