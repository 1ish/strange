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
		thing_t(void* const me_ /* :<any>= */);

		thing_t(void* const me_ /* :<any>= */,
			void const* const original_ /* :<any># */);

		virtual ~thing_t();

		// any_o
		static any_o const* operations_f();
		static any_o const* pointer_operations_f();

		// inline
		static inline void _init_f(void* const me_ /* :<any>= */)
		{
		}

		static inline void _clone_f(void const* const me_ /* :<any># */,
			void* const copy_ /* :<any>= */)
		{
		}

		// any_a
		static void _free_m(void* const me_ /* :<any># */);

		static void _copy_e(void const* const me_ /* :<any># */,
			void* const copy_ /* :<any>= */);

		static void _no_copy_e(void const* const me_ /* :<any># */,
			void* const copy_ /* :<any>= */);

		static bool is_e(void const* const me_ /* :<any># */,
			void const* const abstraction_ /* :<any># */);

		static bool as_e(void const* const me_ /* :<any># */,
			void* const abstraction_ /* :<any>= */);

		static void _as_e(void const* const me_ /* :<any># */,
			void* const abstraction_ /* :<any>= */);

		static var<symbol_a> type_e(void const* const me_ /* :<any># */);

		static void _set_pointer_m(void* const me_ /* :<any>= */,
			bool is_pointer /* :_bool_# */);

		static bool _pointer_e(void const* const me_ /* :<any># */);

		static void set_something_m(void* const me_ /* :<any>= */,
			bool is_something /* :_bool_# */);

		static bool something_e(void const* const me_ /* :<any># */);

		static void set_error_m(void* const me_ /* :<any>= */,
			void const* const error_ /* :<any># */);

		static var<any_a> error_e(void const* const me_ /* :<any># */);

		static uint64_t hash_e(void const* const me_ /* :<any># */);

		static bool equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool _equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool not_equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool _not_equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool less_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool _less_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool greater_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool _greater_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool less_or_equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool _less_or_equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /*: <any># */);

		static bool greater_or_equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

		static bool _greater_or_equal_e(void const* const me_ /* :<any># */,
			void const* const other_ /* :<any># */);

	public:
		// creators
		static var<any_a> create_f();
		static var<any_a> create_nothing_f();
	};
}

#endif
