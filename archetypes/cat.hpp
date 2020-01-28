#ifndef COM_ONEISH_STRANGE_CAT_A_H
#define COM_ONEISH_STRANGE_CAT_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/dderived.hpp -c ~/source/repos/strange/archetypes/cat.hpp > ~/source/repos/strange/sauce/strange_cat_a.h
*/

#include "any_forward.hpp"
#include "range_forward.hpp"
#include "symbol_forward.hpp"
#include "flock_forward.hpp"
#include "herd_forward.hpp"
#include "number_forward.hpp"

namespace strange
{

template <typename lake_a_int8>
class cat_a
{
public:
	// cat
	inline any_a<> symbolic__(range_a<> const& _) const;
	inline any_a<> symbolic_() const;
	inline bool symbolic() const;

	inline any_a<> order__(range_a<> const& _) const;
	inline number_data_a<int64_t> order_() const;
	inline int64_t order() const;

	inline any_a<> name__(range_a<> const& _) const;
	inline symbol_a<> name_() const;

	inline any_a<> dimensions__(range_a<> const& _) const;
	inline flock_a<> dimensions_() const;

	inline any_a<> parameters__(range_a<> const& _) const;
	inline flock_a<> parameters_() const;

	inline any_a<> result__(range_a<> const& _) const;
	inline cat_a result_() const;

	inline any_a<> code__(range_a<> const& _) const;
	inline lake_a_int8 code_() const;
	inline std::string code() const;
};

} // namespace strange

#endif
