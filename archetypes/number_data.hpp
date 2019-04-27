#ifndef COM_ONEISH_STRANGE_NUMBER_DATA_A_H
#define COM_ONEISH_STRANGE_NUMBER_DATA_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/number_data.hpp > ~/source/repos/strange/sauce/strange_number_data_a.h
*/

#include "number.hpp"

namespace strange
{

template <typename _1_>
class number_data
{
public:
	// data
	inline const _1_& extract__() const;
	inline void mutate__(const _1_& data);
	inline _1_& reference__();
};

} // namespace strange

#endif
