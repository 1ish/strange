#ifndef COM_ONEISH_STRANGE_FORWARD_ITERATOR_A_H
#define COM_ONEISH_STRANGE_FORWARD_ITERATOR_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/forward_iterator.hpp > ~/source/repos/strange/sauce/strange_forward_iterator_a.h
*/

#include "any.hpp"

namespace strange
{

template <typename _1_>
class forward_iterator_a
{
public:
	// forward iterator
	inline any_a<> get(any_a<> const& _) const;
	inline any_a<> get_() const;
	inline any_a<> set(any_a<> const& range) const;
	inline any_a<> set_(any_a<> const& thing) const;
	inline any_a<>& operator*() const;
	inline any_a<>* operator->() const;

	inline forward_iterator_a increment(any_a<> const& _);
	inline forward_iterator_a increment_();
};

} // namespace strange

#endif
