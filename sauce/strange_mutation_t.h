#ifndef COM_ONEISH_STRANGE_MUTATION_T_H
#define COM_ONEISH_STRANGE_MUTATION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class mutation_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<mutation_t<>>;

	// construction
	static inline operation_a<> create_(token_a<> const& token, flock_a<> const& names, flock_a<> const& params, flock_a<> const& defaults, symbol_a<> const& name, cat_a<> const& result, expression_a<> const& expression)
	{
		return operation_a<>{ over{ mutation_t<>(token, names, params, defaults, name, result, expression) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::mutation");
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
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto local_shoal = unordered_shoal_t<>::create_();
		auto& local = local_shoal.reference();
		local.emplace(sym("$"), _shared);
		thing.mutate_thing();
		local.emplace(sym("^"), thing);
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
				throw dis(_token.report() + "strange::mutation::operate cat does not include argument");
			}
			local.emplace(*nit++, argument);
		}
		try
		{
			auto result = _expression.operate(local_shoal, range);
			if (!result.cats_().has_(_result))
			{
				throw dis(_token.report() + "strange::mutation::operate cat does not include result");
			}
			return result;
		}
		catch (expression_t<>::return_i& ret)
		{
			if (!ret.result.cats_().has_(_result))
			{
				throw dis(_token.report() + "strange::mutation::operate cat does not include result");
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

	inline mutation_t(token_a<> const& token, flock_a<> const& names, flock_a<> const& params, flock_a<> const& defaults, symbol_a<> const& name, cat_a<> const& result, expression_a<> const& expression)
		: operation_t(expression.pure(), expression.literal())
		, _token{ token }
		, _names{ names }
		, _params{ params }
		, _defaults{ defaults }
		, _name{ name }
		, _result{ result }
		, _expression{ expression }
		, _cat{ cat_t<>::create_(number_int_64_t<>::create(1), sym(""), flock_t<>::create_(), _params, _result) }
		, _cats{ cats(_cat) }
		, _kind{ kind_from_cat(_cat) }
		, _kinds{ kinds(_kind) }
		, _shared{ unordered_shoal_t<true>::create_() }
	{}
};

} // namespace strange

#endif
