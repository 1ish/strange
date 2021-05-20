#ifndef COM_ONEISH__STRANGE__SYMBOL_T_H
#define COM_ONEISH__STRANGE__SYMBOL_T_H

namespace strange
{
	struct symbol_t : thing_t
	{
		char* symbol;
		int64_t length;
		uint64_t hash;

	protected:
		symbol_t(void* const me_ /* :<symbol>= */,
			char const* const s /* :_char_star_# */);

		symbol_t(void* const me_ /* :<symbol>= */,
			void const* const original /* :<symbol># */);

		virtual ~symbol_t();

		// symbol_o
		static symbol_o const* operations_f();
		static symbol_o const* pointer_operations_f();

		// any_a
		static void _copy_e(void const* const me_ /* :<symbol># */,
			void* const cp /* :<symbol>= */);

		static bool is_e(void const* const me_ /* :<symbol># */,
			void const* const ab /* :<any># */);

		static bool as_e(void const* const me_ /* :<symbol># */,
			void* const ab /* :<any>= */);

		static var<symbol_a> type_e(void const* const me_ /* :<symbol># */);

		static void _set_pointer_m(void* const me_ /* :<symbol>= */,
			bool is_pointer /* :_bool_# */);

		static bool _pointer_e(void const* const me_ /* :<symbol># */);

		static uint64_t hash_e(void const* const me_ /* :<symbol># */);

		static bool equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool not_equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _not_equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool less_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _less_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool greater_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _greater_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool less_or_equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _less_or_equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<symbol># */);

		static bool greater_or_equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<any># */);

		static bool _greater_or_equal_e(void const* const me_ /* :<symbol># */,
			void const* const other /* :<symbol># */);

		// symbol_a
		static var<symbol_a> add_e(void const* const me_ /* :<symbol># */,
			void const* const suffix /* :<symbol># */);

		static char const* to_char_star_e(void const* const me_ /* :<symbol># */);

		static int64_t length_e(void const* const me_ /* :<symbol># */);

		static char first_char_e(void const* const me_ /* :<symbol># */);

		static char last_char_e(void const* const me_ /* :<symbol># */);

	public:
		// creators
		static var<symbol_a> create_f(char const* const s /* :_char_star_# */);
		static var<symbol_a> create_empty_f();
	};
}

#endif
