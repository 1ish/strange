#ifndef COM_ONEISH_STRANGE_ORDERED_SHOAL_A_H
#define COM_ONEISH_STRANGE_ORDERED_SHOAL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale.hpp -c ~/source/repos/strange/archetypes/ordered_shoal.hpp > ~/source/repos/strange/sauce/strange_ordered_shoal_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class ordered_shoal_a
{
public:
	// ordered shoal
	inline std::map<any_a<>, any_a<>> const& extract_ordered_map() const;
	inline std::map<any_a<>, any_a<>>& mutate_ordered_map();
};

} // namespace strange

#endif
