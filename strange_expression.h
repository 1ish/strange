#ifndef COM_ONEISH_STRANGE_EXPRESSION_H
#define COM_ONEISH_STRANGE_EXPRESSION_H

#include "strange_core.h"
#include "strange_method.h"
#include "strange_creature.h"

namespace strange
{
	class Expression;

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
	typedef const Ptr(Expression::*MemberPtr)(const Ptr) const;

public:
	inline Expression(const MemberPtr member, const Ptr flock)
		: Thing{}
		, _member{ member }
		, _flock{ flock }
	{
	}

	static inline const Ptr fin_(const MemberPtr member, const Ptr flock)
	{
		flock->freeze_();
		return fake_<Expression>(member, flock);
	}

	static inline const Ptr fin_(const Ptr statement, const Ptr flock)
	{
		const int64_t size = static_<Flock>(flock)->size_();
		if (statement->is_("local_"))
		{
			if (size == 0)
			{
				return fin_(&Expression::_local_, flock);
			}
			log_("local_ expression of wrong size");
		}
		else if (statement->is_("thing_"))
		{
			if (size == 1)
			{
				return fin_(&Expression::_thing_, flock);
			}
			log_("thing_ expression of wrong size");
		}
		else if (statement->is_("invoke_"))
		{
			if (size >= 2)
			{
				return fin_(&Expression::_invoke_, flock);
			}
			log_("invoke_ expression of wrong size");
		}
		else if (statement->is_("invoke_iterator_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_invoke_iterator_, flock);
			}
			log_("invoke_iterator_ expression of wrong size");
		}
		else if (statement->is_("invoke_iterable_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_invoke_iterable_, flock);
			}
			log_("invoke_iterable_ expression of wrong size");
		}
		else if (statement->is_("method_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_method_, flock);
			}
			log_("method_ expression of wrong size");
		}
		else if (statement->is_("operate_iterator_"))
		{
			if (size == 3)
			{
				return fin_(&Expression::_operate_iterator_, flock);
			}
			log_("operate_iterator_ expression of wrong size");
		}
		else if (statement->is_("operate_iterable_"))
		{
			if (size == 3)
			{
				return fin_(&Expression::_operate_iterable_, flock);
			}
			log_("operate_iterable_ expression of wrong size");
		}
		else if (statement->is_("lambda_"))
		{
			if (size % 2 == 1)
			{
				return fin_(&Expression::_lambda_, flock);
			}
			log_("lambda_ expression of wrong size");
		}
		else if (statement->is_("function_"))
		{
			if (size % 2 == 1)
			{
				return fin_(&Expression::_function_, flock);
			}
			log_("function_ expression of wrong size");
		}
		else if (statement->is_("shared_scope_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_shared_scope_, flock);
			}
			log_("shared_scope_ expression of wrong size");
		}
		else if (statement->is_("relative_scope_"))
		{
			if (size == 3)
			{
				return fin_(&Expression::_relative_scope_, flock);
			}
			log_("relative_scope_ expression of wrong size");
		}
		else if (statement->is_("flock_"))
		{
			return fin_(&Expression::_flock_, flock);
		}
		else if (statement->is_("flock_iterator_"))
		{
			if (size == 1)
			{
				return fin_(&Expression::_flock_iterator_, flock);
			}
			log_("flock_iterator_ expression of wrong size");
		}
		else if (statement->is_("shoal_"))
		{
			if (size % 2 == 0)
			{
				return fin_(&Expression::_shoal_, flock);
			}
			log_("shoal_ expression of odd size");
		}
		else if (statement->is_("herd_"))
		{
			return fin_(&Expression::_herd_, flock);
		}
		else if (statement->is_("break_"))
		{
			if (size == 1)
			{
				return fin_(&Expression::_break_, flock);
			}
			log_("break_ expression of wrong size");
		}
		else if (statement->is_("continue_"))
		{
			if (size == 1)
			{
				return fin_(&Expression::_continue_, flock);
			}
			log_("continue_ expression of wrong size");
		}
		else if (statement->is_("return_"))
		{
			if (size == 1)
			{
				return fin_(&Expression::_return_, flock);
			}
			log_("return_ expression of wrong size");
		}
		else if (statement->is_("throw_"))
		{
			if (size == 1)
			{
				return fin_(&Expression::_throw_, flock);
			}
			log_("throw_ expression of wrong size");
		}
		else if (statement->is_("catch_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_catch_, flock);
			}
			log_("catch_ expression of wrong size");
		}
		else if (statement->is_("block_"))
		{
			return fin_(&Expression::_block_, flock);
		}
		else if (statement->is_("if_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_if_, flock);
			}
			if (size == 3)
			{
				return fin_(&Expression::_if_else_, flock);
			}
			log_("if_ expression of wrong size");
		}
		else if (statement->is_("while_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_while_, flock);
			}
			log_("while_ expression of wrong size");
		}
		else if (statement->is_("do_"))
		{
			if (size == 2)
			{
				return fin_(&Expression::_do_, flock);
			}
			log_("do_ expression of wrong size");
		}
		else if (statement->is_("for_"))
		{
			if (size == 4)
			{
				return fin_(&Expression::_for_, flock);
			}
			log_("for_ expression of wrong size");
		}
		else
		{
			log_("expression with unexpected statement");
		}
		const Ptr none = Flock::mut_();
		static_<Flock>(none)->push_back_(nothing_());
		return fin_(&Expression::_thing_, none);
	}

