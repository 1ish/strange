#ifndef COM_ONEISH_STRANGE_H
#define COM_ONEISH_STRANGE_H

#include <vector>
#include <unordered_set>
#include <unordered_map>

// options
#include "strange_options.h"

namespace strange
{

template <typename _1_ = void>
class symbol_a;

template <typename _1_ = void>
class cat_a;

template <typename _1_ = void>
class forward_iterator_a;

template <typename _1_>
class forward_iterator_data_a;

template <typename _1_ = void>
class misunderstanding_a;

template <typename _1_ = void>
class collection_a;

template <typename _1_ = void>
class shoal_a;

template <typename _1_ = void>
class flock_a;

template <typename _1_ = void>
class herd_a;

template <typename _1_>
class data_a;

template <typename _1_ = void>
class number_a;

template <typename _1_>
class number_data_a;

template <typename _1_ = void>
class bidirectional_iterator_a;

template <typename _1_>
class bidirectional_iterator_data_a;

template <typename _1_ = void>
class random_access_iterator_a;

template <typename _1_>
class random_access_iterator_data_a;

}

// abstractions
#include "strange_any_a.h"
#define ___root___ any_a<>
#include "strange_symbol_a.h"
#define ___derived___ symbol_a<>
#include "strange_cat_a.h"
#include "strange_forward_iterator_a.h"
#define ___derived___ forward_iterator_a<>
#include "strange_forward_iterator_data_a.h"
#include "strange_misunderstanding_a.h"
#include "strange_collection_a.h"
#define ___derived___ collection_a<>
#include "strange_shoal_a.h"
#define ___derived___ collection_a<>
#include "strange_flock_a.h"
#define ___derived___ collection_a<>
#include "strange_herd_a.h"
#include "strange_data_a.h"
#include "strange_number_a.h"
#define ___derived___ number_a<>
#include "strange_number_data_a.h"
#define ___derived___ forward_iterator_a<>
#include "strange_bidirectional_iterator_a.h"
#define ___derived___ bidirectional_iterator_a<>
#include "strange_bidirectional_iterator_data_a.h"
#define ___derived___ bidirectional_iterator_a<>
#include "strange_random_access_iterator_a.h"
#define ___derived___ random_access_iterator_a<>
#include "strange_random_access_iterator_data_a.h"

#undef ___root___
#undef ___derived___

// things
#include "strange_one_t.h"
#include "strange_thing_t.h"
#include "strange_native_function_t.h"
#include "strange_native_extraction_t.h"
#include "strange_native_mutation_t.h"
#include "strange_something_t.h"
#include "strange_everything_t.h"
#include "strange_nothing_t.h"
#include "strange_it_t.h"
#include "strange_symbol_t.h"
#include "strange_cat_t.h"
#include "strange_range_t.h"
#include "strange_misunderstanding_t.h"
#include "strange_disagreement_t.h"
#include "strange_collection_t.h"
#include "strange_shoal_t.h"
#include "strange_flock_t.h"
#include "strange_herd_t.h"

// utilities
#include "strange_variadic_u.h"

#endif
