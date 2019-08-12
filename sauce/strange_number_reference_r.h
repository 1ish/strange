#ifndef COM_ONEISH_STRANGE_NUMBER_REFERENCE_R_H
#define COM_ONEISH_STRANGE_NUMBER_REFERENCE_R_H

namespace strange
{

template<typename PRIMITIVE>
class reflection<number_reference_t<PRIMITIVE>>
{
public:
	static inline symbol_a<> type()
	{
		static symbol_a<> TYPE = sym("strange::number_reference_" + number_u<PRIMITIVE>::category());
		return TYPE;
	}
};

}

#endif
