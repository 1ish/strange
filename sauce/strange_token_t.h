#ifndef COM_ONEISH_STRANGE_TOKEN_T_H
#define COM_ONEISH_STRANGE_TOKEN_T_H

namespace strange
{

template <typename ___ego___ = token_a<>>
class token_t : public thing_t<___ego___>
{
	using create_member = token_a<>(*)(symbol_a<> const&, number_data_a<int64_t> const&, number_data_a<int64_t> const&, symbol_a<> const&, number_data_a<int64_t> const&);

public:
	// override
	using over = thing_o<token_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::token::create passed empty range");
		}
		any_a<> filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis("strange::token::create passed non-symbol filename");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis("strange::token::create passed non-number-int-64 line");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis("strange::token::create passed non-number-int-64 position");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> tag = *it;
		if (!check<symbol_a<>>(tag))
		{
			throw dis("strange::token::create passed non-symbol tag");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis("strange::token::create passed non-symbol symbol");
		}
		if (++it == range.cend_())
		{
			return create_(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(tag), cast<symbol_a<>>(symbol));
		}
		any_a<> literal = *it;
		if (++it == range.cend_())
		{
			return create_(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(tag), cast<symbol_a<>>(symbol), literal);
		}
		any_a<> precedence = *it;
		if (!check<number_data_a<int64_t>>(precedence))
		{
			throw dis("strange::token::create passed non-int-64 precedence");
		}
		return create_(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(tag), cast<symbol_a<>>(symbol), literal, cast<number_data_a<int64_t>>(precedence));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol)
	{
		return create_(filename, line, position, tag, symbol, symbol, number_int_64_t<>::create(-1));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal)
	{
		return token_a<>{ over{ token_t<>(filename, line, position, tag, symbol, literal, number_int_64_t<>::create(-1)) } };
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal, number_data_a<int64_t> const& precedence)
	{
		return token_a<>{ over{ token_t<>(filename, line, position, tag, symbol, literal, precedence) } };
	}

	static inline token_a<> create(std::string const& tag, range_a<> const& range, create_member member)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::token::create_" + tag + " passed empty range");
		}
		auto const filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis("strange::token::create_" + tag + " passed non-symbol filename");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::create_" + tag + "passed short range");
		}
		auto const line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis("strange::token::create_" + tag + " passed non-number-int-64 line");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::create_" + tag + " passed short range");
		}
		auto const position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis("strange::token::create_" + tag + " passed non-number-int-64 position");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::create_" + tag + " passed short range");
		}
		auto const symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis("strange::token::create_" + tag + " passed non-symbol symbol");
		}
		if (++it == range.cend_())
		{
			return member(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(symbol), number_int_64_t<>::create(-1));
		}
		auto const precedence = *it;
		if (!check<number_data_a<int64_t>>(precedence))
		{
			throw dis("strange::token::create_" + tag + " passed non-int-64 precedence");
		}
		return member(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(symbol), cast<number_data_a<int64_t>>(precedence));
	}

	static inline any_a<> create_symbol__(range_a<> const& range)
	{
		return create("symbol", range, &create_symbol_);
	}
	
	static inline token_a<> create_symbol_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("symbol"), symbol);
	}

	static inline token_a<> create_symbol(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return create_symbol_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_lake__(range_a<> const& range)
	{
		return create("lake", range, &create_lake_);
	}

	static inline token_a<> create_lake_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("lake"), symbol, lake_from_string(symbol.to_string()));
	}

	static inline token_a<> create_lake(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return create_lake_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_int__(range_a<> const& range)
	{
		return create("int", range, &create_int_);
	}

	static inline token_a<> create_int_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("int"), symbol, int_64_from_string(symbol.to_string()));
	}

	static inline token_a<> create_int(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return create_int_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_float__(range_a<> const& range)
	{
		return create("float", range, &create_float_);
	}

	static inline token_a<> create_float_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("float"), symbol, float_64_from_string(symbol.to_string()));
	}

	static inline token_a<> create_float(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return create_float_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_name__(range_a<> const& range)
	{
		return create("name", range, &create_name_);
	}

	static inline token_a<> create_name_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("name"), symbol);
	}

	static inline token_a<> create_name(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return create_name_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_punctuation__(range_a<> const& range)
	{
		return create("punctuation", range, &create_punctuation_);
	}

	static inline token_a<> create_punctuation_()
	{
		return create_punctuation("", 0, 0, "", 0);
	}

	static inline token_a<> create_punctuation_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& precedence)
	{
		return create_(filename, line, position, sym("punctuation"), symbol, symbol, precedence);
	}

	static inline token_a<> create_punctuation(std::string const& filename, int64_t line, int64_t position, std::string const& symbol, int64_t precedence)
	{
		return create_punctuation_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol), number_int_64_t<>::create(precedence));
	}

	static inline any_a<> create_error__(range_a<> const& range)
	{
		return create("error", range, &create_error_);
	}

	static inline token_a<> create_error_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("error"), symbol);
	}

	static inline token_a<> create_error(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return create_error_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
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
	inline any_a<> filename__(range_a<> const&) const
	{
		return filename_();
	}

	inline symbol_a<> filename_() const
	{
		return _filename;
	}

	inline std::string filename() const
	{
		return _filename.to_string();
	}

	inline any_a<> line__(range_a<> const&) const
	{
		return line_();
	}

	inline number_data_a<int64_t> line_() const
	{
		return _line;
	}

	inline int64_t line() const
	{
		return _line.extract_primitive();
	}

	inline any_a<> position__(range_a<> const&) const
	{
		return position_();
	}

	inline number_data_a<int64_t> position_() const
	{
		return _position;
	}

	inline int64_t position() const
	{
		return _position.extract_primitive();
	}

	inline any_a<> tag__(range_a<> const&) const
	{
		return tag_();
	}

	inline symbol_a<> tag_() const
	{
		return _tag;
	}

	inline std::string tag() const
	{
		return _tag.to_string();
	}

	inline any_a<> symbol__(range_a<> const&) const
	{
		return symbol_();
	}

	inline symbol_a<> symbol_() const
	{
		return _symbol;
	}

	inline std::string symbol() const
	{
		return _symbol.to_string();
	}

	inline any_a<> literal__(range_a<> const&) const
	{
		return literal_();
	}

	inline any_a<> literal_() const
	{
		return _literal;
	}

	inline any_a<> precedence__(range_a<> const&) const
	{
		return precedence_();
	}

	inline number_data_a<int64_t> precedence_() const
	{
		return _precedence;
	}

	inline int64_t precedence() const
	{
		return _precedence.extract_primitive();
	}

	inline any_a<> report__(range_a<> const&) const
	{
		return report_();
	}

	inline misunderstanding_a<> report_() const
	{
		return misunderstanding_t<>::create(report());
	}

	inline std::string report() const
	{
		return filename() + "(" + std::to_string(line()) + "," + std::to_string(position()) + "): " + tag() + " '" + symbol() + "'\n";
	}

protected:
	symbol_a<> const _filename;
	number_data_a<int64_t> const _line;
	number_data_a<int64_t> const _position;
	symbol_a<> const _tag;
	symbol_a<> const _symbol;
	any_a<> const _literal;
	number_data_a<int64_t> const _precedence;

	inline token_t(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal, number_data_a<int64_t> const& precedence)
		: thing_t{}
		, _filename{ filename }
		, _line{ line }
		, _position{ position }
		, _tag{ tag }
		, _symbol{ symbol }
		, _literal{ literal }
		, _precedence{ precedence }
	{}

private:
	static bool const ___share___;
	friend class ___token_t_share___;
};

template <typename ___ego___>
bool const token_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	token_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
