#ifndef COM_ONEISH_STRANGE_DECLARATIONS_H
#define COM_ONEISH_STRANGE_DECLARATIONS_H

// forward declarations

namespace strange
{

// things
class one_t;

// abstractions
template <typename _1_ = void>
class range_a;

template <typename _1_ = void>
class symbol_a;

template <typename _1_>
class lake_a;

template <typename lake_a_int8 = lake_a<int8_t>>
class cat_a;

template <typename _1_ = void>
class kind_a;

template <typename _1_ = void>
class inventory_a;

template <typename _1_ = void>
class unordered_herd_a;

template <typename _1_ = void>
class shoal_a;

template <typename _1_ = void>
class unordered_shoal_a;

template <typename _1_>
class number_data_a;

template <typename _1_ = void>
using number_data_int64_a = number_data_a<int64_t>;

template <typename _1_ = void>
using number_data_uint64_a = number_data_a<uint64_t>;

template <typename _1_ = void>
using number_data_double_a = number_data_a<double>;

template <typename range_a = range_a<>, typename symbol_a = symbol_a<>, typename cat_a = cat_a<>, typename kind_a = kind_a<>, typename inventory_a = inventory_a<>, typename unordered_herd_a = unordered_herd_a<>, typename shoal_a = shoal_a<>, typename unordered_shoal_a = unordered_shoal_a<>, typename number_data_uint64_a = number_data_uint64_a<>>
class any_a;
template <typename _1_ = void>
class forward_const_iterator_a;

template <typename _1_>
class forward_const_iterator_data_a;

template <typename _1_ = void>
class forward_iterator_a;

template <typename _1_>
class forward_iterator_data_a;

template <typename _1_ = void>
class bidirectional_const_iterator_a;

template <typename _1_>
class bidirectional_const_iterator_data_a;

template <typename _1_ = void>
class bidirectional_iterator_a;

template <typename _1_>
class bidirectional_iterator_data_a;

template <typename _1_ = void>
class random_access_const_iterator_a;

template <typename _1_>
class random_access_const_iterator_data_a;

template <typename _1_ = void>
class random_access_iterator_a;

template <typename _1_>
class random_access_iterator_data_a;

template <typename _1_ = void>
class misunderstanding_a;

template <typename _element_ = any_a<>>
class range_of_a;

template <typename number_data_int64_a = number_data_int64_a<>>
class collection_a;

template <typename _1_ = void>
class ordered_shoal_a;

template <typename _1_ = void>
class flock_a;

template <typename _1_ = void>
class squad_a;

template <typename _1_ = void>
class herd_a;

template <typename _1_ = void>
class ordered_herd_a;

template <typename _1_>
class data_a;

template <typename number_data_int64_a = number_data_int64_a<>, typename number_data_uint64_a = number_data_uint64_a<>, typename number_data_double_a = number_data_double_a<>>
class number_a;

template <typename lake_a_int8 = lake_a<int8_t>>
class river_a;

template <typename _1_>
class brook_a;

template <typename number_data_int64_a = number_data_int64_a<>>
class token_a;

template <typename _1_ = void>
class operation_a;

template <typename number_data_int64_a = number_data_int64_a<>>
class expression_a;

template <typename _1_ = void>
class parser_a;

// reflection
template<typename _abstraction_or_thing_>
class reflection;

// logic
inline any_a<> yes();
inline any_a<> no();
inline any_a<> boole(bool b);

// shared
inline shoal_a<>& shared();

// pipe
inline any_a<> operator|(any_a<> const& thing, any_a<> const& adaptor);

// check/cast
template <typename ___TTT___>
inline bool check(any_a<> const& value) noexcept;
template <typename ___TTT___, typename ___VVV___>
inline bool check(___VVV___ const&) noexcept;
#ifdef STRANGE_CHECK_STATIC_CASTS
template <typename ___TTT___>
inline ___TTT___ cast(any_a<> const& value);
#else
template <typename ___TTT___>
inline ___TTT___ cast(any_a<> const& value) noexcept;
#endif
#ifdef STRANGE_CHECK_STATIC_CASTS
template <typename ___TTT___>
inline ___TTT___ cast_ref(any_a<>& value);
#else
template <typename ___TTT___>
inline ___TTT___ cast_ref(any_a<>& value) noexcept;
#endif
#ifdef STRANGE_CHECK_STATIC_CASTS
template <typename ___TTT___>
inline ___TTT___ cast_dup(any_a<>& value);
#else
template <typename ___TTT___>
inline ___TTT___ cast_dup(any_a<>& value) noexcept;
#endif

}

#endif
