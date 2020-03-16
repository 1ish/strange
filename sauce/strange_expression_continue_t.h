#ifndef COM_ONEISH_STRANGE_EXPRESSION_CONTINUE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CONTINUE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_continue_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_continue_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_a<>::create<over>(expression_continue_t<>{ token });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_continue");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_continue::create", native_function_create(&expression_continue_t<>::over::create__));
		shoal.update_string("continue!", native_function_create(&expression_continue_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		throw typename expression_t<___ego___>::continue_i{};
	}

	// expression
	inline any_a<> evaluate_() const
	{
		any_a<> null;
		return operate(null, range_a<>{});
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// continue()
		river.write_string(" continue() ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_continue::generate_cpp called for wrong type of expression");
		}
		river.write_string(" continue; ");
	}

protected:
	inline expression_continue_t(token_a<> const& token)
		: expression_t<___ego___>(token, true, true) // pure, literal
	{}

private:
	static bool const ___share___;
	friend class ___expression_continue_t_share___;
};

template <typename ___ego___>
bool const expression_continue_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_continue_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_continue_t_share___
{
	static inline bool ___share___()
	{
		return expression_continue_t<>::___share___;
	}
};

} // namespace strange

#endif
