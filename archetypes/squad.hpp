#ifndef COM_ONEISH_STRANGE_SQUAD_A_H
#define COM_ONEISH_STRANGE_SQUAD_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale.hpp -c ~/source/repos/strange/archetypes/squad.hpp > ~/source/repos/strange/sauce/strange_squad_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class squad_a
{
public:
	// data
	inline std::deque<any_a<>> const& extract() const;
	inline void mutate(std::deque<any_a<>> const& data);
	inline std::deque<any_a<>>& reference();
};

} // namespace strange

#endif
