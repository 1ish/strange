#ifndef COM_ONEISH_STRANGE_FLOCK_A_H
#define COM_ONEISH_STRANGE_FLOCK_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ffinale.hpp -c ~/source/repos/strange/archetypes/flock.hpp > ~/source/repos/strange/sauce/strange_flock_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename random_access_iterator_a>
class flock_a
{
public:
	// flock
	inline bool has(int64_t index) const;
	inline any_a<> at(int64_t index) const;
	inline void update(int64_t index, any_a<> const& value);
	inline bool insert(int64_t index, any_a<> const& value);
	inline bool erase(int64_t index);

	// mutable range
	inline any_a<> begin__(range_a<> const& _);
	inline random_access_iterator_a begin_();
	inline random_access_iterator_a begin();

	inline any_a<> end__(range_a<> const& _);
	inline random_access_iterator_a end_();
	inline random_access_iterator_a end();

	// data
	inline std::vector<any_a<>> const& extract() const;
	inline void mutate(std::vector<any_a<>> const& data);
	inline std::vector<any_a<>>& reference();
};

} // namespace strange

#endif
