#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived_1.hpp -c ~/source/repos/strange/archetypes/misunderstanding.hpp > ~/source/repos/strange/sauce/strange_misunderstanding_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename _1_>
class misunderstanding_a
{
public:
	// misunderstanding
	inline std::string to_string() const;

	inline any_a<> add__(range_a<> const& range) const;
	inline misunderstanding_a add_(misunderstanding_a const& misunderstanding) const;
	inline misunderstanding_a operator+(misunderstanding_a const& misunderstanding) const;
};

} // namespace strange

#endif
