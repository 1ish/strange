#ifndef COM_ONEISH_STRANGE_NATIVE_MUTATION_T_H
#define COM_ONEISH_STRANGE_NATIVE_MUTATION_T_H

namespace strange
{

// template <typename _abstraction_, typename ___ego___ = operation_a<>>
template <typename _abstraction_, typename ___ego___>
class native_mutation_t : public operation_t<___ego___>
{
public:
	// construction
	template <typename... Args>
	static inline operation_a<> create(native_mutation::member_ptr<_abstraction_> const ptr, Args&&... args)
	{
		std_vector<any_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<>::variadic(v, std::forward<Args>(args)...);
		return operation_a<>::create<native_mutation_t<_abstraction_>>(ptr,
			operation_t<___ego___>::kind_names_params(flock::create(std::move(v))));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_mutation");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	inline cat_a<> cat_() const
	{
		return _cat;
	}

	inline unordered_herd_a<> cats_() const
	{
		return _cats;
	}

	inline kind_a<> kind_() const
	{
		return _kind;
	}

	inline unordered_herd_a<> kinds_() const
	{
		return _kinds;
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
		assert(check<_abstraction_>(thing));
		return (static_cast<_abstraction_&>(thing).*_function)(list);
	}

protected:
	native_mutation::member_ptr<_abstraction_> const _function;
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;

	friend class any_a<>;

	inline native_mutation_t(native_mutation::member_ptr<_abstraction_> const ptr, std_pair<kind_a<>, flock_a<>> const& kind_names)
		: operation_t<___ego___>{ false, kind_names.second } //TODO pure
		, _function{ ptr }
		, _kind{ kind_names.first }
		, _kinds{ operation_t<___ego___>::kinds(_kind) }
		, _cat{ kind::to_cat(_kind) }
		, _cats{ operation_t<___ego___>::cats(_cat) }
	{}
};

namespace native_mutation
{
	template <typename _abstraction_, typename... Args>
	inline operation_a<> create(member_ptr<_abstraction_> const ptr, Args&&... args)
	{
		return native_mutation_t<_abstraction_>::create(ptr, std::forward<Args>(args)...);
	}
}

} // namespace strange

#endif
