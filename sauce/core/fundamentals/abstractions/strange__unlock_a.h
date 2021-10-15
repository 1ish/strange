#ifndef COM_ONEISH__STRANGE__UNLOCK_A_H
#define COM_ONEISH__STRANGE__UNLOCK_A_H

namespace strange
{
	struct unlock_o :
		any_o
	{
		struct empty {};

		static inline ptr<> read_lock (var<lock_a> const& me)
		{
			return ptr<>{};
		}

		static inline ptr<> write_lock (var<lock_a> const& me)
		{
			return ptr<>{};
		}

		static inline empty _read_lock (var<lock_a> const& me)
		{
			return empty{};
		}

		static inline empty _write_lock (var<lock_a> const& me)
		{
			return empty{};
		}
	};

	struct unlock_a
	{
		using operations = unlock_o;
		using creator_fp = var<unlock_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