	static inline const Ptr fin_(const Ptr thing = nothing_())
	{
		const Ptr flock = Flock::mut_();
		static_<Flock>(flock)->push_back_(thing);
		return Expression::fin_(sym_("thing_"), flock);
	}

	static inline const Ptr fin(const Ptr it)
	{
		const Ptr statement = it->next_();
		const Ptr flock = it->next_();
		return fin_(statement, flock);
	}

	static inline const Ptr evaluate_(const Ptr expression, const Ptr local)
	{
		Expression* const exp = static_<Expression>(expression);
		return (exp->*(exp->_member))(local);
	}

	static inline const Ptr immediate_(const Ptr expression)
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->update_("$", Shoal::mut_());
		loc->update_("&", stop_());
		return evaluate_(expression, local);
	}

	static inline void generate_(const Ptr expression, const Ptr language, const Ptr river)
	{
		River* const riv = dynamic_<River>(river);
		if (!riv)
		{
			return;
		}
		Expression* const exp = static_<Expression>(expression);
		if (language->is_("strange"))
		{
			exp->_generate_strange_(riv);
		}
		else if (language->is_("c++"))
		{
			exp->_generate_cpp_(riv);
		}
	}

	inline const Ptr iterator_(const Ptr local) const
	{
		return Iterator::mut_(_flock, local);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Expression");
		return TYPE;
	}

