
namespace strange
{

template <typename _1>
inline any_a<> bidirectional_mutator_a<_1>::decrement__(range_a<> const& ___arguments___)
{
	return decrement_();
}

class ___bidirectional_mutator_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___bidirectional_mutator_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _1>
inline bidirectional_mutator_d<_1> ___bidirectional_mutator_dynamic___(any_a<> const& thing)
{
	return bidirectional_mutator_d<_1>{ thing };
}

} // namespace
