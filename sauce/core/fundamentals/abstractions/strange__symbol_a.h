#ifndef COM_ONEISH__STRANGE__SYMBOL_A_H
#define COM_ONEISH__STRANGE__SYMBOL_A_H

namespace strange
{
	struct symbol_o : any_o
	{
		var<symbol_a> (*add)(void const* const me_ /* :<symbol># */,
			void const* const suffix_ /* :<symbol># */);

		char const* (*to_char_star)(void const* const me_ /* :<symbol># */);

		int64_t (*length)(void const* const me_ /* :<symbol># */);

		char (*first_char)(void const* const me_ /* :<symbol># */);

		char (*last_char)(void const* const me_ /* :<symbol># */);
	};

	struct symbol_a
	{
		using operations = symbol_o;
		thing_t* t;
		operations const* o;

		static var<symbol_a> cat_e(void const* const me_ /* :<symbol># */);

		using creator = var<symbol_a>(*)();
		static creator creator_f(void const* const scope_ /* :<symbol># */,
			void const* const thing_ /* :<symbol># */,
			void const* const function_ /* :<symbol># */);
	};
}

#endif
