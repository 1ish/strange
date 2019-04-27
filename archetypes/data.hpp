#ifndef COM_ONEISH_STRANGE_DATA_A_H
#define COM_ONEISH_STRANGE_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived_data.hpp -c ~/source/repos/strange/archetypes/data.hpp > ~/source/repos/strange/sauce/strange_data_a.h
*/

#include "any.hpp"

namespace strange
{

template <typename DATA>
class data
{
public:
	// data
	inline const DATA& extract__() const;
	inline void mutate__(const DATA& data);
	inline DATA& reference__();
};

} // namespace strange

#endif
