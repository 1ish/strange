#ifndef COM_ONEISH_STRANGE_COLLECTION_O_H
#define COM_ONEISH_STRANGE_COLLECTION_O_H

namespace strange
{

template <typename _OVERRIDDEN_>
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
		return boole(has(key));
	}

	inline any_a<> at__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[collection] at passed empty range");
		}
		return at_(*it);
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
			return update_(key, key);
		}
		return update_(key, *it);
	}

	inline any_a<> update_(any_a<> const& key, any_a<> const& value)
	{
		update(key, value);
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
			return insert_(key, key);
		}
		return insert_(key, *it);
	}

	inline any_a<> insert_(any_a<> const& key, any_a<> const& value)
	{
		return boole(insert(key, value));
	}

	inline any_a<> erase__(range_a<> const& range)
	{
		bool erased = false;
		for (auto const& key : range)
		{
			if (erase(key))
			{
				erased = true;
			}
		}
		return boole(erased);
	}

	inline any_a<> erase_(any_a<> const& key)
	{
		return boole(erase(key));
	}

	inline any_a<> clear__(range_a<> const&)
	{
		return clear_();
	}

	inline collection_a<> clear_()
	{
		clear();
		return me_();
	}

	inline any_a<> size__(range_a<> const&) const
	{
		return size_();
	}

	inline number_data_a<int64_t> size_() const
	{
		return number_int_64_t<>::val(size());
	}

	inline any_a<> empty__(range_a<> const&) const
	{
		return empty_();
	}

	inline any_a<> empty_() const
	{
		return boole(empty());
	}

	inline any_a<> push_front__(range_a<> const& range)
	{
		for (auto const& value : range)
		{
			push_front(value);
		}
		return me_();
	}

	inline collection_a<> push_front_(any_a<> const& value)
	{
		push_front(value);
		return me_();
	}

	inline any_a<> pop_front__(range_a<> const&)
	{
		return pop_front_();
	}

	inline any_a<> push_back__(range_a<> const& range)
	{
		for (auto const& value : range)
		{
			push_back(value);
		}
		return me_();
	}

	inline collection_a<> push_back_(any_a<> const& value)
	{
		push_back(value);
		return me_();
	}

	inline any_a<> pop_back__(range_a<> const&)
	{
		return pop_back_();
	}

	inline any_a<> self_add__(range_a<> const& range)
	{
		for (auto const& rng : range)
		{
			operator+=(rng);
		}
		return me_();
	}

	inline collection_a<> self_add_(range_a<> const& range)
	{
		operator+=(range);
		return me_();
	}

	inline any_a<> add__(range_a<> const& range) const
	{
		auto result = me_();
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
		auto result = me_();
		result += range;
		return result;
	}

	inline any_a<> self_subtract__(range_a<> const& range)
	{
		for (auto const& rng : range)
		{
			operator-=(rng);
		}
		return me_();
	}

	inline collection_a<> self_subtract_(range_a<> const& range)
	{
		operator-=(range);
		return me_();
	}

	inline any_a<> subtract__(range_a<> const& range) const
	{
		auto result = me_();
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
		auto result = me_();
		result -= range;
		return result;
	}

	inline any_a<> read_lock__(range_a<> const& _) const
	{
		return read_lock_();
	}

	inline any_a<> write_lock__(range_a<> const& _) const
	{
		return write_lock_();
	}
/*
	inline any_a<> read_lock_() const
	{
		return data_t<read_lock_ptr<CONCURRENT>>::val(make_read_lock_ptr<CONCURRENT>(_mutex));
	}

	inline any_a<> write_lock_() const
	{
		return data_t<write_lock_ptr<CONCURRENT>>::val(make_write_lock_ptr<CONCURRENT>(_mutex));
	}
*/
};

} // namespace strange

#endif
