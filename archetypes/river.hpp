#ifndef COM_ONEISH_STRANGE_RIVER_A_H
#define COM_ONEISH_STRANGE_RIVER_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/dderived.hpp -c ~/source/repos/strange/archetypes/river.hpp > ~/source/repos/strange/sauce/strange_river_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename number_data_a_int8, typename number_data_a_int64>
class river_a
{
public:
	// river input
	int8_t get();
	
	int8_t peek();

	void unget();

	void putback(int8_t char8);

	std::vector<int8_t> getline(int64_t count = -1, int8_t delim = '\n');

	void ignore(int64_t count = 1);

	std::vector<int8_t> read(int64_t count = -1);

	// river output


};

} // namespace strange

#endif
