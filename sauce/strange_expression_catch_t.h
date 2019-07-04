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
		forward_const_iterator_a<> pit = ++it;
		while (it != terms.cend_())
		{
			auto name = *it;
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-symbol name");
			}
			names.push_back(name);
			if (++it == terms.cend_())
			{
				throw dis(token.report() + "strange::expression_catch::val passed short range");
			}
			auto cat_expression = *it;
			if (!check<expression_a<>>(cat_expression))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-expression cat");
			}
			auto cat = cast<expression_a<>>(cat_expression).evaluate_();
			if (!check<cat_a<>>(cat))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-cat");
			}
			cats.push_back(cat);
			if (++it == terms.cend_())
			{
				throw dis(token.report() + "strange::expression_catch::val passed short range");
			}
			auto catch_expression = *it;
			if (!check<expression_a<>>(catch_expression))
			{
				throw dis(token.report() + "strange::expression_catch::val passed non-expression catch");
			}
			++it;
		}
		return expression_substitute_t<over>::val(over{ expression_catch_t<>(token, terms, cast<expression_a<>>(expression), range_t<>::val_(pit, terms.cend_()), names, cats) });
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
			auto pit = _parameters.cbegin_();
			auto cit = _cats.extract().cbegin();
			for (auto const& name : _names.extract())
			{
				++pit;
				++pit;
				auto cat = *cit++;
				if (exception.cats_().has_(cat))
				{
					cast<unordered_shoal_a<>>(thing).update_(name, exception);
					return pit->operate_(thing, range);
				}
				++pit;
			}
			throw;
		}
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" catch(");
		forward_const_iterator_a<> pit = _parameters.cbegin_();
		bool first = true;
		while (pit != _parameters.cend_())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			river.write_string(cast<symbol_a<>>(*pit).to_string() + " :");
			cast<expression_a<>>(*++pit).generate(indent, river);
			river.write_string("=");
			cast<expression_a<>>(*++pit).generate(indent, river);
			++pit;
		}
		river.write_string(")\n");
		_expression.generate(indent, river);
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" catch(");
		forward_const_iterator_a<> pit = _parameters.cbegin_();
		bool first = true;
		while (pit != _parameters.cend_())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto name = cast<symbol_a<>>(*pit).to_string();
			cast<expression_a<>>(*++pit).generate_cpp(indent, river);
			river.write_string( name + " =");
			cast<expression_a<>>(*++pit).generate_cpp(indent, river);
			++pit;
		}
		river.write_string(")\n");
		river.write_string("{\n");
		_expression.generate_cpp(indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _expression;
	range_a<> const _parameters;
	flock_a<> const _names;
	flock_a<> const _cats;

	inline expression_catch_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& expression, range_a<> const& parameters, flock_a<> const& names, flock_a<> const& cats)
		: expression_t(token, is_pure(expression, parameters), is_literal(expression, parameters))
		, _terms{ terms }
		, _expression{ expression }
		, _parameters{ parameters }
		, _names{ names }
		, _cats{ cats }
	{}

	static inline bool is_pure(expression_a<> const& expression, range_a<> const& parameters)
	{
		if (!expression.pure())
		{
			return false;
		}
		forward_const_iterator_a<> pit = parameters.cbegin_();
		while (pit != parameters.cend_())
		{
			if (!cast<expression_a<>>(*++pit).pure())
			{
				return false;
			}
			if (!cast<expression_a<>>(*++pit).pure())
			{
				return false;
			}
			++pit;
		}
		return true;
	}

	static inline bool is_literal(expression_a<> const& expression, range_a<> const& parameters)
	{
		if (!expression.literal())
		{
			return false;
		}
		forward_const_iterator_a<> pit = parameters.cbegin_();
		while (pit != parameters.cend_())
		{
			if (!cast<expression_a<>>(*++pit).literal())
			{
				return false;
			}
			if (!cast<expression_a<>>(*++pit).literal())
			{
				return false;
			}
			++pit;
		}
		return true;
	}
};

} // namespace strange

#endif
