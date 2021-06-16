#ifndef COM_ONEISH__STRANGE__LOCK_A_H
#define COM_ONEISH__STRANGE__LOCK_A_H

namespace strange
{
	struct lock_i
	{
		static inline var<> read_lock (con<lock_a> const& me);

		static inline var<> write_lock (con<lock_a> const& me);

		static inline std::shared_lock<std::shared_timed_mutex> _read_lock (con<lock_a> const& me);

		static inline std::unique_lock<std::shared_timed_mutex> _write_lock (con<lock_a> const& me);
	};

	struct lock_o :
		any_i,
		lock_i
	{
	};

	struct lock_a
	{
		using interface = lock_i;
		using operations = lock_o;
		using creator_fp = var<lock_a>(*)(con<range_a<>> const& range);

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static inline var<lock_a> create();

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
