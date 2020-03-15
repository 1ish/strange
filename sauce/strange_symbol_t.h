#ifndef COM_ONEISH_STRANGE_SYMBOL_T_H
#define COM_ONEISH_STRANGE_SYMBOL_T_H

namespace strange
{

template <typename ___ego___ = symbol_a<>>
class symbol_t : public thing_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			return create_();
		}
		any_a<> const lake = *it;
		if (!check<lake_a<int8_t>>(lake))
		{
			throw dis("strange::symbol::create passed non-lake-int-8");
		}
		return create_(fast<lake_a<int8_t>>(lake));
	}

	static inline symbol_a<> create_()
	{
		static symbol_a<> VAL = symbol_t<>::create("");
		return VAL;
	}

	static inline symbol_a<> create_(lake_a<int8_t> const& lake)
	{
		return symbol_a<>::create<symbol_t<>>(lake_to_string(lake));
	}

	template <typename F>
	static inline symbol_a<> create(F&& s)
	{
		return symbol_a<>::create<symbol_t<>>(std::forward<F>(s));
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
	inline bool same_(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing) && _string == fast<symbol_a<>>(thing).to_string();
	}

	inline bool operator==(symbol_a<> const& symbol) const
	{
		return _string == symbol.to_string();
	}

	inline bool operator!=(symbol_a<> const& symbol) const
	{
		return _string != symbol.to_string();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		return _hash;
	}

	inline bool is(std::string const& s) const
	{
		return _string == s;
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing)
			? _string < fast<symbol_a<>>(thing).to_string()
			: one_t::less_than_(thing);
	}

	inline bool operator<(symbol_a<> const& symbol) const
	{
		return _string < symbol.to_string();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing)
			? _string > fast<symbol_a<>>(thing).to_string()
			: one_t::greater_than_(thing);
	}

	inline bool operator>(symbol_a<> const& symbol) const
	{
		return _string > symbol.to_string();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing)
			? _string <= fast<symbol_a<>>(thing).to_string()
			: one_t::less_or_equal_(thing);
	}

	inline bool operator<=(symbol_a<> const& symbol) const
	{
		return _string <= symbol.to_string();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		return check<symbol_a<>>(thing)
			? _string >= fast<symbol_a<>>(thing).to_string()
			: one_t::greater_or_equal_(thing);
	}

	inline bool operator>=(symbol_a<> const& symbol) const
	{
		return _string >= symbol.to_string();
	}

	// symbol
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

	inline symbol_a<> add_(symbol_a<> const& symbol) const
	{
		return symbol_t<>::create(_string + symbol.to_string());
	}

protected:
	std::string const _string;
	std::size_t const _hash;

	friend class any_a<>;

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
