#ifndef COM_ONEISH__STRANGE__LOCK_A_H
#define COM_ONEISH__STRANGE__LOCK_A_H

namespace strange
{
	struct lock_o : // operations
		any_o
	{
		static inline ptr<> read_lock (var<lock_a> const& me);

		static inline ptr<> write_lock (var<lock_a> const& me);

		static inline std::shared_lock<std::shared_mutex> _read_lock (var<lock_a> const& me);

		static inline std::unique_lock<std::shared_mutex> _write_lock (var<lock_a> const& me);
	};

	struct lock_b // base
	{
		mutable thing_t* t;
		mutable lock_o const* o;
	};

	template <typename base_d>
	struct lock_c : // constant
		any_c<base_d>
	{
		using me_d = con<lock_a>;
	};
	
	template <typename base_d>
	struct lock_v : // variable
		any_v<base_d>
	{
		using me_d = var<lock_a>;

		inline ptr<> read_lock() const;

		inline ptr<> write_lock() const;
	};

	struct lock_a : // abstraction
		lock_c<lock_b>
	{
		using operations = lock_o;
		using variations = lock_v<lock_a>;
		using creator_fp = var<lock_a>(*)(con<range_a<>> const& range);

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
