
namespace strange
{

template <typename _1_>
inline any_a<> parser_a<_1_>::parse__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("parser_a::parse_ passed short range");
	}
	auto tokenizer = cast<range_a<>>(*___it___);
	return parse_(tokenizer);
}

template <typename _1_>
bool const parser_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<parser_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline parser_d<_1_> ___parser_dynamic___(any_a<> const& thing)
{
	return parser_d<_1_>{ thing };
}

} // namespace
