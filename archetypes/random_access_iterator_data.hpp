#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_DATA_A_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_ITERATOR_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/random_access_iterator_data.hpp > ~/source/repos/strange/sauce/strange_random_access_iterator_data_a.h
*/

#include "random_access_iterator.hpp"

namespace strange
{

template <typename _1_>
class random_access_iterator_data
{
public:
	// data
	inline const _1_& extract__() const;
	inline void mutate__(const _1_& data);
	inline _1_& reference__();
};

} // namespace strange

#endif
