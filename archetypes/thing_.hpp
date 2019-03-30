#ifndef COM_ONEISH_STRANGE_THING__H
#define COM_ONEISH_STRANGE_THING__H

// ~/source/repos/type_erasure/windows/emtypen.exe --form ~/source/repos/strange/emtypen/root.hpp -c ~/source/repos/strange/archetypes/thing_.hpp > ~/source/repos/strange/sauce/strange_thing_.h

#include "definitions.hpp"

namespace strange
{

class thing_
{
public:
	// function
	inline thing_ mutate(thing_ range);
	inline thing_ extract(thing_ range) const;
	inline thing_ operator()(thing_ range);
	inline thing_ operator()(thing_ range) const;

	// comparison
	inline thing_ same(thing_ range) const;
	inline thing_ different(thing_ range) const;
	inline bool operator==(thing_ thing) const;
	inline bool operator!=(thing_ thing) const;

	inline thing_ is_something(thing_ _ = thing_()) const;
	inline bool is_something_() const;

	inline thing_ is_nothing(thing_ _ = thing_()) const;
	inline bool is_nothing_() const;

	// range
	inline thing_ begin(thing_ _ = thing_());
	inline thing_ cbegin(thing_ _ = thing_()) const;
	inline thing_ end(thing_ _ = thing_());
	inline thing_ cend(thing_ _ = thing_()) const;

	// iterator
	inline thing_ set(thing_ range);
	inline thing_ get(thing_ _ = thing_()) const;
	inline thing_& operator*();
	inline const thing_& operator*() const;
	inline thing_* operator->();
	inline const thing_* operator->() const;

	inline thing_ increment(thing_ _ = thing_());
	inline thing_& operator++();
};

} // namespace strange

#endif
