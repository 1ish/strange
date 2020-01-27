#ifndef COM_ONEISH_STRANGE_EXPRESSION_INVOKE_ATTRIBUTE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INVOKE_ATTRIBUTE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_invoke_attribute_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_invoke_attribute_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_invoke_attribute::create passed empty range");
		}
		auto thing = *it;
		if (!check<expression_a<>>(thing))
		{
			throw dis(token.report() + "strange::expression_invoke_attribute::create passed non-expression thing term");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_invoke_attribute::create passed short range");
		}
		auto member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_invoke_attribute::create passed non-symbol member term");
		}
		if (++it == terms.cend_())
		{
			return expression_substitute_t<over>::create(over{ expression_invoke_attribute_t<>(token, terms, cast<expression_a<>>(thing), cast<symbol_a<>>(member)) });
		}
		auto value = *it;
		if (!check<expression_a<>>(value))
		{
			throw dis(token.report() + "strange::expression_invoke_attribute::create passed non-expression value term");
		}
		return expression_substitute_t<over>::create(over{ expression_invoke_attribute_t<>(token, terms, cast<expression_a<>>(thing), cast<symbol_a<>>(member), cast<expression_a<>>(value)) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_invoke_attribute_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_invoke_attribute_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto thing_term = _thing.operate(thing, range);
		if (_assign)
		{
			return thing_t<>::invoke_member(thing_term, _member, flock_t<>::create_(_value.operate(thing, range)));
		}
		return thing_t<>::invoke_member(thing_term, _member, flock_t<>::create_());
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		_thing.generate(version, indent, river);
		river.write_string("." + _member.to_string());
		_value.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_thing.generate_cpp(version, indent, river, declare, define);
			if (_assign)
			{
				_value.generate_cpp(version, indent, river, declare, define);
			}
			return;
		}
		if (type)
		{
			throw dis(_token.report() + "strange::expression_invoke_attribute::generate_cpp called for wrong type of expression");
		}
		_thing.generate_cpp(version, indent, river, declare, define);
		river.write_string("." + _member.to_string());
		_value.generate_cpp(version, indent, river, declare, define);
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _thing;
	symbol_a<> const _member;
	expression_a<> const _value;
	bool const _assign;

	inline expression_invoke_attribute_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, symbol_a<> const& member)
		: expression_t(token, is_pure_literal(token, terms, thing, member, expression_t<>::create(token)))
		, _terms{ terms }
		, _thing{ thing }
		, _member{ member }
		, _value{ expression_t<>::create(token) }
		, _assign{ false }
	{}

	inline expression_invoke_attribute_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& thing, symbol_a<> const& member, expression_a<> const& value)
		: expression_t(token, is_pure_literal(token, terms, thing, member, value))
		, _terms{ terms }
		, _thing{ thing }
		, _member{ member }
		, _value{ value }
		, _assign{ true }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, flock_a<> const& terms, expression_a<> const& expression_thing, symbol_a<> const& member, expression_a<> const& expression_value)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal
		if (!expression_thing.literal() || !expression_value.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_invoke_attribute_t_share___;
};

template <typename ___ego___>
bool const expression_invoke_attribute_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_invoke_attribute_t<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
