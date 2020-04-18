#ifndef COM_ONEISH_STRANGE_DEFINITIONS_H
#define COM_ONEISH_STRANGE_DEFINITIONS_H

// definitions

namespace strange
{

// hash

template <typename ___ego___>
inline std_size_t hash_of(___ego___ const& thing)
{
	return thing.hash();
}

// logic

inline any_a<> yes()
{
	return something_t<>::create_();
}

inline any_a<> no()
{
	return nothing_t<>::create_();
}

inline any_a<> boole(bool b)
{
	return b ? yes() : no();
}

// shared

inline shoal_a<>& shared()
{
	static shoal_a<> SHARED = unordered_shoal_t<>::create_();
	return SHARED;
}

// pipe

inline any_a<> operator|(any_a<> const& thing, any_a<> const& adaptor)
{
	if (check<range_a<>>(thing))
	{
		any_a<> _;
		return adaptor.operate(_, fast<range_a<>>(thing));
	}
	if (check<misunderstanding_a<>>(thing))
	{
		return thing;
	}
	any_a<> _;
	return adaptor.operate(_, flock_t<>::create_(thing));
}

// operate

template <typename... Args>
inline any_a<> variadic_operate(any_a<> const& op, any_a<>& thing, Args&&... args)
{
	return op.operate(thing, flock_t<>::create_dups_(std::forward<Args>(args)...));
}

// check/cast

template <typename ___TTT___>
inline bool check(any_a<> const& value) noexcept
{
	return ___TTT___::___check___(value);
}

template <typename ___TTT___>
inline ___TTT___ fast(any_a<> const& value) noexcept
{
	return ___TTT___{ value.___handle___ };
}

template <typename ___TTT___>
inline ___TTT___ fast_ref(any_a<> const& value) noexcept
{
	return ___TTT___(value.___handle___, typename ___TTT___::___reference_tag___{});
}

template <typename ___TTT___>
inline ___TTT___ fast_dup(any_a<> const& value) noexcept
{
	if (value.is_ref())
	{
		return ___TTT___(value.___handle___, typename ___TTT___::___reference_tag___{});
	}
	return ___TTT___{ value.___handle___ };
}

template <typename ___TTT___>
inline ___TTT___ cast(any_a<> const& value) noexcept
{
	return ___TTT___::___cast___(value);
}

template <typename ___TTT___>
inline ___TTT___ cast_ref(any_a<> const& value) noexcept
{
	return ___TTT___::___cast_ref___(const_cast<any_a<>&>(value));
}

template <typename ___TTT___>
inline ___TTT___ cast_dup(any_a<> const& value) noexcept
{
	if (value.is_ref())
	{
		return ___TTT___::___cast_ref___(const_cast<any_a<>&>(value));
	}
	return ___TTT___::___cast___(value);
}

}

#endif