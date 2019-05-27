#ifndef COM_ONEISH_STRANGE_INVENTORY_A_H
#define COM_ONEISH_STRANGE_INVENTORY_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ddderived.hpp -c ~/source/repos/strange/archetypes/inventory.hpp > ~/source/repos/strange/sauce/strange_inventory_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "random_access_iterator_forward.hpp"

namespace strange
{

template <typename _1_>
class inventory_a
{
public:
	// inventory
	inline bool has(int64_t index) const;
	inline any_a<> at(int64_t index) const;
	inline void update(int64_t index, any_a<> const& value);
	inline bool insert(int64_t index, any_a<> const& value);
	inline bool erase(int64_t index);

	// mutable range
	inline any_a<> begin__(range_a<> const& _);
	inline random_access_iterator_a<> begin_();
	inline random_access_iterator_a<> begin();

	inline any_a<> end__(range_a<> const& _);
	inline random_access_iterator_a<> end_();
	inline random_access_iterator_a<> end();
};

} // namespace strange

#endif
