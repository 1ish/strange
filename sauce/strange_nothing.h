#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

namespace strange
{

template <typename CAT_ = any_a>
class Nothing : public Something<CAT_>
{
public: ___THING___
	// construction
	static inline any_a val(any_a _)
	{
		return val_();
	}

	static inline any_a val_()
	{
		return val__();
	}

	static inline any_a& val__()
	{
		static any_a VAL = any_a{ Nothing<>{} };
		return VAL;
	}

	static inline any_a ref(any_a _)
	{
		return ref_();
	}

	static inline any_a ref_()
	{
		return ref__();
	}

	static inline any_a& ref__()
	{
		static any_a REF = any_a(Nothing<>{}, true);
		return REF;
	}

	// conversion
	inline operator bool() const
	{
		return anything__();
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::Nothing");
		return TYPE;
	}

	// comparison
	static inline any_a nothing(any_a)
	{
		return nothing_();
	}

	static inline any_a nothing_()
	{
		return Everything<>::val_();
	}

	static inline bool nothing__()
	{
		return true;
	}

	static inline any_a anything(any_a)
	{
		return anything_();
	}

	static inline any_a anything_()
	{
		return Nothing<>::val_();
	}

	static inline bool anything__()
	{
		return false;
	}

	inline bool operator==(any_a thing) const
	{
		return thing.nothing__();
	}

	inline bool operator!=(any_a thing) const
	{
		return !thing.nothing__();
	}

	inline std::size_t hash__() const
	{
		static const std::size_t HASH = std::hash<int64_t>{}(0);
		return HASH;
	}

	// range
	inline any_a cbegin() const
	{
		return It<true, any_a, Everything<>>::val_(Nothing<>::val_());
	}

	inline any_a begin()
	{
		return It<false, any_a, Everything<>>::val_(Nothing<>::val_());
	}

	inline any_a cend() const
	{
		return Everything<>::val_();
	}

	inline any_a end()
	{
		return Everything<>::val_();
	}

	// iterator
	inline any_a& operator*() const
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
