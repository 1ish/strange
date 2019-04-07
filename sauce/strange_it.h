#ifndef COM_ONEISH_STRANGE_IT_H
#define COM_ONEISH_STRANGE_IT_H

namespace strange
{

template <typename THING_ = thing_, typename END = Nothing<>>
class It : public Range<THING_>
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
		return thing_{ It<THING_, END>{ thing } };
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
		return thing_(It<THING_, END>{ thing }, true);
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
		return hash_();
	}

	inline thing_ hash_() const
	{
		return Everything<>::ref(); //TODO
	}

	inline size_t hash__() const
	{
		return size_t(this);
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

	inline thing_ set(thing_ range) const
	{
		return set_(range);
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
		return &operator*();
	}

	inline thing_ increment(thing_)
	{
		return increment_();
	}

	inline thing_ increment_()
	{
		operator++();
		return me_();
	}

	inline It& operator++()
	{
		_thing = END::ref();
		return *this;
	}

	inline It operator++(int)
	{
		It result = *this;
		operator++();
		return result;
	}

protected:
	mutable thing_ _thing;

	inline It(const thing_& thing)
		: Range{}
		, _thing(thing, true)
	{}
};

} // namespace strange

#endif