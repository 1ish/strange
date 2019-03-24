#ifndef COM_ONEISH_STRANGE_THING__HPP
#define COM_ONEISH_STRANGE_THING__HPP

// ~/source/repos/type_erasure/windows/emtypen.exe -c --form ~/source/repos/type_erasure/windows/cow.hpp ~/source/repos/strange/archetypes/thing_.hpp > ~/source/repos/strange/sauce/strange_thing_.h

namespace strange
{

class thing_
{
public:
	// function
	thing_ mutate(thing_ thing);
	thing_ extract(thing_ thing) const;
	thing_ operator()(thing_ thing);
	thing_ operator()(thing_ thing) const;

	// comparison
	thing_ same(thing_ thing) const;
	thing_ different(thing_ thing) const;
	bool operator==(thing_ thing) const;
	bool operator!=(thing_ thing) const;

	thing_ is_something(thing_ _) const;
	bool is_something_() const;

	thing_ is_nothing(thing_ _) const;
	bool is_nothing_() const;

	// range
	thing_ begin(thing_ _);
	thing_ cbegin(thing_ _) const;
	thing_ end(thing_ _);
	thing_ cend(thing_ _) const;

	// iterator
	thing_ set(thing_ thing);
	thing_ get(thing_ _) const;
	thing_& operator*();
	const thing_& operator*() const;
	thing_* operator->();
	const thing_* operator->() const;

	thing_ increment(thing_ _);
	thing_& operator++();
};

} // namespace strange

#endif
