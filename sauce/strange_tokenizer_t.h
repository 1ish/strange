#ifndef COM_ONEISH_STRANGE_TOKENIZER_T_H
#define COM_ONEISH_STRANGE_TOKENIZER_T_H

namespace strange
{

template <typename ___ego___ = range_a<>>
class tokenizer_t : public thing_t<___ego___>
{
	template <typename _element, typename _iterator_, typename ___ego_it___ = forward_extractor_data_a<_element, _iterator_>>
	class extractor_t : public thing_t<___ego_it___>
	{
	public:
		// construction
		template <typename F>
		static inline forward_extractor_data_a<_element, _iterator_> create(river_a<> const& river, F&& it)
		{
			return forward_extractor_data_a<_element, _iterator_>::template create<extractor_t<_element, _iterator_>>(river, std::forward<F>(it));
		}

		// reflection
		static inline symbol_a<> type_()
		{
			static symbol_a<> TYPE = sym("strange::tokenizer::extractor");
			return TYPE;
		}

		static inline void share(shoal_a<>& shoal)
		{}

		// comparison
		inline bool same_(any_a<> const& thing) const
		{
			return type_() == thing.type_() &&
				_end == static_cast<extractor_t const&>(thing.extract_thing())._end;
		}

		inline bool operator==(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return same_(it);
		}

		inline bool operator!=(forward_extractor_data_a<_element, _iterator_> const& it) const
		{
			return !same_(it);
		}

		inline number_data_a<uint64_t> hash_() const
		{
			return num(uint64_t(hash()));
		}

		inline std_size_t hash() const
		{
			return std::hash<void const*>{}(&*_it);
		}

		// forward extractor
		inline _element get_() const
		{
			return _token;
		}

		inline _element const* operator->() const
		{
			return &operator*();
		}

		inline _element const& operator*() const
		{
			return _token;
		}

		inline void increment_()
		{
			if (!_end)
			{
				if (!_dot && !_use && _it == _river.extract_end_())
				{
					_end = true;
				}
				else
				{
					_token = next();
					if (!_dot && !_use && _it == _river.extract_end_() &&
						_token.tag() == "punctuation" && _token.symbol() == "")
					{
						_end = true;
					}
				}
			}
		}

		// data
		inline _iterator_ const& extract_it() const
		{
			return _it;
		}

