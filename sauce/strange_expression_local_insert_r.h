#ifndef COM_ONEISH_STRANGE_EXPRESSION_LOCAL_INSERT_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_LOCAL_INSERT_R_H

namespace strange
{

template<>
class reflection<expression_local_insert_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_local_insert");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_local_insert::val", native_function_t<>::val(&expression_local_insert_t<>::val__));
	}
};

}

#endif
