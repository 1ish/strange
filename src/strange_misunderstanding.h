#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_H

#include "strange_core.h"

namespace strange
{
	class Misunderstanding;

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
			Shoal* const shoal = static_<Shoal>(pub);
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
		Shoal* const s = static_<Shoal>(shoal);
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
		for (Ptr i = it->next_(); !i->is_("."); i = it->next_())
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

	virtual inline const Ptr type_() const override
	{
		static const Ptr TYPE = sym_("strange::Misunderstanding");
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
	const Ptr _river;
};

//======================================================================
// class Misunderstanding
//======================================================================

} // namespace strange

#endif
