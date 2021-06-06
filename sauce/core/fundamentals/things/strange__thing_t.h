#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

namespace strange
{
	struct thing_t
	{
		std::atomic_int64_t refs_d;
		any_a error_d;

	protected:
		thing_t(any_a& me);

		thing_t(any_a& me,
			any_a const& original);

		thing_t(thing_t const&) = delete;

		thing_t& operator=(thing_t const&) = delete;

		virtual ~thing_t();

	private:
		// any_o
		static any_o const* operations_f();
		static any_o const* pointer_operations_f();

	protected:
		// inline
		static inline void _initialise_f(any_a& me)
		{
		}

		static inline void _clone_f(any_a const& me,
			any_a& copy)
		{
		}

	public:
		static inline void set_something_f(var<> const& me,
			bool is_something)
		{
			if (is_something == thing_t::something_f(me))
			{
				return;
			}
			me.mut();
			auto& mate = reinterpret_cast<var<>&>(me.t->error_d);
			if (is_something)
			{
				mate.dec();
				mate.t = nullptr;
				mate.o = nullptr;
			}
			else
			{
				auto const err = thing_t::create_f();
				err.inc();
				mate.t = err.t;
				mate.o = err.o;
			}
		}

		static inline bool something_f(con<> const& me)
		{
			return !me.t->error_d.t;
		}

		static inline bool _equal_f(con<> const& me,
			con<> const& other)
		{
			return me.t == other.t;
		}

		static inline bool _not_equal_f(con<> const& me,
			con<> const& other)
		{
			return me.t != other.t;
		}

		static inline bool _less_f(con<> const& me,
			con<> const& other)
		{
			return me.t < other.t;
		}

		static inline bool _greater_f(con<> const& me,
			con<> const& other)
		{
			return me.t > other.t;
		}

		static inline bool _less_or_equal_f(con<> const& me,
			con<> const& other)
		{
			return me.t <= other.t;
		}

		static inline bool _greater_or_equal_f(con<> const& me,
			con<> const& other)
		{
			return me.t >= other.t;
		}

	protected:
		// any_a
		static bool is_f(con<> const& me,
			con<> const& abstraction);

		static bool as_f(con<> const& me,
			var<> const& abstraction);

		static var<symbol_a> type_f(con<> const& me);

		static void set_error_f(var<> const& me,
			con<> const& error_d);

		static var<> error_f(con<> const& me);

		static uint64_t hash_f(con<> const& me);

		static bool equal_f(con<> const& me,
			con<> const& other);

		static bool not_equal_f(con<> const& me,
			con<> const& other);

		static bool less_f(con<> const& me,
			con<> const& other);

		static bool greater_f(con<> const& me,
			con<> const& other);

		static bool less_or_equal_f(con<> const& me,
			con<> const& other);

		static bool greater_or_equal_f(con<> const& me,
			con<> const& other);

		static void _free_f(any_a const& me);

		static void _copy_f(any_a const& me,
			any_a& copy);

		static void _no_copy_f(any_a const& me,
			any_a& copy);

		static void _set_pointer_f(var<> const& me,
			bool is_pointer);

		static bool _pointer_f(con<> const& me);

	public:
		// creators
		static var<> create_f();
		static var<> create_nothing_f();
	};
}

#endif
