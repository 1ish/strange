#ifndef COM_ONEISH_STRANGE_ABSTRACTION_R_H
#define COM_ONEISH_STRANGE_ABSTRACTION_R_H

namespace strange
{

template<>
class reflection<abstraction_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::abstraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::abstraction::val", native_function_t<>::val(&abstraction_t<>::val__));
	}
};

class ___abstraction_t_share___
{
	static inline bool ___share___()
	{
		return abstraction_t<>::___share___;
	}
};

}

#endif
