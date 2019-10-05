#ifndef COM_ONEISH_STRANGE_THING_O_H
#define COM_ONEISH_STRANGE_THING_O_H

namespace strange
{

template <typename _OVERRIDDEN_>
class thing_o : public _OVERRIDDEN_
{
public:
	inline thing_o(_OVERRIDDEN_&& overridden)
		: _OVERRIDDEN_{ std::move(overridden) }
	{}

	inline any_a<> type__(range_a<> const&) const
	{
		return type_();
	}

	inline any_a<> shared__(range_a<> const&) const
	{
		return shared_();
	}

	inline unordered_shoal_a<> shared_() const
	{
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	inline any_a<> eater__(range_a<> const&) const
	{
		return eater_();
	}

	inline any_a<> same__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[thing] same passed empty range");
		}
		return same_(*it);
	}

	inline any_a<> same_(any_a<> const& thing) const
	{
		return boole(operator==(thing));
	}

	inline any_a<> different__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[thing] different passed empty range");
		}
		return different_(*it);
	}

	inline any_a<> different_(any_a<> const& thing) const
	{
		return boole(operator!=(thing));
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !operator==(thing);
	}

	inline any_a<> hash__(range_a<> const&) const
	{
		return hash_();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return number_uint_64_t<>::create(uint64_t(hash()));
	}

	inline any_a<> ranged__(range_a<> const& _) const
	{
		return ranged_();
	}
};

} // namespace strange

#endif
