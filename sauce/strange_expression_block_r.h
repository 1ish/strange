#ifndef COM_ONEISH_STRANGE_EXPRESSION_BLOCK_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_BLOCK_R_H

namespace strange
{

template<>
class reflection<expression_block_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_block");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_block::create", native_function_t<>::create(&expression_block_t<>::over::create__));
	}
};

class ___expression_block_t_share___
{
	static inline bool ___share___()
	{
		return expression_block_t<>::___share___;
	}
};

}

#endif
