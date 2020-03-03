#ifndef COM_ONEISH_STRANGE_EXPRESSION_PIPE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_PIPE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_pipe_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_pipe_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_pipe::create not passed any terms");
		}
		any_a<> left = *it;
		if (!check<expression_a<>>(left))
		{
			throw dis(token.report() + "strange::expression_pipe::create passed non-expression left-hand term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_pipe::create not passed sufficient terms");
		}
		any_a<> right = *it;
		if (!check<expression_a<>>(right))
		{
			throw dis(token.report() + "strange::expression_pipe::create passed non-expression right-hand term");
		}
		return expression_a<>::create<over>(expression_pipe_t<>( token, terms, cast<expression_a<>>(left), cast<expression_a<>>(right)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_pipe");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_pipe::create", native_function_create(&expression_pipe_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const left = _left.operate(thing, range);
		return left | _right.operate(thing, range);
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// (left && right)
		river.write_string(" (");
		_left.generate(version, indent, river);
		river.write_string(" | ");
		_right.generate(version, indent, river);
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			_left.generate_cpp(version, indent, river, declare, define);
			_right.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_pipe::generate_cpp called for wrong type of expression");
		}
		river.write_string(" (");
		_left.generate_cpp(version, indent, river, declare, define);
		river.write_string(" | ");
		_right.generate_cpp(version, indent, river, declare, define);
		river.write_string(") ");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _left;
	expression_a<> const _right;

	inline expression_pipe_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& left, expression_a<> const& right)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _left{ left }
		, _right{ right }
	{}

private:
	static bool const ___share___;
	friend class ___expression_pipe_t_share___;
};

template <typename ___ego___>
bool const expression_pipe_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_pipe_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_pipe_t_share___
{
	static inline bool ___share___()
	{
		return expression_pipe_t<>::___share___;
	}
};

} // namespace strange

#endif
