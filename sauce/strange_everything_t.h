#ifndef COM_ONEISH_STRANGE_EVERYTHING_T_H
#define COM_ONEISH_STRANGE_EVERYTHING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class everything_t : public something_t<_ABSTRACTION_>
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
		static any_a<> VAL = any_a<>{ everything_t<>{} };
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
		static any_a<> REF = any_a<>(everything_t<>{}, true);
		return REF;
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::everything");
		return TYPE;
	}

	// comparison
	static inline any_a<> everything(any_a<> const&)
	{
		return everything_();
	}

	static inline any_a<> everything_()
	{
		return everything_t<>::val_();
	}

	static inline bool everything__()
	{
		return true;
	}

	inline bool operator==(any_a<> const& thing) const
	{
		return thing.everything__();
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !thing.everything__();
	}

	inline std::size_t hash__() const
	{
		static std::size_t const HASH = std::hash<int64_t>{}(1);
		return HASH;
	}

	// iterator
	inline any_a<>& operator*() const
	{
		return everything_t<>::val__();
	}

	inline everything_t& operator++()
	{
		return *this;
	}

	inline everything_t operator++(int)
	{
		return *this;
	}

protected:
	inline everything_t()
		: something_t{}
	{}
};

} // namespace strange

#endif
