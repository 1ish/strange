#ifndef COM_ONEISH_STRANGE_SHOAL_A_H
#define COM_ONEISH_STRANGE_SHOAL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ffinale.hpp -c ~/source/repos/strange/archetypes/shoal.hpp > ~/source/repos/strange/sauce/strange_shoal_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename bidirectional_iterator_a>
class shoal_a
{
public:
	// shoal
	inline bool has(std::string const& s) const;
	inline any_a<> at(std::string const& s) const;
	inline void update(std::string const& s, any_a<> const& value);
	inline bool insert(std::string const& s, any_a<> const& value);
	inline bool erase(std::string const& s);

	// mutable range
	inline any_a<> begin__(range_a<> const& _);
	inline bidirectional_iterator_a begin_();
	inline bidirectional_iterator_a begin();

	inline any_a<> end__(range_a<> const& _);
	inline bidirectional_iterator_a end_();
	inline bidirectional_iterator_a end();

	// data
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& extract() const;
	inline void mutate(std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f> const& data);
	inline std::unordered_map<any_a<>, any_a<>, any_a<>::hash_f>& reference();
};

} // namespace strange

#endif
