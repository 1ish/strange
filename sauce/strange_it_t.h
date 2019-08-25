#ifndef COM_ONEISH_STRANGE_IT_T_H
#define COM_ONEISH_STRANGE_IT_T_H

namespace strange
{

template <bool _const_ = false, typename _end_ = nothing_t<>, typename ___ego___ = forward_const_iterator_a<>>
class it_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<it_t<_const_, _end_>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline forward_const_iterator_a<> val_()
	{
		static forward_const_iterator_a<> VAL = it_t<_const_, _end_>::val_(_end_::val_());
		return VAL;
	}

	static inline forward_const_iterator_a<> val_(any_a<> const& thing)
	{
		return forward_const_iterator_a<>{ over{ it_t<_const_, _end_>{ thing } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<it_t<_const_>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<it_t<_const_>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<forward_const_iterator_a<>>(thing))
		{
			return false;
		}
		return _thing.nothing() == cast<forward_const_iterator_a<>>(thing)->nothing();
	}

	inline std::size_t hash() const
	{
		return _thing.hash();
	}

	// forward iterator
	inline any_a<> get__(range_a<> const&) const
	{
		return get_();
	}
	
	inline any_a<> get_() const
	{
		return _thing;
	}

	inline any_a<> const* operator->() const
	{
		return &operator*();
	}

	inline any_a<> const& operator*() const
	{
		return _thing;
	}

	inline ___ego___ increment__(range_a<> const&)
	{
		return increment_();
	}

	inline ___ego___ increment_()
	{
		operator++();
		return me_();
	}

	inline it_t& operator++()
	{
		_thing = _end_::val_();
		return *this;
	}

	inline it_t operator++(int)
	{
		it_t result = *this;
		operator++();
		return result;
	}

protected:
	mutable any_a<> _thing; //TODO A forward iterator cannot be "stashing": it cannot return a reference to an object within itself, because such references would be invalidated by the destruction of the forward iterator.

	inline it_t(any_a<> const& thing)
		: thing_t{}
		, _thing(thing, !_const_)
	{}

private:
	static bool const ___share___;
	friend class ___it_t_share___;
};

template <bool _const_, typename _end_, typename ___ego___>
bool const it_t<_const_, _end_, ___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	it_t<_const_, _end_, ___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
