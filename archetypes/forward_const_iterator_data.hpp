#ifndef COM_ONEISH_STRANGE_FORWARD_CONST_ITERATOR_DATA_A_H
#define COM_ONEISH_STRANGE_FORWARD_CONST_ITERATOR_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/forward_const_iterator_data.hpp > ~/source/repos/strange/sauce/strange_forward_const_iterator_data_a.h
*/

#include "forward_const_iterator_forward.hpp"

namespace strange
{

template <typename _1_>
class forward_const_iterator_data_a
{
public:
	// data
	inline _1_ const& extract__() const;
	inline void mutate__(_1_ const& data);
	inline _1_& reference__();
};

} // namespace strange

#endif
