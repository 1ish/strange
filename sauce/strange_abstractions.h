#ifndef COM_ONEISH_STRANGE_ABSTRACTIONS_H
#define COM_ONEISH_STRANGE_ABSTRACTIONS_H

// forward declarations

namespace strange
{

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

template <typename number_data_a_int8 = number_data_a<int8_t>, typename number_data_a_int64 = number_data_a<int64_t>, typename lake_a_int8 = lake_a<int8_t>>
class river_a;

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

template <typename _1_ = void>
class inventory_a;

template <typename _1_>
class lake_a;

template <typename _1_>
class brook_a;

template <typename _1_ = void>
class cat_a;

}

// abstractions

#include "strange_any_a.h"

#define ___root___ any_a<>
#include "strange_symbol_a.h"

#include "strange_forward_const_iterator_a.h"

#define ___derived___ forward_const_iterator_a<>
#include "strange_forward_const_iterator_data_a.h"

#include "strange_forward_iterator_a.h"

#define ___derived___ forward_iterator_a<>
#include "strange_forward_iterator_data_a.h"

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

#include "strange_misunderstanding_a.h"

#include "strange_range_a.h"

#define ___derived___ range_a<>
#include "strange_collection_a.h"

#define ___derived___ range_a<>
#include "strange_river_a.h"

#define ___derived___ collection_a<>
#include "strange_shoal_a.h"

#define ___derived___ shoal_a<>
#include "strange_ordered_shoal_a.h"

#define ___derived___ shoal_a<>
#include "strange_unordered_shoal_a.h"

#define ___derived___ collection_a<>
#include "strange_herd_a.h"

#define ___derived___ herd_a<>
#include "strange_ordered_herd_a.h"

#define ___derived___ herd_a<>
#include "strange_unordered_herd_a.h"

#include "strange_data_a.h"

#include "strange_number_a.h"

#define ___derived___ number_a<>
#include "strange_number_data_a.h"

#define ___derived___ collection_a<>
#include "strange_inventory_a.h"

#define ___derived___ inventory_a<>
#include "strange_flock_a.h"

#define ___derived___ inventory_a<>
#include "strange_squad_a.h"

#define ___derived___ inventory_a<>
#include "strange_lake_a.h"

#define ___derived___ inventory_a<>
#include "strange_brook_a.h"

#define ___derived___ symbol_a<>
#include "strange_cat_a.h"

namespace strange
{
	inline forward_const_iterator_a<> begin(range_a<> const& range)
	{
		return range.cbegin_();
	}

	inline forward_const_iterator_a<> end(range_a<> const& range)
	{
		return range.cend_();
	}

	inline forward_const_iterator_a<> begin(shoal_a<> const& shoal)
	{
		return shoal.cbegin_();
	}

	inline forward_const_iterator_a<> end(shoal_a<> const& shoal)
	{
		return shoal.cend_();
	}

	inline forward_iterator_a<> begin(shoal_a<>& shoal)
	{
		return shoal.begin_();
	}

	inline forward_iterator_a<> end(shoal_a<>& shoal)
	{
		return shoal.end_();
	}

	inline forward_const_iterator_a<> begin(inventory_a<> const& inventory)
	{
		return inventory.cbegin_();
	}

	inline forward_const_iterator_a<> end(inventory_a<> const& inventory)
	{
		return inventory.cend_();
	}

	inline random_access_iterator_a<> begin(inventory_a<>& inventory)
	{
		return inventory.begin_();
	}

	inline random_access_iterator_a<> end(inventory_a<>& inventory)
	{
		return inventory.end_();
	}
	/*
	inline forward_const_iterator_a<> begin(flock_a<> const& flock)
	{
		return flock.cbegin_();
	}

	inline forward_const_iterator_a<> end(flock_a<> const& flock)
	{
		return flock.cend_();
	}

	inline random_access_iterator_a<> begin(flock_a<>& flock)
	{
		return flock.begin_();
	}

	inline random_access_iterator_a<> end(flock_a<>& flock)
	{
		return flock.end_();
	}
	*/
}

#undef ___root___
#undef ___derived___

#endif
