#ifndef COM_ONEISH_STRANGE_LAKE_A_H
#define COM_ONEISH_STRANGE_LAKE_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ddderived.hpp -c ~/source/repos/strange/archetypes/lake.hpp > ~/source/repos/strange/sauce/strange_lake_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename random_access_iterator_a>
class lake_a
{
public:
	// lake
	inline bool has(int64_t index) const;
	inline any_a<> at(int64_t index) const;
	inline void update(int64_t index, any_a<> const& value);
	inline bool insert(int64_t index, any_a<> const& value);
	inline bool erase(int64_t index);

	// mutable range
	inline any_a<> beset__(range_a<> const& _);
	inline random_access_iterator_a beset_();
	inline random_access_iterator_a begin();

	inline any_a<> enset__(range_a<> const& _);
	inline random_access_iterator_a enset_();
	inline random_access_iterator_a end();
};

} // namespace strange

#endif
