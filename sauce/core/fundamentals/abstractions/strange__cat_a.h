#ifndef COM_ONEISH__STRANGE__CAT_A_H
#define COM_ONEISH__STRANGE__CAT_A_H

namespace strange
{
	struct cat_o : symbol_o
	{
		var<symbol_a>(*name)(con<cat_a> const& me);

		representation_e (*representation)(con<cat_a> const& me);

		//TODO var<flock_a<cat_a>> (*aspects)(con<cat_a> const& me);

		int64_t (*order)(con<cat_a> const& me);

		// abstraction  <symbol>
		// aspect       <^element>
		// native       <+bool>
		// enumeration  <|behaviour>
	};

	struct cat_a
	{
		using operations = cat_o;
		using creator_fp = var<cat_a>(*)();

		mutable thing_t* t;
		mutable operations const* o;

		static var<symbol_a> cat(con<> const& me); //TODO cat

		static creator_fp creator(con<symbol_a> const& scope,
			con<symbol_a> const& thing,
			con<symbol_a> const& function);
	};
}

#endif
