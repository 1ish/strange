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
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("strange::token::create passed empty range");
		}
		any_a<> filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis("strange::token::create passed non-symbol filename");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis("strange::token::create passed non-number-int-64 line");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis("strange::token::create passed non-number-int-64 position");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> tag = *it;
		if (!check<symbol_a<>>(tag))
		{
			throw dis("strange::token::create passed non-symbol tag");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::token::create passed short range");
		}
		any_a<> symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis("strange::token::create passed non-symbol symbol");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(tag), fast<symbol_a<>>(symbol));
		}
		any_a<> literal = *it;
		if (++it == range.extract_end_())
		{
			return create_(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(tag), fast<symbol_a<>>(symbol), literal);
		}
		any_a<> precedence = *it;
		if (!check<number_data_a<int64_t>>(precedence))
		{
			throw dis("strange::token::create passed non-int-64 precedence");
		}
		return create_(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(tag), fast<symbol_a<>>(symbol), literal, fast<number_data_a<int64_t>>(precedence));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol)
	{
		return create_(filename, line, position, tag, symbol, symbol, number_int_64_t<>::create(-1));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal)
	{
		return token_a<>::create<over>(token_t<>(filename, line, position, tag, symbol, literal, number_int_64_t<>::create(-1)));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal, number_data_a<int64_t> const& precedence)
	{
		return token_a<>::create<over>(token_t<>(filename, line, position, tag, symbol, literal, precedence));
	}

	static inline token_a<> create(std::string const& tag, range_a<> const& range, create_member member)
	{
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("strange::token::create_" + tag + " passed empty range");
		}
		auto const filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis("strange::token::create_" + tag + " passed non-symbol filename");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::token::create_" + tag + "passed short range");
		}
		auto const line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis("strange::token::create_" + tag + " passed non-number-int-64 line");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::token::create_" + tag + " passed short range");
		}
		auto const position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis("strange::token::create_" + tag + " passed non-number-int-64 position");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::token::create_" + tag + " passed short range");
		}
		auto const symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis("strange::token::create_" + tag + " passed non-symbol symbol");
		}
		if (++it == range.extract_end_())
		{
			return member(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(symbol), number_int_64_t<>::create(-1));
		}
		auto const precedence = *it;
		if (!check<number_data_a<int64_t>>(precedence))
		{
			throw dis("strange::token::create_" + tag + " passed non-int-64 precedence");
		}
		return member(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(symbol), fast<number_data_a<int64_t>>(precedence));
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
		static symbol_a<> TYPE = sym("strange::token");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::token::create", native_function_create(&token_t<>::create__));
		shoal.update_string("strange::token::create_symbol", native_function_create(&token_t<>::create_symbol__));
		shoal.update_string("strange::token::create_lake", native_function_create(&token_t<>::create_lake__));
		shoal.update_string("strange::token::create_int", native_function_create(&token_t<>::create_int__));
		shoal.update_string("strange::token::create_float", native_function_create(&token_t<>::create_float__));
		shoal.update_string("strange::token::create_name", native_function_create(&token_t<>::create_name__));
		shoal.update_string("strange::token::create_punctuation", native_function_create(&token_t<>::create_punctuation__));
		shoal.update_string("strange::token::create_error", native_function_create(&token_t<>::create_error__));
	}

	// token
	inline symbol_a<> filename_() const
	{
		return _filename;
	}

	inline std::string filename() const
	{
		return _filename.to_string();
	}

	inline number_data_a<int64_t> line_() const
	{
		return _line;
	}

	inline int64_t line() const
	{
		return _line.extract_primitive();
	}

	inline number_data_a<int64_t> position_() const
	{
		return _position;
	}

	inline int64_t position() const
	{
		return _position.extract_primitive();
	}

	inline symbol_a<> tag_() const
	{
		return _tag;
	}

	inline std::string tag() const
	{
		return _tag.to_string();
	}

	inline symbol_a<> symbol_() const
	{
		return _symbol;
	}

	inline std::string symbol() const
	{
		return _symbol.to_string();
	}

	inline any_a<> literal_() const
	{
		return _literal;
	}

	inline number_data_a<int64_t> precedence_() const
	{
		return _precedence;
	}

	inline int64_t precedence() const
	{
		return _precedence.extract_primitive();
	}

	inline misunderstanding_a<> report_() const
	{
		return mis(report());
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
		: thing_t<___ego___>{}
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
	auto& shoal = shared();
	token_t<___ego___>::share(shoal);
	return shoal;
}();

class ___token_t_share___
{
	static inline bool ___share___()
	{
		return token_t<>::___share___;
	}
};

} // namespace strange

#endif
