#ifndef COM_ONEISH_STRANGE_THING_O_H
#define COM_ONEISH_STRANGE_THING_O_H

namespace strange
{

template <typename _OVERRIDDEN_, typename _unordered_shoal_ = unordered_shoal_t<>, typename _number_uint64_ = number_t<uint64_t>>
class thing_o : public _OVERRIDDEN_
{
public:
	inline thing_o(_OVERRIDDEN_&& overridden)
		: _OVERRIDDEN_{ std::move(overridden) }
	{}

	inline any_a<> type__(range_a<> const&) const
	{
		return _OVERRIDDEN_::type_();
	}

	inline any_a<> shared__(range_a<> const&) const
	{
		return shared_();
	}

	inline unordered_shoal_a<> shared_() const
	{
		unordered_shoal_a<> shoal = _unordered_shoal_::create_();
		_OVERRIDDEN_::share(shoal);
		return shoal;
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
		return boole(_OVERRIDDEN_::operator==(thing));
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
		return !_OVERRIDDEN_::operator==(thing);
	}

	inline any_a<> hash__(range_a<> const&) const
	{
		return hash_();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return _number_uint64_::create(uint64_t(_OVERRIDDEN_::hash()));
	}
};

} // namespace strange

#endif
