#ifndef COM_ONEISH_STRANGE_ANY_A_H
#define COM_ONEISH_STRANGE_ANY_A_H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/root.hpp -c ~/source/repos/strange/archetypes/any.hpp > ~/source/repos/strange/sauce/strange_any_a.h
*/

#include "definitions.hpp"

namespace strange
{

class any
{
public:
	// construction
	inline any_a val(any_a range) const;
	inline any_a ref(any_a range) const;

	// reflection
	inline any_a type(any_a _) const;
	inline any_a type_() const;

	inline any_a cat(any_a _) const;
	inline any_a cat_() const;

//	herd_a<cat_a> inline any_a cats(any_a _) const;
//	herd_a<cat_a> inline any_a cats_() const;

//	void inline any_a share(any_a range) const;
	
//	shoal_a<symbol_a, any_a> inline any_a shared(any_a _) const;

//  shoal_a<symbol_a, any_a> inline any_a operations(any_a _) const;
//  shoal_a<symbol_a, any_a> inline any_a operations_() const;

	inline any_a eater(any_a _) const;
	inline any_a eater_() const; // return range of parameter names

	inline any_a feeder(any_a range) const; // return range of parameter values

	// visitor pattern
	inline any_a visit(any_a range);

	// function
	inline any_a invoke(any_a range) const;
	inline any_a invoke_(any_a member, any_a range) const;
	inline any_a operate(any_a range) const;
	inline any_a operate_(any_a thing, any_a operation, any_a range) const;
	inline any_a operator()(any_a thing, any_a range) const;

	// identification
	inline const void* identity__() const;

	inline any_a identical(any_a range) const;
	inline any_a identical_(any_a thing) const;
	inline bool identical__(any_a thing) const;

	// comparison
	inline any_a nothing(any_a _) const;
	inline any_a nothing_() const;
	inline bool nothing__() const;

	inline any_a anything(any_a _) const;
	inline any_a anything_() const;
	inline bool anything__() const;

	inline any_a something(any_a _) const;
	inline any_a something_() const;
	inline bool something__() const;

	inline any_a everything(any_a _) const;
	inline any_a everything_() const;
	inline bool everything__() const;

	inline any_a same(any_a range) const;
	inline any_a same_(any_a thing) const;
	inline bool operator==(any_a thing) const;

	inline any_a different(any_a range) const;
	inline any_a different_(any_a thing) const;
	inline bool operator!=(any_a thing) const;

	inline any_a hash(any_a _) const;
	inline any_a hash_() const;
	inline std::size_t hash__() const;

	inline bool is__(const std::string& s) const;

	// range
	inline any_a beget(any_a _) const;
	inline any_a beget_() const;
	inline any_a cbegin() const;

	inline any_a beset(any_a _);
	inline any_a beset_();
	inline any_a begin();

	inline any_a enget(any_a _) const;
	inline any_a enget_() const;
	inline any_a cend() const;

	inline any_a enset(any_a _);
	inline any_a enset_();
	inline any_a end();

	// iterator
	inline any_a get(any_a _) const;
	inline any_a get_() const;
	inline any_a set(any_a range) const;
	inline any_a set_(any_a thing) const;
	inline any_a& operator*() const;
	inline any_a* operator->() const;

	inline any_a increment(any_a _);
	inline any_a increment_();
};

} // namespace strange

#endif
