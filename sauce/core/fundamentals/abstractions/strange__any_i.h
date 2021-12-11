#ifndef COM_ONEISH__STRANGE__ANY_I_H
#define COM_ONEISH__STRANGE__ANY_I_H

namespace strange
{
	template <typename base_d>
	inline var<symbol_a> any_c<base_d>::cat() const //TODO cat
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->cat(me);
	}

	template <typename base_d>
	inline bool any_c<base_d>::is(con<> const& abstraction) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->is(me, abstraction);
	}

	template <typename base_d>
	inline bool any_c<base_d>::as(var<> const& abstraction) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->as(me, abstraction);
	}

	template <typename base_d>
	inline var<symbol_a> any_c<base_d>::type() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->type(me);
	}

	template <typename base_d>
	inline bool any_c<base_d>::something() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->something(me);
	}

	template <typename base_d>
	inline var<> any_c<base_d>::error() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->error(me);
	}

	template <typename base_d>
	inline uint64_t any_c<base_d>::identity() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->identity(me);
	}

	template <typename base_d>
	inline uint64_t any_c<base_d>::hash() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->hash(me);
	}

	template <typename base_d>
	inline bool any_c<base_d>::equal(con<> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->equal(me, other);
	}

	template <typename base_d>
	inline bool any_c<base_d>::not_equal(con<> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->not_equal(me, other);
	}

	template <typename base_d>
	inline bool any_c<base_d>::less(con<> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->less(me, other);
	}

	template <typename base_d>
	inline bool any_c<base_d>::greater(con<> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->greater(me, other);
	}

	template <typename base_d>
	inline bool any_c<base_d>::less_or_equal(con<> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->less_or_equal(me, other);
	}

	template <typename base_d>
	inline bool any_c<base_d>::greater_or_equal(con<> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->greater_or_equal(me, other);
	}

	template <typename base_d>
	inline bool any_c<base_d>::pack(var<container_a> const& container) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->pack(me, container);
	}

	template <typename base_d>
	inline void any_v<base_d>::set_something(bool is_something) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		me.o->set_something(me, is_something);
	}

	template <typename base_d>
	inline void any_v<base_d>::set_error(con<> const& err) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		me.mut();
		me.o->set_error(me, err);
	}

	inline uint64_t any_o::identity(con<> const& me)
	{
		return reinterpret_cast<std::uintptr_t>(me.t);
	}

	inline bool any_o::not_equal(con<> const& me,
		con<> const& other)
	{
		return !me.o->equal(me, other);
	}

	inline bool any_o::greater(con<> const& me,
		con<> const& other)
	{
		return !me.o->less_or_equal(me, other);
	}

	inline bool any_o::greater_or_equal(con<> const& me,
		con<> const& other)
	{
		return !me.o->less(me, other);
	}
}

//TODO hash_u
namespace std
{
	template <typename abstraction_d>
	struct hash<strange::con<abstraction_d>>
	{
		std::size_t operator()(strange::con<abstraction_d> const& thing) const
		{
			return static_cast<std::size_t>(thing.o->hash(thing));
		}
	};

	template <typename abstraction_d>
	struct hash<strange::var<abstraction_d>>
	{
		std::size_t operator()(strange::var<abstraction_d> const& thing) const
		{
			return static_cast<std::size_t>(thing.o->hash(thing));
		}
	};

	template <typename abstraction_d>
	struct hash<strange::ptr<abstraction_d>>
	{
		std::size_t operator()(strange::ptr<abstraction_d> const& thing) const
		{
			return static_cast<std::size_t>(thing.o->hash(thing));
		}
	};
}

#endif
