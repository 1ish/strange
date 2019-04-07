#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

namespace strange
{

template <typename THING_ = thing_>
class Everything : public Range<THING_>
{
public:
	// construction
	static inline thing_& val(thing_ _ = thing_{})
	{
		static thing_ VAL = thing_{ Everything<>{} };
		return VAL;
	}

	static inline thing_& ref(thing_ _ = thing_{})
	{
		static thing_ REF = thing_(Everything<>{}, true);
		return REF;
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
		return thing.hash__() == 1;
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
		return thing.hash__() != 1;
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
		return 1;
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return get_();
	}

	inline thing_ get_() const
	{
		return Everything<>::ref();
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
		return Everything<>::ref();
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
		return operator++();
	}

	inline thing_ operator++()
	{
		return Everything<>::ref();
	}

protected:
	inline Everything()
		: Range{}
	{}
};

} // namespace strange

#endif
