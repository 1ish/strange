#ifndef COM_ONEISH_STRANGE_DEFINITIONS_HPP
#define COM_ONEISH_STRANGE_DEFINITIONS_HPP

using int64_t = long long;
using uint64_t = unsigned long long;

namespace std
{
	typedef unsigned long long size_t;
	class string;
	template <typename T> class vector;
	template <typename T> class deque;
	template <typename T> class set;
	template <typename T, typename H> class unordered_set;
	template <typename K, typename V> class map;
	template <typename K, typename V, typename H> class unordered_map;
}

#endif
