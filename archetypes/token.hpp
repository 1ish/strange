#ifndef COM_ONEISH_STRANGE_TOKEN_A_H
#define COM_ONEISH_STRANGE_TOKEN_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/derived.hpp -c ~/source/repos/strange/archetypes/token.hpp > ~/source/repos/strange/sauce/strange_token_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "symbol_forward.hpp"
#include "misunderstanding_forward.hpp"

namespace strange
{

template <typename number_data_a_int64>
class token_a
{
public:
	// token
	inline any_a<> filename__(range_a<> const& _) const;
	inline symbol_a<> filename_() const;
	inline std::string filename() const;

	inline any_a<> line__(range_a<> const& _) const;
	inline number_data_a_int64 line_() const;
	inline int64_t line() const;

	inline any_a<> position__(range_a<> const& _) const;
	inline number_data_a_int64 position_() const;
	inline int64_t position() const;

	inline any_a<> tag__(range_a<> const& _) const;
	inline symbol_a<> tag_() const;
	inline std::string tag() const;

	inline any_a<> symbol__(range_a<> const& _) const;
	inline symbol_a<> symbol_() const;
	inline std::string symbol() const;

	inline any_a<> literal__(range_a<> const& _) const;
	inline any_a<> literal_() const;

	inline any_a<> precedence__(range_a<> const& _) const;
	inline number_data_a_int64 precedence_() const;
	inline int64_t precedence() const;

	inline any_a<> report__(range_a<> const& _) const;
	inline misunderstanding_a<> report_() const;
	inline std::string report() const;
};

} // namespace strange

#endif
