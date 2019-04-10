#ifndef COM_ONEISH_STRANGE_SYMBOL_H
#define COM_ONEISH_STRANGE_SYMBOL_H

namespace strange
{

template <typename CAT = symbol_>
class Symbol : public Something<CAT>
{
public: ___THING___
	// construction
	static inline symbol_ val(thing_ range)
	{
		const auto it = range.beget_();
		if (it == range.enget_())
		{
			return val_();
		}
		return val_(it.get_());
	}

	static inline symbol_ val_(thing_ thing = Nothing<>::val())
	{
		return val__("");
	}

	template <typename F>
	static inline symbol_ val__(F&& s)
	{
		return symbol_{ Symbol{ std::forward<F>(s) } };
	}

	static inline symbol_ ref(thing_ range)
	{
		const auto it = range.beget_();
		if (it == range.enget_())
		{
			return ref_();
		}
		return ref_(it.get_());
	}

	static inline symbol_ ref_(thing_ thing = Nothing<>::val())
	{
		return ref__("");
	}

	template <typename F>
	static inline symbol_ ref__(F&& s)
	{
		return symbol_(Symbol{ std::forward<F>(s) }, true);
	}

	// comparison
	inline bool operator==(thing_ thing) const
	{
		return check_<symbol_>(thing) && cast_<symbol_>(thing).to_string__() == _string;
	}

	inline bool operator!=(thing_ thing) const
	{
		return !check_<symbol_>(thing) || cast_<symbol_>(thing).to_string__() != _string;
	}

	inline std::size_t hash__() const
	{
		return _hash;
	}

	inline bool is__(const std::string& s) const
	{
		return s == _string;
	}

	// symbol
	inline const std::string& to_string__() const
	{
		return _string;
	}

	inline symbol_ add(thing_ range) const
	{
		std::string s;
		for (const thing_ thing : range)
		{
			if (check_<symbol_>(thing))
			{
				s += cast_<symbol_>(thing).to_string__();
			}
		}
		return symbol_{ Symbol{ s } };
	}

	inline symbol_ add_(symbol_ symbol) const
	{
		return operator+(symbol);
	}

	inline symbol_ operator+(symbol_ symbol) const
	{
		return symbol_{ Symbol{ _string + symbol.to_string__() } };
	}

protected:
	const std::string _string;
	const std::size_t _hash;

	template <typename F>
	inline Symbol(F&& s)
		: Something{}
		, _string{ std::forward<F>(s) }
		, _hash{ std::hash<std::string>{}(_string) }
	{}
};

template <typename F>
inline symbol_ sym__(F&& s)
{
	return Symbol<>::val__(std::forward<F>(s));
}

} // namespace strange

#endif
