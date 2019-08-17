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
			kind_eater_params(flock_t<>::val(std::move(v)))) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_function");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	inline any_a<> cat__(range_a<> const&) const
	{
		return cat_();
	}

	inline cat_a<> cat_() const
	{
		return _cat;
	}

	inline any_a<> cats__(range_a<> const&) const
	{
		return cats_();
	}

	inline unordered_herd_a<> cats_() const
	{
		return _cats;
	}

	inline any_a<> kind__(range_a<> const&) const
	{
		return kind_();
	}

	inline kind_a<> kind_() const
	{
		return _kind;
	}

	inline any_a<> kinds__(range_a<> const&) const
	{
		return kinds_();
	}

	inline unordered_herd_a<> kinds_() const
	{
		return _kinds;
	}

	inline any_a<> eater_() const
	{
		return _eater;
	}

	// function
	inline any_a<> operate_(any_a<>&, range_a<> const& range) const
	{
		return _function(range);
	}

protected:
	function const _function;
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;
	flock_a<> const _eater;

	inline native_function_t(function const fun, std::pair<kind_a<>, flock_a<>> const& kind_eater)
		: operation_t{}
		, _function{ fun }
		, _kind{ kind_eater.first }
		, _kinds{ kinds(_kind) }
		, _cat{ kind_to_cat(_kind) }
		, _cats{ kinds_to_cats(_kinds) }
		, _eater{ kind_eater.second }
	{}
};

} // namespace strange

#endif
