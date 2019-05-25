#ifndef COM_ONEISH_STRANGE_NOTHING_R_H
#define COM_ONEISH_STRANGE_NOTHING_R_H

namespace strange
{

template<>
class reflection<nothing_t<>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::nothing");
		return TYPE;
	}

	static inline void share(shoal_a<> const& shoal)
	{
		auto ref = shoal_a<>(shoal, true);
		ref.update("strange::nothing::val", native_function_t<>::val(&nothing_t<>::val__));
	}
};

}

#endif
