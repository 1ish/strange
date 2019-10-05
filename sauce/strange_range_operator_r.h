#ifndef COM_ONEISH_STRANGE_RANGE_OPERATOR_R_H
#define COM_ONEISH_STRANGE_RANGE_OPERATOR_R_H

namespace strange
{

template<>
class reflection<range_operator_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::range_operator");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::range_operator::create", native_function_t<>::create(&range_operator_t<>::create__));
	}
};

class ___range_operator_t_share___
{
	static inline bool ___share___()
	{
		return range_operator_t<>::___share___;
	}
};

}

#endif
