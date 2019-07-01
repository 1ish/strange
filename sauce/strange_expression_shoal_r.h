#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHOAL_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHOAL_R_H

namespace strange
{

template<>
class reflection<expression_shoal_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_shoal");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_shoal::val", native_function_t<>::val(&expression_shoal_t<>::over::val__));
	}
};

}

#endif
