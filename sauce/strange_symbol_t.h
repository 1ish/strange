#ifndef COM_ONEISH_STRANGE_SYMBOL_T_H
#define COM_ONEISH_STRANGE_SYMBOL_T_H

namespace strange
{

template <typename ___ego___ = symbol_a<>>
class symbol_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<symbol_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return create_();
		}
		any_a<> const lake = *it;
		if (!check<lake_a<int8_t>>(lake))
		{
			throw dis("strange::symbol::create passed non-lake-int-8");
		}
		return create_(cast<lake_a<int8_t>>(lake));
	}

	static inline symbol_a<> create_()
	{
		static symbol_a<> VAL = symbol_t<>::create("");
		return VAL;
	}

	static inline symbol_a<> create_(lake_a<int8_t> const& lake)
	{
		return symbol_a<>::create<over>(symbol_t<>{ lake_to_string(lake) });
	}

	template <typename F>
	static inline symbol_a<> create(F&& s)
	{
		return symbol_a<>::create<over>(symbol_t<>{ std::forward<F>(s) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::symbol");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::symbol::create", native_function_create(&symbol_t<>::create__));
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing) && cast<symbol_a<>>(thing).to_string() == _string;
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
	inline any_a<> to_lake__(range_a<> const&) const
	{
		return to_lake_();
	}

	inline lake_a<int8_t> to_lake_() const
	{
		return lake_from_string(_string);
	}

	inline std::string to_string() const
	{
		return _string;
	}

	inline int8_t first_character() const
	{
		return _string.empty() ? 0 : _string[0];
	}

	inline int8_t last_character() const
	{
		auto const length = _string.length();
		return length ? _string[length - 1] : 0;
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
		return symbol_t<>::create(std::move(s));
	}

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{
		return operator+(symbol);
	}

	inline symbol_a<> operator+(symbol_a<> const& symbol) const
	{
		return symbol_t<>::create(_string + symbol.to_string());
	}

protected:
	std::string const _string;
	std::size_t const _hash;

	template <typename F>
	inline symbol_t(F&& s)
		: thing_t<___ego___>{}
		, _string{ std::forward<F>(s) }
		, _hash{ std::hash<std::string>{}(_string) }
	{}

private:
	static bool const ___share___;
	friend class ___symbol_t_share___;
};

template <typename ___ego___>
bool const symbol_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	symbol_t<___ego___>::share(shoal);
	return shoal;
}();

template <typename F>
inline symbol_a<> sym(F&& s)
{
	return symbol_t<>::create(std::forward<F>(s));
}

class ___symbol_t_share___
{
	static inline bool ___share___()
	{
		return symbol_t<>::___share___;
	}
};

} // namespace strange

#endif
