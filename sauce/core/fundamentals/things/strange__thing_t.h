#ifndef COM_ONEISH__STRANGE__THING_T_H
#define COM_ONEISH__STRANGE__THING_T_H

#define STRANGE__THING_D \
		int64_t refs; \

extern "C"
{
	struct strange__thing_d
	{
		STRANGE__THING_D
	};

	// any_o
	strange__any_o const* strange__thing_o_f();
	strange__any_o const* strange__thing_p_f();
	strange__any_o const* strange__thing_n_f();

	// any_a
	void strange__thing___free_f(void const* const me /* <any># */);

	void strange__thing___copy_f(void const* const me /* <any># */,
		void* const cp /* <any>= */);

	void strange__thing___no_copy_f(void const* const me /* <any># */,
		void* const cp /* <any>= */);

	bool strange__thing__is_f(void const* const me /* <any># */,
		void const* const ab /* <any># */);

	bool strange__thing__as_f(void const* const me /* <any># */,
		void* const ab /* <any>= */);

	void strange__thing___as_f(void const* const me /* <any># */,
		void* const ab /* <any>= */);

	strange__symbol_a strange__thing__type_f(void const* const me /* <any># */);

	bool strange__thing__something_f(void const* const me /* <any># */);

	bool strange__thing__nothing_f(void const* const me /* <any># */);

	bool strange__thing__equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing___equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing__not_equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing___not_equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing__less_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing___less_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing__greater_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing___greater_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing__less_or_equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing___less_or_equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing__greater_or_equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	bool strange__thing___greater_or_equal_f(void const* const me /* <any># */,
		void const* const other /* <any># */);

	void mutate(void* const me /* <any># */);

	// constructors
	strange__any_a strange__something();
	strange__any_a strange__nothing();
}

#endif
