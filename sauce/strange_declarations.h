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

template <typename ___ego___ = operation_a<>>
class native_function_t;

template <typename _abstraction_, typename ___ego___ = operation_a<>>
class native_extraction_t;

template <typename _abstraction_, typename ___ego___ = operation_a<>>
class native_mutation_t;

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

// native function
using native_function_pointer = any_a<>(*)(range_a<> const&);

template <typename... Args>
inline operation_a<> native_function_create(native_function_pointer const fun, Args&&... args);

// native extraction
template <typename _abstraction_>
using native_const_member_pointer = any_a<>(_abstraction_::*)(range_a<> const&) const;

template <typename _abstraction_, typename... Args>
inline operation_a<> native_extraction_create(native_const_member_pointer<_abstraction_> const fun, Args&&... args);

// native mutation
template <typename _abstraction_>
using native_member_pointer = any_a<>(_abstraction_::*)(range_a<> const&);

template <typename _abstraction_, typename... Args>
inline operation_a<> native_mutation_create(native_member_pointer<_abstraction_> const fun, Args&&... args);

// number
inline number_data_a<int64_t> int_64_from_string(std::string const& str);
inline number_data_a<double> float_64_from_string(std::string const& str);

template <typename _primitive_, typename _result_ = number_data_a<_primitive_>>
inline _result_ num(_primitive_ primitive);

// range
inline range_a<> range_create();
inline range_a<> range_create(forward_const_iterator_a<> const& begin, forward_const_iterator_a<> const& end);

// flock
template <bool _concurrent_ = false>
inline flock_a<> flock_create();

template <typename F>
inline flock_a<> flock_create(F&& init);

// lake
inline lake_a<int8_t> lake_from_string(std::string const& str);
inline std::string lake_to_string(lake_a<int8_t> const& lake);

template <typename F>
inline lake_a<int8_t> lake_int8_create(F&& init);

// ordered herd
template <bool _concurrent_ = false>
inline ordered_herd_a<> ordered_herd_create();

// ordered shoal
template <bool _concurrent_ = false>
inline ordered_shoal_a<> ordered_shoal_create();

// squad
template <bool _concurrent_ = false>
inline squad_a<> squad_create();

// unordered herd
template <bool _concurrent_ = false>
inline unordered_herd_a<> unordered_herd_create();

// unordered shoal
template <bool _concurrent_ = false>
inline unordered_shoal_a<> unordered_shoal_create();

// cat
template <typename ___cat_a___ = cat_a<>>
inline ___cat_a___ cat_create(int64_t order = 1, std::string const& name = "");

template <typename ___cat_a___ = cat_a<>>
inline ___cat_a___ cat_create(int64_t order, std::string const& name, flock_a<> const& dimensions);

template <typename ___cat_a___ = cat_a<>>
inline ___cat_a___ cat_create(int64_t order, std::string const& name, flock_a<> const& dimensions, flock_a<> const& parameters, symbol_a<> const& result);

// kind
inline kind_a<> kind_create();
inline kind_a<> kind_create(int64_t order, std::string const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool fixed = false, bool reference = false, bool optional = false);
inline kind_a<> kind_from_cat(cat_a<> const& cat);
inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects);
inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional);
inline cat_a<> kind_to_cat(kind_a<> const& kind);
inline unordered_herd_a<> kinds_to_cats(unordered_herd_a<> const& kinds);

// attributes
inline operation_a<> attribute_extraction_create(any_a<> const& thing);
inline operation_a<> attribute_mutation_create(symbol_a<> const& name, any_a<> const& kind, any_a<> const& thing);

// expressions
inline expression_a<> expression_intimate_create(token_a<> const& token, flock_a<> const& terms);
inline expression_a<> expression_intimate_member_create(token_a<> const& token, flock_a<> const& terms);
inline expression_a<> expression_intimate_member_range_create(token_a<> const& token, flock_a<> const& terms);
inline expression_a<> expression_intimate_attribute_create(token_a<> const& token, flock_a<> const& terms);

// operate
template <typename... Args>
inline any_a<> variadic_operate(any_a<> const& op, any_a<>& thing, Args&&... args);

// check/cast

template <typename ___TTT___ = any_a<>>
inline bool check(any_a<> const& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ fast(any_a<> const& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ fast_ref(any_a<>& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ fast_dup(any_a<>& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ cast(any_a<> const& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ cast_ref(any_a<>& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ cast_dup(any_a<>& value) noexcept;
}

#endif
