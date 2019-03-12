#ifndef COM_ONEISH_STRANGE_METHOD_H
#define COM_ONEISH_STRANGE_METHOD_H

#include "strange_core.h"

namespace strange
{
class Method;

//----------------------------------------------------------------------
class Method : public Thing
//----------------------------------------------------------------------
{
public:
	inline Method(const Ptr& thing, const Ptr& member) // member is a functor, not a name
		: Thing{}
		, _thing{ thing }
		, _member{ member }
	{
	}

	static inline const Ptr fin_(const Ptr& thing, const Ptr& member) // member is functor, not a name
	{
		return fake_<Method>(thing, member);
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Method");
		return TYPE;
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_(Method::type_());
		return CAT;
	}

	virtual inline const Ptr eater_() const override
	{
		return _member->eater_();
	}

protected:
	virtual inline const Ptr operator()(Thing* const thing, const Ptr& it) override
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
