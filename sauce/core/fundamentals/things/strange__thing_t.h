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
	void strange__thing_free_f(void const* const me);
	void strange__thing_copy_f(void const* const me, void* const cp);
	void strange__thing_clone_f(void const* const me, void* const cp);
	strange__symbol_a strange__thing_type_f(void const* const me);
	bool strange__thing_nothing_f(void const* const me);
	bool strange__thing_something_f(void const* const me);

	void mutate(void* const me);
	strange__any_a nothing();
	strange__any_a something();
}

#endif
