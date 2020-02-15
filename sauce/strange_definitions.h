#ifndef COM_ONEISH_STRANGE_DEFINITIONS_H
#define COM_ONEISH_STRANGE_DEFINITIONS_H

// definitions

namespace strange
{

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
		return adaptor.operate(_, cast<range_a<>>(thing));
	}
	if (check<misunderstanding_a<>>(thing))
	{
		return thing;
	}
	any_a<> _;
	return adaptor.operate(_, flock_t<>::create_(thing));
}

// check/cast

template <typename ___TTT___, typename ___VVV___>
inline bool check(___VVV___ const&) noexcept
{
	return false;
}

#ifdef STRANGE_CHECK_STATIC_CASTS
template <typename ___TTT___>
inline ___TTT___ cast(any_a<> const& value)
{
	return ___TTT___{ value.handle_ };
}
#else
template <typename ___TTT___>
inline ___TTT___ cast(any_a<> const& value) noexcept
{
	return ___TTT___{ value.handle_ };
}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
template <typename ___TTT___>
inline ___TTT___ cast_ref(any_a<>& value)
{
	return ___TTT___(value.handle_, any_a<>::___reference_tag___{});
}
#else
template <typename ___TTT___>
inline ___TTT___ cast_ref(any_a<>& value) noexcept
{
	return ___TTT___(value.handle_, any_a<>::___reference_tag___{});
}
#endif

#ifdef STRANGE_CHECK_STATIC_CASTS
template <typename ___TTT___>
inline ___TTT___ cast_dup(any_a<>& value)
{
	if (&value.handle_ == &value.___shared___)
	{
		return ___TTT___{ value.handle_ };
	}
	else
	{
		return ___TTT___(value.handle_, any_a<>::___reference_tag___{});
	}
}
#else
template <typename ___TTT___>
inline ___TTT___ cast_dup(any_a<>& value) noexcept
{
	if (&value.handle_ == &value.___shared___)
	{
		return ___TTT___{ value.handle_ };
	}
	else
	{
		return ___TTT___(value.handle_, any_a<>::___reference_tag___{});
	}
}
#endif

}

#endif