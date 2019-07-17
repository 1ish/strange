#ifndef COM_ONEISH_STRANGE_IT_T_H
#define COM_ONEISH_STRANGE_IT_T_H

namespace strange
{

template <bool CONST = false, typename END = nothing_t<>, typename _ABSTRACTION_ = forward_const_iterator_a<>>
class it_t : public thing_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<it_t<CONST, END>>;

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
		static forward_const_iterator_a<> VAL = val_(END::val_());
		return VAL;
	}

	static inline forward_const_iterator_a<> val_(any_a<> const& thing)
	{
		return forward_const_iterator_a<>{ over{ it_t<CONST, END>{ thing } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<it_t<CONST>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<it_t<CONST>>::share(shoal);
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

	inline _ABSTRACTION_ increment__(range_a<> const&)
	{
		return increment_();
	}

	inline _ABSTRACTION_ increment_()
	{
		operator++();
		return me_();
	}

	inline it_t& operator++()
	{
		_thing = END::val_();
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
		, _thing(thing, !CONST)
	{}

private:
	static bool const ___share___;
	friend class ___it_t_share___;
};

template <bool CONST, typename END, typename _ABSTRACTION_>
bool const it_t<CONST, END, _ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	it_t<CONST, END, _ABSTRACTION_>::share(shoal);
	return shoal;
}();

class ___it_t_share___
{
	static inline bool ___share___()
	{
		return it_t<true>::___share___
			&& it_t<false>::___share___;
	}
};

} // namespace strange

#endif
