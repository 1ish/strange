#ifndef COM_ONEISH_STRANGE_EXPRESSION_WHILE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_WHILE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_while_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_while_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_while::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_while::create passed non-symbol scope");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_while::create passed too few terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(token.report() + "strange::expression_while::create passed non-expression condition");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_while::create not passed sufficient terms");
		}
		any_a<> loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_while::create passed non-expression loop");
		}
		return expression_a<>{ over{ expression_while_t<>( token, terms, cast<expression_a<>>(condition), cast<expression_a<>>(loop)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_while_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_while_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		any_a<> local = any_a<>::val(thing); // new block scope
		any_a<> result = no();
		try
		{
			while (_condition.operate(local, range))
			{
				try
				{
					auto thing = any_a<>::val(local); // new scope each time round the loop
					result = _loop.operate(thing, range);
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
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// while(condition, loop)
		river.write_string(" while(");
		_condition.generate(version, indent, river);
		river.write_string(", ");
		_loop.generate(version, indent, river);
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_condition.generate_cpp(version, indent, river, declare, define);
			_loop.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_while::generate_cpp called for wrong type of expression");
		}
		river.write_string(" while(");
		_condition.generate_cpp(version, indent, river, declare, define);
		river.write_string(")\n{");
		_loop.generate_cpp(version, indent, river, declare, define);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _condition;
	expression_a<> const _loop;

	inline expression_while_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& condition, expression_a<> const& loop)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _condition{ condition }
		, _loop{ loop }
	{}

private:
	static bool const ___share___;
	friend class ___expression_while_t_share___;
};

template <typename ___ego___>
bool const expression_while_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_while_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
