#ifndef COM_ONEISH_STRANGE_NATIVE_MUTATION_T_H
#define COM_ONEISH_STRANGE_NATIVE_MUTATION_T_H

namespace strange
{

template <typename T, typename _ABSTRACTION_ = any_a<>>
class native_mutation_t : public operation_t<_ABSTRACTION_>
{
	using member = any_a<>(T::*)(range_a<> const&);

public: ___STRANGE_THING___
	// construction
	template <typename... Args>
	static inline any_a<> val(member const fun, Args&&... args)
	{
		std::vector<symbol_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<symbol_a<>>::variadic(v, std::forward<Args>(args)...);
		return any_a<>{ native_mutation_t(fun, std::move(v)) };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_mutation");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

	inline any_a<> eater_() const
	{
		return no(); //TODO return range of parameter names
	}

	// function
	inline any_a<> operate__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::native_mutation::operate passed empty range");
		}
		any_a<> thing(*it, true);
		return operate_(thing, range_t<>::val_(++it, range.cend_()));
	}

	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		assert(dynamic_cast<T*>(&thing));
		return (static_cast<T&>(thing).*_function)(range);
	}

protected:
	member const _function;
	std::vector<symbol_a<>> const _params;

	template <typename F>
	inline native_mutation_t(member const fun, F&& params)
		: operation_t{}
		, _function{ fun }
		, _params{ std::forward<F>(params) }
	{}
};

} // namespace strange

#endif
