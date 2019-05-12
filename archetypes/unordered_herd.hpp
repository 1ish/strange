#ifndef COM_ONEISH_STRANGE_UNORDERED_HERD_A_H
#define COM_ONEISH_STRANGE_UNORDERED_HERD_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ffinale.hpp -c ~/source/repos/strange/archetypes/unordered_herd.hpp > ~/source/repos/strange/sauce/strange_unordered_herd_a.h
*/

#include "any.hpp"

namespace strange
{

template <typename _1_>
class unordered_herd_a
{
public:
	// unordered_herd
	inline bool has(std::string const& s) const;
	inline bool at(std::string const& s) const;
	inline bool insert(std::string const& s);
	inline bool erase(std::string const& s);

	// data
	inline std::unordered_set<any_a<>, any_a<>::hash_f> const& extract() const;
	inline void mutate(std::unordered_set<any_a<>, any_a<>::hash_f> const& data);
	inline std::unordered_set<any_a<>, any_a<>::hash_f>& reference();
};

} // namespace strange

#endif
