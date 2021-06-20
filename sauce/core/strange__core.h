#ifndef COM_ONEISH__STRANGE__CORE_H
#define COM_ONEISH__STRANGE__CORE_H

#include <atomic>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <mutex>
#include <shared_mutex>
#include <utility>

namespace strange
{
	struct any_a;

	template <typename A = any_a> struct con;
	template <typename A = any_a> struct var;
	template <typename A = any_a> struct ptr;

	struct symbol_a;
	struct cat_a;
	struct kind_a;
	template <typename type_d> struct data_a;
	struct lock_a;
	struct unlock_a;

	template <typename element_d = var<>> struct forward_extractor_a;
	template <typename element_d = var<>> struct forward_mutator_a;
	template <typename element_d = var<>> struct bidirectional_extractor_a;
	template <typename element_d = var<>> struct bidirectional_mutator_a;
	template <typename element_d = var<>> struct random_access_extractor_a;
	template <typename element_d = var<>> struct random_access_mutator_a;
	template <typename element_d = var<>> struct contiguous_extractor_a;
	template <typename element_d = var<>> struct contiguous_mutator_a;
	template <typename... elements_d> struct forward_tuple_extractor_a;
	template <typename... elements_d> struct forward_tuple_mutator_a;
	template <typename... elements_d> struct bidirectional_tuple_extractor_a;
	template <typename... elements_d> struct bidirectional_tuple_mutator_a;
	template <typename... elements_d> struct random_access_tuple_extractor_a;
	template <typename... elements_d> struct random_access_tuple_mutator_a;
	template <typename... elements_d> struct contiguous_tuple_extractor_a;
	template <typename... elements_d> struct contiguous_tuple_mutator_a;

	template <typename element_d = var<>> struct range_a;
	template <typename element_d = var<>> struct mutator_range_a;
	template <typename element_d = var<>> struct bidirectional_range_a;
	template <typename element_d = var<>> struct bidirectional_mutator_range_a;
	template <typename element_d = var<>> struct random_access_range_a;
	template <typename element_d = var<>> struct random_access_mutator_range_a;
	template <typename... elements_d> struct tuple_range_a;
	template <typename... elements_d> struct tuple_mutator_range_a;
	template <typename... elements_d> struct bidirectional_tuple_range_a;
	template <typename... elements_d> struct bidirectional_tuple_mutator_range_a;

	template <typename... elements_d> struct tuple_a;
	template <typename key_d = var<>, typename value_d = var<>, typename element_d = var<>> struct collection_a;
	template <typename element_d = var<>> struct list_a;
	template <typename element_d = var<>> struct group_a;
	template <typename key_d = var<>, typename value_d = var<>> struct table_a;

	struct thing_t;
	struct symbol_t;
	template <typename type_d> struct data_t;
	template <typename type_d> struct data_pointer_t;
}

#include "utilities/strange__val_u.hpp"

#include "fundamentals/enumerations/strange__representation_e.h"
#include "fundamentals/enumerations/strange__behaviour_e.h"

#include "fundamentals/abstractions/strange__any_a.h"
#include "fundamentals/abstractions/strange__symbol_a.h"
#include "fundamentals/abstractions/strange__cat_a.h"
#include "fundamentals/abstractions/strange__kind_a.h"
#include "fundamentals/abstractions/strange__data_a.h"
#include "fundamentals/abstractions/strange__lock_a.h"
#include "fundamentals/abstractions/strange__unlock_a.h"

#include "collections/iterators/abstractions/strange__forward_extractor_a.h"
#include "collections/iterators/abstractions/strange__forward_mutator_a.h"
#include "collections/iterators/abstractions/strange__bidirectional_extractor_a.h"
#include "collections/iterators/abstractions/strange__bidirectional_mutator_a.h"
#include "collections/iterators/abstractions/strange__random_access_extractor_a.h"
#include "collections/iterators/abstractions/strange__random_access_mutator_a.h"
#include "collections/iterators/abstractions/strange__contiguous_extractor_a.h"
#include "collections/iterators/abstractions/strange__contiguous_mutator_a.h"
#include "collections/iterators/abstractions/strange__forward_tuple_extractor_a.h"
#include "collections/iterators/abstractions/strange__forward_tuple_mutator_a.h"
#include "collections/iterators/abstractions/strange__bidirectional_tuple_extractor_a.h"
#include "collections/iterators/abstractions/strange__bidirectional_tuple_mutator_a.h"
#include "collections/iterators/abstractions/strange__random_access_tuple_extractor_a.h"
#include "collections/iterators/abstractions/strange__random_access_tuple_mutator_a.h"
#include "collections/iterators/abstractions/strange__contiguous_tuple_extractor_a.h"
#include "collections/iterators/abstractions/strange__contiguous_tuple_mutator_a.h"

#include "collections/ranges/abstractions/strange__range_a.h"
#include "collections/ranges/abstractions/strange__mutator_range_a.h"
#include "collections/ranges/abstractions/strange__bidirectional_range_a.h"
#include "collections/ranges/abstractions/strange__bidirectional_mutator_range_a.h"
#include "collections/ranges/abstractions/strange__random_access_range_a.h"
#include "collections/ranges/abstractions/strange__random_access_mutator_range_a.h"
#include "collections/ranges/abstractions/strange__tuple_range_a.h"
#include "collections/ranges/abstractions/strange__tuple_mutator_range_a.h"
#include "collections/ranges/abstractions/strange__bidirectional_tuple_range_a.h"
#include "collections/ranges/abstractions/strange__bidirectional_tuple_mutator_range_a.h"

#include "collections/abstractions/strange__tuple_a.h"
#include "collections/abstractions/strange__collection_a.h"
#include "collections/abstractions/strange__list_a.h"
#include "collections/abstractions/strange__group_a.h"
#include "collections/abstractions/strange__table_a.h"

#include "fundamentals/things/strange__thing_t.h"
#include "fundamentals/things/strange__symbol_t.h"
#include "fundamentals/things/strange__data_t.h"

#endif
