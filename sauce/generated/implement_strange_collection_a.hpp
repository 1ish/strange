
namespace strange
{

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::has__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::has_ passed short range");
	}
	auto key = cast< _key >(*___it___);
	return has_(key);
}

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::has_(_key const& key) const
{ assert(any_a<>::___handle___); return ___read___().has_(key); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::has_(_key const& key) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.has_(key); }

template <typename _key, typename _value, typename _element>
inline bool collection_a<_key, _value, _element>::has(_key const & key ) const
{ assert(any_a<>::___handle___); return ___read___().has(key); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::has(_key const & key ) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.has(key); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::at__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::at_ passed short range");
	}
	auto key = cast< _key >(*___it___);
	return at_(key);
}

template <typename _key, typename _value, typename _element>
inline _value collection_a<_key, _value, _element>::at_(_key const& key) const
{ assert(any_a<>::___handle___); return ___read___().at_(key); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _value collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::at_(_key const& key) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.at_(key); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::update__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::update_ passed short range");
	}
	auto key = cast< _key >(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::update_ passed short range");
	}
	auto value = cast< _value >(*___it___);
	return update_(key, value);
}

template <typename _key, typename _value, typename _element>
inline _value collection_a<_key, _value, _element>::update_(_key const& key, _value const& value)
{ assert(any_a<>::___handle___); return ___write___().update_(key, value); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _value collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::update_(_key const& key, _value const& value)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update_(key, value); }

template <typename _key, typename _value, typename _element>
inline void collection_a<_key, _value, _element>::update(_key const & key , _value const & value )
{ assert(any_a<>::___handle___); ___write___().update(key, value); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::update(_key const & key , _value const & value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.update(key, value); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::insert__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::insert_ passed short range");
	}
	auto key = cast< _key >(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::insert_ passed short range");
	}
	auto value = cast< _value >(*___it___);
	return insert_(key, value);
}

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::insert_(_key const& key, _value const& value)
{ assert(any_a<>::___handle___); return ___write___().insert_(key, value); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::insert_(_key const& key, _value const& value)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert_(key, value); }

template <typename _key, typename _value, typename _element>
inline bool collection_a<_key, _value, _element>::insert(_key const & key , _value const & value )
{ assert(any_a<>::___handle___); return ___write___().insert(key, value); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::insert(_key const & key , _value const & value )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.insert(key, value); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::erase__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::erase_ passed short range");
	}
	auto key = cast< _key >(*___it___);
	return erase_(key);
}

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::erase_(_key const& key)
{ assert(any_a<>::___handle___); return ___write___().erase_(key); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::erase_(_key const& key)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase_(key); }

