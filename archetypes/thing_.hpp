#ifndef COM_ONEISH_STRANGE_THING__H
#define COM_ONEISH_STRANGE_THING__H

/*
~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/root.hpp -c ~/source/repos/strange/archetypes/thing_.hpp > ~/source/repos/strange/sauce/strange_thing_.h
*/

#include "definitions.hpp"

namespace strange
{

class thing_
{
public:
	// construction
	inline thing_ val(thing_ range) const;
	inline thing_ ref(thing_ range) const;

	// reflection

//	symbol_ inline thing_ type(thing_ _) const;
//	symbol_ inline thing_ type_() const;

//	cat_ inline thing_ cat(thing_ _) const;
//	cat_ inline thing_ cat_() const;

//	herd_<cat_> inline thing_ cats(thing_ _) const;
//	herd_<cat_> inline thing_ cats_() const;

//	void inline thing_ share(thing_ range) const;
	
//	shoal_<symbol_, thing_> inline thing_ shared(thing_ _) const;

//	shoal_<symbol_, thing_> inline thing_ pub(thing_ _) const;

//	shoal_<symbol_, thing_> inline thing_ creator_() const;

//	flock_<symbol_> inline thing_ eater(thing_ _) const;
//	flock_<symbol_> inline thing_ eater_() const; // return range of parameter names

//	flock_<thing_> inline thing_ feeder(thing_ eater) const; // return range of parameter values

	// serialization

//	inline thing_ visit(thing_ range); // used for serialization

	// function
	inline thing_ extract(thing_ range) const;
	inline thing_ operator()(thing_ range) const;

	inline thing_ mutate(thing_ range);
	inline thing_ operator()(thing_ range);

	// identification
	inline const void* identity__() const;

	inline thing_ identical(thing_ range) const;
	inline thing_ identical_(thing_ thing) const;
	inline bool identical__(thing_ thing) const;

	// comparison
	inline thing_ same(thing_ range) const;
	inline thing_ same_(thing_ thing) const;
	inline bool operator==(thing_ thing) const;

	inline thing_ different(thing_ range) const;
	inline thing_ different_(thing_ thing) const;
	inline bool operator!=(thing_ thing) const;

	inline thing_ hash(thing_ _) const;
	inline thing_ hash_() const;
	inline std::size_t hash__() const;

	inline thing_ nothing(thing_ _) const;
	inline thing_ nothing_() const;
	inline bool nothing__() const;

	inline thing_ anything(thing_ _) const;
	inline thing_ anything_() const;
	inline bool anything__() const;

	inline thing_ something(thing_ _) const;
	inline thing_ something_() const;
	inline bool something__() const;

	inline thing_ everything(thing_ _) const;
	inline thing_ everything_() const;
	inline bool everything__() const;

	// range
	inline thing_ beget(thing_ _) const;
	inline thing_ beget_() const;
	inline thing_ cbegin() const;

	inline thing_ beset(thing_ _);
	inline thing_ beset_();
	inline thing_ begin();

	inline thing_ enget(thing_ _) const;
	inline thing_ enget_() const;
	inline thing_ cend() const;

	inline thing_ enset(thing_ _);
	inline thing_ enset_();
	inline thing_ end();

	// iterator
	inline thing_ get(thing_ _) const;
	inline thing_ get_() const;
	inline thing_ set(thing_ range) const;
	inline thing_ set_(thing_ thing) const;
	inline thing_& operator*() const;
	inline thing_* operator->() const;

	inline thing_ increment(thing_ _);
	inline thing_ increment_();
};

} // namespace strange

#endif
