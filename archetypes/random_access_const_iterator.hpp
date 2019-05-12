#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_A_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ddderived.hpp -c ~/source/repos/strange/archetypes/random_access_const_iterator.hpp > ~/source/repos/strange/sauce/strange_random_access_const_iterator_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "number_forward.hpp"

namespace strange
{

template <typename _1_>
class random_access_const_iterator_a
{
public:
	// random access const iterator
	inline any_a<> self_add__(range_a<> const& range);
	inline random_access_const_iterator_a self_add_(number_a<> const& number);

	inline any_a<> add__(range_a<> const& range) const;
	inline random_access_const_iterator_a add_(number_a<> const& number) const;
	inline random_access_const_iterator_a operator+(number_a<> const& number) const;

	inline any_a<> self_subtract__(range_a<> const& range);
	inline random_access_const_iterator_a self_subtract_(number_a<> const& number);

	inline any_a<> subtract__(range_a<> const& range) const;
	inline random_access_const_iterator_a subtract_(number_a<> const& number) const;
	inline random_access_const_iterator_a operator-(number_a<> const& number) const;

	inline any_a<> less_than__(range_a<> const& range) const;
	inline any_a<> less_than_(random_access_const_iterator_a const& it) const;
	inline bool operator<(random_access_const_iterator_a const& it) const;

	inline any_a<> greater_than__(range_a<> const& range) const;
	inline any_a<> greater_than_(random_access_const_iterator_a const& it) const;
	inline bool operator>(random_access_const_iterator_a const& it) const;

	inline any_a<> less_or_equal__(range_a<> const& range) const;
	inline any_a<> less_or_equal_(random_access_const_iterator_a const& it) const;
	inline bool operator<=(random_access_const_iterator_a const& it) const;

	inline any_a<> greater_or_equal__(range_a<> const& range) const;
	inline any_a<> greater_or_equal_(random_access_const_iterator_a const& it) const;
	inline bool operator>=(random_access_const_iterator_a const& it) const;
};

} // namespace strange

#endif
