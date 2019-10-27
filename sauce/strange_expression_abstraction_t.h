#ifndef COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_ABSTRACTION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_abstraction_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_abstraction_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto dimension_names = flock_t<>::create_();
		auto dimension_kinds = flock_t<>::create_();
		auto dimension_expressions = flock_t<>::create_();
		auto dimension_defaults = flock_t<>::create_();
		auto parent_expressions = flock_t<>::create_();
		auto parent_shoals = flock_t<>::create_();
		any_a<> name = no();
		any_a<> kind = no();
		any_a<> value = no();
		auto it = terms.cbegin_();
		bool end = it == terms.cend_();
		while (!end)
		{
			auto const& term = *it;
			end = ++it == terms.cend_();
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed non-expression term");
			}
			if (end)
			{
				if (!term.type_().is("strange::expression_block"))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-block last term");
				}
				auto const subterms = cast<expression_a<>>(term).terms_();
				if (subterms.empty())
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed no subterms");
				}
				for (auto const& subterm : subterms)
				{
					if (!check<expression_a<>>(subterm))
					{
						throw dis(token.report() + "strange::expression_abstraction::create passed non-expression subterm");
					}
					try
					{
						auto const parent_shoal = cast<expression_a<>>(subterm).evaluate_();
						if (!check<unordered_shoal_a<>>(parent_shoal))
						{
							throw dis("parent does not evaluate to an unordered shoal");
						}
						parent_expressions.push_back(subterm);
						parent_shoals.push_back(parent_shoal);
					}
					catch (misunderstanding_a<>& misunderstanding)
					{
						throw dis("strange::expression_abstraction::create parent shoal evaluation error:") + token.report_() + misunderstanding;
					}
				}
				break;
			}
			if (term.type_().is("strange::expression_local_at") ||
				term.type_().is("strange::expression_intimate_attribute") &&
					cast<expression_a<>>(term).terms_().size() == 1)
			{
				auto subterms = cast<expression_a<>>(term).terms_();
				if (subterms.size() != 1)
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed wrong number of dimension subterms");
				}
				name = subterms.at_index(0);
				if (!check<symbol_a<>>(name))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-symbol dimension name");
				}
				kind = kind_t<>::create_();
				value = expression_t<>::create(token);
			}
			else if (term.type_().is("strange::expression_local_insert") ||
				term.type_().is("strange::expression_local_update") ||
				term.type_().is("strange::expression_intimate_attribute") &&
					cast<expression_a<>>(term).terms_().size() == 3)
			{
				auto subterms = cast<expression_a<>>(term).terms_();
				if (subterms.size() != 3)
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed wrong number of dimension subterms");
				}
				name = subterms.at_index(0);
				if (!check<symbol_a<>>(name))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-symbol dimension name");
				}
				kind = subterms.at_index(1); //TODO optional?
				if (!check<kind_a<>>(kind))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-kind dimension kind");
				}
				value = subterms.at_index(2);
				if (!check<expression_a<>>(value))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-expression dimension default");
				}
			}
			else
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed invalid dimension term");
			}
			dimension_names.push_back(name);
			dimension_kinds.push_back(kind);
			dimension_expressions.push_back(value);
			try
			{
				dimension_defaults.push_back(cast<expression_a<>>(value).evaluate_());
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_abstraction::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<over>::create(over{ expression_abstraction_t<>(token, terms, dimension_names, dimension_kinds, dimension_expressions, dimension_defaults, parent_expressions, parent_shoals) },
			abstraction_t<>::create_(token, dimension_names, dimension_kinds, dimension_defaults, parent_shoals));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_abstraction_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_abstraction_t<>>::share(shoal);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" abstraction(");
		auto nit = _dimension_names.extract().cbegin();
		auto pit = _dimension_kinds.extract().cbegin();
		auto vit = _dimension_expressions.extract().cbegin();
		bool first = true;
		for (auto const& def : _dimension_defaults.extract())
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
			auto kind = cast<kind_a<>>(*pit++);
			auto value = cast<expression_a<>>(*vit++);
			river.write_string(name.to_string() + ":");
			river.write_string(kind.to_string() + "=");
			value.generate(version, indent, river);
		}
		river.write_string(")\n");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" [](");
		auto nit = _dimension_names.extract().cbegin();
		auto pit = _dimension_kinds.extract().cbegin();
		auto vit = _dimension_expressions.extract().cbegin();
		bool first = true;
		for (auto const& def : _dimension_defaults.extract())
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
			auto kind = cast<kind_a<>>(*pit++);
			auto value = cast<expression_a<>>(*vit++);
			river.write_string("catch(" + kind.name_().to_string() + "_a<> const& ");
			river.write_string(name.to_string() + " =");
			value.generate_cpp(version, indent, river);
		}
		river.write_string(")\n{\n");
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	flock_a<> const _dimension_names;
	flock_a<> const _dimension_kinds;
	flock_a<> const _dimension_expressions;
	flock_a<> const _dimension_defaults;
	flock_a<> const _parent_expressions;
	flock_a<> const _parent_shoals;

	inline expression_abstraction_t(token_a<> const& token, flock_a<> const& terms, flock_a<> const& dimension_names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_expressions, flock_a<> const& dimension_defaults, flock_a<> const& parent_expressions, flock_a<> const& parent_shoals)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _dimension_names{ dimension_names }
		, _dimension_kinds{ dimension_kinds }
		, _dimension_expressions{ dimension_expressions }
		, _dimension_defaults{ dimension_defaults }
		, _parent_expressions{ parent_expressions }
		, _parent_shoals{ parent_shoals }
	{}

private:
	static bool const ___share___;
	friend class ___expression_abstraction_t_share___;
};

template <typename ___ego___>
bool const expression_abstraction_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_abstraction_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
