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
	static inline operation_a<> create_(token_a<> const& token, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
	{
		return operation_a<>{ over{ mutation_t<>(token, names, kinds, defaults, expression) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::mutation");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto local_shoal = check<unordered_shoal_a<>>(_aspects)
			? cast<unordered_shoal_a<>>(_aspects)
			: unordered_shoal_t<>::create_();
		auto& local = local_shoal.mutate_map();
		local.emplace(sym("$"), _shared);
		thing.mutate();
		local.emplace(sym("^"), thing);
		forward_const_iterator_a<> ait = range.cbegin_();
		auto nit = _names.extract_vector().cbegin();
		auto kit = _kinds.extract_vector().cbegin();
		for (auto const& def : _defaults.extract_vector())
		{
			if (nit->is("&"))
			{
				if (ait == range.cbegin_())
				{
					local.emplace(*nit, range);
				}
				else
				{
					local.emplace(*nit, range_t<>::create_(ait, range.cend_()));
				}
				break;
			}

			auto kind = *kit++;
			if (check<expression_a<>>(kind))
			{
				try
				{
					kind = cast<expression_a<>>(kind).operate(local_shoal, range);
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis(_token.report() + "strange::mutation::operate kind expression evaluation error") + misunderstanding;
				}
			}
			if (!check<kind_a<>>(kind))
			{
				throw dis(_token.report() + "strange::mutation::operate non-kind parameter kind");
			}

			bool const more = ait != range.cend_();
			if (!more && !cast<kind_a<>>(kind).optional())
			{
				throw dis(_token.report() + "strange::mutation::operate not passed enough arguments");
			}
			if (more)
			{
				any_a<> argument = any_a<>::dup(const_cast<any_a<>&>(*ait++));
				if (!argument.kinds_().has_(kind))
				{
					throw dis(_token.report() + "strange::mutation::operate kind does not include argument");
				}
				local.emplace(*nit++, argument);
			}
			else
			{
				if (!def.kinds_().has_(kind))
				{
					throw dis(_token.report() + "strange::mutation::operate kind does not include default");
				}
				local.emplace(*nit++, def);
			}
		}
		try
		{
			return _expression.operate(local_shoal, range);
		}
		catch (expression_t<>::return_i& ret)
		{
			return ret.result;
		}
	}

	// operation
	inline void aspects(unordered_shoal_a<> const& aspects)
	{
		_aspects = aspects;
	}

	inline void assign(operation_a<> const& operation)
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (operation.type_() != type_())
		{
			throw dis(_token.report() + "strange::mutation::assign passed non-mutation operation");
		}
#endif
		auto const& other = static_cast<mutation_t<> const&>(operation.extract_thing());
		_kinds = other._kinds;
		_defaults = other._defaults;
		_expression = other._expression;
	}

protected:
	token_a<> const _token;
	flock_a<> _kinds;
	flock_a<> _defaults;
	expression_a<> _expression;
	any_a<> _aspects;
	unordered_shoal_a<> const _shared;

	inline mutation_t(token_a<> const& token, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
		: operation_t(expression.pure(), names)
		, _token{ token }
		, _kinds{ kinds }
		, _defaults{ defaults }
		, _expression{ expression }
		, _aspects{ no() }
		, _shared{ unordered_shoal_t<true>::create_() }
	{}
};

} // namespace strange

#endif
