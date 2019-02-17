#ifndef COM_ONEISH_STRANGE_EXPRESSION_H
#define COM_ONEISH_STRANGE_EXPRESSION_H

#include "strange_core.h"
#include "strange_misunderstanding.h"
#include "strange_token.h"
#include "strange_weak.h"
#include "strange_method.h"

namespace strange
{
class Expression;
class Operation;
class Function;
class Closure;
class Mutation;
class Extraction;
class Creation;
class Attribute;
class Fixed;
class Mutable;
class Variable;
class Changeable;
class Creature;

//----------------------------------------------------------------------
class Expression : public Thing
//----------------------------------------------------------------------
{
	typedef const Ptr(Expression::*MemberPtr)(const Ptr&) const;

public:
	inline Expression(const Ptr& token, const Ptr& statement, const MemberPtr member, const Ptr& flock)
		: Thing{}
		, _token(token)
		, _statement{ statement }
		, _member{ member }
		, _flock{ flock }
		, _parent{ Weak::mut_(nothing_()) }
	{
	}

	static inline const Ptr fin_(const Ptr& token, const Ptr& statement, const MemberPtr member, const Ptr& flock);

	static inline const Ptr fin_(const Ptr& token, const Ptr& statement, const Ptr& flock);

	static inline const Ptr fin_(const Ptr& token, const Ptr& thing = nothing_())
	{
		const Ptr flock = Flock::mut_();
		static_<Flock>(flock)->push_back_(thing);
		return Expression::fin_(token, sym_("thing_"), &Expression::_thing_, flock);
	}

	static inline const Ptr fin(const Ptr& it)
	{
		const Ptr token = it->next_();
		const Ptr statement = it->next_();
		const Ptr flock = it->next_();
		return fin_(token, statement, flock);
	}

	static inline const Ptr evaluate_(const Ptr& expression, const Ptr& local)
	{
		Expression* const exp = static_<Expression>(expression);
		return (exp->*(exp->_member))(local);
	}

	static inline const Ptr immediate_(const Ptr& expression)
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->update_("$", Shoal::Concurrent::mut_());
		loc->update_("&", stop_());
		return evaluate_(expression, local);
	}

	inline void generate_(const Ptr& generator)
	{
		generator->invoke_("generate_" + static_<Symbol>(_statement)->get_() + "code", _token, _flock);
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::Expression>");
		return CAT;
	}

	inline void parent_(const Ptr& parent)
	{
		static_<Weak>(_parent)->set_(parent);
	}

	inline const Ptr get_() const
	{
		if (_member == &Expression::_thing_)
		{
			return static_<Flock>(_flock)->get_()[0];
		}
		if (_member == &Expression::_shoal_)
		{
			return immediate_(me_()); //TODO can we evaluate this later?
		}
		return nothing_();
	}

private:
	const Ptr _token;
	const Ptr _statement;
	const MemberPtr _member;
	const Ptr _flock;
	const Ptr _parent;

	inline const Ptr _stack_(const std::string& str, const int64_t stack = 1, const Ptr& misunderstanding = Misunderstanding::mut_()) const
	{
		const std::string message = str.empty() ? str : ("Expression ERROR: " + str);
		static_<Token>(_token)->error_(message + '\n' +
			std::to_string(stack) + ": " + static_<Symbol>(_statement)->get_(),
			misunderstanding);
		const Ptr parent = static_<Weak>(_parent)->get_();
		Expression* const p = dynamic_<Expression>(parent);
		if (p)
		{
			p->_stack_("", stack + 1, misunderstanding);
		}
		return misunderstanding;
	}

	inline const Ptr _local_at_(const Ptr& local) const
	{
		return static_<Shoal>(local)->at_(static_<Flock>(_flock)->get_()[0]);
	}

	inline const Ptr _local_update_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr value = Expression::evaluate_(vec[1], local);
			static_<Shoal>(local)->update_(vec[0], value);
			return value;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _shared_at_(const Ptr& local) const
	{
		return static_<Shoal::Concurrent>(static_<Shoal>(local)->at_("$"))->at_(static_<Flock>(_flock)->get_()[0]);
	}

	inline const Ptr _shared_update_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr value = Expression::evaluate_(vec[1], local);
			static_<Shoal::Concurrent>(static_<Shoal>(local)->at_("$"))->update_(vec[0], value);
			return value;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _shared_insert_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			Shoal::Concurrent* const shared = static_<Shoal::Concurrent>(static_<Shoal>(local)->at_("$"));
			const Ptr key = vec[0];
			const Ptr existing = shared->at_(key);
			if (existing->is_nothing_())
			{
				const Ptr value = Expression::evaluate_(vec[1], local);
				if (!shared->insert_(key, value))
				{
					return shared->at_(key);
				}
				return value;
			}
			return existing;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _me_(const Ptr& local) const
	{
		const Ptr thing = static_<Shoal>(local)->at_("|");
		if (thing->is_nothing_())
		{
			throw _stack_("me accessed without a creature");
		}
		return thing;
	}

	inline const Ptr _thing_(const Ptr& local) const
	{
		return static_<Flock>(_flock)->get_()[0];
	}

