#ifndef COM_ONEISH_STRANGE_NUMBER_A_H
#define COM_ONEISH_STRANGE_NUMBER_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived_3.hpp -c ~/source/repos/strange/archetypes/number.hpp > ~/source/repos/strange/sauce/strange_number_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename number_data_a_int64, typename number_data_a_uint64, typename number_data_a_double>
class number_a
{
public:
	// number
	inline any_a<> increment__(range_a<> const& _);
	inline number_a increment_();

	inline any_a<> decrement__(range_a<> const& _);
	inline number_a decrement_();

	inline any_a<> self_add(range_a<> const& range);
	inline number_a self_add_(number_a const& number);

	inline any_a<> add(range_a<> const& range) const;
	inline number_a add_(number_a const& number) const;
	inline number_a operator+(number_a const& number) const;

	inline any_a<> self_subtract(range_a<> const& range);
	inline number_a self_subtract_(number_a const& number);

	inline any_a<> subtract(range_a<> const& range) const;
	inline number_a subtract_(number_a const& number) const;
	inline number_a operator-(number_a const& number) const;

	inline any_a<> self_multiply(range_a<> const& range);
	inline number_a self_multiply_(number_a const& number);

	inline any_a<> multiply(range_a<> const& range) const;
	inline number_a multiply_(number_a const& number) const;
	inline number_a operator*(number_a const& number) const;

	inline any_a<> self_divide(range_a<> const& range);
	inline number_a self_divide_(number_a const& number);

	inline any_a<> divide(range_a<> const& range) const;
	inline number_a divide_(number_a const& number) const;
	inline number_a operator/(number_a const& number) const;

	inline any_a<> self_modulo(range_a<> const& range);
	inline number_a self_modulo_(number_a const& number);

	inline any_a<> modulo(range_a<> const& range) const;
	inline number_a modulo_(number_a const& number) const;
	inline number_a operator%(number_a const& number) const;

	inline any_a<> to_int_64(range_a<> const& _) const;
	inline number_data_a_int64 to_int_64_() const;
	inline int64_t to_int_64__() const;

	inline any_a<> from_int_64(range_a<> const& range);
	inline any_a<> from_int_64_(number_data_a_int64 const& int_64);
	inline void from_int_64__(int64_t int_64);

	inline any_a<> to_uint_64(range_a<> const& _) const;
	inline number_data_a_uint64 to_uint_64_() const;
	inline uint64_t to_uint_64__() const;

	inline any_a<> from_uint_64(range_a<> const& range);
	inline any_a<> from_uint_64_(number_data_a_uint64 const& uint_64);
	inline void from_uint_64__(uint64_t uint_64);

	inline any_a<> to_float_64(range_a<> const& _) const;
	inline number_data_a_double to_float_64_() const;
	inline double to_float_64__() const;

	inline any_a<> from_float_64(range_a<> const& range);
	inline any_a<> from_float_64_(number_data_a_double const& float_64);
	inline void from_float_64__(double float_64);

	inline any_a<> less_than(range_a<> const& range) const;
	inline any_a<> less_than_(number_a const& number) const;
	inline bool operator<(number_a const& number) const;

	inline any_a<> greater_than(range_a<> const& range) const;
	inline any_a<> greater_than_(number_a const& number) const;
	inline bool operator>(number_a const& number) const;

	inline any_a<> less_or_equal(range_a<> const& range) const;
	inline any_a<> less_or_equal_(number_a const& number) const;
	inline bool operator<=(number_a const& number) const;

	inline any_a<> greater_or_equal(range_a<> const& range) const;
	inline any_a<> greater_or_equal_(number_a const& number) const;
	inline bool operator>=(number_a const& number) const;

	inline any_a<> byte_size(range_a<> const& _) const;
	inline number_data_a_int64 byte_size_() const;
	inline int64_t byte_size__() const;

	inline any_a<> is_int(range_a<> const& _) const;
	inline any_a<> is_int_() const;
	inline bool is_int__() const;

	inline any_a<> is_signed(range_a<> const& _) const;
	inline any_a<> is_signed_() const;
	inline bool is_signed__() const;

	inline any_a<> is_nan(range_a<> const& _) const;
	inline any_a<> is_nan_() const;
	inline bool is_nan__() const;

	inline any_a<> is_inf(range_a<> const& _) const;
	inline any_a<> is_inf_() const;
	inline bool is_inf__() const;

	inline any_a<> is_finite(range_a<> const& _) const;
	inline any_a<> is_finite_() const;
	inline bool is_finite__() const;

	inline any_a<> is_normal(range_a<> const& _) const;
	inline any_a<> is_normal_() const;
	inline bool is_normal__() const;

	inline any_a<> little_endian(range_a<> const& _) const;
	inline any_a<> little_endian_() const;
	inline bool little_endian__() const;
};

} // namespace strange

#endif
