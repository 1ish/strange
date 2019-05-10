#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_A_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_CONST_ITERATOR_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/dderived.hpp -c ~/source/repos/strange/archetypes/bidirectional_const_iterator.hpp > ~/source/repos/strange/sauce/strange_bidirectional_const_iterator_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename _1_>
class bidirectional_const_iterator_a
{
public:
	// bidirectional iterator
	inline any_a<> decrement__(range_a<> const& _);
	inline bidirectional_const_iterator_a decrement_();
};

} // namespace strange

#endif
