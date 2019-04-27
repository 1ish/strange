#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_A_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/random_access_iterator.hpp > ~/source/repos/strange/sauce/strange_random_access_iterator_a.h
*/

#include "any.hpp"

namespace strange
{

class random_access_iterator
{
public:
	// random access iterator
	inline random_access_iterator_a decrement(any_a _);
	inline random_access_iterator_a decrement_();

	inline random_access_iterator_a self_add(any_a range);
	inline random_access_iterator_a self_add_(any_a thing);

	inline random_access_iterator_a add(any_a range) const;
	inline random_access_iterator_a add_(any_a thing) const;
	inline random_access_iterator_a operator+(any_a thing) const;

	inline random_access_iterator_a self_subtract(any_a range);
	inline random_access_iterator_a self_subtract_(any_a thing);

	inline random_access_iterator_a subtract(any_a range) const;
	inline random_access_iterator_a subtract_(any_a thing) const;
	inline random_access_iterator_a operator-(any_a thing) const;

	inline any_a less_than(any_a range) const;
	inline any_a less_than_(random_access_iterator_a it) const;
	inline bool operator<(random_access_iterator_a it) const;

	inline any_a greater_than(any_a range) const;
	inline any_a greater_than_(random_access_iterator_a it) const;
	inline bool operator>(random_access_iterator_a it) const;

	inline any_a less_or_equal(any_a range) const;
	inline any_a less_or_equal_(random_access_iterator_a it) const;
	inline bool operator<=(random_access_iterator_a it) const;

	inline any_a greater_or_equal(any_a range) const;
	inline any_a greater_or_equal_(random_access_iterator_a it) const;
	inline bool operator>=(random_access_iterator_a it) const;
};

} // namespace strange

#endif
