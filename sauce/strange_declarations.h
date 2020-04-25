#ifndef COM_ONEISH_STRANGE_DECLARATIONS_H
#define COM_ONEISH_STRANGE_DECLARATIONS_H

#include "strange_concurrent_u.h"

// forward declarations

namespace strange
{
// things
class one_t;

// hash
template <typename ___ego___>
inline std_size_t hash_of(___ego___ const& thing);
}

// abstractions
#include "generated/declare_strange_forward_extractor_a.hpp"
#include "generated/declare_strange_forward_extractor_data_a.hpp"
#include "generated/declare_strange_forward_mutator_a.hpp"
#include "generated/declare_strange_forward_mutator_data_a.hpp"
#include "generated/declare_strange_bidirectional_extractor_a.hpp"
#include "generated/declare_strange_bidirectional_extractor_data_a.hpp"
#include "generated/declare_strange_bidirectional_mutator_a.hpp"
#include "generated/declare_strange_bidirectional_mutator_data_a.hpp"
#include "generated/declare_strange_random_access_extractor_a.hpp"
#include "generated/declare_strange_random_access_extractor_data_a.hpp"
#include "generated/declare_strange_random_access_mutator_a.hpp"
#include "generated/declare_strange_random_access_mutator_data_a.hpp"
#include "generated/declare_strange_symbol_a.hpp"
#include "generated/declare_strange_cat_a.hpp"
#include "generated/declare_strange_kind_a.hpp"
#include "generated/declare_strange_number_data_a.hpp"
template <> struct std::hash<strange::number_data_a<uint64_t>>
{
	inline strange::std_size_t operator()(strange::number_data_a<uint64_t> const& thing) const
	{
		return strange::hash_of(thing);
	}
};

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
template <> struct std::hash<strange::any_a<>>
{
	inline strange::std_size_t operator()(strange::any_a<> const& thing) const
	{
		return strange::hash_of(thing);
	}
};
#include "generated/declare_strange_lake_a.hpp"

namespace strange
{
template <typename _1_ = void>
using lake_int8_a = lake_a<int8_t>;
}

#include "generated/declare_strange_misunderstanding_a.hpp"
#include "generated/declare_strange_list_a.hpp"
#include "generated/declare_strange_range_a.hpp"
#include "generated/declare_strange_collection_a.hpp"
#include "generated/declare_strange_inventory_a.hpp"
#include "generated/declare_strange_flock_a.hpp"
#include "generated/declare_strange_squad_a.hpp"
#include "generated/declare_strange_herd_a.hpp"
#include "generated/declare_strange_ordered_herd_a.hpp"
#include "generated/declare_strange_unordered_herd_a.hpp"
#include "generated/declare_strange_shoal_a.hpp"
#include "generated/declare_strange_ordered_shoal_a.hpp"
#include "generated/declare_strange_unordered_shoal_a.hpp"
#include "generated/declare_strange_container_a.hpp"
template <> struct std::hash<strange::container_a<>>
{
	inline strange::std_size_t operator()(strange::container_a<> const& thing) const
	{
		return strange::hash_of(thing);
	}
};
#include "generated/declare_strange_container_data_a.hpp"
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

template <typename ___ego___ = list_a<>>
class list_t;

template <typename _element = any_a<>, typename ___ego___ = range_a<_element>>
class range_t;

template <typename ___ego___ = list_a<>>
class range_operator_t;

template <typename _element = any_a<>, bool _concurrent_ = false, typename ___ego___ = flock_a<_element>>
class flock_t;

template <typename _key = any_a<>, typename _value = any_a<>, bool _concurrent_ = false, typename ___ego___ = unordered_shoal_a<>>
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
using native_function_pointer = any_a<>(*)(list_a<> const&);

template <typename... Args>
inline operation_a<> native_function_create(native_function_pointer const fun, Args&&... args);

// native extraction
template <typename _abstraction_>
using native_const_member_pointer = any_a<>(_abstraction_::*)(list_a<> const&) const;

template <typename _abstraction_, typename... Args>
inline operation_a<> native_extraction_create(native_const_member_pointer<_abstraction_> const fun, Args&&... args);

// native mutation
template <typename _abstraction_>
using native_member_pointer = any_a<>(_abstraction_::*)(list_a<> const&);

template <typename _abstraction_, typename... Args>
inline operation_a<> native_mutation_create(native_member_pointer<_abstraction_> const fun, Args&&... args);

// number
inline number_data_a<int64_t> int_64_from_string(std_string const& str);
inline number_data_a<double> float_64_from_string(std_string const& str);

template <typename _primitive_, typename _result_ = number_data_a<_primitive_>>
inline _result_ num(_primitive_ primitive);

// list
inline list_a<> list_create();

inline list_a<> list_create(forward_extractor_a<any_a<>> const& begin, forward_extractor_a<any_a<>> const& end);

// range
template <typename _element = any_a<>>
inline range_a<_element> range_create();

template <typename _element = any_a<>>
inline range_a<_element> range_create(forward_extractor_a<_element> const& begin, forward_extractor_a<_element> const& end);

// range operator
inline list_a<> range_operator_create(list_a<> const& list, any_a<>& thing_ref, list_a<> const& list_ref);

// flock
template <typename _element = any_a<>, bool _concurrent_ = false>
inline flock_a<_element> flock_create();

template <typename F>
inline flock_a<> flock_create(F&& init);

template <typename... Args>
inline flock_a<> flock_vals(Args&&... args);

template <typename... Args>
inline flock_a<> flock_refs(Args&&... args);

template <typename... Args>
inline flock_a<> flock_dups(Args&&... args);