template <typename _key, typename _value, typename _element>
inline bool collection_a<_key, _value, _element>::erase(_key const & key )
{ assert(any_a<>::___handle___); return ___write___().erase(key); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::erase(_key const & key )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.erase(key); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::clear__(range_a<> const& ___arguments___)
{
	return clear_();
}

template <typename _key, typename _value, typename _element>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::clear_()
{ assert(any_a<>::___handle___); return ___write___().clear_(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::clear_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.clear_(); }

template <typename _key, typename _value, typename _element>
inline void collection_a<_key, _value, _element>::clear()
{ assert(any_a<>::___handle___); ___write___().clear(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::clear()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.clear(); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::size__(range_a<> const& ___arguments___) const
{
	return size_();
}

template <typename _key, typename _value, typename _element>
inline number_data_int64_a<> collection_a<_key, _value, _element>::size_() const
{ assert(any_a<>::___handle___); return ___read___().size_(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::size_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.size_(); }

template <typename _key, typename _value, typename _element>
inline int64_t collection_a<_key, _value, _element>::size() const
{ assert(any_a<>::___handle___); return ___read___().size(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline int64_t collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::size() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.size(); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::empty__(range_a<> const& ___arguments___) const
{
	return empty_();
}

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::empty_() const
{ assert(any_a<>::___handle___); return ___read___().empty_(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::empty_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.empty_(); }

template <typename _key, typename _value, typename _element>
inline bool collection_a<_key, _value, _element>::empty() const
{ assert(any_a<>::___handle___); return ___read___().empty(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline bool collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::empty() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.empty(); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::push_front__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::push_front_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return push_front_(thing);
}

template <typename _key, typename _value, typename _element>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::push_front_(_element const& thing)
{ assert(any_a<>::___handle___); return ___write___().push_front_(thing); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::push_front_(_element const& thing)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.push_front_(thing); }

template <typename _key, typename _value, typename _element>
inline void collection_a<_key, _value, _element>::push_front(_element const & thing )
{ assert(any_a<>::___handle___); ___write___().push_front(thing); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::push_front(_element const & thing )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.push_front(thing); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::pop_front__(range_a<> const& ___arguments___)
{
	return pop_front_();
}

template <typename _key, typename _value, typename _element>
inline _element collection_a<_key, _value, _element>::pop_front_()
{ assert(any_a<>::___handle___); return ___write___().pop_front_(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::pop_front_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.pop_front_(); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::push_back__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::push_back_ passed short range");
	}
	auto thing = cast< _element >(*___it___);
	return push_back_(thing);
}

template <typename _key, typename _value, typename _element>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::push_back_(_element const& thing)
{ assert(any_a<>::___handle___); return ___write___().push_back_(thing); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::push_back_(_element const& thing)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.push_back_(thing); }

template <typename _key, typename _value, typename _element>
inline void collection_a<_key, _value, _element>::push_back(_element const & thing )
{ assert(any_a<>::___handle___); ___write___().push_back(thing); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::push_back(_element const & thing )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.push_back(thing); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::pop_back__(range_a<> const& ___arguments___)
{
	return pop_back_();
}

template <typename _key, typename _value, typename _element>
inline _element collection_a<_key, _value, _element>::pop_back_()
{ assert(any_a<>::___handle___); return ___write___().pop_back_(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline _element collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::pop_back_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.pop_back_(); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::self_assign__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::self_assign_ passed short range");
	}
	auto range = cast< range_a< _element > >(*___it___);
	return self_assign_(range);
}

template <typename _key, typename _value, typename _element>
inline collection_a<_key, _value, _element> collection_a<_key, _value, _element>::self_assign_(range_a< _element > const& range)
{
	assert(any_a<>::___handle___);
	___write___().self_assign_(range);
	return *this;
}

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::self_assign_(range_a< _element > const& range)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_assign_(range); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::self_add__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::self_add_ passed short range");
	}
	auto range = cast< range_a< _element > >(*___it___);
	return self_add_(range);
}

template <typename _key, typename _value, typename _element>
inline collection_a<_key, _value, _element> collection_a<_key, _value, _element>::self_add_(range_a< _element > const& range)
{
	assert(any_a<>::___handle___);
	___write___().self_add_(range);
	return *this;
}

template <typename _key, typename _value, typename _element>
inline collection_a<_key, _value, _element>& collection_a<_key, _value, _element>::operator+=(range_a< _element > const& range)
{
	assert(any_a<>::___handle___);
	___write___().self_add_(range);
	return *this;
}

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::self_add_(range_a< _element > const& range)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_add_(range); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::add__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::add_ passed short range");
	}
	auto range = cast< range_a< _element > >(*___it___);
	return add_(range);
}

template <typename _key, typename _value, typename _element>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::add_(range_a< _element > const& range) const
{ assert(any_a<>::___handle___); return ___read___().add_(range); }

template <typename _key, typename _value, typename _element>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::operator+(range_a< _element > const& range) const
{ assert(any_a<>::___handle___); return ___read___().add_(range); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::add_(range_a< _element > const& range) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(range); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::self_subtract__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::self_subtract_ passed short range");
	}
	auto range = cast< range_a< _element > >(*___it___);
	return self_subtract_(range);
}

template <typename _key, typename _value, typename _element>
inline collection_a<_key, _value, _element> collection_a<_key, _value, _element>::self_subtract_(range_a< _element > const& range)
{
	assert(any_a<>::___handle___);
	___write___().self_subtract_(range);
	return *this;
}

template <typename _key, typename _value, typename _element>
inline collection_a<_key, _value, _element>& collection_a<_key, _value, _element>::operator-=(range_a< _element > const& range)
{
	assert(any_a<>::___handle___);
	___write___().self_subtract_(range);
	return *this;
}

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline void collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::self_subtract_(range_a< _element > const& range)
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.self_subtract_(range); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::subtract__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::subtract_ passed short range");
	}
	auto range = cast< range_a< _element > >(*___it___);
	return subtract_(range);
}

template <typename _key, typename _value, typename _element>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::subtract_(range_a< _element > const& range) const
{ assert(any_a<>::___handle___); return ___read___().subtract_(range); }

template <typename _key, typename _value, typename _element>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::operator-(range_a< _element > const& range) const
{ assert(any_a<>::___handle___); return ___read___().subtract_(range); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline collection_a< _key , _value , _element > collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::subtract_(range_a< _element > const& range) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.subtract_(range); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::read_lock__(range_a<> const& ___arguments___) const
{
	return read_lock_();
}

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::read_lock_() const
{ assert(any_a<>::___handle___); return ___read___().read_lock_(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::read_lock_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.read_lock_(); }

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::write_lock__(range_a<> const& ___arguments___) const
{
	return write_lock_();
}

template <typename _key, typename _value, typename _element>
inline any_a<> collection_a<_key, _value, _element>::write_lock_() const
{ assert(any_a<>::___handle___); return ___read___().write_lock_(); }

template <typename _key, typename _value, typename _element>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> collection_a<_key, _value, _element>::___collection_a_handle___<___TTT___, ___DHB___>::write_lock_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.write_lock_(); }

class ___collection_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___collection_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _key, typename _value, typename _element>
inline collection_d<_key, _value, _element> ___collection_dynamic___(any_a<> const& thing)
{
	return collection_d<_key, _value, _element>{ thing };
}

} // namespace
