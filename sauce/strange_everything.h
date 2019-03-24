#ifndef COM_ONEISH_STRANGE_EVERYTHING_H
#define COM_ONEISH_STRANGE_EVERYTHING_H

#include "strange_thing.h"

namespace strange
{

class Everything
{
public:
	static inline Thing& val(Thing _ = Thing())
	{
		static Thing VAL = Everything{};
		return VAL;
	}

	// function
	inline Thing mutate(Thing _ = Thing())
	{
		return Everything::val();
	}

	inline Thing extract(Thing _ = Thing()) const
	{
		return Everything::val();
	}

	inline Thing operator()(Thing _ = Thing())
	{
		return Everything::val();
	}

	inline Thing operator()(Thing _ = Thing()) const
	{
		return Everything::val();
	}

	// comparison
	inline Thing same(Thing thing) const;

	inline Thing different(Thing thing) const;

	inline bool operator==(Thing thing) const
	{
		return thing.is_something_();
	}

	inline bool operator!=(Thing thing) const
	{
		return thing.is_nothing_();
	}

	inline Thing is_something(Thing _ = Thing()) const
	{
		return Everything::val();
	}

	inline bool is_something_() const
	{
		return true;
	}

	inline Thing is_nothing(Thing _ = Thing()) const;

	inline bool is_nothing_() const { return false; };

	// range
	inline Thing begin(Thing _ = Thing())
	{
		return Everything::val();
	}

	inline Thing cbegin(Thing _ = Thing()) const
	{
		return Everything::val();
	}

	inline Thing end(Thing _ = Thing())
	{
		return Everything::val();
	}

	inline Thing cend(Thing _ = Thing()) const
	{
		return Everything::val();
	}

	// iterator
	inline Thing set(Thing thing)
	{
		return Everything::val();
	}

	inline Thing get(Thing _ = Thing()) const
	{
		return Everything::val();
	}

	inline Thing& operator*()
	{
		return Everything::val();
	}

	inline const Thing& operator*() const
	{
		return Everything::val();
	}

	inline Thing* operator->()
	{
		return &Everything::val();
	}

	inline const Thing* operator->() const
	{
		return &Everything::val();
	}

	inline Thing increment(Thing _ = Thing())
	{
		return Everything::val();
	}

	inline Thing& operator++()
	{
		return Everything::val();
	}
};

} // namespace strange

#endif
