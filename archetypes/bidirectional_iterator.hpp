#ifndef COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_A_H
#define COM_ONEISH_STRANGE_BIDIRECTIONAL_ITERATOR_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/dderived.hpp -c ~/source/repos/strange/archetypes/bidirectional_iterator.hpp > ~/source/repos/strange/sauce/strange_bidirectional_iterator_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class bidirectional_iterator_a
{
public:
	// bidirectional iterator
	inline any_a<> decrement(any_a<> const& _);
	inline bidirectional_iterator_a decrement_();
};

} // namespace strange

#endif
