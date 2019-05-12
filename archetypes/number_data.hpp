#ifndef COM_ONEISH_STRANGE_NUMBER_DATA_A_H
#define COM_ONEISH_STRANGE_NUMBER_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/number_data.hpp > ~/source/repos/strange/sauce/strange_number_data_a.h
*/

#include "any_forward.hpp"
#include "number_forward.hpp"

namespace strange
{

template <typename _1_>
class number_data_a
{
public:
	// number data
	inline _1_ const& extract() const;
	inline void mutate(_1_ const& data);
	inline _1_& reference();
};

} // namespace strange

#endif
