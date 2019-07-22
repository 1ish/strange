#ifndef COM_ONEISH_STRANGE_EXPRESSION_THROW_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_THROW_R_H

namespace strange
{

template<>
class reflection<expression_throw_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_throw");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_throw::val", native_function_t<>::val(&expression_throw_t<>::over::val__));
		shoal.update_string("strange::throw_", native_function_t<>::val(&expression_throw_t<>::over::val__));
	}
};

class ___expression_throw_t_share___
{
	static inline bool ___share___()
	{
		return expression_throw_t<>::___share___;
	}
};

}

#endif
