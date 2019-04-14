#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

namespace strange
{

template <typename CAT_ = thing_>
class Nothing : public Something<CAT_>
{
public: ___THING___
	// construction
	static inline thing_ val(thing_ _)
	{
		return val_();
	}

	static inline thing_ val_()
	{
		return val__();
	}

	static inline thing_& val__()
	{
		static thing_ VAL = thing_{ Nothing<>{} };
		return VAL;
	}

	static inline thing_ ref(thing_ _)
	{
		return ref_();
	}

	static inline thing_ ref_()
	{
		return ref__();
	}

	static inline thing_& ref__()
	{
		static thing_ REF = thing_(Nothing<>{}, true);
		return REF;
	}

	// conversion
	inline operator bool() const
	{
		return anything__();
	}

	// reflection
	static inline symbol_ type_()
	{
		static symbol_ TYPE = sym__("strange::Nothing");
		return TYPE;
	}

	// comparison
	static inline thing_ nothing(thing_)
	{
		return nothing_();
	}

	static inline thing_ nothing_()
	{
		return Everything<>::val_();
	}

	static inline bool nothing__()
	{
		return true;
	}

	static inline thing_ anything(thing_)
	{
		return anything_();
	}

	static inline thing_ anything_()
	{
		return Nothing<>::val_();
	}

	static inline bool anything__()
	{
		return false;
	}

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

	// range
	inline thing_ cbegin() const
	{
		return It<true, thing_, Everything<>>::val_(Nothing<>::val_());
	}

	inline thing_ begin()
	{
		return It<false, thing_, Everything<>>::val_(Nothing<>::val_());
	}

	inline thing_ cend() const
	{
		return Everything<>::val_();
	}

	inline thing_ end()
	{
		return Everything<>::val_();
	}

	// iterator
	inline thing_& operator*() const
	{
		return Nothing<>::val__();
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
