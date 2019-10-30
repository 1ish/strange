#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_UPDATE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_shared_update_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_shared_update_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_update::create not passed any terms");
		}
		any_a<> key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_shared_update::create passed non-symbol key");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_update::create not passed sufficient terms");
		}
		any_a<> kind = *it;
		if (!check<kind_a<>>(kind)) //TODO accept kind expression
		{
			throw dis(token.report() + "strange::expression_shared_update::create passed non-kind");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_shared_update::create not passed sufficient terms");
		}
		any_a<> val = *it;
		if (!check<expression_a<>>(val))
		{
			throw dis(token.report() + "strange::expression_shared_update::create passed non-expression");
		}
		return expression_a<>{ over{ expression_shared_update_t<>{ token, terms, cast<symbol_a<>>(key), cast<kind_a<>>(kind), cast<expression_a<>>(val) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_shared_update_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_shared_update_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = static_cast<unordered_shoal_a<>&>(thing).reference();
		auto lit = local.find(sym("$"));
		if (lit == local.end())
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate $ not found");
		}
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(lit->second))
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate passed non-unordered-shoal shared");
		}
#endif
		auto val = _val.operate(thing, range);
		if (!val.kinds_().has_(_kind))
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate kind does not include value");
		}
		auto& shared = static_cast<unordered_shoal_a<>&>(lit->second);
		auto& map = shared.reference();
		auto lock = shared.write_lock_();
		auto it = map.find(_key);
		if (it == map.end())
		{
			throw dis(_token.report() + "strange::expression_shared_update::operate key not found");
		}
		it->second = val;
		return val;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" $" + cast<symbol_a<>>(_key).to_string() + " :=");
		_val.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" " + cast<symbol_a<>>(_key).to_string() + " =");
		_val.generate_cpp(version, indent, river);
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _key;
	kind_a<> const _kind;
	expression_a<> const _val;

	inline expression_shared_update_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& key, kind_a<> const& kind, expression_a<> const& val)
		: expression_t{ token }
		, _terms{ terms }
		, _key{ key }
		, _kind{ kind }
		, _val{ val }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shared_update_t_share___;
};

template <typename ___ego___>
bool const expression_shared_update_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_shared_update_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
