#ifndef COM_ONEISH_STRANGE_FUNCTION_T_H
#define COM_ONEISH_STRANGE_FUNCTION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class function_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<function_t<>>;

	// construction
	static inline operation_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		auto names = flock_t<>::val_();
		auto params = flock_t<>::val_();
		auto values = flock_t<>::val_();
		auto defaults = flock_t<>::val_();
		any_a<> name = sym("");
		any_a<> cat = cat_t<>::val_();
		any_a<> value = no();
		for (auto const& term : terms)
		{
			if (value)
			{
				names.push_back(name);
				params.push_back(cat);
				values.push_back(value);
				defaults.push_back(cast<expression_a<>>(value).evaluate_());
			}

			if (!check<expression_a<>>(term))
			{
				throw dis(token.report() + "strange::function::val passed non-expression catch");
			}
			auto subterms = cast<expression_a<>>(term).terms_();
			if (subterms.size() != 3)
			{
				throw dis(token.report() + "strange::function::val passed wrong number of subterms");
			}

			name = subterms.at_index(0);
			if (!check<symbol_a<>>(name))
			{
				throw dis(token.report() + "strange::function::val passed non-symbol name");
			}

			cat = subterms.at_index(1);
			if (!check<cat_a<>>(cat))
			{
				throw dis(token.report() + "strange::function::val passed non-cat");
			}

			value = subterms.at_index(2);
			if (!check<expression_a<>>(value))
			{
				throw dis(token.report() + "strange::function::val passed non-expression catch");
			}
		}
		if (!value)
		{
			value = expression_t<>::val(token);
		}
		return operation_a<>{ over{ function_t<>(token, terms, names, params, values, defaults, cast<symbol_a<>>(name), cast<cat_a<>>(cat), cast<expression_a<>>(value)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<function_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<function_t<>>::share(shoal);
	}

	inline cat_a<> cat_() const
	{
		return _cat;
	}

	inline unordered_herd_a<> cats_() const
	{
		return _cats;
	}

	inline kind_a<> kind_() const
	{
		return _kind;
	}

	inline unordered_herd_a<> kinds_() const
	{
		return _kinds;
	}

	inline any_a<> eater_() const
	{
		return _names;
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const& range) const
	{
		auto local_shoal = unordered_shoal_t<>::val_();
		auto& local = local_shoal.reference();
		local.emplace(sym("$"), _shared);
		forward_const_iterator_a<> ait = range.cbegin_();
		auto nit = _names.extract().cbegin();
		auto pit = _params.extract().cbegin();
		for (auto const& def : _defaults.extract())
		{
			any_a<> argument = (ait == range.cend_())
				? def
				: (*ait++);
			if (!argument.cats_().has_(*pit++))
			{
				throw dis(_token.report() + "strange::function::operate cat does not include argument");
			}
			local.emplace(*nit++, argument);
		}
		try
		{
			auto result = _expression.operate(local_shoal, range);
			if (!result.cats_().has_(_result))
			{
				throw dis(_token.report() + "strange::function::operate cat does not include result");
			}
			return result;
		}
		catch (return_i& ret)
		{
			if (!ret.result.cats_().has_(_result))
			{
				throw dis(_token.report() + "strange::function::operate cat does not include result");
			}
			return ret.result;
		}
	}

protected:
	flock_a<> const _terms;
	flock_a<> const _names;
	flock_a<> const _params;
	flock_a<> const _values;
	flock_a<> const _defaults;
	symbol_a<> const _name;
	cat_a<> const _result;
	expression_a<> const _expression;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;
	unordered_shoal_a<> const _shared;

	inline function_t(token_a<> const& token, flock_a<> const& terms, flock_a<> const& names, flock_a<> const& params, flock_a<> const& values, flock_a<> const& defaults, symbol_a<> const& name, cat_a<> const& result, expression_a<> const& expression)
		: thing_t{}
		, _terms{ terms }
		, _names{ names }
		, _params{ params }
		, _values{ values }
		, _defaults{ defaults }
		, _name{ name }
		, _result{ result }
		, _expression{ expression }
		, _cat{ cat_t<>::val_(number_int_64_t<>::val(1), _name, flock_t<>::val_(), _params, _result) }
		, _cats{ cats(_cat) }
		, _kind{ kind_from_cat(_cat) }
		, _kinds{ kinds(_kind) }
		, _shared{ unordered_shoal_t<true>::val_() }
	{}

private:
	static bool const ___share___;
	friend class ___function_t_share___;
};

template <typename ___ego___>
bool const function_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	function_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
