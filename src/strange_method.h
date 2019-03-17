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

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Method");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Method::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Method::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Method::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Method::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Method::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Thing::categories_()->copy_());
			categories->insert_(Method::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Method::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Method::categories_();
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
