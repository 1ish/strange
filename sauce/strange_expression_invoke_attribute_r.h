#ifndef COM_ONEISH_STRANGE_EXPRESSION_INVOKE_ATTRIBUTE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_INVOKE_ATTRIBUTE_R_H

namespace strange
{

template<>
class reflection<expression_invoke_attribute_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_invoke_attribute");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		// nope: shoal.update_string("strange::expression_invoke_attribute::create", native_function_t<>::create(&expression_invoke_attribute_t<>::over::create__));
	}
};

class ___expression_invoke_attribute_t_share___
{
	static inline bool ___share___()
	{
		return expression_invoke_attribute_t<>::___share___;
	}
};

}

#endif
