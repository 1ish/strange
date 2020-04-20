#ifndef COM_ONEISH_STRANGE_CONCEPTION_T_H
#define COM_ONEISH_STRANGE_CONCEPTION_T_H

namespace strange
{

template <typename ___ego___ = unordered_shoal_a<>>
class conception_t : public unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return unordered_shoal_a<>::create<conception_t<>>(list);
	}

	template <typename... Args>
	static inline unordered_shoal_a<> create_(Args&&... args)
	{
		return unordered_shoal_a<>::create<conception_t<>>(flock_t<>::create_(std::forward<Args>(args)...));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::conception");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::conception::create"), native_function_create(&conception_t<>::create__));
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

		auto const type_op = parent.at_(sym("type"));
		if (!type_op)
		{
			type = sym("");
		}
		else
		{
			auto _ = no();
			auto const type_any = type_op.operate(_, range_t<>::create_());
			if (!check<symbol_a<>>(type_any))
			{
				throw dis("strange::conception::create merge parent type returned non-symbol");
			}
			type = fast<symbol_a<>>(type_any);
		}
		auto const type_string = type.to_string();

		auto const cat_op = parent.at_(sym("cat"));
		if (!cat_op)
		{
			cat = cat_t<>::create_();
		}
		else
		{
			auto _ = no();
			auto const cat_any = cat_op.operate(_, range_t<>::create_());
			if (!check<cat_a<>>(cat_any))
			{
				throw dis("strange::conception::create merge parent cat returned non-cat");
			}
			cat = fast<cat_a<>>(cat_any);
		}
		cats.insert_thing(cat);

		auto const cats_op = parent.at_(sym("cats"));
		any_a<> cats_any;
		if (cats_op)
		{
			auto _ = no();
			cats_any = cats_op.operate(_, range_t<>::create_());
			if (!check<unordered_herd_a<>>(cats_any))
			{
				throw dis("strange::conception::create merge parent cats returned non-unordered-herd");
			}
			cats += fast<unordered_herd_a<>>(cats_any);
		}

		auto const kind_op = parent.at_(sym("kind"));
		if (!kind_op)
		{
			kind = cat_op ? kind_from_cat(cat) : kind_t<>::create_();
		}
		else
		{
			auto _ = no();
			auto const kind_any = kind_op.operate(_, range_t<>::create_());
			if (!check<kind_a<>>(kind_any))
			{
				throw dis("strange::conception::create merge parent kind returned non-kind");
			}
			kind = fast<kind_a<>>(kind_any);
		}
		kinds.insert_thing(kind);

		auto const kinds_op = parent.at_(sym("kinds"));
		if (!kinds_op)
		{
			if (check<unordered_herd_a<>>(cats_any))
			{
				kinds += kinds_from_cats(fast<unordered_herd_a<>>(cats_any));
			}
		}
		else
		{
			auto _ = no();
			auto const kinds_any = kinds_op.operate(_, range_t<>::create_());
			if (!check<unordered_herd_a<>>(kinds_any))
			{
				throw dis("strange::conception::create merge parent kinds returned non-unordered-herd");
			}
			kinds += fast<unordered_herd_a<>>(kinds_any);
		}

		for (auto const& member : parent.extract_map())
		{
			if (!check<symbol_a<>>(member.first))
			{
				throw dis("strange::conception::create merge passed non-symbol key");
			}
			auto key = fast<symbol_a<>>(member.first);
			bool const intimate = key.first_character() == '_';
			if (intimate)
			{
				key = sym("_" + type_string + key.to_string());
			}
			else if (DROP.has_(key))
			{
				continue;
			}
			auto const it = unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.find(key);
			if (it != unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.cend())
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
				unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.emplace(key, member.second);
			}
		}
	}

protected:
	friend class any_a<>;

	inline conception_t(list_a<> const& parents)
		: unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>{ std_unordered_map<any_a<>, any_a<>>{} }
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
			merge(fast<unordered_shoal_a<>>(parent), type, cat, cats, kind, kinds);
		}
		// add operations for type, cat, cats, kind and kinds
		unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.emplace(sym("type"), attribute_extraction_create(type));
		unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.emplace(sym("cat"), attribute_extraction_create(cat));
		unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.emplace(sym("cats"), attribute_extraction_create(cats));
		unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.emplace(sym("kind"), attribute_extraction_create(kind));
		unordered_shoal_t<any_a<>, any_a<>, false, ___ego___>::_map.emplace(sym("kinds"), attribute_extraction_create(kinds));
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
	return shoal;
}();

class ___conception_t_share___
{
	static inline bool ___share___()
	{
		return conception_t<>::___share___;
	}
};

} // namespace strange

#endif
