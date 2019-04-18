#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

namespace strange
{

template <typename CAT_ = any_a>
class Everything : public Something<CAT_>
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
		static any_a VAL = any_a{ Everything<>{} };
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
		static any_a REF = any_a(Everything<>{}, true);
		return REF;
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::Everything");
		return TYPE;
	}

	// comparison
	static inline any_a everything(any_a)
	{
		return everything_();
	}

	static inline any_a everything_()
	{
		return Everything<>::val_();
	}

	static inline bool everything__()
	{
		return true;
	}

	inline bool operator==(any_a thing) const
	{
		return thing.everything__();
	}

	inline bool operator!=(any_a thing) const
	{
		return !thing.everything__();
	}

	inline std::size_t hash__() const
	{
		static const std::size_t HASH = std::hash<int64_t>{}(1);
		return HASH;
	}

	// iterator
	inline any_a& operator*() const
	{
		return Everything<>::val__();
	}

	inline Everything& operator++()
	{
		return *this;
	}

	inline Everything operator++(int)
	{
		return *this;
	}

protected:
	inline Everything()
		: Something{}
	{}
};

} // namespace strange

#endif
