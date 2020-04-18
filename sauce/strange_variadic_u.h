#ifndef COM_ONEISH_STRANGE_VARIADIC_U_H
#define COM_ONEISH_STRANGE_VARIADIC_U_H

namespace strange
{

template <typename _1_ = any_a<>, typename _2_ = std::hash<_1_>>
class variadic_u
{
public:
	static inline void variadic(std_vector<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std_vector<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace_back(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_vector<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace_back(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_vector<_1_> vector(Args&&... args)
	{
		std_vector<_1_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_ref(std_vector<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_ref(std_vector<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace_back(sym(s));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std_vector<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace_back(const_cast<_1_&>(thing), typename _1_::___reference_tag___{});
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_vector<_1_> vector_ref(Args&&... args)
	{
		std_vector<_1_> collection;
		variadic_ref(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_dup(std_vector<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_dup(std_vector<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace_back(sym(s));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std_vector<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace_back(const_cast<_1_&>(thing), typename _1_::___duplicate_tag___{});
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_vector<_1_> vector_dup(Args&&... args)
	{
		std_vector<_1_> collection;
		variadic_dup(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std_deque<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std_deque<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace_back(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std_deque<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace_back(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_deque<_1_> deque(Args&&... args)
	{
		std_deque<_1_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_ref(std_deque<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_ref(std_deque<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace_back(sym(s));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std_deque<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace_back(const_cast<_1_&>(thing), typename _1_::___reference_tag___{});
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_deque<_1_> deque_ref(Args&&... args)
	{
		std_deque<_1_> collection;
		variadic_ref(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_dup(std_deque<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_dup(std_deque<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace_back(sym(s));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std_deque<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace_back(const_cast<_1_&>(thing), typename _1_::___duplicate_tag___{});
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std_deque<_1_> deque_dup(Args&&... args)
	{
		std_deque<_1_> collection;
		variadic_dup(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::set<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, int64_t i, Args&&... args)
	{
		collection.emplace(num(i));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, double f, Args&&... args)
	{
		collection.emplace(num(f));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::set<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::set<_1_> set(Args&&... args)
	{
		std::set<_1_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_ref(std::set<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_ref(std::set<_1_>& collection, int64_t i, Args&&... args)
	{
		collection.emplace(num(i));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std::set<_1_>& collection, double f, Args&&... args)
	{
		collection.emplace(num(f));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std::set<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace(sym(s));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std::set<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace(const_cast<_1_&>(thing), typename _1_::___reference_tag___{});
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::set<_1_> set_ref(Args&&... args)
	{
		std::set<_1_> collection;
		variadic_ref(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_dup(std::set<_1_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_dup(std::set<_1_>& collection, int64_t i, Args&&... args)
	{
		collection.emplace(num(i));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std::set<_1_>& collection, double f, Args&&... args)
	{
		collection.emplace(num(f));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std::set<_1_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace(sym(s));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std::set<_1_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace(const_cast<_1_&>(thing), typename _1_::___duplicate_tag___{});
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::set<_1_> set_dup(Args&&... args)
	{
		std::set<_1_> collection;
		variadic_dup(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic(std::unordered_set<_1_, _2_>& collection)
	{}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, int64_t i, Args&&... args)
	{
		collection.emplace(num(i));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, double f, Args&&... args)
	{
		collection.emplace(num(f));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace(sym(s));
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::unordered_set<_1_, _2_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace(thing);
		variadic(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::unordered_set<_1_, _2_> unordered_set(Args&&... args)
	{
		std::unordered_set<_1_, _2_> collection;
		variadic(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_ref(std::unordered_set<_1_, _2_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_ref(std::unordered_set<_1_, _2_>& collection, int64_t i, Args&&... args)
	{
		collection.emplace(num(i));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std::unordered_set<_1_, _2_>& collection, double f, Args&&... args)
	{
		collection.emplace(num(f));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std::unordered_set<_1_, _2_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace(sym(s));
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_ref(std::unordered_set<_1_, _2_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace(const_cast<_1_&>(thing), typename _1_::___reference_tag___{});
		variadic_ref(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::unordered_set<_1_, _2_> unordered_set_ref(Args&&... args)
	{
		std::unordered_set<_1_, _2_> collection;
		variadic_ref(collection, std::forward<Args>(args)...);
		return collection;
	}

	static inline void variadic_dup(std::unordered_set<_1_, _2_>& collection)
	{}

	template <typename... Args>
	static inline void variadic_dup(std::unordered_set<_1_, _2_>& collection, int64_t i, Args&&... args)
	{
		collection.emplace(num(i));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std::unordered_set<_1_, _2_>& collection, double f, Args&&... args)
	{
		collection.emplace(num(f));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std::unordered_set<_1_, _2_>& collection, std_string const& s, Args&&... args)
	{
		collection.emplace(sym(s));
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_dup(std::unordered_set<_1_, _2_>& collection, _1_ const& thing, Args&&... args)
	{
		collection.emplace(const_cast<_1_&>(thing), typename _1_::___duplicate_tag___{});
		variadic_dup(collection, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::unordered_set<_1_, _2_> unordered_set_dup(Args&&... args)
	{
		std::unordered_set<_1_, _2_> collection;
		variadic_dup(collection, std::forward<Args>(args)...);
		return collection;
	}
};

} // namespace strange

#endif
