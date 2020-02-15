#ifndef COM_ONEISH_STRANGE_DECLARATIONS_H
#define COM_ONEISH_STRANGE_DECLARATIONS_H

// forward declarations

namespace strange
{
// things
class one_t;
}

// abstractions
#include "generated/declare_strange_range_a.hpp"
#include "generated/declare_strange_symbol_a.hpp"
#include "generated/declare_strange_lake_a.hpp"

namespace strange
{
template <typename _1_ = void>
using lake_int8_a = lake_a<int8_t>;
}

#include "generated/declare_strange_cat_a.hpp"
#include "generated/declare_strange_kind_a.hpp"
#include "generated/declare_strange_inventory_a.hpp"
#include "generated/declare_strange_unordered_herd_a.hpp"
#include "generated/declare_strange_shoal_a.hpp"
#include "generated/declare_strange_unordered_shoal_a.hpp"
#include "generated/declare_strange_number_data_a.hpp"

namespace strange
{
template <typename _1_ = void>
using number_data_int8_a = number_data_a<int8_t>;

template <typename _1_ = void>
using number_data_int64_a = number_data_a<int64_t>;

template <typename _1_ = void>
using number_data_uint64_a = number_data_a<uint64_t>;

template <typename _1_ = void>
using number_data_double_a = number_data_a<double>;
}

#include "generated/declare_strange_any_a.hpp"
#include "generated/declare_strange_forward_const_iterator_a.hpp"
#include "generated/declare_strange_forward_const_iterator_data_a.hpp"
#include "generated/declare_strange_forward_iterator_a.hpp"
#include "generated/declare_strange_forward_iterator_data_a.hpp"
#include "generated/declare_strange_bidirectional_const_iterator_a.hpp"
#include "generated/declare_strange_bidirectional_const_iterator_data_a.hpp"
#include "generated/declare_strange_bidirectional_iterator_a.hpp"
#include "generated/declare_strange_bidirectional_iterator_data_a.hpp"
#include "generated/declare_strange_random_access_const_iterator_a.hpp"
#include "generated/declare_strange_random_access_const_iterator_data_a.hpp"
#include "generated/declare_strange_random_access_iterator_a.hpp"
#include "generated/declare_strange_random_access_iterator_data_a.hpp"
#include "generated/declare_strange_misunderstanding_a.hpp"
#include "generated/declare_strange_range_of_a.hpp"
#include "generated/declare_strange_collection_a.hpp"
#include "generated/declare_strange_ordered_shoal_a.hpp"
#include "generated/declare_strange_flock_a.hpp"
#include "generated/declare_strange_squad_a.hpp"
#include "generated/declare_strange_herd_a.hpp"
#include "generated/declare_strange_ordered_herd_a.hpp"
#include "generated/declare_strange_data_a.hpp"
#include "generated/declare_strange_number_a.hpp"
#include "generated/declare_strange_river_a.hpp"
#include "generated/declare_strange_brook_a.hpp"
#include "generated/declare_strange_token_a.hpp"
#include "generated/declare_strange_operation_a.hpp"
#include "generated/declare_strange_expression_a.hpp"
#include "generated/declare_strange_parser_a.hpp"

namespace strange
{
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
