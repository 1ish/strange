#ifndef COM_ONEISH_STRANGE_PARSER_H
#define COM_ONEISH_STRANGE_PARSER_H

#include "strange_core.h"
#include "strange_reference.h"
#include "strange_expression.h"
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
class Parser : public Stateful
//----------------------------------------------------------------------
{
public:
	inline Parser(const Ptr& tokenizer)
		: Stateful{}
		, _tokenizer{ tokenizer }
		, _next{ _tokenizer->next_() }
	{
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr& tokenizer)
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

	inline const bool good_()
	{
		Tokenizer* const tokenizer = dynamic_<Tokenizer>(_tokenizer);
		if (tokenizer)
		{
			return tokenizer->good_();
		}
		return !_tokenizer->invoke_("good")->is_nothing_();
	}

	inline const Ptr good(const Ptr& ignore)
	{
		Tokenizer* const tokenizer = dynamic_<Tokenizer>(_tokenizer);
		if (tokenizer)
		{
			return tokenizer->good(ignore);
		}
		return _tokenizer->invoke_("good");
	}

	inline const Ptr parse_()
	{
		const Ptr shoal = Shoal::mut_();
		Thing::share_(shoal);
		const Ptr expression = _parse_(nothing_(), shoal, Herd::mut_(), true);
		shoal->finalize_();
		return expression;
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
			herd->insert_("strange::Stateful");
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

	static inline void _wrap_(const Ptr& token, const Ptr& thing, const Ptr& flock)
	{
		static_<Flock>(flock)->push_back_(Expression::fin_(token, thing));
	}

	inline const Ptr _parse_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const bool right)
	{
		Ptr token;
		Ptr result;
		for (bool first = true, cont = true; cont; first = false, cont = cont && right)
		{
			token = _token_();
			if (token->is_("."))
			{
				break;
			}
			Token* const tok = static_<Token>(token);
			const char tag = tok->tag_();
			if (tag == 'E') // error
			{
				throw tok->error_("Tokenizer ERROR");
			}
			const Ptr symbol = tok->symbol();
			const Ptr flock = Flock::mut_();
			Flock* const flk = static_<Flock>(flock);
			static const Ptr local = sym_("local_");
			static const Ptr invoke = sym_("invoke_");
			static const Ptr at = sym_("at");
			const Ptr statement = Reference::mut_(invoke);
			Reference* const smt = static_<Reference>(statement);
			if (first)
			{
				_next_();
				if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
				{
					flk->push_back_(tok->value_());
					result = Expression::fin_(token, sym_("thing_"), flock);
				}
				else if (tag == 'N') // name
				{
					if (symbol->is_("lambda_"))
					{
						if (_statement_(scope, shoal, finalized, flock, true, true)) // parameters/capture
						{
							if (flk->size_() % 3 == 0) // <cat> param := capture
							{
								const Ptr nested = Flock::mut_();
								Flock* const nst = static_<Flock>(nested);
								if (_statement_(scope, shoal, finalized, nested, true)) // parameters
								{
									if (nst->size_() % 3 == 0) // <cat> param := default
									{
										nst->push_back_(_parse_(scope, shoal, Herd::mut_(), false)); // create new 'finalized' scope
										flk->push_back_(Expression::fin_(token, sym_("closure_"), nested));
										result = Expression::fin_(token, symbol, flock);
									}
									else
									{
										throw tok->error_("Parser ERROR: invalid lambda_ function_");
									}
									continue;
								}
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid lambda_");
							}
							continue;
						}
					}
					else if (symbol->is_("function_") || symbol->is_("mutation_") || symbol->is_("extraction_"))
					{
						if (_statement_(scope, shoal, finalized, flock, true)) // parameters
						{
							if (flk->size_() % 3 == 0) // <cat> param := default
							{
								flk->push_back_(_parse_(scope, shoal, Herd::mut_(), false)); // create new 'finalized' scope
								result = Expression::fin_(token, symbol, flock);
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid function_/mutation_/extraction_");
							}
							continue;
						}
					}
					else if (symbol->is_("fixed_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Fixed::fin_(Expression::fin_(token)));
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Fixed::fin_(flk->at_(0)));
							}
							else
							{
								throw tok->error_("Parser Error: invalid fixed_");
							}
							continue;
						}
					}
					else if (symbol->is_("mutable_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Mutable::fin_(Expression::fin_(token)));
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Mutable::fin_(flk->at_(0)));
							}
							else
							{
								throw tok->error_("Parser Error: invalid mutable_");
							}
							continue;
						}
					}
					else if (symbol->is_("variable_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Variable::fin_(Expression::fin_(token)));
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Variable::fin_(flk->at_(0)));
							}
							else
							{
								throw tok->error_("Parser Error: invalid variable_");
							}
							continue;
						}
					}
					else if (symbol->is_("changeable_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Changeable::fin_(Expression::fin_(token)));
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Changeable::fin_(flk->at_(0)));
							}
							else
							{
								throw tok->error_("Parser Error: invalid changeable_");
							}
							continue;
						}
					}
					else if (symbol->is_("break_") || symbol->is_("continue_") || symbol->is_("return_") || symbol->is_("throw_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								_wrap_(token, nothing_(), flock);
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, symbol, flock);
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid break_/continue_/return_/throw_");
							}
							continue;
						}
					}
					else if (symbol->is_("error_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							result = Expression::fin_(token, symbol, flock);
							continue;
						}
					}
					else if (symbol->is_("catch_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							if (flk->size_() == 2)
							{
								result = Expression::fin_(token, symbol, flock);
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid catch_");
							}
							continue;
						}
					}
					else if (symbol->is_("if_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							const int64_t size = flk->size_();
							if (size == 2 || size == 3)
							{
								result = Expression::fin_(token, symbol, flock);
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid if_");
							}
							continue;
						}
					}
					else if (symbol->is_("while_") || symbol->is_("do_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							if (flk->size_() == 1)
							{
								flk->push_back_(_parse_(scope, shoal, finalized, false));
								result = Expression::fin_(token, symbol, flock);
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid while_/do_");
							}
							continue;
						}
					}
					else if (symbol->is_("for_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							if (flk->size_() == 3)
							{
								flk->push_back_(_parse_(scope, shoal, finalized, false));
								result = Expression::fin_(token, symbol, flock);
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid for_");
							}
							continue;
						}
					}
					else if (symbol->is_("import_"))
					{
						if (_statement_(scope, shoal, finalized, flock))
						{
							if (flk->size_() >= 1)
							{
								const Ptr it = flock->iterator_();
								for (Ptr i = it->next_(); !i->is_("."); i = it->next_())
								{
									Lake* const lake = dynamic_<Lake>(Expression::immediate_(i)->invoke_("to_lake"));
									if (!lake)
									{
										throw tok->error_("Parser ERROR: invalid import_ filename");
									}
									const Ptr river = River::mut_(lake->get_(), true);
									if (!static_<River>(river)->good_())
									{
										throw tok->error_("Parser ERROR: invalid import_ file: " + lake->get_());
									}
									result = static_<Parser>(Parser::mut_(Tokenizer::mut_(river)))->_parse_(nothing_(), shoal, finalized, true);
								}
							}
							else
							{
								throw tok->error_("Parser ERROR: invalid import_");
							}
							continue;
						}
					}
					// local at/update name
					flk->push_back_(symbol);
					bool insert = false;
					cont = _update_(scope, shoal, finalized, flock, symbol, insert);
					result = Expression::fin_(token, local, flock);
				}
				else if (tag == 'P') // punctuation
				{
					if (symbol->is_("$")) // shared at/update
					{
						_name_(flock);
						bool insert = false;
						cont = _update_(scope, shoal, finalized, flock, static_<Symbol>(symbol)->add_(flk->at_(0)), insert);
						if (cont)
						{
							result = Expression::fin_(token, sym_("shared_at_"), flock);
						}
						else if (insert)
						{
							result = Expression::fin_(token, sym_("shared_insert_"), flock);
						}
						else
						{
							result = Expression::fin_(token, sym_("shared_update_"), flock);
						}
					}
					else if (symbol->is_("|")) // me
					{
						result = Expression::fin_(token, sym_("me_"), flock);
					}
					else if (symbol->is_("|.")) // me dot
					{
						_dot_(scope, shoal, finalized, statement, flock, true);
						result = Expression::fin_(token, smt->get_(), flock);
					}
					else if (symbol->is_("|:.")) // me operation
					{
						_name_(flock);
						result = Expression::fin_(token, sym_("intimation_"), flock);
					}
					else if (symbol->is_("..")) // iterator
					{
						flk->push_back_(sym_("&"));
						result = Expression::fin_(token, local, flock);
					}
					else if (symbol->is_("^^")) // iterator next
					{
						const Ptr nested = Flock::mut_();
						static_<Flock>(nested)->push_back_(sym_("&"));
						flk->push_back_(Expression::fin_(token, local, nested));
						flk->push_back_(sym_("next"));
						result = Expression::fin_(token, sym_("operate_"), flock);
					}
					else if (symbol->is_("$$") || symbol->is_("**")) // shared/relative scope
					{
						result = _scope_(scope, shoal, flock, symbol->is_("**"));
					}
					else if (symbol->is_("<>")) // container
					{
						std::string container = static_<Symbol>(scope)->get_();
						const std::size_t pos = container.rfind("::");
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
						result = Expression::fin_(token, sym_("shared_scope_"), flock);
					}
					else if (symbol->is_("(")) // block
					{
						_list_(scope, shoal, finalized, flock, sym_(")"));
						result = Expression::fin_(token, sym_("block_"), flock);
					}
					else if (symbol->is_("[")) // flock
					{
						_list_(scope, shoal, finalized, flock, sym_("]"));
						result = Expression::fin_(token, sym_("flock_"), flock);
					}
					else if (symbol->is_("{")) // shoal or herd
					{
						if (_map_(scope, shoal, finalized, flock))
						{
							result = Expression::fin_(token, sym_("shoal_"), flock);
						}
						else
						{
							result = Expression::fin_(token, sym_("herd_"), flock);
						}
					}
					else if (symbol->is_("<<")) // iterator
					{
						_list_(scope, shoal, finalized, flock, sym_(">>"));
						result = Expression::fin_(token, sym_("flock_iterator_"), flock);
					}
					else
					{
						throw tok->error_("Parser ERROR: unexpected initial punctuation");
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
					if (_thing_(scope, shoal, finalized, statement, flock))
					{
						result = Expression::fin_(token, smt->get_(), flock);
					}
					else
					{
						cont = false;
					}
				}
			}
		}
		if (result.get())
		{
			return result;
		}
		return Expression::fin_(token);
	}

	inline const bool _thing_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const Ptr& statement, const Ptr& flock)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return false; // break
		}
		Flock* const flk = static_<Flock>(flock);
		Token* const tok = static_<Token>(token);
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		const Ptr symbol = tok->symbol();
		Reference* const smt = static_<Reference>(statement);
		if (tag == 'P') // punctuation
		{
			if (symbol->is_("."))
			{
				_next_();
				_dot_(scope, shoal, finalized, statement, flock, false);
			}
			else if (symbol->is_("(") || symbol->is_("{")) // block or shoal
			{
				flk->push_back_(_parse_(scope, shoal, finalized, false));
				smt->set_(sym_("invoke_iterable_"));
			}
			else if (symbol->is_("[")) // flock
			{
				_next_();
				_list_(scope, shoal, finalized, flock, sym_("]"));
			}
			else if (symbol->is_("<<")) // iterator
			{
				_next_();
				_list_(scope, shoal, finalized, flock, sym_(">>"));
				smt->set_(sym_("invoke_iterator_"));
			}
			else if (symbol->is_("%"))
			{
				_next_();
				flk->push_back_(sym_("modulo"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("%="))
			{
				_next_();
				flk->push_back_(sym_("self_modulo"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("%%"))
			{
				_next_();
				flk->push_back_(sym_("xor"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("!%"))
			{
				_next_();
				flk->push_back_(sym_("xnor"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("+"))
			{
				_next_();
				flk->push_back_(sym_("add"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("+="))
			{
				_next_();
				flk->push_back_(sym_("self_add"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("++"))
			{
				_next_();
				flk->push_back_(sym_("increment"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("-"))
			{
				_next_();
				flk->push_back_(sym_("subtract"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("-="))
			{
				_next_();
				flk->push_back_(sym_("self_subtract"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("--"))
			{
				_next_();
				flk->push_back_(sym_("decrement"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("*"))
			{
				_next_();
				flk->push_back_(sym_("multiply"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("*="))
			{
				_next_();
				flk->push_back_(sym_("self_multiply"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("/"))
			{
				_next_();
				flk->push_back_(sym_("divide"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("/="))
			{
				_next_();
				flk->push_back_(sym_("self_divide"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("=="))
			{
				_next_();
				flk->push_back_(sym_("same"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("!="))
			{
				_next_();
				flk->push_back_(sym_("different"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("&"))
			{
				_next_();
				flk->push_back_(sym_("iterator"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("&&"))
			{
				_next_();
				flk->push_back_(sym_("and"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("!&"))
			{
				_next_();
				flk->push_back_(sym_("nand"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("||"))
			{
				_next_();
				flk->push_back_(sym_("or"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("!|"))
			{
				_next_();
				flk->push_back_(sym_("nor"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("^"))
			{
				_next_();
				flk->push_back_(sym_("next"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("="))
			{
				_next_();
				flk->push_back_(sym_("assign"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("~"))
			{
				_next_();
				flk->push_back_(sym_("copy"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("~~"))
			{
				_next_();
				flk->push_back_(sym_("clone"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("#"))
			{
				_next_();
				flk->push_back_(sym_("finalize"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("##"))
			{
				_next_();
				flk->push_back_(sym_("freeze"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("~#"))
			{
				_next_();
				flk->push_back_(sym_("copy_finalize"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("~~##"))
			{
				_next_();
				flk->push_back_(sym_("clone_freeze"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("@@"))
			{
				_next_();
				flk->push_back_(sym_("replicate"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("@"))
			{
				_next_();
				flk->push_back_(sym_("at"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("@>"))
			{
				_next_();
				flk->push_back_(sym_("pop_back"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("<@"))
			{
				_next_();
				flk->push_back_(sym_("pop_front"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("@<"))
			{
				_next_();
				flk->push_back_(sym_("push_back"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_(">@"))
			{
				_next_();
				flk->push_back_(sym_("push_front"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("@="))
			{
				_next_();
				flk->push_back_(sym_("update"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("@+"))
			{
				_next_();
				flk->push_back_(sym_("insert"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("@-"))
			{
				_next_();
				flk->push_back_(sym_("erase"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("!"))
			{
				_next_();
				flk->push_back_(sym_("is_nothing"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("?"))
			{
				_next_();
				flk->push_back_(sym_("is_not_nothing"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("<"))
			{
				_next_();
				flk->push_back_(sym_("less_than"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_(">"))
			{
				_next_();
				flk->push_back_(sym_("greater_than"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_("<="))
			{
				_next_();
				flk->push_back_(sym_("less_or_equal"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_(">="))
			{
				_next_();
				flk->push_back_(sym_("greater_or_equal"));
				_member_(scope, shoal, finalized, statement, flock);
			}
			else if (symbol->is_(":."))
			{
				_next_();
				_name_(flock);
				smt->set_(sym_("operation_"));
			}
			else if (symbol->is_(".:"))
			{
				_next_();
				flk->push_back_(_parse_(scope, shoal, finalized, false));
				smt->set_(sym_("perform_"));
			}
			else
			{
				return false; // break
			}
		}
		else
		{
			flk->push_back_(_parse_(scope, shoal, finalized, false));
			smt->set_(sym_("invoke_iterable_"));
		}
		return true; // continue
	}

	inline void _dot_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const Ptr& statement, const Ptr& flock, const bool me_dot)
	{
		const Ptr token = _token_();
		Token* const tok = static_<Token>(token);
		if (token->is_("."))
		{
			throw tok->error_("Parser ERROR: dot stop");
		}
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			throw tok->error_("Parser ERROR: dot literal");
		}
		if (tag == 'P') // punctuation
		{
			throw tok->error_("Parser ERROR: dot punctuation");
		}
		const Ptr symbol = tok->symbol();
		Flock* const flk = static_<Flock>(flock);
		if (tag == 'N') // name
		{
			_next_();
			flk->push_back_(symbol);
			_member_(scope, shoal, finalized, statement, flock, me_dot);
		}
	}

	inline void _member_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const Ptr& statement, const Ptr& flock, const bool me_dot = false)
	{
		const Ptr token = _token_();
		Reference* const smt = static_<Reference>(statement);
		if (token->is_("."))
		{
			smt->set_(sym_(me_dot ? "private_" : "method_"));
			return;
		}
		Flock* const flk = static_<Flock>(flock);
		Token* const tok = static_<Token>(token);
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		const Ptr symbol = tok->symbol();
		if (tag == 'P') // punctuation
		{
			if (symbol->is_("[")) // flock
			{
				_next_();
				_list_(scope, shoal, finalized, flock, sym_("]"));
				smt->set_(sym_(me_dot ? "intimate_" : "operate_"));
			}
			else if (symbol->is_("(") || symbol->is_("{")) // block or shoal
			{
				flk->push_back_(_parse_(scope, shoal, finalized, false));
				smt->set_(sym_(me_dot ? "intimate_iterable_" : "operate_iterable_"));
			}
			else if (symbol->is_("<<")) // iterator
			{
				_next_();
				_list_(scope, shoal, finalized, flock, sym_(">>"));
				smt->set_(sym_(me_dot ? "intimate_iterator_" : "operate_iterator_"));
			}
			else
			{
				smt->set_(sym_(me_dot ? "private_" : "method_"));
			}
		}
		else
		{
			flk->push_back_(_parse_(scope, shoal, finalized, false));
			smt->set_(sym_(me_dot ? "intimate_iterable_" : "operate_iterable_"));
		}
	}

	inline const bool _statement_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const Ptr& flock, const bool parameters = false, const bool capture = false)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return false; // not a statement
		}
		Token* const tok = static_<Token>(token);
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		const Ptr symbol = tok->symbol();
		if (tag == 'P' && symbol->is_("("))
		{
			_next_();
			_list_(scope, shoal, finalized, flock, sym_(")"), parameters, capture);
			return true; // is a statement
		}
		return false; // not a statement
	}

	inline void _list_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const Ptr& flock, const Ptr& close, const bool parameters = false, const bool capture = false)
	{
		Flock* const flk = static_<Flock>(flock);
		bool parameter = parameters || capture;
		Ptr captured;
		bool punctuation = false;
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			Token* const tok = static_<Token>(token);
			if (token->is_("."))
			{
				throw tok->error_("Parser ERROR: open without close");
			}
			const char tag = tok->tag_();
			if (tag == 'E') // error
			{
				throw tok->error_("Tokenizer ERROR");
			}
			const Ptr symbol = tok->symbol();
			if (first)
			{
				if (tag == 'P') // punctuation
				{
					if (symbol->is_(close))
					{
						if (close->is_(">>"))
						{
							throw tok->error_("Parser ERROR: list expecting single item instead of none");
						}
						_next_();
						return;
					}
					if (symbol->is_(","))
					{
						throw tok->error_("Parser ERROR: list open followed immediately by ,");
					}
				}
			}
			else if (punctuation)
			{
				if (tag == 'P') // punctuation
				{
					if ((symbol->is_(close) || symbol->is_(",")) && parameter)
					{
						if (capture)
						{
							const std::string& s = static_<Symbol>(captured)->get_();
							const Ptr cap = Flock::mut_();
							if (s[0] == '$')
							{
								static_<Flock>(cap)->push_back_(sym_(s.substr(1)));
								flk->push_back_(Expression::fin_(token, sym_("shared_at_"), cap));
							}
							else if (s == "|")
							{
								flk->push_back_(Expression::fin_(token, sym_("me_"), cap));
							}
							else
							{
								static_<Flock>(cap)->push_back_(captured);
								flk->push_back_(Expression::fin_(token, sym_("local_"), cap));
							}
						}
						else
						{
							flk->push_back_(Expression::fin_(token));
						}
					}
					if (symbol->is_(close))
					{
						_next_();
						return;
					}
					else if (symbol->is_(","))
					{
						if (close->is_(">>"))
						{
							throw tok->error_("Parser ERROR: list expecting single item then close");
						}
						if (!parameter)
						{
							parameter = parameters || capture;
						}
					}
					else if (parameter)
					{
						if (symbol->is_(":="))
						{
							parameter = false;
						}
						else
						{
							throw tok->error_("Parser ERROR: list expecting , := or close");
						}
					}
					else
					{
						throw tok->error_("Parser ERROR: list expecting , or close");
					}
				}
				else if (parameter)
				{
					throw tok->error_("Parser ERROR: list expecting , := or close");
				}
				else
				{
					throw tok->error_("Parser ERROR: list expecting , or close");
				}
				_next_();
				punctuation = false;
				continue;
			}
			if (parameter)
			{
				_next_();
				if (tag == 'N') // name
				{
					flk->push_back_(nothing_()); // cat
					flk->push_back_(symbol);
					if (capture)
					{
						captured = symbol;
					}
				}
				else if (tag == 'P') // punctuation
				{
					if (symbol->is_("<"))
					{
						captured = _cat_(flock, capture);
					}
					else if (capture)
					{
						flk->push_back_(nothing_()); // cat
						captured = _capture_(symbol, flock);
						if (captured->is_nothing_())
						{
							throw tok->error_("Parser ERROR: list expecting capture name");
						}
					}
					else
					{
						throw tok->error_("Parser ERROR: list expecting parameter <cat> name");
					}
				}
				else
				{
					throw tok->error_("Parser ERROR: list expecting parameter <cat> name");
				}
			}
			else
			{
				flk->push_back_(_parse_(scope, shoal, finalized, true));
			}
			punctuation = true;
		}
	}

	inline const Ptr _cat_(const Ptr& flock, const bool capture)
	{
		// add cat and default/captured to flock, return captured
		Flock* const flk = static_<Flock>(flock);

		Ptr token;
		flk->push_back_(_scope_key_(token));
		Token* tok = static_<Token>(token);

		Ptr symbol;
		for (bool first = true; true; first = false)
		{
			token = _token_();
			tok = static_<Token>(token);
			if (token->is_("."))
			{
				throw tok->error_("Parser ERROR: cat < without >");
			}
			const char tag = tok->tag_();
			if (tag == 'E') // error
			{
				throw tok->error_("Tokenizer ERROR");
			}
			symbol = tok->symbol();
			_next_();
			if (first)
			{
				if (tag == 'P' && symbol->is_(">"))
				{
					continue;
				}
				throw tok->error_("Parser ERROR: cat < without >");
			}
			else
			{
				if (tag == 'N') // name
				{
					flk->push_back_(symbol);
					return capture ? symbol : nothing_();
				}
				else if (capture && tag == 'P')
				{
					break;
				}
				throw tok->error_("Parser ERROR: list expecting <cat> name");
			}
		}
		const Ptr captured = _capture_(symbol, flock);
		if (captured->is_nothing_())
		{
			throw tok->error_("Parser ERROR: list expecting capture <cat> name");
		}
		return captured;
	}

	inline const Ptr _capture_(const Ptr& symbol, const Ptr& flock)
	{
		if (symbol->is_("$") || symbol->is_("|"))
		{
			const Ptr captured = symbol->is_("|") ? symbol : static_<Symbol>(symbol)->add_(_name_());
			static_<Flock>(flock)->push_back_(captured);
			return captured;
		}
		return nothing_();
	}

	inline const bool _map_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const Ptr& flock)
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
			Token* const tok = static_<Token>(token);
			if (token->is_("."))
			{
				throw tok->error_("Parser ERROR: { without }");
			}
			const char tag = tok->tag_();
			if (tag == 'E') // error
			{
				throw tok->error_("Tokenizer ERROR");
			}
			const Ptr symbol = tok->symbol();
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
						throw tok->error_("Parser ERROR: { followed immediately by ,");
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
				throw tok->error_("Parser ERROR: {: not followed immediately by }");
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
								throw tok->error_("Parser ERROR: last key with missing value");
							}
							_next_();
							return is_map;
						}
						else if (symbol->is_(":") || symbol->is_("::"))
						{
							if (not_map)
							{
								throw tok->error_("Parser ERROR: key with unexpected value");
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
								throw tok->error_("Parser ERROR: key with missing value");
							}
							_next_();
							not_map = true;
							key = false;
							punctuation = false;
							continue;
						}
						else
						{
							throw tok->error_("Parser ERROR: key followed by unexpected punctuation");
						}
					}
					throw tok->error_("Parser ERROR: key not followed by punctuation");
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
						throw tok->error_("Parser ERROR: value followed by unexpected punctuation");
					}
				}
				throw tok->error_("Parser ERROR: value not followed by punctuation");
			}
			if (key)
			{
				add_scope = _parse_(scope, shoal, finalized, true);
				flk->push_back_(add_scope);
			}
			else
			{
				const Ptr add_scope_symbol = Expression::immediate_(add_scope);
				Symbol* const add_scope_sym = dynamic_<Symbol>(add_scope_symbol);
				const Ptr new_scope = add_scope_sym
					? ( scope->is_nothing_()
						? add_scope_symbol
						: sym_(static_<Symbol>(scope)->get_() + "::" + add_scope_sym->get_())
					)
					: scope;
				const Ptr value = _parse_(new_scope, shoal, finalized, true);
				flk->push_back_(value);
				if (add_shoal)
				{
					const Ptr thing = static_<Expression>(value)->get_();
					if (!thing->is_nothing_())
					{
						static_<Shoal>(shoal)->update_(new_scope, thing);
					}
				}
			}
			punctuation = true;
		}
		return is_map;
	}

	inline const Ptr _name_(const Ptr& flock = Flock::mut_())
	{
		const Ptr token = _token_();
		Token* const tok = static_<Token>(token);
		if (token->is_("."))
		{
			throw tok->error_("Parser ERROR: stop instead of name");
		}
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
		{
			throw tok->error_("Parser ERROR: literal instead of name");
		}
		if (tag == 'P') // punctuation
		{
			throw tok->error_("Parser ERROR: punctuation instead of name");
		}
		if (tag == 'N') // name
		{
			_next_();
			static_<Flock>(flock)->push_back_(tok->symbol());
		}
		return tok->symbol();
	}

	inline const Ptr _scope_(const Ptr& scope, const Ptr& shoal, const Ptr& flock, const bool relative)
	{
		Ptr token;
		const Ptr key = _scope_key_(token);
		const Ptr key_flock = Flock::mut_();
		Flock* const key_flk = static_<Flock>(key_flock);
		key_flk->push_back_(shoal);
		key_flk->push_back_(key);
		if (relative)
		{
			key_flk->push_back_(scope);
			return Expression::fin_(token, sym_("relative_scope_"), key_flock);
		}
		return Expression::fin_(token, sym_("shared_scope_"), key_flock);
	}

	inline const Ptr _scope_key_(Ptr& token)
	{
		Ptr key = nothing_();
		bool punctuation = false;
		for (bool first = true; true; first = false)
		{
			token = _token_();
			if (token->is_("."))
			{
				break;
			}
			Token* const tok = static_<Token>(token);
			const char tag = tok->tag_();
			if (tag == 'E') // error
			{
				throw tok->error_("Tokenizer ERROR");
			}
			const Ptr symbol = tok->symbol();
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
					key = sym_(static_<Symbol>(key)->get_() + "::" + static_<Symbol>(symbol)->get_());
				}
				else
				{
					throw tok->error_("Parser ERROR: shared scope :: not followed by name");
				}
			}
			_next_();
			punctuation = true;
		}
		return key;
	}
	
	inline const bool _update_(const Ptr& scope, const Ptr& shoal, const Ptr& finalized, const Ptr& flock, const Ptr& name, bool& insert)
	{
		const Ptr token = _token_();
		if (token->is_("."))
		{
			return false; // break
		}
		Flock* const flk = static_<Flock>(flock);
		Token* const tok = static_<Token>(token);
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		const Ptr symbol = tok->symbol();
		if (tag == 'P')
		{
			if (symbol->is_(":="))
			{
				_next_();
				flk->push_back_(_parse_(scope, shoal, finalized, true));
				return false; // break
			}
			if (symbol->is_("#="))
			{
				insert = true;
				if (!static_<Herd>(finalized)->insert_(name))
				{
					throw tok->error_("Parser ERROR: attempt to reassign final name");
				}
				_next_();
				flk->push_back_(_parse_(scope, shoal, finalized, true));
				return false; // break
			}
		}
		return true; // continue
	}
};

//======================================================================
// class Parser
//======================================================================

} // namespace strange

#endif
