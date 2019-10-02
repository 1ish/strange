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
	static inline operation_a<> val_(token_a<> const& token, flock_a<> const& names, flock_a<> const& params, flock_a<> const& defaults, symbol_a<> const& name, cat_a<> const& result, expression_a<> const& expression)
	{
		return operation_a<>{ over{ function_t<>(token, names, params, defaults, name, result, expression) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::function");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

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
		catch (expression_t<>::return_i& ret)
		{
			if (!ret.result.cats_().has_(_result))
			{
				throw dis(_token.report() + "strange::function::operate cat does not include result");
			}
			return ret.result;
		}
	}

protected:
	token_a<> const _token;
	flock_a<> const _names;
	flock_a<> const _params;
	flock_a<> const _defaults;
	symbol_a<> const _name;
	cat_a<> const _result;
	expression_a<> const _expression;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;
	unordered_shoal_a<> const _shared;

	inline function_t(token_a<> const& token, flock_a<> const& names, flock_a<> const& params, flock_a<> const& defaults, symbol_a<> const& name, cat_a<> const& result, expression_a<> const& expression)
		: operation_t(expression.pure(), expression.literal())
		, _token{ token }
		, _names{ names }
		, _params{ params }
		, _defaults{ defaults }
		, _name{ name }
		, _result{ result }
		, _expression{ expression }
		, _cat{ cat_t<>::val_(number_int_64_t<>::val(1), sym(""), flock_t<>::val_(), _params, _result) }
		, _cats{ cats(_cat) }
		, _kind{ kind_from_cat(_cat) }
		, _kinds{ kinds(_kind) }
		, _shared{ unordered_shoal_t<true>::val_() }
	{}
};

} // namespace strange

#endif
