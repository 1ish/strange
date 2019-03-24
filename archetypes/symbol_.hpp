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
	inline thing_ mutate(thing_ thing);
	inline thing_ extract(thing_ thing) const;
	inline thing_ operator()(thing_ thing);
	inline thing_ operator()(thing_ thing) const;

	// comparison
	inline thing_ same(thing_ thing) const;
	inline thing_ different(thing_ thing) const;
	inline bool operator==(thing_ thing) const;
	inline bool operator!=(thing_ thing) const;

	thing_ is_something(thing_ _) const;
	inline bool is_something_() const;

	thing_ is_nothing(thing_ _) const;
	inline bool is_nothing_() const;

	// range
	inline thing_ begin(thing_ _);
	inline thing_ cbegin(thing_ _) const;
	inline thing_ end(thing_ _);
	inline thing_ cend(thing_ _) const;

	// iterator
	inline thing_ set(thing_ thing);
	inline thing_ get(thing_ _) const;
	inline thing_& operator*();
	inline const thing_& operator*() const;
	inline thing_* operator->();
	inline const thing_* operator->() const;

	inline thing_ increment(thing_ _);
	inline thing_& operator++();

	// symbol
	inline std::size_t hash_() const;

	inline const Everything& me_();
};

} // namespace strange

#endif
