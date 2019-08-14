#ifndef COM_ONEISH_STRANGE_CREATION_R_H
#define COM_ONEISH_STRANGE_CREATION_R_H

namespace strange
{

template<>
class reflection<creation_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::creation");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::creation::val", native_function_t<>::val(&creation_t<>::val__));
	}
};

class ___creation_t_share___
{
	static inline bool ___share___()
	{
		return creation_t<>::___share___;
	}
};

}

#endif
