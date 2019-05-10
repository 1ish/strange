#ifndef COM_ONEISH_STRANGE_RANGE_A_H
#define COM_ONEISH_STRANGE_RANGE_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/range.hpp > ~/source/repos/strange/sauce/strange_range_a.h
*/

#include "any_forward.hpp"
#include "forward_const_iterator_forward.hpp"

namespace strange
{

template <typename _1_>
class range_a
{
public:
	// range
	inline any_a<> beget__(range_a const& _) const;
	inline forward_const_iterator_a<> beget_() const;
	inline forward_const_iterator_a<> cbegin() const;
	inline forward_const_iterator_a<> begin() const;

	inline any_a<> enget__(range_a const& _) const;
	inline forward_const_iterator_a<> enget_() const;
	inline forward_const_iterator_a<> cend() const;
	inline forward_const_iterator_a<> end() const;
};

} // namespace strange

#endif
