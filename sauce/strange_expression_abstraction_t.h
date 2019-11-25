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
			if (end) // parents
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
					parent_expressions.push_back(subterm);
				}
				break;
			}
			// dimensions
			if (!term.type_().is("strange::expression_local_at") &&
				!term.type_().is("strange::expression_local_insert"))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed invalid dimension term");
			}
			auto const subterms = cast<expression_a<>>(term).terms_();
			int64_t const count = subterms.size();
			auto const name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed non-symbol dimension name");
			}
			if (cast<symbol_a<>>(name).first_character() != '#')
			{
				throw dis(token.report() + "strange::expression_abstraction::create passed dimension name without # preceding it");
			}
			dimension_names.push_back(name);
			if (count == 1)
			{
				dimension_kinds.push_back(kind_t<>::create_());
			}
			else
			{
				auto const kind = subterms.at_index(1);
				if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-kind/expression dimension kind");
				}
				dimension_kinds.push_back(kind);
			}
			auto expression = no();
			if (count == 3)
			{
				expression = subterms.at_index(2);
				if (!check<expression_a<>>(expression))
				{
					throw dis(token.report() + "strange::expression_abstraction::create passed non-expression dimension default");
				}
			}
			else
			{
				expression = expression_t<>::create(token);
			}
			dimension_expressions.push_back(expression);
			try
			{
				dimension_defaults.push_back(cast<expression_a<>>(expression).evaluate_());
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::expression_abstraction::create parameter default evaluation error:") + token.report_() + misunderstanding;
			}
		}
		return expression_substitute_t<over>::create(over{ expression_abstraction_t<>(token, terms, dimension_names, dimension_kinds, dimension_expressions, dimension_defaults, parent_expressions) },
			abstraction_t<>::create_(token, dimension_names, dimension_kinds, dimension_defaults, parent_expressions));
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
		auto kit = _dimension_kinds.extract().cbegin();
		auto eit = _dimension_expressions.extract().cbegin();
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
			auto const name = cast<symbol_a<>>(*nit++);
			auto const kind = *kit++;
			auto const expression = cast<expression_a<>>(*eit++);
			river.write_string(name.to_string() + ":");
			if (check<kind_a<>>(kind))
			{
				river.write_string(cast<kind_a<>>(kind).to_string() + "=");
			}
			else
			{
				cast<expression_a<>>(kind).generate(version, indent, river);
			}
			expression.generate(version, indent, river);
		}
		river.write_string(")\n");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string(" [](");
		auto nit = _dimension_names.extract().cbegin();
		auto kit = _dimension_kinds.extract().cbegin();
		auto eit = _dimension_expressions.extract().cbegin();
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
			auto const name = cast<symbol_a<>>(*nit++);
			auto const kind = *kit++;
			auto const expression = cast<expression_a<>>(*eit++);
			if (check<kind_a<>>(kind))
			{
				river.write_string("catch(" + cast<kind_a<>>(kind).name_().to_string() + "_a<> const& ");
				river.write_string(cast<kind_a<>>(kind).to_string() + " =");
			}
			else
			{
				cast<expression_a<>>(kind).generate_cpp(version, indent, river);
			}
			expression.generate_cpp(version, indent, river);
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

	inline expression_abstraction_t(token_a<> const& token, flock_a<> const& terms, flock_a<> const& dimension_names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_expressions, flock_a<> const& dimension_defaults, flock_a<> const& parent_expressions)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _dimension_names{ dimension_names }
		, _dimension_kinds{ dimension_kinds }
		, _dimension_expressions{ dimension_expressions }
		, _dimension_defaults{ dimension_defaults }
		, _parent_expressions{ parent_expressions }
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
