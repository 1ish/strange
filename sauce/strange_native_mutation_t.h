#ifndef COM_ONEISH_STRANGE_NATIVE_MUTATION_T_H
#define COM_ONEISH_STRANGE_NATIVE_MUTATION_T_H

namespace strange
{

template <typename T, typename _ABSTRACTION_ = any_a>
class native_mutation_t : public thing_t<_ABSTRACTION_>
{
	using member = any_a(T::*)(any_a);

public: ___THING___
	// construction
	static inline any_a val(any_a _)
	{
		throw dis__("strange::native_mutation::val cannot be implemented");
	}

	template <typename... Args>
	static inline any_a val__(const member fun, Args&&... args)
	{
		std::vector<symbol_a> v;
		v.reserve(sizeof...(Args));
		variadic_u<symbol_a>::variadic_(v, std::forward<Args>(args)...);
		return any_a{ native_mutation_t(fun, std::move(v)) };
	}

	static inline any_a ref(any_a _)
	{
		throw dis__("strange::native_mutation::ref cannot be implemented");
	}

	template <typename... Args>
	static inline any_a ref__(const member fun, Args&&... args)
	{
		std::vector<symbol_a> v;
		v.reserve(sizeof...(Args));
		variadic_u<symbol_a>::variadic_(v, std::forward<Args>(args)...);
		return any_a(native_mutation_t(fun, std::move(v)), true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::native_mutation");
		return TYPE;
	}

	inline any_a eater_() const
	{
		return nothing_t<>::val_(); //TODO return range of parameter names
	}

	// function
	inline any_a operator()(any_a thing, any_a range) const
	{
		return (cast_<T>(std::move(thing)).*_function)(std::move(range));
	}

protected:
	const member _function;
	const std::vector<symbol_a> _params;

	template <typename F>
	inline native_mutation_t(const member fun, F&& params)
		: thing_t{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{}
};

} // namespace strange

#endif
