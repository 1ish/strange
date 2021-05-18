#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

namespace strange
{
	struct thing_d
	{
		int64_t refs;
		any_a error;

		// any_o
		static any_o const* thing_o_f();
		static any_o const* thing_p_f();

		// init
		static void thing__init_f(void* const me /* :<any>= */);

		// any_a
		static void thing___free_f(void const* const me /* :<any># */);

		static void thing___copy_f(void const* const me /* :<any># */,
			void* const cp /* :<any>= */);

		static void thing___clone_f(void const* const me /* :<any># */,
			void* const cp /* :<any>= */);

		static void thing___no_copy_f(void const* const me /* :<any># */,
			void* const cp /* :<any>= */);

		static bool thing__is_f(void const* const me /* :<any># */,
			void const* const ab /* :<any># */);

		static bool thing__as_f(void const* const me /* :<any># */,
			void* const ab /* :<any>= */);

		static void thing___as_f(void const* const me /* :<any># */,
			void* const ab /* :<any>= */);

		static symbol_a thing__type_f(void const* const me /* :<any># */);

		static void thing___set_pointer_f(void* const me /* :<any>= */,
			bool is_pointer /* :_bool_# */);

		static bool thing___pointer_f(void const* const me /* :<any># */);

		static void thing__set_something_f(void* const me /* :<any>= */,
			bool is_something /* :_bool_# */);

		static bool thing__something_f(void const* const me /* :<any># */);

		static void thing__set_error_f(void* const me /* :<any>= */,
			void const* const error /* :<any># */);

		static any_a thing__error_f(void const* const me /* :<any># */);

		static uint64_t thing__hash_f(void const* const me /* :<any># */);

		static bool thing__equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing___equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing__not_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing___not_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing__less_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing___less_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing__greater_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing___greater_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing__less_or_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing___less_or_equal_f(void const* const me /* :<any># */,
			void const* const other /*: <any># */);

		static bool thing__greater_or_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		static bool thing___greater_or_equal_f(void const* const me /* :<any># */,
			void const* const other /* :<any># */);

		// creators
		static any_a thing__create_f();
		static any_a thing__create_nothing_f();
	};
}

#endif
