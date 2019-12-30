#ifndef COM_ONEISH_STRANGE_UNORDERED_HERD_A_H
#define COM_ONEISH_STRANGE_UNORDERED_HERD_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale.hpp -c ~/source/repos/strange/archetypes/unordered_herd.hpp > ~/source/repos/strange/sauce/strange_unordered_herd_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class unordered_herd_a
{
public:
	// unordered herd
	inline std::unordered_set<any_a<>, any_a<>::hash_f> const& extract_unordered_set() const;
	inline std::unordered_set<any_a<>, any_a<>::hash_f>& mutate_unordered_set();
};

} // namespace strange

#endif
