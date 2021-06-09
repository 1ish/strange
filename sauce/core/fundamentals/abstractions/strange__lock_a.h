#ifndef COM_ONEISH__STRANGE__LOCK_A_H
#define COM_ONEISH__STRANGE__LOCK_A_H

namespace strange
{
	struct lock_o : any_o
	{
		static var<> read_lock(con<lock_a> const& me);

		static var<> write_lock(con<lock_a> const& me);

		static inline std::shared_lock<std::shared_timed_mutex> _read_lock(con<lock_a> const& me);

		static inline std::unique_lock<std::shared_timed_mutex> _write_lock(con<lock_a> const& me);
	};

	struct lock_a
	{
		using operations = lock_o;
		using creator_fp = var<lock_a>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static var<lock_a> create();

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
