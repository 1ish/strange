#ifndef COM_ONEISH_STRANGE_EXPRESSION_CONTINUE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_CONTINUE_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_continue_t : public expression_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		return expression_a<>{ expression_continue_t<>{ token } };
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
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		throw continue_i{};
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_(lake_from_string(" continue "));
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_(lake_from_string(" continue; "));
	}

protected:
	inline expression_continue_t(token_a<> const& token)
		: expression_t{ token }
	{}
};

} // namespace strange

#endif
