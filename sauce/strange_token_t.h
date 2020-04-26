#ifndef COM_ONEISH_STRANGE_TOKEN_T_H
#define COM_ONEISH_STRANGE_TOKEN_T_H

namespace strange
{

template <typename ___ego___ = token_a<>>
class token_t : public thing_t<___ego___>
{
	using create_member = token_a<>(*)(symbol_a<> const&, number_data_a<int64_t> const&, number_data_a<int64_t> const&, symbol_a<> const&, number_data_a<int64_t> const&);

public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		auto it = list.begin_();
		auto end = list.end_();
		if (it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed empty list");
		}
		any_a<> filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed non-symbol filename");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed short list");
		}
		any_a<> line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed non-number-int-64 line");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed short list");
		}
		any_a<> position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed non-number-int-64 position");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed short list");
		}
		any_a<> tag = *it;
		if (!check<symbol_a<>>(tag))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed non-symbol tag");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed short list");
		}
		any_a<> symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed non-symbol symbol");
		}
		if (++it == end)
		{
			return create_(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(tag), fast<symbol_a<>>(symbol));
		}
		any_a<> literal = *it;
		if (++it == end)
		{
			return create_(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(tag), fast<symbol_a<>>(symbol), literal);
		}
		any_a<> precedence = *it;
		if (!check<number_data_a<int64_t>>(precedence))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create passed non-int-64 precedence");
		}
		return create_(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(tag), fast<symbol_a<>>(symbol), literal, fast<number_data_a<int64_t>>(precedence));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol)
	{
		return create_(filename, line, position, tag, symbol, symbol, number_int_64_t<>::create(-1));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal)
	{
		return token_a<>::create<token_t<>>(filename, line, position, tag, symbol, literal, number_int_64_t<>::create(-1));
	}

	static inline token_a<> create_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal, number_data_a<int64_t> const& precedence)
	{
		return token_a<>::create<token_t<>>(filename, line, position, tag, symbol, literal, precedence);
	}

	static inline token_a<> create(std_string const& tag, list_a<> const& list, create_member member)
	{
		auto it = list.begin_();
		auto end = list.end_();
		if (it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed empty list");
		}
		auto const filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed non-symbol filename");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + "passed short list");
		}
		auto const line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed non-number-int-64 line");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed short list");
		}
		auto const position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed non-number-int-64 position");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed short list");
		}
		auto const symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed non-symbol symbol");
		}
		if (++it == end)
		{
			return member(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(symbol), number_int_64_t<>::create(-1));
		}
		auto const precedence = *it;
		if (!check<number_data_a<int64_t>>(precedence))
		{
			throw dis(__FILE__, __LINE__, "strange::token::create_" + tag + " passed non-int-64 precedence");
		}
		return member(fast<symbol_a<>>(filename), fast<number_data_a<int64_t>>(line), fast<number_data_a<int64_t>>(position), fast<symbol_a<>>(symbol), fast<number_data_a<int64_t>>(precedence));
	}

	static inline any_a<> create_symbol__(list_a<> const& list)
	{
		return create("symbol", list, &create_symbol_);
	}
	
	static inline token_a<> create_symbol_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("symbol"), symbol);
	}

	static inline token_a<> create_symbol(std_string const& filename, int64_t line, int64_t position, std_string const& symbol)
	{
		return create_symbol_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_lake__(list_a<> const& list)
	{
		return create("lake", list, &create_lake_);
	}

	static inline token_a<> create_lake_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("lake"), symbol, lake_from_string(symbol.to_string()));
	}

	static inline token_a<> create_lake(std_string const& filename, int64_t line, int64_t position, std_string const& symbol)
	{
		return create_lake_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_int__(list_a<> const& list)
	{
		return create("int", list, &create_int_);
	}

	static inline token_a<> create_int_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("int"), symbol, int_64_from_string(symbol.to_string()));
	}

	static inline token_a<> create_int(std_string const& filename, int64_t line, int64_t position, std_string const& symbol)
	{
		return create_int_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_float__(list_a<> const& list)
	{
		return create("float", list, &create_float_);
	}

	static inline token_a<> create_float_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("float"), symbol, float_64_from_string(symbol.to_string()));
	}

	static inline token_a<> create_float(std_string const& filename, int64_t line, int64_t position, std_string const& symbol)
	{
		return create_float_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_name__(list_a<> const& list)
	{
		return create("name", list, &create_name_);
	}

	static inline token_a<> create_name_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("name"), symbol);
	}

	static inline token_a<> create_name(std_string const& filename, int64_t line, int64_t position, std_string const& symbol)
	{
		return create_name_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol));
	}

	static inline any_a<> create_punctuation__(list_a<> const& list)
	{
		return create("punctuation", list, &create_punctuation_);
	}

	static inline token_a<> create_punctuation_()
	{
		return create_punctuation("", 0, 0, "", 0);
	}

	static inline token_a<> create_punctuation_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& precedence)
	{
		return create_(filename, line, position, sym("punctuation"), symbol, symbol, precedence);
	}

	static inline token_a<> create_punctuation(std_string const& filename, int64_t line, int64_t position, std_string const& symbol, int64_t precedence)
	{
		return create_punctuation_(sym(filename), number_int_64_t<>::create(line), number_int_64_t<>::create(position), sym(symbol), number_int_64_t<>::create(precedence));
	}

	static inline any_a<> create_error__(list_a<> const& list)
	{
		return create("error", list, &create_error_);
	}

	static inline token_a<> create_error_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol, number_data_a<int64_t> const& = number_int_64_t<>::create_())
	{
		return create_(filename, line, position, sym("error"), symbol);
	}

	static inline token_a<> create_error(std_string const& filename, int64_t line, int64_t position, std_string const& symbol)
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
		shoal.update(sym("strange::token::create"), native_function_create(&token_t<>::create__));
		shoal.update(sym("strange::token::create_symbol"), native_function_create(&token_t<>::create_symbol__));
		shoal.update(sym("strange::token::create_lake"), native_function_create(&token_t<>::create_lake__));
		shoal.update(sym("strange::token::create_int"), native_function_create(&token_t<>::create_int__));
		shoal.update(sym("strange::token::create_float"), native_function_create(&token_t<>::create_float__));
		shoal.update(sym("strange::token::create_name"), native_function_create(&token_t<>::create_name__));
		shoal.update(sym("strange::token::create_punctuation"), native_function_create(&token_t<>::create_punctuation__));
		shoal.update(sym("strange::token::create_error"), native_function_create(&token_t<>::create_error__));
	}

	// token
	inline symbol_a<> filename_() const
	{
		return _filename;
	}

	inline std_string filename() const
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

	inline std_string tag() const
	{
		return _tag.to_string();
	}

	inline symbol_a<> symbol_() const
	{
		return _symbol;
	}

	inline std_string symbol() const
	{
		return _symbol.to_string();
	}

	inline any_a<> literal_() const
	{
		return _literal;
	}

	inline bool literal() const
	{
		return bool{ _literal };
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

	inline std_string report() const
	{
		return filename() + "(" + std_to_string(line()) + "," + std_to_string(position()) + "): " + tag() + " '" + symbol() + "'\n";
	}

protected:
	symbol_a<> const _filename;
	number_data_a<int64_t> const _line;
	number_data_a<int64_t> const _position;
	symbol_a<> const _tag;
	symbol_a<> const _symbol;
	any_a<> const _literal;
	number_data_a<int64_t> const _precedence;

	friend class any_a<>;

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
