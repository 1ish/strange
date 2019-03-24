#ifndef COM_ONEISH_STRANGE_SYMBOL__H
#define COM_ONEISH_STRANGE_SYMBOL__H

// ~/source/repos/type_erasure/windows/emtypen.exe -c ~/source/repos/strange/archetypes/symbol_.hpp > ~/source/repos/strange/sauce/strange_symbol_.h

#include "thing_.hpp"

namespace strange
{

class symbol_
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

	// symbol
	inline std::size_t hash_() const;
};

} // namespace strange

#endif
