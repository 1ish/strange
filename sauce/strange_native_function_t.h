#ifndef COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H
#define COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H

namespace strange
{

// template <typename ___ego___ = operation_a<>>
template <typename ___ego___>
class native_function_t : public operation_t<___ego___>
{
public:
	// construction
	template <typename... Args>
	static inline operation_a<> create(native_function_pointer const fun, Args&&... args)
	{
		std_vector<any_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<>::variadic(v, std::forward<Args>(args)...);
		return operation_a<>::create<native_function_t<>>(fun,
			operation_t<___ego___>::kind_names_params(flock_create(std::move(v))));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_function");
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
	inline any_a<> operate(any_a<>&, list_a<> const& list) const
	{
		return _function(list);
	}

protected:
	native_function_pointer const _function;
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;

	friend class any_a<>;

	inline native_function_t(native_function_pointer const fun, std_pair<kind_a<>, flock_a<>> const& kind_names)
		: operation_t<___ego___>{ false, kind_names.second } //TODO pure
		, _function{ fun }
		, _kind{ kind_names.first }
		, _kinds{ operation_t<___ego___>::kinds(_kind) }
		, _cat{ kind_to_cat(_kind) }
		, _cats{ operation_t<___ego___>::cats(_cat) }
	{}
};

template <typename... Args>
inline operation_a<> native_function_create(native_function_pointer const fun, Args&&... args)
{
	return native_function_t<>::create(fun, std::forward<Args>(args)...);
}

} // namespace strange

#endif
