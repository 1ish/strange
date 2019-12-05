#ifndef COM_ONEISH_STRANGE_NATIVE_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_NATIVE_EXTRACTION_T_H

namespace strange
{

template <typename _abstraction_, typename ___ego___ = operation_a<>>
class native_extraction_t : public operation_t<___ego___>
{
	using const_member = any_a<>(_abstraction_::*)(range_a<> const&) const;

public:
	// override
	using over = thing_o<native_extraction_t<_abstraction_>>;

	// construction
	template <typename... Args>
	static inline operation_a<> create(const_member const fun, Args&&... args)
	{
		std::vector<any_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<>::variadic(v, std::forward<Args>(args)...);
		return operation_a<>{ over{ native_extraction_t<_abstraction_>(fun,
			kind_eater_params(flock_t<>::create(std::move(v)))) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_extraction");
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

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		assert(check<_abstraction_>(thing));
		return (static_cast<_abstraction_&>(thing).*_function)(range);
	}

protected:
	const_member const _function;
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;

	inline native_extraction_t(const_member const fun, std::pair<kind_a<>, flock_a<>> const& kind_eater)
		: operation_t{ false, false, kind_eater.second }
		, _function{ fun }
		, _kind{ kind_eater.first }
		, _kinds{ kinds(_kind) }
		, _cat{ kind_to_cat(_kind) }
		, _cats{ cats(_cat) }
	{}
};

} // namespace strange

#endif
