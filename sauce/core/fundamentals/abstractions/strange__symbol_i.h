#ifndef COM_ONEISH__STRANGE__SYMBOL_I_H
#define COM_ONEISH__STRANGE__SYMBOL_I_H

namespace strange
{
	template <typename base_d>
	inline bool symbol_c<base_d>::equal(con<symbol_a> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->equal(me, other);
	}

	template <typename base_d>
	inline bool symbol_c<base_d>::not_equal(con<symbol_a> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->not_equal(me, other);
	}

	template <typename base_d>
	inline bool symbol_c<base_d>::less(con<symbol_a> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->less(me, other);
	}

	template <typename base_d>
	inline bool symbol_c<base_d>::greater(con<symbol_a> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->greater(me, other);
	}

	template <typename base_d>
	inline bool symbol_c<base_d>::less_or_equal(con<symbol_a> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->less_or_equal(me, other);
	}

	template <typename base_d>
	inline bool symbol_c<base_d>::greater_or_equal(con<symbol_a> const& other) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->greater_or_equal(me, other);
	}

	template <typename base_d>
	inline var<symbol_a> symbol_c<base_d>::add(con<symbol_a> const& suffix) const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->add(me, suffix);
	}

	template <typename base_d>
	inline char const* symbol_c<base_d>::char_star() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->char_star(me);
	}

	template <typename base_d>
	inline int64_t symbol_c<base_d>::length() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->length(me);
	}

	template <typename base_d>
	inline char symbol_c<base_d>::first_char() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->first_char(me);
	}

	template <typename base_d>
	inline char symbol_c<base_d>::last_char() const
	{
		auto const& me = reinterpret_cast<me_d const&>(*this);
		return me.o->last_char(me);
	}

	inline bool symbol_o::not_equal(con<symbol_a> const& me,
		con<symbol_a> const& other)
	{
		return !me.o->equal(me, other);
	}

	inline bool symbol_o::greater(con<symbol_a> const& me,
		con<symbol_a> const& other)
	{
		return !me.o->less_or_equal(me, other);
	}

	inline bool symbol_o::greater_or_equal(con<symbol_a> const& me,
		con<symbol_a> const& other)
	{
		return !me.o->less(me, other);
	}

	inline bool operator==(con<symbol_a> const& left,
		char const* right)
	{
		return std::strncmp(left.o->char_star(left), right, static_cast<std::size_t>(left.o->length(left) + 1)) == 0;
	}

	inline bool operator!=(con<symbol_a> const& left,
		char const* right)
	{
		return std::strncmp(left.o->char_star(left), right, static_cast<std::size_t>(left.o->length(left) + 1)) != 0;
	}

	inline bool operator==(char const* left,
		con<symbol_a> const& right)
	{
		return std::strncmp(left, right.o->char_star(right), static_cast<std::size_t>(right.o->length(right) + 1)) == 0;
	}

	inline bool operator!=(char const* left,
		con<symbol_a> const& right)
	{
		return std::strncmp(left, right.o->char_star(right), static_cast<std::size_t>(right.o->length(right) + 1)) != 0;
	}
}

#endif
