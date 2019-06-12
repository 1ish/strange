#ifndef COM_ONEISH_STRANGE_VARIADIC_U_H
#define COM_ONEISH_STRANGE_VARIADIC_U_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class variadic_u
{
public:
	static inline void variadic(std::vector<_ABSTRACTION_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::vector<_ABSTRACTION_>& collection, std::string const& s, Args&&... args)
	{
		collection.push_back(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::vector<_ABSTRACTION_>& collection, _ABSTRACTION_ const& thing, Args&&... args)
	{
		collection.push_back(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::vector<_ABSTRACTION_> vector(Args&&... args)
	{
		std::vector<_ABSTRACTION_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::deque<_ABSTRACTION_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::deque<_ABSTRACTION_>& collection, std::string const& s, Args&& ... args)
	{
		collection.push_back(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::deque<_ABSTRACTION_>& collection, _ABSTRACTION_ const& thing, Args&& ... args)
	{
		collection.push_back(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::deque<_ABSTRACTION_> deque(Args&& ... args)
	{
		std::deque<_ABSTRACTION_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::set<_ABSTRACTION_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::set<_ABSTRACTION_>& collection, int64_t i, Args&& ... args)
	{
		collection.insert(number_int_64_t<>::val(i));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_ABSTRACTION_>& collection, double f, Args&& ... args)
	{
		collection.insert(number_float_64_t<>::val(f));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_ABSTRACTION_>& collection, std::string const& s, Args&& ... args)
	{
		collection.insert(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_ABSTRACTION_>& collection, _ABSTRACTION_ const& thing, Args&& ... args)
	{
		collection.insert(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::set<_ABSTRACTION_> set(Args&& ... args)
	{
		std::set<_ABSTRACTION_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::unordered_set<_ABSTRACTION_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_ABSTRACTION_>& collection, int64_t i, Args&& ... args)
	{
		collection.insert(number_int_64_t<>::val(i));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_ABSTRACTION_>& collection, double f, Args&& ... args)
	{
		collection.insert(number_float_64_t<>::val(f));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_ABSTRACTION_>& collection, std::string const& s, Args&& ... args)
	{
		collection.insert(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_ABSTRACTION_>& collection, _ABSTRACTION_ const& thing, Args&& ... args)
	{
		collection.insert(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::unordered_set<_ABSTRACTION_> unordered_set(Args&& ... args)
	{
		std::unordered_set<_ABSTRACTION_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}
};

} // namespace strange

#endif
