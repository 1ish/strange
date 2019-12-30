#ifndef COM_ONEISH_STRANGE_ORDERED_HERD_A_H
#define COM_ONEISH_STRANGE_ORDERED_HERD_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale.hpp -c ~/source/repos/strange/archetypes/ordered_herd.hpp > ~/source/repos/strange/sauce/strange_ordered_herd_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class ordered_herd_a
{
public:
	// ordered herd
	inline std::set<any_a<>> const& extract_set() const;
	inline std::set<any_a<>>& mutate_set();
};

} // namespace strange

#endif
