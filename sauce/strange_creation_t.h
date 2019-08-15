#ifndef COM_ONEISH_STRANGE_CREATION_T_H
#define COM_ONEISH_STRANGE_CREATION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = unordered_shoal_a<>>
class creation_t : public unordered_shoal_t<false, _ABSTRACTION_>
{
public:
	// override
	using over = collection_o<creation_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return unordered_shoal_a<>{ over{ creation_t<>{ range } } };
	}

	template <typename... Args>
	static inline unordered_shoal_a<> val_(Args&&... args)
	{
		return val__(flock_t<>::val_(std::forward<Args>(args)...));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<creation_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<creation_t<>>::share(shoal);
	}

	// creation
	inline void merge(unordered_shoal_a<> const& parent)
	{
		static auto const DROP = unordered_herd_t<>::val_(
			sym("type"),
			sym("cat"),
			sym("cats"),
			sym("kind"),
			sym("kinds"),
			sym("operations"),
			sym("identity"),
			sym("identical"),
			sym("nothing"),
			sym("something"),
			sym("different"),
			sym("ranged"));

		auto type_op = parent.at_string("type");
		if (!type_op)
		{
			_type = sym("");
		}
		else
		{
			auto const type = type_op.operate_(no(), range_t<>::val_());
			if (!check<symbol_a<>>(type))
			{
				throw dis("strange::creation::val merge parent type returned non-symbol");
			}
			_type = cast<symbol_a<>>(type);
		}
		auto const& type_string = _type.to_string();

		auto cat_op = parent.at_string("cat");
		if (!cat_op)
		{
			_cat = cat_t<>::val_();
		}
		else
		{
			auto const cat = cat_op.operate_(no(), range_t<>::val_());
			if (!check<cat_a<>>(cat))
			{
				throw dis("strange::creation::val merge parent cat returned non-cat");
			}
			_cat = cast<cat_a<>>(cat);
		}
		_cats.insert(_cat);

		auto cats_op = parent.at_string("cats");
		any_a<> cats = no();
		if (cats_op)
		{
			cats = cats_op.operate_(no(), range_t<>::val_());
			if (!check<unordered_herd_a<>>(cats))
			{
				throw dis("strange::creation::val merge parent cats returned non-unordered-herd");
			}
			_cats += cats;
		}

		auto kind_op = parent.at_string("kind");
		if (!kind_op)
		{
			_kind = cat_op ? kind_from_cat(_cat) : kind_t<>::val_();
		}
		else
		{
			auto const kind = kind_op.operate_(no(), range_t<>::val_());
			if (!check<kind_a<>>(kind))
			{
				throw dis("strange::creation::val merge parent kind returned non-kind");
			}
			_kind = cast<kind_a<>>(kind);
		}
		_kinds.insert(_kind);

		auto kinds_op = parent.at_string("kinds");
		if (!kinds_op)
		{
			if (cats_op)
			{
				_kinds += kinds_from_cats(cast<unordered_herd_a<>>(cats));
			}
		}
		else
		{
			auto const kinds = kinds_op.operate_(no(), range_t<>::val_());
			if (!check<unordered_herd_a<>>(kinds))
			{
				throw dis("strange::creation::val merge parent kinds returned non-unordered-herd");
			}
			_kinds += kinds;
		}

		for (auto const& member : parent.extract())
		{
			if (!check<symbol_a<>>(member.first))
			{
				throw dis("strange::creation::val merge passed non-symbol key");
			}
			auto key = cast<symbol_a<>>(member.first);
			auto const& key_string = key.to_string();
			bool const intimate = (key_string.c_str()[0] == '_');
			if (intimate)
			{
				key = sym("_" + type_string + key_string);
			}
			else if (DROP.has_(key))
			{
				continue;
			}
			auto const it = _map.find(key);
			if (it != _map.cend())
			{
				// check overrides
				if (intimate || !member.second.kinds_().has_(it->second.kind_()))
				{
					throw dis("strange::creation::val merge invalid override");
				}
				it->second = member.second;
			}
			else
			{
				_map.emplace(key, member.second);
			}
		}
	}

protected:
	symbol_a<> _type;
	cat_a<> _cat;
	unordered_herd_a<> _cats;
	kind_a<> _kind;
	unordered_herd_a<> _kinds;

	inline creation_t(range_a<> const& parents)
		: unordered_shoal_t{ std_unordered_map_any_any{} }
		, _type{ sym("") }
		, _cat{ cat_t<>::val_() }
		, _cats{ unordered_herd_t<>::val_() }
		, _kind{ kind_t<>::val_() }
		, _kinds{ unordered_herd_t<>::val_() }
	{
		for (auto const& parent : parents)
		{
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::creation::val passed non-unordered-shoal parent");
			}
			merge(cast<unordered_shoal_a<>>(parent));
		}
		//TODO add operations for type, cat, cats, kind and kinds
	}

private:
	static bool const ___share___;
	friend class ___creation_t_share___;
};

template <typename _ABSTRACTION_>
bool const creation_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	creation_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
