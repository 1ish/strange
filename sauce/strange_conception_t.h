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
	static inline any_a<> create__(range_a<> const& range)
	{
		return unordered_shoal_a<>{ over{ conception_t<>{ range } } };
	}

	template <typename... Args>
	static inline unordered_shoal_a<> create_(Args&&... args)
	{
		return unordered_shoal_a<>{ over{ conception_t<>{ flock_t<>::create_(std::forward<Args>(args)...) } } };
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
		static auto const DROP = unordered_herd_t<>::create_(
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
			sym("different"));

		auto const type_op = parent.at_string("type");
		if (!type_op)
		{
			type = sym("");
		}
		else
		{
			auto const type_any = type_op.operate(no(), range_t<>::create_());
			if (!check<symbol_a<>>(type_any))
			{
				throw dis("strange::conception::create merge parent type returned non-symbol");
			}
			type = cast<symbol_a<>>(type_any);
		}
		auto const& type_string = type.to_string();

		auto const cat_op = parent.at_string("cat");
		if (!cat_op)
		{
			cat = cat_t<>::create_();
		}
		else
		{
			auto const cat_any = cat_op.operate(no(), range_t<>::create_());
			if (!check<cat_a<>>(cat_any))
			{
				throw dis("strange::conception::create merge parent cat returned non-cat");
			}
			cat = cast<cat_a<>>(cat_any);
		}
		cats.insert(cat);

		auto const cats_op = parent.at_string("cats");
		any_a<> cats_any;
		if (cats_op)
		{
			cats_any = cats_op.operate(no(), range_t<>::create_());
			if (!check<unordered_herd_a<>>(cats_any))
			{
				throw dis("strange::conception::create merge parent cats returned non-unordered-herd");
			}
			cats += cats_any;
		}

		auto const kind_op = parent.at_string("kind");
		if (!kind_op)
		{
			kind = cat_op ? kind_from_cat(cat) : kind_t<>::create_();
		}
		else
		{
			auto const kind_any = kind_op.operate(no(), range_t<>::create_());
			if (!check<kind_a<>>(kind_any))
			{
				throw dis("strange::conception::create merge parent kind returned non-kind");
			}
			kind = cast<kind_a<>>(kind_any);
		}
		kinds.insert(kind);

		auto const kinds_op = parent.at_string("kinds");
		if (!kinds_op)
		{
			if (check<unordered_herd_a<>>(cats_any))
			{
				kinds += kinds_from_cats(cast<unordered_herd_a<>>(cats_any));
			}
		}
		else
		{
			auto const kinds_any = kinds_op.operate(no(), range_t<>::create_());
			if (!check<unordered_herd_a<>>(kinds_any))
			{
				throw dis("strange::conception::create merge parent kinds returned non-unordered-herd");
			}
			kinds += kinds_any;
		}

		for (auto const& member : parent.extract_map())
		{
			if (!check<symbol_a<>>(member.first))
			{
				throw dis("strange::conception::create merge passed non-symbol key");
			}
			auto key = cast<symbol_a<>>(member.first);
			bool const intimate = key.first_character() == '_';
			if (intimate)
			{
				key = sym("_" + type_string + key.to_string());
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
					throw dis("strange::conception::create merge invalid override");
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
		cat_a<> cat = cat_t<>::create_();
		unordered_herd_a<> cats = unordered_herd_t<>::create_();
		kind_a<> kind = kind_t<>::create_();
		unordered_herd_a<> kinds = unordered_herd_t<>::create_();

		for (auto const& parent : parents)
		{
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::conception::create passed non-unordered-shoal parent");
			}
			merge(cast<unordered_shoal_a<>>(parent), type, cat, cats, kind, kinds);
		}
		// add operations for type, cat, cats, kind and kinds
		_map.emplace(sym("type"), attribute_extraction_t<>::create_(type));
		_map.emplace(sym("cat"), attribute_extraction_t<>::create_(cat));
		_map.emplace(sym("cats"), attribute_extraction_t<>::create_(cats));
		_map.emplace(sym("kind"), attribute_extraction_t<>::create_(kind));
		_map.emplace(sym("kinds"), attribute_extraction_t<>::create_(kinds));
	}

private:
	static bool const ___share___;
	friend class ___conception_t_share___;
};

template <typename ___ego___>
bool const conception_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	conception_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
