#ifndef COM_ONEISH_STRANGE_DEFINITIONS_H
#define COM_ONEISH_STRANGE_DEFINITIONS_H

// definitions

namespace strange
{

// conversion
inline any_a<> boole(bool b)
{
	return b ? something_t<>::val_() : nothing_t<>::val_();
}

}

#endif