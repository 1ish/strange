
namespace strange
{

template <typename _1_>
inline any_a<> symbol_a<_1_>::to_lake__(range_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename _1_>
inline any_a<> symbol_a<_1_>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("symbol_a::add_ passed short range");
	}
	auto symbol = cast<symbol_a<>>(*___it___);
	return add_(symbol);
}

template <typename _1_>
inline symbol_d<_1_> ___symbol_dynamic___(any_a<> const& thing)
{
	return symbol_d<_1_>{ thing };
}

} // namespace
