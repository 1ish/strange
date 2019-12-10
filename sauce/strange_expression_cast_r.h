#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAST_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAST_R_H

namespace strange
{

template<>
class reflection<expression_cast_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_cast");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_cast::create", native_function_t<>::create(&expression_cast_t<>::over::create__));
		shoal.update_string("cast!", native_function_t<>::create(&expression_cast_t<>::over::create__));
	}
};

class ___expression_cast_t_share___
{
	static inline bool ___share___()
	{
		return expression_cast_t<>::___share___;
	}
};

}

#endif
