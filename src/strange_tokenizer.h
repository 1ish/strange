#ifndef COM_ONEISH_STRANGE_TOKENIZER_H
#define COM_ONEISH_STRANGE_TOKENIZER_H

#include "strange_core.h"
#include "strange_token.h"

namespace strange
{
	class Tokenizer;

	// Categories:
	// private typedefs
	// protected typedefs
	// public typedefs
	// public static utility functions
	// public static factory functions
	// public static symbols
	// public construction/destruction/assignment
	// public pure virtual member functions and adapters
	// public impure virtual member functions and adapters
	// public non-virtual member functions and adapters
	// protected static utility functions
	// protected static factory functions
	// protected static symbols
	// protected construction/destruction/assignment
	// protected pure virtual member functions and adapters
	// protected impure virtual member functions and adapters
	// protected non-virtual member functions and adapters
	// private static utility functions
	// private static factory functions
	// private static symbols
	// private construction/destruction/assignment
	// private pure virtual member functions and adapters
	// private impure virtual member functions and adapters
	// private non-virtual member functions and adapters

//----------------------------------------------------------------------
class Tokenizer : public Mutable
//----------------------------------------------------------------------
{
public:
	inline Tokenizer(const Ptr& river)
		: Mutable{}
		, _river{ river }
		, _filename{ static_<River>(river)->filename_() }
	{
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr& river)
	{
		return make_<Tokenizer>(river);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Tokenizer::mut, "river"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	inline const bool good_()
	{
		River* const river = dynamic_<River>(_river);
		if (river)
		{
			return river->good_();
		}
		return !_river->invoke_("good")->is_nothing_();
	}

	inline const Ptr good(const Ptr& ignore)
	{
		River* const river = dynamic_<River>(_river);
		if (river)
		{
			return river->good(ignore);
		}
		return _river->invoke_("good");
	}

	virtual inline const Ptr next_() override
	{
		River* const river = dynamic_<River>(_river);
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
		bool clone = false;
		std::string token;
		while (true)
		{
			char char1;
			char char2;
			if (river)
			{
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
				else if (!river->good_())
				{
					break;
				}
				else
				{
					char1 = river->get_();
					if (!river->good_())
					{
						break;
					}
					++_x;
				}
				char2 = river->good_() ? river->peek_() : 0;
				if (!river->good_())
				{
					char2 = 0;
				}
			}
			else
			{
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
				else if (!good_())
				{
					break;
				}
				else
				{
					const Ptr river_get = _river->invoke_("get");
					if (!good_())
					{
						break;
					}
					Int8* const byte1 = dynamic_<Int8>(river_get);
					if (!byte1)
					{
						break;
					}
					char1 = byte1->get_();
					++_x;
				}
				const Ptr river_peek = _river->invoke_("peek");
				Int8* const byte2 = good_() ? dynamic_<Int8>(river_peek) : 0;
				char2 = byte2 ? byte2->get_() : 0;
			}

			if (char1 == '\n')
			{
				_x = 0;
				++_y;
			}

			if (clone)
			{
				if (token == "~~")
				{
					if (char2 == '#') // ~~##
					{
						token += char1; // ~~#
						continue;
					}
					// ~~#.
					_use = char1; // #
					return Token::punctuation_(_filename, _x, _y, token); // ~~
				}
				// ~~##.
				return Token::punctuation_(_filename, _x, _y, token + char1); // ~~##
			}

			if (commentblock)
			{
				if (second)
				{
					commentblock = false;
				}
				second = (char1 == '*' && char2 == '/');
			}
			else if (commentline)
			{
				if (char1 == '\n')
				{
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
				if (char1 == '=' && char2 == '=' && (token == "!" || token == "#")) // !== or #==
				{
					_use = char1; // =
					return Token::punctuation_(_filename, _x, _y, token); // ! or #
				}
				if (char1 == '~' && char2 == '#' && token == "~") // ~~#
				{
					token += char1; // ~~
					clone = true;
					continue;
				}
				return Token::punctuation_(_filename, _x, _y, token + char1);
			}
			else if (singlequote && char1 == '\'')
			{
				return Token::symbol_(_filename, _x, _y, token + char1);
			}
			else if (doublequote && char1 == '\"')
			{
				return Token::lake_(_filename, _x, _y, token + char1);
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
			else switch (char1)
			{
			case ' ':
			case '\n':
			case '\t':
			case '\r':
				// skip whitespace
				break;
			case '\'':
				token = char1;
				singlequote = true;
				break;
			case '\"':
				token = char1;
				doublequote = true;
				break;
			case '!':
				if (char2 == '&' || char2 == '|' || char2 == '%')
				{
					second = true;
				}
			case '+':
			case '-':
			case '*':
			case '%':
			case ':':
			case '#':
				if ((char1 != '!' && char1 == char2) || char2 == '=')
				{
					second = true;
				}
				token = char1;
				if (second)
				{
					break;
				}
				return Token::punctuation_(_filename, _x, _y, token);
			case '<':
			case '>':
				token = char1;
				if (char1 == char2 || char2 == '=' || char2 == '>' || char2 == '@')
				{
					second = true;
					break;
				}
				return Token::punctuation_(_filename, _x, _y, token);
			case '@':
				token = char1;
				if (char1 == char2 || char2 == '=' || char2 == '+' || char2 == '-' || char2 == '<' || char2 == '>')
				{
					second = true;
					break;
				}
				return Token::punctuation_(_filename, _x, _y, token);
			case '|':
				token = char1;
				if (char1 == char2 || char2 == '.')
				{
					second = true;
					break;
				}
				return Token::punctuation_(_filename, _x, _y, token);
			case '&':
			case '^':
			case '$':
			case '~':
			case '.':
			case '=':
				token = char1;
				if (char1 == char2)
				{
					second = true;
					break;
				}
				return Token::punctuation_(_filename, _x, _y, token);
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
				return Token::punctuation_(_filename, _x, _y, token);
			default:
			{
				const bool alpha1 = alpha_(char1);
				const bool num1 = numeric_(char1);
				const bool alpha2 = alpha_(char2);
				const bool num2 = numeric_(char2);
				if (!alphanumeric && !numeric)
				{
					if (num1 || char1 == '-' && num2)
					{
						numeric = true;
					}
					else if (alpha1)
					{
						alphanumeric = true;
					}
				}
				if (numeric)
				{
					token += char1;
					const bool exp1 = (char1 == 'E' || char1 == 'e');
					const bool pnt1 = (char1 == '.');
					if (exp1)
					{
						exponent = true;
						point = true;
					}
					else if (pnt1)
					{
						point = true;
					}
					const bool pnt2 = (char2 == '.');
					const bool exp2 = (char2 == 'E' || char2 == 'e');
					const bool sig2 = (char2 == '+' || char2 == '-');
					if (!num2 &&
						(!pnt2 || (pnt2 && point)) &&
						(!exp2 || (exp2 && exponent)) &&
						(!sig2 || (sig2 && !exp1)))
					{
						if (point || exponent)
						{
							if (pnt1)
							{
								_dot = true;
								return Token::integer_(_filename, _x, _y, token.substr(0, token.length() - 1));
							}
							if (exp1)
							{
								_use = char1;
								if (point)
								{
									if (token[token.length() - 2] == '.')
									{
										_dot = true;
										return Token::integer_(_filename, _x, _y, token.substr(0, token.length() - 2));
									}
									return Token::float_(_filename, _x, _y, token.substr(0, token.length() - 1));
								}
								return Token::integer_(_filename, _x, _y, token.substr(0, token.length() - 1));
							}
							return Token::float_(_filename, _x, _y, token);
						}
						return Token::integer_(_filename, _x, _y, token);
					}
				}
				else if (alphanumeric)
				{
					token += char1;
					if (!alpha2 && !num2)
					{
						return Token::name_(_filename, _x, _y, token);
					}
				}
				else
				{
					// single character punctuation
					return Token::punctuation_(_filename, _x, _y, std::string(&char1, 1));
				}
			}
			}
		}
		if (commentline || token.empty())
		{
			return stop_();
		}
		return Token::error_(_filename, _x, _y, token);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Tokenizer");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Tokenizer");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	const Ptr _river;
	const Ptr _filename;
	int64_t _x = 0;
	int64_t _y = 1;
	bool _dot = false;
	char _use = 0;

	static inline const bool alpha_(const char c)
	{
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
	}

	static inline const bool numeric_(const char c)
	{
		return c >= '0' && c <= '9';
	}
};

//======================================================================
// class Tokenizer
//======================================================================

} // namespace strange

#endif
