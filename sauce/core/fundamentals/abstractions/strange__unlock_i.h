#ifndef COM_ONEISH__STRANGE__UNLOCK_I_H
#define COM_ONEISH__STRANGE__UNLOCK_I_H

namespace strange
{
	template <typename base_d>
	inline ptr<> unlock_v<base_d>::read_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->read_lock(me);
	}

	template <typename base_d>
	inline ptr<> unlock_v<base_d>::write_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->write_lock(me);
	}

	inline ptr<> unlock_o::read_lock(var<unlock_a> const& me)
	{
		return ptr<>{};
	}

	inline ptr<> unlock_o::write_lock(var<unlock_a> const& me)
	{
		return ptr<>{};
	}

	inline unlock_o::empty unlock_o::_read_lock(var<unlock_a> const& me)
	{
		return empty{};
	}

	inline unlock_o::empty unlock_o::_write_lock(var<unlock_a> const& me)
	{
		return empty{};
	}
}

#endif
