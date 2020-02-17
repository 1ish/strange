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
		return expression_a<>{ over{ expression_continue_t<>{ token } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_continue_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_continue_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		throw expression_t<___ego___>::continue_i{};
	}

	// expression
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

} // namespace strange

#endif
