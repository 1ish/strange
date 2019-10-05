#ifndef COM_ONEISH_STRANGE_EXPRESSION_XOR_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_XOR_R_H

namespace strange
{

template<>
class reflection<expression_xor_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_xor");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_xor::create", native_function_t<>::create(&expression_xor_t<>::over::create__));
	}
};

class ___expression_xor_t_share___
{
	static inline bool ___share___()
	{
		return expression_xor_t<>::___share___;
	}
};

}

#endif
