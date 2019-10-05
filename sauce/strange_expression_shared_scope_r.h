#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_SCOPE_R_H

namespace strange
{

template<>
class reflection<expression_shared_scope_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_scope");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_shared_scope::create", native_function_t<>::create(&expression_shared_scope_t<>::over::create__));
	}
};

class ___expression_shared_scope_t_share___
{
	static inline bool ___share___()
	{
		return expression_shared_scope_t<>::___share___;
	}
};

}

#endif
