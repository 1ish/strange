#ifndef COM_ONEISH_STRANGE_ONE_T_H
#define COM_ONEISH_STRANGE_ONE_T_H

namespace strange
{

class one_t
{
public:
	// erasure
	inline void ___weak___(any_a<>::___WEAK___ const& weak) const
	{
		_meek = weak;
	}

	// exposure
	inline one_t const& extract_thing() const
	{
		return *this;
	}

	inline one_t& mutate_thing()
	{
		return *this;
	}

	// conversion
	inline operator bool() const
	{
		return something();
	}

	// identification
	inline void const* identity() const
	{
		return this;
	}

	inline bool identical(any_a<> const& thing) const
	{
		return identity() == thing.identity();
	}

	// comparison
	static inline bool nothing()
	{
		return false;
	}

	static inline bool something()
	{
		return true;
	}

	inline bool same_(any_a<> const& thing) const
	{
		return identical(thing);
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std::size_t hash() const
	{
		return std::hash<void const*>{}(identity());
	}

	static inline bool is(std::string const& s)
	{
		return false;
	}

	inline bool less_than_(any_a<> const& thing) const
	{
		return identity() < thing.identity();
	}

	inline bool greater_than_(any_a<> const& thing) const
	{
		return identity() > thing.identity();
	}

	inline bool less_or_equal_(any_a<> const& thing) const
	{
		return identity() <= thing.identity();
	}

	inline bool greater_or_equal_(any_a<> const& thing) const
	{
		return identity() >= thing.identity();
	}

	inline parcel_a<> parcel_() const
	{
		return parcel_a<>{};
	}

	inline parcel_a<> parcel_unique_(unordered_herd_a<number_data_a<uint64_t>>& herd) const
	{
		return parcel_a<>{};
	}

protected:
	any_a<>::___WEAK___ mutable _meek;

	// construction
	inline one_t() {};
};

} // namespace strange

#endif
