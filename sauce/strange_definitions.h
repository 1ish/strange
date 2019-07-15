#ifndef COM_ONEISH_STRANGE_DEFINITIONS_H
#define COM_ONEISH_STRANGE_DEFINITIONS_H

// definitions

namespace strange
{

// logic

inline any_a<> yes()
{
	return something_t<>::val_();
}

inline any_a<> no()
{
	return nothing_t<>::val_();
}

inline any_a<> boole(bool b)
{
	return b ? yes() : no();
}

// shared

inline shoal_a<> shared()
{
	static shoal_a<> SHARED = []()
	{
		auto shared = unordered_shoal_t<>::val_();
		symbol_t<>::share(shared);
		cat_t<>::share(shared);
		return shared;
	}();
	return SHARED;
}

}

#endif