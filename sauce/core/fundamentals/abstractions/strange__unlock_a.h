#ifndef COM_ONEISH__STRANGE__UNLOCK_A_H
#define COM_ONEISH__STRANGE__UNLOCK_A_H

namespace strange
{
	struct unlock_o : // operations
		any_o
	{
		struct empty {};

		static inline ptr<> read_lock (var<unlock_a> const& me);

		static inline ptr<> write_lock (var<unlock_a> const& me);

		static inline empty _read_lock (var<unlock_a> const& me);

		static inline empty _write_lock (var<unlock_a> const& me);
	};

	struct unlock_b // base
	{
		mutable thing_t* t;
		mutable unlock_o const* o;
	};

	template <typename base_d>
	struct unlock_c : // constant
		any_c<base_d>
	{
		using me_d = con<unlock_a>;
	};

	template <typename base_d>
	struct unlock_v : // variable
		any_v<base_d>
	{
		using me_d = var<unlock_a>;

		inline ptr<> read_lock() const;

		inline ptr<> write_lock() const;
	};

	struct unlock_a : // abstraction
		unlock_c<unlock_b>
	{
		using operations = unlock_o;
		using variations = unlock_v<unlock_a>;
		using creator_fp = var<unlock_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
