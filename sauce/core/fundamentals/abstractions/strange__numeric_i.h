#ifndef COM_ONEISH__STRANGE__NUMERIC_I_H
#define COM_ONEISH__STRANGE__NUMERIC_I_H

namespace strange
{
	template <typename base_d>
	inline int64_t numeric_c<base_d>::int64() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->int64(me);
	}

	template <typename base_d>
	inline uint64_t numeric_c<base_d>::uint64() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->uint64(me);
	}

	template <typename base_d>
	inline double numeric_c<base_d>::float64() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->float64(me);
	}

	template <typename base_d>
	inline int64_t numeric_c<base_d>::byte_size() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->byte_size(me);
	}

	template <typename base_d>
	inline bool numeric_c<base_d>::is_int() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_int(me);
	}

	template <typename base_d>
	inline bool numeric_c<base_d>::is_signed() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_signed(me);
	}

	template <typename base_d>
	inline bool numeric_c<base_d>::is_nan() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_nan(me);
	}

	template <typename base_d>
	inline bool numeric_c<base_d>::is_inf() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_inf(me);
	}

	template <typename base_d>
	inline bool numeric_c<base_d>::is_finite() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_finite(me);
	}

	template <typename base_d>
	inline bool numeric_c<base_d>::is_normal() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_normal(me);
	}

	template <typename base_d>
	inline bool numeric_c<base_d>::little_endian() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->little_endian(me);
	}
}

#endif
