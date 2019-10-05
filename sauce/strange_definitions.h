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

}

#endif