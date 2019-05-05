#ifndef COM_ONEISH_STRANGE_VARIADIC_U_H
#define COM_ONEISH_STRANGE_VARIADIC_U_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class variadic_u
{
public:
	static inline void variadic__(std::vector<_ABSTRACTION_>& vec)
	{
	}

	template <typename... Args>
	static inline void variadic__(std::vector<_ABSTRACTION_>& vec, std::string const& s, Args&&... args)
	{
		vec.push_back(sym__(s));
		variadic__(vec, std::forward<Args>(args)...);
	}

	template <typename... Args>
	static inline void variadic__(std::vector<_ABSTRACTION_>& vec, _ABSTRACTION_ const& thing, Args&&... args)
	{
		vec.push_back(thing);
		variadic__(vec, std::forward<Args>(args)...);
	}
};

} // namespace strange

#endif
