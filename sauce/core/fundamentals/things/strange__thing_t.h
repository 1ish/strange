#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

namespace strange
{
	struct thing_t
	{
		std::atomic_int64_t refs;
		any_a error;

	protected:
		thing_t(any_a& me_ /* :<any>= */);

		thing_t(any_a& me_ /* :<any>= */,
			any_a const& original_ /* :<any># */);

		virtual ~thing_t();

		// any_o
		static any_o const* operations_f();
		static any_o const* pointer_operations_f();

		// inline
		static inline void _initialise_m(any_a& me_ /* :<any>= */)
		{
		}

		static inline void _clone_e(any_a const& me_ /* :<any># */,
			any_a& copy_ /* :<any>= */)
		{
		}

		static inline void _repoint_m(var<>& after_ /* :<any>= */,
			bool pointer_before /* :_bool_# */,
			bool pointer_after /* :_bool_# */)
		{
			if (pointer_after != pointer_before)
			{
				if (pointer_after)
				{
					after_.mut();
					after_.o->_set_pointer(after_, true);
				}
				else
				{
					after_.o->_set_pointer(after_, false);
					after_.mut();
				}
			}
		}

		static inline bool _equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */)
		{
			return me_.t == other_.t;
		}

		static inline bool _not_equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */)
		{
			return me_.t != other_.t;
		}

		static inline bool _less_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */)
		{
			return me_.t < other_.t;
		}

		static inline bool _greater_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */)
		{
			return me_.t > other_.t;
		}

		static inline bool _less_or_equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /*: <any># */)
		{
			return me_.t <= other_.t;
		}

		static inline bool _greater_or_equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */)
		{
			return me_.t >= other_.t;
		}

		// any_a
		static void _free_m(any_a& me_ /* :<any>= */);

		static void _copy_e(any_a const& me_ /* :<any># */,
			any_a& copy_ /* :<any>= */);

		static void _no_copy_e(any_a const& me_ /* :<any># */,
			any_a& copy_ /* :<any>= */);

		static bool is_e(val<> const& me_ /* :<any># */,
			val<> const& abstraction_ /* :<any># */);

		static bool as_e(val<> const& me_ /* :<any># */,
			var<>& abstraction_ /* :<any>= */);

		static var<symbol_a> type_e(val<> const& me_ /* :<any># */);

		static void _set_pointer_m(var<>& me_ /* :<any>= */,
			bool is_pointer /* :_bool_# */);

		static bool _pointer_e(val<> const& me_ /* :<any># */);

		static void set_something_m(var<>& me_ /* :<any>= */,
			bool is_something /* :_bool_# */);

		static bool something_e(val<> const& me_ /* :<any># */);

		static void set_error_m(var<>& me_ /* :<any>= */,
			val<> const& error_ /* :<any># */);

		static var<> error_e(val<> const& me_ /* :<any># */);

		static uint64_t hash_e(val<> const& me_ /* :<any># */);

		static bool equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */);

		static bool not_equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */);

		static bool less_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */);

		static bool greater_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */);

		static bool less_or_equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */);

		static bool greater_or_equal_e(val<> const& me_ /* :<any># */,
			val<> const& other_ /* :<any># */);

	public:
		// creators
		static var<> create_f();
		static var<> create_nothing_f();
	};
}

#endif
