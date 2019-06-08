#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_INSERT_R_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_INSERT_R_H

namespace strange
{

template<>
class reflection<expression_shared_insert_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_insert");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update("strange::expression_shared_insert::val", native_function_t<>::val(&expression_shared_insert_t<>::val__));
	}
};

}

#endif