	inline const Ptr _invoke_(const Ptr& local) const
	{
		try
		{
			const Ptr it = _iterator_(local);
			const Ptr thing = it->next_();
			return thing->invoke(it);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _invoke_iterator_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			return thing->invoke(Expression::evaluate_(vec[1], local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _invoke_iterable_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			const Ptr iterable = Expression::evaluate_(vec[1], local);
			const Ptr feeder = iterable->feeder(thing->eater_());
			if (!feeder->is_nothing_())
			{
				return thing->invoke(feeder);
			}
			return thing->invoke(iterable->iterator_());
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _set_attribute_(const Ptr& local) const;

	inline const Ptr _public_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			const Ptr member = static_<Shoal>(thing->pub_())->at_(vec[1]);
			if (member->is_nothing_())
			{
				throw Dismemberment(thing->cat_(), vec[1]);
			}
			return Method::fin_(thing, member);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _operate_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			const Ptr member = static_<Shoal>(thing->pub_())->at_(vec[1]);
			if (member->is_nothing_())
			{
				throw Dismemberment(thing->cat_(), vec[1]);
			}
			return operate_(thing.get(), member, _iterator_(local, 2));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _operate_iterator_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			const Ptr member = static_<Shoal>(thing->pub_())->at_(vec[1]);
			if (member->is_nothing_())
			{
				throw Dismemberment(thing->cat_(), vec[1]);
			}
			return operate_(thing.get(), member, Expression::evaluate_(vec[2], local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _operate_iterable_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			const Ptr member = static_<Shoal>(thing->pub_())->at_(vec[1]);
			if (member->is_nothing_())
			{
				throw Dismemberment(thing->cat_(), vec[1]);
			}
			const Ptr iterable = Expression::evaluate_(vec[2], local);
			const Ptr feeder = iterable->feeder(member->eater_());
			if (!feeder->is_nothing_())
			{
				return operate_(thing.get(), member, feeder);
			}
			return operate_(thing.get(), member, iterable->iterator_());
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _operation_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			const Ptr member = static_<Shoal>(thing->pub_())->at_(vec[1]);
			if (member->is_nothing_())
			{
				throw Dismemberment(thing->cat_(), vec[1]);
			}
			return member;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _perform_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			const Ptr member = Expression::evaluate_(vec[1], local);
			return Method::fin_(thing, member);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _set_intimate_(const Ptr& local) const;

	inline const Ptr _private_(const Ptr& local) const;

	inline const Ptr _intimate_(const Ptr& local) const;

	inline const Ptr _intimate_iterator_(const Ptr& local) const;

	inline const Ptr _intimate_iterable_(const Ptr& local) const;

	inline const Ptr _intimation_(const Ptr& local) const;

	inline const Ptr _lambda_(const Ptr& local) const;

	inline const Ptr _function_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			Shoal* const shoal = static_<Shoal>(local);
			const Ptr it = shoal->at_("&");
			const std::size_t size_1 = vec.size() - 1;
			for (std::size_t i = 0; i < size_1; i += 3)
			{
				const Ptr cat = vec[i];
				Ptr value = it->next_();
				if (value->is_stop_())
				{
					value = Expression::evaluate_(vec[i + 2], local);
				}
				if (!cat->is_nothing_())
				{
					// check cat
					if (!Cat::check_(value, cat))
					{
						throw _stack_("function passed wrong kind of thing");
					}
				}
				shoal->update_(vec[i + 1], value);
			}
			try
			{
				return Expression::evaluate_(vec[size_1], local);
			}
			catch (const Return& r)
			{
				return r.thing_();
			}
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _creation_(const Ptr& local) const;

	static inline void _merge_(const bool derived, Shoal* const creation, Shoal* const result)
	{
		Ptr cat;
		if (derived)
		{
			cat = creation->at_("cat")->invoke_();
			if (!dynamic_<Cat>(cat))
			{
				throw Disagreement("creation merge cat is not a cat");
			}
		}
		const Ptr cats = creation->at_("cats")->invoke_();
		if (!dynamic_<Herd>(cats))
		{
			throw Disagreement("creation merge cats are not a herd");
		}
		Herd* const herd = static_<Herd>(result->at_("cats")->invoke_());
		for (const auto& it : creation->get_())
		{
			const Ptr key = it.first;
			Symbol* const symbol = dynamic_<Symbol>(key);
			if (!symbol)
			{
				throw Disagreement("creation merge key is not a symbol");
			}
			const Ptr value = it.second;
			if (symbol->is_("cat"))
			{
				if (derived)
				{
					result->update_(key, value);
					herd->insert_(cat);
				}
			}
			else if (symbol->is_("cats"))
			{
				herd->self_add_(cats);
			}
			else if (derived && symbol->get_()[0] == '_')
			{
				result->update_("_" + static_<Cat>(cat)->get_() + symbol->get_(), value);
			}
			else
			{
				result->update_(key, value); //TODO check overrides
			}
		}
	}

	inline const Ptr _shared_scope_(const Ptr& local) const
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr result = static_<Shoal>(vec[0])->at_(vec[1]);
		if (result->is_nothing_())
		{
			throw _stack_("not found in shared scope");
		}
		return result;
	}
	
	inline const Ptr _relative_scope_(const Ptr& local) const
	{
		// search scope from bottom to top
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		Shoal* const shoal = static_<Shoal>(vec[0]);
		const Ptr key = vec[1];
		const std::string& key_str = static_<Symbol>(key)->get_();
		std::string scope = static_<Symbol>(vec[2])->get_();
		for (;;)
		{
			if (scope.empty())
			{
				return shoal->at_(key);
			}
			const Ptr result = shoal->at_(scope + "::" + key_str);
			if (!result->is_nothing_())
			{
				return result;
			}
			const std::size_t pos = scope.rfind("::");
			if (pos == std::string::npos)
			{
				scope = "";
			}
			else
			{
				scope = scope.substr(0, pos);
			}
		}
		throw _stack_("not found in relative scope");
	}

	inline const Ptr _flock_(const Ptr& local) const
	{
		try
		{
			return Flock::mut(_iterator_(local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _flock_iterator_(const Ptr& local) const
	{
		try
		{
			return Flock::mut(Expression::evaluate_(static_<Flock>(_flock)->get_()[0], local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _shoal_(const Ptr& local) const
	{
		try
		{
			return Shoal::mut(_iterator_(local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _herd_(const Ptr& local) const
	{
		try
		{
			return Herd::mut(_iterator_(local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _break_(const Ptr& local) const
	{
		try
		{
			throw Break(Expression::evaluate_(static_<Flock>(_flock)->get_()[0], local), false);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _continue_(const Ptr& local) const
	{
		try
		{
			throw Break(Expression::evaluate_(static_<Flock>(_flock)->get_()[0], local), true);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _return_(const Ptr& local) const
	{
		try
		{
			throw Return(Expression::evaluate_(static_<Flock>(_flock)->get_()[0], local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _error_(const Ptr& local) const
	{
		std::string error;
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const std::size_t size = vec.size();
			for (std::size_t i = 0; i < size; ++i)
			{
				const Ptr thing = Expression::evaluate_(vec[i], local);
				const Ptr to_lake = thing->invoke_("to_lake");
				Lake* const lake = Thing::dynamic_<Lake>(to_lake);
				if (lake)
				{
					error += lake->get_();
				}
			}
		}
		catch (const std::exception& err)
		{
			error = err.what();
		}
		throw _stack_(error);
	}

	inline const Ptr _throw_(const Ptr& local) const
	{
		try
		{
			throw Expression::evaluate_(static_<Flock>(_flock)->get_()[0], local);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _catch_(const Ptr& local) const
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		try
		{
			return Expression::evaluate_(vec[0], local);
		}
		catch (const Ptr& thing)
		{
			if (!thing->is_nothing_())
			{
				static_<Shoal>(local)->update_("%", thing);
			}
			return Expression::evaluate_(vec[1], local);
		}
		catch (const std::exception& err)
		{
			static_<Shoal>(local)->update_("%", _stack_(err.what()));
			return Expression::evaluate_(vec[1], local);
		}
	}

	inline const Ptr _block_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const std::size_t size = vec.size();
			Ptr result = nothing_();
			for (std::size_t i = 0; i < size; ++i)
			{
				result = Expression::evaluate_(vec[i], local);
			}
			return result;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _if_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			if (!Expression::evaluate_(vec[0], local)->is_nothing_())
			{
				return Expression::evaluate_(vec[1], local);
			}
			return nothing_();
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _if_else_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			if (!Expression::evaluate_(vec[0], local)->is_nothing_())
			{
				return Expression::evaluate_(vec[1], local);
			}
			return Expression::evaluate_(vec[2], local);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _while_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			Ptr result = nothing_();
			while (!Expression::evaluate_(vec[0], local)->is_nothing_())
			{
				try
				{
					result = Expression::evaluate_(vec[1], local);
				}
				catch (const Break& b)
				{
					result = b.thing_();
					if (b.continue_())
					{
						continue;
					}
					break;
				}
			}
			return result;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _do_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			Ptr result = nothing_();
			do
			{
				try
				{
					result = Expression::evaluate_(vec[1], local);
				}
				catch (const Break& b)
				{
					result = b.thing_();
					if (b.continue_())
					{
						continue;
					}
					break;
				}
			} while (!Expression::evaluate_(vec[0], local)->is_nothing_());
			return result;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _for_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			Ptr result = nothing_();
			for (Expression::evaluate_(vec[0], local);
				!Expression::evaluate_(vec[1], local)->is_nothing_();
				Expression::evaluate_(vec[2], local))
			{
				try
				{
					result = Expression::evaluate_(vec[3], local);
				}
				catch (const Break& b)
				{
					result = b.thing_();
					if (b.continue_())
					{
						continue;
					}
					break;
				}
			}
			return result;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _iterator_(const Ptr& local, const int64_t pos = 0) const
	{
		return Iterator::mut_(static_<Flock>(_flock)->get_(), local, pos);
	}

	class Iterator : public Stateful
	{
	public:
		inline Iterator(const std::vector<Ptr>& vec, const Ptr& local, const int64_t pos)
			: Stateful{}
			, _elements{ vec }
			, _local{ local }
			, _pos{ pos }
		{
		}

		virtual inline const Ptr next_() override
		{
			if (_pos >= int64_t(_elements.size()))
			{
				return stop_();
			}
			return Expression::evaluate_(_elements[_pos++], _local);
		}

		virtual inline const Ptr copy_() const override
		{
			return mut_(_elements, _local, _pos);
		}

		static inline const Ptr mut_(const std::vector<Ptr>& vec, const Ptr& local, const int64_t pos)
		{
			return make_<Iterator>(vec, local, pos);
		}

		virtual inline const Ptr cat_() const override
		{
			static const Ptr CAT = Cat::fin_("<strange::Expression::Iterator>");
			return CAT;
		}

		virtual inline const Ptr cats_() const override
		{
			static const Ptr CATS = [this]()
			{
				const Ptr cats = Herd::mut_();
				Herd* const herd = static_<Herd>(cats);
				herd->self_add_(Stateful::cats_());
				herd->insert_(Expression::Iterator::cat_());
				herd->finalize_();
				return cats;
			}();
			return CATS;
		}

	private:
		const std::vector<Ptr>& _elements;
		const Ptr _local;
		int64_t _pos;
	};

	class Break
	{
	public:
		inline Break(const Ptr& thing, const bool cont)
			:_thing(thing)
			,_continue(cont)
		{
		}

		inline const Ptr thing_() const
		{
			return _thing;
		}

		inline const bool continue_() const
		{
			return _continue;
		}

	private:
		const Ptr _thing;
		const bool _continue;
	};

	class Return
	{
	public:
		inline Return(const Ptr& thing)
			:_thing(thing)
		{
		}

		inline const Ptr thing_() const
		{
			return _thing;
		}

	private:
		const Ptr _thing;
	};
};

//----------------------------------------------------------------------
class Operation : public Thing
//----------------------------------------------------------------------
{
public:
	inline Operation(const Ptr& expression)
		: Thing{}
		, _expression{ expression }
	{
	}

	inline void parent_(const Ptr& parent)
	{
		static_<Expression>(_expression)->parent_(parent);
	}

protected:
	const Ptr _expression;
};

//----------------------------------------------------------------------
class Function : public Operation
//----------------------------------------------------------------------
{
public:
	inline Function(const Ptr& expression)
		: Operation{ expression }
		, _shared{ Shoal::Concurrent::mut_() }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Function>(expression);
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::Function>");
		return CAT;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", _shared);
		loc->insert_("&", it);
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _shared;
};

//----------------------------------------------------------------------
class Closure : public Operation
//----------------------------------------------------------------------
{
public:
	inline Closure(const Ptr& expression, const Ptr& local)
		: Operation{ expression }
		, _local{ local }
	{
	}

	static inline const Ptr fin_(const Ptr& expression, const Ptr& local)
	{
		return fake_<Closure>(expression, local);
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::Closure>");
		return CAT;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		const Ptr local = _local->copy_();
		static_<Shoal>(local)->insert_("&", it);
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _local;
};

//----------------------------------------------------------------------
class Mutation : public Operation
//----------------------------------------------------------------------
{
public:
	inline Mutation(const Ptr& expression)
		: Operation{ expression }
		, _shared{ Shoal::Concurrent::mut_() }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Mutation>(expression);
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::Mutation>");
		return CAT;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		if (thing->final_())
		{
			throw Mutilation(thing->cat_());
		}
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", _shared);
		loc->insert_("&", it);
		loc->insert_("|", thing->me_());
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _shared;
};

//----------------------------------------------------------------------
class Extraction : public Operation
//----------------------------------------------------------------------
{
public:
	inline Extraction(const Ptr& expression)
		: Operation{ expression }
		, _shared{ Shoal::Concurrent::mut_() }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Extraction>(expression);
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::Extraction>");
		return CAT;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", _shared);
		loc->insert_("&", it);
		loc->insert_("|", thing->me_());
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _shared;
};

//----------------------------------------------------------------------
class Creation : public Operation
//----------------------------------------------------------------------
{
public:
	inline Creation(const Ptr& expression)
		: Operation{ expression }
		, _shared{ Shoal::Concurrent::mut_() }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Creation>(expression);
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_("<strange::Creation>");
		return CAT;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", _shared);
		loc->insert_("&", it);
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _shared;
};

//----------------------------------------------------------------------
class Attribute : public Operation
//----------------------------------------------------------------------
{
public:
	virtual inline const Ptr cat_() const override
	{
		_initialize_();
		return _value->cat_();
	}

	virtual inline void finalize_() const override
	{
		if (_value)
		{
			_value->finalize_();
		}
	}

	virtual inline const bool final_() const override
	{
		_initialize_();
		return _value->final_();
	}

	virtual inline void freeze_() const override
	{
		if (_value)
		{
			_value->freeze_();
		}
	}

	virtual inline const bool frozen_() const override
	{
		_initialize_();
		return _value->frozen_();
	}

	virtual inline const Ptr copy_() const override
	{
		return duplicate_(_expression, _value ? _value->copy_() : _value);
	}

	virtual inline const Ptr clone_() const override
	{
		return duplicate_(_expression, _value ? _value->clone_() : _value);
	}

	virtual inline const Ptr replicate_() const override
	{
		return duplicate_(_expression, _value ? _value->replicate_() : _value);
	}

	virtual inline const Ptr iterator_() const override
	{
		_initialize_();
		return _value->iterator_();
	}

	virtual inline const Ptr next_() override
	{
		_initialize_();
		return _value->next_();
	}

	virtual inline std::size_t hash_() const override
	{
		_initialize_();
		return _value->hash_();
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		_initialize_();
		return _value->same_(other);
	}

	virtual inline const Ptr visit(const Ptr& it)
	{
		_initialize_();
		return _value->visit(it);
	}

	virtual inline const Ptr cats_() const override
	{
		_initialize_();
		return _value->cats_();
	}

	virtual inline const Ptr pub_() const override
	{
		_initialize_();
		return _value->pub_();
	}

	virtual inline const Ptr eater_() const override
	{
		_initialize_();
		return _value->eater_();
	}

	virtual inline const Ptr feeder(const Ptr& eater) const
	{
		_initialize_();
		return _value->feeder(eater);
	}

	static inline void initialize_(const Ptr& creature, const Ptr& shoal, const bool values)
	{
		auto& members = static_<Shoal>(shoal)->get_();
		for (auto& it : members)
		{
			Attribute* const attribute = dynamic_cast<Attribute*>(it.second.get());
			if (attribute)
			{
				static_<Weak>(attribute->_creature)->set_(creature);
			}
		}
		if (values)
		{
			for (auto& it : members)
			{
				Attribute* const attribute = dynamic_cast<Attribute*>(it.second.get());
				if (attribute)
				{
					attribute->_initialize_(creature);
				}
			}
		}
	}

	virtual inline void set_(const Ptr& thing, const bool intimate) const = 0;

	virtual inline const Ptr get_() const
	{
		return _value;
	}

	virtual inline const Ptr duplicate_(const Ptr& expression, const Ptr& value) const = 0;

	virtual inline const Ptr intimator_(const Ptr& thing, const Ptr& it)
	{
		_initialize_(thing);
		return _value->invoke(it);
	}

protected:
	const Ptr _creature;
	mutable Ptr _value;

	inline Attribute(const Ptr& expression)
		: Operation{ expression }
		, _creature{ Weak::mut_(nothing_()) }
		, _value{}
	{
	}

	static inline const Ptr _actual_(const Ptr thing)
	{
		Ptr actual = thing;
		Attribute* attribute = dynamic_cast<Attribute*>(actual.get());
		while (attribute)
		{
			actual = attribute->get_();
			if (actual.get() == thing.get())
			{
				throw Disagreement("circular attribute reference");
			}
			attribute = dynamic_cast<Attribute*>(actual.get());
		}
		return actual;
	}

	inline void _initialize_(Thing* const thing) const
	{
		if (!_value)
		{
			_init_(thing->me_());
		}
	}

	inline void _initialize_(const Ptr& thing) const
	{
		if (!_value)
		{
			_init_(thing);
		}
	}

	inline void _initialize_() const
	{
		if (!_value)
		{
			_init_(static_<Weak>(_creature)->get_());
		}
	}

	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		_initialize_(thing);
		return _value->invoke(it);
	}

private:
	inline void _init_(const Ptr& thing) const
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", Shoal::Concurrent::mut_());
		loc->insert_("&", stop_());
		loc->insert_("|", thing);
		_value = _actual_(static_<Expression>(_expression)->evaluate_(_expression, local));
	}
};

//----------------------------------------------------------------------
class Fixed : public Attribute
//----------------------------------------------------------------------
{
public:
	inline Fixed(const Ptr& expression)
		: Attribute{ expression }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Fixed>(expression);
	}

	virtual inline void set_(const Ptr& thing, const bool intimate) const override
	{
		throw Mutilation(thing->cat_());
	}

	virtual inline const Ptr duplicate_(const Ptr& expression, const Ptr& value) const override
	{
		const Ptr result = fin_(expression);
		static_<Fixed>(result)->_value = value;
		return result;
	}
};

//----------------------------------------------------------------------
class Mutable : public Attribute
//----------------------------------------------------------------------
{
public:
	inline Mutable(const Ptr& expression)
		: Attribute{ expression }
		, _mutex{}
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Mutable>(expression);
	}

	virtual inline const Ptr cat_() const override
	{
		_initialize_();
		return _get_()->cat_();
	}

	virtual inline void finalize_() const override
	{
		const Ptr value = _get_();
		if (value)
		{
			value->finalize_();
		}
	}

	virtual inline const bool final_() const override
	{
		_initialize_();
		return _get_()->final_();
	}

	virtual inline void freeze_() const override
	{
		const Ptr value = _get_();
		if (value)
		{
			value->freeze_();
		}
	}

	virtual inline const bool frozen_() const override
	{
		_initialize_();
		return _get_()->frozen_();
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr value = _get_();
		return duplicate_(_expression, value ? value->copy_() : value);
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr value = _get_();
		return duplicate_(_expression, value ? value->clone_() : value);
	}

	virtual inline const Ptr replicate_() const override
	{
		const Ptr value = _get_();
		return duplicate_(_expression, value ? value->replicate_() : value);
	}

	virtual inline const Ptr iterator_() const override
	{
		_initialize_();
		return _get_()->iterator_();
	}

	virtual inline const Ptr next_() override
	{
		_initialize_();
		return _get_()->next_();
	}

	virtual inline std::size_t hash_() const override
	{
		_initialize_();
		return _get_()->hash_();
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		_initialize_();
		return _get_()->same_(other);
	}

	virtual inline const Ptr visit(const Ptr& it)
	{
		_initialize_();
		return _get_()->visit(it);
	}

	virtual inline const Ptr cats_() const override
	{
		_initialize_();
		return _get_()->cats_();
	}

	virtual inline const Ptr pub_() const override
	{
		_initialize_();
		return _get_()->pub_();
	}

	virtual inline const Ptr eater_() const override
	{
		_initialize_();
		return _get_()->eater_();
	}

	virtual inline const Ptr feeder(const Ptr& eater) const
	{
		_initialize_();
		return _get_()->feeder(eater);
	}

	virtual inline void set_(const Ptr& thing, const bool intimate) const override
	{
		if (intimate)
		{
			_set_(_actual_(thing));
		}
		else
		{
			throw Mutilation(thing->cat_());
		}
	}

	virtual inline const Ptr get_() const override
	{
		return _get_();
	}

	virtual inline const Ptr duplicate_(const Ptr& expression, const Ptr& value) const override
	{
		const Ptr result = fin_(expression);
		static_<Mutable>(result)->_set_(value);
		return result;
	}

	virtual inline const Ptr intimator_(const Ptr& thing, const Ptr& it) override
	{
		_initialize_(thing);
		return _get_()->invoke(it);
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		throw Dismemberment(thing->cat_(), sym_("Mutable attributes are private"));
	}

private:
	mutable std::shared_timed_mutex _mutex;

	inline void _set_(const Ptr& value) const
	{
		std::unique_lock<std::shared_timed_mutex> lock(_mutex);
		_value = value;
	}

	inline const Ptr _get_() const
	{
		std::shared_lock<std::shared_timed_mutex> lock(_mutex);
		return _value;
	}
};

//----------------------------------------------------------------------
class Variable : public Attribute
//----------------------------------------------------------------------
{
public:
	inline Variable(const Ptr& expression)
		: Attribute{ expression }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Variable>(expression);
	}

	virtual inline void set_(const Ptr& thing, const bool intimate) const override
	{
		if (intimate && !static_<Weak>(_creature)->get_()->final_())
		{
			_value = _actual_(thing);
		}
		else
		{
			throw Mutilation(thing->cat_());
		}
	}

	virtual inline const Ptr duplicate_(const Ptr& expression, const Ptr& value) const override
	{
		const Ptr result = fin_(expression);
		static_<Variable>(result)->_value = value;
		return result;
	}
};

//----------------------------------------------------------------------
class Changeable : public Attribute
//----------------------------------------------------------------------
{
public:
	inline Changeable(const Ptr& expression)
		: Attribute{ expression }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Changeable>(expression);
	}

	virtual inline void set_(const Ptr& thing, const bool intimate) const override
	{
		if (!static_<Weak>(_creature)->get_()->final_())
		{
			_value = _actual_(thing);
		}
		else
		{
			throw Mutilation(thing->cat_());
		}
	}

	virtual inline const Ptr duplicate_(const Ptr& expression, const Ptr& value) const override
	{
		const Ptr result = fin_(expression);
		static_<Changeable>(result)->_value = value;
		return result;
	}
};

//----------------------------------------------------------------------
class Creature : public Stateful, public Serializable
//----------------------------------------------------------------------
{
public:
	inline Creature(const Ptr& creator, const Ptr& members)
		: Stateful{}
		, Serializable{}
		, _creator{ dynamic_<Shoal>(creator) ? creator : Shoal::mut_() }
		, _members{ dynamic_<Shoal>(members) ? members : _creator->replicate_() }
		, _public{ _public_(Stateful::pub_(), _members) }
	{
	}

	static inline const Ptr mut_(const Ptr& creator, const Ptr& members = Ptr())
	{
		const Ptr result = make_<Creature>(creator, members);
		Attribute::initialize_(result, static_<Creature>(result)->_members, !members);
		return result;
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr fin_(const Ptr& creator, const Ptr& members = Ptr())
	{
		const Ptr result = mut_(creator, members);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& it)
	{
		return fin_(it->next_());
	}

	static inline void share_(const Ptr& shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Creature::mut", Static::fin_(&Creature::mut, "creator"));
	}

	virtual inline const Ptr cat_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("cat");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		static const Ptr CAT = Cat::fin_("<strange::Creature>");
		return CAT;
	}

	virtual inline void finalize_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("finalize");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over);
		}
		_members->finalize_();
		Stateful::finalize_();
	}

	virtual inline const bool final_() const override
	{
		if (!Stateful::final_() || !_members->final_())
		{
			return false;
		}
		const Ptr over = static_<Shoal>(_members)->at_("final");
		if (!over->is_nothing_())
		{
			return !operate_(const_cast<Creature*>(this), over)->is_nothing_();
		}
		return true;
	}

	virtual inline void freeze_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("freeze");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over);
		}
		_members->freeze_();
		Stateful::freeze_();
	}

	virtual inline const bool frozen_() const override
	{
		if (!Stateful::frozen_() || !_members->frozen_())
		{
			return false;
		}
		const Ptr over = static_<Shoal>(_members)->at_("frozen");
		if (!over->is_nothing_())
		{
			return !operate_(const_cast<Creature*>(this), over)->is_nothing_();
		}
		return true;
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("copy");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return mut_(_creator, _members->copy_());
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("clone");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return mut_(_creator, _members->clone_());
	}

	virtual inline const Ptr replicate_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("replicate");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		if (final_())
		{
			return fin_(_creator, _members->replicate_());
		}
		return mut_(_creator, _members->replicate_());
	}

	virtual inline const Ptr iterator_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("iterator");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return Stateful::iterator_();
	}

	virtual inline const Ptr next_() override
	{
		const Ptr over = static_<Shoal>(_members)->at_("next");
		if (!over->is_nothing_())
		{
			return operate_(this, over);
		}
		return Stateful::next_();
	}

	virtual inline std::size_t hash_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("hash");
		if (!over->is_nothing_())
		{
			return std::size_t(static_<Int64>(operate_(const_cast<Creature*>(this), over))->get_());
		}
		return Stateful::hash_();
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("same");
		if (!over->is_nothing_())
		{
			return !operate_(const_cast<Creature*>(this), over,
				IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ other }))->is_nothing_();
		}
		return Stateful::same_(other);
	}

	virtual inline const Ptr visit(const Ptr& it) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("visit");
		if (!over->is_nothing_())
		{
			return operate_(this, over, it);
		}
		return Stateful::visit(it);
	}

	virtual inline const Ptr eater_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("eater");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return Stateful::eater_();
	}

	virtual inline const Ptr feeder(const Ptr& eater) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("feeder");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over, eater);
		}
		return Stateful::feeder(eater);
	}

	virtual inline const Ptr cats_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("cats");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		static const Ptr CATS = [this]()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->self_add_(Stateful::cats_());
			herd->self_add_(Serializable::cats_());
			herd->insert_(Creature::cat_()); //TODO dynamic creature cat/cats
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline const Ptr pub_() const override
	{
		return _public;
	}

	inline const Ptr members_() const
	{
		return _members;
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("to_lake");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("from_lake");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ lake }));
		}
		else
		{
			from_lake_via_river_(lake);
		}
	}

	virtual inline void to_river_(const Ptr& river) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("to_river");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->to_river_(river);
		}
	}

	virtual inline void from_river_(const Ptr& river) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("from_river");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->from_river_(river);
		}
	}

