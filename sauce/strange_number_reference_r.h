#ifndef COM_ONEISH_STRANGE_NUMBER_REFERENCE_R_H
#define COM_ONEISH_STRANGE_NUMBER_REFERENCE_R_H

namespace strange
{

template<typename _primitive_>
class reflection<number_reference_t<_primitive_>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_" + number_u<_primitive_>::category());
		return TYPE;
	}
};

}

#endif
