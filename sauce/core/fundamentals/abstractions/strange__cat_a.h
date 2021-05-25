#ifndef COM_ONEISH__STRANGE__CAT_A_H
#define COM_ONEISH__STRANGE__CAT_A_H

namespace strange
{
	struct cat_o : symbol_o
	{
		int64_t (*order)(void const* const me_ /* :<cat># */);

		var<symbol_a> (*name)(void const* const me_ /* :<cat># */);

		//TODO var<flock_a<cat_a>> (*aspects)(void const* const me_ /* :<cat># */);
	};

	struct cat_a
	{
		using operations = cat_o;
		thing_t* t;
		operations const* o;

		static var<symbol_a> cat_e(void const* const me_ /* :<cat># */);

		using creator = var<cat_a>(*)();
		static creator creator_f(void const* const scope_ /* :<symbol># */,
			void const* const thing_ /* :<symbol># */,
			void const* const function_ /* :<symbol># */);
	};
}

#endif
