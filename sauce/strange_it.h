#ifndef COM_ONEISH_STRANGE_IT_H
#define COM_ONEISH_STRANGE_IT_H

namespace strange
{

template <bool CONST = false, typename CAT = thing_, typename END = Nothing<>>
class It : public Something<CAT>
{
public: ___THING___
	// construction
	static inline thing_ val(thing_ range)
	{
		thing_ it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline thing_ val_(thing_ thing = END::val_())
	{
		return thing_{ It<CONST, CAT, END>{ thing } };
	}

	static inline thing_ ref(thing_ range)
	{
		thing_ it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline thing_ ref_(thing_ thing = END::val_())
	{
		return thing_(It<CONST, CAT, END>{ thing }, true);
	}

	// reflection
	static inline symbol_ type_()
	{
		return sym__("strange::It");
	}

	// comparison
	inline bool operator==(thing_ thing) const
	{
		return thing->nothing__() == _thing.nothing__();
	}

	inline bool operator!=(thing_ thing) const
	{
		return thing->nothing__() != _thing.nothing__();
	}

	inline std::size_t hash__() const
	{
		return _thing.hash__();
	}

	// iterator
	inline thing_& operator*() const
	{
		return _thing;
	}

	inline It& operator++()
	{
		_thing = END::val_();
		return *this;
	}

	inline It operator++(int)
	{
		It result = *this;
		operator++();
		return result;
	}

protected:
	mutable thing_ _thing; //TODO A forward iterator cannot be "stashing": it cannot return a reference to an object within itself, because such references would be invalidated by the destruction of the forward iterator.

	inline It(const thing_& thing)
		: Something{}
		, _thing(thing, !CONST)
	{}
};

} // namespace strange

#endif
