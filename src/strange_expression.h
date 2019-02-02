#ifndef COM_ONEISH_STRANGE_EXPRESSION_H
#define COM_ONEISH_STRANGE_EXPRESSION_H

#include "strange_core.h"
#include "strange_misunderstanding.h"
#include "strange_token.h"
#include "strange_weak.h"
#include "strange_method.h"
#include "strange_creature.h"

namespace strange
{
	class Expression;
	class Function;
	class Closure;
	class Mutation;
	class Extraction;

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

	static inline const Ptr fin_(const Ptr& token, const Ptr& statement, const MemberPtr member, const Ptr& flock)
	{
		const Ptr exp = fake_<Expression>(token, statement, member, flock);
		const Ptr it = flock->iterator_();
		for (Ptr sub = it->next_(); !sub->is_("."); sub = it->next_())
		{
			Expression* const e = dynamic_<Expression>(sub);
			if (e)
			{
				e->parent_(exp);
			}
		}
		flock->freeze_();
		return exp;
	}

	static inline const Ptr fin_(const Ptr& token, const Ptr& statement, const Ptr& flock);

	static inline const Ptr fin_(const Ptr& token, const Ptr& thing = nothing_())
	{
		const Ptr flock = Flock::mut_();
		static_<Flock>(flock)->push_back_(thing);
		return Expression::fin_(token, nothing_(), &Expression::_thing_, flock);
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

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Expression");
		return TYPE;
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

	inline const Ptr _method_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			const Ptr thing = Expression::evaluate_(vec[0], local);
			return Method::with_name_(thing, vec[1]);
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
				throw Dismemberment(thing->type_(), vec[1]);
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
				throw Dismemberment(thing->type_(), vec[1]);
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
				throw Dismemberment(thing->type_(), vec[1]);
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
				throw Dismemberment(thing->type_(), vec[1]);
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

	inline const Ptr _private_(const Ptr& local) const
	{
		try
		{
			const Ptr thing = static_<Shoal>(local)->at_("|");
			if (thing->is_nothing_())
			{
				throw _stack_("me accessed without a creature");
			}
			return Method::with_name_(thing, static_<Flock>(_flock)->get_()[0]);
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _intimate_(const Ptr& local) const
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
				throw Dismemberment(thing->type_(), vec[0]);
			}
			return operate_(thing.get(), member, _iterator_(local, 1));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _intimate_iterator_(const Ptr& local) const
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
				throw Dismemberment(thing->type_(), vec[0]);
			}
			return operate_(thing.get(), member, Expression::evaluate_(vec[1], local));
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _intimate_iterable_(const Ptr& local) const
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
				throw Dismemberment(thing->type_(), vec[0]);
			}
			const Ptr iterable = Expression::evaluate_(vec[1], local);
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

