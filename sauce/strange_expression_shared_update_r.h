#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_R_H

namespace strange
{

template<>
class reflection<expression_shared_update_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_update");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_shared_update::create", native_function_t<>::create(&expression_shared_update_t<>::over::create__));
	}
};

class ___expression_shared_update_t_share___
{
	static inline bool ___share___()
	{
		return expression_shared_update_t<>::___share___;
	}
};

}

#endif
