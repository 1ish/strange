#ifndef COM_ONEISH_STRANGE_SYMBOL__H
#define COM_ONEISH_STRANGE_SYMBOL__H

// ~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/symbol_.hpp > ~/source/repos/strange/sauce/strange_symbol_.h

#include "thing_.hpp"

namespace strange
{

class symbol_
{
public:
	// symbol
	inline std::size_t hash_() const;
};

} // namespace strange

#endif
