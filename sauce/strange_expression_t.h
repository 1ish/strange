#ifndef COM_ONEISH_STRANGE_EXPRESSION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_t : public operation_t<___ego___>
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

	class return_i : public std::runtime_error
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
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return create(token);
	}

	static inline expression_a<> create(token_a<> const& token)
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
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		return no();
	}

	// expression
	inline void recreated(expression_a<> const& expression) const
	{}

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

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" $$strange::no[] ");
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

	inline expression_t(token_a<> const& token, bool pure = false, bool literal = false, flock_a<> const& names = flock_t<>::create_())
		: operation_t(pure, names)
		, _literal(literal)
		, _token(token)
	{}

	inline expression_t(token_a<> const& token, std::pair<bool, bool> const& pure_literal, flock_a<> const& names = flock_t<>::create_())
		: operation_t(pure_literal.first, names)
		, _literal(pure_literal.second)
		, _token(token)
	{}

	static inline std::pair<bool, bool> pure_literal_terms(token_a<> const& token, flock_a<> const& terms)
	{
		std::pair<bool, bool> pure_literal(true, true);
		for (auto const& term : terms.extract_vector())
		{
			if (!check<expression_a<>>(term))
			{
				continue;
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

private:
	static bool const ___share___;
	friend class ___expression_t_share___;
};

template <typename ___ego___>
bool const expression_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
