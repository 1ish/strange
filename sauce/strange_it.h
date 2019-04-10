#ifndef COM_ONEISH_STRANGE_IT_H
#define COM_ONEISH_STRANGE_IT_H

namespace strange
{

template <bool CONST = false, typename THING_ = thing_, typename END = Nothing<>>
class It : public Something<THING_>
{
public: ___THING___
	// construction
	static inline thing_ val(thing_ range)
	{
		const auto it = range.beget_();
		if (it == range.enget_())
		{
			return val_();
		}
		return val_(it.get_());
	}

	static inline thing_ val_(thing_ thing = END::val())
	{
		return thing_{ It<CONST, THING_, END>{ thing } };
	}

	static inline thing_ ref(thing_ range)
	{
		const auto it = range.beget_();
		if (it == range.enget_())
		{
			return ref_();
		}
		return ref_(it.get_());
	}

	static inline thing_ ref_(thing_ thing = END::val())
	{
		return thing_(It<CONST, THING_, END>{ thing }, true);
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
		_thing = END::val();
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
