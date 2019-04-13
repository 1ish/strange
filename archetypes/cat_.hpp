#ifndef COM_ONEISH_STRANGE_CAT__H
#define COM_ONEISH_STRANGE_CAT__H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/cat_.hpp > ~/source/repos/strange/sauce/strange_cat_.h
*/

#include "symbol_.hpp"

namespace strange
{

class cat_
{
public:
	// cat
	inline thing_ name(thing_ _) const;
	inline symbol_ name_() const;

	inline thing_ arguments(thing_ _) const;
	inline thing_ arguments_() const;

	inline thing_ parameters(thing_ _) const;
	inline thing_ parameters_() const;

	inline thing_ result(thing_ _) const;
	inline cat_ result_() const;

	inline thing_ includes(thing_ range) const;
	inline thing_ includes_(thing_ thing) const;
	inline bool includes__(thing_ thing) const;

	inline thing_ conforms(thing_ range) const;
	inline thing_ conforms_(thing_ thing, thing_ cat_or_herd) const;
	inline bool conforms__(thing_ thing, thing_ cat_or_herd) const;
};

} // namespace strange

#endif
