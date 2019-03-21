#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_H

#include "strange_core.h"

namespace strange
{
class Misunderstanding;

//----------------------------------------------------------------------
class Misunderstanding : public Stateful
//----------------------------------------------------------------------
{
public:
	inline Misunderstanding(const std::string& description)
		: Stateful{}
		, _river{ River::mut_(description) }
	{
	}

	static inline const Ptr mut(const Ptr& it)
	{
		const Ptr result = mut_();
		static_<Misunderstanding>(result)->self_add(it);
		return result;
	}

	static inline const Ptr mut_(const std::string& description = "")
	{
		return make_<Misunderstanding>(description);
	}

	virtual inline const Ptr copy_() const override
	{
		return mut_(get_());
	}

	virtual inline const Ptr pub_() const override
	{
		static const Ptr PUB = [this]()
		{
			const Ptr pub = Thing::pub_()->copy_();
			const auto shoal = static_<Shoal>(pub);
			shoal->update_("mut", Static::fin_(&Misunderstanding::mut, "thing", ".."));
			shoal->update_("self_add", Member<Misunderstanding>::fin_(&Misunderstanding::self_add, "thing", ".."));
			shoal->update_("to_lake", Const<Misunderstanding>::fin_(&Misunderstanding::to_lake));
			shoal->update_("get", Const<Misunderstanding>::fin_(&Misunderstanding::get));
			shoal->finalize_();
			return pub;
		}();
		return PUB;
	}

	static inline void share_(const Ptr& shoal)
	{
		const auto s = static_<Shoal>(shoal);
		s->update_("strange::Misunderstanding::mut", Static::fin_(&Misunderstanding::mut, "thing", ".."));
	}

	inline void self_add_(const std::string& str)
	{
		static_<River>(_river)->write_(str);
	}

	inline void self_add_(const Ptr& thing)
	{
		static_<River>(_river)->write_(thing);
	}

	inline const Ptr self_add(const Ptr& it)
	{
		for (Ptr i = it->next_(); !i->is_stop_(); i = it->next_())
		{
			self_add_(i);
		}
		return me_();
	}

	inline const Ptr to_lake_() const
	{
		return static_<River>(_river)->to_lake_();
	}

	inline const Ptr to_lake(const Ptr& ignore) const
	{
		return to_lake_();
	}

	inline const std::string get_() const
	{
		return static_<Lake>(to_lake_())->get_();
	}

	inline const Ptr get(const Ptr& ignore) const
	{
		return _river;
	}

	static inline const Ptr type_name_()
	{
		static const Ptr TYPE_NAME = sym_("strange::Misunderstanding");
		return TYPE_NAME;
	}

	static inline const Ptr type_name(const Ptr& ignore)
	{
		return Misunderstanding::type_name_();
	}

	virtual inline const Ptr type_() const override
	{
		return Misunderstanding::type_name_();
	}

	static inline const Ptr category_()
	{
		static const Ptr CATEGORY = Cat::fin_(Misunderstanding::type_name_());
		return CATEGORY;
	}

	static inline const Ptr category(const Ptr& ignore)
	{
		return Misunderstanding::category_();
	}

	virtual inline const Ptr cat_() const override
	{
		return Misunderstanding::category_();
	}

	static inline const Ptr categories_()
	{
		static const Ptr CATEGORIES = []()
		{
			const auto categories = static_<Herd>(Stateful::categories_()->copy_());
			categories->insert_(Misunderstanding::category_());
			categories->finalize_();
			return categories;
		}();
		return CATEGORIES;
	}

	static inline const Ptr categories(const Ptr& ignore)
	{
		return Misunderstanding::categories_();
	}

	virtual inline const Ptr cats_() const override
	{
		return Misunderstanding::categories_();
	}

private:
	const Ptr _river;
};

//======================================================================
// class Misunderstanding
//======================================================================

} // namespace strange

#endif
