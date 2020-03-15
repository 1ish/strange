
namespace strange
{

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::increment__(range_a<> const& ___arguments___)
{
	return increment_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::decrement__(range_a<> const& ___arguments___)
{
	return decrement_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::self_assign__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::self_assign_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_assign_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::self_add__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::self_add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_add_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::add_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return add_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::self_subtract__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::self_subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_subtract_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::subtract__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::subtract_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return subtract_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::self_multiply__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::self_multiply_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_multiply_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::multiply__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::multiply_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return multiply_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::self_divide__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::self_divide_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_divide_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::divide__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::divide_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return divide_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::self_modulo__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::self_modulo_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return self_modulo_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::modulo__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::modulo_ passed short range");
	}
	auto number = cast<number_a<>>(*___it___);
	return modulo_(number);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::to_int_64__(range_a<> const& ___arguments___) const
{
	return to_int_64_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::from_int_64__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::from_int_64_ passed short range");
	}
	auto int_64 = cast< number_data_int64>(*___it___);
	return from_int_64_(int_64);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::to_uint_64__(range_a<> const& ___arguments___) const
{
	return to_uint_64_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::from_uint_64__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::from_uint_64_ passed short range");
	}
	auto uint_64 = cast< number_data_uint64>(*___it___);
	return from_uint_64_(uint_64);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::to_float_64__(range_a<> const& ___arguments___) const
{
	return to_float_64_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::from_float_64__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("number_a::from_float_64_ passed short range");
	}
	auto float_64 = cast< number_data_double>(*___it___);
	return from_float_64_(float_64);
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::byte_size__(range_a<> const& ___arguments___) const
{
	return byte_size_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::is_int__(range_a<> const& ___arguments___) const
{
	return is_int_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::is_signed__(range_a<> const& ___arguments___) const
{
	return is_signed_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::is_nan__(range_a<> const& ___arguments___) const
{
	return is_nan_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::is_inf__(range_a<> const& ___arguments___) const
{
	return is_inf_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::is_finite__(range_a<> const& ___arguments___) const
{
	return is_finite_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::is_normal__(range_a<> const& ___arguments___) const
{
	return is_normal_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline any_a<> number_a<number_data_int64, number_data_uint64, number_data_double>::little_endian__(range_a<> const& ___arguments___) const
{
	return little_endian_();
}

template <typename number_data_int64, typename number_data_uint64, typename number_data_double>
inline number_d<number_data_int64, number_data_uint64, number_data_double> ___number_dynamic___(any_a<> const& thing)
{
	return number_d<number_data_int64, number_data_uint64, number_data_double>{ thing };
}

} // namespace
