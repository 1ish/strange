#ifndef COM_ONEISH_STRANGE_COLLECTION_O_H
#define COM_ONEISH_STRANGE_COLLECTION_O_H

namespace strange
{

template <typename _OVERRIDDEN_, typename _number_int64_ = number_t<int64_t>>
class collection_o : public range_o<_OVERRIDDEN_>
{
public:
	inline collection_o(_OVERRIDDEN_&& overridden)
		: range_o<_OVERRIDDEN_>{ std::move(overridden) }
	{}

	inline any_a<> has__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[collection] has passed empty range");
		}
		return has_(*it);
	}

	inline any_a<> has_(any_a<> const& key) const
	{
		return boole(_OVERRIDDEN_::has(key));
	}

	inline any_a<> at__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[collection] at passed empty range");
		}
		return _OVERRIDDEN_::at_(*it);
	}

	inline any_a<> update__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[collection] update passed empty range");
		}
		any_a<> key = *it;
		if (++it == range.cend_())
		{
			return update_(key);
		}
		return update_(key, *it);
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value = no())
	{
		_OVERRIDDEN_::update(key, value);
		return value;
	}

	inline any_a<> insert__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[collection] insert passed empty range");
		}
		any_a<> key = *it;
		if (++it == range.cend_())
		{
			return insert_(key);
		}
		return insert_(key, *it);
	}

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value = no())
	{
		return boole(_OVERRIDDEN_::insert(key, value));
	}

	inline any_a<> erase__(range_a<> const& range)
	{
		bool erased = false;
		for (auto const& key : range)
		{
			if (_OVERRIDDEN_::erase(key))
			{
				erased = true;
			}
		}
		return boole(erased);
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		return boole(_OVERRIDDEN_::erase(key));
	}

	inline any_a<> clear__(range_a<> const&)
	{
		return clear_();
	}

	inline collection_a<> clear_()
	{
		_OVERRIDDEN_::clear();
		return _OVERRIDDEN_::me_();
	}

	inline any_a<> size__(range_a<> const&) const
	{
		return size_();
	}

	inline number_data_a<int64_t> size_() const
	{
		return _number_int64_::create(_OVERRIDDEN_::size());
	}

	inline any_a<> empty__(range_a<> const&) const
	{
		return empty_();
	}

	inline any_a<> empty_() const
	{
		return boole(_OVERRIDDEN_::empty());
	}

	inline any_a<> push_front__(range_a<> const& range)
	{
		for (auto const& value : range)
		{
			_OVERRIDDEN_::push_front(value);
		}
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> push_front_(any_a<> const& value)
	{
		_OVERRIDDEN_::push_front(value);
		return _OVERRIDDEN_::me_();
	}

	inline any_a<> pop_front__(range_a<> const&)
	{
		return _OVERRIDDEN_::pop_front_();
	}

	inline any_a<> push_back__(range_a<> const& range)
	{
		for (auto const& value : range)
		{
			_OVERRIDDEN_::push_back(value);
		}
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> push_back_(any_a<> const& value)
	{
		_OVERRIDDEN_::push_back(value);
		return _OVERRIDDEN_::me_();
	}

	inline any_a<> pop_back__(range_a<> const&)
	{
		return _OVERRIDDEN_::pop_back_();
	}

	inline any_a<> self_assign__(range_a<> const& range)
	{
		return _OVERRIDDEN_::self_assign_(range);
	}
	
	inline any_a<> self_add__(range_a<> const& range)
	{
		for (auto const& rng : range)
		{
			_OVERRIDDEN_::operator+=(rng);
		}
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> self_add_(range_a<> const& range)
	{
		_OVERRIDDEN_::operator+=(range);
		return _OVERRIDDEN_::me_();
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		auto result = _OVERRIDDEN_::me_();
		for (auto const& rng : range)
		{
			result += rng;
		}
		return result;
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

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		for (auto const& rng : range)
		{
			_OVERRIDDEN_::operator-=(rng);
		}
		return _OVERRIDDEN_::me_();
	}

	inline collection_a<> self_subtract_(range_a<> const& range)
	{
		_OVERRIDDEN_::operator-=(range);
		return _OVERRIDDEN_::me_();
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		auto result = _OVERRIDDEN_::me_();
		for (auto const& rng : range)
		{
			result -= rng;
		}
		return result;
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

	inline any_a<> read_lock__(range_a<> const& _) const
	{
		return _OVERRIDDEN_::read_lock_();
	}

	inline any_a<> write_lock__(range_a<> const& _) const
	{
		return _OVERRIDDEN_::write_lock_();
	}
};

} // namespace strange

#endif
