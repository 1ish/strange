#ifndef COM_ONEISH_STRANGE_ANY_A_H
#define COM_ONEISH_STRANGE_ANY_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/root.hpp -c ~/source/repos/strange/archetypes/any.hpp > ~/source/repos/strange/sauce/strange_any_a.h
*/

#include "definitions.hpp"
#include "range_forward.hpp"
#include "symbol_forward.hpp"
#include "cat_forward.hpp"
#include "unordered_shoal_forward.hpp"
#include "number_data_forward.hpp"

namespace strange
{

template <typename range_a = range_a<>, typename symbol_a = symbol_a<>, typename cat_a = cat_a<>, typename unordered_shoal_a = unordered_shoal_a<>, typename number_data_a_uint64 = number_data_a<uint64_t>>
class any_a
{
public:
	class hash_f
	{
	public:
		inline std::size_t operator()(any_a const& thing) const
		{
			return thing.hash();
		}
	};

	// reflection
	inline any_a type__(range_a const& _) const;
	inline symbol_a type_() const;

	inline any_a cat__(range_a const& _) const;
	inline cat_a cat_() const;

//	unordered_herd_a<cat_a> inline any_a cats__(range_a const& _) const;
//	unordered_herd_a<cat_a> inline any_a cats_() const;

//	void inline any_a share__(range_a const& range) const;
	
//	unordered_shoal_a<symbol_a, any_a> inline any_a shared__(range_a const& _) const;

	inline any_a operations__(range_a const& _) const;
	inline unordered_shoal_a operations_() const;

	inline any_a eater__(range_a const& _) const;
	inline any_a eater_() const; // return range of parameter names

	inline any_a feeder__(range_a const& range) const; // return range of parameter values

	// visitor pattern
	inline any_a visit__(range_a const& range);

	// function
	inline any_a invoke__(range_a const& range) const;
	inline any_a invoke_(any_a const& member, range_a const& range) const;
	inline any_a operate__(range_a const& range) const;
	inline any_a operate_(any_a const& thing, any_a const& operation, range_a const& range) const;
	inline any_a operator()(any_a const& thing, range_a const& range) const;

	// identification
	inline void const* identity() const;

	inline any_a identical__(range_a const& range) const;
	inline any_a identical_(any_a const& thing) const;
	inline bool identical(any_a const& thing) const;

	// comparison
	inline any_a nothing__(range_a const& _) const;
	inline any_a nothing_() const;
	inline bool nothing() const;

	inline any_a everything__(range_a const& _) const;
	inline any_a everything_() const;
	inline bool everything() const;

	inline any_a anything__(range_a const& _) const;
	inline any_a anything_() const;
	inline bool anything() const;

	inline any_a something__(range_a const& _) const;
	inline any_a something_() const;
	inline bool something() const;

	inline any_a same__(range_a const& range) const;
	inline any_a same_(any_a const& thing) const;
	inline bool operator==(any_a const& thing) const;

	inline any_a different__(range_a const& range) const;
	inline any_a different_(any_a const& thing) const;
	inline bool operator!=(any_a const& thing) const;

	inline any_a hash__(range_a const& _) const;
	inline number_data_a_uint64 hash_() const;
	inline std::size_t hash() const;

	inline bool is(std::string const& s) const;

	// conversion
	inline any_a ranged__(range_a const& _) const;
	inline range_a ranged_() const;
};

} // namespace strange

#endif
