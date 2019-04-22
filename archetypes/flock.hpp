#ifndef COM_ONEISH_STRANGE_FLOCK_A_H
#define COM_ONEISH_STRANGE_FLOCK_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/flock.hpp > ~/source/repos/strange/sauce/strange_flock_a.h
*/

#include "collection.hpp"

namespace strange
{

class flock
{
public:
	// flock
	inline bool has__(int64_t index) const;
	inline any_a at__(int64_t index) const;
	inline void update__(int64_t index, any_a value);
	inline bool insert__(int64_t index, any_a value);
	inline bool erase__(int64_t index);
};

} // namespace strange

#endif
