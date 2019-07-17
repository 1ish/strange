#ifndef COM_ONEISH_STRANGE_TOKEN_T_H
#define COM_ONEISH_STRANGE_TOKEN_T_H

namespace strange
{

template <typename _ABSTRACTION_ = token_a<>>
class token_t : public thing_t<_ABSTRACTION_>
{
	using val_member = token_a<>(*)(symbol_a<> const&, number_data_a<int64_t> const&, number_data_a<int64_t> const&, symbol_a<> const&);

public:
	// override
	using over = thing_o<token_t<>>;

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
		any_a<> position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis("strange::token::val passed non-number-int-64 position");
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
			return val_(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(tag), cast<symbol_a<>>(symbol));
		}
		return val_(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(tag), cast<symbol_a<>>(symbol), *it);
	}

	static inline token_a<> val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, tag, symbol, symbol);
	}

	static inline token_a<> val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal)
	{
		return token_a<>{ over{ token_t<>(filename, line, position, tag, symbol, literal) } };
	}

	static inline token_a<> val(std::string const& tag, range_a<> const& range, val_member member)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::token::" + tag + "_val passed empty range");
		}
		any_a<> filename = *it;
		if (!check<symbol_a<>>(filename))
		{
			throw dis("strange::token::" + tag + "_val passed non-symbol filename");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::" + tag + "_val passed short range");
		}
		any_a<> line = *it;
		if (!check<number_data_a<int64_t>>(line))
		{
			throw dis("strange::token::" + tag + "_val passed non-number-int-64 line");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::" + tag + "_val passed short range");
		}
		any_a<> position = *it;
		if (!check<number_data_a<int64_t>>(position))
		{
			throw dis("strange::token::" + tag + "_val passed non-number-int-64 position");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::token::" + tag + "_val passed short range");
		}
		any_a<> symbol = *it;
		if (!check<symbol_a<>>(symbol))
		{
			throw dis("strange::token::" + tag + "_val passed non-symbol symbol");
		}
		return member(cast<symbol_a<>>(filename), cast<number_data_a<int64_t>>(line), cast<number_data_a<int64_t>>(position), cast<symbol_a<>>(symbol));
	}

	static inline any_a<> symbol_val__(range_a<> const& range)
	{
		return val("symbol", range, &symbol_val_);
	}
	
	static inline token_a<> symbol_val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, sym("symbol"), symbol);
	}

	static inline token_a<> symbol_val(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return symbol_val_(sym(filename), number_int_64_t<>::val(line), number_int_64_t<>::val(position), sym(symbol));
	}

	static inline any_a<> lake_val__(range_a<> const& range)
	{
		return val("lake", range, &lake_val_);
	}

	static inline token_a<> lake_val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, sym("lake"), symbol, lake_from_string(symbol.to_string()));
	}

	static inline token_a<> lake_val(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return lake_val_(sym(filename), number_int_64_t<>::val(line), number_int_64_t<>::val(position), sym(symbol));
	}

	static inline any_a<> int_val__(range_a<> const& range)
	{
		return val("int", range, &int_val_);
	}

	static inline token_a<> int_val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, sym("int"), symbol, int_64_from_string(symbol.to_string()));
	}

	static inline token_a<> int_val(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return int_val_(sym(filename), number_int_64_t<>::val(line), number_int_64_t<>::val(position), sym(symbol));
	}

	static inline any_a<> float_val__(range_a<> const& range)
	{
		return val("float", range, &float_val_);
	}

	static inline token_a<> float_val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, sym("float"), symbol, float_64_from_string(symbol.to_string()));
	}

	static inline token_a<> float_val(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return float_val_(sym(filename), number_int_64_t<>::val(line), number_int_64_t<>::val(position), sym(symbol));
	}

	static inline any_a<> name_val__(range_a<> const& range)
	{
		return val("name", range, &name_val_);
	}

	static inline token_a<> name_val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, sym("name"), symbol);
	}

	static inline token_a<> name_val(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return name_val_(sym(filename), number_int_64_t<>::val(line), number_int_64_t<>::val(position), sym(symbol));
	}

	static inline any_a<> punctuation_val__(range_a<> const& range)
	{
		return val("punctuation", range, &punctuation_val_);
	}

	static inline token_a<> punctuation_val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, sym("punctuation"), symbol);
	}

	static inline token_a<> punctuation_val(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return punctuation_val_(sym(filename), number_int_64_t<>::val(line), number_int_64_t<>::val(position), sym(symbol));
	}

	static inline any_a<> error_val__(range_a<> const& range)
	{
		return val("error", range, &error_val_);
	}

	static inline token_a<> error_val_(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& symbol)
	{
		return val_(filename, line, position, sym("error"), symbol);
	}

	static inline token_a<> error_val(std::string const& filename, int64_t line, int64_t position, std::string const& symbol)
	{
		return error_val_(sym(filename), number_int_64_t<>::val(line), number_int_64_t<>::val(position), sym(symbol));
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
	inline any_a<> filename__(range_a<> const& _) const
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

	inline any_a<> line__(range_a<> const& _) const
	{
		return line_();
	}

	inline number_data_a<int64_t> line_() const
	{
		return _line;
	}

	inline int64_t line() const
	{
		return _line.extract();
	}

	inline any_a<> position__(range_a<> const& _) const
	{
		return position_();
	}

	inline number_data_a<int64_t> position_() const
	{
		return _position;
	}

	inline int64_t position() const
	{
		return _position.extract();
	}

	inline any_a<> tag__(range_a<> const& _) const
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

	inline any_a<> symbol__(range_a<> const& _) const
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

	inline any_a<> literal__(range_a<> const& _) const
	{
		return literal_();
	}

	inline any_a<> literal_() const
	{
		return _literal;
	}

	inline any_a<> precedence__(range_a<> const& _) const
	{
		return precedence_();
	}

	inline number_data_a<int64_t> precedence_() const
	{
		return _precedence;
	}

	inline int64_t precedence() const
	{
		return _precedence.extract();
	}

	inline any_a<> report__(range_a<> const& _) const
	{
		return report_();
	}

	inline misunderstanding_a<> report_() const
	{
		return misunderstanding_t<>::val(report());
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

	inline token_t(symbol_a<> const& filename, number_data_a<int64_t> const& line, number_data_a<int64_t> const& position, symbol_a<> const& tag, symbol_a<> const& symbol, any_a<> const& literal)
		: thing_t{}
		, _filename{ filename }
		, _line{ line }
		, _position{ position }
		, _tag{ tag }
		, _symbol{ symbol }
		, _literal{ literal }
		, _precedence{ _precedence_(tag, symbol) }
	{}

	static inline number_data_a<int64_t> _precedence_(symbol_a<> const& tag, symbol_a<> const& symbol)
	{
		if (tag.is("punctuation"))
		{
			static auto PRECEDENCE = []()
			{
				auto precedence = unordered_shoal_t<>::val_();
				precedence.update_string(":.", number_int_64_t<>::val(100));
				precedence.update_string(".", number_int_64_t<>::val(95));
				precedence.update_string(".:", number_int_64_t<>::val(95));
				precedence.update_string("[", number_int_64_t<>::val(90));
				precedence.update_string("(", number_int_64_t<>::val(90));
				precedence.update_string("{", number_int_64_t<>::val(90));
				precedence.update_string("<<", number_int_64_t<>::val(90));
				precedence.update_string("@", number_int_64_t<>::val(85));
				precedence.update_string("@=", number_int_64_t<>::val(85));
				precedence.update_string("@+", number_int_64_t<>::val(85));
				precedence.update_string("@-", number_int_64_t<>::val(85));
				precedence.update_string("@<", number_int_64_t<>::val(85));
				precedence.update_string(">@", number_int_64_t<>::val(85));
				precedence.update_string("@>", number_int_64_t<>::val(85));
				precedence.update_string("<@", number_int_64_t<>::val(85));
				precedence.update_string("@@", number_int_64_t<>::val(85));
				precedence.update_string("@:", number_int_64_t<>::val(85));
				precedence.update_string("++", number_int_64_t<>::val(80));
				precedence.update_string("--", number_int_64_t<>::val(80));
				precedence.update_string("?", number_int_64_t<>::val(80));
				precedence.update_string("!", number_int_64_t<>::val(80));
				precedence.update_string("*", number_int_64_t<>::val(75));
				precedence.update_string("/", number_int_64_t<>::val(75));
				precedence.update_string("%", number_int_64_t<>::val(75));
				precedence.update_string("+", number_int_64_t<>::val(70));
				precedence.update_string("-", number_int_64_t<>::val(70));
				precedence.update_string("<", number_int_64_t<>::val(65));
				precedence.update_string(">", number_int_64_t<>::val(65));
				precedence.update_string("<=", number_int_64_t<>::val(65));
				precedence.update_string(">=", number_int_64_t<>::val(65));
				precedence.update_string("==", number_int_64_t<>::val(60));
				precedence.update_string("!=", number_int_64_t<>::val(60));
				precedence.update_string("&&", number_int_64_t<>::val(55));
				precedence.update_string("!&", number_int_64_t<>::val(55));
				precedence.update_string("%%", number_int_64_t<>::val(50));
				precedence.update_string("!%", number_int_64_t<>::val(50));
				precedence.update_string("||", number_int_64_t<>::val(45));
				precedence.update_string("!|", number_int_64_t<>::val(45));
				precedence.update_string("=", number_int_64_t<>::val(40));
				precedence.update_string("+=", number_int_64_t<>::val(40));
				precedence.update_string("-=", number_int_64_t<>::val(40));
				precedence.update_string("*=", number_int_64_t<>::val(40));
				precedence.update_string("/=", number_int_64_t<>::val(40));
				precedence.update_string("%=", number_int_64_t<>::val(40));
				return precedence;
			}();
			auto p = PRECEDENCE.at_(symbol);
			if (p)
			{
				return cast<number_data_a<int64_t>>(p);
			}
		}
		return number_int_64_t<>::val(-1);
	}

private:
	static bool const ___share___;
	friend class ___token_t_share___;
};

template <typename _ABSTRACTION_>
bool const token_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	token_t<_ABSTRACTION_>::share(shoal);
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
