
namespace strange
{

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::type__(range const& ___arguments___) const
{
	return type_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::shared__(range const& ___arguments___) const
{
	return shared_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::cat__(range const& ___arguments___) const
{
	return cat_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::cats__(range const& ___arguments___) const
{
	return cats_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::kind__(range const& ___arguments___) const
{
	return kind_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::kinds__(range const& ___arguments___) const
{
	return kinds_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::operations__(range const& ___arguments___) const
{
	return operations_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::visit__(range const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("any_a::visit_ passed short range");
	}
	auto arguments = cast_dup< inventory>(*___it___);
	return visit_(arguments);
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::identity__(range const& ___arguments___) const
{
	return identity_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::identical__(range const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("any_a::identical_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return identical_(thing);
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::nothing__(range const& ___arguments___) const
{
	return nothing_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::something__(range const& ___arguments___) const
{
	return something_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::same__(range const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("any_a::same_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return same_(thing);
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::different__(range const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.cbegin_();
	if (___it___ == ___arguments___.cend_())
	{
		throw dis("any_a::different_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return different_(thing);
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
inline any_a<> any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::hash__(range const& ___arguments___) const
{
	return hash_();
}

template <typename range, typename symbol, typename cat, typename kind, typename inventory, typename unordered_herd, typename shoal, typename unordered_shoal, typename number_data_uint64>
bool const any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<any_a<range, symbol, cat, kind, inventory, unordered_herd, shoal, unordered_shoal, number_data_uint64>>::share(shared_shoal);
	return shared_shoal;
}();

} // namespace
