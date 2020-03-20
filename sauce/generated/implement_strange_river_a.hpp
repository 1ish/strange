
namespace strange
{

template <typename _1>
inline any_a<> river_a<_1>::to_lake__(range_a<> const& ___arguments___)
{
	return to_lake_();
}

template <typename _1>
inline any_a<> river_a<_1>::get_char__(range_a<> const& ___arguments___)
{
	return get_char_();
}

template <typename _1>
inline any_a<> river_a<_1>::peek_char__(range_a<> const& ___arguments___)
{
	return peek_char_();
}

template <typename _1>
inline any_a<> river_a<_1>::unget_char__(range_a<> const& ___arguments___)
{
	return unget_char_();
}

template <typename _1>
inline any_a<> river_a<_1>::put_back_char__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::put_back_char_ passed short range");
	}
	auto int_8 = cast<number_data_int8_a<>>(*___it___);
	return put_back_char_(int_8);
}

template <typename _1>
inline any_a<> river_a<_1>::get_line__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::get_line_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::get_line_ passed short range");
	}
	auto delimiter = cast<number_data_int8_a<>>(*___it___);
	return get_line_(count, delimiter);
}

template <typename _1>
inline any_a<> river_a<_1>::ignore__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::ignore_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	return ignore_(count);
}

template <typename _1>
inline any_a<> river_a<_1>::read__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::read_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	return read_(count);
}

template <typename _1>
inline any_a<> river_a<_1>::tellg__(range_a<> const& ___arguments___) const
{
	return tellg_();
}

template <typename _1>
inline any_a<> river_a<_1>::seekg_beg__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekg_beg_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_beg_(offset);
}

template <typename _1>
inline any_a<> river_a<_1>::seekg_end__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekg_end_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_end_(offset);
}

template <typename _1>
inline any_a<> river_a<_1>::seekg_cur__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekg_cur_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_cur_(offset);
}

template <typename _1>
inline any_a<> river_a<_1>::sync__(range_a<> const& ___arguments___)
{
	return sync_();
}

template <typename _1>
inline any_a<> river_a<_1>::put_char__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::put_char_ passed short range");
	}
	auto int_8 = cast<number_data_int8_a<>>(*___it___);
	return put_char_(int_8);
}

template <typename _1>
inline any_a<> river_a<_1>::write__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::write_ passed short range");
	}
	auto lake = cast<lake_int8_a<>>(*___it___);
	return write_(lake);
}

template <typename _1>
inline any_a<> river_a<_1>::tellp__(range_a<> const& ___arguments___) const
{
	return tellp_();
}

template <typename _1>
inline any_a<> river_a<_1>::seekp_beg__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekp_beg_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_beg_(offset);
}

template <typename _1>
inline any_a<> river_a<_1>::seekp_end__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekp_end_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_end_(offset);
}

template <typename _1>
inline any_a<> river_a<_1>::seekp_cur__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::seekp_cur_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_cur_(offset);
}

template <typename _1>
inline any_a<> river_a<_1>::flush__(range_a<> const& ___arguments___)
{
	return flush_();
}

template <typename _1>
inline any_a<> river_a<_1>::good__(range_a<> const& ___arguments___) const
{
	return good_();
}

template <typename _1>
inline any_a<> river_a<_1>::eof__(range_a<> const& ___arguments___) const
{
	return eof_();
}

template <typename _1>
inline any_a<> river_a<_1>::fail__(range_a<> const& ___arguments___) const
{
	return fail_();
}

template <typename _1>
inline any_a<> river_a<_1>::bad__(range_a<> const& ___arguments___) const
{
	return bad_();
}

template <typename _1>
inline any_a<> river_a<_1>::set_good__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_good_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_good_(value);
}

template <typename _1>
inline any_a<> river_a<_1>::set_eof__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_eof_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_eof_(value);
}

template <typename _1>
inline any_a<> river_a<_1>::set_fail__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_fail_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_fail_(value);
}

template <typename _1>
inline any_a<> river_a<_1>::set_bad__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("river_a::set_bad_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_bad_(value);
}

template <typename _1>
inline any_a<> river_a<_1>::filename__(range_a<> const& ___arguments___) const
{
	return filename_();
}

class ___river_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___river_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline river_d<_1> ___river_dynamic___(any_a<> const& thing)
{
	return river_d<_1>{ thing };
}

} // namespace
