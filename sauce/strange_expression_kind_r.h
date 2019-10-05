#ifndef COM_ONEISH_STRANGE_EXPRESSION_KIND_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_KIND_R_H

namespace strange
{

template<>
class reflection<expression_kind_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_kind");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_kind::create", native_function_t<>::create(&expression_kind_t<>::over::create__));
	}
};

class ___expression_kind_t_share___
{
	static inline bool ___share___()
	{
		return expression_kind_t<>::___share___;
	}
};

}

#endif
