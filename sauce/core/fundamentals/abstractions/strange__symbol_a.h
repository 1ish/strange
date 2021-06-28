#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

namespace strange
{
	struct symbol_o :
		any_o
	{
		var<symbol_a> (*add) (con<symbol_a> const& me,
			con<symbol_a> const& suffix);

		char const* (*char_star) (con<symbol_a> const& me);

		int64_t (*length) (con<symbol_a> const& me);

		char (*first_char) (con<symbol_a> const& me);

		char (*last_char) (con<symbol_a> const& me);
	};

	struct symbol_a
	{
		using operations = symbol_o;
		using creator_fp = var<symbol_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};

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
