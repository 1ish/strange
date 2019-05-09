#ifndef COM_ONEISH_STRANGE_SYMBOL_T_H
#define COM_ONEISH_STRANGE_SYMBOL_T_H

namespace strange
{

template <typename _ABSTRACTION_ = symbol_a<>>
class symbol_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline symbol_a<> val(any_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline symbol_a<> val_(any_a<> const& thing = nothing_t<>::val_())
	{
		return val__("");
	}

	template <typename F>
	static inline symbol_a<> val__(F&& s)
	{
		return symbol_a<>{ symbol_t{ std::forward<F>(s) } };
	}

	static inline symbol_a<> ref(any_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline symbol_a<> ref_(any_a<> const& thing = nothing_t<>::val_())
	{
		return ref__("");
	}

	template <typename F>
	static inline symbol_a<> ref__(F&& s)
	{
		return symbol_a<>(symbol_t{ std::forward<F>(s) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::symbol");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check_<symbol_a<>>(thing) && cast_<symbol_a<>>(thing).to_string__() == _string;
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !check_<symbol_a<>>(thing) || cast_<symbol_a<>>(thing).to_string__() != _string;
	}

	inline std::size_t hash__() const
	{
		return _hash;
	}

	inline bool is__(std::string const& s) const
	{
		return s == _string;
	}

	// symbol
	inline std::string const& to_string__() const
	{
		return _string;
	}

	inline symbol_a<> add(any_a<> const& range) const
	{
		std::string s = _string;
		for (any_a<> const& thing : range)
		{
			if (check_<symbol_a<>>(thing))
			{
				s += cast_<symbol_a<>>(thing).to_string__();
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
		return symbol_a<>{ symbol_t{ _string + symbol.to_string__() } };
	}

protected:
	std::string const _string;
	std::size_t const _hash;

	template <typename F>
	inline symbol_t(F&& s)
		: something_t{}
		, _string{ std::forward<F>(s) }
		, _hash{ std::hash<std::string>{}(_string) }
	{}
};

template <typename F>
inline symbol_a<> sym__(F&& s)
{
	return symbol_t<>::val__(std::forward<F>(s));
}

} // namespace strange

#endif
