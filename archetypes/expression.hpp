#ifndef COM_ONEISH_STRANGE_EXPRESSION_A_H
#define COM_ONEISH_STRANGE_EXPRESSION_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/expression.hpp > ~/source/repos/strange/sauce/strange_expression_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "river_forward.hpp"

namespace strange
{

template <typename number_data_a_int64>
class expression_a
{
public:
	// expression
	inline any_a<> generate__(range_a<> const& range) const;
	inline any_a<> generate_(number_data_a_int64 const& indent, river_a<> const& river) const;
	inline void generate(int64_t indent, river_a<> const& river) const;
};

} // namespace strange

#endif
