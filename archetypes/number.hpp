#ifndef COM_ONEISH_STRANGE_NUMBER_A_H
#define COM_ONEISH_STRANGE_NUMBER_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived_1.hpp -c ~/source/repos/strange/archetypes/number.hpp > ~/source/repos/strange/sauce/strange_number_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class number_a
{
public:
	// number
	inline number_a decrement(any_a<> const& _);
	inline number_a decrement_();

	inline number_a self_add(any_a<> const& range);
	inline number_a self_add_(number_a const& number);

	inline number_a add(any_a<> const& range) const;
	inline number_a add_(number_a const& number) const;
	inline number_a operator+(number_a const& number) const;

	inline number_a self_subtract(any_a<> const& range);
	inline number_a self_subtract_(number_a const& number);

	inline number_a subtract(any_a<> const& range) const;
	inline number_a subtract_(number_a const& number) const;
	inline number_a operator-(number_a const& number) const;

	inline number_a self_multiply(any_a<> const& range);
	inline number_a self_multiply_(number_a const& number);

	inline number_a multiply(any_a<> const& range) const;
	inline number_a multiply_(number_a const& number) const;
	inline number_a operator*(number_a const& number) const;

	inline number_a self_divide(any_a<> const& range);
	inline number_a self_divide_(number_a const& number);

	inline number_a divide(any_a<> const& range) const;
	inline number_a divide_(number_a const& number) const;
	inline number_a operator/(number_a const& number) const;

	inline number_a self_modulo(any_a<> const& range);
	inline number_a self_modulo_(number_a const& number);

	inline number_a modulo(any_a<> const& range) const;
	inline number_a modulo_(number_a const& number) const;
	inline number_a operator%(number_a const& number) const;

	inline number_a to_int_64(any_a<> const& _) const;
	inline number_a to_int_64_() const;
	inline int64_t to_int_64__() const;

	inline any_a<> from_int_64(any_a<> const& range);
	inline any_a<> from_int_64_(number_a const& int_64);
	inline void from_int_64__(int64_t int_64);

	inline number_a to_float_64(any_a<> const& _) const;
	inline number_a to_float_64_() const;
	inline double to_float_64__() const;

	inline any_a<> from_float_64(any_a<> const& range);
	inline any_a<> from_float_64_(number_a const& float_64);
	inline void from_float_64__(double float_64);

	inline any_a<> less_than(any_a<> const& range) const;
	inline any_a<> less_than_(number_a const& number) const;
	inline bool operator<(number_a const& number) const;

	inline any_a<> greater_than(any_a<> const& range) const;
	inline any_a<> greater_than_(number_a const& number) const;
	inline bool operator>(number_a const& number) const;

	inline any_a<> less_or_equal(any_a<> const& range) const;
	inline any_a<> less_or_equal_(number_a const& number) const;
	inline bool operator<=(number_a const& number) const;

	inline any_a<> greater_or_equal(any_a<> const& range) const;
	inline any_a<> greater_or_equal_(number_a const& number) const;
	inline bool operator>=(number_a const& number) const;
};

} // namespace strange

#endif
