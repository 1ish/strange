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

	strange__any_o const* strange__thing_o_f();
	strange__any_o const* strange__thing_p_f();
	strange__any_o const* strange__thing_n_f();
	void strange__thing_free_f(void const* const me);
	void strange__thing_copy_f(void const* const me, void* const cp);
	void strange__thing_no_copy_f(void const* const me, void* const cp);
	bool strange__thing_is_f(void const* const me, void const* const at);
	bool strange__thing_as_f(void const* const me, void* const at);
	strange__symbol_a strange__thing_type_f(void const* const me);
	bool strange__thing_something_f(void const* const me);
	bool strange__thing_nothing_f(void const* const me);

	void mutate(void* const me);
	strange__any_a something();
	strange__any_a nothing();
}

#endif
