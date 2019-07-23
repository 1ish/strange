#ifndef COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_R_H

namespace strange
{

template<>
class reflection<expression_extraction_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_extraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_extraction::val", native_function_t<>::val(&expression_extraction_t<>::over::val__));
	}
};

class ___expression_extraction_t_share___
{
	static inline bool ___share___()
	{
		return expression_extraction_t<>::___share___;
	}
};

}

#endif
