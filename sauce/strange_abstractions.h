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
	template <>
	inline kind_a<> kind_of<std::set<any_a<>>::const_iterator>();
	template <>
	inline kind_a<> kind_of<std::map<any_a<>, any_a<>>::const_iterator>();
	template <>
	inline kind_a<> kind_of<std::map<any_a<>, any_a<>>::iterator>();
	template <>
	inline kind_a<> kind_of<std::unordered_set<any_a<>>::const_iterator>();
	template <>
	inline kind_a<> kind_of<std::unordered_map<any_a<>, any_a<>>::const_iterator>();
	template <>
	inline kind_a<> kind_of<std::unordered_map<any_a<>, any_a<>>::iterator>();
	template <>
	inline kind_a<> kind_of<std::vector<any_a<>>::const_iterator>();
	template <>
	inline kind_a<> kind_of<std::deque<any_a<>>::const_iterator>();
	template <>
	inline kind_a<> kind_of<std::vector<any_a<>>::iterator>();
	template <>
	inline kind_a<> kind_of<std::deque<any_a<>>::iterator>();
}

#include "generated/define_strange_misunderstanding_a.hpp"
#include "generated/define_strange_forward_extractor_a.hpp"
#include "generated/define_strange_forward_extractor_data_a.hpp"
#include "generated/define_strange_forward_mutator_a.hpp"
#include "generated/define_strange_forward_mutator_data_a.hpp"
#include "generated/define_strange_bidirectional_extractor_a.hpp"
#include "generated/define_strange_bidirectional_extractor_data_a.hpp"
#include "generated/define_strange_bidirectional_mutator_a.hpp"
#include "generated/define_strange_bidirectional_mutator_data_a.hpp"
#include "generated/define_strange_random_access_extractor_a.hpp"
#include "generated/define_strange_random_access_extractor_data_a.hpp"
#include "generated/define_strange_random_access_mutator_a.hpp"
#include "generated/define_strange_random_access_mutator_data_a.hpp"
#include "generated/define_strange_range_a.hpp"
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
#include "generated/define_strange_parcel_a.hpp"
namespace strange
{
	inline std::size_t hash_of(parcel_a<> const& thing)
	{
		return thing.hash();
	}
}
#include "generated/define_strange_cat_a.hpp"
#include "generated/define_strange_kind_a.hpp"
#include "generated/define_strange_token_a.hpp"
#include "generated/define_strange_operation_a.hpp"
#include "generated/define_strange_expression_a.hpp"
#include "generated/define_strange_parser_a.hpp"

#include "generated/implement_strange_any_a.hpp"
#include "generated/implement_strange_misunderstanding_a.hpp"
#include "generated/implement_strange_range_a.hpp"
#include "generated/implement_strange_data_a.hpp"
#include "generated/implement_strange_number_a.hpp"
#include "generated/implement_strange_number_data_a.hpp"
#include "generated/implement_strange_river_a.hpp"
#include "generated/implement_strange_symbol_a.hpp"
#include "generated/implement_strange_cat_a.hpp"
#include "generated/implement_strange_kind_a.hpp"
#include "generated/implement_strange_token_a.hpp"
#include "generated/implement_strange_operation_a.hpp"
#include "generated/implement_strange_expression_a.hpp"
#include "generated/implement_strange_parser_a.hpp"
#include "generated/implement_strange_collection_a.hpp"
#include "generated/implement_strange_inventory_a.hpp"
#include "generated/implement_strange_lake_a.hpp"
#include "generated/implement_strange_shoal_a.hpp"
#include "generated/implement_strange_ordered_shoal_a.hpp"
#include "generated/implement_strange_unordered_shoal_a.hpp"
#include "generated/implement_strange_parcel_a.hpp"
#include "generated/implement_strange_herd_a.hpp"
#include "generated/implement_strange_ordered_herd_a.hpp"
#include "generated/implement_strange_unordered_herd_a.hpp"
#include "generated/implement_strange_flock_a.hpp"
#include "generated/implement_strange_squad_a.hpp"
#include "generated/implement_strange_brook_a.hpp"
#include "generated/implement_strange_forward_extractor_a.hpp"
#include "generated/implement_strange_forward_extractor_data_a.hpp"
#include "generated/implement_strange_forward_mutator_a.hpp"
#include "generated/implement_strange_forward_mutator_data_a.hpp"
#include "generated/implement_strange_bidirectional_extractor_a.hpp"
#include "generated/implement_strange_bidirectional_extractor_data_a.hpp"
#include "generated/implement_strange_bidirectional_mutator_a.hpp"
#include "generated/implement_strange_bidirectional_mutator_data_a.hpp"
#include "generated/implement_strange_random_access_extractor_a.hpp"
#include "generated/implement_strange_random_access_extractor_data_a.hpp"
#include "generated/implement_strange_random_access_mutator_a.hpp"
#include "generated/implement_strange_random_access_mutator_data_a.hpp"
#endif
