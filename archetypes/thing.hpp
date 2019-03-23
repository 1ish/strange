#ifndef COM_ONEISH_STRANGE_THING_H
#define COM_ONEISH_STRANGE_THING_H

// ~/source/repos/type_erasure/windows/emtypen.exe -c --form ~/source/repos/type_erasure/windows/cow.hpp ~/source/repos/strange/archetypes/thing.hpp > ~/source/repos/strange/sauce/strange_thing.h

namespace strange
{

class Thing
{
public:
	// function
	Thing mutate(Thing thing);
	Thing extract(Thing thing) const;
	Thing operator()(Thing thing);
	Thing operator()(Thing thing) const;

	// comparison
	Thing same(Thing thing) const;
	Thing different(Thing thing) const;
	bool operator==(Thing thing) const;
	bool operator!=(Thing thing) const;

	Thing is_something(Thing thing) const;
	bool is_something_() const;

	Thing is_nothing(Thing thing) const;
	bool is_nothing_() const;

	// range
	Thing begin(Thing thing);
	Thing cbegin(Thing thing) const;
	Thing end(Thing thing);
	Thing cend(Thing thing) const;

	// iterator
	Thing set(Thing thing);
	Thing get(Thing thing) const;
	Thing& operator*();
	const Thing& operator*() const;
	Thing* operator->();
	const Thing* operator->() const;

	Thing increment(Thing thing);
	Thing& operator++();
};

} // namespace strange

#endif
