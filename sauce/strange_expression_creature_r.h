#ifndef COM_ONEISH_STRANGE_EXPRESSION_CREATURE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_CREATURE_R_H

namespace strange
{

template<>
class reflection<expression_c<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_creature");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_creature::val", native_function_t<>::val(&expression_c<>::val__));
	}
};

class ___expression_c_share___
{
	static inline bool ___share___()
	{
		return expression_c<>::___share___;
	}
};

}

#endif
