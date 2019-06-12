#ifndef COM_ONEISH_STRANGE_VARIADIC_PAIR_U_H
#define COM_ONEISH_STRANGE_VARIADIC_PAIR_U_H

namespace strange
{

template <typename _1_ = any_a<>, typename _2_ = any_a<>>
class variadic_pair_u
{
public:
	static inline void variadic(std::map<_1_, _2_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::map<_1_, _2_>& collection, std::pair<std::string, _2_> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::map<_1_, _2_>& collection, std::pair<_1_, std::string> const& p, Args&&... args)
	{
		collection.emplace(p.first, sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::map<_1_, _2_>& collection, std::pair<std::string, std::string> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::map<_1_, _2_>& collection, std::pair<_1_, _2_> const& p, Args&&... args)
	{
		collection.emplace(p.first, p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::map<_1_, _2_> map(Args&&... args)
	{
		std::map<_1_, _2_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::unordered_map<_1_, _2_, typename _1_::hash_f>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::unordered_map<_1_, _2_, typename _1_::hash_f>& collection, std::pair<std::string, _2_> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_map<_1_, _2_, typename _1_::hash_f>& collection, std::pair<_1_, std::string> const& p, Args&&... args)
	{
		collection.emplace(p.first, sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_map<_1_, _2_, typename _1_::hash_f>& collection, std::pair<std::string, std::string> const& p, Args&&... args)
	{
		collection.emplace(sym(p.first), sym(p.second));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_map<_1_, _2_, typename _1_::hash_f>& collection, std::pair<_1_, _2_> const& p, Args&&... args)
	{
		collection.emplace(p.first, p.second);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::unordered_map<_1_, _2_, typename _1_::hash_f> unordered_map(Args&&... args)
	{
		std::unordered_map<_1_, _2_, typename _1_::hash_f> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}
};

} // namespace strange

#endif
