#ifndef COM_ONEISH_STRANGE_WEAK_H
#define COM_ONEISH_STRANGE_WEAK_H

#include "strange_core.h"

namespace strange
{
class Weak;

//----------------------------------------------------------------------
class Weak : public Stateful
//----------------------------------------------------------------------
{
public:
	inline Weak(const Ptr& ptr)
		: Stateful{}
		, _ptr{ ptr }
	{
	}

	static inline const Ptr mut(const Ptr& it)
	{
		return mut_(it->next_());
	}

	static inline const Ptr mut_(const Ptr& ptr)
	{
		return make_<Weak>(ptr);
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr clone_() const override
	{
		return mut_(get_()->clone_());
	}

	virtual inline const Ptr iterator_() const override
	{
		return Iterator::mut_(me_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = _public_(Weak::creator_());
		return PUB;
	}

	static inline const Ptr creator_(const Ptr& ignore = nothing_())
	{
		static const Ptr CREATION = []()
		{
			const auto shoal = static_<Shoal>(Stateful::creator_()->copy_());
			shoal->update_("type_name", Static::fin_(&Weak::type_name));
			shoal->update_("category", Static::fin_(&Weak::category));
			shoal->update_("categories", Static::fin_(&Weak::categories));
			shoal->update_("mut", Static::fin_(&Weak::mut, "thing"));
			shoal->update_("set", Member<Weak>::fin_(&Weak::set, "thing"));
			shoal->update_("get", Const<Weak>::fin_(&Weak::get));
			shoal->finalize_();
			return shoal;
		}();
		return CREATION;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Weak", Static::fin_(&Weak::creator_));
		s->update_("strange::Weak::mut", Static::fin_(&Weak::mut, "thing"));
	}

	inline void set_(const Ptr& ptr)
	{
		_ptr = ptr;
	}

	inline const Ptr set(const Ptr& it)
	{
		const Ptr ptr = it->next_();
		set_(ptr);
		return ptr;
	}

	inline const Ptr get_() const
	{
		const Ptr ptr = _ptr.lock();
		if (ptr)
		{
			return ptr;
		}
		return nothing_();
	}

	inline const Ptr get(const Ptr& ignore) const
	{
		return get_();
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Weak");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Weak::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Weak::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Weak::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Weak::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Weak::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(Weak::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Weak::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Weak::categories_();
	}

private:
	WeakPtr _ptr;

	class Iterator : public Stateful
	{
	public:
		inline Iterator(const Ptr& weak)
			: Stateful{}
			, _weak{ weak }
		{
		}

		static inline const Ptr mut(const Ptr& it)
		{
			return mut_(it->next_());
		}

		static inline const Ptr mut_(const Ptr& weak)
		{
			return make_<Iterator>(weak);
		}

		virtual inline const Ptr copy_() const override
		{
			return mut_(_weak);
		}

		virtual inline const Ptr next_() override
		{
			if (_weak->is_stop_())
			{
				return _weak;
			}
			const Ptr ptr = static_<Weak>(_weak)->get_();
			_weak = stop_();
			return ptr;
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				const auto shoal = static_<Shoal>(pub);
				shoal->update_("mut", Static::fin_(&Iterator::mut, "thing"));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Weak::Iterator");
			return TYPE;
		}

		virtual inline const Ptr cat_() const override
		{
			static const Ptr CAT = Cat::fin_(Weak::Iterator::type_());
			return CAT;
		}

		virtual inline const Ptr cats_() const override
		{
			static const Ptr CATS = [this]()
			{
				const Ptr cats = Herd::mut_();
				const auto herd = static_<Herd>(cats);
				herd->self_add_(Stateful::categories_());
				herd->insert_(Weak::Iterator::cat_());
				herd->finalize_();
				return cats;
			}();
			return CATS;
		}

	private:
		Ptr _weak;
	};
};

//======================================================================
// class Weak
//======================================================================

} // namespace strange

#endif
