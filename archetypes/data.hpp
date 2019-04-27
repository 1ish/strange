#ifndef COM_ONEISH_STRANGE_DATA_A_H
#define COM_ONEISH_STRANGE_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived_1.hpp -c ~/source/repos/strange/archetypes/data.hpp > ~/source/repos/strange/sauce/strange_data_a.h
*/

#include "any.hpp"

namespace strange
{

template <typename _1_>
class data
{
public:
	// data
	inline const _1_& extract__() const;
	inline void mutate__(const _1_& data);
	inline _1_& reference__();
};

} // namespace strange

#endif
