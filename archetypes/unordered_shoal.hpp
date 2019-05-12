#ifndef COM_ONEISH_STRANGE_UNORDERED_SHOAL_A_H
#define COM_ONEISH_STRANGE_UNORDERED_SHOAL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/fffinale.hpp -c ~/source/repos/strange/archetypes/unordered_shoal.hpp > ~/source/repos/strange/sauce/strange_unordered_shoal_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename _1_>
class unordered_shoal_a
{
public:
	// unordered shoal
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& extract() const;
	inline void mutate(std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& data);
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>& reference();
};

} // namespace strange

#endif
