#ifndef COM_ONEISH_STRANGE_EXPRESSION_CATCH_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CATCH_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_catch_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_catch_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_catch::val not passed any terms");
		}
		any_a<> expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_catch::val passed non-expression try");
		}
		auto names = flock_t<>::val_();
		auto cats = flock_t<>::val_();
		auto values = flock_t<>::val_();
		while (++it != terms.cend_())
		{
			auto term = *it;
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-expression catch");
			}
			auto subterms = cast<expression_a<>>(term).terms_();
			if (subterms.size() != 3)
			{
				throw dis(token.report() + "strange::expression_catch::val passed wrong number of subterms");
			}

			auto name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-symbol name");
			}
			names.push_back(name);

			auto cat = subterms.at_index(1);
			if (!check<cat_a<>>(cat))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-cat");
			}
			cats.push_back(cat);

			auto value = subterms.at_index(2);
			if (!check<expression_a<>>(value))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-expression catch");
			}
			values.push_back(value);
		}
		return expression_substitute_t<over>::val(over{ expression_catch_t<>(token, terms, cast<expression_a<>>(expression), names, cats, values) });
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

	inline any_a<> eater_() const
	{
		return _names;
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_catch::operate passed non-unordered-shoal local");
		}
#endif
		try
		{
			return _expression.operate_(thing, range);
		}
		catch (any_a<>& exception)
		{
			auto cit = _cats.extract().cbegin();
			auto vit = _values.extract().cbegin();
			for (auto const& name : _names.extract())
			{
				if (exception.cats_().has_(*cit++))
				{
					cast<unordered_shoal_a<>>(thing).update_(name, exception);
					return vit->operate_(thing, range);
				}
				++vit;
			}
			throw;
		}
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
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

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string("try\n{\n");
		_expression.generate_cpp(version, indent, river);
		river.write_string("\n}\n");
		forward_const_iterator_a<> cit = _cats.cbegin_();
		forward_const_iterator_a<> vit = _values.cbegin_();
		for (auto const& name : _names)
		{
			river.write_string("catch(" + cast<cat_a<>>(*cit++).name_().to_string() + "_a<> const& exception)\n{\n");
			cast<expression_a<>>(*vit++).generate_cpp(version, indent, river);
			river.write_string("\n}\n");
		}
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _expression;
	flock_a<> const _names;
	flock_a<> const _cats;
	flock_a<> const _values;

	inline expression_catch_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& expression, flock_a<> const& names, flock_a<> const& cats, flock_a<> const& values)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _expression{ expression }
		, _names{ names }
		, _cats{ cats }
		, _values{ values }
	{}

private:
	static bool const ___share___;
	friend class ___expression_catch_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_catch_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_catch_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
