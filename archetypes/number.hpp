#ifndef COM_ONEISH_STRANGE_NUMBER_A_H
#define COM_ONEISH_STRANGE_NUMBER_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/number.hpp > ~/source/repos/strange/sauce/strange_number_a.h
*/

#include "data.hpp"

namespace strange
{

template <typename _1_>
class number
{
public:
	// number
	inline number_a decrement(any_a _);
	inline number_a decrement_();

	inline number_a self_add(any_a range);
	inline number_a self_add_(number_a number);

	inline number_a add(any_a range) const;
	inline number_a add_(number_a number) const;
	inline number_a operator+(number_a number) const;

	inline number_a self_subtract(any_a range);
	inline number_a self_subtract_(number_a number);

	inline number_a subtract(any_a range) const;
	inline number_a subtract_(number_a number) const;
	inline number_a operator-(number_a number) const;

	inline number_a self_multiply(any_a range);
	inline number_a self_multiply_(number_a number);

	inline number_a multiply(any_a range) const;
	inline number_a multiply_(number_a number) const;
	inline number_a operator*(number_a number) const;

	inline number_a self_divide(any_a range);
	inline number_a self_divide_(number_a number);

	inline number_a divide(any_a range) const;
	inline number_a divide_(number_a number) const;
	inline number_a operator/(number_a number) const;

	inline number_a self_modulo(any_a range);
	inline number_a self_modulo_(number_a number);

	inline number_a modulo(any_a range) const;
	inline number_a modulo_(number_a number) const;
	inline number_a operator%(number_a number) const;

	inline number_a to_integer64(any_a _) const;
	inline number_a to_integer64_() const;
	inline int64_t to_int64__() const;

	inline any_a from_integer64(any_a range);
	inline any_a from_integer64_(number_a integer64);
	inline void from_int64__(int64_t int64);

	inline number_a to_float64(any_a _) const;
	inline number_a to_float64_() const;
	inline double to_double__() const;

	inline any_a from_float64(any_a range);
	inline any_a from_float64_(number_a float64);
	inline void from_double__(double dbl);

	inline any_a less_than(any_a range) const;
	inline any_a less_than_(number_a number) const;
	inline bool operator<(number_a number) const;

	inline any_a greater_than(any_a range) const;
	inline any_a greater_than_(number_a number) const;
	inline bool operator>(number_a number) const;

	inline any_a less_or_equal(any_a range) const;
	inline any_a less_or_equal_(number_a number) const;
	inline bool operator<=(number_a number) const;

	inline any_a greater_or_equal(any_a range) const;
	inline any_a greater_or_equal_(number_a number) const;
	inline bool operator>=(number_a number) const;
};

} // namespace strange

#endif
