#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

#include "strange_symbol_.h" //TODO thing

namespace strange
{

class Thing
{
};

class Something : public Thing
{
public:
	// conversion
	inline operator bool() const
	{
		return true;
	}
};

class Everything : public Something
{
public:
	static inline symbol_& val(thing_ _ = thing_{}) //TODO thing
	{
		static symbol_ VAL = Everything{}; //TODO thing
		return VAL;
	}

	static inline symbol_& ref(thing_ _ = thing_{}) //TODO thing
	{
		static symbol_ REF(Everything{}, true); //TODO thing
		return REF;
	}

	// function
	inline thing_ extract(thing_) const
	{
		return Everything::val();
	}

	inline thing_ operator()(thing_) const
	{
		return Everything::val();
	}

	inline thing_ mutate(thing_)
	{
		return Everything::val();
	}

	inline thing_ operator()(thing_)
	{
		return Everything::val();
	}

	// comparison
	inline thing_ same(thing_ range) const;

	inline thing_ same_(thing_ thing) const;

	inline bool operator==(thing_ thing) const
	{
		return thing;
	}

	inline thing_ different(thing_ range) const;

	inline thing_ different_(thing_ thing) const;

	inline bool operator!=(thing_ thing) const
	{
		return !thing;
	}

	inline thing_ is_something(thing_) const
	{
		return Everything::val();
	}

	inline thing_ is_something_() const
	{
		return Everything::val();
	}

	inline thing_ is_nothing(thing_) const;

	inline thing_ is_nothing_() const;

	inline thing_ hash(thing_) const
	{
		return Everything::val();
	}

	inline thing_ hash_() const
	{
		return Everything::val();
	}

	inline size_t hash__() const
	{
		return 1;
	}

	// range
	inline thing_ begin_get(thing_) const
	{
		return Everything::val();
	}

	inline thing_ begin_get_() const
	{
		return Everything::val();
	}

	inline thing_ cbegin() const
	{
		return Everything::val();
	}

	inline thing_ begin_set(thing_)
	{
		return Everything::val();
	}

	inline thing_ begin_set_()
	{
		return Everything::val();
	}

	inline thing_ begin()
	{
		return Everything::val();
	}

	inline thing_ end_get(thing_) const
	{
		return Everything::val();
	}

	inline thing_ end_get_() const
	{
		return Everything::val();
	}

	inline thing_ cend() const
	{
		return Everything::val();
	}

	inline thing_ end_set(thing_)
	{
		return Everything::val();
	}

	inline thing_ end_set_()
	{
		return Everything::val();
	}

	inline thing_ end()
	{
		return Everything::val();
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return Everything::val();
	}

	inline thing_ get_() const
	{
		return Everything::val();
	}

	inline thing_ set(thing_) const
	{
		return Everything::val();
	}

	inline thing_ set_(thing_) const
	{
		return Everything::val();
	}

	inline thing_& operator*() const
	{
		return Everything::val();
	}

	inline thing_* operator->() const
	{
		return &Everything::val();
	}

	inline thing_ increment(thing_)
	{
		return Everything::val();
	}

	inline thing_ increment_()
	{
		return Everything::val();
	}

	inline thing_& operator++()
	{
		return Everything::val();
	}

	//TODO symbol
	inline symbol_ add(thing_ range) const
	{
		return Everything::val();
	}

	inline symbol_ add_(symbol_ symbol) const
	{
		return Everything::val();
	}

	inline symbol_ operator+(symbol_ symbol) const
	{
		return Everything::val();
	}

private:
	inline Everything() {};
};

} // namespace strange

#endif
