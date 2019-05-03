#ifndef COM_ONEISH_STRANGE_IT_T_H
#define COM_ONEISH_STRANGE_IT_T_H

namespace strange
{

template <bool CONST = false, typename _ABSTRACTION_ = forward_iterator_a<>, typename END = nothing_t<>>
class it_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline forward_iterator_a<> val(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline forward_iterator_a<> val_(any_a<> const& thing = END::val_())
	{
		return forward_iterator_a<>{ it_t<CONST, _ABSTRACTION_, END>{ thing } };
	}

	static inline forward_iterator_a<> ref(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline forward_iterator_a<> ref_(any_a<> const& thing = END::val_())
	{
		return forward_iterator_a<>(it_t<CONST, _ABSTRACTION_, END>{ thing }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::it");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check_<forward_iterator_a<>>(thing))
		{
			return false;
		}
		return _thing.nothing__() == cast_<forward_iterator_a<>>(thing)->nothing__();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		if (!check_<forward_iterator_a<>>(thing))
		{
			return true;
		}
		return _thing.nothing__() != cast_<forward_iterator_a<>>(thing)->nothing__();
	}

	inline std::size_t hash__() const
	{
		return _thing.hash__();
	}

	// forward iterator
	inline any_a<> get(any_a<> const&) const
	{
		return get_();
	}
	
	inline any_a<> get_() const
	{
		return operator*();
	}

	inline any_a<> set(any_a<> const& range) const
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::it set passed empty range");
		}
		return set_(*it);
	}

	inline any_a<> set_(any_a<> const& thing) const
	{
		return operator*() = thing;
	}

	inline any_a<>* operator->() const
	{
		return &operator*();
	}

	inline any_a<>& operator*() const
	{
		return _thing;
	}

	inline _ABSTRACTION_ increment(any_a<> const&)
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
		: something_t{}
		, _thing(thing, !CONST)
	{}
};

} // namespace strange

#endif
