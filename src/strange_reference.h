#ifndef COM_ONEISH_STRANGE_REFERENCE_H
#define COM_ONEISH_STRANGE_REFERENCE_H

#include "strange_core.h"

namespace strange
{
class Reference;

//----------------------------------------------------------------------
class Reference : public Stateful
//----------------------------------------------------------------------
{
public:
	inline Reference(const Ptr& ptr)
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
		return make_<Reference>(ptr);
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(_ptr);
	}

	virtual inline const Ptr clone_() const override
	{
		return mut_(_ptr->clone_());
	}

	virtual inline const Ptr iterator_() const override
	{
		return Iterator::mut_(me_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			Shoal* const shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Reference::mut, "thing"));
			shoal->update_("set", Member<Reference>::fin_(&Reference::set, "thing"));
			shoal->update_("get", Const<Reference>::fin_(&Reference::get));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr& shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Reference::mut", Static::fin_(&Reference::mut, "thing"));
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
		return _ptr;
	}

	inline const Ptr get(const Ptr& ignore) const
	{
		return get_();
	}

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Reference");
		return TYPE;
	}

	virtual inline const Ptr cats_() const override
	{
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Stateful");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

private:
	Ptr _ptr;

	class Iterator : public Stateful
	{
	public:
		inline Iterator(const Ptr& reference)
			: Stateful{}
			, _reference{ reference }
		{
		}

		static inline const Ptr mut(const Ptr& it)
		{
			return mut_(it->next_());
		}

		static inline const Ptr mut_(const Ptr& reference)
		{
			return make_<Iterator>(reference);
		}

		virtual inline const Ptr copy_() const override
		{
			return mut_(_reference);
		}

		virtual inline const Ptr next_() override
		{
			if (_reference->is_("."))
			{
				return _reference;
			}
			const Ptr ptr = static_<Reference>(_reference)->get_();
			_reference = stop_();
			return ptr;
		}

		virtual inline const Ptr pub_() const override
		{
			static const Ptr PUB = [this]()
			{
				const Ptr pub = Thing::pub_()->copy_();
				Shoal* const shoal = static_<Shoal>(pub);
				shoal->update_("mut", Static::fin_(&Iterator::mut, "thing"));
				shoal->finalize_();
				return pub;
			}();
			return PUB;
		}

		virtual inline const Ptr type_() const override
		{
			static const Ptr TYPE = sym_("strange::Reference::Iterator");
			return TYPE;
		}

		virtual inline const Ptr cats_() const override
		{
			static const Ptr CATS = []()
			{
				const Ptr cats = Herd::mut_();
				Herd* const herd = static_<Herd>(cats);
				herd->insert_("strange::Stateful");
				herd->insert_("strange::Thing");
				herd->finalize_();
				return cats;
			}();
			return CATS;
		}

	private:
		Ptr _reference;
	};
};

//======================================================================
// class Reference
//======================================================================

} // namespace strange

#endif
