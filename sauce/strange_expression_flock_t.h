#ifndef COM_ONEISH_STRANGE_EXPRESSION_FLOCK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FLOCK_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_flock_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_flock_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<expression_flock_t<>>::create(expression_flock_t<>(token, terms));
	}

	static inline expression_a<> create(token_a<> const& token)
	{
		return expression_substitute_t<expression_flock_t<>>::create(expression_flock_t<>(token, flock_t<>::create_()));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_flock");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_flock::create"), native_function_create(&expression_flock_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
		return flock_t<>::create__(range_operator_t<>::create_(_terms, thing, list));
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_flock_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, list_create());
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
		river.write_string(" [");
		bool first = true;
		for (auto const& term : _terms.extract_vector())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(__FILE__, __LINE__, expression_t<___ego___>::_token.report() + "strange::expression_flock::generate with non-expression term");
			}
			fast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string("] ");
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
					throw dis(__FILE__, __LINE__, expression_t<___ego___>::_token.report() + "strange::expression_flock::generate_cpp with non-expression term");
				}
				fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(__FILE__, __LINE__, expression_t<___ego___>::_token.report() + "strange::expression_flock::generate_cpp called for wrong type of expression");
		}
		river.write_string(" flock_t<>::create_(");
		bool first = true;
		for (auto const& term : _terms.extract_vector())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(__FILE__, __LINE__, expression_t<___ego___>::_token.report() + "strange::expression_flock::generate_cpp with non-expression term");
			}
			fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
		}
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;

	friend class any_a<>;

	inline expression_flock_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
	{}

private:
	static bool const ___share___;
	friend class ___expression_flock_t_share___;
};

template <typename ___ego___>
bool const expression_flock_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_flock_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_flock_t_share___
{
	static inline bool ___share___()
	{
		return expression_flock_t<>::___share___;
	}
};

} // namespace strange

#endif
