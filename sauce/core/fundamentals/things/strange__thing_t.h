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
	void strange__thing___free_f(void const* const me);
	void strange__thing___copy_f(void const* const me, void* const cp);
	void strange__thing___no_copy_f(void const* const me, void* const cp);
	bool strange__thing__is_f(void const* const me, void const* const ab);
	void strange__thing__as_f(void const* const me, void* const ab);
	strange__symbol_a strange__thing__type_f(void const* const me);
	bool strange__thing__something_f(void const* const me);
	bool strange__thing__nothing_f(void const* const me);

	void mutate(void* const me);
	strange__any_a something();
	strange__any_a nothing();
}

#endif
