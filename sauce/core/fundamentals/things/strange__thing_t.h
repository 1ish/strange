#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

namespace strange
{
	struct thing_t
	{
		std::atomic_int64_t refs;
		any_a error;

	protected:
		thing_t(any_a& me /* :<any>= */);

		thing_t(any_a& me /* :<any>= */,
			any_a const& original /* :<any># */);

		thing_t(thing_t const&) = delete;

		thing_t& operator=(thing_t const&) = delete;

		virtual ~thing_t();

	private:
		// any_o
		static any_o const* operations_f();
		static any_o const* pointer_operations_f();

	protected:
		// inline
		static inline void _initialise_f(any_a& me /* :<any>= */)
		{
		}

		static inline void _clone_f(any_a const& me /* :<any># */,
			any_a& copy /* :<any>= */)
		{
		}

	public:
		static inline bool _equal_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t == other.t;
		}

		static inline bool _not_equal_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t != other.t;
		}

		static inline bool _less_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t < other.t;
		}

		static inline bool _greater_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t > other.t;
		}

		static inline bool _less_or_equal_f(con<> const& me /* :<any># */,
			con<> const& other /*: <any># */)
		{
			return me.t <= other.t;
		}

		static inline bool _greater_or_equal_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t >= other.t;
		}

	protected:
		// any_a
		static bool is_f(con<> const& me /* :<any># */,
			con<> const& abstraction /* :<any># */);

		static bool as_f(con<> const& me /* :<any># */,
			var<> const& abstraction /* :<any>= */);

		static var<symbol_a> type_f(con<> const& me /* :<any># */);

		static void set_something_f(var<> const& me /* :<any>= */,
			bool is_something /* :_bool_# */);

		static bool something_f(con<> const& me /* :<any># */);

		static void set_error_f(var<> const& me /* :<any>= */,
			con<> const& error /* :<any># */);

		static var<> error_f(con<> const& me /* :<any># */);

		static uint64_t hash_f(con<> const& me /* :<any># */);

		static bool equal_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool not_equal_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool less_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool greater_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool less_or_equal_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool greater_or_equal_f(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static void _free_f(any_a const& me /* :<any>= */);

		static void _copy_f(any_a const& me /* :<any># */,
			any_a& copy /* :<any>= */);

		static void _no_copy_f(any_a const& me /* :<any># */,
			any_a& copy /* :<any>= */);

		static void _set_pointer_f(var<> const& me /* :<any>= */,
			bool is_pointer /* :_bool_# */);

		static bool _pointer_f(con<> const& me /* :<any># */);

	public:
		// creators
		static var<> create_f();
		static var<> create_nothing_f();
	};
}

#endif
