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

inline shoal_a<> shared()
{
	static shoal_a<> SHARED = unordered_shoal_t<>::create_();
	return SHARED;
}

// pipe

inline any_a<> operator|(any_a<> const& thing, any_a<> const& adaptor)
{
	if (check<range_a<>>(thing))
	{
		return adaptor.operate(any_a<>{}, cast<range_a<>>(thing));
	}
	if (check<misunderstanding_a<>>(thing))
	{
		return thing;
	}
	return adaptor.operate(any_a<>{}, thing.ranged_());
}

}

#endif