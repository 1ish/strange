#ifndef COM_ONEISH__STRANGE__CONTAINER_I_H
#define COM_ONEISH__STRANGE__CONTAINER_I_H

namespace strange
{
	// thing
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_thing(con<> const& thing) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_thing(me, thing);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_thing() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_thing(me);
	}

	template <typename base_d>
	inline var<> container_c<base_d>::thing() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->thing(me);
	}

	// boolean
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_boolean(bool boolean) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_boolean(me, boolean);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_boolean() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_boolean(me);
	}

	template <typename base_d>
	inline bool container_c<base_d>::boolean() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->boolean(me);
	}

	// int64
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_int64(int64_t int64) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_int64(me, int64);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_int64() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_int64(me);
	}

	template <typename base_d>
	inline int64_t container_c<base_d>::int64() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->int64(me);
	}

	// float64
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_float64(double float64) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_float64(me, float64);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_float64() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_float64(me);
	}

	template <typename base_d>
	inline double container_c<base_d>::float64() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->float64(me);
	}

	// symbol
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_symbol(con<symbol_a> const& symbol) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_symbol(me, symbol);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_symbol() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_symbol(me);
	}

	template <typename base_d>
	inline var<symbol_a> container_c<base_d>::symbol() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->symbol(me);
	}

	// lake
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_lake(con<lake_a> const& lake) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_lake(me, lake);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_lake() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_lake(me);
	}

	template <typename base_d>
	inline var<lake_a> container_c<base_d>::lake() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->lake(me);
	}

	// inventory
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_inventory() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_inventory(me);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_inventory() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_inventory(me);
	}

	template <typename base_d>
	inline bool container_c<base_d>::inventory_has(int64_t index) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->inventory_has(me, index);
	}

	template <typename base_d>
	inline var<container_a> container_c<base_d>::inventory_at(int64_t index) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->inventory_at(me, index);
	}

	// directory
	template <typename base_d>
	inline var<container_a> container_c<base_d>::make_directory() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->make_directory(me);
	}

	template <typename base_d>
	inline bool container_c<base_d>::is_directory() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is_directory(me);
	}

	template <typename base_d>
	inline bool container_c<base_d>::directory_has(con<symbol_a> const& symbol) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->directory_has(me, symbol);
	}

	template <typename base_d>
	inline var<container_a> container_c<base_d>::directory_at(con<symbol_a> const& symbol) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->directory_at(me, symbol);
	}

	// inventory
	template <typename base_d>
	inline void container_v<base_d>::inventory_update(int64_t index,
		var<container_a> const& container) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->inventory_update(me, index, container);
	}

	template <typename base_d>
	inline bool container_v<base_d>::inventory_insert(int64_t index,
		var<container_a> const& container) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->inventory_insert(me, index, container);
	}

	template <typename base_d>
	inline bool container_v<base_d>::inventory_erase(int64_t index) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->inventory_erase(me, index);
	}

	// directory
	template <typename base_d>
	inline void container_v<base_d>::directory_update(con<symbol_a> const& symbol,
		var<container_a> const& container) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.o->directory_update(me, symbol, container);
	}

	template <typename base_d>
	inline bool container_v<base_d>::directory_insert(con<symbol_a> const& symbol,
		var<container_a> const& container) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->directory_insert(me, symbol, container);
	}

	template <typename base_d>
	inline bool container_v<base_d>::directory_erase(con<symbol_a> const& symbol) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->directory_erase(me, symbol);
	}
}

#endif
