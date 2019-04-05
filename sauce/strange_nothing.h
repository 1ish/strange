#ifndef COM_ONEISH_STRANGE_NOTHING_H
#define COM_ONEISH_STRANGE_NOTHING_H

#include "strange_thing_.h"
#include "strange_everything.h"

namespace strange
{

template <typename THING_ = thing_>
class Nothing : public Something<THING_, false>
{
public:
	// construction
	static inline thing_& val(thing_ _ = thing_{})
	{
		static thing_ VAL = []()
		{
			thing_ thing;
			thing = Nothing<>{ thing };
			return thing;
		}();
		return VAL;
	}

	static inline thing_& ref(thing_ _ = thing_{})
	{
		static thing_ REF = []()
		{
			thing_ thing{ true };
			thing = Nothing<>{ thing };
			return thing;
		}();
		return REF;
	}

	// comparison
	inline thing_ same(thing_ range) const
	{
		const auto other = range.cbegin();
		assert(other != range.cend()); //TODO throw
		return _boole_(other.hash__() == 0);
	}

	inline thing_ same_(thing_ thing) const
	{
		return _boole_(thing.hash__() == 0);
	}

	inline bool operator==(thing_ thing) const
	{
		return thing.hash__() == 0;
	}

	inline thing_ different(thing_ range) const
	{
		const auto other = range.cbegin();
		assert(other != range.cend()); //TODO throw
		return _boole_(other.hash__() != 0);
	}

	inline thing_ different_(thing_ thing) const
	{
		return _boole_(thing.hash__() != 0);
	}

	inline bool operator!=(thing_ thing) const
	{
		return thing.hash__() != 0;
	}

	inline thing_ hash(thing_) const
	{
		return Nothing<>::val();
	}

	inline thing_ hash_() const
	{
		return Nothing<>::val();
	}

	inline size_t hash__() const
	{
		return 0;
	}

	// range
	inline thing_ begin_get(thing_) const
	{
		return Nothing<>::val();
	}

	inline thing_ begin_get_() const
	{
		return Nothing<>::val();
	}

	inline thing_ cbegin() const
	{
		return Nothing<>::val();
	}

	inline thing_ begin_set(thing_)
	{
		return Nothing<>::val();
	}

	inline thing_ begin_set_()
	{
		return Nothing<>::val();
	}

	inline thing_ begin()
	{
		return Nothing<>::val();
	}

	inline thing_ end_get(thing_) const
	{
		return Nothing<>::val();
	}

	inline thing_ end_get_() const
	{
		return Nothing<>::val();
	}

	inline thing_ cend() const
	{
		return Nothing<>::val();
	}

	inline thing_ end_set(thing_)
	{
		return Nothing<>::val();
	}

	inline thing_ end_set_()
	{
		return Nothing<>::val();
	}

	inline thing_ end()
	{
		return Nothing<>::val();
	}

	// iterator
	inline thing_ get(thing_) const
	{
		return Nothing<>::val();
	}

	inline thing_ get_() const
	{
		return Nothing<>::val();
	}

	inline thing_ set(thing_) const
	{
		return Nothing<>::val();
	}

	inline thing_ set_(thing_) const
	{
		return Nothing<>::val();
	}

	inline thing_& operator*() const
	{
		return Nothing<>::val();
	}

	inline thing_* operator->() const
	{
		return &Nothing<>::val();
	}

	inline thing_ increment(thing_)
	{
		return Nothing<>::val();
	}

	inline thing_ increment_()
	{
		return Nothing<>::val();
	}

	inline thing_& operator++()
	{
		return Nothing<>::val();
	}

protected:
	inline Nothing(const thing_& me)
		: Something{ me }
	{};
};

} // namespace strange

#endif
