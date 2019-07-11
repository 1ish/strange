#ifndef COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FUNCTION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_function_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_function_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		auto names = flock_t<>::val_();
		auto cats = flock_t<>::val_();
		auto values = flock_t<>::val_();
		auto evaluated = flock_t<>::val_();
		any_a<> value = no();
		for (auto const& term : terms)
		{
			if (value)
			{
				evaluated.push_back(cast<expression_a<>>(value).evaluate_());
			}

			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-expression catch");
			}
			auto subterms = cast<expression_a<>>(term).terms_();
			if (subterms.size() != 3)
			{
				throw dis(token.report() + "strange::expression_function::val passed wrong number of subterms");
			}

			auto name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-symbol name");
			}
			names.push_back(name);

			auto cat = subterms.at_index(1);
			if (!check<cat_a<>>(cat))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-cat");
			}
			cats.push_back(cat);

			value = subterms.at_index(2);
			if (!check<expression_a<>>(value))
			{
				throw dis(token.report() + "strange::expression_function::val passed non-expression catch");
			}
			values.push_back(value);
		}
		return expression_substitute_t<over>::val(over{ expression_function_t<>(token, terms, names, cats, values, evaluated) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_function_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_function_t<>>::share(shoal);
	}

	inline any_a<> eater_() const
	{
		return _names;
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		auto local_shoal = unordered_shoal_t<>::val_();
		auto& local = local_shoal.reference();
		local.emplace(sym("$"), _shared);
		local.emplace(sym("^"), thing);
		forward_const_iterator_a<> ait = range.cbegin_();
		auto nit = _names.extract().cbegin();
		auto cit = _cats.extract().cbegin();
		auto vit = _values.extract().cbegin();
		for (auto const& eval : _evaluated.extract())
		{
			++vit;
			any_a<> argument = (ait == range.cend_())
				? eval
				: (*ait++);
			if (!argument.cats_().has_(*cit++))
			{
				throw dis(_token.report() + "strange::expression_function::operate cat does not include argument");
			}
			local.emplace(*nit++, argument);
		}
		try
		{
			auto result = vit->operate_(local_shoal, range);
			if (!result.cats_().has_(*cit))
			{
				throw dis(_token.report() + "strange::expression_function::operate cat does not include result");
			}
			return result;
		}
		catch (return_i& ret)
		{
			if (!ret.result.cats_().has_(*cit))
			{
				throw dis(_token.report() + "strange::expression_function::operate cat does not include result");
			}
			return ret.result;
		}
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" function(");
		auto nit = _names.extract().cbegin();
		auto cit = _cats.extract().cbegin();
		auto vit = _values.extract().cbegin();
		bool first = true;
		for (auto const& eval : _evaluated.extract())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto name = cast<symbol_a<>>(*nit++);
			auto cat = cast<cat_a<>>(*cit++);
			auto value = cast<expression_a<>>(*vit++);
			river.write_string(name.to_string() + ":");
			river.write_string(cat.to_string() + "=");
			value.generate(indent, river);
		}
		river.write_string(")\n");
		cast<expression_a<>>(*vit).generate(indent, river);
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_string(" [](");
		auto nit = _names.extract().cbegin();
		auto cit = _cats.extract().cbegin();
		auto vit = _values.extract().cbegin();
		bool first = true;
		for (auto const& eval : _evaluated.extract())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			auto name = cast<symbol_a<>>(*nit++);
			auto cat = cast<cat_a<>>(*cit++);
			auto value = cast<expression_a<>>(*vit++);
			river.write_string("catch(" + cat.name_().to_string() + "_a<> const& ");
			river.write_string(name.to_string() + " =");
			value.generate_cpp(indent, river);
		}
		river.write_string(")\n{\n");
		cast<expression_a<>>(*vit).generate_cpp(indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	flock_a<> const _names;
	flock_a<> const _cats;
	flock_a<> const _values;
	flock_a<> const _evaluated;
	unordered_shoal_a<> const _shared;

	inline expression_function_t(token_a<> const& token, flock_a<> const& terms, flock_a<> const& names, flock_a<> const& cats, flock_a<> const& values, flock_a<> const& evaluated)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _names{ names }
		, _cats{ cats }
		, _values{ values }
		, _evaluated{ evaluated }
		, _shared{ unordered_shoal_t<true>::val_() }
	{}
};

} // namespace strange

#endif
