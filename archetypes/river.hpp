#ifndef COM_ONEISH_STRANGE_RIVER_A_H
#define COM_ONEISH_STRANGE_RIVER_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/dderived.hpp -c ~/source/repos/strange/archetypes/river.hpp > ~/source/repos/strange/sauce/strange_river_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename number_data_a_int8, typename number_data_a_int64, typename lake_a_int8>
class river_a
{
public:
	// river input
	any_a<> get__(range_a<> const& _);
	number_data_a_int8 get_();
	int8_t get();
	
	any_a<> peek__(range_a<> const& _);
	number_data_a_int8 peek_();
	int8_t peek();

	any_a<> unget__(range_a<> const& _);
	any_a<> unget_();
	void unget();

	any_a<> putback__(range_a<> const& range);
	any_a<> putback_(number_data_a_int8 const& int_8);
	void putback(int8_t int_8);

	any_a<> getline__(range_a<> const& range);
	lake_a_int8 getline_(number_data_a_int64 const& count, number_data_a_int8 const& delim);
	std::vector<int8_t> getline(int64_t count = -1, int8_t delim = '\n');

	any_a<> ignore__(range_a<> const& range);
	any_a<> ignore_(number_data_a_int64 const& count);
	void ignore(int64_t count = 1);

	any_a<> read__(range_a<> const& range);
	lake_a_int8 read_(number_data_a_int64 const& count);
	std::vector<int8_t> read(int64_t count = -1);

	any_a<> tellg__(range_a<> const& range) const;
	number_data_a_int64 tellg_() const;
	int64_t tellg() const;

	any_a<> seekg_beg__(range_a<> const& range);
	any_a<> seekg_beg_(number_data_a_int64 const& pos);
	void seekg_beg(int64_t pos);

	any_a<> seekg_end__(range_a<> const& range);
	any_a<> seekg_end_(number_data_a_int64 const& pos);
	void seekg_end(int64_t pos);

	any_a<> seekg_cur__(range_a<> const& range);
	any_a<> seekg_cur_(number_data_a_int64 const& pos);
	void seekg_cur(int64_t pos);

	// river output


};

} // namespace strange

#endif