		inline _iterator_& mutate_it()
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
			std_string token;

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
				else if (_it == _river.extract_end_())
				{
					break;
				}
				else
				{
					char1 = fast<number_data_a<int8_t>>(*_it).extract_primitive();
					++_it;
					++_position;
				}
				char2 = _it != _river.extract_end_() ? fast<number_data_a<int8_t>>(*_it).extract_primitive() : 0;

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
					continue;
				}
				else if (commentline)
				{
					if (char1 == '\n')
					{
						token = "";
						commentline = false;
					}
					continue;
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
						if ((char1 == '-' && num2) || numeric_char(char1))
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
						if (char1 == char2 || char2 == '=')
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
						if (char1 == char2 || char2 == '.' || char2 == '=' || char2 == '#' || char2 == '&' || char2 == '<' || char2 == '(')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '.':
						token = char1;
						if (char1 == char2 || char2 == ':')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '<':
						token = char1;
						if (char2 == '=' || char2 == '@' || char2 == '~')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '>':
						token = char1;
						if (char2 == '=' || char2 == '@')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '~':
						token = char1;
						if (char2 == '>' || char2 == ')' || char2 == ']' || char2 == '}')
						{
							second = true;
							break;
						}
						return punctuation_token(token);
					case '(':
					case '[':
					case '{':
						token = char1;
						if (char2 == '~')
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
					case '^':
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
						return punctuation_token(std_string(&char1, 1));
					}
				}
				if (!commentblock && !commentline)
				{
					first = false;
				}
			}
			if (commentline || token.empty())
			{
				return punctuation_token("");
			}
			return error_token(token);
		}

	protected:
		_iterator_ _it;
		river_a<> _river;
		bool _end;
		int64_t _line;
		int64_t _position;
		int64_t _start_line;
		int64_t _start_position;
		bool _dot;
		char _use;
		token_a<> mutable _token;

		friend class any_a<>;

		template <typename F>
		inline extractor_t(river_a<> const& river, F&& it)
			: thing_t<___ego_it___>{}
			, _it{ std::forward<F>(it) }
			, _river{ river }
			, _end{ _it == _river.extract_end_() }
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

		inline token_a<> symbol_token(std_string const& str) const
		{
			return token_t<>::create_symbol(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> lake_token(std_string const& str) const
		{
			return token_t<>::create_lake(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> int_token(std_string const& str) const
		{
			return token_t<>::create_int(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> float_token(std_string const& str) const
		{
			return token_t<>::create_float(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> name_token(std_string const& str) const
		{
			return token_t<>::create_name(_river.filename(), _start_line, _start_position, str);
		}

		inline token_a<> punctuation_token(std_string const& str) const
		{
			return token_t<>::create_punctuation(_river.filename(), _start_line, _start_position, str, _precedence_(str));
		}

		inline token_a<> error_token(std_string const& str) const
		{
			return token_t<>::create_error(_river.filename(), _line, _position, str);
		}
	};

public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("strange::tokenizer::create passed empty range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("strange::tokenizer::create passed non-river");
		}
		return create_(fast<river_a<>>(river));
	}

	static inline range_a<> create_(river_a<> const& river)
	{
		return range_a<>::create<tokenizer_t<>>(river);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::tokenizer");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::tokenizer::create"), native_function_create(&tokenizer_t<>::create__));
	}

	// range
	inline forward_extractor_a<any_a<>> extract_begin_() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_river, _river.extract_begin_());
	}

	inline forward_extractor_a<any_a<>> extract_end_() const
	{
		return extractor_t<any_a<>, forward_extractor_a<any_a<>>>::create(_river, _river.extract_end_());
	}

protected:
	river_a<> const _river;

	friend class any_a<>;

	inline tokenizer_t(river_a<> const& river)
		: thing_t<___ego___>{}
		, _river(river)
	{}

	static inline int64_t _precedence_(std_string const& str)
	{
		static auto PRECEDENCE = []()
		{
			auto precedence = unordered_shoal_t<>::create_();
			precedence.update(sym("@?"), number_int_64_t<>::create(85));
			precedence.update(sym("@"), number_int_64_t<>::create(85));
			precedence.update(sym("@="), number_int_64_t<>::create(85));
			precedence.update(sym("@+"), number_int_64_t<>::create(85));
			precedence.update(sym("@-"), number_int_64_t<>::create(85));
			precedence.update(sym("@<"), number_int_64_t<>::create(85));
			precedence.update(sym(">@"), number_int_64_t<>::create(85));
			precedence.update(sym("@>"), number_int_64_t<>::create(85));
			precedence.update(sym("<@"), number_int_64_t<>::create(85));
			precedence.update(sym("++"), number_int_64_t<>::create(80));
			precedence.update(sym("--"), number_int_64_t<>::create(80));
			precedence.update(sym("?"), number_int_64_t<>::create(80));
			precedence.update(sym("!"), number_int_64_t<>::create(80));
			precedence.update(sym("#"), number_int_64_t<>::create(80));
			precedence.update(sym("*"), number_int_64_t<>::create(75));
			precedence.update(sym("/"), number_int_64_t<>::create(75));
			precedence.update(sym("%"), number_int_64_t<>::create(75));
			precedence.update(sym("+"), number_int_64_t<>::create(70));
			precedence.update(sym("-"), number_int_64_t<>::create(70));
			precedence.update(sym("<"), number_int_64_t<>::create(65));
			precedence.update(sym(">"), number_int_64_t<>::create(65));
			precedence.update(sym("<="), number_int_64_t<>::create(65));
			precedence.update(sym(">="), number_int_64_t<>::create(65));
			precedence.update(sym("=="), number_int_64_t<>::create(60));
			precedence.update(sym("!="), number_int_64_t<>::create(60));
			precedence.update(sym("|"), number_int_64_t<>::create(55));
			precedence.update(sym("&&"), number_int_64_t<>::create(50));
			precedence.update(sym("!&"), number_int_64_t<>::create(50));
			precedence.update(sym("%%"), number_int_64_t<>::create(45));
			precedence.update(sym("!%"), number_int_64_t<>::create(45));
			precedence.update(sym("||"), number_int_64_t<>::create(40));
			precedence.update(sym("!|"), number_int_64_t<>::create(40));
			precedence.update(sym("="), number_int_64_t<>::create(35));
			precedence.update(sym("+="), number_int_64_t<>::create(35));
			precedence.update(sym("-="), number_int_64_t<>::create(35));
			precedence.update(sym("*="), number_int_64_t<>::create(35));
			precedence.update(sym("/="), number_int_64_t<>::create(35));
			precedence.update(sym("%="), number_int_64_t<>::create(35));
			return precedence;
		}();
		auto p = PRECEDENCE.at_(sym(str));
		if (p)
		{
			return fast<number_data_a<int64_t>>(p).extract_primitive();
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
	auto& shoal = shared();
	tokenizer_t<___ego___>::share(shoal);
	return shoal;
}();

class ___tokenizer_t_share___
{
	static inline bool ___share___()
	{
		return tokenizer_t<>::___share___;
	}
};

} // namespace strange

#endif
