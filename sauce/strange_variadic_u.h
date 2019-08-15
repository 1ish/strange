#ifndef COM_ONEISH_STRANGE_VARIADIC_U_H
#define COM_ONEISH_STRANGE_VARIADIC_U_H

namespace strange
{

template <typename _1_ = any_a<>, typename _2_ = std::hash<_1_>>
class variadic_u
{
public:
	static inline void variadic(std::vector<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::vector<_1_>& collection, std::string const& s, Args&&... args)
	{
		collection.push_back(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::vector<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.push_back(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::vector<_1_> vector(Args&&... args)
	{
		std::vector<_1_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::deque<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::deque<_1_>& collection, std::string const& s, Args&&... args)
	{
		collection.push_back(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::deque<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.push_back(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::deque<_1_> deque(Args&&... args)
	{
		std::deque<_1_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::set<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, int64_t i, Args&&... args)
	{
		collection.insert(number_int_64_t<>::val(i));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, double f, Args&&... args)
	{
		collection.insert(number_float_64_t<>::val(f));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, std::string const& s, Args&&... args)
	{
		collection.insert(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.insert(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::set<_1_> set(Args&&... args)
	{
		std::set<_1_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::unordered_set<_1_, _2_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, int64_t i, Args&&... args)
	{
		collection.insert(number_int_64_t<>::val(i));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, double f, Args&&... args)
	{
		collection.insert(number_float_64_t<>::val(f));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, std::string const& s, Args&&... args)
	{
		collection.insert(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.insert(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::unordered_set<_1_, _2_> unordered_set(Args&&... args)
	{
		std::unordered_set<_1_, _2_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}
};

} // namespace strange

#endif
