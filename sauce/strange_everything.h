#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

namespace strange
{

template <typename CAT_ = thing_>
class Everything : public Something<CAT_>
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
		static thing_ VAL = thing_{ Everything<>{} };
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
		static thing_ REF = thing_(Everything<>{}, true);
		return REF;
	}

	// reflection
	static inline symbol_ type_()
	{
		static symbol_ TYPE = sym__("strange::Everything");
		return TYPE;
	}

	// comparison
	static inline thing_ everything(thing_)
	{
		return everything_();
	}

	static inline thing_ everything_()
	{
		return Everything<>::val_();
	}

	static inline bool everything__()
	{
		return true;
	}

	inline bool operator==(thing_ thing) const
	{
		return thing.everything__();
	}

	inline bool operator!=(thing_ thing) const
	{
		return !thing.everything__();
	}

	inline std::size_t hash__() const
	{
		static const std::size_t HASH = std::hash<int64_t>{}(1);
		return HASH;
	}

	// iterator
	inline thing_& operator*() const
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
