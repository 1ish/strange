#ifndef COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_MUTATION_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_ATTRIBUTE_MUTATION_R_H

namespace strange
{

template<>
class reflection<expression_attribute_mutation_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_attribute_mutation");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_attribute_mutation::val", native_function_t<>::val(&expression_attribute_mutation_t<>::over::val__));
	}
};

class ___expression_attribute_mutation_t_share___
{
	static inline bool ___share___()
	{
		return expression_attribute_mutation_t<>::___share___;
	}
};

}

#endif
