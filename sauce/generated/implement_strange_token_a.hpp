
namespace strange
{

template <typename _1_>
inline any_a<> token_a<_1_>::filename__(range_a<> const& ___arguments___) const
{
	return filename_();
}

template <typename _1_>
inline any_a<> token_a<_1_>::line__(range_a<> const& ___arguments___) const
{
	return line_();
}

template <typename _1_>
inline any_a<> token_a<_1_>::position__(range_a<> const& ___arguments___) const
{
	return position_();
}

template <typename _1_>
inline any_a<> token_a<_1_>::tag__(range_a<> const& ___arguments___) const
{
	return tag_();
}

template <typename _1_>
inline any_a<> token_a<_1_>::symbol__(range_a<> const& ___arguments___) const
{
	return symbol_();
}

template <typename _1_>
inline any_a<> token_a<_1_>::literal__(range_a<> const& ___arguments___) const
{
	return literal_();
}

template <typename _1_>
inline any_a<> token_a<_1_>::precedence__(range_a<> const& ___arguments___) const
{
	return precedence_();
}

template <typename _1_>
inline any_a<> token_a<_1_>::report__(range_a<> const& ___arguments___) const
{
	return report_();
}

class ___token_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___token_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1_>
inline token_d<_1_> ___token_dynamic___(any_a<> const& thing)
{
	return token_d<_1_>{ thing };
}

} // namespace
