#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

namespace strange
{

template <typename THING_ = thing_>
class Nothing : public Range<THING_, true>
{
public:
	// construction
	static inline thing_& val(thing_ _ = thing_{})
	{
		static thing_ VAL = []()
		{
			thing_ thing;
			thing = Nothing<>{ thing };
			return thing;
		}();
		return VAL;
	}

	static inline thing_& ref(thing_ _ = thing_{})
	{
		static thing_ REF = []()
		{
			thing_ thing{ true };
			thing = Nothing<>{ thing };
			return thing;
		}();
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
		return thing.hash__() == 0;
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
		return thing.hash__() != 0;
	}

	inline thing_ hash(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_ hash_() const
	{
		return Nothing<>::ref();
	}

	inline size_t hash__() const
	{
		return 0;
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_ get_() const
	{
		return Nothing<>::ref();
	}

	inline thing_ set(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_ set_(thing_) const
	{
		return Nothing<>::ref();
	}

	inline thing_& operator*() const
	{
		return Nothing<>::ref();
	}

	inline thing_* operator->() const
	{
		return &Nothing<>::ref();
	}

	inline thing_ increment(thing_)
	{
		return Nothing<>::ref();
	}

	inline thing_ increment_()
	{
		return Nothing<>::ref();
	}

	inline thing_ operator++()
	{
		return Nothing<>::ref();
	}

protected:
	inline Nothing(const thing_& me)
		: Range{ me }
	{}
};

} // namespace strange

#endif
