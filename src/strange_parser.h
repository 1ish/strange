#ifndef COM_ONEISH_STRANGE_PARSER_H
#define COM_ONEISH_STRANGE_PARSER_H

#include "strange_core.h"
#include "strange_reference.h"
#include "strange_expression.h"
#include "strange_tokenizer.h"
#include "strange_weak.h"

namespace strange
{
class Parser;

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
			const auto shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Parser::mut, "tokenizer"));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	inline const bool good_()
	{
		const auto tokenizer = dynamic_<Tokenizer>(_tokenizer);
		if (tokenizer)
		{
			return tokenizer->good_();
		}
		return !_tokenizer->invoke_("good")->is_nothing_();
	}

	inline const Ptr good(const Ptr& ignore)
	{
		const auto tokenizer = dynamic_<Tokenizer>(_tokenizer);
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
		const Ptr expression = _parse_(nothing_(), shoal, Herd::mut_(), Shoal::mut_(), Weak::mut_(nothing_()), true);
		shoal->finalize_();
		return expression;
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Parser");
		return TYPE;
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::Parser>");
		return CAT;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = [this]()
		{
			const Ptr cats = Herd::mut_();
			const auto herd = static_<Herd>(cats);
			herd->self_add_(Stateful::cats_());
			herd->insert_(Parser::cat_());
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

	inline const Ptr _parse_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const bool right, const bool key = false)
	{
		Ptr token;
		Ptr result;
		for (bool first = true, cont = true; cont; first = false, cont = cont && right)
		{
			token = _token_();
			if (token->is_stop_())
			{
				break;
			}
			const auto tok = static_<Token>(token);
			const char tag = tok->tag_();
			if (tag == 'E') // error
			{
				throw tok->error_("Tokenizer ERROR");
			}
			const Ptr symbol = tok->symbol();
			const Ptr flock = Flock::mut_();
			const auto flk = static_<Flock>(flock);
			static const Ptr local = sym_("local_");
			static const Ptr invoke = sym_("invoke_");
			static const Ptr at = sym_("at");
			const Ptr statement = Reference::mut_(invoke);
			const auto smt = static_<Reference>(statement);
			if (first)
			{
				_next_();
				if (tag == 'S' || tag == 'L' || tag == 'I' || tag == 'F') // literal
				{
					result = Expression::fin_(token, tok->value_());
				}
				else if (tag == 'N') // name
				{
					if (symbol->is_("lambda_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock, true, true)) // parameters/capture
						{
							if (flk->size_() % 3 == 0) // <cat> param := capture
							{
								const Ptr nested = Flock::mut_();
								const auto nst = static_<Flock>(nested);
								if (_statement_(scope, shoal, fixed, cats, creator, nested, true)) // parameters
								{
									if (nst->size_() % 3 == 0) // <cat> param := default
									{
										nst->push_back_(_parse_(scope, shoal, Herd::mut_(), Shoal::mut_(), creator, false)); // create new fixed/cats scope
										flk->push_back_(Expression::fin_(token, sym_("function_"), nested));
										result = Expression::fin_(token, symbol, flock);
										continue;
									}
								}
								throw tok->error_("Parser ERROR: invalid lambda_ function_");
							}
							throw tok->error_("Parser ERROR: invalid lambda_");
						}
					}
					else if (symbol->is_("function_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock, true)) // parameters
						{
							if (flk->size_() % 3 == 0) // <cat> param := default
							{
								flk->push_back_(_parse_(scope, shoal, Herd::mut_(), Shoal::mut_(), creator, false)); // create new fixed/cats scope
								result = Expression::fin_(token, Function::fin_(Expression::fin_(token, symbol, flock)));
								continue;
							}
							throw tok->error_("Parser ERROR: invalid function_");
						}
					}
					else if (symbol->is_("mutation_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock, true)) // parameters
						{
							if (flk->size_() % 3 == 0) // <cat> param := default
							{
								flk->push_back_(_parse_(scope, shoal, Herd::mut_(), Shoal::mut_(), creator, false)); // create new fixed/cats scope
								result = Expression::fin_(token, Mutation::fin_(Expression::fin_(token, sym_("function_"), flock)));
								continue;
							}
							throw tok->error_("Parser ERROR: invalid mutation_");
						}
					}
					else if (symbol->is_("extraction_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock, true)) // parameters
						{
							if (flk->size_() % 3 == 0) // <cat> param := default
							{
								flk->push_back_(_parse_(scope, shoal, Herd::mut_(), Shoal::mut_(), creator, false)); // create new fixed/cats scope
								result = Expression::fin_(token, Extraction::fin_(Expression::fin_(token, sym_("function_"), flock)));
								continue;
							}
							throw tok->error_("Parser ERROR: invalid extraction_");
						}
					}
					else if (symbol->is_("creator_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock, true)) // cat parameters
						{
							if (flk->size_() % 3 == 0) // <cat> param := default
							{
								const Ptr nested = Flock::mut_();
								const auto nst = static_<Flock>(nested);
								const Ptr new_creator = Weak::mut_(nothing_());
								nst->push_back_(new_creator);
								if (_statement_(scope, shoal, fixed, cats, creator, nested))
								{
									nst->push_back_(_parse_(scope, shoal, Herd::mut_(), Shoal::mut_(), new_creator, false)); // create new fixed/cats scope
									flk->push_back_(Expression::fin_(token, sym_("creation_"), nested));
									result = Expression::fin_(token, Creation::fin_(Expression::fin_(token, symbol, flock)));
									continue;
								}
								throw tok->error_("Parser ERROR: invalid creator_ creation_");
							}
							throw tok->error_("Parser ERROR: invalid creator_");
						}
					}
					else if (symbol->is_("creation_"))
					{
						const Ptr new_creator = Weak::mut_(nothing_());
						flk->push_back_(new_creator);
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							flk->push_back_(_parse_(scope, shoal, fixed, cats, new_creator, false)); // right
							result = Expression::fin_(token, Creation::fin_(Expression::fin_(token, symbol, flock)));
							continue;
						}
						flk->clear_();
					}
					else if (symbol->is_("fixed_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Fixed::fin_(Expression::fin_(token)));
								continue;
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Fixed::fin_(flk->at_(0)));
								continue;
							}
							throw tok->error_("Parser Error: invalid fixed_");
						}
					}
					else if (symbol->is_("mutable_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Mutable::fin_(Expression::fin_(token)));
								continue;
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Mutable::fin_(flk->at_(0)));
								continue;
							}
							throw tok->error_("Parser Error: invalid mutable_");
						}
					}
					else if (symbol->is_("variable_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Variable::fin_(Expression::fin_(token)));
								continue;
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Variable::fin_(flk->at_(0)));
								continue;
							}
							throw tok->error_("Parser Error: invalid variable_");
						}
					}
					else if (symbol->is_("changeable_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								result = Expression::fin_(token, Changeable::fin_(Expression::fin_(token)));
								continue;
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, Changeable::fin_(flk->at_(0)));
								continue;
							}
							throw tok->error_("Parser Error: invalid changeable_");
						}
					}
					else if (symbol->is_("break_") || symbol->is_("continue_") || symbol->is_("return_") || symbol->is_("throw_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							const int64_t size = flk->size_();
							if (size == 0)
							{
								_wrap_(token, nothing_(), flock);
								continue;
							}
							else if (size == 1)
							{
								result = Expression::fin_(token, symbol, flock);
								continue;
							}
							throw tok->error_("Parser ERROR: invalid break_/continue_/return_/throw_");
						}
					}
					else if (symbol->is_("error_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							result = Expression::fin_(token, symbol, flock);
							continue;
						}
					}
					else if (symbol->is_("catch_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							if (flk->size_() == 2)
							{
								result = Expression::fin_(token, symbol, flock);
								continue;
							}
							throw tok->error_("Parser ERROR: invalid catch_");
						}
					}
					else if (symbol->is_("if_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							const int64_t size = flk->size_();
							if (size == 2 || size == 3)
							{
								result = Expression::fin_(token, symbol, flock);
								continue;
							}
							throw tok->error_("Parser ERROR: invalid if_");
						}
					}
					else if (symbol->is_("while_") || symbol->is_("do_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							if (flk->size_() == 1)
							{
								flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, false));
								result = Expression::fin_(token, symbol, flock);
								continue;
							}
							throw tok->error_("Parser ERROR: invalid while_/do_");
						}
					}
					else if (symbol->is_("for_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							if (flk->size_() == 3)
							{
								flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, false));
								result = Expression::fin_(token, symbol, flock);
								continue;
							}
							throw tok->error_("Parser ERROR: invalid for_");
						}
					}
					else if (symbol->is_("import_"))
					{
						if (_statement_(scope, shoal, fixed, cats, creator, flock))
						{
							if (flk->size_() >= 1)
							{
								const Ptr it = flock->iterator_();
								for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
								{
									const auto lake = dynamic_<Lake>(Expression::immediate_(i)->invoke_("to_lake"));
									if (!lake)
									{
										throw tok->error_("Parser ERROR: invalid import_ filename");
									}
									const Ptr river = River::mut_(lake->get_(), true);
									if (!static_<River>(river)->good_())
									{
										throw tok->error_("Parser ERROR: invalid import_ file: " + lake->get_());
									}
									result = static_<Parser>(Parser::mut_(Tokenizer::mut_(river)))->_parse_(nothing_(), shoal, fixed, cats, creator, true);
								}
								continue;
							}
							throw tok->error_("Parser ERROR: invalid import_");
						}
					}
					// local at/update name
					flk->push_back_(symbol);
					bool insert = false;
					cont = _update_(scope, shoal, fixed, cats, creator, flock, symbol, insert);
					result = Expression::fin_(token, local, flock);
				}
				else if (tag == 'P') // punctuation
				{
					if (symbol->is_("$")) // shared at/update
					{
						_name_(flock);
						bool insert = false;
						cont = _update_(scope, shoal, fixed, cats, creator, flock, static_<Symbol>(symbol)->add_(flk->at_(0)), insert);
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
						flk->push_back_(creator);
						_dot_(scope, shoal, fixed, cats, creator, statement, flock, true); // me dot
						result = Expression::fin_(token, smt->get_(), flock);
					}
					else if (symbol->is_("|:.")) // me operation
					{
						flk->push_back_(creator);
						_name_(flock);
						result = Expression::fin_(token, sym_("intimation_"), flock);
					}
					else if (symbol->is_("|::")) // me creator
					{
						flk->push_back_(creator);
						_name_(flock);
						result = Expression::fin_(token, sym_("me_creator_"), flock);
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
					else if (false) //TODO container?
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
						_list_(scope, shoal, fixed, cats, creator, flock, sym_(")"));
						result = Expression::fin_(token, sym_("block_"), flock);
					}
					else if (symbol->is_("[")) // flock
					{
						_list_(scope, shoal, fixed, cats, creator, flock, sym_("]"));
						result = Expression::fin_(token, sym_("flock_"), flock);
					}
					else if (symbol->is_("{")) // creator, shoal or herd
					{
						if (_map_(scope, shoal, fixed, cats, creator, flock))
						{
							if (flk->size_() == 1 && flk->at_(0) == creator)
							{
								result = Expression::fin_(token, sym_("me_creator_"), flock);
							}
							else
							{
								result = Expression::fin_(token, sym_("shoal_"), flock);
							}
						}
						else
						{
							result = Expression::fin_(token, sym_("herd_"), flock);
						}
					}
					else if (symbol->is_("<")) // cat
					{
						result = Expression::fin_(token, _cat_nest_());
					}
					else if (symbol->is_("<<")) // iterator
					{
						_list_(scope, shoal, fixed, cats, creator, flock, sym_(">>"));
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
					if (_thing_(scope, shoal, fixed, cats, creator, statement, flock, key))
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

	inline const bool _thing_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const Ptr& statement, const Ptr& flock, const bool key, const int64_t min_precedence = 0)
	{
		const Ptr token = _token_();
		if (token->is_stop_())
		{
			return false; // break
		}
		const auto flk = static_<Flock>(flock);
		const auto tok = static_<Token>(token);
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		const Ptr symbol = tok->symbol();
		const auto smt = static_<Reference>(statement);
		if (tag == 'P') // punctuation
		{
			const int64_t precedence_inc = tok->precedence_() + 1;
			if (precedence_inc <= min_precedence)
			{
				return false; // break
			}
			if (symbol->is_("."))
			{
				_next_();
				_dot_(scope, shoal, fixed, cats, creator, statement, flock, false);
			}
			else if (symbol->is_("(") || symbol->is_("{")) // block or shoal
			{
				flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, false));
				smt->set_(sym_("invoke_iterable_"));
			}
			else if (symbol->is_("[")) // flock
			{
				_next_();
				_list_(scope, shoal, fixed, cats, creator, flock, sym_("]"));
			}
			else if (symbol->is_("<<")) // iterator
			{
				_next_();
				_list_(scope, shoal, fixed, cats, creator, flock, sym_(">>"));
				smt->set_(sym_("invoke_iterator_"));
			}
			else if (!key && symbol->is_("::"))
			{
				_next_();
				flk->push_back_(sym_("at"));
				_name_(flock, true); // wrap
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("%"))
			{
				_next_();
				flk->push_back_(sym_("modulo"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("%="))
			{
				_next_();
				flk->push_back_(sym_("self_modulo"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("%%"))
			{
				_next_();
				flk->push_back_(sym_("xor"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("!%"))
			{
				_next_();
				flk->push_back_(sym_("xnor"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("+"))
			{
				_next_();
				flk->push_back_(sym_("add"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("+="))
			{
				_next_();
				flk->push_back_(sym_("self_add"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("-="))
			{
				_next_();
				flk->push_back_(sym_("self_subtract"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("*="))
			{
				_next_();
				flk->push_back_(sym_("self_multiply"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("/"))
			{
				_next_();
				flk->push_back_(sym_("divide"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("/="))
			{
				_next_();
				flk->push_back_(sym_("self_divide"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("=="))
			{
				_next_();
				flk->push_back_(sym_("same"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("!="))
			{
				_next_();
				flk->push_back_(sym_("different"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("!&"))
			{
				_next_();
				flk->push_back_(sym_("nand"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("||"))
			{
				_next_();
				flk->push_back_(sym_("or"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("!|"))
			{
				_next_();
				flk->push_back_(sym_("nor"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_(">@"))
			{
				_next_();
				flk->push_back_(sym_("push_front"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("@="))
			{
				_next_();
				flk->push_back_(sym_("update"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("@+"))
			{
				_next_();
				flk->push_back_(sym_("insert"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("@-"))
			{
				_next_();
				flk->push_back_(sym_("erase"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
			else if (symbol->is_(".!"))
			{
				_next_();
				flk->push_back_(sym_("is_not_stop"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_(".?"))
			{
				_next_();
				flk->push_back_(sym_("is_stop"));
				smt->set_(sym_("operate_"));
			}
			else if (symbol->is_("<"))
			{
				_next_();
				flk->push_back_(sym_("less_than"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_(">"))
			{
				_next_();
				flk->push_back_(sym_("greater_than"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_("<="))
			{
				_next_();
				flk->push_back_(sym_("less_or_equal"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
			}
			else if (symbol->is_(">="))
			{
				_next_();
				flk->push_back_(sym_("greater_or_equal"));
				_member_(scope, shoal, fixed, cats, creator, statement, flock);
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
				flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, false));
				smt->set_(sym_("perform_"));
			}
			else
			{
				return false; // break
			}
			const Ptr stmnt = smt->get_();
			if (stmnt->is_("intimate_iterable_") || stmnt->is_("operate_iterable_") || stmnt->is_("perform_"))
			{
				const int64_t index = stmnt->is_("perform_") ? 1 : 2;
				for (;;)
				{
					const Ptr next_statement = Reference::mut_(sym_("invoke_"));
					const auto next_smt = static_<Reference>(next_statement);
					const Ptr next_flock = Flock::mut_();
					const auto next_flk = static_<Flock>(next_flock);
					next_flk->push_back_(flk->at_(index));
					if (!_thing_(scope, shoal, fixed, cats, creator, next_statement, next_flock, key, precedence_inc))
					{
						break;
					}
					flk->update_(index, Expression::fin_(token, next_smt->get_(), next_flock));
				}
			}
		}
		else if (min_precedence)
		{
			return false;
		}
		else
		{
			flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, false));
			smt->set_(sym_("invoke_iterable_"));
		}
		return true; // continue
	}

	inline void _dot_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const Ptr& statement, const Ptr& flock, const bool me_dot)
	{
		const Ptr token = _token_();
		const auto tok = static_<Token>(token);
		if (token->is_stop_())
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
		const auto flk = static_<Flock>(flock);
		if (tag == 'N') // name
		{
			_next_();
			flk->push_back_(symbol);
			_member_(scope, shoal, fixed, cats, creator, statement, flock, me_dot);
		}
	}

	inline void _member_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const Ptr& statement, const Ptr& flock, const bool me_dot = false)
	{
		const Ptr token = _token_();
		const auto smt = static_<Reference>(statement);
		if (token->is_stop_())
		{
			smt->set_(sym_(me_dot ? "private_" : "public_"));
			return;
		}
		const auto flk = static_<Flock>(flock);
		const auto tok = static_<Token>(token);
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
				_list_(scope, shoal, fixed, cats, creator, flock, sym_("]"));
				smt->set_(sym_(me_dot ? "intimate_" : "operate_"));
			}
			else if (symbol->is_("(") || symbol->is_("{")) // block or shoal
			{
				flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, false));
				smt->set_(sym_(me_dot ? "intimate_iterable_" : "operate_iterable_"));
			}
			else if (symbol->is_("<<")) // iterator
			{
				_next_();
				_list_(scope, shoal, fixed, cats, creator, flock, sym_(">>"));
				smt->set_(sym_(me_dot ? "intimate_iterator_" : "operate_iterator_"));
			}
			else if (symbol->is_(":=")) // set attribute
			{
				_next_();
				flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, true));
				smt->set_(sym_(me_dot ? "set_intimate_" : "set_attribute_"));
			}
			else
			{
				smt->set_(sym_(me_dot ? "private_" : "public_"));
			}
		}
		else
		{
			flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, false));
			smt->set_(sym_(me_dot ? "intimate_iterable_" : "operate_iterable_"));
		}
	}

	inline const bool _statement_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const Ptr& flock, const bool parameters = false, const bool capture = false)
	{
		const Ptr token = _token_();
		if (token->is_stop_())
		{
			return false; // not a statement
		}
		const auto tok = static_<Token>(token);
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		const Ptr symbol = tok->symbol();
		if (tag == 'P' && symbol->is_("("))
		{
			_next_();
			_list_(scope, shoal, fixed, cats, creator, flock, sym_(")"), parameters, capture);
			return true; // is a statement
		}
		return false; // not a statement
	}

	inline void _list_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const Ptr& flock, const Ptr& close, const bool parameters = false, const bool capture = false)
	{
		const auto flk = static_<Flock>(flock);
		bool parameter = parameters || capture;
		Ptr captured;
		bool punctuation = false;
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			const auto tok = static_<Token>(token);
			if (token->is_stop_())
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
					flk->push_back_(nothing_()); // no cat
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
				flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, true));
			}
			punctuation = true;
		}
	}

	inline const Ptr _cat_nest_()
	{
		std::string category = "<";
		Ptr token;
		const std::string name = static_<Symbol>(_scope_key_(token))->get_();
		auto tok = static_<Token>(token);
		category += name;

		bool comma = false;
		bool close = false;
		Ptr symbol;
		for (bool first = true; true; first = false)
		{
			token = _token_();
			tok = static_<Token>(token);
			if (token->is_stop_())
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
				if (tag == 'P')
				{
					if (symbol->is_(">"))
					{
						break;
					}
					if (symbol->is_("["))
					{
						if (name.empty())
						{
							throw tok->error_("Parser ERROR: cat without a name");
						}
						category += "[";
						continue;
					}
				}
			}
			else
			{
				if (tag == 'P')
				{
					if (symbol->is_("]"))
					{
						while (category.length() > 3 && category.substr(category.length() - 3) == ",<>")
						{
							category = category.substr(0, category.length() - 3);
						}
						if (category.length() > 2 && category.substr(category.length() - 2) == "<>")
						{
							category = category.substr(0, category.length() - 2);
						}
						const char last = category[category.length() - 1];
						if (last == '[')
						{
							category = category.substr(0, category.length() - 1);
						}
						else if (last == ',')
						{
							throw tok->error_("Parser ERROR: bad cat comma");
						}
						else
						{
							category += "]";
						}
						close = true;
						continue;
					}
					if (close)
					{
						if (symbol->is_(">"))
						{
							break;
						}
					}
					else if (comma)
					{
						comma = false;
						if (symbol->is_(","))
						{
							category += ",";
							continue;
						}
					}
					else
					{
						comma = true;
						if (symbol->is_("<"))
						{
							category += static_<Cat>(_cat_nest_())->get_();
							continue;
						}
					}
				}
			}
			throw tok->error_("Parser ERROR: bad cat");
		}
		return Cat::fin_(category + ">");
	}

	inline const Ptr _cat_(const Ptr& flock, const bool capture)
	{
		// add cat and default/captured to flock, return captured
		const auto flk = static_<Flock>(flock);

		flk->push_back_(_cat_nest_());

		const Ptr token = _token_();
		const auto tok = static_<Token>(token);
		Ptr symbol;
		if (token->is_stop_())
		{
			throw tok->error_("Parser ERROR: cat stop");
		}
		const char tag = tok->tag_();
		if (tag == 'E') // error
		{
			throw tok->error_("Tokenizer ERROR");
		}
		symbol = tok->symbol();
		_next_();
		if (tag == 'N') // name
		{
			flk->push_back_(symbol);
			return capture ? symbol : nothing_();
		}
		else if (!capture || tag != 'P')
		{
			throw tok->error_("Parser ERROR: list expecting <cat> name");
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

	inline const bool _map_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const Ptr& flock)
	{
		const auto flk = static_<Flock>(flock);
		bool is_map = false;
		bool not_map = false;
		bool empty = false;
		bool me_creator = false;
		bool key = true;
		bool punctuation = false;
		bool add_shoal = false;
		Ptr add_scope = nothing_();
		Ptr attribute = nothing_();
		for (bool first = true; true; first = false)
		{
			const Ptr token = _token_();
			const auto tok = static_<Token>(token);
			if (token->is_stop_())
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
						is_map = true;
						empty = true;
						continue;
					}
					else if (symbol->is_("::"))
					{
						_next_();
						is_map = true;
						me_creator = true;
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
			else if (me_creator)
			{
				if (tag == 'P' && symbol->is_("}"))
				{
					_next_();
					flk->push_back_(creator);
					return is_map;
				}
				throw tok->error_("Parser ERROR: {:: not followed immediately by }");
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
						if (symbol->is_(":#") || symbol->is_(":%") || symbol->is_(":*") || symbol->is_(":~"))
						{
							attribute = symbol;
						}
						else
						{
							attribute = nothing_();
						}
						if (!attribute->is_nothing_() || symbol->is_(":") || symbol->is_("::"))
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
				add_scope = _parse_(scope, shoal, fixed, cats, creator, true, true); // right, key
				flk->push_back_(add_scope);
			}
			else
			{
				const Ptr add_scope_symbol = Expression::immediate_(add_scope);
				const auto add_scope_sym = dynamic_<Symbol>(add_scope_symbol);
				const Ptr new_scope = add_scope_sym
					? ( scope->is_nothing_()
						? add_scope_symbol
						: sym_(static_<Symbol>(scope)->get_() + "::" + add_scope_sym->get_())
					)
					: scope;
				Ptr value = _parse_(new_scope, shoal, fixed, cats, creator, true);
				if (attribute->is_(":#")) // fixed
				{
					value = Expression::fin_(token, Fixed::fin_(value));
				}
				else if (attribute->is_(":*")) // mutable
				{
					value = Expression::fin_(token, Mutable::fin_(value));
				}
				else if (attribute->is_(":%")) // variable
				{
					value = Expression::fin_(token, Variable::fin_(value));
				}
				else if (attribute->is_(":~")) // changeable
				{
					value = Expression::fin_(token, Changeable::fin_(value));
				}
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

	inline const Ptr _name_(const Ptr& flock = Flock::mut_(), const bool wrap = false)
	{
		const Ptr token = _token_();
		const auto tok = static_<Token>(token);
		if (token->is_stop_())
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
			if (wrap)
			{
				_wrap_(token, tok->symbol(), flock);
			}
			else
			{
				static_<Flock>(flock)->push_back_(tok->symbol());
			}
		}
		return tok->symbol();
	}

	inline const Ptr _scope_(const Ptr& scope, const Ptr& shoal, const Ptr& flock, const bool relative)
	{
		Ptr token;
		const Ptr key = _scope_key_(token);
		const Ptr key_flock = Flock::mut_();
		const auto key_flk = static_<Flock>(key_flock);
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
			if (token->is_stop_())
			{
				break;
			}
			const auto tok = static_<Token>(token);
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
	
	inline const bool _update_(const Ptr& scope, const Ptr& shoal, const Ptr& fixed, const Ptr& cats, const Ptr& creator, const Ptr& flock, const Ptr& name, bool& insert)
	{
		const Ptr token = _token_();
		if (token->is_stop_())
		{
			return false; // break
		}
		const auto flk = static_<Flock>(flock);
		const auto tok = static_<Token>(token);
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
				flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, true));
				return false; // break
			}
			if (symbol->is_("#="))
			{
				insert = true;
				if (!static_<Herd>(fixed)->insert_(name))
				{
					throw tok->error_("Parser ERROR: attempt to reassign fixed name");
				}
				_next_();
				flk->push_back_(_parse_(scope, shoal, fixed, cats, creator, true));
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
