#ifndef COM_ONEISH_STRANGE_EXPRESSION_OR_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_OR_R_H

namespace strange
{

template<>
class reflection<expression_or_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_or");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_or::create", native_function_t<>::create(&expression_or_t<>::over::create__));
	}
};

class ___expression_or_t_share___
{
	static inline bool ___share___()
	{
		return expression_or_t<>::___share___;
	}
};

}

#endif
