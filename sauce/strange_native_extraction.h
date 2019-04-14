#ifndef COM_ONEISH_STRANGE_NATIVE_EXTRACTION_H
#define COM_ONEISH_STRANGE_NATIVE_EXTRACTION_H

namespace strange
{

template <typename T, typename CAT_ = thing_>
class NativeExtraction : public Thing<CAT_>
{
	using member = thing_(T::*)(thing_) const;

public: ___THING___
	// construction
	static inline thing_ val(thing_ _)
	{
		assert(false); //TODO
		return Nothing<>::val_();
	}

	template <typename... Args>
	static inline thing_ val__(const member fun, Args&&... args)
	{
		std::vector<symbol_> v;
		v.reserve(sizeof...(Args));
		Variadic<symbol_>::variadic_(v, std::forward<Args>(args)...);
		return thing_{ NativeExtraction(fun, std::move(v)) };
	}

	static inline thing_ ref(thing_ _)
	{
		assert(false); //TODO
		return Nothing<>::val_();
	}

	template <typename... Args>
	static inline thing_ ref__(const member fun, Args&&... args)
	{
		std::vector<symbol_> v;
		v.reserve(sizeof...(Args));
		Variadic<symbol_>::variadic_(v, std::forward<Args>(args)...);
		return thing_(NativeExtraction(fun, std::move(v)), true);
	}

	// reflection
	static inline symbol_ type_()
	{
		static symbol_ TYPE = sym__("strange::NativeExtraction");
		return TYPE;
	}

	// function
	inline thing_ operator()(thing_ thing, thing_ range) const
	{
		return (cast_<T>(thing).*_function)(range);
	}

protected:
	const member _function;
	const std::vector<symbol_> _params;

	template <typename F>
	inline NativeExtraction(const member fun, F&& params)
		: Thing{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{}
};

} // namespace strange

#endif
