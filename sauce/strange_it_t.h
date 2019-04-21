#ifndef COM_ONEISH_STRANGE_IT_T_H
#define COM_ONEISH_STRANGE_IT_T_H

namespace strange
{

template <bool CONST = false, typename _ABSTRACTION_ = any_a, typename END = nothing_t<>>
class it_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline any_a val(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline any_a val_(any_a thing = END::val_())
	{
		return any_a{ it_t<CONST, _ABSTRACTION_, END>{ thing } };
	}

	static inline any_a ref(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline any_a ref_(any_a thing = END::val_())
	{
		return any_a(it_t<CONST, _ABSTRACTION_, END>{ thing }, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::it");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a thing) const
	{
		return _thing.nothing__() == thing->nothing__();
	}

	inline bool operator!=(any_a thing) const
	{
		return _thing.nothing__() != thing->nothing__();
	}

	inline std::size_t hash__() const
	{
		return _thing.hash__();
	}

	// iterator
	inline any_a& operator*() const
	{
		return _thing;
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
	mutable any_a _thing; //TODO A forward iterator cannot be "stashing": it cannot return a reference to an object within itself, because such references would be invalidated by the destruction of the forward iterator.

	inline it_t(const any_a& thing)
		: something_t{}
		, _thing(thing, !CONST)
	{}
};

} // namespace strange

#endif
