#ifndef COM_ONEISH_STRANGE_VARIADIC_PAIR_U_H
#define COM_ONEISH_STRANGE_VARIADIC_PAIR_U_H

namespace strange
{

template <typename _1_ = any_a<>, typename _2_ = any_a<>>
class variadic_pair_u
{
public:
	static inline void variadic(std_map<_1_, _2_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std_map<_1_, _2_>& collection, std::pair<std_string, _2_> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_map<_1_, _2_>& collection, std::pair<_1_, std_string> const& p, Args&&... args)
	{
		collection.emplace(p.first, sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_map<_1_, _2_>& collection, std::pair<std_string, std_string> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_map<_1_, _2_>& collection, std::pair<_1_, _2_> const& p, Args&&... args)
	{
		collection.emplace(p.first, p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_map<_1_, _2_> map(Args&&... args)
	{
		std_map<_1_, _2_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std_unordered_map<_1_, _2_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std_unordered_map<_1_, _2_>& collection, std::pair<std_string, _2_> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_unordered_map<_1_, _2_>& collection, std::pair<_1_, std_string> const& p, Args&&... args)
	{
		collection.emplace(p.first, sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_unordered_map<_1_, _2_>& collection, std::pair<std_string, std_string> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_unordered_map<_1_, _2_>& collection, std::pair<_1_, _2_> const& p, Args&&... args)
	{
		collection.emplace(p.first, p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_unordered_map<_1_, _2_> unordered_map(Args&&... args)
	{
		std_unordered_map<_1_, _2_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}
};

} // namespace strange

#endif
