#ifndef COM_ONEISH_STRANGE_RANGES_H
#define COM_ONEISH_STRANGE_RANGES_H

// ranges

namespace strange
{
	inline forward_extractor_a<> begin(range_a<> const& range)
	{
		return range.extract_begin_();
	}

	inline forward_extractor_a<> end(range_a<> const& range)
	{
		return range.extract_end_();
	}

	inline forward_extractor_a<> begin(shoal_a<> const& shoal)
	{
		return shoal.extract_begin_();
	}

	inline forward_extractor_a<> end(shoal_a<> const& shoal)
	{
		return shoal.extract_end_();
	}

	inline forward_mutator_a<> begin(shoal_a<>& shoal)
	{
		return shoal.mutate_begin_();
	}

	inline forward_mutator_a<> end(shoal_a<>& shoal)
	{
		return shoal.mutate_end_();
	}

	inline forward_extractor_a<> begin(inventory_a<> const& inventory)
	{
		return inventory.extract_begin_();
	}

	inline forward_extractor_a<> end(inventory_a<> const& inventory)
	{
		return inventory.extract_end_();
	}

	inline random_access_mutator_a<> begin(inventory_a<>& inventory)
	{
		return inventory.mutate_begin_();
	}

	inline random_access_mutator_a<> end(inventory_a<>& inventory)
	{
		return inventory.mutate_end_();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<typename std::deque<_primitive_>::const_iterator> begin(brook_a<_primitive_> const& brook)
	{
		return brook.extract_begin();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<typename std::deque<_primitive_>::const_iterator> end(brook_a<_primitive_> const& brook)
	{
		return brook.extract_end();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<typename std::deque<_primitive_>::iterator> begin(brook_a<_primitive_>& brook)
	{
		return brook.mutate_begin();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<typename std::deque<_primitive_>::iterator> end(brook_a<_primitive_>& brook)
	{
		return brook.mutate_end();
	}

	inline random_access_extractor_data_a<typename std::vector<any_a<>>::const_iterator> begin(flock_a<> const& flock)
	{
		return flock.extract_begin();
	}

	inline random_access_extractor_data_a<typename std::vector<any_a<>>::const_iterator> end(flock_a<> const& flock)
	{
		return flock.extract_end();
	}

	inline random_access_mutator_data_a<typename std::vector<any_a<>>::iterator> begin(flock_a<>& flock)
	{
		return flock.mutate_begin();
	}

	inline random_access_mutator_data_a<typename std::vector<any_a<>>::iterator> end(flock_a<>& flock)
	{
		return flock.mutate_end();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<typename std::vector<_primitive_>::const_iterator> begin(lake_a<_primitive_> const& lake)
	{
		return lake.extract_begin();
	}

	template <typename _primitive_>
	inline random_access_extractor_data_a<typename std::vector<_primitive_>::const_iterator> end(lake_a<_primitive_> const& lake)
	{
		return lake.extract_end();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<typename std::vector<_primitive_>::iterator> begin(lake_a<_primitive_>& lake)
	{
		return lake.mutate_begin();
	}

	template <typename _primitive_>
	inline random_access_mutator_data_a<typename std::vector<_primitive_>::iterator> end(lake_a<_primitive_>& lake)
	{
		return lake.mutate_end();
	}

	inline bidirectional_extractor_data_a<typename std::set<any_a<>>::const_iterator> begin(ordered_herd_a<> const& herd)
	{
		return herd.extract_begin();
	}

	inline bidirectional_extractor_data_a<typename std::set<any_a<>>::const_iterator> end(ordered_herd_a<> const& herd)
	{
		return herd.extract_end();
	}
}

#endif
