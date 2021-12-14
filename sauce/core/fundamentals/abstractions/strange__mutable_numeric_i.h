#ifndef COM_ONEISH__STRANGE__MUTABLE_NUMERIC_I_H
#define COM_ONEISH__STRANGE__MUTABLE_NUMERIC_I_H

namespace strange
{
	template <typename base_d>
	inline void mutable_numeric_v<base_d>::from_int64(int64_t number) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->from_int64(me, number);
	}

	template <typename base_d>
	inline void mutable_numeric_v<base_d>::from_uint64(uint64_t number) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->from_uint64(me, number);
	}

	template <typename base_d>
	inline void mutable_numeric_v<base_d>::from_float64(double number) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->from_float64(me, number);
	}
}

#endif
