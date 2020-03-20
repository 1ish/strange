
namespace strange
{

template <typename _1>
inline any_a<> parser_a<_1>::parse__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("parser_a::parse_ passed short range");
	}
	auto tokenizer = cast<range_a<>>(*___it___);
	return parse_(tokenizer);
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
