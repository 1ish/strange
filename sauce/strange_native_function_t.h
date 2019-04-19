#ifndef COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H
#define COM_ONEISH_STRANGE_NATIVE_FUNCTION_T_H

namespace strange
{

template <typename CAT_ = any_a>
class native_function_t : public thing_t<CAT_>
{
	using function = any_a(*)(any_a);

public: ___THING___
	// construction
	static inline any_a val(any_a _)
	{
		assert(false); //TODO
		return nothing_t<>::val_();
	}

	template <typename... Args>
	static inline any_a val__(const function fun, Args&&... args)
	{
		std::vector<symbol_a> v;
		v.reserve(sizeof...(Args));
		variadic_u<symbol_a>::variadic_(v, std::forward<Args>(args)...);
		return any_a{ native_function_t(fun, std::move(v)) };
	}

	static inline any_a ref(any_a _)
	{
		assert(false); //TODO
		return nothing_t<>::val_();
	}

	template <typename... Args>
	static inline any_a ref__(const function fun, Args&&... args)
	{
		std::vector<symbol_a> v;
		v.reserve(sizeof...(Args));
		variadic_u<symbol_a>::variadic_(v, std::forward<Args>(args)...);
		return any_a(native_function_t(fun, std::move(v)), true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::native_function");
		return TYPE;
	}

	inline any_a eater_() const
	{
		return nothing_t<>::val_(); //TODO return range of parameter names
	}

	// function
	inline any_a operator()(any_a _, any_a range) const
	{
		return _function(range);
	}

protected:
	const function _function;
	const std::vector<symbol_a> _params;

	template <typename F>
	inline native_function_t(const function fun, F&& params)
		: thing_t{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{}
};

} // namespace strange

#endif
