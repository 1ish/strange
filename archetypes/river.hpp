#ifndef COM_ONEISH_STRANGE_RIVER_A_H
#define COM_ONEISH_STRANGE_RIVER_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/dderived.hpp -c ~/source/repos/strange/archetypes/river.hpp > ~/source/repos/strange/sauce/strange_river_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "lake_forward.hpp"
#include "number_data_forward.hpp"

namespace strange
{

template <typename _1_>
class river_a
{
public:
	// river input
	inline std::string to_string();

	inline any_a<> get__(range_a<> const& _);
	inline number_data_int8_a<> get_();
	inline int8_t get();
	
	inline any_a<> peek__(range_a<> const& _);
	inline number_data_int8_a<> peek_();
	inline int8_t peek();

	inline any_a<> unget__(range_a<> const& _);
	inline any_a<> unget_();
	inline void unget();

	inline any_a<> putback__(range_a<> const& range);
	inline any_a<> putback_(number_data_int8_a<> const& int_8);
	inline void putback(int8_t int_8);

	inline any_a<> getline__(range_a<> const& range);
	inline lake_int8_a<> getline_(number_data_int64_a<> const& count, number_data_int8_a<> const& delimiter);
	inline std::vector<int8_t> getline(int64_t count, int8_t delimiter);

	inline any_a<> ignore__(range_a<> const& range);
	inline any_a<> ignore_(number_data_int64_a<> const& count);
	inline void ignore(int64_t count);

	inline any_a<> read__(range_a<> const& range);
	inline lake_int8_a<> read_(number_data_int64_a<> const& count);
	inline std::vector<int8_t> read(int64_t count);
	inline std::string read_string(int64_t count);

	inline any_a<> tellg__(range_a<> const& _) const;
	inline number_data_int64_a<> tellg_() const;
	inline int64_t tellg() const;

	inline any_a<> seekg_beg__(range_a<> const& range);
	inline any_a<> seekg_beg_(number_data_int64_a<> const& offset);
	inline void seekg_beg(int64_t offset);

	inline any_a<> seekg_end__(range_a<> const& range);
	inline any_a<> seekg_end_(number_data_int64_a<> const& offset);
	inline void seekg_end(int64_t offset);

	inline any_a<> seekg_cur__(range_a<> const& range);
	inline any_a<> seekg_cur_(number_data_int64_a<> const& offset);
	inline void seekg_cur(int64_t offset);

	inline any_a<> sync__(range_a<> const& _);
	inline any_a<> sync_();
	inline bool sync();

	// river output
	inline any_a<> put__(range_a<> const& range);
	inline any_a<> put_(number_data_int8_a<> const& int_8);
	inline void put(int8_t int_8);

	inline any_a<> write__(range_a<> const& range);
	inline any_a<> write_(lake_int8_a<> const& lake);
	inline void write(std::vector<int8_t> const& lake);
	inline void write_string(std::string const& str);

	inline any_a<> tellp__(range_a<> const& _) const;
	inline number_data_int64_a<> tellp_() const;
	inline int64_t tellp() const;

	inline any_a<> seekp_beg__(range_a<> const& range);
	inline any_a<> seekp_beg_(number_data_int64_a<> const& offset);
	inline void seekp_beg(int64_t offset);

	inline any_a<> seekp_end__(range_a<> const& range);
	inline any_a<> seekp_end_(number_data_int64_a<> const& offset);
	inline void seekp_end(int64_t offset);

	inline any_a<> seekp_cur__(range_a<> const& range);
	inline any_a<> seekp_cur_(number_data_int64_a<> const& offset);
	inline void seekp_cur(int64_t offset);

	inline any_a<> flush__(range_a<> const& _);
	inline any_a<> flush_();
	inline void flush();

	// river
	inline any_a<> good__(range_a<> const& _) const;
	inline any_a<> good_() const;
	inline bool good() const;

	inline any_a<> eof__(range_a<> const& _) const;
	inline any_a<> eof_() const;
	inline bool eof() const;

	inline any_a<> fail__(range_a<> const& _) const;
	inline any_a<> fail_() const;
	inline bool fail() const;

	inline any_a<> bad__(range_a<> const& _) const;
	inline any_a<> bad_() const;
	inline bool bad() const;

	inline any_a<> set_good__(range_a<> const& range);
	inline any_a<> set_good_(any_a<> const& value);
	inline void set_good(bool value);

	inline any_a<> set_eof__(range_a<> const& range);
	inline any_a<> set_eof_(any_a<> const& value);
	inline void set_eof(bool value);

	inline any_a<> set_fail__(range_a<> const& range);
	inline any_a<> set_fail_(any_a<> const& value);
	inline void set_fail(bool value);

	inline any_a<> set_bad__(range_a<> const& range);
	inline any_a<> set_bad_(any_a<> const& value);
	inline void set_bad(bool value);

	inline any_a<> filename__(range_a<> const& _) const;
	inline lake_int8_a<> filename_() const;
	inline std::string filename() const;
};

} // namespace strange

#endif
