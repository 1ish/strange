#ifndef COM_ONEISH_STRANGE_EXPRESSION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_t : public operation_t<___ego___>
{
public:
	// exceptions
	class break_e {};

	class continue_e {};

	class return_e
	{
	public:
		any_a<> const result;

		return_e(any_a<> const& thing = no())
			: result{ thing }
		{}
	};

	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return create_expression<expression_t<___ego___>>(list);
	}
	
	template <typename _expression_>
	static inline any_a<> create_expression(list_a<> const& list)
	{
		auto it = list.begin_();
		auto end = list.end_();
		if (it == end)
		{
			throw dis("[expression] create passed empty list");
		}
		any_a<> token = *it;
		if (!check<token_a<>>(token))
		{
			throw dis("[expression] create passed non-token");
		}
		if (++it == end)
		{
			throw dis("[expression] create passed short list");
		}
		any_a<> terms = *it;
		if (!check<flock_a<>>(terms))
		{
			throw dis("[expression] create passed non-flock terms");
		}
		return _expression_::create_(fast<token_a<>>(token), fast<flock_a<>>(terms));
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return create(token);
	}

	static inline expression_a<> create(token_a<> const& token)
	{
		return expression_a<>::create<expression_t<>>(token);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression::create"), native_function_create(&expression_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>&, list_a<> const&) const
	{
		return no();
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return recreate_expression<expression_t<___ego___>>(operation_t<___ego___>::me_());
	}

	template <typename _expression_>
	static inline expression_a<> recreate_expression(expression_a<> const& expression)
	{
		std_vector<any_a<>> const& vector = expression.terms_().extract_vector();
		auto recreated_terms = flock_create();
		std_vector<any_a<>>& recreated_vector = recreated_terms.mutate_vector();
		recreated_vector.reserve(vector.size());
		for (auto const& term : vector)
		{
			if (check<expression_a<>>(term))
			{
				recreated_vector.emplace_back(fast<expression_a<>>(term).recreate_());
			}
			else
			{
				recreated_vector.emplace_back(term);
			}
		}
		return _expression_::create_(expression.token_(), recreated_terms);
	}

	inline any_a<> evaluate_() const
	{
		any_a<> null;
		return operate(null, list_a<>{});
	}

	inline any_a<> literal_() const
	{
		return boole(literal());
	}

	inline bool literal() const
	{
		return _literal;
	}

	inline token_a<> token_() const
	{
		return _token;
	}

	static inline flock_a<> terms_()
	{
		return flock_t<>::create_();
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" $$strange::no[] ");
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
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression::generate_cpp called for wrong type of expression");
		}
		river.write_string(" strange::no() ");
	}

protected:
	bool const _literal;
	token_a<> const _token;

	friend class any_a<>;

	inline expression_t(token_a<> const& token, bool pure = false, bool literal = false, flock_a<> const& names = flock_t<>::create_())
		: operation_t<___ego___>(pure, names)
		, _literal(literal)
		, _token(token)
	{}

	inline expression_t(token_a<> const& token, std_pair<bool, bool> const& pure_literal, flock_a<> const& names = flock_t<>::create_())
		: operation_t<___ego___>(pure_literal.first, names)
		, _literal(pure_literal.second)
		, _token(token)
	{}

	static inline std_pair<bool, bool> pure_literal_terms(token_a<> const& token, flock_a<> const& terms)
	{
		std_pair<bool, bool> pure_literal(true, true);
		for (auto const& term : terms.extract_vector())
		{
			if (!check<expression_a<>>(term))
			{
				continue;
			}
			auto expression = fast<expression_a<>>(term);
			if (!expression.pure())
			{
				pure_literal.first = false;
				if (!pure_literal.second)
				{
					break;
				}
			}
			if (!expression.literal())
			{
				pure_literal.second = false;
				if (!pure_literal.first)
				{
					break;
				}
			}
		}
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_t_share___;
};

template <typename ___ego___>
bool const expression_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_t_share___
{
	static inline bool ___share___()
	{
		return expression_t<>::___share___;
	}
};

} // namespace strange

#endif
