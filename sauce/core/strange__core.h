#ifndef COM_ONEISH__STRANGE__CORE_H
#define COM_ONEISH__STRANGE__CORE_H

#include <atomic>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <mutex>
#include <shared_mutex>

namespace strange
{
	struct any_a;
	struct symbol_a;
	struct cat_a;
	struct kind_a;
	template <typename type_d> struct data_a;
	struct lock_a;
	struct unlock_a;

	template <typename element_d = any_a> struct forward_extractor_a;
	template <typename element_d = any_a> struct forward_mutator_a;
	template <typename element_d = any_a> struct bidirectional_extractor_a;
	template <typename element_d = any_a> struct bidirectional_mutator_a;
	template <typename element_d = any_a> struct random_access_extractor_a;
	template <typename element_d = any_a> struct random_access_mutator_a;

	template <typename element_d = any_a> struct range_a;
	template <typename element_d = any_a> struct mutator_range_a;
	template <typename element_d = any_a> struct bidirectional_range_a;
	template <typename element_d = any_a> struct bidirectional_mutator_range_a;
	template <typename element_d = any_a> struct random_access_range_a;
	template <typename element_d = any_a> struct random_access_mutator_range_a;

	template <typename... elements_d> struct tuple_a;
	template <typename key_d = any_a, typename value_d = any_a, typename element_d = any_a> struct collection_a;
	template <typename element_d = any_a> struct list_a;
	template <typename element_d = any_a> struct group_a;

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

#include "collections/ranges/abstractions/strange__range_a.h"
#include "collections/ranges/abstractions/strange__mutator_range_a.h"
#include "collections/ranges/abstractions/strange__bidirectional_range_a.h"
#include "collections/ranges/abstractions/strange__bidirectional_mutator_range_a.h"
#include "collections/ranges/abstractions/strange__random_access_range_a.h"
#include "collections/ranges/abstractions/strange__random_access_mutator_range_a.h"

#include "collections/abstractions/strange__tuple_a.h"
#include "collections/abstractions/strange__collection_a.h"
#include "collections/abstractions/strange__list_a.h"
#include "collections/abstractions/strange__group_a.h"

#include "fundamentals/things/strange__thing_t.h"
#include "fundamentals/things/strange__symbol_t.h"
#include "fundamentals/things/strange__data_t.h"

#endif
