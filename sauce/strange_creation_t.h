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
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	template <typename... Args>
	static inline unordered_shoal_a<> val_(Args&&... args)
	{
		auto const parents = flock_t<>::val_(std::forward<Args>(args)...);
		auto child = over{ creation_t<>{} };
		for (auto const& parent : parents)
		{
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::creation::val passed non-unordered-shoal parent");
			}
			child.merge(cast<unordered_shoal_a<>>(parent));
		}
		//TODO finishing touches?
		return unordered_shoal_a<>{ child };
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
		auto type = parent.at_string("type");
		if (!type)
		{
			throw dis("strange::creation::val merge passed parent without a type");
		}
		auto const type_symbol = type(range_t<>::val_());
		if (!check<symbol_a<>>(type_symbol))
		{
			throw dis("strange::creation::val merge parent type returned non-symbol");
		}
		auto const& type_string = cast<symbol_a<>>(type_symbol).to_string();
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
	inline creation_t()
		: unordered_shoal_t{ std_unordered_map_any_any{} }
	{}

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
