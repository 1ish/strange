#ifndef COM_ONEISH_STRANGE_CAT_A_H
#define COM_ONEISH_STRANGE_CAT_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/cat.hpp > ~/source/repos/strange/sauce/strange_cat_a.h
*/

#include "symbol.hpp"

namespace strange
{

class cat
{
public:
	// cat
	inline symbol_a name(any_a const& _) const;
	inline symbol_a name_() const;

	inline any_a arguments(any_a const& _) const;
	inline any_a arguments_() const;

	inline any_a parameters(any_a const& _) const;
	inline any_a parameters_() const;

	inline cat_a result(any_a const& _) const;
	inline cat_a result_() const;

	inline any_a includes(any_a const& range) const;
	inline any_a includes_(any_a const& thing) const;
	inline bool includes__(any_a const& thing) const;

	inline any_a conforms(any_a const& range) const;
	inline any_a conforms_(any_a const& thing, any_a const& cat_or_herd) const;
	inline bool conforms__(any_a const& thing, any_a const& cat_or_herd) const;
};

} // namespace strange

#endif
