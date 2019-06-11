#ifndef COM_ONEISH_STRANGE_VARIADIC_U_H
#define COM_ONEISH_STRANGE_VARIADIC_U_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class variadic_u
{
public:
	static inline void variadic(std::vector<_ABSTRACTION_>& vec)
	{
	}

	template <typename... Args>
	static inline void variadic(std::vector<_ABSTRACTION_>& vec, std::string const& s, Args&&... args)
	{
		vec.push_back(sym(s));
		variadic(vec, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic(std::vector<_ABSTRACTION_>& vec, _ABSTRACTION_ const& thing, Args&&... args)
	{
		vec.push_back(thing);
		variadic(vec, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline std::vector<_ABSTRACTION_> vector(Args&&... args)
	{
		std::vector<_ABSTRACTION_> vec;
		variadic(vec, std::forward<Args>(args)...);
		return vec;
	}
};

} // namespace strange

#endif
