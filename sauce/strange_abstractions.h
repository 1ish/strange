#ifndef COM_ONEISH_STRANGE_ABSTRACTIONS_H
#define COM_ONEISH_STRANGE_ABSTRACTIONS_H

// abstractions
#include "generated/define_strange_any_a.hpp"

namespace strange
{
	inline std::size_t hash_of(any_a<> const& thing)
	{
		return thing.hash();
	}
}

#include "generated/define_strange_misunderstanding_a.hpp"
#include "generated/define_strange_forward_const_iterator_a.hpp"
#include "generated/define_strange_forward_const_iterator_data_a.hpp"
#include "generated/define_strange_forward_iterator_a.hpp"
#include "generated/define_strange_forward_iterator_data_a.hpp"
#include "generated/define_strange_bidirectional_const_iterator_a.hpp"
#include "generated/define_strange_bidirectional_const_iterator_data_a.hpp"
#include "generated/define_strange_bidirectional_iterator_a.hpp"
#include "generated/define_strange_bidirectional_iterator_data_a.hpp"
#include "generated/define_strange_random_access_const_iterator_a.hpp"
#include "generated/define_strange_random_access_const_iterator_data_a.hpp"
#include "generated/define_strange_random_access_iterator_a.hpp"
#include "generated/define_strange_random_access_iterator_data_a.hpp"
#include "generated/define_strange_range_a.hpp"
#include "generated/define_strange_range_of_a.hpp"
#include "generated/define_strange_data_a.hpp"
#include "generated/define_strange_number_a.hpp"
#include "generated/define_strange_number_data_a.hpp"
#include "generated/define_strange_collection_a.hpp"
#include "generated/define_strange_inventory_a.hpp"
#include "generated/define_strange_lake_a.hpp"
#include "generated/define_strange_symbol_a.hpp"
#include "generated/define_strange_shoal_a.hpp"
#include "generated/define_strange_ordered_shoal_a.hpp"
#include "generated/define_strange_unordered_shoal_a.hpp"
#include "generated/define_strange_herd_a.hpp"
#include "generated/define_strange_ordered_herd_a.hpp"
#include "generated/define_strange_unordered_herd_a.hpp"
#include "generated/define_strange_flock_a.hpp"
#include "generated/define_strange_squad_a.hpp"
#include "generated/define_strange_brook_a.hpp"
#include "generated/define_strange_river_a.hpp"
#include "generated/define_strange_cat_a.hpp"
#include "generated/define_strange_kind_a.hpp"
#include "generated/define_strange_token_a.hpp"
#include "generated/define_strange_operation_a.hpp"
#include "generated/define_strange_expression_a.hpp"
#include "generated/define_strange_parser_a.hpp"

#endif
