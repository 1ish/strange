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
// things
template <typename _primitive_, typename ___ego___ = number_data_a<_primitive_>>
class number_t;

template <typename ___ego___ = kind_a<>>
class kind_t;

template <typename _data_, typename ___ego___ = data_a<_data_>>
class data_t;

template <typename ___ego___ = range_a<>>
class range_t;

template <typename ___ego___ = range_a<>>
class range_operator_t;

template <bool _concurrent_ = false, typename ___ego___ = flock_a<>>
class flock_t;

template <bool _concurrent_ = false, typename ___ego___ = unordered_shoal_a<>>
class unordered_shoal_t;

template <typename ___ego___ = expression_a<>>
class expression_t;

template <typename ___ego___ = expression_a<>>
class expression_and_t;

template <typename ___ego___ = expression_a<>>
class expression_attribute_extraction_t;

template <typename ___ego___ = expression_a<>>
class expression_attribute_mutation_t;

template <typename ___ego___ = expression_a<>>
class expression_block_t;

template <typename ___ego___ = expression_a<>>
class expression_extraction_t;

template <typename ___ego___ = expression_a<>>
class expression_flock_t;

template <typename ___ego___ = expression_a<>>
class expression_herd_t;

template <typename ___ego___ = expression_a<>>
class expression_intimate_attribute_t;

template <typename ___ego___ = expression_a<>>
class expression_intimate_member_range_t;

template <typename ___ego___ = expression_a<>>
class expression_intimate_member_t;

template <typename ___ego___ = expression_a<>>
class expression_intimate_t;

template <typename ___ego___ = expression_a<>>
class expression_invoke_attribute_t;

template <typename ___ego___ = expression_a<>>
class expression_invoke_member_range_t;

template <typename ___ego___ = expression_a<>>
class expression_invoke_t;

template <typename ___ego___ = expression_a<>>
class expression_kind_t;

template <typename ___ego___ = expression_a<>>
class expression_literal_t;

template <typename ___ego___ = expression_a<>>
class expression_local_at_t;

template <typename ___ego___ = expression_a<>>
class expression_local_insert_t;

template <typename ___ego___ = expression_a<>>
class expression_local_update_t;

template <typename ___ego___ = expression_a<>>
class expression_me_t;

template <typename ___ego___ = expression_a<>>
class expression_member_t;

template <typename ___ego___ = expression_a<>>
class expression_mutation_t;

template <typename ___ego___ = expression_a<>>
class expression_nand_t;

template <typename ___ego___ = expression_a<>>
class expression_nor_t;

template <typename ___ego___ = expression_a<>>
class expression_operate_range_t;

template <typename ___ego___ = expression_a<>>
class expression_operate_t;

template <typename ___ego___ = expression_a<>>
class expression_or_t;

template <typename ___ego___ = expression_a<>>
class expression_pipe_t;

template <typename ___ego___ = expression_a<>>
class expression_shared_at_t;

template <typename ___ego___ = expression_a<>>
class expression_shared_insert_t;

template <typename ___ego___ = expression_a<>>
class expression_shared_scope_t;

template <typename ___ego___ = expression_a<>>
class expression_shared_update_t;

template <typename ___ego___ = expression_a<>>
class expression_shoal_t;

template <typename ___ego___ = expression_a<>>
class expression_xnor_t;

template <typename ___ego___ = expression_a<>>
class expression_xor_t;

// creatures
template <typename ___ego___ = any_a<>>
class any_c;

template <typename ___ego___ = operation_a<>>
class operation_c;

template <typename ___ego___ = expression_a<>>
class expression_c;

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

// symbol
template <typename F>
inline symbol_a<> sym(F&& s);

// misunderstanding
template <typename F>
inline misunderstanding_a<> mis(F&& s);

// disagreement
template <typename F>
inline misunderstanding_a<> dis(F&& s);

// kind
inline kind_a<> kind_from_cat(cat_a<> const& cat);
inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects);
inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional);
inline cat_a<> kind_to_cat(kind_a<> const& kind);
inline unordered_herd_a<> kinds_to_cats(unordered_herd_a<> const& kinds);

// lake
lake_a<int8_t> lake_from_string(std::string const& str);
std::string lake_to_string(lake_a<int8_t> const& lake);

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
