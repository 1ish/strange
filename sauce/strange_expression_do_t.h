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
		forward_extractor_a<> it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_do::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(token.report() + "strange::expression_do::create passed non-symbol scope");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_do::create passed too few terms");
		}
		any_a<> loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_do::create passed non-expression loop");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_do::create not passed sufficient terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(token.report() + "strange::expression_do::create passed non-expression condition");
		}
		return expression_a<>::create<over>(expression_do_t<>( token, terms, fast<expression_a<>>(loop), fast<expression_a<>>(condition)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_do");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_do::create", native_function_t<>::create(&expression_do_t<>::over::create__));
		shoal.update_string("do!", native_function_t<>::create(&expression_do_t<>::over::create__));
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
					auto thing = any_a<>::val(local); // new scope each time round the loop
					result = _loop.operate(thing, range);
				}
				catch (typename expression_t<___ego___>::continue_i&)
				{}
			} while (_condition.operate(local, range));
		}
		catch (typename expression_t<___ego___>::break_i&)
		{}
		return result;
	}

	// expression
	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<true>());
		return operate(local, range_create());
	}

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
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_do::generate_cpp called for wrong type of expression");
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
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
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
	return shoal;
}();

class ___expression_do_t_share___
{
	static inline bool ___share___()
	{
		return expression_do_t<>::___share___;
	}
};

} // namespace strange

#endif
