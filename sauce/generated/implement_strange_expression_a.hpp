
namespace strange
{

template <typename _1_>
inline any_a<> expression_a<_1_>::recreate__(range_a<> const& ___arguments___) const
{
	return recreate_();
}

template <typename _1_>
inline any_a<> expression_a<_1_>::literal__(range_a<> const& ___arguments___) const
{
	return literal_();
}

template <typename _1_>
inline any_a<> expression_a<_1_>::evaluate__(range_a<> const& ___arguments___) const
{
	return evaluate_();
}

template <typename _1_>
inline any_a<> expression_a<_1_>::token__(range_a<> const& ___arguments___) const
{
	return token_();
}

template <typename _1_>
inline any_a<> expression_a<_1_>::terms__(range_a<> const& ___arguments___) const
{
	return terms_();
}

template <typename _1_>
inline any_a<> expression_a<_1_>::generate__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_ passed short range");
	}
	auto version = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_ passed short range");
	}
	auto indent = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_ passed short range");
	}
	auto river = cast_dup<river_a<>>(*___it___);
	return generate_(version, indent, river);
}

template <typename _1_>
inline any_a<> expression_a<_1_>::generate_cpp__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto version = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto indent = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto river = cast_dup<river_a<>>(*___it___);
	if (++___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto declare = cast<any_a<>>(*___it___);
	if (++___it___ == ___arguments___.cend_())
	{
		throw dis("expression_a::generate_cpp_ passed short range");
	}
	auto define = cast<any_a<>>(*___it___);
	if (++___it___ == ___arguments___.cend_())
	{
		return generate_cpp_(version, indent, river, declare, define);
	}
	auto type = cast<any_a<>>(*___it___);
	return generate_cpp_(version, indent, river, declare, define, type);
}

template <typename _1_>
bool const expression_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<expression_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline expression_d<_1_> ___expression_dynamic___(any_a<> const& thing)
{
	return expression_d<_1_>{ thing };
}

} // namespace
