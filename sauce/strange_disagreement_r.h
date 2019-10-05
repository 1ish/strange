#ifndef COM_ONEISH_STRANGE_DISAGREEMENT_R_H
#define COM_ONEISH_STRANGE_DISAGREEMENT_R_H

namespace strange
{

template<>
class reflection<disagreement_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::disagreement");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::disagreement::create", native_function_t<>::create(&disagreement_t<>::create__));
	}
};

class ___disagreement_t_share___
{
	static inline bool ___share___()
	{
		return disagreement_t<>::___share___;
	}
};

}

#endif
