#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_DATA_A_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ffinale_1.hpp -c ~/source/repos/strange/archetypes/bidirectional_const_iterator_data.hpp > ~/source/repos/strange/sauce/strange_bidirectional_const_iterator_data_a.h
*/

#include "bidirectional_const_iterator_forward.hpp"

namespace strange
{

template <typename _1_>
class bidirectional_const_iterator_data_a
{
public:
	// data
	inline _1_ const& extract() const;
	inline void mutate(_1_ const& data);
	inline _1_& reference();
};

} // namespace strange

#endif
