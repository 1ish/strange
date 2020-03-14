#ifndef COM_ONEISH_STRANGE_EXPRESSION_CATCH_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CATCH_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_catch_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_catch_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_extractor_a<> it = terms.extract_begin_();
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
		return expression_substitute_t<over>::create(over{ expression_catch_t<>(token, terms, fast<expression_a<>>(try_expression), names, kinds, expressions) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_catch");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_catch::create", native_function_create(&expression_catch_t<>::over::create__));
		shoal.update_string("catch!", native_function_create(&expression_catch_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_catch::operate passed non-unordered-shoal local");
		}
#endif
		try
		{
			return _try_expression.operate(thing, range);
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
						kind = fast<expression_a<>>(kind).operate(thing, range);
					}
					catch (misunderstanding_a<>& misunderstanding)
					{
						throw dis(expression_t<___ego___>::_token.report() + "strange::expression_catch::operate kind expression returned non-kind") + misunderstanding;
					}
				}
				if (exception.kinds_().has_(kind))
				{
					fast<unordered_shoal_a<>>(thing).update_(name, exception);
					return eit->operate(thing, range);
				}
				++eit;
			}
			throw;
		}
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		// catch(name :<kind>= expression)
		river.write_string(" catch\n(\n");
		_try_expression.generate(version, indent, river);
		forward_extractor_a<> kit = _kinds.extract_begin_();
		forward_extractor_a<> eit = _expressions.extract_begin_();
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
		forward_extractor_a<> kit = _kinds.extract_begin_();
		forward_extractor_a<> eit = _expressions.extract_begin_();
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
