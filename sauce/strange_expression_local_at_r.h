#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_AT_R_H

namespace strange
{

template<>
class reflection<expression_local_at_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_local_at");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_local_at::create", native_function_t<>::create(&expression_local_at_t<>::over::create__));
	}
};

class ___expression_local_at_t_share___
{
	static inline bool ___share___()
	{
		return expression_local_at_t<>::___share___;
	}
};

}

#endif
