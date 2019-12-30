#ifndef COM_ONEISH_STRANGE_DATA_A_H
#define COM_ONEISH_STRANGE_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived_1.hpp -c ~/source/repos/strange/archetypes/data.hpp > ~/source/repos/strange/sauce/strange_data_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class data_a
{
public:
	// data
	inline _1_ const& extract_data() const;
	inline _1_& mutate_data();
};

} // namespace strange

#endif
