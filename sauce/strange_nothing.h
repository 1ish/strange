#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

namespace strange
{

template <typename CAT = thing_>
class Nothing : public Something<CAT>
{
public: ___THING___
	// construction
	static inline thing_ val(thing_ _ = thing_{})
	{
		static thing_ VAL = thing_{ Nothing<>{} };
		return VAL;
	}

	static inline thing_ ref(thing_ _ = thing_{})
	{
		static thing_ REF = thing_(Nothing<>{}, true);
		return REF;
	}

	// conversion
	inline operator bool() const
	{
		return anything__();
	}

	// comparison
	inline bool operator==(thing_ thing) const
	{
		return thing.nothing__();
	}

	inline bool operator!=(thing_ thing) const
	{
		return !thing.nothing__();
	}

	inline std::size_t hash__() const
	{
		static const std::size_t HASH = std::hash<int64_t>{}(0);
		return HASH;
	}

	inline thing_ nothing(thing_) const
	{
		return nothing_();
	}

	inline thing_ nothing_() const
	{
		return Everything<>::ref();
	}

	inline bool nothing__() const
	{
		return true;
	}

	inline thing_ anything(thing_) const
	{
		return anything_();
	}

	inline thing_ anything_() const
	{
		return Nothing<>::ref();
	}

	inline bool anything__() const
	{
		return false;
	}

	// range
	inline thing_ cbegin() const
	{
		return It<true, thing_, Everything<>>::val_(Nothing<>::ref());
	}

	inline thing_ begin()
	{
		return It<false, thing_, Everything<>>::val_(Nothing<>::ref());
	}

	inline thing_ cend() const
	{
		return Everything<>::ref();
	}

	inline thing_ end()
	{
		return Everything<>::ref();
	}

	// iterator
	inline thing_& operator*() const
	{
		return Nothing<>::val();
	}

	inline Nothing& operator++()
	{
		return *this;
	}

	inline Nothing operator++(int)
	{
		return *this;
	}

protected:
	inline Nothing()
		: Something{}
	{}
};

} // namespace strange

#endif
