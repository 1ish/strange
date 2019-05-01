#ifndef COM_ONEISH_STRANGE_SHOAL_A_H
#define COM_ONEISH_STRANGE_SHOAL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale_1.hpp -c ~/source/repos/strange/archetypes/shoal.hpp > ~/source/repos/strange/sauce/strange_shoal_a.h
*/

#include "collection.hpp"

namespace strange
{

template <typename _1_ = void>
class shoal_a
{
public:
	// shoal
	inline bool has__(std::string const& s) const;
	inline any_a<> at__(std::string const& s) const;
	inline void update__(std::string const& s, any_a<> const& value);
	inline bool insert__(std::string const& s, any_a<> const& value);
	inline bool erase__(std::string const& s);

	// data
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& extract__() const;
	inline void mutate__(std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& data);
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>& reference__();
};

} // namespace strange

#endif
