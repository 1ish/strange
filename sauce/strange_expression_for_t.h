#ifndef COM_ONEISH_STRANGE_EXPRESSION_FOR_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FOR_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_for_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_for_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for::create not passed any terms");
		}
		any_a<> initialize = *it;
		if (!check<expression_a<>>(initialize))
		{
			throw dis(token.report() + "strange::expression_for::create passed non-expression initialize");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for::create not passed sufficient terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(token.report() + "strange::expression_for::create passed non-expression condition");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for::create not passed sufficient terms");
		}
		any_a<> next = *it;
		if (!check<expression_a<>>(next))
		{
			throw dis(token.report() + "strange::expression_for::create passed non-expression next");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for::create not passed sufficient terms");
		}
		any_a<> loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_for::create passed non-expression loop");
		}
		return expression_a<>{ over{ expression_for_t<>( token, terms, cast<expression_a<>>(initialize), cast<expression_a<>>(condition), cast<expression_a<>>(next), cast<expression_a<>>(loop)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_for_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_for_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		any_a<> local = any_a<>::val(thing); // new block scope
		any_a<> result = no();
		try
		{
			for (_initialize.operate(local, range); _condition.operate(local, range); _next.operate(local, range))
			{
				try
				{
					result = _loop.operate(any_a<>::val(local), range); // new scope each time round the loop
				}
				catch (continue_i&)
				{}
			}
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
		river.write_string(" for_(");
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
				throw dis(_token.report() + "strange::expression_for::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool def, bool type = false) const
	{
		if (def)
		{
			_initialize.generate_cpp(version, indent, river, def);
			_condition.generate_cpp(version, indent, river, def);
			_next.generate_cpp(version, indent, river, def);
			_loop.generate_cpp(version, indent, river, def);
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_for::generate_cpp called for wrong type of expression");
		}
		river.write_string(" for(");
		_initialize.generate_cpp(version, indent, river, def);
		river.write_string(";");
		_condition.generate_cpp(version, indent, river, def);
		river.write_string(";");
		_next.generate_cpp(version, indent, river, def);
		river.write_string(")\n{");
		_loop.generate_cpp(version, indent, river, def);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _initialize;
	expression_a<> const _condition;
	expression_a<> const _next;
	expression_a<> const _loop;

	inline expression_for_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& initialize, expression_a<> const& condition, expression_a<> const& next, expression_a<> const& loop)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _initialize{ initialize }
		, _condition{ condition }
		, _next{ next }
		, _loop{ loop }
	{}

private:
	static bool const ___share___;
	friend class ___expression_for_t_share___;
};

template <typename ___ego___>
bool const expression_for_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_for_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
