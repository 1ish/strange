#ifndef COM_ONEISH_STRANGE_KIND_A_H
#define COM_ONEISH_STRANGE_KIND_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ffinale.hpp -c ~/source/repos/strange/archetypes/kind.hpp > ~/source/repos/strange/sauce/strange_kind_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "flock_forward.hpp"

namespace strange
{

template <typename _1_>
class kind_a
{
public:
	// kind
	inline any_a<> aspects__(range_a<> const& _) const;
	inline flock_a<> aspects_() const;
};

} // namespace strange

#endif
