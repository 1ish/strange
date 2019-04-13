#ifndef COM_ONEISH_STRANGE_NATIVE_FUNCTION_H
#define COM_ONEISH_STRANGE_NATIVE_FUNCTION_H

namespace strange
{

template <typename CAT = thing_>
class NativeFunction : public Thing<CAT>
{
	using function = thing_(*)(thing_);

public: ___THING___
	// construction
	static inline thing_ val(thing_ _)
	{
		assert(false); //TODO
		return Nothing<>::val_();
	}

	template <typename... Args>
	static inline thing_ val__(const function fun, Args&&... args)
	{
		std::vector<symbol_> v;
		v.reserve(sizeof...(Args));
		Variadic<symbol_>::variadic_(v, std::forward<Args>(args)...);
		return thing_{ NativeFunction(fun, std::move(v)) };
	}

	static inline thing_ ref(thing_ _)
	{
		assert(false); //TODO
		return Nothing<>::val_();
	}

	template <typename... Args>
	static inline thing_ ref__(const function fun, Args&&... args)
	{
		std::vector<symbol_> v;
		v.reserve(sizeof...(Args));
		Variadic<symbol_>::variadic_(v, std::forward<Args>(args)...);
		return thing_(NativeFunction(fun, std::move(v)), true);
	}

	// function
	inline thing_ operator()(thing_ _, thing_ range) const
	{
		return _function(range);
	}

protected:
	const function _function;
	const std::vector<symbol_> _params;

	template <typename F>
	inline NativeFunction(const function fun, F&& params)
		: Thing{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{}
};

} // namespace strange

#endif
