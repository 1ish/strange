#ifndef COM_ONEISH__STRANGE__CAT_I_H
#define COM_ONEISH__STRANGE__CAT_I_H

namespace strange
{
	template <typename base_d>
	inline int64_t cat_c<base_d>::order() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->order(me);
	}

	template <typename base_d>
	inline representation_e cat_c<base_d>::representation() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->representation(me);
	}

	template <typename base_d>
	inline var<symbol_a> cat_c<base_d>::scope() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->scope(me);
	}

	template <typename base_d>
	inline var<symbol_a> cat_c<base_d>::name() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->name(me);
	}

	template <typename base_d>
	inline var<list_a<var<kind_a>>> cat_c<base_d>::aspects() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->aspects(me);
	}
}

#endif
