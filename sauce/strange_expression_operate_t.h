#ifndef COM_ONEISH_STRANGE_EXPRESSION_OPERATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_OPERATE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_operate_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_operate_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<over>::create(over{ expression_operate_t<>(token, terms) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_operate_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_operate_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		return thing_t<>::operate__(range_operator_t<>::create_(_terms, thing, range));
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
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
				throw dis(_token.report() + "strange::expression_operate::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(version, indent, river);
			++count;
		}
		if (!count)
		{
			throw dis(_token.report() + "strange::expression_operate::generate with no terms");
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

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_operate::generate_cpp called for wrong type of expression");
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
				throw dis(_token.report() + "strange::expression_operate::generate_cpp with non-expression term");
			}
			cast<expression_a<>>(term).generate_cpp(version, indent, river);
			++count;
		}
		river.write_string(")) ");
	}

protected:
	flock_a<> const _terms;

	inline expression_operate_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t(token, is_pure_literal(token, terms))
		, _terms{ terms }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, flock_a<> const& terms)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate::create passed no terms");
		}
		auto any_thing = *it;
		if (!check<expression_a<>>(any_thing))
		{
			throw dis(token.report() + "strange::expression_operate::create passed non-expression thing");
		}
		auto expression_thing = cast<expression_a<>>(any_thing);
		if (!expression_thing.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_operate::create passed too few terms");
		}
		auto any_operation = *it;
		if (!check<expression_a<>>(any_operation))
		{
			throw dis(token.report() + "strange::expression_operate::create passed non-expression operation");
		}
		auto expression_operation = cast<expression_a<>>(any_operation);
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
	return shoal.something();
}();

} // namespace strange

#endif
