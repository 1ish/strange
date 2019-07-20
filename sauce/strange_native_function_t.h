#ifndef COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H
#define COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = operation_a<>>
class native_function_t : public operation_t<_ABSTRACTION_>
{
	using function = any_a<>(*)(range_a<> const&);

public:
	// override
	using over = thing_o<native_function_t<>>;

	// construction
	template <typename... Args>
	static inline operation_a<> val(function const fun, Args&&... args)
	{
		std::vector<any_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<>::variadic(v, std::forward<Args>(args)...);
		return operation_a<>{ over{ native_function_t<>(fun,
			interface_eater_params(sym(""), flock_t<>::val(std::move(v)))) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_function");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

	inline any_a<> eater_() const
	{
		return _eater;
	}

	// function
	inline any_a<> operate_(any_a<>& _, range_a<> const& range) const
	{
		return _function(range);
	}

	// operation
	inline any_a<> interface__(range_a<> const&) const
	{
		return interface_();
	}

	inline cat_a<> interface_() const
	{
		return _interface;
	}

protected:
	function const _function;
	cat_a<> const _interface;
	flock_a<> const _eater;

	inline native_function_t(function const fun, std::pair<cat_a<>, flock_a<>> const& interface_eater)
		: operation_t{}
		, _function{ fun }
		, _interface{ interface_eater.first }
		, _eater{ interface_eater.second }
	{}
};

} // namespace strange

#endif
