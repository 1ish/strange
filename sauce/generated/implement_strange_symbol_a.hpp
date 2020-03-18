
namespace strange
{

template <typename _1>
inline any_a<> symbol_a<_1>::to_lake__(range_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename _1>
inline any_a<> symbol_a<_1>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("symbol_a::add_ passed short range");
	}
	auto symbol = cast<symbol_a<>>(*___it___);
	return add_(symbol);
}

class ___symbol_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___symbol_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline symbol_d<_1> ___symbol_dynamic___(any_a<> const& thing)
{
	return symbol_d<_1>{ thing };
}

} // namespace
