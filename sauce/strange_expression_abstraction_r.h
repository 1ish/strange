#ifndef COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_R_H

namespace strange
{

template<>
class reflection<expression_abstraction_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_abstraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_abstraction::create", native_function_t<>::create(&expression_abstraction_t<>::over::create__));
		shoal.update_string("abstraction!", native_function_t<>::create(&expression_abstraction_t<>::over::create__));
	}
};

class ___expression_abstraction_t_share___
{
	static inline bool ___share___()
	{
		return expression_abstraction_t<>::___share___;
	}
};

}

#endif
