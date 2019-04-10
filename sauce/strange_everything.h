#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

namespace strange
{

template <typename CAT = thing_>
class Everything : public Something<CAT>
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

	inline thing_ everything(thing_) const
	{
		return everything_();
	}

	inline thing_ everything_() const
	{
		return Everything<>::ref();
	}

	inline bool everything__() const
	{
		return true;
	}

	// iterator
	inline thing_& operator*() const
	{
		return Everything<>::val();
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
