#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_R_H

namespace strange
{

template<>
class reflection<expression_intimate_attribute_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_intimate_attribute");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		// nope: shoal.update_string("strange::expression_intimate_attribute::val", native_function_t<>::val(&expression_intimate_attribute_t<>::over::val__));
	}
};

class ___expression_intimate_attribute_t_share___
{
	static inline bool ___share___()
	{
		return expression_intimate_attribute_t<>::___share___;
	}
};

}

#endif
