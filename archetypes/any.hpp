#ifndef COM_ONEISH_STRANGE_ANY_A_H
#define COM_ONEISH_STRANGE_ANY_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/root.hpp -c ~/source/repos/strange/archetypes/any.hpp > ~/source/repos/strange/sauce/strange_any_a.h
*/

#include "definitions.hpp"
#include "symbol_forward.hpp"
#include "cat_forward.hpp"
#include "forward_iterator_forward.hpp"

namespace strange
{

template <typename symbol_a = symbol_a<>, typename cat_a = cat_a<>, typename forward_iterator_a = forward_iterator_a<>>
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
	inline symbol_a type(any_a const& _) const;
	inline symbol_a type_() const;

	inline cat_a cat(any_a const& _) const;
	inline cat_a cat_() const;

//	herd_a<cat_a> inline any_a cats(any_a const& _) const;
//	herd_a<cat_a> inline any_a cats_() const;

//	void inline any_a share(any_a const& range) const;
	
//	shoal_a<symbol_a, any_a> inline any_a shared(any_a const& _) const;

//  shoal_a<symbol_a, any_a> inline any_a operations(any_a const& _) const;
//  shoal_a<symbol_a, any_a> inline any_a operations_() const;

	inline any_a eater(any_a const& _) const;
	inline any_a eater_() const; // return range of parameter names

	inline any_a feeder(any_a const& range) const; // return range of parameter values

	// visitor pattern
	inline any_a visit(any_a const& range);

	// function
	inline any_a invoke(any_a const& range) const;
	inline any_a invoke_(any_a const& member, any_a const& range) const;
	inline any_a operate(any_a const& range) const;
	inline any_a operate_(any_a const& thing, any_a const& operation, any_a const& range) const;
	inline any_a operator()(any_a const& thing, any_a const& range) const;

	// identification
	inline void const* identity__() const;

	inline any_a identical(any_a const& range) const;
	inline any_a identical_(any_a const& thing) const;
	inline bool identical__(any_a const& thing) const;

	// comparison
	inline any_a nothing(any_a const& _) const;
	inline any_a nothing_() const;
	inline bool nothing__() const;

	inline any_a anything(any_a const& _) const;
	inline any_a anything_() const;
	inline bool anything__() const;

	inline any_a something(any_a const& _) const;
	inline any_a something_() const;
	inline bool something__() const;

	inline any_a everything(any_a const& _) const;
	inline any_a everything_() const;
	inline bool everything__() const;

	inline any_a same(any_a const& range) const;
	inline any_a same_(any_a const& thing) const;
	inline bool operator==(any_a const& thing) const;

	inline any_a different(any_a const& range) const;
	inline any_a different_(any_a const& thing) const;
	inline bool operator!=(any_a const& thing) const;

	inline any_a hash(any_a const& _) const;
	inline any_a hash_() const;
	inline std::size_t hash__() const;

	inline bool is__(std::string const& s) const;

	// range
	inline any_a beget(any_a const& _) const;
	inline any_a beget_() const;
	inline any_a cbegin() const;
	inline any_a begin() const;

	inline any_a beset(any_a const& _);
	inline any_a beset_();
	inline any_a begin();

	inline any_a enget(any_a const& _) const;
	inline any_a enget_() const;
	inline any_a cend() const;
	inline any_a end() const;

	inline any_a enset(any_a const& _);
	inline any_a enset_();
	inline any_a end();

	// iterator
	inline any_a get(any_a const& _) const;
	inline any_a get_() const;
	inline any_a set(any_a const& range) const;
	inline any_a set_(any_a const& thing) const;
	inline any_a& operator*() const;
	inline any_a* operator->() const;

	inline any_a increment(any_a const& _);
	inline any_a increment_();
};

} // namespace strange

#endif
