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
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_catch::create not passed any terms");
		}
		any_a<> try_expression = *it;
		if (!check<expression_a<>>(try_expression))
		{
			throw dis(token.report() + "strange::expression_catch::create passed non-expression try");
		}
		auto names = flock_t<>::create_();
		auto kinds = flock_t<>::create_();
		auto expressions = flock_t<>::create_();
		while (++it != terms.cend_())
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
			auto subterms = cast<expression_a<>>(term).terms_();
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
		return expression_substitute_t<over>::create(over{ expression_catch_t<>(token, terms, cast<expression_a<>>(try_expression), names, kinds, expressions) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_catch_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_catch_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_catch::operate passed non-unordered-shoal local");
		}
#endif
		try
		{
			return _try_expression.operate(thing, range);
		}
		catch (any_a<>& exception)
		{
			auto kit = _kinds.extract().cbegin();
			auto eit = _expressions.extract().cbegin();
			for (auto const& name : _names.extract())
			{
				auto kind = *kit++;
				if (check<expression_a<>>(kind))
				{
					try
					{
						kind = cast<expression_a<>>(kind).operate(thing, range);
					}
					catch (misunderstanding_a<>& misunderstanding)
					{
						throw dis(_token.report() + "strange::expression_catch::operate kind expression returned non-kind") + misunderstanding;
					}
				}
				if (exception.kinds_().has_(kind))
				{
					cast<unordered_shoal_a<>>(thing).update_(name, exception);
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
		river.write_string(" catch(");
		bool first = true;
		for (auto const& term : _terms)
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string("\n,");
			}
			cast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string("\n)\n");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string("try\n{\n");
		_try_expression.generate_cpp(version, indent, river);
		river.write_string("\n}\n");
		forward_const_iterator_a<> kit = _kinds.cbegin_();
		forward_const_iterator_a<> eit = _expressions.cbegin_();
		for (auto const& name : _names)
		{
			river.write_string("catch(" + cast<kind_a<>>(*kit++).name_().to_string() + "_a<> const& exception)\n{\n");
			cast<expression_a<>>(*eit++).generate_cpp(version, indent, river);
			river.write_string("\n}\n");
		}
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _try_expression;
	flock_a<> const _kinds;
	flock_a<> const _expressions;

	inline expression_catch_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& try_expression, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& expressions)
		: expression_t(token, pure_literal_terms(token, terms), names)
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
	auto shoal = shoal_a<>(shared(), true);
	expression_catch_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
