#ifndef COM_ONEISH_STRANGE_COLLECTION_O_H
#define COM_ONEISH_STRANGE_COLLECTION_O_H

namespace strange
{

template <typename _OVERRIDDEN_>
class collection_o : public thing_o<_OVERRIDDEN_>
{
public:
	inline collection_o(_OVERRIDDEN_&& overridden)
		: thing_o<_OVERRIDDEN_>{ std::move(overridden) }
	{}

	inline any_a<> has_(any_a<> const& key) const
	{
		return boole(_OVERRIDDEN_::has(key));
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value = no())
	{
		_OVERRIDDEN_::update(key, value);
		return value;
	}

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value = no())
	{
		return boole(_OVERRIDDEN_::insert(key, value));
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		return boole(_OVERRIDDEN_::erase(key));
	}

	inline collection_a<> clear_()
	{
		_OVERRIDDEN_::clear();
		return _OVERRIDDEN_::me_();
	}

	inline number_data_a<int64_t> size_() const
	{
		return num(_OVERRIDDEN_::size());
	}

	inline any_a<> empty_() const
	{
		return boole(_OVERRIDDEN_::empty());
	}

	inline collection_a<> push_front_(any_a<> const& value)
	{
		_OVERRIDDEN_::push_front(value);
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> push_back_(any_a<> const& value)
	{
		_OVERRIDDEN_::push_back(value);
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> self_add_(range_a<> const& range)
	{
		_OVERRIDDEN_::operator+=(range);
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> add_(range_a<> const& range) const
	{
		return operator+(range);
	}

	inline collection_a<> operator+(range_a<> const& range) const
	{
		auto result = _OVERRIDDEN_::me_();
		result += range;
		return result;
	}

	inline collection_a<> self_subtract_(range_a<> const& range)
	{
		_OVERRIDDEN_::operator-=(range);
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> subtract_(range_a<> const& range) const
	{
		return operator-(range);
	}

	inline collection_a<> operator-(range_a<> const& range) const
	{
		auto result = _OVERRIDDEN_::me_();
		result -= range;
		return result;
	}
};

} // namespace strange

#endif
