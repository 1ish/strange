#ifndef COM_ONEISH_STRANGE_RANGES_H
#define COM_ONEISH_STRANGE_RANGES_H

// ranges

namespace strange
{
	template <typename _element>
	inline forward_extractor_a<_element> begin(range_a<_element> const& range)
	{
		return range.extract_begin_();
	}

	template <typename _element>
	inline forward_extractor_a<_element> end(range_a<_element> const& range)
	{
		return range.extract_end_();
	}

	template <typename _key, typename _value>
	inline forward_extractor_a<any_a<>> begin(shoal_a<_key, _value> const& shoal)
	{
		return shoal.extract_begin_();
	}

	template <typename _key, typename _value>
	inline forward_extractor_a<any_a<>> end(shoal_a<_key, _value> const& shoal)
	{
		return shoal.extract_end_();
	}

	template <typename _key, typename _value>
	inline forward_mutator_a<any_a<>> begin(shoal_a<_key, _value>& shoal)
	{
		return shoal.mutate_begin_();
	}

	template <typename _key, typename _value>
	inline forward_mutator_a<any_a<>> end(shoal_a<_key, _value>& shoal)
	{
		return shoal.mutate_end_();
	}

	template <typename _element>
	inline forward_extractor_a<_element> begin(inventory_a<_element> const& inventory)
	{
		return inventory.extract_begin_();
	}

	template <typename _element>
	inline forward_extractor_a<_element> end(inventory_a<_element> const& inventory)
	{
		return inventory.extract_end_();
	}

	template <typename _element>
	inline random_access_mutator_a<_element> begin(inventory_a<_element>& inventory)
	{
		return inventory.mutate_begin_();
	}

	template <typename _element>
	inline random_access_mutator_a<_element> end(inventory_a<_element>& inventory)
	{
		return inventory.mutate_end_();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<number_data_a<int64_t>, typename std::deque<_primitive_>::const_iterator> begin(brook_a<_primitive_> const& brook)
	{
		return brook.extract_begin();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<number_data_a<int64_t>, typename std::deque<_primitive_>::const_iterator> end(brook_a<_primitive_> const& brook)
	{
		return brook.extract_end();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<number_data_a<int64_t>, typename std::deque<_primitive_>::iterator> begin(brook_a<_primitive_>& brook)
	{
		return brook.mutate_begin();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<number_data_a<int64_t>, typename std::deque<_primitive_>::iterator> end(brook_a<_primitive_>& brook)
	{
		return brook.mutate_end();
	}

	template <typename _element>
	inline random_access_extractor_data_a<_element, typename std::vector<_element>::const_iterator> begin(flock_a<_element> const& flock)
	{
		return flock.extract_begin();
	}

	template <typename _element>
	inline random_access_extractor_data_a<_element, typename std::vector<_element>::const_iterator> end(flock_a<_element> const& flock)
	{
		return flock.extract_end();
	}

	template <typename _element>
	inline random_access_mutator_data_a<_element, typename std::vector<_element>::iterator> begin(flock_a<_element>& flock)
	{
		return flock.mutate_begin();
	}

	template <typename _element>
	inline random_access_mutator_data_a<_element, typename std::vector<_element>::iterator> end(flock_a<_element>& flock)
	{
		return flock.mutate_end();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<number_data_a<_primitive_>, typename std::vector<_primitive_>::const_iterator> begin(lake_a<_primitive_> const& lake)
	{
		return lake.extract_begin();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<number_data_a<_primitive_>, typename std::vector<_primitive_>::const_iterator> end(lake_a<_primitive_> const& lake)
	{
		return lake.extract_end();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<number_data_a<_primitive_>, typename std::vector<_primitive_>::iterator> begin(lake_a<_primitive_>& lake)
	{
		return lake.mutate_begin();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<number_data_a<_primitive_>, typename std::vector<_primitive_>::iterator> end(lake_a<_primitive_>& lake)
	{
		return lake.mutate_end();
	}

	template <typename _element>
	inline bidirectional_extractor_data_a<_element, typename std::set<_element>::const_iterator> begin(ordered_herd_a<_element> const& herd)
	{
		return herd.extract_begin();
	}

	template <typename _element>
	inline bidirectional_extractor_data_a<_element, typename std::set<_element>::const_iterator> end(ordered_herd_a<_element> const& herd)
	{
		return herd.extract_end();
	}

	inline bidirectional_extractor_data_a<any_a<>, typename std::map<any_a<>, any_a<>>::const_iterator> begin(ordered_shoal_a<> const& shoal)
	{
		return shoal.extract_begin();
	}

	inline bidirectional_extractor_data_a<any_a<>, typename std::map<any_a<>, any_a<>>::const_iterator> end(ordered_shoal_a<> const& shoal)
	{
		return shoal.extract_end();
	}

	inline bidirectional_mutator_data_a<any_a<>, typename std::map<any_a<>, any_a<>>::iterator> begin(ordered_shoal_a<>& shoal)
	{
		return shoal.mutate_begin();
	}

	inline bidirectional_mutator_data_a<any_a<>, typename std::map<any_a<>, any_a<>>::iterator> end(ordered_shoal_a<>& shoal)
	{
		return shoal.mutate_end();
	}

	inline random_access_extractor_data_a<any_a<>, typename std::deque<any_a<>>::const_iterator> begin(squad_a<> const& squad)
	{
		return squad.extract_begin();
	}

	inline random_access_extractor_data_a<any_a<>, typename std::deque<any_a<>>::const_iterator> end(squad_a<> const& squad)
	{
		return squad.extract_end();
	}

	inline random_access_mutator_data_a<any_a<>, typename std::deque<any_a<>>::iterator> begin(squad_a<>& squad)
	{
		return squad.mutate_begin();
	}

	inline random_access_mutator_data_a<any_a<>, typename std::deque<any_a<>>::iterator> end(squad_a<>& squad)
	{
		return squad.mutate_end();
	}

	template <typename _element>
	inline forward_extractor_data_a<_element, typename std::unordered_set<_element>::const_iterator> begin(unordered_herd_a<_element> const& herd)
	{
		return herd.extract_begin();
	}

	template <typename _element>
	inline forward_extractor_data_a<_element, typename std::unordered_set<_element>::const_iterator> end(unordered_herd_a<_element> const& herd)
	{
		return herd.extract_end();
	}

	inline forward_extractor_data_a<any_a<>, typename std::unordered_map<any_a<>, any_a<>>::const_iterator> begin(unordered_shoal_a<> const& shoal)
	{
		return shoal.extract_begin();
	}

	inline forward_extractor_data_a<any_a<>, typename std::unordered_map<any_a<>, any_a<>>::const_iterator> end(unordered_shoal_a<> const& shoal)
	{
		return shoal.extract_end();
	}

	inline forward_mutator_data_a<any_a<>, typename std::unordered_map<any_a<>, any_a<>>::iterator> begin(unordered_shoal_a<>& shoal)
	{
		return shoal.mutate_begin();
	}

	inline forward_mutator_data_a<any_a<>, typename std::unordered_map<any_a<>, any_a<>>::iterator> end(unordered_shoal_a<>& shoal)
	{
		return shoal.mutate_end();
	}

	inline forward_extractor_data_a<any_a<>, std::istreambuf_iterator<char>> begin(river_a<> const& river)
	{
		return river.extract_begin();
	}

	inline forward_extractor_data_a<any_a<>, std::istreambuf_iterator<char>> end(river_a<> const& river)
	{
		return river.extract_end();
	}
}

#endif
