#ifndef COM_ONEISH_STRANGE_RANGE_OF_A_H
#define COM_ONEISH_STRANGE_RANGE_OF_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/range_of.hpp > ~/source/repos/strange/sauce/strange_range_of_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "forward_const_iterator_forward.hpp"

namespace strange
{

template <typename _element_>
class range_of_a
{
public:
	// range
	inline any_a<> cbegin__(range_a<> const& _) const;
	inline forward_const_iterator_a<> cbegin_() const;

	inline any_a<> cend__(range_a<> const& _) const;
	inline forward_const_iterator_a<> cend_() const;
};

} // namespace strange

#endif
