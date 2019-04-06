#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

#include "strange_symbol_.h" //TODO thing_
#include "strange_something.h"

namespace strange
{

template <typename THING_ = thing_>
class Everything : public Something<THING_>
{
public:
	// construction
	static inline symbol_& ref(thing_ _ = thing_{}) //TODO thing_
	{
		static symbol_ REF = []() //TODO thing_
		{
			symbol_ thing{ true }; //TODO thing_
			thing = Everything<>{ thing };
			return thing;
		}();
		return REF;
	}

	// comparison
	inline thing_ same(thing_ range) const
	{
		const auto other = range.cbegin();
		assert(other != range.cend()); //TODO throw
		return _boole_(other.hash__() == 1);
	}

	inline thing_ same_(thing_ thing) const
	{
		return _boole_(thing.hash__() == 1);
	}

	inline bool operator==(thing_ thing) const
	{
		return thing.hash__() == 1;
	}

	inline thing_ different(thing_ range) const
	{
		const auto other = range.cbegin();
		assert(other != range.cend()); //TODO throw
		return _boole_(other.hash__() != 1);
	}

	inline thing_ different_(thing_ thing) const
	{
		return _boole_(thing.hash__() != 1);
	}

	inline bool operator!=(thing_ thing) const
	{
		return thing.hash__() != 1;
	}

	inline thing_ hash(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ hash_() const
	{
		return Everything<>::ref();
	}

	inline size_t hash__() const
	{
		return 1;
	}

	// range
	inline thing_ begin_get(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ begin_get_() const
	{
		return Everything<>::ref();
	}

	inline thing_ cbegin() const
	{
		return Everything<>::ref();
	}

	inline thing_ begin_set(thing_)
	{
		return Everything<>::ref();
	}

	inline thing_ begin_set_()
	{
		return Everything<>::ref();
	}

	inline thing_ begin()
	{
		return Everything<>::ref();
	}

	inline thing_ end_get(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ end_get_() const
	{
		return Everything<>::ref();
	}

	inline thing_ cend() const
	{
		return Everything<>::ref();
	}

	inline thing_ end_set(thing_)
	{
		return Everything<>::ref();
	}

	inline thing_ end_set_()
	{
		return Everything<>::ref();
	}

	inline thing_ end()
	{
		return Everything<>::ref();
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ get_() const
	{
		return Everything<>::ref();
	}

	inline thing_ set(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_ set_(thing_) const
	{
		return Everything<>::ref();
	}

	inline thing_& operator*() const
	{
		return Everything<>::ref();
	}

	inline thing_* operator->() const
	{
		return &Everything<>::ref();
	}

	inline thing_ increment(thing_)
	{
		return Everything<>::ref();
	}

	inline thing_ increment_()
	{
		return Everything<>::ref();
	}

	inline thing_& operator++()
	{
		return Everything<>::ref();
	}

	//TODO symbol
	inline symbol_ add(thing_ range) const
	{
		return Everything<>::ref();
	}

	inline symbol_ add_(symbol_ symbol) const
	{
		return Everything<>::ref();
	}

	inline symbol_ operator+(symbol_ symbol) const
	{
		return Everything<>::ref();
	}

protected:
	inline Everything(const thing_& me)
		: Something{ me }
	{};
};

} // namespace strange

#endif
