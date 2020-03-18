
namespace strange
{

template <typename _1>
inline any_a<> token_a<_1>::filename__(range_a<> const& ___arguments___) const
{
	return filename_();
}

template <typename _1>
inline any_a<> token_a<_1>::line__(range_a<> const& ___arguments___) const
{
	return line_();
}

template <typename _1>
inline any_a<> token_a<_1>::position__(range_a<> const& ___arguments___) const
{
	return position_();
}

template <typename _1>
inline any_a<> token_a<_1>::tag__(range_a<> const& ___arguments___) const
{
	return tag_();
}

template <typename _1>
inline any_a<> token_a<_1>::symbol__(range_a<> const& ___arguments___) const
{
	return symbol_();
}

template <typename _1>
inline any_a<> token_a<_1>::literal__(range_a<> const& ___arguments___) const
{
	return literal_();
}

template <typename _1>
inline any_a<> token_a<_1>::precedence__(range_a<> const& ___arguments___) const
{
	return precedence_();
}

template <typename _1>
inline any_a<> token_a<_1>::report__(range_a<> const& ___arguments___) const
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

template <typename _1>
inline token_d<_1> ___token_dynamic___(any_a<> const& thing)
{
	return token_d<_1>{ thing };
}

} // namespace
