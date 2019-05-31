#ifndef COM_ONEISH_STRANGE_RANGES_H
#define COM_ONEISH_STRANGE_RANGES_H

// ranges

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
}

#endif
