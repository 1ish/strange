#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_intimate_attribute_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_intimate_attribute_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed empty range");
		}
		auto const member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-symbol member term");
		}
		if (++it == terms.cend_())
		{
			return expression_substitute_t<over>::create(over{ expression_intimate_attribute_t<>(token, terms, cast<symbol_a<>>(member)) });
		}
		auto const kind = *it;
		if (!check<kind_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-kind term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed short range");
		}
		auto const value = *it;
		if (!check<expression_a<>>(value))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-expression value term");
		}
		return expression_substitute_t<over>::create(over{ expression_intimate_attribute_t<>(token, terms, cast<symbol_a<>>(member), cast<kind_a<>>(kind), cast<expression_a<>>(value)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_intimate_attribute_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_intimate_attribute_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_intimate_attribute::operate passed non-unordered-shoal local");
		}
#endif
		auto const& local = static_cast<unordered_shoal_a<>&>(thing).extract();
		auto it = local.find(sym("^"));
		if (it == local.cend())
		{
			throw dis(_token.report() + "strange::expression_intimate_attribute::operate ^ not found");
		}
		auto me_reference = any_a<>(it->second, true);
		if (_assign)
		{
			auto const value = _value.operate(thing, range);
			if (!value.kinds_().has(_kind))
			{
				throw dis(_token.report() + "strange::expression_intimate_attribute::operate returned wrong kind of thing");
			}
			return any_c<>::intimate(me_reference, _member, flock_t<>::create_(value));
		}
		return any_c<>::intimate(me_reference, _member, flock_t<>::create_());
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string("." + _member.to_string());
		_value.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string("." + _member.to_string());
		_value.generate_cpp(version, indent, river);
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _member;
	kind_a<> const _kind;
	expression_a<> const _value;
	bool const _assign;

	inline expression_intimate_attribute_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member)
		: expression_t(token, is_pure_literal(token, member, expression_t<>::create(token)))
		, _terms{ terms }
		, _member{ member }
		, _kind{ kind_t<>::create_() }
		, _value{ expression_t<>::create(token) }
		, _assign{ false }
	{}

	inline expression_intimate_attribute_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member, kind_a<> const& kind, expression_a<> const& value)
		: expression_t(token, is_pure_literal(token, member, value))
		, _terms{ terms }
		, _member{ member }
		, _kind{ kind }
		, _value{ value }
		, _assign{ true }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, symbol_a<> const& member, expression_a<> const& expression_value)
	{
		std::pair<bool, bool> pure_literal(true, true);
		if (!expression_value.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		//TODO pure literal attribute?
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_intimate_attribute_t_share___;
};

template <typename ___ego___>
bool const expression_intimate_attribute_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_intimate_attribute_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
