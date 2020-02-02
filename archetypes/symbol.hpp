#ifndef COM_ONEISH_STRANGE_SYMBOL_A_H
#define COM_ONEISH_STRANGE_SYMBOL_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/symbol.hpp > ~/source/repos/strange/sauce/strange_symbol_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "lake_forward.hpp"

namespace strange
{

template <typename _1_>
class symbol_a
{
public:
	// symbol
	inline any_a<> to_lake__(range_a<> const& range) const;
	inline lake_int8_a<> to_lake_() const;

	inline std::string const& to_string() const;

	inline int8_t first_character() const;
	inline int8_t last_character() const;

	inline any_a<> add__(range_a<> const& range) const;
	inline symbol_a add_(symbol_a const& symbol) const;
	inline symbol_a operator+(symbol_a const& symbol) const;
};

} // namespace strange

#endif
