#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

#include "strange_symbol_.h" //TODO thing

namespace strange
{

template <typename THING_>
class Thing
{
public:
	const THING_ me_() const
	{
		return THING_(_meek.lock(), true);
	}

	THING_ me_()
	{
		return THING_(_meek.lock(), true);
	}

protected:
	inline Thing(const THING_& me)
		: _meek(me.weak_())
	{}

private:
	const decltype(THING_().weak_()) _meek;
};

template <typename THING_>
class Something : public Thing<THING_>
{
public:
	// conversion
	inline operator bool() const
	{
		return true;
	}

protected:
	inline Something(const thing_& me)
		: Thing{ me }
	{};
};

template <typename THING_>
class Creature : public Something<THING_>
{
public:
	// function
	inline thing_ extract(thing_ range) const;
	inline thing_ operator()(thing_ range) const;
	inline thing_ mutate(thing_ range);
	inline thing_ operator()(thing_ range);

protected:
	inline Creature(const thing_& me)
		: Something{ me }
	{};
};

template <typename THING_ = thing_>
class Everything : public Creature<THING_>
{
public:
	// construction
	static inline symbol_& val(thing_ _ = thing_{}) //TODO thing_
	{
		static symbol_ VAL = []() //TODO thing_
		{
			symbol_ thing; //TODO thing_
			thing = Everything<>{thing};
			return thing;
		}();
		return VAL;
	}

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
		return Everything<>::val();
	}

	inline thing_ is_something_() const
	{
		return Everything<>::val();
	}

	inline thing_ is_nothing(thing_) const;

	inline thing_ is_nothing_() const;

	inline thing_ hash(thing_) const
	{
		return Everything<>::val();
	}

	inline thing_ hash_() const
	{
		return Everything<>::val();
	}

	inline size_t hash__() const
	{
		return 1;
	}

	// range
	inline thing_ begin_get(thing_) const
	{
		return Everything<>::val();
	}

	inline thing_ begin_get_() const
	{
		return Everything<>::val();
	}

	inline thing_ cbegin() const
	{
		return Everything<>::val();
	}

	inline thing_ begin_set(thing_)
	{
		return Everything<>::val();
	}

	inline thing_ begin_set_()
	{
		return Everything<>::val();
	}

	inline thing_ begin()
	{
		return Everything<>::val();
	}

	inline thing_ end_get(thing_) const
	{
		return Everything<>::val();
	}

	inline thing_ end_get_() const
	{
		return Everything<>::val();
	}

	inline thing_ cend() const
	{
		return Everything<>::val();
	}

	inline thing_ end_set(thing_)
	{
		return Everything<>::val();
	}

	inline thing_ end_set_()
	{
		return Everything<>::val();
	}

	inline thing_ end()
	{
		return Everything<>::val();
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return Everything<>::val();
	}

	inline thing_ get_() const
	{
		return Everything<>::val();
	}

	inline thing_ set(thing_) const
	{
		return Everything<>::val();
	}

	inline thing_ set_(thing_) const
	{
		return Everything<>::val();
	}

	inline thing_& operator*() const
	{
		return Everything<>::val();
	}

	inline thing_* operator->() const
	{
		return &Everything<>::val();
	}

	inline thing_ increment(thing_)
	{
		return Everything<>::val();
	}

	inline thing_ increment_()
	{
		return Everything<>::val();
	}

	inline thing_& operator++()
	{
		return Everything<>::val();
	}

	//TODO symbol
	inline symbol_ add(thing_ range) const
	{
		return Everything<>::val();
	}

	inline symbol_ add_(symbol_ symbol) const
	{
		return Everything<>::val();
	}

	inline symbol_ operator+(symbol_ symbol) const
	{
		return Everything<>::val();
	}

protected:
	inline Everything(const thing_& me)
		: Creature{ me }
	{};
};

} // namespace strange

#endif
