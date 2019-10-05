#ifndef COM_ONEISH_STRANGE_EXPRESSION_FLOCK_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_FLOCK_R_H

namespace strange
{

template<>
class reflection<expression_flock_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_flock");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_flock::create", native_function_t<>::create(&expression_flock_t<>::over::create__));
	}
};

class ___expression_flock_t_share___
{
	static inline bool ___share___()
	{
		return expression_flock_t<>::___share___;
	}
};

}

#endif
