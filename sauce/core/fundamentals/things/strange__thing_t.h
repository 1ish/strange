#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

#include <atomic>

namespace strange
{
	struct thing_t
	{
		std::atomic_int64_t refs;
		any_a error;

	protected:
		thing_t(void* const me /* :<any>= */);

		thing_t(void* const me /* :<any>= */,
			void const* const original /* :<any># */);

		virtual ~thing_t();

		// any_o
		static any_o const* operations_f();
		static any_o const* pointer_operations_f();

		// init
		static void init_f(void* const me /* :<any>= */);

		// any_a
		static void _free_f(void* const me /* :<any># */);

		static void _copy_f(void const* const me /* :<any># */,
			void* const cp /* :<any>= */);

		static void _clone_f(void const* const me /* :<any># */,
			void* const cp /* :<any>= */);

		static void _no_copy_f(void const* const me /* :<any># */,
			void* const cp /* :<any>= */);

		static bool is_f(void const* const me /* :<any># */,
			void const* const ab /* :<any># */);

		static bool as_f(void const* const me /* :<any># */,
			void* const ab /* :<any>= */);

		static void _as_f(void const* const me /* :<any># */,
			void* const ab /* :<any>= */);

		static var<symbol_a> type_f(void const* const me /* :<any># */);

		static void _set_pointer_f(void* const me /* :<any>= */,
			bool is_pointer /* :_bool_# */);

		static bool _pointer_f(void const* const me /* :<any># */);

		static void set_something_f(void* const me /* :<any>= */,
			bool is_something /* :_bool_# */);

		static bool something_f(void const* const me /* :<any># */);

		static void set_error_f(void* const me /* :<any>= */,
			void const* const error /* :<any># */);

		static var<any_a> error_f(void const* const me /* :<any># */);

		static uint64_t hash_f(void const* const me /* :<any># */);

		static bool equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool _equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool not_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool _not_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool less_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool _less_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool greater_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool _greater_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool less_or_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool _less_or_equal_f(void const* const me /* :<any># */,
			void const* const other /*: <any># */);

		static bool greater_or_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool _greater_or_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

	public:
		// creators
		static var<any_a> create_f();
		static var<any_a> create_nothing_f();
	};
}

#endif
