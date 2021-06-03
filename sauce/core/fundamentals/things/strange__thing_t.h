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
		static inline void _initialise_m(any_a& me /* :<any>= */)
		{
		}

		static inline void _clone_e(any_a const& me /* :<any># */,
			any_a& copy /* :<any>= */)
		{
		}

	public:
		static inline bool _equal_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t == other.t;
		}

		static inline bool _not_equal_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t != other.t;
		}

		static inline bool _less_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t < other.t;
		}

		static inline bool _greater_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t > other.t;
		}

		static inline bool _less_or_equal_e(con<> const& me /* :<any># */,
			con<> const& other /*: <any># */)
		{
			return me.t <= other.t;
		}

		static inline bool _greater_or_equal_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */)
		{
			return me.t >= other.t;
		}

	protected:
		// any_a
		static bool is_e(con<> const& me /* :<any># */,
			con<> const& abstraction /* :<any># */);

		static bool as_e(con<> const& me /* :<any># */,
			var<> const& abstraction /* :<any>= */);

		static var<symbol_a> type_e(con<> const& me /* :<any># */);

		static void set_something_m(var<> const& me /* :<any>= */,
			bool is_something /* :_bool_# */);

		static bool something_e(con<> const& me /* :<any># */);

		static void set_error_m(var<> const& me /* :<any>= */,
			con<> const& error /* :<any># */);

		static var<> error_e(con<> const& me /* :<any># */);

		static uint64_t hash_e(con<> const& me /* :<any># */);

		static bool equal_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool not_equal_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool less_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool greater_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool less_or_equal_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static bool greater_or_equal_e(con<> const& me /* :<any># */,
			con<> const& other /* :<any># */);

		static void _free_m(any_a const& me /* :<any>= */);

		static void _copy_e(any_a const& me /* :<any># */,
			any_a& copy /* :<any>= */);

		static void _no_copy_e(any_a const& me /* :<any># */,
			any_a& copy /* :<any>= */);

		static void _set_pointer_m(var<> const& me /* :<any>= */,
			bool is_pointer /* :_bool_# */);

		static bool _pointer_e(con<> const& me /* :<any># */);

	public:
		// creators
		static var<> create_f();
		static var<> create_nothing_f();
	};
}

#endif
