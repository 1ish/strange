#ifndef COM_ONEISH_STRANGE_CONCEPTION_T_H
#define COM_ONEISH_STRANGE_CONCEPTION_T_H

namespace strange
{

template <typename ___ego___ = unordered_shoal_a<>>
class conception_t : public unordered_shoal_t<false, ___ego___>
{
public:
	// override
	using over = collection_o<conception_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		return unordered_shoal_a<>{ over{ conception_t<>{ range } } };
	}

	template <typename... Args>
	static inline unordered_shoal_a<> val_(Args&&... args)
	{
		return unordered_shoal_a<>{ over{ conception_t<>{ flock_t<>::val_(std::forward<Args>(args)...) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<conception_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<conception_t<>>::share(shoal);
	}

	// conception
	inline void merge(unordered_shoal_a<> const& parent, symbol_a<>& type, cat_a<>& cat, unordered_herd_a<>& cats, kind_a<>& kind, unordered_herd_a<>& kinds)
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

		auto const type_op = parent.at_string("type");
		if (!type_op)
		{
			type = sym("");
		}
		else
		{
			auto const type_any = type_op.operate(no(), range_t<>::val_());
			if (!check<symbol_a<>>(type_any))
			{
				throw dis("strange::conception::val merge parent type returned non-symbol");
			}
			type = cast<symbol_a<>>(type_any);
		}
		auto const& type_string = type.to_string();

		auto const cat_op = parent.at_string("cat");
		if (!cat_op)
		{
			cat = cat_t<>::val_();
		}
		else
		{
			auto const cat_any = cat_op.operate(no(), range_t<>::val_());
			if (!check<cat_a<>>(cat_any))
			{
				throw dis("strange::conception::val merge parent cat returned non-cat");
			}
			cat = cast<cat_a<>>(cat_any);
		}
		cats.insert(cat);

		auto const cats_op = parent.at_string("cats");
		any_a<> cats_any = no();
		if (cats_op)
		{
			cats_any = cats_op.operate(no(), range_t<>::val_());
			if (!check<unordered_herd_a<>>(cats_any))
			{
				throw dis("strange::conception::val merge parent cats returned non-unordered-herd");
			}
			cats += cats_any;
		}

		auto const kind_op = parent.at_string("kind");
		if (!kind_op)
		{
			kind = cat_op ? kind_from_cat(cat) : kind_t<>::val_();
		}
		else
		{
			auto const kind_any = kind_op.operate(no(), range_t<>::val_());
			if (!check<kind_a<>>(kind_any))
			{
				throw dis("strange::conception::val merge parent kind returned non-kind");
			}
			kind = cast<kind_a<>>(kind_any);
		}
		kinds.insert(kind);

		auto const kinds_op = parent.at_string("kinds");
		if (!kinds_op)
		{
			if (cats_any)
			{
				kinds += kinds_from_cats(cast<unordered_herd_a<>>(cats_any));
			}
		}
		else
		{
			auto const kinds_any = kinds_op.operate(no(), range_t<>::val_());
			if (!check<unordered_herd_a<>>(kinds_any))
			{
				throw dis("strange::conception::val merge parent kinds returned non-unordered-herd");
			}
			kinds += kinds_any;
		}

		for (auto const& member : parent.extract())
		{
			if (!check<symbol_a<>>(member.first))
			{
				throw dis("strange::conception::val merge passed non-symbol key");
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
					throw dis("strange::conception::val merge invalid override");
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
	inline conception_t(range_a<> const& parents)
		: unordered_shoal_t{ std_unordered_map_any_any{} }
	{
		symbol_a<> type = sym("");
		cat_a<> cat = cat_t<>::val_();
		unordered_herd_a<> cats = unordered_herd_t<>::val_();
		kind_a<> kind = kind_t<>::val_();
		unordered_herd_a<> kinds = unordered_herd_t<>::val_();

		for (auto const& parent : parents)
		{
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::conception::val passed non-unordered-shoal parent");
			}
			merge(cast<unordered_shoal_a<>>(parent), type, cat, cats, kind, kinds);
		}
		// add operations for type, cat, cats, kind and kinds
		_map.emplace(sym("type"), attribute_extraction_t<>::val_(type));
		_map.emplace(sym("cat"), attribute_extraction_t<>::val_(cat));
		_map.emplace(sym("cats"), attribute_extraction_t<>::val_(cats));
		_map.emplace(sym("kind"), attribute_extraction_t<>::val_(kind));
		_map.emplace(sym("kinds"), attribute_extraction_t<>::val_(kinds));
	}

private:
	static bool const ___share___;
	friend class ___conception_t_share___;
};

template <typename ___ego___>
bool const conception_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	conception_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