	inline const Ptr _intimation_(const Ptr& local) const
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
				throw Dismemberment(thing->type_(), vec[0]);
			}
			return member;
		}
		catch (const std::exception& err)
		{
			throw _stack_(err.what());
		}
	}

	inline const Ptr _lambda_(const Ptr& local) const;

	inline const Ptr _function_(const Ptr& local) const
	{
		try
		{
			const std::vector<Ptr>& vec = static_<Flock>(_flock)->get_();
			Shoal* const shoal = static_<Shoal>(local);
			const Ptr it = shoal->at_("&");
			const std::size_t size_1 = vec.size() - 1;
			Ptr param;
			Ptr value;
			for (std::size_t i = 0; i < size_1; ++i)
			{
				if (i % 2 == 0)
				{
					param = vec[i];
					continue;
				}
				value = it->next_();
				if (value->is_("."))
				{
					value = Expression::evaluate_(vec[i], local); // default
				}
				shoal->update_(param, value);
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
			const std::size_t pos = scope.find_last_of("::");
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

	class Iterator : public Mutable
	{
	public:
		inline Iterator(const std::vector<Ptr>& vec, const Ptr& local, const int64_t pos)
			: Mutable{}
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

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Expression::Iterator");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override
		{
			static const Ptr CATS = []()
			{
				const Ptr cats = Herd::mut_();
				Herd* const herd = static_<Herd>(cats);
				herd->insert_("strange::Mutable");
				herd->insert_("strange::Iterator");
				herd->insert_("strange::Thing");
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
class Function : public Thing
//----------------------------------------------------------------------
{
public:
	inline Function(const Ptr& expression)
		: Thing{}
		, _expression{ expression }
		, _shared{ Shoal::Concurrent::mut_() }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Function>(expression);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Function");
		return TYPE;
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
	const Ptr _expression;
	const Ptr _shared;
};

//----------------------------------------------------------------------
class Closure : public Thing
//----------------------------------------------------------------------
{
public:
	inline Closure(const Ptr& expression, const Ptr& local)
		: Thing{}
		, _expression{ expression }
		, _local{ local }
	{
	}

	static inline const Ptr fin_(const Ptr& expression, const Ptr& local)
	{
		return fake_<Closure>(expression, local);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Closure");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		const Ptr local = _local->copy_();
		static_<Shoal>(local)->insert_("&", it);
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _expression;
	const Ptr _local;
};

//----------------------------------------------------------------------
class Mutation : public Thing
//----------------------------------------------------------------------
{
public:
	inline Mutation(const Ptr& expression)
		: Thing{}
		, _expression{ expression }
		, _shared{ Shoal::Concurrent::mut_() }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Mutation>(expression);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Mutation");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
	{
		if (thing->final_())
		{
			throw Mutilation(thing->type_());
		}
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", _shared);
		loc->insert_("&", it);
		loc->insert_("|", thing->me_());
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _expression;
	const Ptr _shared;
};

//----------------------------------------------------------------------
class Extraction : public Thing
//----------------------------------------------------------------------
{
public:
	inline Extraction(const Ptr& expression)
		: Thing{}
		, _expression{ expression }
		, _shared{ Shoal::Concurrent::mut_() }
	{
	}

	static inline const Ptr fin_(const Ptr& expression)
	{
		return fake_<Extraction>(expression);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Extraction");
		return TYPE;
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
	const Ptr _expression;
	const Ptr _shared;
};

//======================================================================
// class Expression
//======================================================================

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
	else if (statement->is_("method_"))
	{
		if (size == 2)
		{
			return fin_(token, statement, &Expression::_method_, flock);
		}
		throw Disagreement("method_ expression of wrong size");
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
		if (size % 2 == 1)
		{
			return fin_(token, statement, &Expression::_lambda_, flock);
		}
		throw Disagreement("lambda_ expression of wrong size");
	}
	else if (statement->is_("function_"))
	{
		if (size % 2 == 1)
		{
			return fin_(token, Function::fin_(fin_(token, statement, &Expression::_function_, flock)));
		}
		throw Disagreement("function_ expression of wrong size");
	}
	else if (statement->is_("closure_"))
	{
		if (size % 2 == 1)
		{
			return fin_(token, statement, &Expression::_function_, flock);
		}
		throw Disagreement("closure_ expression of wrong size");
	}
	else if (statement->is_("mutation_"))
	{
		if (size % 2 == 1)
		{
			return fin_(token, Mutation::fin_(fin_(token, statement, &Expression::_function_, flock)));
		}
		throw Disagreement("mutation_ expression of wrong size");
	}
	else if (statement->is_("extraction_"))
	{
		if (size % 2 == 1)
		{
			return fin_(token, Extraction::fin_(fin_(token, statement, &Expression::_function_, flock)));
		}
		throw Disagreement("extraction_ expression of wrong size");
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
		Ptr param;
		for (std::size_t i = 0; i < size_1; ++i)
		{
			if (i % 2 == 0)
			{
				param = vec[i];
				continue;
			}
			const std::string& s = static_<Symbol>(param)->get_();
			if (s[0] == '$')
			{
				capture_shared->update_(sym_(s.substr(1)), Expression::evaluate_(vec[i], local));
			}
			else
			{
				capture_local->update_(param, Expression::evaluate_(vec[i], local)->clone_freeze_());
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

} // namespace strange

#endif
