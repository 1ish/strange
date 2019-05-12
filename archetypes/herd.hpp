#ifndef COM_ONEISH_STRANGE_HERD_A_H
#define COM_ONEISH_STRANGE_HERD_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ddderived.hpp -c ~/source/repos/strange/archetypes/herd.hpp > ~/source/repos/strange/sauce/strange_herd_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class herd_a
{
public:
	// herd
	inline bool has(std::string const& s) const;
	inline bool at(std::string const& s) const;
	inline bool insert(std::string const& s);
	inline bool erase(std::string const& s);
};

} // namespace strange

#endif
