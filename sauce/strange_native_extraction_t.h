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
			interface_eater_params(reflection<T>::cat().name_() + sym(":#"), flock_t<>::val(std::move(v)))) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::native_extraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

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

	// operation
	inline any_a<> interface__(range_a<> const&) const
	{
		return interface_();
	}

	inline cat_a<> interface_() const
	{
		return _interface;
	}

protected:
	const_member const _function;
	cat_a<> const _interface;
	flock_a<> const _eater;

	inline native_extraction_t(const_member const fun, std::pair<cat_a<>, flock_a<>> const& interface_eater)
		: operation_t{}
		, _function{ fun }
		, _interface{ interface_eater.first }
		, _eater{ interface_eater.second }
	{}
};

} // namespace strange

#endif
