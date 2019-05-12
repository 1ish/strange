#ifndef COM_ONEISH_STRANGE_ABSTRACTIONS_H
#define COM_ONEISH_STRANGE_ABSTRACTIONS_H

// forward declarations

namespace strange
{

template <typename _1_ = void>
class symbol_a;

template <typename _1_ = void>
class cat_a;

template <typename _1_ = void>
class forward_const_iterator_a;

template <typename _1_>
class forward_const_iterator_data_a;

template <typename _1_ = void>
class forward_iterator_a;

template <typename _1_>
class forward_iterator_data_a;

template <typename _1_ = void>
class misunderstanding_a;

template <typename _1_ = void>
class range_a;

template <typename number_data_a_int64 = number_data_a<int64_t>>
class collection_a;

template <typename bidirectional_iterator_a = bidirectional_iterator_a<>>
class shoal_a;

template <typename random_access_iterator_a = random_access_iterator_a<>>
class flock_a;

template <typename _1_ = void>
class squad_a;

template <typename _1_ = void>
class herd_a;

template <typename _1_>
class data_a;

template <typename number_data_a_int64 = number_data_a<int64_t>, typename number_data_a_uint64 = number_data_a<uint64_t>, typename number_data_a_double = number_data_a<double>>
class number_a;

template <typename _1_>
class number_data_a;

template <typename random_access_iterator_a = random_access_iterator_a<>>
class inventory_a;

template <typename _1_>
class lake_a;

template <typename _1_>
class brook_a;

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

}

// abstractions

#include "strange_any_a.h"

#define ___root___ any_a<>
#include "strange_symbol_a.h"

#define ___derived___ symbol_a<>
#include "strange_cat_a.h"

#include "strange_forward_const_iterator_a.h"

#define ___derived___ forward_const_iterator_a<>
#include "strange_forward_const_iterator_data_a.h"

#include "strange_forward_iterator_a.h"

#define ___derived___ forward_iterator_a<>
#include "strange_forward_iterator_data_a.h"

#include "strange_misunderstanding_a.h"

#include "strange_range_a.h"

#define ___derived___ range_a<>
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

#define ___derived___ collection_a<>
#include "strange_inventory_a.h"

#define ___derived___ inventory_a<>
#include "strange_squad_a.h"

#define ___derived___ inventory_a<>
#include "strange_lake_a.h"

#define ___derived___ inventory_a<>
#include "strange_brook_a.h"

#define ___derived___ forward_const_iterator_a<>
#include "strange_bidirectional_const_iterator_a.h"

#define ___derived___ bidirectional_const_iterator_a<>
#include "strange_bidirectional_const_iterator_data_a.h"

#define ___derived___ forward_iterator_a<>
#include "strange_bidirectional_iterator_a.h"

#define ___derived___ bidirectional_iterator_a<>
#include "strange_bidirectional_iterator_data_a.h"

#define ___derived___ bidirectional_const_iterator_a<>
#include "strange_random_access_const_iterator_a.h"

#define ___derived___ random_access_const_iterator_a<>
#include "strange_random_access_const_iterator_data_a.h"

#define ___derived___ bidirectional_iterator_a<>
#include "strange_random_access_iterator_a.h"

#define ___derived___ random_access_iterator_a<>
#include "strange_random_access_iterator_data_a.h"

#undef ___root___
#undef ___derived___

#endif
