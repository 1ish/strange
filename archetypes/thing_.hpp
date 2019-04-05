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

	// range
	inline thing_ begin_get(thing_ _) const;
	inline thing_ begin_get_() const;
	inline thing_ cbegin() const;

	inline thing_ begin_set(thing_ _);
	inline thing_ begin_set_();
	inline thing_ begin();

	inline thing_ end_get(thing_ _) const;
	inline thing_ end_get_() const;
	inline thing_ cend() const;

	inline thing_ end_set(thing_ _);
	inline thing_ end_set_();
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
	inline thing_& operator++();
};

} // namespace strange

#endif
