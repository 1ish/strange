#ifndef COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_DATA_A_H
#define COM_ONEISH_STRANGE_RANDOM_ACCESS_CONST_ITERATOR_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale_1.hpp -c ~/source/repos/strange/archetypes/random_access_const_iterator_data.hpp > ~/source/repos/strange/sauce/strange_random_access_const_iterator_data_a.h
*/

#include "random_access_const_iterator_forward.hpp"

namespace strange
{

template <typename _1_>
class random_access_const_iterator_data_a
{
public:
	// data
	inline _1_ const& extract() const;
	inline void mutate(_1_ const& data);
	inline _1_& reference();
};

} // namespace strange

#endif
