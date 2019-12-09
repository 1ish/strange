#ifndef COM_ONEISH_STRANGE_IT_R_H
#define COM_ONEISH_STRANGE_IT_R_H

namespace strange
{

template<>
class reflection<it_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::it");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::it::create", native_function_t<>::create(&it_t<>::create__));
	}
};

class ___it_t_share___
{
	static inline bool ___share___()
	{
		return it_t<>::___share___;
	}
};

}

#endif
