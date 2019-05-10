#ifndef COM_ONEISH_STRANGE_ANY_A_H
#define COM_ONEISH_STRANGE_ANY_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/root.hpp -c ~/source/repos/strange/archetypes/any.hpp > ~/source/repos/strange/sauce/strange_any_a.h
*/

#include "definitions.hpp"
#include "symbol_forward.hpp"
#include "cat_forward.hpp"
#include "range_forward.hpp"
#include "number_data_forward.hpp"

namespace strange
{

template <typename symbol_a = symbol_a<>, typename cat_a = cat_a<>, typename range_a = range_a<>, typename number_data_a_uint64 = number_data_a<uint64_t>>
class any_a
{
public:
	class hash_f
	{
	public:
		inline std::size_t operator()(any_a const& thing) const
		{
			return thing.hash__();
		}
	};

	// reflection
	inline any_a type(range_a const& _) const;
	inline symbol_a type_() const;

	inline any_a cat(range_a const& _) const;
	inline cat_a cat_() const;

//	herd_a<cat_a> inline any_a cats(range_a const& _) const;
//	herd_a<cat_a> inline any_a cats_() const;

//	void inline any_a share(range_a const& range) const;
	
//	shoal_a<symbol_a, any_a> inline any_a shared(range_a const& _) const;

//  shoal_a<symbol_a, any_a> inline any_a operations(range_a const& _) const;
//  shoal_a<symbol_a, any_a> inline any_a operations_() const;

	inline any_a eater(range_a const& _) const;
	inline any_a eater_() const; // return range of parameter names

	inline any_a feeder(range_a const& range) const; // return range of parameter values

	// visitor pattern
	inline any_a visit(range_a const& range);

	// function
	inline any_a invoke(range_a const& range) const;
	inline any_a invoke_(any_a const& member, range_a const& range) const;
	inline any_a operate(range_a const& range) const;
	inline any_a operate_(any_a const& thing, any_a const& operation, range_a const& range) const;
	inline any_a operator()(any_a const& thing, range_a const& range) const;

	// identification
	inline void const* identity__() const;

	inline any_a identical(range_a const& range) const;
	inline any_a identical_(any_a const& thing) const;
	inline bool identical__(any_a const& thing) const;

	// comparison
	inline any_a nothing(range_a const& _) const;
	inline any_a nothing_() const;
	inline bool nothing__() const;

	inline any_a anything(range_a const& _) const;
	inline any_a anything_() const;
	inline bool anything__() const;

	inline any_a something(range_a const& _) const;
	inline any_a something_() const;
	inline bool something__() const;

	inline any_a everything(range_a const& _) const;
	inline any_a everything_() const;
	inline bool everything__() const;

	inline any_a same(range_a const& range) const;
	inline any_a same_(any_a const& thing) const;
	inline bool operator==(any_a const& thing) const;

	inline any_a different(range_a const& range) const;
	inline any_a different_(any_a const& thing) const;
	inline bool operator!=(any_a const& thing) const;

	inline any_a hash(range_a const& _) const;
	inline number_data_a_uint64 hash_() const;
	inline std::size_t hash__() const;

	inline bool is__(std::string const& s) const;

	// conversion
	inline range_a to_range(range_a const& _) const;
	inline range_a to_range_() const;
};

} // namespace strange

#endif