// lake
inline lake_a<int8_t> lake_from_string(std_string const& str);
inline std_string lake_to_string(lake_a<int8_t> const& lake);

template <typename F>
inline lake_a<int8_t> lake_int8_create(F&& init);

// ordered herd
template <typename _element = any_a<>, bool _concurrent_ = false>
inline ordered_herd_a<_element> ordered_herd_create();

template <typename... Args>
inline ordered_herd_a<> ordered_herd_vals(Args&&... args);

template <typename... Args>
inline ordered_herd_a<> ordered_herd_refs(Args&&... args);

template <typename... Args>
inline ordered_herd_a<> ordered_herd_dups(Args&&... args);

// ordered shoal
template <typename _key = any_a<>, typename _value = any_a<>, bool _concurrent_ = false>
inline ordered_shoal_a<_key, _value> ordered_shoal_create();

template <typename... Args>
inline ordered_shoal_a<> ordered_shoal_vals(Args&&... args);

// parcel
template <bool _concurrent_ = false>
inline container_data_a<dart_packet, dart_packet::iterator> parcel_create();

template <typename F>
inline container_data_a<dart_packet, dart_packet::iterator> parcel_create(F&& init);

// squad
template <typename _element = any_a<>, bool _concurrent_ = false>
inline squad_a<_element> squad_create();

// unordered herd
template <typename _element = any_a<>, bool _concurrent_ = false>
inline unordered_herd_a<_element> unordered_herd_create();

template <typename... Args>
inline unordered_herd_a<> unordered_herd_vals(Args&&... args);

template <typename... Args>
inline unordered_herd_a<> unordered_herd_refs(Args&&... args);

template <typename... Args>
inline unordered_herd_a<> unordered_herd_dups(Args&&... args);

// unordered shoal
template <typename _key = any_a<>, typename _value = any_a<>, bool _concurrent_ = false, typename ___unordered_shoal_a___ = unordered_shoal_a<_key, _value>>
inline ___unordered_shoal_a___ unordered_shoal_create();

template <typename... Args>
inline unordered_shoal_a<> unordered_shoal_vals(Args&&... args);

// cat
template <typename ___cat_a___ = cat_a<>>
inline ___cat_a___ cat_create(int64_t order = 1, std_string const& name = "");

template <typename ___cat_a___ = cat_a<>>
inline ___cat_a___ cat_create(int64_t order, std_string const& name, flock_a<> const& dimensions);

template <typename ___cat_a___ = cat_a<>>
inline ___cat_a___ cat_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& parameters, symbol_a<> const& result);

// kind
template <typename ___kind_a___ = kind_a<>>
inline ___kind_a___ kind_create(int64_t order = 1, std_string const& name = "");

template <typename ___kind_a___ = kind_a<>>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions);

template <typename ___kind_a___ = kind_a<>>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& aspects);

template <typename ___kind_a___ = kind_a<>>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters);

template <typename ___kind_a___ = kind_a<>>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool fixed = false, bool reference = false, bool optional = false);

inline kind_a<> kind_from_cat(cat_a<> const& cat);
inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects);
inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects);
inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional);
inline cat_a<> kind_to_cat(kind_a<> const& kind);
inline unordered_herd_a<> kinds_to_cats(unordered_herd_a<> const& kinds);

template <typename ___TTT___>
inline kind_a<> kind_of();
template <>
inline kind_a<> kind_of<int8_t>();
template <>
inline kind_a<> kind_of<uint8_t>();
template <>
inline kind_a<> kind_of<int16_t>();
template <>
inline kind_a<> kind_of<uint16_t>();
template <>
inline kind_a<> kind_of<int32_t>();
template <>
inline kind_a<> kind_of<uint32_t>();
template <>
inline kind_a<> kind_of<int64_t>();
template <>
inline kind_a<> kind_of<uint64_t>();
template <>
inline kind_a<> kind_of<float>();
template <>
inline kind_a<> kind_of<double>();
template <>
inline kind_a<> kind_of<std_shared_ptr<strange::concurrent_u<false>::read_lock>>();
template <>
inline kind_a<> kind_of<std_shared_ptr<strange::concurrent_u<false>::write_lock>>();
template <>
inline kind_a<> kind_of<std_shared_ptr<strange::concurrent_u<true>::read_lock>>();
template <>
inline kind_a<> kind_of<std_shared_ptr<strange::concurrent_u<true>::write_lock>>();
template <>
inline kind_a<> kind_of<std_istreambuf_iterator<char>>();
template <>
inline kind_a<> kind_of<std_vector<int8_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<int8_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint8_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint8_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<int16_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<int16_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint16_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint16_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<int32_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<int32_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint32_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint32_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<int64_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<int64_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint64_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint64_t>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<float>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<float>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<double>::const_iterator>();
template <>
inline kind_a<> kind_of<std_deque<double>::const_iterator>();
template <>
inline kind_a<> kind_of<std_vector<int8_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<int8_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint8_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint8_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<int16_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<int16_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint16_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint16_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<int32_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<int32_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint32_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint32_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<int64_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<int64_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<uint64_t>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<uint64_t>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<float>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<float>::iterator>();
template <>
inline kind_a<> kind_of<std_vector<double>::iterator>();
template <>
inline kind_a<> kind_of<std_deque<double>::iterator>();
template <>
inline kind_a<> kind_of<dart_packet::iterator>();

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
inline ___TTT___ fast_ref(any_a<> const& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ fast_dup(any_a<> const& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ cast(any_a<> const& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ cast_ref(any_a<> const& value) noexcept;

template <typename ___TTT___ = any_a<>>
inline ___TTT___ cast_dup(any_a<> const& value) noexcept;
}

#endif