	virtual inline void to_river_with_links_(const Ptr& shoal, const Ptr& river) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("to_river_with_links");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ shoal, river }));
		}
		else
		{
			static_<Shoal>(_members)->to_river_with_links_(shoal, river);
		}
	}

	virtual inline void from_river_with_links_(const Ptr& river) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("from_river_with_links");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->from_river_with_links_(river);
		}
	}

	virtual inline void replace_links_(const Ptr& shoal) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("replace_links");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ shoal }));
		}
		else
		{
			static_<Shoal>(_members)->replace_links_(shoal);
		}
	}

private:
	const Ptr _creator;
	const Ptr _members;
	const Ptr _public;

	static inline const Ptr _public_(const Ptr& pub, const Ptr& members)
	{
		const Ptr result = pub->copy_();
		Shoal* const r = static_<Shoal>(result);
		Shoal* const m = static_<Shoal>(members);
		const Ptr it = m->iterator_();
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			Flock* const flock = static_<Flock>(i);
			const Ptr first = flock->at_(0);
			Symbol* const symbol = dynamic_<Symbol>(first);
			if (symbol && symbol->get_()[0] != '_')
			{
				r->update_(first, flock->at_(1));
			}
		}
		result->finalize_();
		return result;
	}
};

//======================================================================
// class Expression
//======================================================================

