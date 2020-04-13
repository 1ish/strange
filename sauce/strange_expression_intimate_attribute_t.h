#ifndef COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_INTIMATE_ATTRIBUTE_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_intimate_attribute_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		return expression_t<___ego___>::template create_expression<expression_intimate_attribute_t<___ego___>>(range);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed empty range");
		}
		auto const member = *it;
		if (!check<symbol_a<>>(member))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-symbol member term");
		}
		if (++it == terms.extract_end_())
		{
			return expression_substitute_t<expression_intimate_attribute_t<>>::create(expression_intimate_attribute_t<>(token, terms, fast<symbol_a<>>(member)));
		}
		auto const kind = *it;
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-kind/expression term");
		}
		if (++it == terms.extract_end_())
		{
			return expression_substitute_t<expression_intimate_attribute_t<>>::create(expression_intimate_attribute_t<>(token, terms, fast<symbol_a<>>(member), fast<kind_a<>>(kind)));
		}
		auto const expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_intimate_attribute::create passed non-expression value term");
		}
		return expression_substitute_t<expression_intimate_attribute_t<>>::create(expression_intimate_attribute_t<>(token, terms, fast<symbol_a<>>(member), kind, fast<expression_a<>>(expression)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_intimate_attribute");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		// nope: shoal.update(sym("strange::expression_intimate_attribute::create"), native_function_create(&expression_intimate_attribute_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_attribute::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = const_cast<std::unordered_map<any_a<>, any_a<>>&>(static_cast<unordered_shoal_a<>&>(thing).extract_map());
		auto it = local.find(sym("^"));
		if (it == local.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_attribute::operate ^ not found");
		}
		if (_assign)
		{
			auto kind = _kind;
			if (check<expression_a<>>(kind))
			{
				try
				{
					kind = fast<expression_a<>>(kind).operate(thing, range);
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_attribute::operate kind expression evaluation error") + misunderstanding;
				}
			}
			auto const value = _expression.operate(thing, range);
			if (!value.kinds_().has(kind))
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_attribute::operate returned wrong kind of thing");
			}
			return any_c<>::intimate(it->second, _member, flock_t<>::create_(value));
		}
		return any_c<>::intimate(it->second, _member, flock_t<>::create_());
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_intimate_attribute_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, range_create());
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		river.write_string("." + _member.to_string());
		_expression.generate(version, indent, river);
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_expression.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_intimate_attribute::generate_cpp called for wrong type of expression");
		}
		river.write_string("." + _member.to_string());
		_expression.generate_cpp(version, indent, river, declare, define);
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _member;
	any_a<> const _kind;
	expression_a<> const _expression;
	bool const _assign;

	friend class any_a<>;

	inline expression_intimate_attribute_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member, any_a<> const& kind = kind_t<>::create_())
		: expression_t<___ego___>(token, is_pure_literal(token, member, expression_t<>::create(token)))
		, _terms{ terms }
		, _member{ member }
		, _kind{ kind }
		, _expression{ expression_t<>::create(token) }
		, _assign{ false }
	{}

	inline expression_intimate_attribute_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& member, any_a<> const& kind, expression_a<> const& expression)
		: expression_t<___ego___>(token, is_pure_literal(token, member, expression))
		, _terms{ terms }
		, _member{ member }
		, _kind{ kind }
		, _expression{ expression }
		, _assign{ true }
	{}

	static inline std::pair<bool, bool> is_pure_literal(token_a<> const& token, symbol_a<> const& member, expression_a<> const& expression)
	{
		std::pair<bool, bool> pure_literal(false, false); //TODO pure literal attribute?
		if (!expression.literal())
		{
			pure_literal.first = false;
			pure_literal.second = false;
			return pure_literal;
		}
		return pure_literal;
	}

private:
	static bool const ___share___;
	friend class ___expression_intimate_attribute_t_share___;
};

template <typename ___ego___>
bool const expression_intimate_attribute_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_intimate_attribute_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_intimate_attribute_t_share___
{
	static inline bool ___share___()
	{
		return expression_intimate_attribute_t<>::___share___;
	}
};

inline expression_a<> expression_intimate_attribute_create(token_a<> const& token, flock_a<> const& terms)
{
	return expression_intimate_attribute_t<>::create_(token, terms);
}

} // namespace strange

#endif
