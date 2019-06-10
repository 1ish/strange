#ifndef COM_ONEISH_STRANGE_EXPRESSION_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_T_H

namespace strange
{

// adaptation
#define ___STRANGE_EXPRESSION___ ___STRANGE_THING___ \
static inline any_a<> val__(range_a<> const& range) \
{ \
	forward_const_iterator_a<> it = range.cbegin_(); \
	if (it == range.cend_()) \
	{ \
		throw dis("[expression] val passed empty range"); \
	} \
	any_a<> token = *it; \
	if (!check<token_a<>>(token)) \
	{ \
		throw dis("[expression] val passed non-token"); \
	} \
	return val_(cast<token_a<>>(token), range_t<>::val_(++it, range.cend_())); \
} \
inline any_a<> generate__(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin_(); \
	if (it == range.cend_()) \
	{ \
		throw dis("[expression]::generate passed empty range"); \
	} \
	any_a<> indent = *it; \
	if (!check<number_data_a<int64_t>>(indent)) \
	{ \
		throw dis("[expression]::generate passed non-int-64 indent"); \
	} \
	if (++it == range.cend_()) \
	{ \
		throw dis("[expression]::generate passed short range"); \
	} \
	any_a<> river = *it; \
	if (!check<river_a<>>(river)) \
	{ \
		throw dis("[expression]::generate passed non-river"); \
	} \
	return generate_(cast<number_data_a<int64_t>>(indent), cast<river_a<>>(river, true)); \
} \
inline any_a<> generate_(number_data_a<int64_t> const& indent, river_a<>& river) const \
{ \
	generate(indent.extract(), river); \
	return river; \
} \
inline any_a<> generate_cpp__(range_a<> const& range) const \
{ \
	forward_const_iterator_a<> it = range.cbegin_(); \
	if (it == range.cend_()) \
	{ \
		throw dis("[expression]::generate_cpp passed empty range"); \
	} \
	any_a<> indent = *it; \
	if (!check<number_data_a<int64_t>>(indent)) \
	{ \
		throw dis("[expression]::generate_cpp passed non-int-64 indent"); \
	} \
	if (++it == range.cend_()) \
	{ \
		throw dis("[expression]::generate_cpp passed short range"); \
	} \
	any_a<> river = *it; \
	if (!check<river_a<>>(river)) \
	{ \
		throw dis("[expression]::generate_cpp passed non-river"); \
	} \
	return generate_cpp_(cast<number_data_a<int64_t>>(indent), cast<river_a<>>(river, true)); \
} \
inline any_a<> generate_cpp_(number_data_a<int64_t> const& indent, river_a<>& river) const \
{ \
	generate_cpp(indent.extract(), river); \
	return river; \
} \

template <typename _ABSTRACTION_ = expression_a<>>
class expression_t : public operation_t<_ABSTRACTION_>
{
public: ___STRANGE_EXPRESSION___
	// instructions
	class break_i : public std::runtime_error
	{
	public:
		break_i()
			: std::runtime_error("strange::expression::break escaped")
		{}
	};

	class continue_i : public std::runtime_error
	{
	public:
		continue_i()
			: std::runtime_error("strange::expression::continue escaped")
		{}
	};


	class  return_i : public std::runtime_error
	{
	public:
		any_a<> const result;

		return_i(any_a<> const& thing = no())
			: std::runtime_error("strange::expression::return escaped")
			, result{ thing }
		{}
	};

	// construction
	static inline expression_a<> val_(token_a<> const& token, range_a<> const& terms)
	{
		return val(token);
	}

	static inline expression_a<> val(token_a<> const& token)
	{
		return expression_a<>{ expression_t<>{token} };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return no();
	}

	// expression
	inline void generate(int64_t indent, river_a<>& river) const
	{
		river.write_(lake_from_string(" $$strange::no[] "));
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		river.write_(lake_from_string(" strange::no() "));
	}

protected:
	token_a<> const _token;

	inline expression_t(token_a<> const& token)
		: operation_t{}
		, _token(token)
	{}
};

} // namespace strange

#endif
