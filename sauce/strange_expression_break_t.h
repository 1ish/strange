#ifndef COM_ONEISH_STRANGE_EXPRESSION_BREAK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_BREAK_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_break_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_break_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_a<>{ over{ expression_break_t<>{ token } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_break_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_break_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		throw break_i{};
	}

	// expression
	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// break()
		river.write_string(" break() ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_break::generate_cpp called for wrong type of expression");
		}
		river.write_string(" break; ");
	}

protected:
	inline expression_break_t(token_a<> const& token)
		: expression_t(token, true, true) // pure, literal
	{}

private:
	static bool const ___share___;
	friend class ___expression_break_t_share___;
};

template <typename ___ego___>
bool const expression_break_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_break_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
