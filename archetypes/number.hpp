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

	inline any_a<> self_add__(range_a<> const& range);
	inline number_a self_add_(number_a const& number);

	inline any_a<> add__(range_a<> const& range) const;
	inline number_a add_(number_a const& number) const;
	inline number_a operator+(number_a const& number) const;

	inline any_a<> self_subtract__(range_a<> const& range);
	inline number_a self_subtract_(number_a const& number);

	inline any_a<> subtract__(range_a<> const& range) const;
	inline number_a subtract_(number_a const& number) const;
	inline number_a operator-(number_a const& number) const;

	inline any_a<> self_multiply__(range_a<> const& range);
	inline number_a self_multiply_(number_a const& number);

	inline any_a<> multiply__(range_a<> const& range) const;
	inline number_a multiply_(number_a const& number) const;
	inline number_a operator*(number_a const& number) const;

	inline any_a<> self_divide__(range_a<> const& range);
	inline number_a self_divide_(number_a const& number);

	inline any_a<> divide__(range_a<> const& range) const;
	inline number_a divide_(number_a const& number) const;
	inline number_a operator/(number_a const& number) const;

	inline any_a<> self_modulo__(range_a<> const& range);
	inline number_a self_modulo_(number_a const& number);

	inline any_a<> modulo__(range_a<> const& range) const;
	inline number_a modulo_(number_a const& number) const;
	inline number_a operator%(number_a const& number) const;

	inline any_a<> to_int_64__(range_a<> const& _) const;
	inline number_data_a_int64 to_int_64_() const;
	inline int64_t to_int_64() const;

	inline any_a<> from_int_64__(range_a<> const& range);
	inline any_a<> from_int_64_(number_data_a_int64 const& int_64);
	inline void from_int_64(int64_t int_64);

	inline any_a<> to_uint_64__(range_a<> const& _) const;
	inline number_data_a_uint64 to_uint_64_() const;
	inline uint64_t to_uint_64() const;

	inline any_a<> from_uint_64__(range_a<> const& range);
	inline any_a<> from_uint_64_(number_data_a_uint64 const& uint_64);
	inline void from_uint_64(uint64_t uint_64);

	inline any_a<> to_float_64__(range_a<> const& _) const;
	inline number_data_a_double to_float_64_() const;
	inline double to_float_64() const;

	inline any_a<> from_float_64__(range_a<> const& range);
	inline any_a<> from_float_64_(number_data_a_double const& float_64);
	inline void from_float_64(double float_64);

	inline any_a<> less_than__(range_a<> const& range) const;
	inline any_a<> less_than_(number_a const& number) const;
	inline bool operator<(number_a const& number) const;

	inline any_a<> greater_than__(range_a<> const& range) const;
	inline any_a<> greater_than_(number_a const& number) const;
	inline bool operator>(number_a const& number) const;

	inline any_a<> less_or_equal__(range_a<> const& range) const;
	inline any_a<> less_or_equal_(number_a const& number) const;
	inline bool operator<=(number_a const& number) const;

	inline any_a<> greater_or_equal__(range_a<> const& range) const;
	inline any_a<> greater_or_equal_(number_a const& number) const;
	inline bool operator>=(number_a const& number) const;

	inline any_a<> byte_size__(range_a<> const& _) const;
	inline number_data_a_int64 byte_size_() const;
	inline int64_t byte_size() const;

	inline any_a<> is_int__(range_a<> const& _) const;
	inline any_a<> is_int_() const;
	inline bool is_int() const;

	inline any_a<> is_signed__(range_a<> const& _) const;
	inline any_a<> is_signed_() const;
	inline bool is_signed() const;

	inline any_a<> is_nan__(range_a<> const& _) const;
	inline any_a<> is_nan_() const;
	inline bool is_nan() const;

	inline any_a<> is_inf__(range_a<> const& _) const;
	inline any_a<> is_inf_() const;
	inline bool is_inf() const;

	inline any_a<> is_finite__(range_a<> const& _) const;
	inline any_a<> is_finite_() const;
	inline bool is_finite() const;

	inline any_a<> is_normal__(range_a<> const& _) const;
	inline any_a<> is_normal_() const;
	inline bool is_normal() const;

	inline any_a<> little_endian__(range_a<> const& _) const;
	inline any_a<> little_endian_() const;
	inline bool little_endian() const;
};

} // namespace strange

#endif
