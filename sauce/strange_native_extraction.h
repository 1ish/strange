#ifndef COM_ONEISH_STRANGE_NATIVE_EXTRACTION_H
#define COM_ONEISH_STRANGE_NATIVE_EXTRACTION_H

namespace strange
{

template <typename T, typename CAT_ = any_a>
class NativeExtraction : public Thing<CAT_>
{
	using member = any_a(T::*)(any_a) const;

public: ___THING___
	// construction
	static inline any_a val(any_a _)
	{
		assert(false); //TODO
		return Nothing<>::val_();
	}

	template <typename... Args>
	static inline any_a val__(const member fun, Args&&... args)
	{
		std::vector<symbol_a> v;
		v.reserve(sizeof...(Args));
		Variadic<symbol_a>::variadic_(v, std::forward<Args>(args)...);
		return any_a{ NativeExtraction(fun, std::move(v)) };
	}

	static inline any_a ref(any_a _)
	{
		assert(false); //TODO
		return Nothing<>::val_();
	}

	template <typename... Args>
	static inline any_a ref__(const member fun, Args&&... args)
	{
		std::vector<symbol_a> v;
		v.reserve(sizeof...(Args));
		Variadic<symbol_a>::variadic_(v, std::forward<Args>(args)...);
		return any_a(NativeExtraction(fun, std::move(v)), true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::NativeExtraction");
		return TYPE;
	}

	inline any_a eater_() const
	{
		return Nothing<>::val_(); //TODO return range of parameter names
	}

	// function
	inline any_a operator()(any_a thing, any_a range) const
	{
		return (cast_<T>(thing).*_function)(range);
	}

protected:
	const member _function;
	const std::vector<symbol_a> _params;

	template <typename F>
	inline NativeExtraction(const member fun, F&& params)
		: Thing{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{}
};

} // namespace strange

#endif
