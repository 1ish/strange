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

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Method::type_name_());
		return CATEGORY;
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

	virtual inline const Ptr type_() const override
	{
		return _member->type_();
	}

	virtual inline const Ptr cat_() const override
	{
		return _member->cat_();
	}

	virtual inline const Ptr cats_() const override
	{
		return _member->cats_();
	}

	virtual inline void finalize_() const override
	{
		_member->finalize_();
	}

	virtual inline const bool final_() const override
	{
		return _member->final_();
	}

	virtual inline void freeze_() const override
	{
		_member->freeze_();
	}

	virtual inline const bool frozen_() const override
	{
		return _member->frozen_();
	}

	virtual inline const Ptr copy_() const override
	{
		return _member->copy_();
	}

	virtual inline const Ptr clone_() const override
	{
		return _member->clone_();
	}

	virtual inline const Ptr replicate_() const override
	{
		return _member->replicate_();
	}

	virtual inline const Ptr iterator_() const override
	{
		return _member->iterator_();
	}

	virtual inline const Ptr next_() override
	{
		return _member->next_();
	}

	virtual inline std::size_t hash_() const override
	{
		return _member->hash_();
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		return _member->same_(other);
	}

	virtual inline const Ptr visit(const Ptr& it)
	{
		return _member->visit(it);
	}

	virtual inline const Ptr pub_() const override
	{
		return _member->pub_();
	}

	virtual inline const Ptr eater_() const override
	{
		return _member->eater_();
	}

	virtual inline const Ptr feeder(const Ptr& eater) const
	{
		return _member->feeder(eater);
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
