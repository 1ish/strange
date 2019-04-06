#ifndef COM_ONEISH_STRANGE_IT_H
#define COM_ONEISH_STRANGE_IT_H

namespace strange
{

template <typename THING_ = thing_, typename END = Nothing<>>
class It : public Something<THING_>
{
public:
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

	static inline thing_ val_(thing_ thing = END::ref())
	{
		thing_ it;
		it = It<THING_, END>(it, thing);
		return it;
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

	static inline thing_ ref_(thing_ thing = END::ref())
	{
		thing_ it{ true };
		it = It<THING_, END>(it, thing);
		return it;
	}

	// comparison
	inline thing_ same(thing_ range) const
	{
		const auto it = range.beget_();
		assert(it != range.enget_()); //TODO throw
		return same_(it.get_());
	}

	inline thing_ same_(thing_ thing) const
	{
		return _boole_(operator==(thing));
	}

	inline bool operator==(thing_ thing) const
	{
		return *thing == _thing;
	}

	inline thing_ different(thing_ range) const
	{
		const auto it = range.beget_();
		assert(it != range.enget_()); //TODO throw
		return different_(it.get_());
	}

	inline thing_ different_(thing_ thing) const
	{
		return _boole_(operator!=(thing));
	}

	inline bool operator!=(thing_ thing) const
	{
		return *thing != _thing;
	}

	inline thing_ hash(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ hash_() const
	{
		return Everything<>::ref();
	}

	inline size_t hash__() const
	{
		return 1;
	}

	// range
	inline thing_ beget(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ beget_() const
	{
		return Everything<>::ref();
	}

	inline thing_ cbegin() const
	{
		return Everything<>::ref();
	}

	inline thing_ beset(thing_)
	{
		return Everything<>::ref();
	}

	inline thing_ beset_()
	{
		return Everything<>::ref();
	}

	inline thing_ begin()
	{
		return Everything<>::ref();
	}

	inline thing_ enget(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ enget_() const
	{
		return Everything<>::ref();
	}

	inline thing_ cend() const
	{
		return Everything<>::ref();
	}

	inline thing_ enset(thing_)
	{
		return Everything<>::ref();
	}

	inline thing_ enset_()
	{
		return Everything<>::ref();
	}

	inline thing_ end()
	{
		return Everything<>::ref();
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return get_();
	}

	inline thing_ get_() const
	{
		return _thing;
	}

	inline thing_ set(thing_) const
	{
		return get_();
	}

	inline thing_ set_(thing_) const
	{
		return get_();
	}

	inline thing_& operator*() const
	{
		return _thing;
	}

	inline thing_* operator->() const
	{
		return &_thing;
	}

	inline thing_ increment(thing_)
	{
		return increment_();
	}

	inline thing_ increment_()
	{
		return operator++();
	}

	inline thing_ operator++()
	{
		_thing = END::ref();
		return me_();
	}

protected:
	mutable thing_ _thing;

	inline It(const thing_& me, const thing_& thing)
		: Something{ me }
		, _thing(thing, true)
	{}
};

} // namespace strange

#endif
