
namespace strange
{

template <typename _lake_int8>
inline any_a<> misunderstanding_a<_lake_int8>::to_lake__(list_a<> const& ___arguments___) const
{
	return to_lake_();
}

template <typename _lake_int8>
inline _lake_int8 misunderstanding_a<_lake_int8>::to_lake_() const
{ assert(any_a<>::___handle___); return ___read___().to_lake_(); }

template <typename _lake_int8>
template <typename ___TTT___, typename ___DHB___>
inline _lake_int8 misunderstanding_a<_lake_int8>::___misunderstanding_a_handle___<___TTT___, ___DHB___>::to_lake_() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_lake_(); }

template <typename _lake_int8>
inline std_string misunderstanding_a<_lake_int8>::to_string() const
{ assert(any_a<>::___handle___); return ___read___().to_string(); }

template <typename _lake_int8>
template <typename ___TTT___, typename ___DHB___>
inline std_string misunderstanding_a<_lake_int8>::___misunderstanding_a_handle___<___TTT___, ___DHB___>::to_string() const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.to_string(); }

template <typename _lake_int8>
inline any_a<> misunderstanding_a<_lake_int8>::add__(list_a<> const& ___arguments___) const
{
	auto ___it___ = ___arguments___.begin_();
	auto ___end___ = ___arguments___.end_();
	if (___it___ == ___end___)
	{
		throw dis(__FILE__, __LINE__, "misunderstanding_a::add_ passed short range");
	}
	auto misunderstanding = cast<misunderstanding_a<>>(*___it___);
	return add_(misunderstanding);
}

template <typename _lake_int8>
inline misunderstanding_a<> misunderstanding_a<_lake_int8>::add_(misunderstanding_a<> const& misunderstanding) const
{ assert(any_a<>::___handle___); return ___read___().add_(misunderstanding); }

template <typename _lake_int8>
inline misunderstanding_a<> misunderstanding_a<_lake_int8>::operator+(misunderstanding_a<> const& misunderstanding) const
{ assert(any_a<>::___handle___); return ___read___().add_(misunderstanding); }

template <typename _lake_int8>
template <typename ___TTT___, typename ___DHB___>
inline misunderstanding_a<> misunderstanding_a<_lake_int8>::___misunderstanding_a_handle___<___TTT___, ___DHB___>::add_(misunderstanding_a<> const& misunderstanding) const
{ return any_a<>::___any_a_handle___<___TTT___, ___DHB___>::___value___.add_(misunderstanding); }

template <typename _lake_int8>
inline cat_a<> misunderstanding_a<_lake_int8>::___cat___()
{
	static cat_a<> CAT = cat_create(1, "strange::misunderstanding");
	return CAT;
}

template <typename _lake_int8>
inline unordered_herd_a<> misunderstanding_a<_lake_int8>::___cats___()
{
	static unordered_herd_a<> CATS = []()
	{
		auto cats = any_a<>::___cats___();
		cats.update_thing(___cat___());
		return cats;
	}();
	return CATS;
}

template <typename _lake_int8>
inline kind_a<> misunderstanding_a<_lake_int8>::___kind___()
{
	static kind_a<> KIND = kind_from_cat(___cat___());
	return KIND;
}

template <typename _lake_int8>
inline unordered_herd_a<> misunderstanding_a<_lake_int8>::___kinds___()
{
	static unordered_herd_a<> KINDS = []()
	{
		auto kinds = any_a<>::___kinds___();
		kinds.update_thing(___cat___());
		return kinds;
	}();
	return KINDS;
}

template <typename _lake_int8>
inline unordered_shoal_a<> misunderstanding_a<_lake_int8>::___operations___()
{
	static unordered_shoal_a<> OPERATIONS = []()
	{
		unordered_shoal_a<> operations = any_a<>::___operations___();
		operations.update(sym("to_lake_"), native_extraction::create(&misunderstanding_a::to_lake__));
		operations.update(sym("add_"), native_extraction::create(&misunderstanding_a::add__));
		return operations;
	}();
	return OPERATIONS;
}

class ___misunderstanding_a_share___
{
	static bool const share;
	static inline bool initialize() { return share; }
};

bool const ___misunderstanding_a_share___::share = []()
{
	auto& shared_shoal = shared();
	// register abstraction
	return shared_shoal;
}();

template <typename _lake_int8>
inline misunderstanding_d<_lake_int8> ___misunderstanding_dynamic___(any_a<> const& thing)
{
	return misunderstanding_d<_lake_int8>{ thing };
}

} // namespace
