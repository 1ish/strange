#ifndef COM_ONEISH_STRANGE_EXPRESSION_CATCH_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CATCH_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_catch_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_catch_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_catch::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_catch::create passed non-symbol scope");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_catch::create passed too few terms");
		}
		any_a<> try_expression = *it;
		if (!check<expression_a<>>(try_expression))
		{
			throw dis(token.report() + "strange::expression_catch::create passed non-expression try");
		}
		auto names = flock_t<>::create_();
		auto kinds = flock_t<>::create_();
		auto expressions = flock_t<>::create_();
		while (++it != terms.extract_end_())
		{
			auto const& term = *it;
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_catch::create passed non-expression catch");
			}
			if (!term.type_().is("strange::expression_local_insert"))
			{
				throw dis(token.report() + "strange::expression_catch::create passed invalid catch term");
			}
			auto subterms = fast<expression_a<>>(term).terms_();
			if (subterms.size() != 3)
			{
				throw dis(token.report() + "strange::expression_catch::create passed wrong number of subterms");
			}

			auto name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_catch::create passed non-symbol");
			}
			names.push_back(name);

			auto kind = subterms.at_index(1);
			if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
			{
				throw dis(token.report() + "strange::expression_catch::create passed non-kind/expression");
			}
			kinds.push_back(kind);

			if (subterms.size() == 3)
			{
				auto const expression = subterms.at_index(2);
				if (!check<expression_a<>>(expression))
				{
					throw dis(token.report() + "strange::expression_catch::create passed non-expression");
				}
				expressions.push_back(expression);
			}
			else
			{
				expressions.push_back(expression_t<>::create(token));
			}
		}
		return expression_substitute_t<expression_catch_t<>>::create(expression_catch_t<>(token, terms, fast<expression_a<>>(try_expression), names, kinds, expressions));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_catch");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_catch::create"), native_function_create(&expression_catch_t<>::create__));
		shoal.update(sym("catch!"), native_function_create(&expression_catch_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_catch::operate passed non-unordered-shoal local");
		}
#endif
		try
		{
			return _try_expression.operate(thing, list);
		}
		catch (any_a<>& exception)
		{
			auto kit = _kinds.extract_vector().cbegin();
			auto eit = _expressions.extract_vector().cbegin();
			for (auto const& name : expression_t<___ego___>::_names.extract_vector())
			{
				auto kind = *kit++;
				if (check<expression_a<>>(kind))
				{
					try
					{
						kind = fast<expression_a<>>(kind).operate(thing, list);
					}
					catch (misunderstanding_a<>& misunderstanding)
					{
						throw dis(expression_t<___ego___>::_token.report() + "strange::expression_catch::operate kind expression returned non-kind") + misunderstanding;
					}
				}
				if (exception.kinds_().has_(kind))
				{
					fast<unordered_shoal_a<>>(thing).update_(name, exception);
					return eit->operate(thing, list);
				}
				++eit;
			}
			throw;
		}
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_catch_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, list_create());
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		// catch(name :<kind>= expression)
		river.write_string(" catch\n(\n");
		_try_expression.generate(version, indent, river);
		auto kit = _kinds.extract_begin_();
		auto eit = _expressions.extract_begin_();
		for (auto const& name : expression_t<___ego___>::_names.extract_vector())
		{
			river.write_string(", " + fast<symbol_a<>>(name).to_string());
			auto kind = *kit;
			++kit;
			if (check<kind_a<>>(kind))
			{
				river.write_string(fast<kind_a<>>(kind).to_string());
			}
			else if (check<expression_a<>>(kind))
			{
				fast<expression_a<>>(kind).generate(version, indent, river);
			}
			fast<expression_a<>>(*eit).generate(version, indent, river);
			++eit;
		}
		river.write_string(")\n");
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_try_expression.generate_cpp(version, indent, river, declare, define);
			for (auto const& expression : _expressions.extract_vector())
			{
				if (!check<expression_a<>>(expression))
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_catch::generate_cpp with non-expression");
				}
				fast<expression_a<>>(expression).generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_catch::generate_cpp called for wrong type of expression");
		}
		river.write_string("try\n{\n");
		_try_expression.generate_cpp(version, indent, river, declare, define);
		river.write_string("\n}\n");
		auto kit = _kinds.extract_begin_();
		auto eit = _expressions.extract_begin_();
		for (auto const& name : expression_t<___ego___>::_names.extract_vector())
		{
			river.write_string("catch(" + fast<kind_a<>>(*kit).code() + " const& exception)\n{\n");
			++kit;
			fast<expression_a<>>(*eit).generate_cpp(version, indent, river, declare, define);
			++eit;
			river.write_string("\n}\n");
		}
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _try_expression;
	flock_a<> const _kinds;
	flock_a<> const _expressions;

	friend class any_a<>;

	inline expression_catch_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& try_expression, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& expressions)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms), names)
		, _terms{ terms }
		, _try_expression{ try_expression }
		, _kinds{ kinds }
		, _expressions{ expressions }
	{}

private:
	static bool const ___share___;
	friend class ___expression_catch_t_share___;
};

template <typename ___ego___>
bool const expression_catch_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_catch_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_catch_t_share___
{
	static inline bool ___share___()
	{
		return expression_catch_t<>::___share___;
	}
};

} // namespace strange

#endif
