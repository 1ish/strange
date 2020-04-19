#ifndef COM_ONEISH_STRANGE_DEPENDENCIES_H
#define COM_ONEISH_STRANGE_DEPENDENCIES_H

// dependencies
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>
#include <ios>
#include <fstream>
#include <sstream>
#include <iterator>
#include <mutex>
#include <shared_mutex>
#include <iostream>
#include <cmath>

#include "../../libdart/include/dart.h"

namespace strange
{
	using std_size_t = std::size_t;

	using std_string = std::string;

	using std_stringstream = std::stringstream;

	template <typename _element>
	using std_deque = std::deque<_element>;

	template <typename _element>
	using std_vector = std::vector<_element>;

	template <typename _element>
	using std_set = std::set<_element>;

	template <typename _key, typename _value>
	using std_map = std::map<_key, _value>;

	template <typename _element>
	using std_unordered_set = std::unordered_set<_element>;

	template <typename _key, typename _value>
	using std_unordered_map = std::unordered_map<_key, _value>;

	template <typename _thing>
	using std_weak_ptr = std::weak_ptr<_thing>;

	template <typename _thing>
	using std_shared_ptr = std::shared_ptr<_thing>;

	template <typename _thing, typename... _types>
	inline std_shared_ptr<_thing> std_make_shared(_types&&... _args) { return std::make_shared<_thing>(std::forward<_types>(_args)...); }

	template <typename _char>
	using std_istreambuf_iterator = std::istreambuf_iterator<_char>;

	template <typename _char>
	using std_basic_ios = std::basic_ios<_char>;

	template <typename _char>
	using std_basic_fstream = std::basic_fstream<_char>;

	using std_istream = std::istream;

	using std_ostream = std::ostream;

	using std_fstream = std::fstream;

	inline std_istream& standard_in() { return std::cin; }
	inline std_ostream& standard_out() { return std::cout; }
	inline std_ostream& standard_err() { return std::cerr; }

	using std_ios_base = std::ios_base;

	//std::exception
	//std::runtime_error
	//std::pair
	//std::getline
	//std::stoll
	//std::stod
	//std::to_string inline string to_string(unsigned long long _Val)

	using dart_packet = dart::packet;
}

#endif
