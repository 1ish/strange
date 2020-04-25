
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
inline cat_a<> parser_a<_1>::___cat___()
{
	static cat_a<> CAT = cat_create<cat_a<>>(1, "strange::parser");
	return CAT;
}

template <typename _1>
inline unordered_herd_a<> parser_a<_1>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = any_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _1>
inline kind_a<> parser_a<_1>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _1>
inline unordered_herd_a<> parser_a<_1>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = any_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _1>
inline unordered_shoal_a<> parser_a<_1>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = any_a<>::___operations___();
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
