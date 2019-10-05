#ifndef COM_ONEISH_STRANGE_CONCEPTION_R_H
#define COM_ONEISH_STRANGE_CONCEPTION_R_H

namespace strange
{

template<>
class reflection<conception_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::conception");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::conception::create", native_function_t<>::create(&conception_t<>::create__));
	}
};

class ___conception_t_share___
{
	static inline bool ___share___()
	{
		return conception_t<>::___share___;
	}
};

}

#endif
