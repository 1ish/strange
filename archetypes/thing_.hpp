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

	// function
	inline thing_ extract(thing_ range) const;
	inline thing_ operator()(thing_ range) const;

	inline thing_ mutate(thing_ range);
	inline thing_ operator()(thing_ range);

	// comparison
	inline thing_ same(thing_ range) const;
	inline thing_ same_(thing_ thing) const;
	inline bool operator==(thing_ thing) const;

	inline thing_ different(thing_ range) const;
	inline thing_ different_(thing_ thing) const;
	inline bool operator!=(thing_ thing) const;

	inline thing_ is_something(thing_ _) const;
	inline thing_ is_something_() const;

	inline thing_ is_nothing(thing_ _) const;
	inline thing_ is_nothing_() const;

	inline thing_ hash(thing_ _) const;
	inline thing_ hash_() const;
	inline size_t hash__() const;

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
	inline thing_ operator++();
};

} // namespace strange

#endif
