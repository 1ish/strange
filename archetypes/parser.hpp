#ifndef COM_ONEISH_STRANGE_PARSER_A_H
#define COM_ONEISH_STRANGE_PARSER_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/parser.hpp > ~/source/repos/strange/sauce/strange_parser_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "expression_forward.hpp"

namespace strange
{

template <typename _1_>
class parser_a
{
public:
	// parser
	inline expression_a<> parse_(range_a<> const& tokenizer);
};

} // namespace strange

#endif
