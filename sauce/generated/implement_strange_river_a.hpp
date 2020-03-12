
namespace strange
{

template <typename _1_>
inline any_a<> river_a<_1_>::get__(range_a<> const& ___arguments___)
{
	return get_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::peek__(range_a<> const& ___arguments___)
{
	return peek_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::unget__(range_a<> const& ___arguments___)
{
	return unget_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::putback__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::putback_ passed short range");
	}
	auto int_8 = cast<number_data_int8_a<>>(*___it___);
	return putback_(int_8);
}

template <typename _1_>
inline any_a<> river_a<_1_>::getline__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::getline_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::getline_ passed short range");
	}
	auto delimiter = cast<number_data_int8_a<>>(*___it___);
	return getline_(count, delimiter);
}

template <typename _1_>
inline any_a<> river_a<_1_>::ignore__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::ignore_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	return ignore_(count);
}

template <typename _1_>
inline any_a<> river_a<_1_>::read__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::read_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	return read_(count);
}

template <typename _1_>
inline any_a<> river_a<_1_>::tellg__(range_a<> const& ___arguments___) const
{
	return tellg_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::seekg_beg__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekg_beg_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_beg_(offset);
}

template <typename _1_>
inline any_a<> river_a<_1_>::seekg_end__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekg_end_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_end_(offset);
}

template <typename _1_>
inline any_a<> river_a<_1_>::seekg_cur__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekg_cur_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_cur_(offset);
}

template <typename _1_>
inline any_a<> river_a<_1_>::sync__(range_a<> const& ___arguments___)
{
	return sync_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::put__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::put_ passed short range");
	}
	auto int_8 = cast<number_data_int8_a<>>(*___it___);
	return put_(int_8);
}

template <typename _1_>
inline any_a<> river_a<_1_>::write__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::write_ passed short range");
	}
	auto lake = cast<lake_int8_a<>>(*___it___);
	return write_(lake);
}

template <typename _1_>
inline any_a<> river_a<_1_>::tellp__(range_a<> const& ___arguments___) const
{
	return tellp_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::seekp_beg__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekp_beg_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_beg_(offset);
}

template <typename _1_>
inline any_a<> river_a<_1_>::seekp_end__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekp_end_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_end_(offset);
}

template <typename _1_>
inline any_a<> river_a<_1_>::seekp_cur__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekp_cur_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_cur_(offset);
}

template <typename _1_>
inline any_a<> river_a<_1_>::flush__(range_a<> const& ___arguments___)
{
	return flush_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::good__(range_a<> const& ___arguments___) const
{
	return good_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::eof__(range_a<> const& ___arguments___) const
{
	return eof_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::fail__(range_a<> const& ___arguments___) const
{
	return fail_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::bad__(range_a<> const& ___arguments___) const
{
	return bad_();
}

template <typename _1_>
inline any_a<> river_a<_1_>::set_good__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_good_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_good_(value);
}

template <typename _1_>
inline any_a<> river_a<_1_>::set_eof__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_eof_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_eof_(value);
}

template <typename _1_>
inline any_a<> river_a<_1_>::set_fail__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_fail_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_fail_(value);
}

template <typename _1_>
inline any_a<> river_a<_1_>::set_bad__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_bad_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_bad_(value);
}

template <typename _1_>
inline any_a<> river_a<_1_>::filename__(range_a<> const& ___arguments___) const
{
	return filename_();
}

template <typename _1_>
bool const river_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<river_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline river_d<_1_> ___river_dynamic___(any_a<> const& thing)
{
	return river_d<_1_>{ thing };
}

} // namespace
