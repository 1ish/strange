#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/misunderstanding.hpp > ~/source/repos/strange/sauce/strange_misunderstanding_a.h
*/

#include "any.hpp"

namespace strange
{

class misunderstanding
{
public:
	// symbol
	inline const std::string& to_string__() const;

	inline symbol_a add(any_a range) const;
	inline symbol_a add_(symbol_a symbol) const;
	inline symbol_a operator+(symbol_a symbol) const;
};

} // namespace strange

#endif
