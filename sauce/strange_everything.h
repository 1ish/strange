#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

namespace strange
{

template <typename THING_ = thing_>
class Everything : public Range<THING_>
{
public: ___THING___
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
	inline bool operator==(thing_ thing) const
	{
		return thing.hash__() == 1;
	}

	inline bool operator!=(thing_ thing) const
	{
		return thing.hash__() != 1;
	}

	inline size_t hash__() const
	{
		return 1;
	}

	// iterator
	inline thing_& operator*() const
	{
		return Everything<>::ref();
	}

	inline Everything& operator++()
	{
		return *this;
	}

	inline Everything operator++(int)
	{
		Everything result = *this;
		operator++();
		return result;
	}

protected:
	inline Everything()
		: Range{}
	{}
};

} // namespace strange

#endif
