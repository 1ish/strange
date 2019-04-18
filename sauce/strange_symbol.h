#ifndef COM_ONEISH_STRANGE_SYMBOL_H
#define COM_ONEISH_STRANGE_SYMBOL_H

namespace strange
{

template <typename CAT_ = symbol_a>
class Symbol : public Something<CAT_>
{
public: ___THING___
	// construction
	static inline symbol_a val(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline symbol_a val_(any_a thing = Nothing<>::val_())
	{
		return val__("");
	}

	template <typename F>
	static inline symbol_a val__(F&& s)
	{
		return symbol_a{ Symbol{ std::forward<F>(s) } };
	}

	static inline symbol_a ref(any_a range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline symbol_a ref_(any_a thing = Nothing<>::val_())
	{
		return ref__("");
	}

	template <typename F>
	static inline symbol_a ref__(F&& s)
	{
		return symbol_a(Symbol{ std::forward<F>(s) }, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::Symbol");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a thing) const
	{
		return check_<symbol_a>(thing) && cast_<symbol_a>(thing).to_string__() == _string;
	}

	inline bool operator!=(any_a thing) const
	{
		return !check_<symbol_a>(thing) || cast_<symbol_a>(thing).to_string__() != _string;
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

	inline symbol_a add(any_a range) const
	{
		std::string s;
		for (const any_a thing : range)
		{
			if (check_<symbol_a>(thing))
			{
				s += cast_<symbol_a>(thing).to_string__();
			}
		}
		return symbol_a{ Symbol{ s } };
	}

	inline symbol_a add_(symbol_a symbol) const
	{
		return operator+(symbol);
	}

	inline symbol_a operator+(symbol_a symbol) const
	{
		return symbol_a{ Symbol{ _string + symbol.to_string__() } };
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
inline symbol_a sym__(F&& s)
{
	return Symbol<>::val__(std::forward<F>(s));
}

} // namespace strange

#endif