inline const Thing::Ptr Expression::fin_(const Ptr& token, const Ptr& statement, const MemberPtr member, const Ptr& flock)
{
	const Ptr exp = fake_<Expression>(token, statement, member, flock);
	const Ptr it = flock->iterator_();
	for (Ptr sub = it->next_(); !sub->is_stop_(); sub = it->next_())
	{
		Expression* const e = dynamic_<Expression>(sub);
		if (e)
		{
			e->parent_(exp);
		}
		else
		{
			Operation* const op = dynamic_<Operation>(sub);
			if (op)
			{
				op->parent_(exp);
			}
		}
	}
	flock->freeze_();
	return exp;
}

inline const Thing::Ptr Expression::fin_(const Ptr& token, const Ptr& statement, const Ptr& flock)
{
	const int64_t size = static_<Flock>(flock)->size_();
	if (statement->is_("local_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_local_at_, flock);
		}
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_local_update_, flock);
		}
		throw Disagreement("local_ expression of wrong size");
	}
	else if (statement->is_("shared_at_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_shared_at_, flock);
		}
		throw Disagreement("shared_at_ expression of wrong size");
	}
	else if (statement->is_("shared_update_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_shared_update_, flock);
		}
		throw Disagreement("shared_update_ expression of wrong size");
	}
	else if (statement->is_("shared_insert_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_shared_insert_, flock);
		}
		throw Disagreement("shared_insert_ expression of wrong size");
	}
	else if (statement->is_("me_"))
	{
		if (size == 0)
		{
			return fin_(token, statement, &Expression::_me_, flock);
		}
		throw Disagreement("me_ expression of wrong size");
	}
	else if (statement->is_("thing_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_thing_, flock);
		}
		throw Disagreement("thing_ expression of wrong size");
	}
	else if (statement->is_("invoke_"))
	{
		if (size >= 1)
		{
			return fin_(token, statement, &Expression::_invoke_, flock);
		}
		throw Disagreement("invoke_ expression of wrong size");
	}
	else if (statement->is_("invoke_iterator_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_invoke_iterator_, flock);
		}
		throw Disagreement("invoke_iterator_ expression of wrong size");
	}
	else if (statement->is_("invoke_iterable_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_invoke_iterable_, flock);
		}
		throw Disagreement("invoke_iterable_ expression of wrong size");
	}
	else if (statement->is_("set_attribute_"))
	{
		if (size == 3)
		{
			return fin_(token, statement, &Expression::_set_attribute_, flock);
		}
		throw Disagreement("set_attribute_ expression of wrong size");
	}
	else if (statement->is_("public_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_public_, flock);
		}
		throw Disagreement("public_ expression of wrong size");
	}
	else if (statement->is_("operate_"))
	{
		if (size >= 2)
		{
			return fin_(token, statement, &Expression::_operate_, flock);
		}
		throw Disagreement("operate_ expression of wrong size");
	}
	else if (statement->is_("operate_iterator_"))
	{
		if (size == 3)
		{
			return fin_(token, statement, &Expression::_operate_iterator_, flock);
		}
		throw Disagreement("operate_iterator_ expression of wrong size");
	}
	else if (statement->is_("operate_iterable_"))
	{
		if (size == 3)
		{
			return fin_(token, statement, &Expression::_operate_iterable_, flock);
		}
		throw Disagreement("operate_iterable_ expression of wrong size");
	}
	else if (statement->is_("operation_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_operation_, flock);
		}
		throw Disagreement("operation_ expression of wrong size");
	}
	else if (statement->is_("perform_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_perform_, flock);
		}
		throw Disagreement("perform_ expression of wrong size");
	}
	else if (statement->is_("set_intimate_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_set_intimate_, flock);
		}
		throw Disagreement("set_intimate_ expression of wrong size");
	}
	else if (statement->is_("private_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_private_, flock);
		}
		throw Disagreement("private_ expression of wrong size");
	}
	else if (statement->is_("intimate_"))
	{
		if (size >= 1)
		{
			return fin_(token, statement, &Expression::_intimate_, flock);
		}
		throw Disagreement("intimate_ expression of wrong size");
	}
	else if (statement->is_("intimate_iterator_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_intimate_iterator_, flock);
		}
		throw Disagreement("intimate_iterator_ expression of wrong size");
	}
	else if (statement->is_("intimate_iterable_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_intimate_iterable_, flock);
		}
		throw Disagreement("intimate_iterable_ expression of wrong size");
	}
	else if (statement->is_("intimation_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_intimation_, flock);
		}
		throw Disagreement("intimation_ expression of wrong size");
	}
	else if (statement->is_("lambda_"))
	{
		if (size % 3 == 1) // <cat> param := capture
		{
			return fin_(token, statement, &Expression::_lambda_, flock);
		}
		throw Disagreement("lambda_ expression of wrong size");
	}
	else if (statement->is_("function_"))
	{
		if (size % 3 == 1) // <cat> param := default
		{
			return fin_(token, statement, &Expression::_function_, flock);
		}
		throw Disagreement("function_ expression of wrong size");
	}
	else if (statement->is_("creation_"))
	{
		if (size >= 1) // creation ..
		{
			return fin_(token, statement, &Expression::_creation_, flock);
		}
		throw Disagreement("creation_ expression of wrong size");
	}
	else if (statement->is_("shared_scope_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_shared_scope_, flock);
		}
		throw Disagreement("shared_scope_ expression of wrong size");
	}
	else if (statement->is_("relative_scope_"))
	{
		if (size == 3)
		{
			return fin_(token, statement, &Expression::_relative_scope_, flock);
		}
		throw Disagreement("relative_scope_ expression of wrong size");
	}
	else if (statement->is_("flock_"))
	{
		return fin_(token, statement, &Expression::_flock_, flock);
	}
	else if (statement->is_("flock_iterator_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_flock_iterator_, flock);
		}
		throw Disagreement("flock_iterator_ expression of wrong size");
	}
	else if (statement->is_("shoal_"))
	{
		if (size % 2 == 0)
		{
			return fin_(token, statement, &Expression::_shoal_, flock);
		}
		throw Disagreement("shoal_ expression of odd size");
	}
	else if (statement->is_("herd_"))
	{
		return fin_(token, statement, &Expression::_herd_, flock);
	}
	else if (statement->is_("break_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_break_, flock);
		}
		throw Disagreement("break_ expression of wrong size");
	}
	else if (statement->is_("continue_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_continue_, flock);
		}
		throw Disagreement("continue_ expression of wrong size");
	}
	else if (statement->is_("return_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_return_, flock);
		}
		throw Disagreement("return_ expression of wrong size");
	}
	else if (statement->is_("error_"))
	{
		return fin_(token, statement, &Expression::_error_, flock);
	}
	else if (statement->is_("throw_"))
	{
		if (size == 1)
		{
			return fin_(token, statement, &Expression::_throw_, flock);
		}
		throw Disagreement("throw_ expression of wrong size");
	}
	else if (statement->is_("catch_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_catch_, flock);
		}
		throw Disagreement("catch_ expression of wrong size");
	}
	else if (statement->is_("block_"))
	{
		return fin_(token, statement, &Expression::_block_, flock);
	}
	else if (statement->is_("if_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_if_, flock);
		}
		if (size == 3)
		{
			return fin_(token, statement, &Expression::_if_else_, flock);
		}
		throw Disagreement("if_ expression of wrong size");
	}
	else if (statement->is_("while_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_while_, flock);
		}
		throw Disagreement("while_ expression of wrong size");
	}
	else if (statement->is_("do_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_do_, flock);
		}
		throw Disagreement("do_ expression of wrong size");
	}
	else if (statement->is_("for_"))
	{
		if (size == 4)
		{
			return fin_(token, statement, &Expression::_for_, flock);
		}
		throw Disagreement("for_ expression of wrong size");
	}
	else
	{
		throw Disagreement("expression with unexpected statement");
	}
	return fin_(token);
}

