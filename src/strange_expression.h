#ifndef COM_ONEISH_STRANGE_EXPRESSION_H
#define COM_ONEISH_STRANGE_EXPRESSION_H

#include "strange_core.h"
#include "strange_token.h"
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
	typedef const Ptr(Expression::*MemberPtr)(const Ptr&) const;

public:
	inline Expression(const Ptr& token, const MemberPtr member, const Ptr& flock)
		: Thing{}
		, _token(token)
		, _member{ member }
		, _flock{ flock }
		, _vector( static_<Flock>(_flock)->get_() )
	{
	}

	static inline const Ptr fin_(const Ptr& token, const MemberPtr member, const Ptr& flock)
	{
		flock->freeze_();
		return fake_<Expression>(token, member, flock);
	}

	static inline const Ptr fin_(const Ptr& token, const Ptr& statement, const Ptr& flock)
	{
		const int64_t size = static_<Flock>(flock)->size_();
		if (statement->is_("local_"))
		{
			if (size == 0)
			{
				return fin_(token, &Expression::_local_, flock);
			}
			throw std::length_error("local_ expression of wrong size");
		}
		else if (statement->is_("thing_"))
		{
			if (size == 1)
			{
				return fin_(token, &Expression::_thing_, flock);
			}
			throw std::length_error("thing_ expression of wrong size");
		}
		else if (statement->is_("invoke_"))
		{
			if (size >= 1)
			{
				return fin_(token, &Expression::_invoke_, flock);
			}
			throw std::length_error("invoke_ expression of wrong size");
		}
		else if (statement->is_("invoke_iterator_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_invoke_iterator_, flock);
			}
			throw std::length_error("invoke_iterator_ expression of wrong size");
		}
		else if (statement->is_("invoke_iterable_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_invoke_iterable_, flock);
			}
			throw std::length_error("invoke_iterable_ expression of wrong size");
		}
		else if (statement->is_("method_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_method_, flock);
			}
			throw std::length_error("method_ expression of wrong size");
		}
		else if (statement->is_("operate_iterator_"))
		{
			if (size == 3)
			{
				return fin_(token, &Expression::_operate_iterator_, flock);
			}
			throw std::length_error("operate_iterator_ expression of wrong size");
		}
		else if (statement->is_("operate_iterable_"))
		{
			if (size == 3)
			{
				return fin_(token, &Expression::_operate_iterable_, flock);
			}
			throw std::length_error("operate_iterable_ expression of wrong size");
		}
		else if (statement->is_("lambda_"))
		{
			if (size % 2 == 1)
			{
				return fin_(token, &Expression::_lambda_, flock);
			}
			throw std::length_error("lambda_ expression of wrong size");
		}
		else if (statement->is_("function_"))
		{
			if (size % 2 == 1)
			{
				return fin_(token, &Expression::_function_, flock);
			}
			throw std::length_error("function_ expression of wrong size");
		}
		else if (statement->is_("shared_scope_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_shared_scope_, flock);
			}
			throw std::length_error("shared_scope_ expression of wrong size");
		}
		else if (statement->is_("relative_scope_"))
		{
			if (size == 3)
			{
				return fin_(token, &Expression::_relative_scope_, flock);
			}
			throw std::length_error("relative_scope_ expression of wrong size");
		}
		else if (statement->is_("flock_"))
		{
			return fin_(token, &Expression::_flock_, flock);
		}
		else if (statement->is_("flock_iterator_"))
		{
			if (size == 1)
			{
				return fin_(token, &Expression::_flock_iterator_, flock);
			}
			throw std::length_error("flock_iterator_ expression of wrong size");
		}
		else if (statement->is_("shoal_"))
		{
			if (size % 2 == 0)
			{
				return fin_(token, &Expression::_shoal_, flock);
			}
			throw std::length_error("shoal_ expression of odd size");
		}
		else if (statement->is_("herd_"))
		{
			return fin_(token, &Expression::_herd_, flock);
		}
		else if (statement->is_("break_"))
		{
			if (size == 1)
			{
				return fin_(token, &Expression::_break_, flock);
			}
			throw std::length_error("break_ expression of wrong size");
		}
		else if (statement->is_("continue_"))
		{
			if (size == 1)
			{
				return fin_(token, &Expression::_continue_, flock);
			}
			throw std::length_error("continue_ expression of wrong size");
		}
		else if (statement->is_("return_"))
		{
			if (size == 1)
			{
				return fin_(token, &Expression::_return_, flock);
			}
			throw std::length_error("return_ expression of wrong size");
		}
		else if (statement->is_("throw_"))
		{
			if (size == 1)
			{
				return fin_(token, &Expression::_throw_, flock);
			}
			throw std::length_error("throw_ expression of wrong size");
		}
		else if (statement->is_("catch_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_catch_, flock);
			}
			throw std::length_error("catch_ expression of wrong size");
		}
		else if (statement->is_("block_"))
		{
			return fin_(token, &Expression::_block_, flock);
		}
		else if (statement->is_("if_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_if_, flock);
			}
			if (size == 3)
			{
				return fin_(token, &Expression::_if_else_, flock);
			}
			throw std::length_error("if_ expression of wrong size");
		}
		else if (statement->is_("while_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_while_, flock);
			}
			throw std::length_error("while_ expression of wrong size");
		}
		else if (statement->is_("do_"))
		{
			if (size == 2)
			{
				return fin_(token, &Expression::_do_, flock);
			}
			throw std::length_error("do_ expression of wrong size");
		}
		else if (statement->is_("for_"))
		{
			if (size == 4)
			{
				return fin_(token, &Expression::_for_, flock);
			}
			throw std::length_error("for_ expression of wrong size");
		}
		else
		{
			throw std::invalid_argument("expression with unexpected statement");
		}
		return fin_(token);
	}

	static inline const Ptr fin_(const Ptr& token, const Ptr& thing = nothing_())
	{
		const Ptr flock = Flock::mut_();
		static_<Flock>(flock)->push_back_(thing);
		return Expression::fin_(token, &Expression::_thing_, flock);
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
		loc->update_("$", Shoal::mut_());
		loc->update_("&", stop_());
		try
		{
			return evaluate_(expression, local);
		}
		catch (const Ptr& thing)
		{
			const Ptr to_lake = thing->invoke_("to_lake");
			Lake* const lake = dynamic_<Lake>(to_lake);
			if (lake)
			{
				throw std::runtime_error(lake->get_());
			}
			throw std::runtime_error("unexpected");
		}
	}

	static inline void generate_(const Ptr& expression, const Ptr& language, const Ptr& river)
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

	inline const Ptr iterator_(const Ptr& local) const
	{
		return Iterator::mut_(_vector, local);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Expression");
		return TYPE;
	}

