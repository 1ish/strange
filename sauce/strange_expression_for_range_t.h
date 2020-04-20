#ifndef COM_ONEISH_STRANGE_EXPRESSION_FOR_RANGE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FOR_RANGE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_for_range_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_for_range_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_for_range::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-symbol scope");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_for_range::create passed too few terms");
		}
		any_a<> term = *it;
		if (!check<expression_a<>>(term))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-expression term");
		}
		if (!term.type_().is("strange::expression_local_insert"))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed invalid parameter term");
		}
		auto const subterms = fast<expression_a<>>(term).terms_();
		if (subterms.size() != 3)
		{
			throw dis(token.report() + "strange::expression_for_range::create passed invalid parameter term");
		}
		auto const name = subterms.at_index(0);
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-symbol parameter name");
		}
		auto const kind = subterms.at_index(1);
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-kind/expression parameter kind");
		}
		auto const range = subterms.at_index(2);
		if (!check<expression_a<>>(range))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-expression parameter default");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_for_range::create not passed sufficient terms");
		}
		auto const loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-expression loop");
		}
		return expression_a<>::create<expression_for_range_t<>>(token, terms, fast<symbol_a<>>(name), kind, fast<expression_a<>>(range), fast<expression_a<>>(loop));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_for_range");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_for_range::create"), native_function_create(&expression_for_range_t<>::create__));
		shoal.update(sym("for_range!"), native_function_create(&expression_for_range_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_for_range::operate passed non-unordered-shoal local");
		}
#endif
		auto local_shoal = fast<unordered_shoal_a<>>(thing); // new block scope
		auto& local = local_shoal.mutate_map();
		auto kind = _kind;
		if (check<expression_a<>>(kind))
		{
			try
			{
				kind = fast<expression_a<>>(kind).operate(local_shoal, list);
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_for_range::operate kind expression evaluation error") + misunderstanding;
			}
		}
		if (!check<kind_a<>>(kind))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_for_range::operate non-kind parameter kind");
		}
		auto it = local.emplace(_name, no()).first;
		any_a<> result = no();
		auto const for_range = _range.operate(local_shoal, list);
		if (!check<list_a<>>(for_range))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_for_range::operate expression returned non-range");
		}
		auto read_lock = check<collection_a<>>(for_range) ? fast<collection_a<>>(for_range).read_lock_() : no();
		try
		{
			for (auto const& for_thing : fast<list_a<> const>(for_range))
			{
				if (!for_thing.kinds_().has_(kind))
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_for_range::operate kind does not include value");
				}
				it->second = for_thing;
				try
				{
					auto thing = any_a<>::val(local_shoal); // new scope each time round the loop
					result = _loop.operate(thing, list);
				}
				catch (typename expression_t<___ego___>::continue_i&)
				{}
			}
		}
		catch (typename expression_t<___ego___>::break_i&)
		{}
		return result;
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_for_range_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, range_create());
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

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// for_range(x,y)
		river.write_string(" for_range(" + _name.to_string() + " ");
		if (check<kind_a<>>(_kind))
		{
			river.write_string(fast<kind_a<>>(_kind).to_string());
		}
		else if (check<expression_a<>>(_kind))
		{
			fast<expression_a<>>(_kind).generate(version, indent, river);
		}
		_range.generate(version, indent, river);
		river.write_string(", ");
		_loop.generate(version, indent, river);
		river.write_string(")\n");
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_range.generate_cpp(version, indent, river, declare, define);
			_loop.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_for_range::generate_cpp called for wrong type of expression");
		}
		//river.write_string(" for(" + _kind.code() + " const& " + _name.to_string() + " : ");
		_range.generate_cpp(version, indent, river, declare, define);
		river.write_string(")\n{\n");
		_loop.generate_cpp(version, indent, river, declare, define);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _name;
	any_a<> const _kind;
	expression_a<> const _range;
	expression_a<> const _loop;

	friend class any_a<>;

	inline expression_for_range_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, any_a<> const& kind, expression_a<> const& range, expression_a<> const& loop)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms)) //TODO pure literal
		, _terms{ terms }
		, _name{ name }
		, _kind{ kind }
		, _range{ range }
		, _loop{ loop }
	{}

private:
	static bool const ___share___;
	friend class ___expression_for_range_t_share___;
};

template <typename ___ego___>
bool const expression_for_range_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_for_range_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_for_range_t_share___
{
	static inline bool ___share___()
	{
		return expression_for_range_t<>::___share___;
	}
};

} // namespace strange

#endif
