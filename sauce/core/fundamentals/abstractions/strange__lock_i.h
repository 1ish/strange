#ifndef COM_ONEISH__STRANGE__LOCK_I_H
#define COM_ONEISH__STRANGE__LOCK_I_H

namespace strange
{
	template <typename base_d>
	inline ptr<> lock_v<base_d>::read_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->read_lock(me);
	}

	template <typename base_d>
	inline ptr<> lock_v<base_d>::write_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->write_lock(me);
	}
}

#endif
