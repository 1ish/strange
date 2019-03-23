#ifndef COM_ONEISH_STRANGE_ONEISH_H
#define COM_ONEISH_STRANGE_ONEISH_H

#include "strange_thing.h"

namespace strange
{

class Oneish
{
public:
	static inline Thing& oneish_()
	{
		static Thing ONEISH = Oneish{};
		return ONEISH;
	}

	// function
	inline Thing mutate(Thing thing = Thing())
	{
		return oneish_();
	}

	inline Thing extract(Thing thing = Thing()) const
	{
		return oneish_();
	}

	inline Thing operator()(Thing thing = Thing())
	{
		return oneish_();
	}

	inline Thing operator()(Thing thing = Thing()) const
	{
		return oneish_();
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

	inline Thing is_something(Thing thing = Thing()) const
	{
		return oneish_();
	}

	inline bool is_something_() const
	{
		return true;
	}

	inline Thing is_nothing(Thing thing = Thing()) const;

	inline bool is_nothing_() const { return false; };

	// range
	inline Thing begin(Thing thing = Thing())
	{
		return oneish_();
	}

	inline Thing cbegin(Thing thing = Thing()) const
	{
		return oneish_();
	}

	inline Thing end(Thing thing = Thing())
	{
		return oneish_();
	}

	inline Thing cend(Thing thing = Thing()) const
	{
		return oneish_(); 
	}

	// iterator
	inline Thing set(Thing thing)
	{
		return oneish_();
	}

	inline Thing get(Thing thing = Thing()) const
	{
		return oneish_();
	}

	inline Thing& operator*()
	{
		return oneish_();
	}

	inline const Thing& operator*() const
	{
		return oneish_();
	}

	inline Thing* operator->()
	{
		return &oneish_();
	}

	inline const Thing* operator->() const
	{
		return &oneish_();
	}

	inline Thing increment(Thing thing = Thing())
	{
		return oneish_();
	}

	inline Thing& operator++()
	{
		return oneish_();
	}
};

} // namespace strange

#endif
