#ifndef COM_ONEISH_STRANGE_EXPRESSION_BREAK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_BREAK_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_break_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_break_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
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
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		throw break_i{};
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_string(" break() ");
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
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

template <typename _ABSTRACTION_>
bool const expression_break_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_break_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
