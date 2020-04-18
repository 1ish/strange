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
	template<typename _element>
	using std_deque = std::deque<_element>;
	template<typename _element>
	using std_vector = std::vector<_element>;
	template<typename _element>
	using std_set = std::set<_element>;
	template<typename _key, typename _value>
	using std_map = std::map<_key, _value>;
	template<typename _char>
	using std_istreambuf_iterator = std::istreambuf_iterator<_char>;

	using dart_packet = dart::packet;
}

#endif
