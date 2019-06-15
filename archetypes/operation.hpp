#ifndef COM_ONEISH_STRANGE_OPERATION_A_H
#define COM_ONEISH_STRANGE_OPERATION_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/operation.hpp > ~/source/repos/strange/sauce/strange_operation_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"

namespace strange
{

template <typename _1_>
class operation_a
{
public:
	// operation
	inline any_a<> pure__(range_a<> const& _) const;
	inline any_a<> pure_() const;
	inline bool pure() const;

	inline any_a<> literal__(range_a<> const& _) const;
	inline any_a<> literal_() const;
	inline bool literal() const;
};

} // namespace strange

#endif