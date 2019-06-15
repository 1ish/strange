#ifndef COM_ONEISH_STRANGE_SHOAL_A_H
#define COM_ONEISH_STRANGE_SHOAL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/ddderived.hpp -c ~/source/repos/strange/archetypes/shoal.hpp > ~/source/repos/strange/sauce/strange_shoal_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "forward_iterator_forward.hpp"

namespace strange
{

template <typename _1_>
class shoal_a
{
public:
	// shoal
	inline bool has_string(std::string const& s) const;
	inline any_a<> at_string(std::string const& s) const;
	inline void update_string(std::string const& s, any_a<> const& value);
	inline bool insert_string(std::string const& s, any_a<> const& value);
	inline bool erase_string(std::string const& s);

	// mutable range
	inline any_a<> begin__(range_a<> const& _);
	inline forward_iterator_a<> begin_();

	inline any_a<> end__(range_a<> const& _);
	inline forward_iterator_a<> end_();
};

} // namespace strange

#endif