private:
	const Ptr _token;
	const MemberPtr _member;
	const Ptr _flock;
	const std::vector<Ptr>& _vector;

	inline const Ptr _error_(const std::exception& err) const
	{
		return static_<Token>(_token)->error_(err.what());
	}

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

	inline const Ptr _local_(const Ptr& local) const
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

	inline const Ptr _thing_(const Ptr& local) const
	{
		return _vector[0];
	}

	inline void _generate_strange_thing_(River* const river) const
	{
		river->write_("£"); //TODO write strange literals
	}

	inline void _generate_cpp_thing_(River* const river) const
	{
		river->write_("£"); //TODO write cpp literals
	}

	inline const Ptr _invoke_(const Ptr& local) const
	{
		const Ptr it = iterator_(local);
		const Ptr thing = it->next_();
		try
		{
			return thing->invoke(it);
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
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

	inline const Ptr _invoke_iterator_(const Ptr& local) const
	{
		try
		{
			const Ptr thing = Expression::evaluate_(_vector[0], local);
			return thing->invoke(Expression::evaluate_(_vector[1], local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _invoke_iterable_(const Ptr& local) const
	{
		try
		{
			const Ptr thing = Expression::evaluate_(_vector[0], local);
			const Ptr iterable = Expression::evaluate_(_vector[1], local);
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
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _method_(const Ptr& local) const
	{
		try
		{
			const Ptr thing = Expression::evaluate_(_vector[0], local);
			return Method::with_name_(thing, Expression::evaluate_(_vector[1], local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _operate_iterator_(const Ptr& local) const
	{
		try
		{
			const Ptr thing = Expression::evaluate_(_vector[0], local);
			const Ptr member = static_<Shoal>(thing->pub_())->at_(Expression::evaluate_(_vector[1], local));
			return operate_(thing.get(), member, Expression::evaluate_(_vector[2], local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _operate_iterable_(const Ptr& local) const
	{
		try
		{
			const Ptr thing = Expression::evaluate_(_vector[0], local);
			const Ptr member = static_<Shoal>(thing->pub_())->at_(Expression::evaluate_(_vector[1], local));
			const Ptr iterable = Expression::evaluate_(_vector[2], local);
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
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _lambda_(const Ptr& local) const
	{
		try
		{
			Shoal* const shoal = static_<Shoal>(local);
			Shoal* const shared = static_<Shoal>(shoal->at_("$"));
			const size_t size_1 = _vector.size() - 1;
			Ptr param;
			for (size_t i = 0; i < size_1; ++i)
			{
				if (i % 2 == 0)
				{
					param = _vector[i];
					continue;
				}
				shared->update_(param, Expression::evaluate_(_vector[i], local));
			}
			return Expression::evaluate_(_vector[size_1], local);
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _function_(const Ptr& local) const
	{
		try
		{
			Shoal* const shoal = static_<Shoal>(local);
			const Ptr it = shoal->at_("&");
			const size_t size_1 = _vector.size() - 1;
			Ptr param;
			Ptr value;
			for (size_t i = 0; i < size_1; ++i)
			{
				if (i % 2 == 0)
				{
					param = _vector[i];
					continue;
				}
				value = it->next_();
				if (value->is_("."))
				{
					value = Expression::evaluate_(_vector[i], local); // default
				}
				shoal->update_(param, value);
			}
			try
			{
				return Expression::evaluate_(_vector[size_1], local);
			}
			catch (const Return& r)
			{
				return r.thing_();
			}
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _shared_scope_(const Ptr& local) const
	{
		const Ptr result = static_<Shoal>(_vector[0])->at_(_vector[1]);
		if (result->is_nothing_())
		{
			throw _error_(std::runtime_error("not found in shared scope"));
		}
		return result;
	}
	
	inline const Ptr _relative_scope_(const Ptr& local) const
	{
		// search scope from bottom to top
		Shoal* const shoal = static_<Shoal>(_vector[0]);
		const Ptr key = _vector[1];
		const std::string& key_str = static_<Symbol>(key)->get_();
		std::string scope = static_<Symbol>(_vector[2])->get_();
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
		throw _error_(std::runtime_error("not found in relative scope"));
	}

	inline const Ptr _flock_(const Ptr& local) const
	{
		try
		{
			return Flock::mut(iterator_(local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _flock_iterator_(const Ptr& local) const
	{
		try
		{
			return Flock::mut(Expression::evaluate_(_vector[0], local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _shoal_(const Ptr& local) const
	{
		try
		{
			return Shoal::mut(iterator_(local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _herd_(const Ptr& local) const
	{
		try
		{
			return Herd::mut(iterator_(local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _break_(const Ptr& local) const
	{
		try
		{
			throw Break(Expression::evaluate_(_vector[0], local), false);
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _continue_(const Ptr& local) const
	{
		try
		{
			throw Break(Expression::evaluate_(_vector[0], local), true);
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _return_(const Ptr& local) const
	{
		try
		{
			throw Return(Expression::evaluate_(_vector[0], local));
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _throw_(const Ptr& local) const
	{
		try
		{
			throw Expression::evaluate_(_vector[0], local);
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _catch_(const Ptr& local) const
	{
		try
		{
			return Expression::evaluate_(_vector[0], local);
		}
		catch (const Ptr& thing)
		{
			if (!thing->is_nothing_())
			{
				static_<Shoal>(local)->update_("%", thing);
			}
			return Expression::evaluate_(_vector[1], local);
		}
		catch (const std::exception& err)
		{
			static_<Shoal>(local)->update_("%", _error_(err));
			return Expression::evaluate_(_vector[1], local);
		}
	}

	inline const Ptr _block_(const Ptr& local) const
	{
		try
		{
			const size_t size = _vector.size();
			Ptr result = nothing_();
			for (size_t i = 0; i < size; ++i)
			{
				result = Expression::evaluate_(_vector[i], local);
			}
			return result;
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _if_(const Ptr& local) const
	{
		try
		{
			if (!Expression::evaluate_(_vector[0], local)->is_nothing_())
			{
				return Expression::evaluate_(_vector[1], local);
			}
			return nothing_();
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _if_else_(const Ptr& local) const
	{
		try
		{
			if (!Expression::evaluate_(_vector[0], local)->is_nothing_())
			{
				return Expression::evaluate_(_vector[1], local);
			}
			return Expression::evaluate_(_vector[2], local);
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _while_(const Ptr& local) const
	{
		try
		{
			Ptr result = nothing_();
			while (!Expression::evaluate_(_vector[0], local)->is_nothing_())
			{
				try
				{
					result = Expression::evaluate_(_vector[1], local);
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
			throw _error_(err);
		}
	}

	inline const Ptr _do_(const Ptr& local) const
	{
		try
		{
			Ptr result = nothing_();
			do
			{
				try
				{
					result = Expression::evaluate_(_vector[1], local);
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
			} while (!Expression::evaluate_(_vector[0], local)->is_nothing_());
			return result;
		}
		catch (const std::exception& err)
		{
			throw _error_(err);
		}
	}

	inline const Ptr _for_(const Ptr& local) const
	{
		try
		{
			Ptr result = nothing_();
			for (Expression::evaluate_(_vector[0], local);
				!Expression::evaluate_(_vector[1], local)->is_nothing_();
				Expression::evaluate_(_vector[2], local))
			{
				try
				{
					result = Expression::evaluate_(_vector[3], local);
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
			throw _error_(err);
		}
	}

	class Iterator : public Mutable
	{
	public:
		inline Iterator(const std::vector<Ptr>& vec, const Ptr& local)
			: Mutable{}
			, _elements{ vec }
			, _local{ local }
			, _pos{ 0 }
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
			const Ptr result = mut_(_elements, _local);
			static_<Iterator>(result)->_pos = _pos;
			return result;
		}

		static inline const Ptr mut_(const std::vector<Ptr>& vec, const Ptr& local)
		{
			return make_<Iterator>(vec, local);
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

//======================================================================
// class Expression
//======================================================================

} // namespace strange

#endif
