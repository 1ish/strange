#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

namespace strange
{
	struct strange__symbol_o : strange__any_o
	{
		strange__symbol_a (*add)(void const* const me /* :<symbol># */,
			void const* const suffix /* :<symbol># */);

		char const* (*to_char_star)(void const* const me /* :<symbol># */);

		int64_t (*length)(void const* const me /* :<symbol># */);

		char (*first_char)(void const* const me /* :<symbol># */);

		char (*last_char)(void const* const me /* :<symbol># */);
	};

	struct strange__symbol_a
	{
		strange__thing_d* d;
		strange__symbol_o const* o;
	};
}

#endif
