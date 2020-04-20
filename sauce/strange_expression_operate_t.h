#ifndef COM_ONEISH_STRANGE_EXPRESSION_OPERATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_OPERATE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_operate_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_operate_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<expression_operate_t<>>::create(expression_operate_t<>(token, terms));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_operate");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_operate::create"), native_function_create(&expression_operate_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
		return thing_t<>::operate__(range_operator_t<>::create_(_terms, thing, list));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_operate_t<___ego___>>(expression_t<___ego___>::me_());
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
		// (thing[x,y,z])
		int64_t count = 0;
		for (auto const& term : _terms.extract_vector())
		{
			if (count == 0)
			{
				river.write_string(" (");
			}
			else if (count == 1)
			{
				river.write_string("[");
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_operate::generate with non-expression term");
			}
			fast<expression_a<>>(term).generate(version, indent, river);
			++count;
		}
		if (!count)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_operate::generate with no terms");
		}
		else if (count == 1)
		{
			river.write_string("[]) ");
		}
		else
		{
			river.write_string("]) ");
		}
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
			for (auto const& term : _terms.extract_vector())
			{
				if (!check<expression_a<>>(term))
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_operate::generate_cpp with non-expression term");
				}
				fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_operate::generate_cpp called for wrong type of expression");
		}
		int64_t count = 0;
		for (auto const& term : _terms.extract_vector())
		{
			if (count == 1)
			{
				river.write_string("(flock_t<>::create_(");
			}
			else if (count > 1)
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_operate::generate_cpp with non-expression term");
			}
			fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
			++count;
		}
		river.write_string(")) ");
	}

protected:
	flock_a<> const _terms;

	friend class any_a<>;

	inline expression_operate_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t<___ego___>(token, is_pure_literal(token, terms))
		, _terms{ terms }
	{}

	static inline std_pair<bool, bool> is_pure_literal(token_a<> const& token, flock_a<> const& terms)
	{
		std_pair<bool, bool> pure_literal(false, false); //TODO pure literal
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_operate::create passed no terms");
		}
		auto any_thing = *it;
		if (!check<expression_a<>>(any_thing))
		{
			throw dis(token.report() + "strange::expression_operate::create passed non-expression thing");
		}
		auto expression_thing = fast<expression_a<>>(any_thing);
		if (!expression_thing.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_operate::create passed too few terms");
		}
		auto any_operation = *it;
		if (!check<expression_a<>>(any_operation))
		{
			throw dis(token.report() + "strange::expression_operate::create passed non-expression operation");
		}
		auto expression_operation = fast<expression_a<>>(any_operation);
		if (!expression_operation.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_operate_t_share___;
};

template <typename ___ego___>
bool const expression_operate_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_operate_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_operate_t_share___
{
	static inline bool ___share___()
	{
		return expression_operate_t<>::___share___;
	}
};

} // namespace strange

#endif
