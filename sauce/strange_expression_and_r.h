#ifndef COM_ONEISH_STRANGE_EXPRESSION_AND_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_AND_R_H

namespace strange
{

template<>
class reflection<expression_and_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_and");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_and::create", native_function_t<>::create(&expression_and_t<>::over::create__));
	}
};

class ___expression_and_t_share___
{
	static inline bool ___share___()
	{
		return expression_and_t<>::___share___;
	}
};

}

#endif
