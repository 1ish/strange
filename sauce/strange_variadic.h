#ifndef COM_ONEISH_STRANGE_VARIADIC_H
#define COM_ONEISH_STRANGE_VARIADIC_H

namespace strange
{

template <typename CAT = thing_>
class Variadic
{
public:
	static inline void variadic_(std::vector<CAT>& vec)
	{
	}

	template <typename... Args>
	static inline void variadic_(std::vector<CAT>& vec, const std::string& s, Args&&... args)
	{
		vec.push_back(sym__(s));
		variadic_(vec, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic_(std::vector<CAT>& vec, CAT thing, Args&&... args)
	{
		vec.push_back(thing);
		variadic_(vec, std::forward<Args>(args)...);
	}
};

} // namespace strange

#endif
