#ifndef COM_ONEISH_STRANGE_SHOAL_A_H
#define COM_ONEISH_STRANGE_SHOAL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/shoal.hpp > ~/source/repos/strange/sauce/strange_shoal_a.h
*/

#include "collection.hpp"

namespace strange
{

class shoal
{
public:
	// shoal
	inline bool has__(const std::string& s) const;
	inline any_a at__(const std::string& s) const;
	inline void update__(const std::string& s, any_a value);
	inline bool insert__(const std::string& s, any_a value);
	inline bool erase__(const std::string& s);

	// data
	inline const std::unordered_map<any_a, any_a, any_a::hash_f>& extract__() const;
	inline void mutate__(const std::unordered_map<any_a, any_a, any_a::hash_f>& data);
	inline std::unordered_map<any_a, any_a, any_a::hash_f>& reference__();
};

} // namespace strange

#endif
