#ifndef COM_ONEISH_STRANGE_TOKENIZER_H
#define COM_ONEISH_STRANGE_TOKENIZER_H

#include "strange_core.h"

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
	inline Tokenizer(const Ptr river)
		: Mutable{}
		, _river{ river }
	{
	}

	static inline const Ptr mut(const Ptr it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr river)
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

	inline const bool eof_()
	{
		River* const river = dynamic_<River>(_river);
		if (river)
		{
			return river->eof_();
		}
		return !_river->invoke_("eof")->is_nothing_();
	}

	inline const Ptr eof(const Ptr ignore)
	{
		River* const river = dynamic_<River>(_river);
		if (river)
		{
			return river->eof(ignore);
		}
		return _river->invoke_("eof");
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
		std::string token;
		while (true)
		{
			char char1;
			char char2;
			if (river)
			{
				if (river->eof_())
				{
					break;
				}
				if (_dot)
				{
					char1 = '.';
					_dot = false;
				}
				else if (_exp)
				{
					char1 = _exp;
					_exp = 0;
				}
				else
				{
					char1 = river->get_();
				}
				char2 = river->eof_() ? 0 : river->peek_();
			}
			else
			{
				if (eof_())
				{
					break;
				}
				if (_dot)
				{
					char1 = '.';
					_dot = false;
				}
				else if (_exp)
				{
					char1 = _exp;
					_exp = 0;
				}
				else
				{
					Int8* const byte1 = dynamic_<Int8>(_river->invoke_("get"));
					if (!byte1)
					{
						break;
					}
					char1 = byte1->get_();
				}
				Int8* const byte2 = eof_() ? 0 : dynamic_<Int8>(_river->invoke_("peek"));
				char2 = byte2 ? byte2->get_() : 0;
			}

			if (_different)
			{
				_different = false;
				return punctuation_("==");
			}

			if (char1 == '\n')
			{
				_x = 0;
				++_y;
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
				case '\a':
					token += '\a';
					break;
				case '\b':
					token += '\b';
					break;
				case '\f':
					token += '\f';
					break;
				case '\n':
					token += '\n';
					break;
				case '\r':
					token += '\r';
					break;
				case '\t':
					token += '\t';
					break;
				case '\v':
					token += '\v';
					break;
				default:
					token += char1;
				}
				escape = false;
			}
			else if (second)
			{
				if (char1 == '=' && char2 == '=' && token == "!")
				{
					_different = true;
					return punctuation_(token);
				}
				return punctuation_(token + char1);
			}
			else if (singlequote && char1 == '\'')
			{
				return symbol_(token + char1);
			}
			else if (doublequote && char1 == '\"')
			{
				return lake_(token + char1);
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
			case '<':
				if (char1 == '<' && char2 == '>')
				{
					second = true;
				}
			case '>':
				if ((char1 != '!' && char1 == char2) || char2 == '=')
				{
					second = true;
				}
				token = char1;
				if (second)
				{
					break;
				}
				return punctuation_(token);
			case '@':
			case '&':
			case '|':
			case '^':
			case '$':
			case '#':
			case '~':
			case '.':
			case '=':
				token = char1;
				if (char1 == char2)
				{
					second = true;
					break;
				}
				return punctuation_(token);
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
				return punctuation_(token);
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
								return integer_(token.substr(0, token.length() - 1));
							}
							if (exp1)
							{
								_exp = char1;
								if (point)
								{
									if (token[token.length() - 2] == '.')
									{
										_dot = true;
										return integer_(token.substr(0, token.length() - 2));
									}
									return float_(token.substr(0, token.length() - 1));
								}
								return integer_(token.substr(0, token.length() - 1));
							}
							return float_(token);
						}
						return integer_(token);
					}
				}
				else if (alphanumeric)
				{
					token += char1;
					if (!alpha2 && !num2)
					{
						return name_(token);
					}
				}
				else
				{
					// single character punctuation
					return punctuation_(std::string(&char1, 1));
				}
			}
			}
			++_x;
		}
		if (commentline || token.empty())
		{
			return stop_();
		}
		return error_(token);
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
	int64_t _x = 0;
	int64_t _y = 0;
	bool _dot = false;
	char _exp = 0;
	bool _different = false;

	static inline const bool alpha_(const char c)
	{
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
	}

	static inline const bool numeric_(const char c)
	{
		return c >= '0' && c <= '9';
	}

	inline const Ptr symbol_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Int8::fin_('S'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		const Ptr symbol = sym_(s.substr(1, s.length() - 2));
		if (symbol->is_nothing_())
		{
			flk->push_back_(nothing_());
		}
		else if (symbol->is_("1"))
		{
			flk->push_back_(one_());
		}
		else if (symbol->is_("."))
		{
			flk->push_back_(stop_());
		}
		else
		{
			flk->push_back_(symbol);
		}
		return flock;
	}

	inline const Ptr lake_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Int8::fin_('L'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		flk->push_back_(Lake::fin_(s.substr(1, s.length() - 2)));
		return flock;
	}

	inline const Ptr name_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Int8::fin_('N'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		return flock;
	}

	inline const Ptr integer_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Int8::fin_('I'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		const Ptr symbol = sym_(s);
		flk->push_back_(symbol);
		const Ptr int64 = Int64::mut_();
		static_<Int64>(int64)->from_symbol_(symbol);
		flk->push_back_(int64);
		return flock;
	}

	inline const Ptr float_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Int8::fin_('F'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		const Ptr symbol = sym_(s);
		flk->push_back_(symbol);
		const Ptr float64 = Float64::mut_();
		static_<Float64>(float64)->from_symbol_(symbol);
		flk->push_back_(float64);
		return flock;
	}

	inline const Ptr punctuation_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Int8::fin_('P'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		return flock;
	}

	inline const Ptr error_(const std::string& s)
	{
		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(Int8::fin_('E'));
		flk->push_back_(Int64::fin_(_x));
		flk->push_back_(Int64::fin_(_y));
		flk->push_back_(sym_(s));
		return flock;
	}
};

//======================================================================
// class Tokenizer
//======================================================================

} // namespace strange

#endif
