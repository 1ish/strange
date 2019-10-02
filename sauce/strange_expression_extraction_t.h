#ifndef COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_EXTRACTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_extraction_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_extraction_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		auto names = flock_t<>::val_();
		auto params = flock_t<>::val_();
		auto values = flock_t<>::val_();
		auto defaults = flock_t<>::val_();
		any_a<> name = sym("");
		any_a<> cat = cat_t<>::val_();
		any_a<> value = no();
		for (auto const& term : terms)
		{
			if (value)
			{
				names.push_back(name);
				params.push_back(cat);
				values.push_back(value);
				try
				{
					defaults.push_back(cast<expression_a<>>(value).evaluate_());
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis("strange::expression_extraction::val parameter default evaluation error:") + token.report_() + misunderstanding;
				}
			}

			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_extraction::val passed non-expression catch");
			}
			auto subterms = cast<expression_a<>>(term).terms_();
			if (subterms.size() != 3)
			{
				throw dis(token.report() + "strange::expression_extraction::val passed wrong number of subterms");
			}

			name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_extraction::val passed non-symbol name");
			}

			cat = subterms.at_index(1);
			if (!check<cat_a<>>(cat))
			{
				throw dis(token.report() + "strange::expression_extraction::val passed non-cat");
			}

			value = subterms.at_index(2);
			if (!check<expression_a<>>(value))
			{
				throw dis(token.report() + "strange::expression_extraction::val passed non-expression catch");
			}
		}
		if (!value)
		{
			value = expression_t<>::val(token);
		}
		return expression_substitute_t<over>::val(over{ expression_extraction_t<>(token, terms, names, params, values, defaults, cast<symbol_a<>>(name), cast<cat_a<>>(cat), cast<expression_a<>>(value)) },
			extraction_t<>::val_(token, names, params, defaults, cast<symbol_a<>>(name), cast<cat_a<>>(cat), cast<expression_a<>>(value)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_extraction_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_extraction_t<>>::share(shoal);
	}

	inline cat_a<> cat_() const
	{
		return _cat;
	}

	inline unordered_herd_a<> cats_() const
	{
		return _cats;
	}

	inline kind_a<> kind_() const
	{
		return _kind;
	}

	inline unordered_herd_a<> kinds_() const
	{
		return _kinds;
	}

	inline any_a<> eater_() const
	{
		return _names;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" extraction(");
		auto nit = _names.extract().cbegin();
		auto pit = _params.extract().cbegin();
		auto vit = _values.extract().cbegin();
		bool first = true;
		for (auto const& def : _defaults.extract())
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
			auto cat = cast<cat_a<>>(*pit++);
			auto value = cast<expression_a<>>(*vit++);
			river.write_string(name.to_string() + ":");
			river.write_string(cat.to_string() + "=");
			value.generate(version, indent, river);
		}
		river.write_string(")\n");
		_expression.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" [](");
		auto nit = _names.extract().cbegin();
		auto pit = _params.extract().cbegin();
		auto vit = _values.extract().cbegin();
		bool first = true;
		for (auto const& def : _defaults.extract())
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
			auto cat = cast<cat_a<>>(*pit++);
			auto value = cast<expression_a<>>(*vit++);
			river.write_string("catch(" + cat.name_().to_string() + "_a<> const& ");
			river.write_string(name.to_string() + " =");
			value.generate_cpp(version, indent, river);
		}
		river.write_string(")\n{\n");
		_expression.generate_cpp(version, indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	flock_a<> const _names;
	flock_a<> const _params;
	flock_a<> const _values;
	flock_a<> const _defaults;
	symbol_a<> const _name;
	cat_a<> const _result;
	expression_a<> const _expression;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;

	inline expression_extraction_t(token_a<> const& token, flock_a<> const& terms, flock_a<> const& names, flock_a<> const& params, flock_a<> const& values, flock_a<> const& defaults, symbol_a<> const& name, cat_a<> const& result, expression_a<> const& expression)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _names{ names }
		, _params{ params }
		, _values{ values }
		, _defaults{ defaults }
		, _name{ name }
		, _result{ result }
		, _expression{ expression }
		, _cat{ cat_t<>::val_(number_int_64_t<>::val(1), _name, flock_t<>::val_(), _params, _result) }
		, _cats{ cats(_cat) }
		, _kind{ kind_from_cat(_cat) }
		, _kinds{ kinds(_kind) }
	{}

private:
	static bool const ___share___;
	friend class ___expression_extraction_t_share___;
};

template <typename ___ego___>
bool const expression_extraction_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_extraction_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
