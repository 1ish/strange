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
		shoal.update_string("strange::range_operator::val", native_function_t<>::val(&range_operator_t<>::val__));
	}
};

}

#endif
