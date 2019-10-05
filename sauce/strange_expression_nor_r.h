#ifndef COM_ONEISH_STRANGE_EXPRESSION_NOR_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_NOR_R_H

namespace strange
{

template<>
class reflection<expression_nor_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_nor");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_nor::create", native_function_t<>::create(&expression_nor_t<>::over::create__));
	}
};

class ___expression_nor_t_share___
{
	static inline bool ___share___()
	{
		return expression_nor_t<>::___share___;
	}
};

}

#endif
