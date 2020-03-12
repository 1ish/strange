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
}

#endif
