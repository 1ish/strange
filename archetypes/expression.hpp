#ifndef COM_ONEISH_STRANGE_EXPRESSION_A_H
#define COM_ONEISH_STRANGE_EXPRESSION_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/finale.hpp -c ~/source/repos/strange/archetypes/expression.hpp > ~/source/repos/strange/sauce/strange_expression_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "token_forward.hpp"
#include "flock_forward.hpp"
#include "unordered_shoal_forward.hpp"
#include "river_forward.hpp"

namespace strange
{

template <typename number_data_a_int64>
class expression_a
{
public:
	// expression
	inline any_a<> recreate__(range_a<> const& _) const;
	inline expression_a recreate_() const;
	inline void recreated(expression_a const& expression) const;

	inline any_a<> literal__(range_a<> const& _) const;
	inline any_a<> literal_() const;
	inline bool literal() const;

	inline any_a<> evaluate__(range_a<> const& _) const;
	inline any_a<> evaluate_() const;

	inline any_a<> token__(range_a<> const& _) const;
	inline token_a<> token_() const;

	inline any_a<> terms__(range_a<> const& _) const;
	inline flock_a<> terms_() const;

	inline any_a<> generate__(range_a<> const& range) const;
	inline any_a<> generate_(number_data_a_int64 const& version, number_data_a_int64 const& indent, river_a<>& river) const;
	inline void generate(int64_t version, int64_t indent, river_a<>& river) const;

	inline any_a<> generate_cpp__(range_a<> const& range) const;
	inline any_a<> generate_cpp_(number_data_a_int64 const& version, number_data_a_int64 const& indent, river_a<>& river) const;
	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const;

	inline any_a<> generate_cpp_type__(range_a<> const& range) const;
	inline any_a<> generate_cpp_type_(number_data_a_int64 const& version, number_data_a_int64 const& indent, river_a<>& river) const;
	inline void generate_cpp_type(int64_t version, int64_t indent, river_a<>& river) const;
};

} // namespace strange

#endif
