#ifndef COM_ONEISH_STRANGE_DECLARATIONS_H
#define COM_ONEISH_STRANGE_DECLARATIONS_H

// forward declarations

namespace strange
{

// things
class one_t;

// abstractions
template <typename range_a = range_a<>, typename symbol_a = symbol_a<>, typename cat_a = cat_a<>, typename inventory_a = inventory_a<>, typename unordered_herd_a = unordered_herd_a<>, typename shoal_a = shoal_a<>, typename unordered_shoal_a = unordered_shoal_a<>, typename number_data_a_uint64 = number_data_a<uint64_t>>
class any_a;
template <typename _1_ = void>
class symbol_a;

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

template <typename _1_ = void>
class range_a;

template <typename number_data_a_int64 = number_data_a<int64_t>>
class collection_a;

template <typename _1_ = void>
class shoal_a;

template <typename _1_ = void>
class ordered_shoal_a;

template <typename _1_ = void>
class unordered_shoal_a;

template <typename _1_ = void>
class flock_a;

template <typename _1_ = void>
class squad_a;

template <typename _1_ = void>
class herd_a;

template <typename _1_ = void>
class ordered_herd_a;

template <typename _1_ = void>
class unordered_herd_a;

template <typename _1_>
class data_a;

template <typename number_data_a_int64 = number_data_a<int64_t>, typename number_data_a_uint64 = number_data_a<uint64_t>, typename number_data_a_double = number_data_a<double>>
class number_a;

template <typename _1_>
class number_data_a;

template <typename lake_a_int8 = lake_a<int8_t>>
class river_a;

template <typename _1_ = void>
class inventory_a;

template <typename _1_>
class lake_a;

template <typename _1_>
class brook_a;

template <typename lake_a_int8 = lake_a<int8_t>>
class cat_a;

template <typename _1_ = void>
class kind_a;

template <typename number_data_a_int64 = number_data_a<int64_t>>
class token_a;

template <typename _1_ = void>
class operation_a;

template <typename number_data_a_int64 = number_data_a<int64_t>>
class expression_a;

// logic
inline any_a<> yes();
inline any_a<> no();
inline any_a<> boole(bool b);

// shared
inline shoal_a<> shared();

}

#endif
