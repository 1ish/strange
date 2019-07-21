#ifndef COM_ONEISH_STRANGE_NATIVE_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_NATIVE_EXTRACTION_T_H

namespace strange
{

template <typename T, typename _ABSTRACTION_ = operation_a<>>
class native_extraction_t : public operation_t<_ABSTRACTION_>
{
	using const_member = any_a<>(T::*)(range_a<> const&) const;

public:
	// override
	using over = thing_o<native_extraction_t<T>>;

	// construction
	template <typename... Args>
	static inline operation_a<> val(const_member const fun, Args&&... args)
	{
		std::vector<any_a<>> v;
		v.reserve(sizeof...(Args));
		variadic_u<>::variadic(v, std::forward<Args>(args)...);
		return operation_a<>{ over{ native_extraction_t<T>(fun,
			cat_eater_params(flock_t<>::val(std::move(v)))) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_extraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
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
		auto result = reflection<_ABSTRACTION_>::cats();
		result.insert(cat_());
		return result;
	}

	inline any_a<> eater_() const
	{
		return _eater;
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		assert(check<T>(thing));
		return (static_cast<T&>(thing).*_function)(range);
	}

protected:
	const_member const _function;
	cat_a<> const _cat;
	flock_a<> const _eater;

	inline native_extraction_t(const_member const fun, std::pair<cat_a<>, flock_a<>> const& cat_eater)
		: operation_t{}
		, _function{ fun }
		, _cat{ cat_eater.first }
		, _eater{ cat_eater.second }
	{}
};

} // namespace strange

#endif
