#ifndef COM_ONEISH_STRANGE_SYMBOL_T_H
#define COM_ONEISH_STRANGE_SYMBOL_T_H

namespace strange
{

template <typename _ABSTRACTION_ = symbol_a<>>
class symbol_t : public thing_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline symbol_a<> val_(any_a<> const& thing = no())
	{
		return val("");
	}

	template <typename F>
	static inline symbol_a<> val(F&& s)
	{
		return symbol_a<>{ symbol_t{ std::forward<F>(s) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<symbol_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<symbol_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing) && cast<symbol_a<>>(thing).to_string() == _string;
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !check<symbol_a<>>(thing) || cast<symbol_a<>>(thing).to_string() != _string;
	}

	inline std::size_t hash() const
	{
		return _hash;
	}

	inline bool is(std::string const& s) const
	{
		return s == _string;
	}

	// symbol
	inline std::string const& to_string() const
	{
		return _string;
	}

	inline symbol_a<> add__(range_a<> const& range) const
	{
		std::string s = _string;
		for (any_a<> const& thing : range)
		{
			if (check<symbol_a<>>(thing))
			{
				s += cast<symbol_a<>>(thing).to_string();
			}
		}
		return symbol_a<>{ symbol_t{ std::move(s) } };
	}

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{
		return operator+(symbol);
	}

	inline symbol_a<> operator+(symbol_a<> const& symbol) const
	{
		return symbol_a<>{ symbol_t{ _string + symbol.to_string() } };
	}

protected:
	std::string const _string;
	std::size_t const _hash;

	template <typename F>
	inline symbol_t(F&& s)
		: thing_t{}
		, _string{ std::forward<F>(s) }
		, _hash{ std::hash<std::string>{}(_string) }
	{}
};

template <typename F>
inline symbol_a<> sym(F&& s)
{
	return symbol_t<>::val(std::forward<F>(s));
}

} // namespace strange

#endif
