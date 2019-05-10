#ifndef COM_ONEISH_STRANGE_FORWARD_ITERATOR_DATA_A_H
#define COM_ONEISH_STRANGE_FORWARD_ITERATOR_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/forward_iterator_data.hpp > ~/source/repos/strange/sauce/strange_forward_iterator_data_a.h
*/

#include "forward_iterator_forward.hpp"

namespace strange
{

template <typename _1_>
class forward_iterator_data_a
{
public:
	// data
	inline _1_ const& extract() const;
	inline void mutate(_1_ const& data);
	inline _1_& reference();
};

} // namespace strange

#endif
