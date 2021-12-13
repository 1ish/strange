#ifndef COM_ONEISH__STRANGE__DATA_I_H
#define COM_ONEISH__STRANGE__DATA_I_H

namespace strange
{
	template <typename base_d, typename type_d>
	inline ptr<> data_c<base_d, type_d>::read_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->read_lock(me);
	}

	template <typename base_d, typename type_d>
	inline type_d const& data_c<base_d, type_d>::extract() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->extract(me);
	}

	template <typename base_d, typename type_d>
	inline ptr<> data_v<base_d, type_d>::write_lock() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->write_lock(me);
	}

	template <typename base_d, typename type_d>
	inline type_d& data_v<base_d, type_d>::mutate() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		return me.o->mutate(me);
	}
}

#endif
