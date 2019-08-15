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
			throw dis("strange::creation::val merge passed parent without a type operation");
		}
		auto const type_symbol = type_op.operate_(no(), range_t<>::val_());
		if (!check<symbol_a<>>(type_symbol))
		{
			throw dis("strange::creation::val merge parent type returned non-symbol");
		}
		_type = cast<symbol_a<>>(type_symbol);
		auto const& type_string = _type.to_string();

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

	inline creation_t(range_a<> const& parents)
		: unordered_shoal_t{ std_unordered_map_any_any{} }
		, _type(sym(""))
	{
		for (auto const& parent : parents)
		{
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::creation::val passed non-unordered-shoal parent");
			}
			merge(cast<unordered_shoal_a<>>(parent));
		}
		//TODO finishing touches?
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
