#ifndef COM_ONEISH_STRANGE_EXPRESSION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_t : public operation_t<_ABSTRACTION_>
{
public:
	// instructions
	class break_i : public std::runtime_error
	{
	public:
		break_i()
			: std::runtime_error("strange::expression::break escaped")
		{}
	};

	class continue_i : public std::runtime_error
	{
	public:
		continue_i()
			: std::runtime_error("strange::expression::continue escaped")
		{}
	};


	class  return_i : public std::runtime_error
	{
	public:
		any_a<> const result;

		return_i(any_a<> const& thing = no())
			: std::runtime_error("strange::expression::return escaped")
			, result{ thing }
		{}
	};

	// override
	using over = expression_o<expression_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		return val(token);
	}

	static inline expression_a<> val(token_a<> const& token)
	{
		return expression_a<>{ over{ expression_t<>{token} } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return no();
	}

	// expression
	inline token_a<> token_() const
	{
		return _token;
	}

	static inline flock_a<> terms_()
	{
		return flock_t<>::val_();
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" $$strange::no[] ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_string(" strange::no() ");
	}

protected:
	token_a<> const _token;

	inline expression_t(token_a<> const& token, bool pure = false, bool literal = false)
		: operation_t(pure, literal)
		, _token(token)
	{}

	inline expression_t(token_a<> const& token, std::pair<bool, bool> const& pure_literal)
		: operation_t(pure_literal)
		, _token(token)
	{}

	static inline bool pure_terms(token_a<> const& token, range_a<> const& terms)
	{
		for (auto const& term : terms)
		{
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression::pure_terms passed non-expression");
			}
			if (!cast<expression_a<>>(term).pure())
			{
				return false;
			}
		}
		return true;
	}

	static inline bool literal_terms(token_a<> const& token, range_a<> const& terms)
	{
		for (auto const& term : terms)
		{
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression::literal_terms passed non-expression");
			}
			if (!cast<expression_a<>>(term).literal())
			{
				return false;
			}
		}
		return true;
	}

	static inline std::pair<bool, bool> pure_literal_terms(token_a<> const& token, range_a<> const& terms)
	{
		std::pair<bool, bool> pure_literal(true, true);
		for (auto const& term : terms)
		{
			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::expression::pure_literal_terms passed non-expression");
			}
			auto expression = cast<expression_a<>>(term);
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
};

} // namespace strange

#endif
