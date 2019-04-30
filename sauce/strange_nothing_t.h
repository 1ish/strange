#ifndef COM_ONEISH_STRANGE_NOTHING_T_H
#define COM_ONEISH_STRANGE_NOTHING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class nothing_t : public something_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline any_a<> val(any_a<> const& _)
	{
		return val_();
	}

	static inline any_a<> val_()
	{
		return val__();
	}

	static inline any_a<>& val__()
	{
		static any_a<> VAL = any_a<>{ nothing_t<>{} };
		return VAL;
	}

	static inline any_a<> ref(any_a<> const& _)
	{
		return ref_();
	}

	static inline any_a<> ref_()
	{
		return ref__();
	}

	static inline any_a<>& ref__()
	{
		static any_a<> REF = any_a<>(nothing_t<>{}, true);
		return REF;
	}

	// conversion
	inline operator bool() const
	{
		return anything__();
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::nothing");
		return TYPE;
	}

	// comparison
	static inline any_a<> nothing(any_a<> const&)
	{
		return nothing_();
	}

	static inline any_a<> nothing_()
	{
		return everything_t<>::val_();
	}

	static inline bool nothing__()
	{
		return true;
	}

	static inline any_a<> anything(any_a<> const&)
	{
		return anything_();
	}

	static inline any_a<> anything_()
	{
		return nothing_t<>::val_();
	}

	static inline bool anything__()
	{
		return false;
	}

	inline bool operator==(any_a<> const& thing) const
	{
		return thing.nothing__();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !thing.nothing__();
	}

	inline std::size_t hash__() const
	{
		static std::size_t const HASH = std::hash<int64_t>{}(0);
		return HASH;
	}

	// range
	inline any_a<> cbegin() const
	{
		return it_t<true, any_a<>, everything_t<>>::val_(nothing_t<>::val_());
	}

	inline any_a<> begin() const
	{
		return it_t<true, any_a<>, everything_t<>>::val_(nothing_t<>::val_());
	}

	inline any_a<> begin()
	{
		return it_t<false, any_a<>, everything_t<>>::val_(nothing_t<>::val_());
	}

	inline any_a<> cend() const
	{
		return everything_t<>::val_();
	}

	inline any_a<> end() const
	{
		return everything_t<>::val_();
	}

	inline any_a<> end()
	{
		return everything_t<>::val_();
	}

	// iterator
	inline any_a<>& operator*() const
	{
		return nothing_t<>::val__();
	}

	inline nothing_t& operator++()
	{
		return *this;
	}

	inline nothing_t operator++(int)
	{
		return *this;
	}

protected:
	inline nothing_t()
		: something_t{}
	{}
};

} // namespace strange

#endif
