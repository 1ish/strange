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
	inline thing_ conform(thing_ range) const; //TODO add member version
	inline thing_ conform_(thing_ thing, thing_ cat_or_herd) const;
	inline bool conform__(thing_ thing, thing_ cat_or_herd) const;

	inline thing_ name(thing_ _) const;
	inline symbol_ name_() const;

	inline thing_ arguments(thing_ _) const;
	inline thing_ arguments_() const;

	inline thing_ parameters(thing_ _) const;
	inline thing_ parameters_() const;

	inline thing_ result(thing_ _) const;
	inline cat_ result_() const;
};

} // namespace strange

#endif
