
namespace strange
{

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::type__(range_a<> const& ___arguments___) const
{
	return type_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::cat__(range_a<> const& ___arguments___) const
{
	return cat_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::cats__(range_a<> const& ___arguments___) const
{
	return cats_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::kind__(range_a<> const& ___arguments___) const
{
	return kind_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::kinds__(range_a<> const& ___arguments___) const
{
	return kinds_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::operations__(range_a<> const& ___arguments___) const
{
	return operations_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::visit__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::visit_ passed short range");
	}
	auto arguments = cast_dup<inventory_a<>>(*___it___);
	return visit_(arguments);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::identity__(range_a<> const& ___arguments___) const
{
	return identity_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::identical__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::identical_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return identical_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::nothing__(range_a<> const& ___arguments___) const
{
	return nothing_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::something__(range_a<> const& ___arguments___) const
{
	return something_();
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::same__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::same_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return same_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::different__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::different_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return different_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::less_than__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::less_than_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return less_than_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::greater_than__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::greater_than_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return greater_than_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::less_or_equal__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::less_or_equal_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return less_or_equal_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::greater_or_equal__(range_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("any_a::greater_or_equal_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return greater_or_equal_(thing);
}

template <typename _symbol, typename _cat, typename _kind, typename _unordered_herd, typename _unordered_shoal, typename _number_data_uint64>
inline any_a<> any_a<_symbol, _cat, _kind, _unordered_herd, _unordered_shoal, _number_data_uint64>::hash__(range_a<> const& ___arguments___) const
{
	return hash_();
}

class ___any_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___any_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

} // namespace
