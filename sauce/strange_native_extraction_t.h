#ifndef COM_ONEISH_STRANGE_NATIVE_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_NATIVE_EXTRACTION_T_H

namespace strange
{

template <typename T, typename _ABSTRACTION_ = any_a<>>
class native_extraction_t : public operation_t<_ABSTRACTION_>
{
	using member = any_a<>(T::*)(range_a<> const&) const;

public: ___STRANGE_THING___
	// construction
	template <typename... Args>
	static inline any_a<> val(member const fun, Args&&... args)
	{
		std::vector<symbol_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<symbol_a<>>::variadic(v, std::forward<Args>(args)...);
		return any_a<>{ native_extraction_t(fun, std::move(v)) };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_extraction");
		return TYPE;
	}

	inline any_a<> eater_() const
	{
		return no(); //TODO return range of parameter names
	}

	// function
	inline any_a<> operator()(any_a<> const& thing, range_a<> const& range) const
	{
		return (cast<T>(thing).*_function)(range);
	}

protected:
	member const _function;
	std::vector<symbol_a<>> const _params;

	template <typename F>
	inline native_extraction_t(member const fun, F&& params)
		: operation_t{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{}
};

} // namespace strange

#endif
