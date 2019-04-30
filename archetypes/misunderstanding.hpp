#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/misunderstanding.hpp > ~/source/repos/strange/sauce/strange_misunderstanding_a.h
*/

#include "any.hpp"

namespace strange
{

class misunderstanding_a
{
public:
	// misunderstanding
	inline std::string const& to_string__() const;

	inline misunderstanding_a add(any_a<> const& range) const;
	inline misunderstanding_a add_(misunderstanding_a const& misunderstanding) const;
	inline misunderstanding_a operator+(misunderstanding_a const& misunderstanding) const;
};

} // namespace strange

#endif
