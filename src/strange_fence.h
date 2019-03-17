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
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			const auto shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Fence::mut, "thing"));
			shoal->update_("give", Member<Fence>::fin_(&Fence::give));
			shoal->update_("take", Member<Fence>::fin_(&Fence::take));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
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

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Fence");
		return TYPE;
	}

	virtual inline const Ptr cat_() const override
	{
		static const Ptr CAT = Cat::fin_(Fence::type_());
		return CAT;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = [this]()
		{
			const Ptr cats = Herd::mut_();
			const auto herd = static_<Herd>(cats);
			herd->self_add_(Stateful::categories_());
			herd->insert_(Fence::cat_());
			herd->finalize_();
			return cats;
		}();
		return CATS;
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
