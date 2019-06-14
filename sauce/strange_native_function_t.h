#ifndef COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H
#define COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = operation_a<>>
class native_function_t : public operation_t<_ABSTRACTION_>
{
	using function = any_a<>(*)(range_a<> const&);

public: ___STRANGE_THING___
	// construction
	template <typename... Args>
	static inline operation_a<> val(function const fun, Args&&... args)
	{
		std::vector<any_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<>::variadic(v, std::forward<Args>(args)...);
		return operation_a<>{ native_function_t(fun, flock_t<>::val(std::move(v))) };
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
		return _params;
	}

	// function
	inline any_a<> operate_(any_a<>& _, range_a<> const& range) const
	{
		return _function(range);
	}

protected:
	function const _function;
	flock_a<> const _params;

	inline native_function_t(function const fun, flock_a<> const& params)
		: operation_t{}
		, _function{ fun }
		, _params{ params }
	{}
};

} // namespace strange

#endif
