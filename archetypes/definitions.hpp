#ifndef COM_ONEISH_STRANGE_DEFINITIONS_HPP
#define COM_ONEISH_STRANGE_DEFINITIONS_HPP

namespace std
{
	typedef unsigned long long size_t;
	class string;
	template <typename T> class vector;
	template <typename T, typename H> class unordered_set;
	template <typename K, typename V, typename H> class unordered_map;
}

namespace strange
{
	class any_a
	{
	public:
		class hash_f;
	};
	class symbol_a;
	class cat_a;
	class misunderstanding_a;
	class collection_a;
	class number_a;
	class random_access_iterator_a;
}

using int64_t = long long;

#endif
