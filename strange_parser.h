#ifndef COM_ONEISH_STRANGE_PARSER_H
#define COM_ONEISH_STRANGE_PARSER_H

#include "strange_core.h"
#include "strange_reference.h"
#include "strange_creature.h"
#include "strange_expression.h"
#include "strange_function.h"
#include "strange_tokenizer.h"

namespace strange
{
	class Parser;

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
class Parser : public Mutable
//----------------------------------------------------------------------
{
public:
	inline Parser(const Ptr tokenizer)
		: Mutable{}
		, _tokenizer{ tokenizer }
		, _next{ _tokenizer->next_() }
	{
	}

	static inline const Ptr mut(const Ptr it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr tokenizer)
	{
		return make_<Parser>(tokenizer);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Parser::mut, "tokenizer"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	inline const bool eof_()
	{
		Tokenizer* const tokenizer = dynamic_<Tokenizer>(_tokenizer);
		if (tokenizer)
		{
			return tokenizer->eof_();
		}
		return !_tokenizer->invoke_("eof")->is_nothing_();
	}

	inline const Ptr eof(const Ptr ignore)
	{
		Tokenizer* const tokenizer = dynamic_<Tokenizer>(_tokenizer);
		if (tokenizer)
		{
			return tokenizer->eof(ignore);
		}
		return _tokenizer->invoke_("eof");
	}

	inline const Ptr parse_()
	{
		const Ptr shoal = Shoal::mut_();
		Thing::share_(shoal);
		return _parse_(nothing_(), shoal);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Parser");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Mutable");
			herd->insert_("strange::Parser");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	const Ptr _tokenizer;
	Ptr _next;

	inline const Ptr _token_()
	{
		return _next;
	}

	inline const void _next_()
	{
		_next = _tokenizer->next_();
	}

	static inline void _wrap_(const Ptr thing, const Ptr flock)
	{
		static_<Flock>(flock)->push_back_(Expression::fin_(thing));
	}

	inline const Ptr _parse_(const Ptr scope, const Ptr shoal)
	{
		Ptr result;
		for (bool first = true, cont = true; cont; first = false)
		{
			const Ptr token = _token_();
			if (token->is_("."))
			{
				break;
			}
			Flock* const tok = static_<Flock>(token);
			const char tag = static_<Int8>(tok->at_(0))->get_();
			if (tag == 'E') // error
			{
				log_("tokenizer error");
				return Expression::fin_();
			}
			const int64_t x = static_<Int64>(tok->at_(1))->get_();
			const int64_t y = static_<Int64>(tok->at_(2))->get_();
			const Ptr symbol = tok->at_(3);
			const Ptr flock = Flock::mut_();
			Flock* const flk = static_<Flock>(flock);
			static const Ptr local = sym_("local_");
			static const Ptr invoke = sym_("invoke_");
			static const Ptr at = sym_("at");
			const Ptr statement = Reference::mut_(invoke);
			Reference* const smt = static_<Reference>(statement);
			if (first)
			{
				if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
				{
					flk->push_back_(tok->at_(4));
					result = Expression::fin_(sym_("thing_"), flock);
				}
				else if (tag == 'N') // name
				{
					_next_();
					if (symbol->is_("lambda_") || symbol->is_("function_"))
					{
						if (_statement_(scope, shoal, flock, true, symbol->is_("lambda_"))) // parameters/capture
						{
							const int64_t size = flk->size_();
							if (size % 2 == 0)
							{
								flk->push_back_(_parse_(scope, shoal));
								result = Expression::fin_(symbol, flock);
							}
							else
							{
								log_("parser error: invalid lambda_/function_");
							}
							continue;
						}
					}
					else if (symbol->is_("break_") || symbol->is_("continue_") || symbol->is_("return_") || symbol->is_("throw_"))
					{
						if (_statement_(scope, shoal, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								_wrap_(nothing_(), flock);
							}
							else if (size != 1)
							{
								log_("parser error: invalid break_/continue_/return_/throw_");
							}
							result = Expression::fin_(symbol, flock);
							continue;
						}
					}
					else if (symbol->is_("catch_"))
					{
						if (_statement_(scope, shoal, flock))
						{
							if (flk->size_() == 2)
							{
								result = Expression::fin_(symbol, flock);
							}
							else
							{
								log_("parser error: invalid catch_");
							}
							continue;
						}
					}
					else if (symbol->is_("if_"))
					{
						if (_statement_(scope, shoal, flock))
						{
							const int64_t size = flk->size_();
							if (size == 2 || size == 3)
							{
								result = Expression::fin_(symbol, flock);
							}
							else
							{
								log_("parser error: invalid if_");
							}
							continue;
						}
					}
					else if (symbol->is_("while_") || symbol->is_("do_"))
					{
						if (_statement_(scope, shoal, flock))
						{
							const int64_t size = flk->size_();
							if (size == 1)
							{
								flk->push_back_(_parse_(scope, shoal));
								result = Expression::fin_(symbol, flock);
							}
							else
							{
								log_("parser error: invalid while_/do_");
							}
							continue;
						}
					}
					else if (symbol->is_("for_"))
					{
						if (_statement_(scope, shoal, flock))
						{
							const int64_t size = flk->size_();
							if (size == 3)
							{
								flk->push_back_(_parse_(scope, shoal));
								result = Expression::fin_(symbol, flock);
							}
							else
							{
								log_("parser error: invalid for_");
							}
							continue;
						}
					}
					// local at name
					flk->push_back_(Expression::fin_(local, Flock::mut_())); // local
					_wrap_(at, flock);
					_wrap_(symbol, flock);
					cont = _update_(scope, shoal, flock);
					result = Expression::fin_(invoke, flock);
				}
				else if (tag == 'P') // punctuation
				{
					if (symbol->is_("$")) // shared at
					{
						const Ptr nested = Flock::mut_();
						static_<Flock>(nested)->push_back_(Expression::fin_(local, Flock::mut_())); // local
						_wrap_(at, nested);
						_wrap_(symbol, nested);

						flk->push_back_(Expression::fin_(invoke, nested));
						_wrap_(at, flock);
						_next_();
						cont = _at_(scope, shoal, flock);
						result = Expression::fin_(invoke, flock);
					}
					else if (symbol->is_("|")) // me dot
					{
						const Ptr nested = Flock::mut_();
						static_<Flock>(nested)->push_back_(Expression::fin_(local, Flock::mut_())); // local
						_wrap_(at, nested);
						_wrap_(symbol, nested);

						flk->push_back_(Expression::fin_(invoke, nested));
						_next_();
						_dot_(scope, shoal, statement, flock);
						result = Expression::fin_(smt->get_(), flock);
					}
					else if (symbol->is_("..")) // iterator
					{
						flk->push_back_(Expression::fin_(local, Flock::mut_())); // local
						_wrap_(at, flock);
						_wrap_(sym_("&"), flock);
						_next_();
						result = Expression::fin_(invoke, flock);
					}
					else if (symbol->is_("^^")) // iterator next
					{
						const Ptr nested = Flock::mut_();
						static_<Flock>(nested)->push_back_(Expression::fin_(local, Flock::mut_())); // local
						_wrap_(at, nested);
						_wrap_(sym_("&"), nested);

						flk->push_back_(Expression::fin_(invoke, nested));
						_wrap_(sym_("next"), flock);
						_next_();
						result = Expression::fin_(invoke, flock);
					}
					else if (symbol->is_("@@")) // local
					{
						_next_();
						result = Expression::fin_(local, Flock::mut_()); // local
					}
					else if (symbol->is_("$$") || symbol->is_("**")) // shared/relative scope
					{
						_next_();
						result = _scope_(scope, shoal, flock, symbol->is_("**"));
					}
					else if (symbol->is_("<>")) // container
					{
						std::string container = static_<Symbol>(scope)->symbol_();
						const size_t pos = container.find_last_of("::");
						if (pos == std::string::npos)
						{
							container = "";
						}
						else
						{
							container = container.substr(0, pos);
						}
						flk->push_back_(shoal);
						flk->push_back_(sym_(container));
						result = Expression::fin_(sym_("shared_scope_"), flock);
					}
					else if (symbol->is_("(")) // block
					{
						_next_();
						_list_(scope, shoal, flock, symbol, sym_(")"));
						result = Expression::fin_(sym_("block_"), flock);
					}
					else if (symbol->is_("[")) // flock
					{
						_next_();
						_list_(scope, shoal, flock, symbol, sym_("]"));
						result = Expression::fin_(sym_("flock_"), flock);
					}
					else if (symbol->is_("{")) // shoal or herd
					{
						_next_();
						if (_map_(scope, shoal, flock))
						{
							result = Expression::fin_(sym_("shoal_"), flock);
						}
						else
						{
							result = Expression::fin_(sym_("herd_"), flock);
						}
					}
					else if (symbol->is_("<<")) // iterator
					{
						_next_();
						_list_(scope, shoal, flock, symbol, sym_(">>"));
						result = Expression::fin_(sym_("flock_iterator_"), flock);
					}
					else
					{
						log_("parser error: unexpected initial punctuation");
					}
				}
			}
			else // not first
			{
				if (tag == 'P' &&
					(symbol->is_(")") || symbol->is_("]") || symbol->is_("}") || symbol->is_(">>") || symbol->is_(",")))
				{
					cont = false;
				}
				else
				{
					flk->push_back_(result);
					cont = _thing_(scope, shoal, statement, flock);
					result = Expression::fin_(smt->get_(), flock);
				}
			}
		}
		if (result.get())
		{
			return result;
		}
		return Expression::fin_();
	}

	inline const bool _thing_(const Ptr scope, const Ptr shoal, const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return false; // break
		}
		Flock* const flk = static_<Flock>(flock);
		Flock* const tok = static_<Flock>(token);
		const char tag = static_<Int8>(tok->at_(0))->get_();
		if (tag == 'E') // error
		{
			log_("tokenizer error");
			return false; // break
		}
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		Reference* const smt = static_<Reference>(statement);
		if (tag == 'P') // punctuation
		{
			if (symbol->is_("."))
			{
				_next_();
				_dot_(scope, shoal, flock, statement);
			}
			else if (symbol->is_("(") || symbol->is_("{")) // block or shoal
			{
				flk->push_back_(_parse_(scope, shoal));
				smt->set_(sym_("invoke_iterable_"));
			}
			else if (symbol->is_("[")) // flock
			{
				_next_();
				_list_(scope, shoal, flock, symbol, sym_("]"));
			}
			else if (symbol->is_("<<")) // iterator
			{
				_next_();
				_list_(scope, shoal, flock, symbol, sym_(">>"));
				smt->set_(sym_("invoke_iterator_"));
			}
			else if (symbol->is_(")") || symbol->is_("]") || symbol->is_("}") || symbol->is_(">>") || symbol->is_(","))
			{
				return false; // break
			}
			else if (symbol->is_("%"))
			{
				_next_();
				_wrap_(sym_("modulo"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("%="))
			{
				_next_();
				_wrap_(sym_("self_modulo"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("%%"))
			{
				_next_();
				_wrap_(sym_("xor"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("!%"))
			{
				_next_();
				_wrap_(sym_("xnor"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("+"))
			{
				_next_();
				_wrap_(sym_("add"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("+="))
			{
				_next_();
				_wrap_(sym_("self_add"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("++"))
			{
				_next_();
				_wrap_(sym_("increment"), flock);
			}
			else if (symbol->is_("-"))
			{
				_next_();
				_wrap_(sym_("subtract"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("-="))
			{
				_next_();
				_wrap_(sym_("self_subtract"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("--"))
			{
				_next_();
				_wrap_(sym_("decrement"), flock);
			}
			else if (symbol->is_("*"))
			{
				_next_();
				_wrap_(sym_("multiply"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("*="))
			{
				_next_();
				_wrap_(sym_("self_multiply"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("/"))
			{
				_next_();
				_wrap_(sym_("divide"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("/="))
			{
				_next_();
				_wrap_(sym_("self_divide"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("=="))
			{
				_next_();
				_wrap_(sym_("same"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("!="))
			{
				_next_();
				_wrap_(sym_("different"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("@"))
			{
				_next_();
				_wrap_(sym_("at"), flock);
				return _at_(scope, shoal, flock); // break/continue
			}
			else if (symbol->is_("&"))
			{
				_next_();
				_wrap_(sym_("iterator"), flock);
			}
			else if (symbol->is_("&&"))
			{
				_next_();
				_wrap_(sym_("and"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("!&"))
			{
				_next_();
				_wrap_(sym_("nand"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("||"))
			{
				_next_();
				_wrap_(sym_("or"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("!|"))
			{
				_next_();
				_wrap_(sym_("nor"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("^"))
			{
				_next_();
				_wrap_(sym_("next"), flock);
			}
			else if (symbol->is_("~"))
			{
				_next_();
				_wrap_(sym_("copy"), flock);
			}
			else if (symbol->is_("~~"))
			{
				_next_();
				_wrap_(sym_("clone"), flock);
			}
			else if (symbol->is_("#"))
			{
				_next_();
				_wrap_(sym_("finalize"), flock);
			}
			else if (symbol->is_("##"))
			{
				_next_();
				_wrap_(sym_("freeze"), flock);
			}
			else if (symbol->is_("!"))
			{
				_next_();
				_wrap_(sym_("is_nothing"), flock);
			}
			else if (symbol->is_("?"))
			{
				_next_();
				_wrap_(sym_("is_not_nothing"), flock);
			}
			else if (symbol->is_("<"))
			{
				_next_();
				_wrap_(sym_("less_than"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_(">"))
			{
				_next_();
				_wrap_(sym_("greater_than"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("<="))
			{
				_next_();
				_wrap_(sym_("less_or_equal"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else if (symbol->is_(">="))
			{
				_next_();
				_wrap_(sym_("greater_or_equal"), flock);
				_member_(scope, shoal, statement, flock);
			}
			else
			{
				log_("parser error: thing punctuation");
			}
		}
		else
		{
			flk->push_back_(_parse_(scope, shoal));
			smt->set_(sym_("invoke_iterable_"));
		}
		return true; // continue
	}

	inline void _dot_(const Ptr scope, const Ptr shoal, const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			log_("parser error: dot eof");
			return;
		}
		Flock* const flk = static_<Flock>(flock);
		Flock* const tok = static_<Flock>(token);
		const char tag = static_<Int8>(tok->at_(0))->get_();
		if (tag == 'E') // error
		{
			log_("tokenizer error");
			return;
		}
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			log_("parser error: dot literal");
		}
		else if (tag == 'N') // name
		{
			_next_();
			_wrap_(symbol, flock);
			_member_(scope, shoal, statement, flock);
		}
		else if (tag == 'P') // punctuation
		{
			log_("parser error: dot punctuation");
		}
	}

	inline void _member_(const Ptr scope, const Ptr shoal, const Ptr statement, const Ptr flock)
	{
		const Ptr token = _token_();
		Reference* const smt = static_<Reference>(statement);
		if (token->is_("."))
		{
			smt->set_(sym_("method_"));
			return;
		}
		Flock* const flk = static_<Flock>(flock);
		Flock* const tok = static_<Flock>(token);
		const char tag = static_<Int8>(tok->at_(0))->get_();
		if (tag == 'E') // error
		{
			log_("tokenizer error");
			return;
		}
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		if (tag == 'P') // punctuation
		{
			if (symbol->is_("."))
			{
				_next_();
				_dot_(scope, shoal, statement, flock);
			}
			else if (symbol->is_("(") || symbol->is_("{")) // block or shoal
			{
				flk->push_back_(_parse_(scope, shoal));
				smt->set_(sym_("operate_iterable_"));
			}
			else if (symbol->is_("[")) // flock
			{
				_next_();
				_list_(scope, shoal, flock, symbol, sym_("]"));
			}
			else if (symbol->is_("<<")) // iterator
			{
				_next_();
				_list_(scope, shoal, flock, symbol, sym_(">>"));
				smt->set_(sym_("operate_iterator_"));
			}
			else
			{
				smt->set_(sym_("method_"));
			}
		}
		else
		{
			flk->push_back_(_parse_(scope, shoal));
			smt->set_(sym_("operate_iterable_"));
		}
	}

	inline const bool _statement_(const Ptr scope, const Ptr shoal, const Ptr flock, const bool parameters = false, const bool capture = false)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return false; // not a statement
		}
		Flock* const tok = static_<Flock>(token);
		const char tag = static_<Int8>(tok->at_(0))->get_();
		if (tag == 'E') // error
		{
			log_("tokenizer error");
			return false;
		}
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		if (tag == 'P' && symbol->is_("("))
		{
			_next_();
			_list_(scope, shoal, flock, symbol, sym_(")"), parameters, capture);
			return true; // is a statement
		}
		return false; // not a statement
	}

	inline void _list_(const Ptr scope, const Ptr shoal, const Ptr flock, const Ptr open, const Ptr close, const bool parameters = false, const bool capture = false)
	{
		Flock* const flk = static_<Flock>(flock);
		bool parameter = parameters;
		Ptr captured;
		bool punctuation = false;
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			if (token->is_("."))
			{
				log_("parser error: open without close");
				return;
			}
			Flock* const tok = static_<Flock>(token);
			const char tag = static_<Int8>(tok->at_(0))->get_();
			if (tag == 'E') // error
			{
				log_("tokenizer error");
				return;
			}
			const int64_t x = static_<Int64>(tok->at_(1))->get_();
			const int64_t y = static_<Int64>(tok->at_(2))->get_();
			const Ptr symbol = tok->at_(3);
			if (first)
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_(close))
					{
						_next_();
						return;
					}
					if (symbol->is_(","))
					{
						log_("parser error: open followed immediately by ,");
						return;
					}
				}
			}
			else if (punctuation)
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_(close))
					{
						_next_();
						if (parameter)
						{
							if (capture)
							{
								flk->push_back_(captured);
							}
							else
							{
								flk->push_back_(Expression::fin_());
							}
						}
						return;
					}
					else if (symbol->is_(","))
					{
						if (close->is_(">>"))
						{
							log_("parser error: open expecting single item then close");
							return;
						}
						if (parameter)
						{
							if (capture)
							{
								flk->push_back_(captured);
							}
							else
							{
								flk->push_back_(Expression::fin_());
							}
						}
						else
						{
							parameter = parameters;
						}
					}
					else if (parameter)
					{
						if (symbol->is_("="))
						{
							parameter = false;
						}
						else
						{
							log_("parser error: open expecting , = or close");
							return;
						}
					}
					else
					{
						log_("parser error: open expecting , or close");
						return;
					}
				}
				else if (parameter)
				{
					log_("parser error: open expecting , = or close");
					return;
				}
				else
				{
					log_("parser error: open expecting , or close");
					return;
				}
				_next_();
				punctuation = false;
				continue;
			}
			if (parameter)
			{
				if (tag == 'N') // name
				{
					flk->push_back_(symbol);
					if (capture)
					{
						captured = _parse_(scope, shoal);
					}
					else
					{
						_next_();
					}
				}
				else
				{
					log_("parser error: open expecting parameter name");
					return;
				}
			}
			else
			{
				flk->push_back_(_parse_(scope, shoal));
			}
			punctuation = true;
		}
	}

	inline const bool _map_(const Ptr scope, const Ptr shoal, const Ptr flock)
	{
		Flock* const flk = static_<Flock>(flock);
		bool is_map = false;
		bool not_map = false;
		bool empty = false;
		bool key = true;
		bool punctuation = false;
		bool add_shoal = false;
		Ptr add_scope = nothing_();
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			if (token->is_("."))
			{
				log_("parser error: { without }");
				return is_map;
			}
			Flock* const tok = static_<Flock>(token);
			const char tag = static_<Int8>(tok->at_(0))->get_();
			if (tag == 'E') // error
			{
				log_("tokenizer error");
				return is_map;
			}
			const int64_t x = static_<Int64>(tok->at_(1))->get_();
			const int64_t y = static_<Int64>(tok->at_(2))->get_();
			const Ptr symbol = tok->at_(3);
			if (first)
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_("}"))
					{
						_next_();
						return is_map;
					}
					else if (symbol->is_(":"))
					{
						_next_();
						empty = true;
						continue;
					}
					else if (symbol->is_(","))
					{
						log_("parser error: { followed immediately by ,");
						return false;
					}
				}
			}
			else if (empty)
			{
				if (tag == 'P' && symbol->is_("}"))
				{
					_next_();
					return is_map;
				}
				log_("parser error: {: not followed immediately by }");
				return false;
			}
			else if (key)
			{
				if (punctuation)
				{
					if (tag == 'P') // punctuation
					{
						if (symbol->is_("}"))
						{
							if (is_map)
							{
								log_("parser error: last key with missing value");
								return false;
							}
							_next_();
							return is_map;
						}
						else if (symbol->is_(":") || symbol->is_("::"))
						{
							if (not_map)
							{
								log_("parser error: key with unexpected value");
								return false;
							}
							_next_();
							is_map = true;
							key = false;
							punctuation = false;
							add_shoal = symbol->is_("::");
							continue;
						}
						else if (symbol->is_(","))
						{
							if (is_map)
							{
								log_("parser error: key with missing value");
								return false;
							}
							_next_();
							not_map = true;
							key = false;
							punctuation = false;
							continue;
						}
						else
						{
							log_("parser error: key followed by unexpected punctuation");
							return false;
						}
					}
					log_("parser error: key not followed by punctuation");
					return false;
				}
			}
			else if (punctuation)
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_("}"))
					{
						_next_();
						return is_map;
					}
					else if (symbol->is_(","))
					{
						_next_();
						key = true;
						punctuation = false;
						continue;
					}
					else
					{
						log_("parser error: value followed by unexpected punctuation");
						return false;
					}
				}
				log_("parser error: value not followed by punctuation");
				return false;
			}
			if (key)
			{
				add_scope = _parse_(scope, shoal);
				flk->push_back_(add_scope);
			}
			else
			{
				const Ptr add_scope_symbol = Expression::immediate_(add_scope);
				Symbol* const add_scope_sym = dynamic_<Symbol>(add_scope_symbol);
				const Ptr new_scope = add_scope_sym
					? ( scope->is_nothing_()
						? add_scope_symbol
						: sym_(static_<Symbol>(scope)->symbol_() + "::" + add_scope_sym->symbol_())
					)
					: scope;
				const Ptr value = _parse_(new_scope, shoal);
				flk->push_back_(value);
				if (add_shoal)
				{
					static_<Shoal>(shoal)->update_(new_scope, Function::fin_(value));
				}
			}
			punctuation = true;
		}
		return is_map;
	}

	inline const Ptr _scope_(const Ptr scope, const Ptr shoal, const Ptr flock, const bool relative)
	{
		Ptr key = nothing_();
		bool punctuation = false;
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			if (token->is_("."))
			{
				break;
			}
			Flock* const tok = static_<Flock>(token);
			const char tag = static_<Int8>(tok->at_(0))->get_();
			if (tag == 'E') // error
			{
				log_("tokenizer error");
				return Expression::fin_();
			}
			const int64_t x = static_<Int64>(tok->at_(1))->get_();
			const int64_t y = static_<Int64>(tok->at_(2))->get_();
			const Ptr symbol = tok->at_(3);
			if (first)
			{
				if (tag == 'N') // name
				{
					key = symbol;
				}
				else
				{
					break;
				}
			}
			else if (punctuation)
			{
				if (tag == 'P' && symbol->is_("::"))
				{
					_next_();
					punctuation = false;
					continue;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (tag == 'N') // name
				{
					key = sym_(static_<Symbol>(key)->symbol_() + "::" + static_<Symbol>(symbol)->symbol_());
				}
				else
				{
					log_("parser error: shared scope :: not followed by name");
					break;
				}
			}
			_next_();
			punctuation = true;
		}
		const Ptr key_flock = Flock::mut_();
		Flock* const key_flk = static_<Flock>(key_flock);
		key_flk->push_back_(shoal);
		key_flk->push_back_(key);
		if (relative)
		{
			key_flk->push_back_(scope);
			return Expression::fin_(sym_("relative_scope_"), key_flock);
		}
		return Expression::fin_(sym_("shared_scope_"), key_flock);
	}
	
	inline const bool _at_(const Ptr scope, const Ptr shoal, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			log_("parser error: at eof");
			return false; // break
		}
		Flock* const flk = static_<Flock>(flock);
		Flock* const tok = static_<Flock>(token);
		const char tag = static_<Int8>(tok->at_(0))->get_();
		if (tag == 'E') // error
		{
			log_("tokenizer error");
			return true; // continue
		}
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			_wrap_(tok->at_(4), flock);
		}
		else if (tag == 'N') // name
		{
			_wrap_(symbol, flock);
		}
		else if (tag == 'P') // punctuation
		{
			log_("parser error: at punctuation");
			return true; // continue
		}
		_next_();
		return _update_(scope, flock, shoal); // continue/break
	}

	inline const bool _update_(const Ptr scope, const Ptr shoal, const Ptr flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return false; // break
		}
		Flock* const flk = static_<Flock>(flock);
		Flock* const tok = static_<Flock>(token);
		const char tag = static_<Int8>(tok->at_(0))->get_();
		if (tag == 'E') // error
		{
			log_("tokenizer error");
			return false; // break
		}
		const int64_t x = static_<Int64>(tok->at_(1))->get_();
		const int64_t y = static_<Int64>(tok->at_(2))->get_();
		const Ptr symbol = tok->at_(3);
		if (tag == 'P' && symbol->is_(":="))
		{
			_next_();
			flk->update_(flk->size_() - 2, Expression::fin_(sym_("update")));
			flk->push_back_(_parse_(scope, shoal));
			return false; // break
		}
		return true; // continue
	}
};

//======================================================================
// class Parser
//======================================================================

} // namespace strange

#endif