#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

namespace strange
{
	struct symbol_o : any_o
	{
		val<symbol_a>(*add)(void const* const me /* :<symbol># */,
			void const* const suffix /* :<symbol># */);

		char const* (*to_char_star)(void const* const me /* :<symbol># */);

		int64_t (*length)(void const* const me /* :<symbol># */);

		char (*first_char)(void const* const me /* :<symbol># */);

		char (*last_char)(void const* const me /* :<symbol># */);
	};

	struct symbol_a
	{
		thing_t* t;
		symbol_o const* o;

		static val<symbol_a> cat_f(void const* const me /* :<symbol># */);
	};
}

#endif
