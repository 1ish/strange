#ifndef COM_ONEISH_STRANGE_OPERATION_CREATURE_R_H
#define COM_ONEISH_STRANGE_OPERATION_CREATURE_R_H

namespace strange
{

template<>
class reflection<operation_c<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::operation_creature");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::operation_creature::create", native_function_t<>::create(&operation_c<>::create__));
	}
};

class ___operation_c_share___
{
	static inline bool ___share___()
	{
		return operation_c<>::___share___;
	}
};

}

#endif
