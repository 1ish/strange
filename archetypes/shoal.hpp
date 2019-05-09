#ifndef COM_ONEISH_STRANGE_SHOAL_A_H
#define COM_ONEISH_STRANGE_SHOAL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/shoal.hpp > ~/source/repos/strange/sauce/strange_shoal_a.h
*/

#include "any_forward.hpp"

namespace strange
{

template <typename bidirectional_iterator_a>
class shoal_a
{
public:
	// shoal
	inline bool has__(std::string const& s) const;
	inline any_a<> at__(std::string const& s) const;
	inline void update__(std::string const& s, any_a<> const& value);
	inline bool insert__(std::string const& s, any_a<> const& value);
	inline bool erase__(std::string const& s);

	// mutable range
	inline any_a<> beset(any_a<> const& _);
	inline bidirectional_iterator_a beset_();
	inline bidirectional_iterator_a begin();

	inline any_a<> enset(any_a<> const& _);
	inline bidirectional_iterator_a enset_();
	inline bidirectional_iterator_a end();

	// data
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& extract__() const;
	inline void mutate__(std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& data);
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>& reference__();
};

} // namespace strange

#endif
