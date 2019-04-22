#ifndef COM_ONEISH_STRANGE_HERD_A_H
#define COM_ONEISH_STRANGE_HERD_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/herd.hpp > ~/source/repos/strange/sauce/strange_herd_a.h
*/

#include "collection.hpp"

namespace strange
{

class herd
{
public:
	// herd
	inline bool has__(const std::string& s) const;
	inline bool at__(const std::string& s) const;
	inline bool insert__(const std::string& s);
	inline bool erase__(const std::string& s);
};

} // namespace strange

#endif
