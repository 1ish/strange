#ifndef COM_ONEISH_STRANGE_EXPRESSION_MEMBER_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_MEMBER_R_H

namespace strange
{

template<>
class reflection<expression_member_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_member");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_member::val", native_function_t<>::val(&expression_member_t<>::over::val__));
	}
};

class ___expression_member_t_share___
{
	static inline bool ___share___()
	{
		return expression_member_t<>::___share___;
	}
};

}

#endif
