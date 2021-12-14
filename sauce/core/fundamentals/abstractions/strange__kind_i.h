#ifndef COM_ONEISH__STRANGE__KIND_I_H
#define COM_ONEISH__STRANGE__KIND_I_H

namespace strange
{
	template <typename base_d>
	inline bool kind_c<base_d>::address() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->address(me);
	}

	template <typename base_d>
	inline behaviour_e kind_c<base_d>::behaviour() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->behaviour(me);
	}

	template <typename base_d>
	inline var<cat_a> kind_c<base_d>::the_cat() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->the_cat(me);
	}

	template <typename base_d>
	inline var<type_a> kind_c<base_d>::the_type() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->the_type(me);
	}
}

#endif
