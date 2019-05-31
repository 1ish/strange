#ifndef COM_ONEISH_STRANGE_TOKEN_T_H
#define COM_ONEISH_STRANGE_TOKEN_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class token_t : public thing_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::token::val passed empty range");
		}
		any_a<> filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis("strange::token::val passed non-symbol filename");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::val passed short range");
		}
		any_a<> line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis("strange::token::val passed non-number-int-64 line");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::val passed short range");
		}
		any_a<> pos = *it;
		if (!check<number_data_a<int64_t>>(pos))
		{
			throw dis("strange::token::val passed non-number-int-64 pos");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::val passed short range");
		}
		any_a<> tag = *it;
		if (!check<symbol_a<>>(tag))
		{
			throw dis("strange::token::val passed non-symbol tag");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::val passed short range");
		}
		any_a<> symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis("strange::token::val passed non-symbol symbol");
		}
		if (++it == range.cend_())
		{
			return val_(filename, line, pos, tag, symbol);
		}
		return val_(filename, line, pos, tag, symbol, *it);
	}

	static inline any_a<> val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& pos, symbol_a<> const& tag, symbol_a<> const& symbol)
	{
		return val_(filename, line, pos, tag, symbol, symbol);
	}

	static inline any_a<> val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& pos, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& value)
	{
		return any_a<>{ token_t(filename, line, pos, tag, symbol, value) };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<token_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<token_t<>>::share(shoal);
	}

	// token

protected:
	symbol_a<> const _filename;
	number_data_a<int64_t> const _line;
	number_data_a<int64_t> const _pos;
	symbol_a<> const _tag;
	symbol_a<> const _symbol;
	any_a<> const _value;

	inline token_t(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& pos, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& value)
		: thing_t{}
		, _filename{ filename }
		, _line{ line }
		, _pos{ pos }
		, _tag{ tag }
		, _symbol{ symbol }
		, _value{ value }
	{}
};

} // namespace strange

#endif
