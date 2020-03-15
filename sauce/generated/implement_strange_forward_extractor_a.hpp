
namespace strange
{

template <typename _1_>
inline any_a<> forward_extractor_a<_1_>::get__(range_a<> const& ___arguments___) const
{
	return get_();
}

template <typename _1_>
inline any_a<> forward_extractor_a<_1_>::increment__(range_a<> const& ___arguments___)
{
	return increment_();
}

template <typename _1_>
bool const forward_extractor_a<_1_>::___share___ = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

class ___forward_extractor_a_share___
{
	static inline bool ___share___()
	{
		return false; // forward_extractor_a<>::___share___;
	}
};

template <typename _1_>
inline forward_extractor_d<_1_> ___forward_extractor_dynamic___(any_a<> const& thing)
{
	return forward_extractor_d<_1_>{ thing };
}

} // namespace
