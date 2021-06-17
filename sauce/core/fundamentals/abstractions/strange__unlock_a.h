#ifndef COM_ONEISH__STRANGE__UNLOCK_A_H
#define COM_ONEISH__STRANGE__UNLOCK_A_H

namespace strange
{
	struct unlock_i
	{
		struct empty {};

		static inline var<> read_lock (con<lock_a> const& me);

		static inline var<> write_lock (con<lock_a> const& me);

		static inline unlock_i::empty _read_lock (con<lock_a> const& me)
		{
			return unlock_i::empty{};
		}

		static inline unlock_i::empty _write_lock (con<lock_a> const& me)
		{
			return unlock_i::empty{};
		}
	};

	struct unlock_o :
		lock_o,
		unlock_i
	{
	};

	struct unlock_a
	{
		using operations = unlock_o;
		using creator_fp = var<unlock_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static inline var<unlock_a> create()
		{
			return var<unlock_a>{};
		}

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
