#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

namespace strange
{
	struct symbol_o : // operations
		any_o
	{
		bool (*equal) (con<symbol_a> const& me,
			con<symbol_a> const& other);

		static inline bool not_equal(con<symbol_a> const& me,
			con<symbol_a> const& other);

		bool (*less) (con<symbol_a> const& me,
			con<symbol_a> const& other);

		static inline bool greater(con<symbol_a> const& me,
			con<symbol_a> const& other);

		bool (*less_or_equal) (con<symbol_a> const& me,
			con<symbol_a> const& other);

		static inline bool greater_or_equal(con<symbol_a> const& me,
			con<symbol_a> const& other);

		var<symbol_a> (*add) (con<symbol_a> const& me,
			con<symbol_a> const& suffix);

		char const* (*char_star) (con<symbol_a> const& me);

		int64_t (*length) (con<symbol_a> const& me);

		char (*first_char) (con<symbol_a> const& me);

		char (*last_char) (con<symbol_a> const& me);
	};

	struct symbol_b // base
	{
		mutable thing_t* t;
		mutable symbol_o const* o;
	};
	
	template <typename base_d>
	struct symbol_c : // constant
		any_c<base_d>
	{
		using me_d = con<symbol_a>;

		inline bool equal(con<symbol_a> const& other) const;

		inline bool not_equal(con<symbol_a> const& other) const;

		inline bool less(con<symbol_a> const& other) const;

		inline bool greater(con<symbol_a> const& other) const;

		inline bool less_or_equal(con<symbol_a> const& other) const;

		inline bool greater_or_equal(con<symbol_a> const& other) const;

		inline var<symbol_a> add(con<symbol_a> const& suffix) const;

		inline char const* char_star() const;

		inline int64_t length() const;

		inline char first_char() const;

		inline char last_char() const;
	};
	
	template <typename base_d>
	struct symbol_v : // variable
		any_v<base_d>
	{
		using me_d = var<symbol_a>;
	};
	
	struct symbol_a : // abstraction
		symbol_c<symbol_b>
	{
		using operations = symbol_o;
		using variations = symbol_v<symbol_a>;
		using creator_fp = var<symbol_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
