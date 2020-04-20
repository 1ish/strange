
namespace strange
{

template <typename _1>
inline any_a<> parser_a<_1>::parse__(list_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis("parser_a::parse_ passed short range");
	}
	auto tokenizer = cast<range_a<strange::any_a<>>>(*___it___);
	return parse_(tokenizer);
}

template <typename _1>
inline expression_a<> parser_a<_1>::parse_(range_a<strange::any_a<>> const& tokenizer)
{ assert(any_a<>::___handle___); return ___write___().parse_(tokenizer); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline expression_a<> parser_a<_1>::___parser_a_handle___<___TTT___, ___DHB___>::parse_(range_a<strange::any_a<>> const& tokenizer)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.parse_(tokenizer); }

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ parser_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = any_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("parse_"), native_mutation_t<parser_a>::create(&parser_a::parse__));
		return operations;
	}();
	return OPERATIONS;
}

class ___parser_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___parser_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline parser_d<_1> ___parser_dynamic___(any_a<> const& thing)
{
	return parser_d<_1>{ thing };
}

} // namespace
