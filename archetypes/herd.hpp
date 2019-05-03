#ifndef COM_ONEISH_STRANGE_HERD_A_H
#define COM_ONEISH_STRANGE_HERD_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/herd.hpp > ~/source/repos/strange/sauce/strange_herd_a.h
*/

#include "any.hpp"
#include "collection_forward.hpp"

namespace strange
{

template <typename _1_>
class herd_a
{
public:
	// herd
	inline bool has__(std::string const& s) const;
	inline bool at__(std::string const& s) const;
	inline bool insert__(std::string const& s);
	inline bool erase__(std::string const& s);

	// data
	inline std::unordered_set<any_a<>, any_a<>::hash_f> const& extract__() const;
	inline void mutate__(std::unordered_set<any_a<>, any_a<>::hash_f> const& data);
	inline std::unordered_set<any_a<>, any_a<>::hash_f>& reference__();
};

} // namespace strange

#endif
