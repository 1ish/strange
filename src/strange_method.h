#ifndef COM_ONEISH_STRANGE_METHOD_H
#define COM_ONEISH_STRANGE_METHOD_H

#include "strange_core.h"

namespace strange
{
	class Method;

	// Categories:
	// private typedefs
	// protected typedefs
	// public typedefs
	// public static utility functions
	// public static factory functions
	// public static symbols
	// public construction/destruction/assignment
	// public pure virtual member functions and adapters
	// public impure virtual member functions and adapters
	// public non-virtual member functions and adapters
	// protected static utility functions
	// protected static factory functions
	// protected static symbols
	// protected construction/destruction/assignment
	// protected pure virtual member functions and adapters
	// protected impure virtual member functions and adapters
	// protected non-virtual member functions and adapters
	// private static utility functions
	// private static factory functions
	// private static symbols
	// private construction/destruction/assignment
	// private pure virtual member functions and adapters
	// private impure virtual member functions and adapters
	// private non-virtual member functions and adapters

//----------------------------------------------------------------------
class Method : public Thing
//----------------------------------------------------------------------
{
public:
	inline Method(const Ptr thing, const Ptr member) // member is a functor, not a name
		: Thing{}
		, _thing{ thing }
		, _member{ member }
	{
	}

	static inline const Ptr fin_(const Ptr thing, const Ptr member) // member is functor, not a name
	{
		return fake_<Method>(thing, member);
	}

	static inline const Ptr with_name_(const Ptr thing, const Ptr name)
	{
		return fin_(thing, static_<Shoal>(thing->pub_())->at_(name));
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Method");
		return TYPE;
	}

	virtual inline const Ptr eater_() const override
	{
		return _member->eater_();
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		return operate_(_thing.get(), _member, it);
	}

private:
	const Ptr _thing;
	const Ptr _member;
};

//======================================================================
// class Method
//======================================================================

} // namespace strange

#endif