private:
	const MemberPtr _member;
	const Ptr _flock;

	inline void _generate_strange_(River* const river) const
	{
		if (_member == &Expression::_local_)
		{
			_generate_strange_local_(river);
		}
		else if (_member == &Expression::_thing_)
		{
			_generate_strange_thing_(river);
		}
		else if (_member == &Expression::_invoke_)
		{
			_generate_strange_invoke_(river);
		}
	}

	inline void _generate_cpp_(River* const river) const
	{
		if (_member == &Expression::_local_)
		{
			_generate_cpp_local_(river);
		}
		else if (_member == &Expression::_thing_)
		{
			_generate_cpp_thing_(river);
		}
		else if (_member == &Expression::_invoke_)
		{
			_generate_cpp_invoke_(river);
		}
	}

	inline const Ptr _local_(const Ptr local) const
	{
		return local;
	}

	inline void _generate_strange_local_(River* const river) const
	{
		river->write_("@@");
	}

	inline void _generate_cpp_local_(River* const river) const
	{
		river->write_("__local__");
	}

	inline const Ptr _thing_(const Ptr local) const
	{
		return static_<Flock>(_flock)->at_(0);
	}

	inline void _generate_strange_thing_(River* const river) const
	{
		river->write_("£"); //TODO write strange literals
	}

	inline void _generate_cpp_thing_(River* const river) const
	{
		river->write_("£"); //TODO write cpp literals
	}

	inline const Ptr _invoke_(const Ptr local) const
	{
		const Ptr it = iterator_(local);
		const Ptr thing = it->next_();
		return thing->invoke(it);
	}

	inline void _generate_strange_invoke_(River* const river) const
	{
		const Ptr it = static_<Flock>(_flock)->iterator_();
		static_<Expression>(it->next_())->_generate_strange_(river);
		river->write_("[");
		bool first = true;
		for (Ptr exp = it->next_(); !exp->is_("."); exp = it->next_())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river->write_(",");
			}
			static_<Expression>(exp)->_generate_strange_(river);
		}
		river->write_("]");
	}

	inline void _generate_cpp_invoke_(River* const river) const
	{
		const Ptr it = static_<Flock>(_flock)->iterator_();
		static_<Expression>(it->next_())->_generate_cpp_(river);
		river->write_("->invoke_(");
		bool first = true;
		for (Ptr exp = it->next_(); !exp->is_("."); exp = it->next_())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river->write_(",");
			}
			static_<Expression>(exp)->_generate_cpp_(river);
		}
		river->write_(")");
	}

	inline const Ptr _invoke_iterator_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const Ptr thing = Expression::evaluate_(flock->at_(0), local);
		return thing->invoke(Expression::evaluate_(flock->at_(1), local));
	}

	inline const Ptr _invoke_iterable_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const Ptr thing = Expression::evaluate_(flock->at_(0), local);
		const Ptr iterable = Expression::evaluate_(flock->at_(1), local);
		const Ptr eater = thing->eater_();
		if (!eater->is_nothing_())
		{
			const Ptr feeder = iterable->feeder(eater);
			if (!feeder->is_nothing_())
			{
				return thing->invoke(feeder);
			}
		}
		return thing->invoke(iterable->iterator_());
	}

	inline const Ptr _method_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const Ptr thing = Expression::evaluate_(flock->at_(0), local);
		return Method::with_name_(thing, Expression::evaluate_(flock->at_(1), local));
	}

	inline const Ptr _operate_iterator_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const Ptr thing = Expression::evaluate_(flock->at_(0), local);
		const Ptr member = static_<Shoal>(thing->pub_())->find_(Expression::evaluate_(flock->at_(1), local));
		return operate_(thing.get(), member, Expression::evaluate_(flock->at_(2), local));
	}

	inline const Ptr _operate_iterable_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const Ptr thing = Expression::evaluate_(flock->at_(0), local);
		const Ptr member = static_<Shoal>(thing->pub_())->find_(Expression::evaluate_(flock->at_(1), local));
		const Ptr iterable = Expression::evaluate_(flock->at_(2), local);
		const Ptr eater = member->eater_();
		if (!eater->is_nothing_())
		{
			const Ptr feeder = iterable->feeder(eater);
			if (!feeder->is_nothing_())
			{
				return operate_(thing.get(), member, feeder);
			}
		}
		return operate_(thing.get(), member, iterable->iterator_());
	}

	inline const Ptr _lambda_(const Ptr local) const
	{
		Shoal* const shoal = static_<Shoal>(local);
		Shoal* const shared = static_<Shoal>(shoal->find_("$"));
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size_1 = flock->size_() - 1;
		Ptr param;
		for (int64_t i = 0; i < size_1; ++i)
		{
			if (i % 2 == 0)
			{
				param = flock->at_(i);
				continue;
			}
			shared->update_(param, Expression::evaluate_(flock->at_(i), local));
		}
		return Expression::evaluate_(flock->at_(size_1), local);
	}

	inline const Ptr _function_(const Ptr local) const
	{
		Shoal* const shoal = static_<Shoal>(local);
		const Ptr it = shoal->find_("&");
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size_1 = flock->size_() - 1;
		Ptr param;
		Ptr value;
		for (int64_t i = 0; i < size_1; ++i)
		{
			if (i % 2 == 0)
			{
				param = flock->at_(i);
				continue;
			}
			value = it->next_();
			if (value->is_("."))
			{
				value = Expression::evaluate_(flock->at_(i), local); // default
			}
			shoal->update_(param, value);
		}
		try
		{
			return Expression::evaluate_(flock->at_(size_1), local);
		}
		catch (const Return& r)
		{
			return r.thing_();
		}
	}

	inline const Ptr _shared_scope_(const Ptr local) const
	{
		Flock* const flk = static_<Flock>(_flock);
		return static_<Shoal>(flk->at_(0))->find_(flk->at_(1));
	}
	
	inline const Ptr _relative_scope_(const Ptr local) const
	{
		// search scope from bottom to top
		Flock* const flk = static_<Flock>(_flock);
		Shoal* const shoal = static_<Shoal>(flk->at_(0));
		const Ptr key = flk->at_(1);
		const std::string& key_str = static_<Symbol>(key)->symbol_();
		std::string scope = static_<Symbol>(flk->at_(2))->symbol_();
		for (;;)
		{
			if (scope.empty())
			{
				return shoal->find_(key);
			}
			const Ptr result = shoal->find_(scope + "::" + key_str);
			if (!result->is_nothing_())
			{
				return result;
			}
			const size_t pos = scope.find_last_of("::");
			if (pos == std::string::npos)
			{
				scope = "";
			}
			else
			{
				scope = scope.substr(0, pos);
			}
		}
		return nothing_();
	}

	inline const Ptr _flock_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		const Ptr result = Flock::mut_();
		Flock* const res = static_<Flock>(result);
		for (int64_t i = 0; i < size; ++i)
		{
			res->push_back_(Expression::evaluate_(flock->at_(i), local));
		}
		return result;
	}

	inline const Ptr _flock_iterator_(const Ptr local) const
	{
		return Flock::mut(Expression::evaluate_(static_<Flock>(_flock)->at_(0), local));
	}

	inline const Ptr _shoal_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		const Ptr result = Shoal::mut_();
		Shoal* const res = static_<Shoal>(result);
		Ptr key;
		for (int64_t i = 0; i < size; ++i)
		{
			if (i % 2 == 0)
			{
				key = Expression::evaluate_(flock->at_(i), local);
			}
			else
			{
				res->update_(key, Expression::evaluate_(flock->at_(i), local));
			}
		}
		return result;
	}

	inline const Ptr _herd_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		const Ptr result = Herd::mut_();
		Herd* const res = static_<Herd>(result);
		for (int64_t i = 0; i < size; ++i)
		{
			res->insert_(Expression::evaluate_(flock->at_(i), local));
		}
		return result;
	}

	inline const Ptr _break_(const Ptr local) const
	{
		throw Break(Expression::evaluate_(static_<Flock>(_flock)->at_(0), local), false);
	}

	inline const Ptr _continue_(const Ptr local) const
	{
		throw Break(Expression::evaluate_(static_<Flock>(_flock)->at_(0), local), true);
	}

	inline const Ptr _return_(const Ptr local) const
	{
		throw Return(Expression::evaluate_(static_<Flock>(_flock)->at_(0), local));
	}

	inline const Ptr _throw_(const Ptr local) const
	{
		throw Expression::evaluate_(static_<Flock>(_flock)->at_(0), local);
	}

	inline const Ptr _catch_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		try
		{
			return Expression::evaluate_(flock->at_(0), local);
		}
		catch (const Ptr thing)
		{
			if (!thing->is_nothing_())
			{
				static_<Shoal>(local)->update_("%", thing);
			}
			return Expression::evaluate_(flock->at_(1), local);
		}
	}

	inline const Ptr _block_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		const int64_t size = flock->size_();
		Ptr result = nothing_();
		for (int64_t i = 0; i < size; ++i)
		{
			result = Expression::evaluate_(flock->at_(i), local);
		}
		return result;
	}

	inline const Ptr _if_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		if (!Expression::evaluate_(flock->at_(0), local)->is_nothing_())
		{
			return Expression::evaluate_(flock->at_(1), local);
		}
		return nothing_();
	}

	inline const Ptr _if_else_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		if (!Expression::evaluate_(flock->at_(0), local)->is_nothing_())
		{
			return Expression::evaluate_(flock->at_(1), local);
		}
		return Expression::evaluate_(flock->at_(2), local);
	}

	inline const Ptr _while_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		Ptr result = nothing_();
		while (!Expression::evaluate_(flock->at_(0), local)->is_nothing_())
		{
			try
			{
				result = Expression::evaluate_(flock->at_(1), local);
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

	inline const Ptr _do_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		Ptr result = nothing_();
		do
		{
			try
			{
				result = Expression::evaluate_(flock->at_(1), local);
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
		} while (!Expression::evaluate_(flock->at_(0), local)->is_nothing_());
		return result;
	}

	inline const Ptr _for_(const Ptr local) const
	{
		Flock* const flock = static_<Flock>(_flock);
		Ptr result = nothing_();
		for (Expression::evaluate_(flock->at_(0), local);
			!Expression::evaluate_(flock->at_(1), local)->is_nothing_();
			Expression::evaluate_(flock->at_(2), local))
		{
			try
			{
				result = Expression::evaluate_(flock->at_(3), local);
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

	class Iterator : public Mutable
	{
	public:
		inline Iterator(const Ptr flock, const Ptr local)
			: Mutable{}
			, _components{ flock }
			, _local{ local }
			, _pos{ 0 }
		{
		}

		virtual inline const Ptr next_() override
		{
			Flock* const flk = static_<Flock>(_components);
			if (_pos >= flk->size_())
			{
				return stop_();
			}
			return Expression::evaluate_(flk->at_(_pos++), _local);
		}

		virtual inline const Ptr copy_() const override
		{
			const Ptr result = mut_(_components, _local);
			static_<Iterator>(result)->_pos = _pos;
			return result;
		}

		static inline const Ptr mut_(const Ptr flock, const Ptr local)
		{
			return make_<Iterator>(flock, local);
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
		const Ptr _components;
		const Ptr _local;
		int64_t _pos;
	};

	class Break
	{
	public:
		inline Break(const Ptr thing, const bool cont)
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
		inline Return(const Ptr thing)
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

//======================================================================
// class Expression
//======================================================================

} // namespace strange

#endif
