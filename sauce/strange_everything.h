#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

#include "strange_symbol_.h" //TODO thing

namespace strange
{

class Everything
{
public:
	static inline symbol_& val(thing_ _ = thing_{}) //TODO thing
	{
		static symbol_ VAL = Everything{}; //TODO thing
		return VAL;
	}

	// function
	inline thing_ mutate(thing_)
	{
		return Everything::val();
	}

	inline thing_ extract(thing_) const
	{
		return Everything::val();
	}

	inline thing_ operator()(thing_)
	{
		return Everything::val();
	}

	inline thing_ operator()(thing_) const
	{
		return Everything::val();
	}

	// comparison
	inline thing_ same(thing_ range) const;

	inline thing_ different(thing_ range) const;

	inline bool operator==(thing_ thing) const
	{
		return thing.is_something_();
	}

	inline bool operator!=(thing_ thing) const
	{
		return thing.is_nothing_();
	}

	inline thing_ is_something(thing_) const
	{
		return Everything::val();
	}

	inline bool is_something_() const
	{
		return true;
	}

	inline thing_ is_nothing(thing_) const;

	inline bool is_nothing_() const
	{
		return false;
	}

	// range
	inline thing_ begin(thing_)
	{
		return Everything::val();
	}

	inline thing_ cbegin(thing_) const
	{
		return Everything::val();
	}

	inline thing_ end(thing_)
	{
		return Everything::val();
	}

	inline thing_ cend(thing_) const
	{
		return Everything::val();
	}

	// iterator
	inline thing_ set(thing_)
	{
		return Everything::val();
	}

	inline thing_ get(thing_) const
	{
		return Everything::val();
	}

	inline thing_& operator*()
	{
		return Everything::val();
	}

	inline const thing_& operator*() const
	{
		return Everything::val();
	}

	inline thing_* operator->()
	{
		return &Everything::val();
	}

	inline const thing_* operator->() const
	{
		return &Everything::val();
	}

	inline thing_ increment(thing_)
	{
		return Everything::val();
	}

	inline thing_& operator++()
	{
		return Everything::val();
	}

	// symbol
	inline std::size_t hash_() const
	{
		return 0;
	}

private:
	inline Everything() {};
};

} // namespace strange

#endif
