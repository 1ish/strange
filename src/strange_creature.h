#ifndef COM_ONEISH_STRANGE_CREATURE_H
#define COM_ONEISH_STRANGE_CREATURE_H

#include "strange_core.h"

namespace strange
{
	class Creature;

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
class Creature : public Stateful, public Serializable
//----------------------------------------------------------------------
{
public:
	inline Creature(const Ptr& creator, const Ptr& members)
		: Stateful{}
		, Serializable{}
		, _creator{ dynamic_<Shoal>(creator) ? creator : Shoal::mut_() }
		, _members{ dynamic_<Shoal>(members) ? members : _creator->replicate_()}
		, _public{ _public_(Stateful::pub_(), _members) }
	{
	}

	static inline const Ptr mut_(const Ptr& creator, const Ptr& members)
	{
		return make_<Creature>(creator, members);
	}

	static inline const Ptr mut(const Ptr& it)
	{
		const Ptr creator = it->next_();
		const Ptr members = it->next_();
		return mut_(creator, members);
	}

	static inline const Ptr fin_(const Ptr& creator, const Ptr& members)
	{
		const Ptr result = mut_(creator, members);
		result->finalize_();
		return result;
	}

	static inline const Ptr fin(const Ptr& it)
	{
		const Ptr creator = it->next_();
		const Ptr members = it->next_();
		return fin_(creator, members);
	}

	static inline void share_(const Ptr& shoal)
	{
		Shoal* const s = static_<Shoal>(shoal);
		s->update_("strange::Creature::mut", Static::fin_(&Creature::mut, "creator", "members"));
	}

	virtual inline const Ptr type_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("type");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		static const Ptr TYPE = sym_("strange::Creature");
		return TYPE;
	}

	virtual inline void finalize_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("finalize");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over);
		}
		_members->finalize_();
		Stateful::finalize_();
	}

	virtual inline const bool final_() const override
	{
		bool fin = Stateful::final_();
		fin = _members->final_() && fin;
		const Ptr over = static_<Shoal>(_members)->at_("final");
		if (!over->is_nothing_())
		{
			return (!operate_(const_cast<Creature*>(this), over)->is_nothing_()) && fin;
		}
		return fin;
	}

	virtual inline void freeze_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("freeze");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over);
		}
		_members->freeze_();
		Stateful::freeze_();
	}

	virtual inline const bool frozen_() const override
	{
		bool froz = Stateful::frozen_();
		froz = _members->frozen_() && froz;
		const Ptr over = static_<Shoal>(_members)->at_("frozen");
		if (!over->is_nothing_())
		{
			return (!operate_(const_cast<Creature*>(this), over)->is_nothing_()) && froz;
		}
		return froz;
	}

	virtual inline const Ptr copy_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("copy");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return mut_(_creator, _members->copy_());
	}

	virtual inline const Ptr clone_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("clone");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return mut_(_creator, _members->clone_());
	}

	virtual inline const Ptr replicate_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("replicate");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return mut_(_creator, _members->replicate_());
	}

	virtual inline const Ptr iterator_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("iterator");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return Stateful::iterator_();
	}

	virtual inline const Ptr next_() override
	{
		const Ptr over = static_<Shoal>(_members)->at_("next");
		if (!over->is_nothing_())
		{
			return operate_(this, over);
		}
		return Stateful::next_();
	}

	virtual inline std::size_t hash_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("hash");
		if (!over->is_nothing_())
		{
			return std::size_t(static_<Int64>(operate_(const_cast<Creature*>(this), over))->get_());
		}
		return Stateful::hash_();
	}

	virtual inline const bool same_(const Ptr& other) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("same");
		if (!over->is_nothing_())
		{
			return !operate_(const_cast<Creature*>(this), over,
				IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ other }))->is_nothing_();
		}
		return Stateful::same_(other);
	}

	virtual inline const Ptr visit(const Ptr& it) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("visit");
		if (!over->is_nothing_())
		{
			return operate_(this, over, it);
		}
		return Stateful::visit(it);
	}

	virtual inline const Ptr eater_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("eater");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return Stateful::eater_();
	}

	virtual inline const Ptr feeder(const Ptr& eater) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("feeder");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over, eater);
		}
		return Stateful::feeder(eater);
	}

	virtual inline const Ptr cats_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("cats");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		static const Ptr CATS = []()
		{
			const Ptr cats = Herd::mut_();
			Herd* const herd = static_<Herd>(cats);
			herd->insert_("strange::Stateful");
			herd->insert_("strange::Creature");
			herd->insert_("strange::Thing");
			herd->finalize_();
			return cats;
		}();
		return CATS;
	}

	virtual inline const Ptr pub_() const override
	{
		return _public;
	}

	inline const Ptr members_() const
	{
		return _members;
	}

	virtual inline const Ptr to_lake_() const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("to_lake");
		if (!over->is_nothing_())
		{
			return operate_(const_cast<Creature*>(this), over);
		}
		return to_lake_via_river_();
	}

	virtual inline void from_lake_(const Ptr& lake) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("from_lake");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ lake }));
		}
		else
		{
			from_lake_via_river_(lake);
		}
	}

	virtual inline void to_river_(const Ptr& river) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("to_river");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->to_river_(river);
		}
	}

	virtual inline void from_river_(const Ptr& river) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("from_river");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->from_river_(river);
		}
	}

	virtual inline void to_river_with_links_(const Ptr& shoal, const Ptr& river) const override
	{
		const Ptr over = static_<Shoal>(_members)->at_("to_river_with_links");
		if (!over->is_nothing_())
		{
			operate_(const_cast<Creature*>(this), over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ shoal, river }));
		}
		else
		{
			static_<Shoal>(_members)->to_river_with_links_(shoal, river);
		}
	}

	virtual inline void from_river_with_links_(const Ptr& river) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("from_river_with_links");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ river }));
		}
		else
		{
			static_<Shoal>(_members)->from_river_with_links_(river);
		}
	}

	virtual inline void replace_links_(const Ptr& shoal) override
	{
		const Ptr over = static_<Shoal>(_members)->at_("replace_links");
		if (!over->is_nothing_())
		{
			operate_(this, over, IteratorCopy<std::vector<Ptr>>::mut_(std::vector<Ptr>{ shoal }));
		}
		else
		{
			static_<Shoal>(_members)->replace_links_(shoal);
		}
	}

private:
	const Ptr _creator;
	const Ptr _members;
	const Ptr _public;

	static inline const Ptr _public_(const Ptr& pub, const Ptr& members)
	{
		const Ptr result = pub->copy_();
		Shoal* const r = static_<Shoal>(result);
		Shoal* const m = static_<Shoal>(members);
		const Ptr it = m->iterator_();
		for (Ptr i = it->next_(); !i->is_("."); i = it->next_())
		{
			Flock* const flock = static_<Flock>(i);
			const Ptr first = flock->at_(0);
			Symbol* const symbol = dynamic_<Symbol>(first);
			if (symbol && symbol->get_()[0] != '_')
			{
				r->update_(first, flock->at_(1));
			}
		}
		result->finalize_();
		return result;
	}
};

//======================================================================
// class Creator
//======================================================================

//======================================================================
// class Creature
//======================================================================

} // namespace strange

#endif
