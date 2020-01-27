#ifndef COM_ONEISH_STRANGE_EXPRESSION_DO_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_DO_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_do_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_do_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_do::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_do::create passed non-symbol scope");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_do::create passed too few terms");
		}
		any_a<> loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_do::create passed non-expression loop");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_do::create not passed sufficient terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(token.report() + "strange::expression_do::create passed non-expression condition");
		}
		return expression_a<>{ over{ expression_do_t<>( token, terms, cast<expression_a<>>(loop), cast<expression_a<>>(condition)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_do_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_do_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		any_a<> local = any_a<>::val(thing); // new block scope
		any_a<> result = no();
		try
		{
			do
			{
				try
				{
					result = _loop.operate(any_a<>::val(local), range); // new scope each time round the loop
				}
				catch (continue_i&)
				{}
			} while (_condition.operate(local, range));
		}
		catch (break_i&)
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
		// do(loop, condition)
		river.write_string(" do(");
		_loop.generate(version, indent, river);
		river.write_string(", ");
		_condition.generate(version, indent, river);
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_loop.generate_cpp(version, indent, river, declare, define);
			_condition.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_do::generate_cpp called for wrong type of expression");
		}
		river.write_string(" do(");
		_loop.generate_cpp(version, indent, river, declare, define);
		river.write_string(")\n{");
		_condition.generate_cpp(version, indent, river, declare, define);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _loop;
	expression_a<> const _condition;

	inline expression_do_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& loop, expression_a<> const& condition)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _loop{ loop }
		, _condition{ condition }
	{}

private:
	static bool const ___share___;
	friend class ___expression_do_t_share___;
};

template <typename ___ego___>
bool const expression_do_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_do_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