inline const Thing::Ptr Expression::_set_attribute_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr thing = Expression::evaluate_(vec[0], local);
		const Ptr member = static_<Shoal>(thing->pub_())->at_(vec[1]);
		if (member->is_nothing_())
		{
			throw Dismemberment(thing->cat_(), vec[1]);
		}
		Attribute* const attribute = dynamic_cast<Attribute*>(member.get());
		if (attribute)
		{
			const Ptr value = Expression::evaluate_(vec[2], local);
			attribute->set_(value, false);
			return value;
		}
		throw Mutilation(thing->cat_());
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_set_intimate_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr thing = static_<Shoal>(local)->at_("|");
		if (thing->is_nothing_())
		{
			throw _stack_("me accessed without a creature");
		}
		const Ptr member = static_<Shoal>(static_<Creature>(thing)->members_())->at_(vec[0]);
		if (member->is_nothing_())
		{
			throw Dismemberment(thing->cat_(), vec[0]);
		}
		Attribute* const attribute = dynamic_cast<Attribute*>(member.get());
		if (attribute)
		{
			const Ptr value = Expression::evaluate_(vec[1], local);
			attribute->set_(value, true);
			return value;
		}
		throw Mutilation(thing->cat_());
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_private_(const Ptr& local) const
{
	try
	{
		const Ptr thing = static_<Shoal>(local)->at_("|");
		if (thing->is_nothing_())
		{
			throw _stack_("me accessed without a creature");
		}
		const Ptr member = static_<Shoal>(static_<Creature>(thing)->members_())->at_(static_<Flock>(_flock)->get_()[0]);
		if (member->is_nothing_())
		{
			throw Dismemberment(thing->cat_(), static_<Flock>(_flock)->get_()[0]);
		}
		return Method::fin_(thing, member);
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_intimate_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr thing = static_<Shoal>(local)->at_("|");
		if (thing->is_nothing_())
		{
			throw _stack_("me accessed without a creature");
		}
		const Ptr member = static_<Shoal>(static_<Creature>(thing)->members_())->at_(vec[0]);
		if (member->is_nothing_())
		{
			throw Dismemberment(thing->cat_(), vec[0]);
		}
		Attribute* const attribute = dynamic_cast<Attribute*>(member.get());
		if (attribute)
		{
			return attribute->intimator_(thing, _iterator_(local, 1));
		}
		return operate_(thing.get(), member, _iterator_(local, 1));
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_intimate_iterator_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr thing = static_<Shoal>(local)->at_("|");
		if (thing->is_nothing_())
		{
			throw _stack_("me accessed without a creature");
		}
		const Ptr member = static_<Shoal>(static_<Creature>(thing)->members_())->at_(vec[0]);
		if (member->is_nothing_())
		{
			throw Dismemberment(thing->cat_(), vec[0]);
		}
		Attribute* const attribute = dynamic_cast<Attribute*>(member.get());
		if (attribute)
		{
			return attribute->intimator_(thing, Expression::evaluate_(vec[1], local));
		}
		return operate_(thing.get(), member, Expression::evaluate_(vec[1], local));
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_intimate_iterable_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr thing = static_<Shoal>(local)->at_("|");
		if (thing->is_nothing_())
		{
			throw _stack_("me accessed without a creature");
		}
		const Ptr member = static_<Shoal>(static_<Creature>(thing)->members_())->at_(vec[0]);
		if (member->is_nothing_())
		{
			throw Dismemberment(thing->cat_(), vec[0]);
		}
		Attribute* const attribute = dynamic_cast<Attribute*>(member.get());
		const Ptr iterable = Expression::evaluate_(vec[1], local);
		const Ptr feeder = iterable->feeder(member->eater_());
		if (!feeder->is_nothing_())
		{
			if (attribute)
			{
				return attribute->intimator_(thing, feeder);
			}
			return operate_(thing.get(), member, feeder);
		}
		if (attribute)
		{
			return attribute->intimator_(thing, iterable->iterator_());
		}
		return operate_(thing.get(), member, iterable->iterator_());
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_intimation_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr thing = static_<Shoal>(local)->at_("|");
		if (thing->is_nothing_())
		{
			throw _stack_("me accessed without a creature");
		}
		const Ptr member = static_<Shoal>(static_<Creature>(thing)->members_())->at_(vec[0]);
		if (member->is_nothing_())
		{
			throw Dismemberment(thing->cat_(), vec[0]);
		}
		return member;
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_lambda_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr new_shared = Shoal::Concurrent::mut_();
		Shoal::Concurrent* const capture_shared = static_<Shoal::Concurrent>(new_shared);
		const Ptr new_local = Shoal::mut_();
		Shoal* const capture_local = static_<Shoal>(new_local);
		const std::size_t size_1 = vec.size() - 1;
		for (std::size_t i = 0; i < size_1; i += 3)
		{
			const Ptr cat = vec[i];
			const Ptr value = Expression::evaluate_(vec[i + 2], local);
			if (!cat->is_nothing_())
			{
				// check cat
				if (!Cat::check_(value, cat))
				{
					throw _stack_("lambda captured wrong kind of thing");
				}
			}
			const Ptr param = vec[i + 1];
			const std::string& s = static_<Symbol>(param)->get_();
			if (s[0] == '$')
			{
				capture_shared->update_(sym_(s.substr(1)), value);
			}
			else
			{
				capture_local->update_(param, value->clone_freeze_());
			}
		}
		capture_local->insert_("$", new_shared);
		return Closure::fin_(vec[size_1], new_local);
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

inline const Thing::Ptr Expression::_creation_(const Ptr& local) const
{
	try
	{
		const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
		const Ptr res = Shoal::mut_();
		Shoal* const result = static_<Shoal>(res);

		const Ptr flock = Flock::mut_();
		Flock* const flk = static_<Flock>(flock);
		flk->push_back_(one_());
		flk->push_back_(Expression::fin_(_token, sym_("herd_"), Flock::mut_()));
		const Ptr cats = Function::fin_(Expression::fin_(_token, sym_("shared_insert_"), flock));
		result->update_("cats", cats);

		const std::size_t size_1 = vec.size() - 1;
		for (std::size_t i = 0; i <= size_1; ++i)
		{
			const Ptr shoal = Expression::evaluate_(vec[i], local);
			Shoal* const creation = dynamic_<Shoal>(shoal);
			if (!creation)
			{
				throw _stack_("creation_ passed wrong kind of thing");
			}
			_merge_(i == size_1, creation, result);
		}
		return res;
	}
	catch (const std::exception& err)
	{
		throw _stack_(err.what());
	}
}

//======================================================================
// class Operation
//======================================================================

//======================================================================
// class Function
//======================================================================

//======================================================================
// class Closure
//======================================================================

//======================================================================
// class Mutation
//======================================================================

//======================================================================
// class Extraction
//======================================================================

//======================================================================
// class Creation
//======================================================================

//======================================================================
// class Attribute
//======================================================================

//======================================================================
// class Fixed
//======================================================================

//======================================================================
// class Mutable
//======================================================================

//======================================================================
// class Variable
//======================================================================

//======================================================================
// class Changeable
//======================================================================

//======================================================================
// class Creature
//======================================================================

} // namespace strange

#endif
