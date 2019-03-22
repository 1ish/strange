#ifndef COM_ONEISH_STRANGE_FENCE_H
#define COM_ONEISH_STRANGE_FENCE_H

#include "strange_core.h"

namespace strange
{
class Fence;

//----------------------------------------------------------------------
class Fence : public Stateful
//----------------------------------------------------------------------
{
public:
	inline Fence(const Ptr& ptr)
		: Stateful{}
		, _fence{}
		, _ptr{ ptr }
	{
		_fence.store(false, std::memory_order_release);
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr& ptr)
	{
		return make_<Fence>(ptr);
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_ptr);
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Fence::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Fence::type_name));
			shoal->update_("category", Static::fin_(&Fence::category));
			shoal->update_("categories", Static::fin_(&Fence::categories));
			shoal->update_("mut", Static::fin_(&Fence::mut, "thing"));
			shoal->update_("give", Member<Fence>::fin_(&Fence::give));
			shoal->update_("take", Member<Fence>::fin_(&Fence::take));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Fence", Static::fin_(&Fence::creator_));
		s->update_("strange::Fence::mut", Static::fin_(&Fence::mut, "thing"));
	}

	inline const bool give_(const Ptr& ptr)
	{
		if (_fence.load(std::memory_order_acquire))
		{
			return false;
		}
		_ptr = ptr;
		_fence.store(true, std::memory_order_release);
		return true;
	}

	inline const Ptr give(const Ptr& it)
	{
		return boolean_(give_(it->next_()));
	}

	inline const Ptr take_()
	{
		if (_fence.load(std::memory_order_acquire))
		{
			_fence.store(false, std::memory_order_release);
			return _ptr;
		}
		return nothing_();
	}

	inline const Ptr take(const Ptr& ignore)
	{
		return take_();
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Fence");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Fence::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Fence::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Fence::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Fence::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Fence::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(Fence::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Fence::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Fence::categories_();
	}

private:
	std::atomic<bool> _fence;
	Ptr _ptr;
};

//======================================================================
// class Fence
//======================================================================

} // namespace strange

#endif
