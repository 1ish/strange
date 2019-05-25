#ifndef COM_ONEISH_STRANGE_SOMETHING_R_H
#define COM_ONEISH_STRANGE_SOMETHING_R_H

namespace strange
{

template<>
class reflection<something_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::something");
		return TYPE;
	}

	static inline void share(shoal_a<> const& shoal)
	{
		auto ref = shoal_a<>(shoal, true);
		ref.update("strange::something::val", native_function_t<>::val(&something_t<>::val__));
	}
};

}

#endif
