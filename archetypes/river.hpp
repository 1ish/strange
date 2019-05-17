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
	lake_a_int8 getline_(number_data_a_int64 const& count, number_data_a_int8 const& delimiter);
	std::vector<int8_t> getline(int64_t count, int8_t delimiter);

	any_a<> ignore__(range_a<> const& range);
	any_a<> ignore_(number_data_a_int64 const& count);
	void ignore(int64_t count);

	any_a<> read__(range_a<> const& range);
	lake_a_int8 read_(number_data_a_int64 const& count);
	std::vector<int8_t> read(int64_t count);

	any_a<> tellg__(range_a<> const& _) const;
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

	any_a<> sync__(range_a<> const& _);
	any_a<> sync_();
	bool sync();

	// river output
	any_a<> put__(range_a<> const& range);
	any_a<> put_(number_data_a_int8 const& int_8);
	void put(int8_t int_8);

	any_a<> write__(range_a<> const& range);
	any_a<> write_(lake_a_int8 const& lake);
	void write(std::vector<int8_t> const& lake);

	any_a<> tellp__(range_a<> const& _) const;
	number_data_a_int64 tellp_() const;
	int64_t tellp() const;

	any_a<> seekp_beg__(range_a<> const& range);
	any_a<> seekp_beg_(number_data_a_int64 const& pos);
	void seekp_beg(int64_t pos);

	any_a<> seekp_end__(range_a<> const& range);
	any_a<> seekp_end_(number_data_a_int64 const& pos);
	void seekp_end(int64_t pos);

	any_a<> seekp_cur__(range_a<> const& range);
	any_a<> seekp_cur_(number_data_a_int64 const& pos);
	void seekp_cur(int64_t pos);

	any_a<> flush__(range_a<> const& _);
	any_a<> flush_();
	void flush();

	// river
	any_a<> good__(range_a<> const& _) const;
	any_a<> good_() const;
	bool good() const;

	any_a<> eof__(range_a<> const& _) const;
	any_a<> eof_() const;
	bool eof() const;

	any_a<> fail__(range_a<> const& _) const;
	any_a<> fail_() const;
	bool fail() const;

	any_a<> bad__(range_a<> const& _) const;
	any_a<> bad_() const;
	bool bad() const;

	any_a<> set_good__(range_a<> const& range);
	any_a<> set_good_(any_a<> const& value);
	void set_good(bool value);

	any_a<> set_eof__(range_a<> const& range);
	any_a<> set_eof_(any_a<> const& value);
	void set_eof(bool value);

	any_a<> set_fail__(range_a<> const& range);
	any_a<> set_fail_(any_a<> const& value);
	void set_fail(bool value);

	any_a<> set_bad__(range_a<> const& range);
	any_a<> set_bad_(any_a<> const& value);
	void set_bad(bool value);
};

} // namespace strange

#endif
