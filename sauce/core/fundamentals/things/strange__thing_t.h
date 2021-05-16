#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

#define STRANGE__THING_D \
		int64_t refs; \
		strange__any_a error; \

extern "C"
{
	struct strange__thing_d
	{
		STRANGE__THING_D
	};

	// any_o
	strange__any_o const* strange__thing_o_f();
	strange__any_o const* strange__thing_p_f();

	// init
	void strange__thing_init_f(void* const me /* :<any>= */);

	// any_a
	void strange__thing___free_f(void const* const me /* :<any># */);

	void strange__thing___copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */);

	void strange__thing___clone_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */);

	void strange__thing___no_copy_f(void const* const me /* :<any># */,
		void* const cp /* :<any>= */);

	bool strange__thing__is_f(void const* const me /* :<any># */,
		void const* const ab /* :<any># */);

	bool strange__thing__as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */);

	void strange__thing___as_f(void const* const me /* :<any># */,
		void* const ab /* :<any>= */);

	strange__symbol_a strange__thing__type_f(void const* const me /* :<any># */);

	void strange__thing___set_pointer_f(void* const me /* :<any>= */,
		bool is_pointer /* :_bool_# */);

	bool strange__thing___pointer_f(void const* const me /* :<any># */);

	void strange__thing__set_something_f(void* const me /* :<any>= */,
		bool is_something /* :_bool_# */);

	bool strange__thing__something_f(void const* const me /* :<any># */);

	void strange__thing__set_error_f(void* const me /* :<any>= */,
		void const* const error /* :<any># */);

	strange__any_a strange__thing__error_f(void const* const me /* :<any># */);

	uint64_t strange__thing__hash_f(void const* const me /* :<any># */);

	bool strange__thing__equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing___equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing__not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing___not_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing__less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing___less_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing__greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing___greater_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing__less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing___less_or_equal_f(void const* const me /* :<any># */,
		void const* const other /*: <any># */);

	bool strange__thing__greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	bool strange__thing___greater_or_equal_f(void const* const me /* :<any># */,
		void const* const other /* :<any># */);

	// constructors
	strange__any_a strange__thing();
	strange__any_a strange__nothing();
}

#endif
