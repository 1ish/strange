#ifndef COM_ONEISH_STRANGE_EXPRESSION_BLOCK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_BLOCK_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_block_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_block_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_substitute_t<over>::create(over{ expression_block_t<>(token, terms) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_block");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_block::create", native_function_create(&expression_block_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto thing_val = any_a<>::val(thing); // new block scope
		auto result_range = range_operator_t<>::create_(_terms, thing_val, range);
		auto it = result_range.extract_begin_();
		auto result = no();
		while (it != result_range.extract_end_())
		{
			result = *it;
			++it;
		}
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
		// (x,y,z)
		river.write_string(" (");
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
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_block::generate with non-expression term");
			}
			fast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			for (auto const& term : _terms.extract_vector())
			{
				if (!check<expression_a<>>(term))
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_block::generate_cpp with non-expression term");
				}
				fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_block::generate_cpp called for wrong type of expression");
		}
		river.write_string(" (");
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
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_block::generate_cpp with non-expression term");
			}
			fast<expression_a<>>(term).generate_cpp(version, indent, river, declare, define);
		}
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;

	inline expression_block_t(token_a<> const& token, flock_a<> const& terms)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
	{}

private:
	static bool const ___share___;
	friend class ___expression_block_t_share___;
};

template <typename ___ego___>
bool const expression_block_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_block_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_block_t_share___
{
	static inline bool ___share___()
	{
		return expression_block_t<>::___share___;
	}
};

} // namespace strange

#endif
