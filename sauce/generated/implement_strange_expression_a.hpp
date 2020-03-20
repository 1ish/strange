
namespace strange
{

template <typename _1>
inline any_a<> expression_a<_1>::recreate__(range_a<> const& ___arguments___) const
{
	return recreate_();
}

template <typename _1>
inline any_a<> expression_a<_1>::literal__(range_a<> const& ___arguments___) const
{
	return literal_();
}

template <typename _1>
inline any_a<> expression_a<_1>::evaluate__(range_a<> const& ___arguments___) const
{
	return evaluate_();
}

template <typename _1>
inline any_a<> expression_a<_1>::token__(range_a<> const& ___arguments___) const
{
	return token_();
}

template <typename _1>
inline any_a<> expression_a<_1>::terms__(range_a<> const& ___arguments___) const
{
	return terms_();
}

template <typename _1>
inline any_a<> expression_a<_1>::generate__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_ passed short range");
	}
	auto version = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_ passed short range");
	}
	auto indent = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_ passed short range");
	}
	auto river = cast_dup<river_a<>>(*___it___);
	return generate_(version, indent, river);
}

template <typename _1>
inline any_a<> expression_a<_1>::generate_cpp__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto version = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto indent = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto river = cast_dup<river_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto declare = cast<any_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto define = cast<any_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		return generate_cpp_(version, indent, river, declare, define);
	}
	auto type = cast<any_a<>>(*___it___);
	return generate_cpp_(version, indent, river, declare, define, type);
}

class ___expression_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___expression_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline expression_d<_1> ___expression_dynamic___(any_a<> const& thing)
{
	return expression_d<_1>{ thing };
}

} // namespace
