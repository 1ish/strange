#ifndef COM_ONEISH_STRANGE_FLOCK_A_H
#define COM_ONEISH_STRANGE_FLOCK_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale.hpp -c ~/source/repos/strange/archetypes/flock.hpp > ~/source/repos/strange/sauce/strange_flock_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class flock_a
{
public:
	// flock
	inline std::vector<any_a<>> const& extract_vector() const;
	inline std::vector<any_a<>>& mutate_vector();
};

} // namespace strange

#endif
