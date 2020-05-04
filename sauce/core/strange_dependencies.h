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

	inline std_string std_to_string(int8_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(uint8_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(int16_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(uint16_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(int32_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(uint32_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(int64_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(uint64_t _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(float _primitive) { return std::to_string(_primitive); }
	inline std_string std_to_string(double _primitive) { return std::to_string(_primitive); }

	inline int64_t std_stoll(std_string const& _str, std_size_t* _pos = nullptr, int _base = 10) { return std::stoll(_str, _pos, _base); }
	inline double std_stod(std_string const& _str, std_size_t* _pos = nullptr) { return std::stod(_str, _pos); }
	inline int64_t std_llround(double number) { return std::llround(number); }

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

	template <typename _first, typename _second>
	using std_pair = std::pair<_first, _second>;

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

	inline std_istream& std_getline(std_istream& _istr, std_string& _str, char _delim) { return std::getline(_istr, _str, _delim); }

	inline std_istream& standard_in() { return std::cin; }
	inline std_ostream& standard_out() { return std::cout; }
	inline std_ostream& standard_error() { return std::cerr; }

	using std_ios_base = std::ios_base;

	using std_exception = std::exception;

	using dart_packet = dart::basic_packet<dart::unsafe_ptr>;

	inline dart_packet dart_packet_from_vector(std_vector<int8_t> const& binary) { return dart_packet{ gsl::make_span(reinterpret_cast<gsl::byte const*>(binary.data()), binary.size()) }; }
	inline dart_packet dart_packet_from_string(std_string const& binary) { return dart_packet{ gsl::make_span(reinterpret_cast<gsl::byte const*>(binary.data()), binary.size()) }; }
}

#endif
