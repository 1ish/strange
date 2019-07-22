#ifndef COM_ONEISH_STRANGE_EXPRESSION_CAT_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_CAT_R_H

namespace strange
{

template<>
class reflection<expression_cat_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_cat");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_cat::val", native_function_t<>::val(&expression_cat_t<>::over::val__));
	}
};

class ___expression_cat_t_share___
{
	static inline bool ___share___()
	{
		return expression_cat_t<>::___share___;
	}
};

}

#endif
