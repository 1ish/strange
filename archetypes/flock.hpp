#ifndef COM_ONEISH_STRANGE_FLOCK_A_H
#define COM_ONEISH_STRANGE_FLOCK_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/flock.hpp > ~/source/repos/strange/sauce/strange_flock_a.h
*/

#include "collection.hpp"

namespace strange
{

template <typename _1_ = void>
class flock_a
{
public:
	// flock
	inline bool has__(int64_t index) const;
	inline any_a<> at__(int64_t index) const;
	inline void update__(int64_t index, any_a<> const& value);
	inline bool insert__(int64_t index, any_a<> const& value);
	inline bool erase__(int64_t index);

	// data
	inline std::vector<any_a<>> const& extract__() const;
	inline void mutate__(std::vector<any_a<>> const& data);
	inline std::vector<any_a<>>& reference__();
};

} // namespace strange

#endif
