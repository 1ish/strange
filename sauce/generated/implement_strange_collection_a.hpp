
namespace strange
{

template <typename _1_>
inline any_a<> collection_a<_1_>::has__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::has_ passed short range");
	}
	auto key = cast<any_a<>>(*___it___);
	return has_(key);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::at__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::at_ passed short range");
	}
	auto key = cast<any_a<>>(*___it___);
	return at_(key);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::update__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::update_ passed short range");
	}
	auto key = cast<any_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		return update_(key);
	}
	auto value = cast<any_a<>>(*___it___);
	return update_(key, value);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::insert__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::insert_ passed short range");
	}
	auto key = cast<any_a<>>(*___it___);
	if (++___it___ == ___arguments___.extract_end_())
	{
		return insert_(key);
	}
	auto value = cast<any_a<>>(*___it___);
	return insert_(key, value);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::erase__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::erase_ passed short range");
	}
	auto key = cast<any_a<>>(*___it___);
	return erase_(key);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::clear__(range_a<> const& ___arguments___)
{
	return clear_();
}

template <typename _1_>
inline any_a<> collection_a<_1_>::size__(range_a<> const& ___arguments___) const
{
	return size_();
}

template <typename _1_>
inline any_a<> collection_a<_1_>::empty__(range_a<> const& ___arguments___) const
{
	return empty_();
}

template <typename _1_>
inline any_a<> collection_a<_1_>::push_front__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::push_front_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return push_front_(thing);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::pop_front__(range_a<> const& ___arguments___)
{
	return pop_front_();
}

template <typename _1_>
inline any_a<> collection_a<_1_>::push_back__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::push_back_ passed short range");
	}
	auto thing = cast<any_a<>>(*___it___);
	return push_back_(thing);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::pop_back__(range_a<> const& ___arguments___)
{
	return pop_back_();
}

template <typename _1_>
inline any_a<> collection_a<_1_>::self_assign__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::self_assign_ passed short range");
	}
	auto range = cast<range_a<>>(*___it___);
	return self_assign_(range);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::self_add__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::self_add_ passed short range");
	}
	auto range = cast<range_a<>>(*___it___);
	return self_add_(range);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::add__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::add_ passed short range");
	}
	auto range = cast<range_a<>>(*___it___);
	return add_(range);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::self_subtract__(range_a<> const& ___arguments___)
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::self_subtract_ passed short range");
	}
	auto range = cast<range_a<>>(*___it___);
	return self_subtract_(range);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::subtract__(range_a<> const& ___arguments___) const
{
	forward_extractor_a<> ___it___ = ___arguments___.extract_begin_();
	if (___it___ == ___arguments___.extract_end_())
	{
		throw dis("collection_a::subtract_ passed short range");
	}
	auto range = cast<range_a<>>(*___it___);
	return subtract_(range);
}

template <typename _1_>
inline any_a<> collection_a<_1_>::read_lock__(range_a<> const& ___arguments___) const
{
	return read_lock_();
}

template <typename _1_>
inline any_a<> collection_a<_1_>::write_lock__(range_a<> const& ___arguments___) const
{
	return write_lock_();
}

template <typename _1_>
bool const collection_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	reflection<collection_a<_1_>>::share(shared_shoal);
	return shared_shoal;
}();

template <typename _1_>
inline collection_d<_1_> ___collection_dynamic___(any_a<> const& thing)
{
	return collection_d<_1_>{ thing };
}

} // namespace
