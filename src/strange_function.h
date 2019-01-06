#ifndef COM_ONEISH_STRANGE_FUNCTION_H
#define COM_ONEISH_STRANGE_FUNCTION_H

#include "strange_core.h"
#include "strange_creature.h"
#include "strange_expression.h"

namespace strange
{
	class Function;

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
class Function : public Thing
//----------------------------------------------------------------------
{
public:
	inline Function(const Ptr expression, const Ptr shared)
		: Thing{}
		, _expression{ expression }
		, _shared{ shared }
	{
	}

	static inline const Ptr fin_(const Ptr expression, const Ptr shared = Shoal::mut_())
	{
		return fake_<Function>(expression, shared);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Function");
		return TYPE;
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr it) override
	{
		const Ptr local = Shoal::mut_();
		Shoal* const loc = static_<Shoal>(local);
		loc->insert_("$", _shared);
		Creature* const creature = dynamic_cast<Creature*>(thing);
		if (creature)
		{
			loc->insert_("|", creature->me_());
		}
		loc->insert_("&", it);
		return static_<Expression>(_expression)->evaluate_(_expression, local);
	}

private:
	const Ptr _expression;
	const Ptr _shared;
};

//======================================================================
// class Function
//======================================================================

} // namespace strange

#endif
