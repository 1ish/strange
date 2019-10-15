#ifndef COM_ONEISH_STRANGE_TOKENIZER_T_H
#define COM_ONEISH_STRANGE_TOKENIZER_T_H

namespace strange
{

template <typename ___ego___ = range_a<>>
class tokenizer_t : public thing_t<___ego___>
{
	template <typename _iterator_, typename ___ego___ = forward_const_iterator_data_a<_iterator_>>
	class const_iterator_t : public thing_t<___ego___>
	{
	public:
		// override
		using over = thing_o<const_iterator_t<_iterator_>>;

		// construction
		template <typename F>
		static inline forward_const_iterator_data_a<_iterator_> create(river_a<> const& river, F&& it)
		{
			return forward_const_iterator_data_a<_iterator_>{ over{ const_iterator_t<_iterator_>(river, std::forward<F>(it)) } };
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::tokenizer::const_iterator");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool operator==(any_a<> const& thing) const
		{
			if (!check<forward_const_iterator_data_a<_iterator_>>(thing))
			{
				return false;
			}
			return _it == cast<forward_const_iterator_data_a<_iterator_>>(thing).extract();
		}

		inline std::size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward iterator
		inline any_a<> get__(range_a<> const&) const
		{
			return get_();
		}

		inline any_a<> get_() const
		{
			return _token;
		}

		inline any_a<> const* operator->() const
		{
			return &operator*();
		}

		inline any_a<> const& operator*() const
		{
			return _token;
		}

		inline ___ego___ increment__(range_a<> const&)
		{
			return increment_();
		}

		inline ___ego___ increment_()
		{
			operator++();
			return me_();
		}

		inline const_iterator_t& operator++()
		{
			_token = next();
			return *this;
		}

		inline const_iterator_t operator++(int)
		{
			const_iterator_t result = *this;
			operator++();
			return result;
		}

		// data
		inline _iterator_ const& extract() const
		{
			return _it;
		}

		inline void mutate(_iterator_ const& it)
		{
			_it = it;
		}

		inline _iterator_& reference()
		{
			return _it;
		}

		// next token
		inline token_a<> next()
		{
			_start_line = _line;
			_start_position = _position;
			if (!_dot && !_use)
			{
				++_start_position;
			}
			if (_it == _river.cend_())
			{
				return punctuation_token("");
			}
			bool alphanumeric = false;
			bool numeric = false;
			bool point = false;
			bool exponent = false;
			bool second = false;
			bool singlequote = false;
			bool doublequote = false;
			bool escape = false;
			bool commentblock = false;
			bool commentline = false;
			std::string token;

			for (bool first = true;;)
			{
				char char1;
				char char2;
				if (_dot)
				{
					char1 = '.';
					_dot = false;
				}
				else if (_use)
				{
					char1 = _use;
					_use = 0;
				}
				else if (!_river.good())
				{
					break;
				}
				else
				{
					char1 = _river.get();
					if (!_river.good())
					{
						break;
					}
					++_position;
				}
				char2 = _river.good() ? _river.peek() : 0;
				if (!_river.good())
				{
					char2 = 0;
				}

				if (char1 == '\n')
				{
					_position = 0;
					++_line;
				}
				else if (char1 == '\t')
				{
					_position = ((_position + 3) / 4) * 4;
				}

				if (commentblock)
				{
					if (second)
					{
						token = "";
						commentblock = false;
					}
					second = (char1 == '*' && char2 == '/');
				}
				else if (commentline)
				{
					if (char1 == '\n')
					{
						token = "";
						commentline = false;
					}
				}
				else if (escape)
				{
					switch (char1)
					{
					case 'a':
						token += '\a';
						break;
					case 'b':
						token += '\b';
						break;
					case 'f':
						token += '\f';
						break;
					case 'n':
						token += '\n';
						break;
					case 'r':
						token += '\r';
						break;
					case 't':
						token += '\t';
						break;
					case 'v':
						token += '\v';
						break;
					default:
						token += char1;
					}
					escape = false;
				}
				else if (second)
				{
					if (char1 == '=' && char2 == '=' && token == "!") // !==
					{
						_use = char1; // =
						return punctuation_token(token); // !
					}
					return punctuation_token(token + char1);
				}
				else if (singlequote && char1 == '\'')
				{
					return symbol_token(token);
				}
				else if (doublequote && char1 == '\"')
				{
					return lake_token(token);
				}
				else if (singlequote || doublequote)
				{
					if (char1 == '\\')
					{
						escape = true;
					}
					else
					{
						token += char1;
					}
				}
				else
				{
					bool const num2 = numeric_char(char2);
					if (first)
					{
						if (char1 == '-' && num2 || numeric_char(char1))
						{
							numeric = true;
						}
						else if (alpha_char(char1))
						{
							alphanumeric = true;
						}
					}
					if (numeric)
					{
						token += char1;
						bool const exp1 = (char1 == 'E' || char1 == 'e');
						bool const exp2 = (char2 == 'E' || char2 == 'e');
						bool const pnt1 = (char1 == '.');
						bool const pnt2 = (char2 == '.');
						bool const sig2 = (char2 == '+' || char2 == '-');
						if (exp1)
						{
							exponent = true;
							point = true;
						}
						else if (pnt1)
						{
							point = true;
						}
						if (!num2 &&
							(!pnt2 || (pnt2 && point)) &&
							(!exp2 || (exp2 && exponent)) &&
							(!sig2 || (sig2 && !exp1)))
						{
							// end of numeric token
							if (point || exponent)
							{
								if (pnt1)
								{
									_dot = true;
									return int_token(token.substr(0, token.length() - 1));
								}
								if (exp1)
								{
									_use = char1;
									if (point)
									{
										if (token[token.length() - 2] == '.')
										{
											_dot = true;
											return int_token(token.substr(0, token.length() - 2));
										}
										return float_token(token.substr(0, token.length() - 1));
									}
									return int_token(token.substr(0, token.length() - 1));
								}
								return float_token(token);
							}
							return int_token(token);
						}
					}
					else if (alphanumeric)
					{
						token += char1;
						if (!num2 && !alpha_char(char2))
						{
							// end of alphanumeric token
							return name_token(token);
						}
					}
					else if (char1 == ' ' || char1 == '\n' || char1 == '\t' || char1 == '\r')
					{
						// skip whitespace
						_start_line = _line;
						_start_position = _position + 1;
						continue;
					}
					else switch (char1)
					{
					case '\'':
						singlequote = true;
						break;
					case '\"':
						doublequote = true;
						break;
					case '+':
					case '-':
					case '*':
					case '%':
						token = char1;
						if (char1 == char2 || char2 == '=' || char2 == '<' || char2 == '{')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '!':
						token = char1;
						if (char2 == '&' || char2 == '|' || char2 == '%' || char2 == '=')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case ':':
						token = char1;
						if (char1 == char2 || char2 == '.' || char2 == '=' || char2 == '#' || char2 == '<' || char2 == '{')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '.':
						token = char1;
						if (char2 == ':')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '<':
						token = char1;
						if (char2 == '=' || char2 == '@')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '>':
						token = char1;
						if (char2 == '=' || char2 == '@' || char2 == '#')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '@':
						token = char1;
						if (char2 == '?' || char2 == '=' || char2 == '+' || char2 == '-' || char2 == '<' || char2 == '>')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '&':
					case '|':
					case '$':
					case '=':
						token = char1;
						if (char1 == char2)
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '/':
						token = char1;
						if (char2 == '=')
						{
							second = true;
							break;
						}
						if (char2 == '*')
						{
							commentblock = true;
							break;
						}
						if (char2 == '/')
						{
							commentline = true;
							break;
						}
						return punctuation_token(token);
					default:
						// single character punctuation
						return punctuation_token(std::string(&char1, 1));
					}
				}
				first = false;
			}
			if (commentline || token.empty())
			{
				if (!_river.good() && _it != _river.cend_())
				{
					++_it;
				}
				return punctuation_token("");
			}
			return error_token(token);
		}

	protected:
		_iterator_ _it;
		river_a<> _river;
		int64_t _line;
		int64_t _position;
		int64_t _start_line;
		int64_t _start_position;
		bool _dot;
		char _use;
		mutable token_a<> _token;

		template <typename F>
		inline const_iterator_t(river_a<> const& river, F&& it)
			: thing_t{}
			, _it{ std::forward<F>(it) }
			, _river(river, true)
			, _line{ 1 }
			, _position{ 0 }
			, _start_line{ 1 }
			, _start_position{ 0 }
			, _dot{ false }
			, _use{ 0 }
			, _token{ next() }
		{}

		static inline bool alpha_char(char c)
		{
			return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
		}

		static inline bool numeric_char(char c)
		{
			return c >= '0' && c <= '9';
		}

		inline token_a<> symbol_token(std::string const& str) const
		{
			return token_t<>::create_symbol(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> lake_token(std::string const& str) const
		{
			return token_t<>::create_lake(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> int_token(std::string const& str) const
		{
			return token_t<>::create_int(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> float_token(std::string const& str) const
		{
			return token_t<>::create_float(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> name_token(std::string const& str) const
		{
			return token_t<>::create_name(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> punctuation_token(std::string const& str) const
		{
			return token_t<>::create_punctuation(_river.filename(), _start_line, _start_position, str, _precedence_(str));
		}

		inline token_a<> error_token(std::string const& str) const
		{
			return token_t<>::create_error(_river.filename(), _line, _position, str);
		}
	};

public:
	// override
	using over = range_o<tokenizer_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::tokenizer::create passed empty range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("strange::tokenizer::create passed non-river");
		}
		return create_(cast<river_a<>>(river));
	}

	static inline range_a<> create_(river_a<> const& river)
	{
		return range_a<>{ over{ tokenizer_t<>(river) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<tokenizer_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<tokenizer_t<>>::share(shoal);
	}

	// range
	inline forward_const_iterator_a<> cbegin_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::create(_river, _river.cbegin_());
	}

	inline forward_const_iterator_a<> cend_() const
	{
		return const_iterator_t<forward_const_iterator_a<>>::create(_river, _river.cend_());
	}

protected:
	river_a<> _river;

	inline tokenizer_t(river_a<> const& river)
		: thing_t{}
		, _river(river)
	{}

	static inline int64_t _precedence_(std::string const& str)
	{
		static auto PRECEDENCE = []()
		{
			auto precedence = unordered_shoal_t<>::create_();
			precedence.update_string("@?", number_int_64_t<>::create(85));
			precedence.update_string("@", number_int_64_t<>::create(85));
			precedence.update_string("@=", number_int_64_t<>::create(85));
			precedence.update_string("@+", number_int_64_t<>::create(85));
			precedence.update_string("@-", number_int_64_t<>::create(85));
			precedence.update_string("@<", number_int_64_t<>::create(85));
			precedence.update_string(">@", number_int_64_t<>::create(85));
			precedence.update_string("@>", number_int_64_t<>::create(85));
			precedence.update_string("<@", number_int_64_t<>::create(85));
			precedence.update_string("++", number_int_64_t<>::create(80));
			precedence.update_string("--", number_int_64_t<>::create(80));
			precedence.update_string("?", number_int_64_t<>::create(80));
			precedence.update_string("!", number_int_64_t<>::create(80));
			precedence.update_string("*", number_int_64_t<>::create(75));
			precedence.update_string("/", number_int_64_t<>::create(75));
			precedence.update_string("%", number_int_64_t<>::create(75));
			precedence.update_string("+", number_int_64_t<>::create(70));
			precedence.update_string("-", number_int_64_t<>::create(70));
			precedence.update_string("<", number_int_64_t<>::create(65));
			precedence.update_string(">", number_int_64_t<>::create(65));
			precedence.update_string("<=", number_int_64_t<>::create(65));
			precedence.update_string(">=", number_int_64_t<>::create(65));
			precedence.update_string("==", number_int_64_t<>::create(60));
			precedence.update_string("!=", number_int_64_t<>::create(60));
			precedence.update_string("&&", number_int_64_t<>::create(55));
			precedence.update_string("!&", number_int_64_t<>::create(55));
			precedence.update_string("%%", number_int_64_t<>::create(50));
			precedence.update_string("!%", number_int_64_t<>::create(50));
			precedence.update_string("||", number_int_64_t<>::create(45));
			precedence.update_string("!|", number_int_64_t<>::create(45));
			precedence.update_string("=", number_int_64_t<>::create(40));
			precedence.update_string("+=", number_int_64_t<>::create(40));
			precedence.update_string("-=", number_int_64_t<>::create(40));
			precedence.update_string("*=", number_int_64_t<>::create(40));
			precedence.update_string("/=", number_int_64_t<>::create(40));
			precedence.update_string("%=", number_int_64_t<>::create(40));
			return precedence;
		}();
		auto p = PRECEDENCE.at_(sym(str));
		if (p)
		{
			return cast<number_data_a<int64_t>>(p).extract();
		}
		return 0;
	}

private:
	static bool const ___share___;
	friend class ___tokenizer_t_share___;
};

template <typename ___ego___>
bool const tokenizer_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	tokenizer_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
