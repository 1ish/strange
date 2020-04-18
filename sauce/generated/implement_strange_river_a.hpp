
namespace strange
{

template <typename _1>
inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > river_a<_1>::extract_begin() const
{ assert(any_a<>::___handle___); return ___read___().extract_begin(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::extract_begin() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_begin(); }

template <typename _1>
inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > river_a<_1>::extract_end() const
{ assert(any_a<>::___handle___); return ___read___().extract_end(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline forward_extractor_data_a < any_a < > , std :: istreambuf_iterator < char > > river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::extract_end() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.extract_end(); }

template <typename _1>
inline any_a<> river_a<_1>::to_lake__(range_a<> const& ___arguments___)
{
	return to_lake_();
}

template <typename _1>
inline lake_int8_a<> river_a<_1>::to_lake_()
{ assert(any_a<>::___handle___); return ___write___().to_lake_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::to_lake_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake_(); }

template <typename _1>
inline std_string river_a<_1>::to_string()
{ assert(any_a<>::___handle___); return ___write___().to_string(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std_string river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::to_string()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

template <typename _1>
inline any_a<> river_a<_1>::get_char__(range_a<> const& ___arguments___)
{
	return get_char_();
}

template <typename _1>
inline number_data_int8_a<> river_a<_1>::get_char_()
{ assert(any_a<>::___handle___); return ___write___().get_char_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int8_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::get_char_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_char_(); }

template <typename _1>
inline int8_t river_a<_1>::get_char()
{ assert(any_a<>::___handle___); return ___write___().get_char(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int8_t river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::get_char()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_char(); }

template <typename _1>
inline any_a<> river_a<_1>::peek_char__(range_a<> const& ___arguments___)
{
	return peek_char_();
}

template <typename _1>
inline number_data_int8_a<> river_a<_1>::peek_char_()
{ assert(any_a<>::___handle___); return ___write___().peek_char_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int8_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::peek_char_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.peek_char_(); }

template <typename _1>
inline int8_t river_a<_1>::peek_char()
{ assert(any_a<>::___handle___); return ___write___().peek_char(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int8_t river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::peek_char()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.peek_char(); }

template <typename _1>
inline any_a<> river_a<_1>::unget_char__(range_a<> const& ___arguments___)
{
	return unget_char_();
}

template <typename _1>
inline river_a<> river_a<_1>::unget_char_()
{ assert(any_a<>::___handle___); return ___write___().unget_char_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::unget_char_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unget_char_(); }

template <typename _1>
inline void river_a<_1>::unget_char()
{ assert(any_a<>::___handle___); ___write___().unget_char(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::unget_char()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.unget_char(); }

template <typename _1>
inline any_a<> river_a<_1>::put_back_char__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::put_back_char_ passed short range");
	}
	auto int_8 = cast<number_data_int8_a<>>(*___it___);
	return put_back_char_(int_8);
}

template <typename _1>
inline river_a<> river_a<_1>::put_back_char_(number_data_int8_a<> const& int_8)
{ assert(any_a<>::___handle___); return ___write___().put_back_char_(int_8); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::put_back_char_(number_data_int8_a<> const& int_8)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.put_back_char_(int_8); }

template <typename _1>
inline void river_a<_1>::put_back_char(int8_t int_8 )
{ assert(any_a<>::___handle___); ___write___().put_back_char(int_8); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::put_back_char(int8_t int_8 )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.put_back_char(int_8); }

template <typename _1>
inline any_a<> river_a<_1>::get_line__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::get_line_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	if (++___it___ == ___end___)
	{
		throw dis("river_a::get_line_ passed short range");
	}
	auto delimiter = cast<number_data_int8_a<>>(*___it___);
	return get_line_(count, delimiter);
}

template <typename _1>
inline lake_int8_a<> river_a<_1>::get_line_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter)
{ assert(any_a<>::___handle___); return ___write___().get_line_(count, delimiter); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::get_line_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_line_(count, delimiter); }

template <typename _1>
inline std :: vector < int8_t > river_a<_1>::get_line(int64_t count , int8_t delimiter )
{ assert(any_a<>::___handle___); return ___write___().get_line(count, delimiter); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: vector < int8_t > river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::get_line(int64_t count , int8_t delimiter )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.get_line(count, delimiter); }

template <typename _1>
inline any_a<> river_a<_1>::ignore__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::ignore_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	return ignore_(count);
}

template <typename _1>
inline river_a<> river_a<_1>::ignore_(number_data_int64_a<> const& count)
{ assert(any_a<>::___handle___); return ___write___().ignore_(count); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::ignore_(number_data_int64_a<> const& count)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.ignore_(count); }

template <typename _1>
inline void river_a<_1>::ignore(int64_t count )
{ assert(any_a<>::___handle___); ___write___().ignore(count); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::ignore(int64_t count )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.ignore(count); }

template <typename _1>
inline any_a<> river_a<_1>::read__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::read_ passed short range");
	}
	auto count = cast<number_data_int64_a<>>(*___it___);
	return read_(count);
}

template <typename _1>
inline lake_int8_a<> river_a<_1>::read_(number_data_int64_a<> const& count)
{ assert(any_a<>::___handle___); return ___write___().read_(count); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::read_(number_data_int64_a<> const& count)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.read_(count); }

template <typename _1>
inline std :: vector < int8_t > river_a<_1>::read(int64_t count )
{ assert(any_a<>::___handle___); return ___write___().read(count); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std :: vector < int8_t > river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::read(int64_t count )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.read(count); }

template <typename _1>
inline std_string river_a<_1>::read_string(int64_t count )
{ assert(any_a<>::___handle___); return ___write___().read_string(count); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std_string river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::read_string(int64_t count )
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.read_string(count); }

template <typename _1>
inline any_a<> river_a<_1>::tellg__(range_a<> const& ___arguments___) const
{
	return tellg_();
}

template <typename _1>
inline number_data_int64_a<> river_a<_1>::tellg_() const
{ assert(any_a<>::___handle___); return ___read___().tellg_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::tellg_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.tellg_(); }

template <typename _1>
inline int64_t river_a<_1>::tellg() const
{ assert(any_a<>::___handle___); return ___read___().tellg(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int64_t river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::tellg() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.tellg(); }

template <typename _1>
inline any_a<> river_a<_1>::seekg_beg__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::seekg_beg_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_beg_(offset);
}

template <typename _1>
inline river_a<> river_a<_1>::seekg_beg_(number_data_int64_a<> const& offset)
{ assert(any_a<>::___handle___); return ___write___().seekg_beg_(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekg_beg_(number_data_int64_a<> const& offset)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_beg_(offset); }

template <typename _1>
inline void river_a<_1>::seekg_beg(int64_t offset )
{ assert(any_a<>::___handle___); ___write___().seekg_beg(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekg_beg(int64_t offset )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_beg(offset); }

template <typename _1>
inline any_a<> river_a<_1>::seekg_end__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::seekg_end_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_end_(offset);
}

template <typename _1>
inline river_a<> river_a<_1>::seekg_end_(number_data_int64_a<> const& offset)
{ assert(any_a<>::___handle___); return ___write___().seekg_end_(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekg_end_(number_data_int64_a<> const& offset)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_end_(offset); }

template <typename _1>
inline void river_a<_1>::seekg_end(int64_t offset )
{ assert(any_a<>::___handle___); ___write___().seekg_end(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekg_end(int64_t offset )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_end(offset); }

template <typename _1>
inline any_a<> river_a<_1>::seekg_cur__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::seekg_cur_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekg_cur_(offset);
}

template <typename _1>
inline river_a<> river_a<_1>::seekg_cur_(number_data_int64_a<> const& offset)
{ assert(any_a<>::___handle___); return ___write___().seekg_cur_(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekg_cur_(number_data_int64_a<> const& offset)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_cur_(offset); }

template <typename _1>
inline void river_a<_1>::seekg_cur(int64_t offset )
{ assert(any_a<>::___handle___); ___write___().seekg_cur(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekg_cur(int64_t offset )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekg_cur(offset); }

template <typename _1>
inline any_a<> river_a<_1>::sync__(range_a<> const& ___arguments___)
{
	return sync_();
}

template <typename _1>
inline any_a<> river_a<_1>::sync_()
{ assert(any_a<>::___handle___); return ___write___().sync_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::sync_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.sync_(); }

template <typename _1>
inline bool river_a<_1>::sync()
{ assert(any_a<>::___handle___); return ___write___().sync(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::sync()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.sync(); }

template <typename _1>
inline any_a<> river_a<_1>::put_char__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::put_char_ passed short range");
	}
	auto int_8 = cast<number_data_int8_a<>>(*___it___);
	return put_char_(int_8);
}

template <typename _1>
inline river_a<> river_a<_1>::put_char_(number_data_int8_a<> const& int_8)
{ assert(any_a<>::___handle___); return ___write___().put_char_(int_8); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::put_char_(number_data_int8_a<> const& int_8)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.put_char_(int_8); }

template <typename _1>
inline void river_a<_1>::put_char(int8_t int_8 )
{ assert(any_a<>::___handle___); ___write___().put_char(int_8); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::put_char(int8_t int_8 )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.put_char(int_8); }

template <typename _1>
inline any_a<> river_a<_1>::write__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::write_ passed short range");
	}
	auto lake = cast<lake_int8_a<>>(*___it___);
	return write_(lake);
}

template <typename _1>
inline river_a<> river_a<_1>::write_(lake_int8_a<> const& lake)
{ assert(any_a<>::___handle___); return ___write___().write_(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::write_(lake_int8_a<> const& lake)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.write_(lake); }

template <typename _1>
inline void river_a<_1>::write(std :: vector < int8_t > const & lake )
{ assert(any_a<>::___handle___); ___write___().write(lake); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::write(std :: vector < int8_t > const & lake )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.write(lake); }

template <typename _1>
inline void river_a<_1>::write_string(std_string const & str )
{ assert(any_a<>::___handle___); ___write___().write_string(str); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::write_string(std_string const & str )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.write_string(str); }

template <typename _1>
inline any_a<> river_a<_1>::tellp__(range_a<> const& ___arguments___) const
{
	return tellp_();
}

template <typename _1>
inline number_data_int64_a<> river_a<_1>::tellp_() const
{ assert(any_a<>::___handle___); return ___read___().tellp_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline number_data_int64_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::tellp_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.tellp_(); }

template <typename _1>
inline int64_t river_a<_1>::tellp() const
{ assert(any_a<>::___handle___); return ___read___().tellp(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline int64_t river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::tellp() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.tellp(); }

template <typename _1>
inline any_a<> river_a<_1>::seekp_beg__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::seekp_beg_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_beg_(offset);
}

template <typename _1>
inline river_a<> river_a<_1>::seekp_beg_(number_data_int64_a<> const& offset)
{ assert(any_a<>::___handle___); return ___write___().seekp_beg_(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekp_beg_(number_data_int64_a<> const& offset)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_beg_(offset); }

template <typename _1>
inline void river_a<_1>::seekp_beg(int64_t offset )
{ assert(any_a<>::___handle___); ___write___().seekp_beg(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekp_beg(int64_t offset )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_beg(offset); }

template <typename _1>
inline any_a<> river_a<_1>::seekp_end__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::seekp_end_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_end_(offset);
}

template <typename _1>
inline river_a<> river_a<_1>::seekp_end_(number_data_int64_a<> const& offset)
{ assert(any_a<>::___handle___); return ___write___().seekp_end_(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekp_end_(number_data_int64_a<> const& offset)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_end_(offset); }

template <typename _1>
inline void river_a<_1>::seekp_end(int64_t offset )
{ assert(any_a<>::___handle___); ___write___().seekp_end(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekp_end(int64_t offset )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_end(offset); }

template <typename _1>
inline any_a<> river_a<_1>::seekp_cur__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::seekp_cur_ passed short range");
	}
	auto offset = cast<number_data_int64_a<>>(*___it___);
	return seekp_cur_(offset);
}

template <typename _1>
inline river_a<> river_a<_1>::seekp_cur_(number_data_int64_a<> const& offset)
{ assert(any_a<>::___handle___); return ___write___().seekp_cur_(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekp_cur_(number_data_int64_a<> const& offset)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_cur_(offset); }

template <typename _1>
inline void river_a<_1>::seekp_cur(int64_t offset )
{ assert(any_a<>::___handle___); ___write___().seekp_cur(offset); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::seekp_cur(int64_t offset )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.seekp_cur(offset); }

template <typename _1>
inline any_a<> river_a<_1>::flush__(range_a<> const& ___arguments___)
{
	return flush_();
}

template <typename _1>
inline river_a<> river_a<_1>::flush_()
{ assert(any_a<>::___handle___); return ___write___().flush_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::flush_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.flush_(); }

template <typename _1>
inline void river_a<_1>::flush()
{ assert(any_a<>::___handle___); ___write___().flush(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::flush()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.flush(); }

template <typename _1>
inline any_a<> river_a<_1>::good__(range_a<> const& ___arguments___) const
{
	return good_();
}

template <typename _1>
inline any_a<> river_a<_1>::good_() const
{ assert(any_a<>::___handle___); return ___read___().good_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::good_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.good_(); }

template <typename _1>
inline bool river_a<_1>::good() const
{ assert(any_a<>::___handle___); return ___read___().good(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::good() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.good(); }

template <typename _1>
inline any_a<> river_a<_1>::eof__(range_a<> const& ___arguments___) const
{
	return eof_();
}

template <typename _1>
inline any_a<> river_a<_1>::eof_() const
{ assert(any_a<>::___handle___); return ___read___().eof_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::eof_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.eof_(); }

template <typename _1>
inline bool river_a<_1>::eof() const
{ assert(any_a<>::___handle___); return ___read___().eof(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::eof() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.eof(); }

template <typename _1>
inline any_a<> river_a<_1>::fail__(range_a<> const& ___arguments___) const
{
	return fail_();
}

template <typename _1>
inline any_a<> river_a<_1>::fail_() const
{ assert(any_a<>::___handle___); return ___read___().fail_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::fail_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.fail_(); }

template <typename _1>
inline bool river_a<_1>::fail() const
{ assert(any_a<>::___handle___); return ___read___().fail(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::fail() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.fail(); }

template <typename _1>
inline any_a<> river_a<_1>::bad__(range_a<> const& ___arguments___) const
{
	return bad_();
}

template <typename _1>
inline any_a<> river_a<_1>::bad_() const
{ assert(any_a<>::___handle___); return ___read___().bad_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::bad_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.bad_(); }

template <typename _1>
inline bool river_a<_1>::bad() const
{ assert(any_a<>::___handle___); return ___read___().bad(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::bad() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.bad(); }

template <typename _1>
inline any_a<> river_a<_1>::set_good__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::set_good_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_good_(value);
}

template <typename _1>
inline river_a<> river_a<_1>::set_good_(any_a<> const& value)
{ assert(any_a<>::___handle___); return ___write___().set_good_(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_good_(any_a<> const& value)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_good_(value); }

template <typename _1>
inline void river_a<_1>::set_good(bool value )
{ assert(any_a<>::___handle___); ___write___().set_good(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_good(bool value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_good(value); }

template <typename _1>
inline any_a<> river_a<_1>::set_eof__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::set_eof_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_eof_(value);
}

template <typename _1>
inline river_a<> river_a<_1>::set_eof_(any_a<> const& value)
{ assert(any_a<>::___handle___); return ___write___().set_eof_(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_eof_(any_a<> const& value)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_eof_(value); }

template <typename _1>
inline void river_a<_1>::set_eof(bool value )
{ assert(any_a<>::___handle___); ___write___().set_eof(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_eof(bool value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_eof(value); }

template <typename _1>
inline any_a<> river_a<_1>::set_fail__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::set_fail_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_fail_(value);
}

template <typename _1>
inline river_a<> river_a<_1>::set_fail_(any_a<> const& value)
{ assert(any_a<>::___handle___); return ___write___().set_fail_(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_fail_(any_a<> const& value)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_fail_(value); }

template <typename _1>
inline void river_a<_1>::set_fail(bool value )
{ assert(any_a<>::___handle___); ___write___().set_fail(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_fail(bool value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_fail(value); }

template <typename _1>
inline any_a<> river_a<_1>::set_bad__(range_a<> const& ___arguments___)
{
	auto ___it___ = ___arguments___.extract_begin_();
	auto ___end___ = ___arguments___.extract_end_();
	if (___it___ == ___end___)
	{
		throw dis("river_a::set_bad_ passed short range");
	}
	auto value = cast<any_a<>>(*___it___);
	return set_bad_(value);
}

template <typename _1>
inline river_a<> river_a<_1>::set_bad_(any_a<> const& value)
{ assert(any_a<>::___handle___); return ___write___().set_bad_(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline river_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_bad_(any_a<> const& value)
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_bad_(value); }

template <typename _1>
inline void river_a<_1>::set_bad(bool value )
{ assert(any_a<>::___handle___); ___write___().set_bad(value); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::set_bad(bool value )
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.set_bad(value); }

template <typename _1>
inline any_a<> river_a<_1>::filename__(range_a<> const& ___arguments___) const
{
	return filename_();
}

template <typename _1>
inline lake_int8_a<> river_a<_1>::filename_() const
{ assert(any_a<>::___handle___); return ___read___().filename_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline lake_int8_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::filename_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.filename_(); }

template <typename _1>
inline std_string river_a<_1>::filename() const
{ assert(any_a<>::___handle___); return ___read___().filename(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline std_string river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::filename() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.filename(); }

template <typename _1>
inline any_a<> river_a<_1>::close__(range_a<> const& ___arguments___)
{
	return close_();
}

template <typename _1>
inline any_a<> river_a<_1>::close_()
{ assert(any_a<>::___handle___); return ___write___().close_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::close_()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.close_(); }

template <typename _1>
inline void river_a<_1>::close()
{ assert(any_a<>::___handle___); ___write___().close(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline void river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::close()
{ any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.close(); }

template <typename _1>
inline any_a<> river_a<_1>::closed__(range_a<> const& ___arguments___) const
{
	return closed_();
}

template <typename _1>
inline any_a<> river_a<_1>::closed_() const
{ assert(any_a<>::___handle___); return ___read___().closed_(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline any_a<> river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::closed_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.closed_(); }

template <typename _1>
inline bool river_a<_1>::closed()
{ assert(any_a<>::___handle___); return ___write___().closed(); }

template <typename _1>
template <typename ___TTT___, typename ___DHB___>
inline bool river_a<_1>::___river_a_handle___<___TTT___, ___DHB___>::closed()
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.closed(); }

template <typename _1>
template <typename ___unordered_shoal_a___>
inline ___unordered_shoal_a___ river_a<_1>::___operations___()
{
	static ___unordered_shoal_a___ OPERATIONS = []()
	{
		___unordered_shoal_a___ operations = range_a<>::template ___operations___<___unordered_shoal_a___>();
		operations.update(sym("to_lake_"), native_mutation_t<river_a>::create(&river_a::to_lake__));
		operations.update(sym("get_char_"), native_mutation_t<river_a>::create(&river_a::get_char__));
		operations.update(sym("peek_char_"), native_mutation_t<river_a>::create(&river_a::peek_char__));
		operations.update(sym("unget_char_"), native_mutation_t<river_a>::create(&river_a::unget_char__));
		operations.update(sym("put_back_char_"), native_mutation_t<river_a>::create(&river_a::put_back_char__));
		operations.update(sym("get_line_"), native_mutation_t<river_a>::create(&river_a::get_line__));
		operations.update(sym("ignore_"), native_mutation_t<river_a>::create(&river_a::ignore__));
		operations.update(sym("read_"), native_mutation_t<river_a>::create(&river_a::read__));
		operations.update(sym("tellg_"), native_extraction_t<river_a>::create(&river_a::tellg__));
		operations.update(sym("seekg_beg_"), native_mutation_t<river_a>::create(&river_a::seekg_beg__));
		operations.update(sym("seekg_end_"), native_mutation_t<river_a>::create(&river_a::seekg_end__));
		operations.update(sym("seekg_cur_"), native_mutation_t<river_a>::create(&river_a::seekg_cur__));
		operations.update(sym("sync_"), native_mutation_t<river_a>::create(&river_a::sync__));
		operations.update(sym("put_char_"), native_mutation_t<river_a>::create(&river_a::put_char__));
		operations.update(sym("write_"), native_mutation_t<river_a>::create(&river_a::write__));
		operations.update(sym("tellp_"), native_extraction_t<river_a>::create(&river_a::tellp__));
		operations.update(sym("seekp_beg_"), native_mutation_t<river_a>::create(&river_a::seekp_beg__));
		operations.update(sym("seekp_end_"), native_mutation_t<river_a>::create(&river_a::seekp_end__));
		operations.update(sym("seekp_cur_"), native_mutation_t<river_a>::create(&river_a::seekp_cur__));
		operations.update(sym("flush_"), native_mutation_t<river_a>::create(&river_a::flush__));
		operations.update(sym("good_"), native_extraction_t<river_a>::create(&river_a::good__));
		operations.update(sym("eof_"), native_extraction_t<river_a>::create(&river_a::eof__));
		operations.update(sym("fail_"), native_extraction_t<river_a>::create(&river_a::fail__));
		operations.update(sym("bad_"), native_extraction_t<river_a>::create(&river_a::bad__));
		operations.update(sym("set_good_"), native_mutation_t<river_a>::create(&river_a::set_good__));
		operations.update(sym("set_eof_"), native_mutation_t<river_a>::create(&river_a::set_eof__));
		operations.update(sym("set_fail_"), native_mutation_t<river_a>::create(&river_a::set_fail__));
		operations.update(sym("set_bad_"), native_mutation_t<river_a>::create(&river_a::set_bad__));
		operations.update(sym("filename_"), native_extraction_t<river_a>::create(&river_a::filename__));
		operations.update(sym("close_"), native_mutation_t<river_a>::create(&river_a::close__));
		operations.update(sym("closed_"), native_extraction_t<river_a>::create(&river_a::closed__));
		return operations;
	}();
	return OPERATIONS;
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
