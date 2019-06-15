#ifndef COM_ONEISH_STRANGE_IT_R_H
#define COM_ONEISH_STRANGE_IT_R_H

namespace strange
{

template<>
class reflection<it_t<true>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::const_it");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::const_it::val", native_function_t<>::val(&it_t<true>::val__));
	}
};

template<>
class reflection<it_t<false>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::it");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::it::val", native_function_t<>::val(&it_t<false>::val__));
	}
};

}

#endif
