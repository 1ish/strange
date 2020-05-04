#ifndef COM_ONEISH_STRANGE_FUNCTION_T_H
#define COM_ONEISH_STRANGE_FUNCTION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class function_t : public operation_t<___ego___>
{
public:
	// construction
	static inline operation_a<> create_(token_a<> const& token, symbol_a<> const& scope, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
	{
		return operation_a<>::create<function_t<>>(token, scope, names, kinds, defaults, expression);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::function");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

	// function
	inline any_a<> operate(any_a<>&, list_a<> const& list) const
	{
		auto local_shoal = check<unordered_shoal_a<>>(_aspects)
			? fast<unordered_shoal_a<>>(_aspects)
			: unordered_shoal_t<>::create_();
		auto& local = local_shoal.mutate_map();
		local.emplace(sym("$"), _shared);
		auto abegin = list.begin_();
		auto aend = list.end_();
		auto ait = abegin;
		auto nit = operation_t<___ego___>::_names.extract_vector().cbegin();
		auto kit = _kinds.extract_vector().cbegin();
		for (auto const& def : _defaults.extract_vector())
		{
			if (nit->is("&"))
			{
				if (ait == abegin)
				{
					local.emplace(*nit, list);
				}
				else
				{
					local.emplace(*nit, list::create(ait, aend));
				}
				break;
			}

			auto any_kind = *kit++;
			if (check<expression_a<>>(any_kind))
			{
				try
				{
					any_kind = fast<expression_a<>>(any_kind).operate(local_shoal, list);
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis(_token.report() + "strange::function::operate kind expression evaluation error") + misunderstanding;
				}
			}
			if (!check<kind_a<>>(any_kind))
			{
				throw dis(_token.report() + "strange::function::operate non-kind parameter kind");
			}
			auto const kind = fast<kind_a<>>(any_kind);

			if (ait != aend)
			{
				if (kind.fixed() || kind.reference())
				{
					auto const argument = fast_dup(*ait);
					++ait;
					if (!argument.kinds_().has_(kind))
					{
						throw dis(_token.report() + "strange::function::operate kind does not include argument");
					}
					local.emplace(*nit++, argument);
				}
				else
				{
					auto const argument = *ait;
					++ait;
					if (!argument.kinds_().has_(kind))
					{
						throw dis(_token.report() + "strange::function::operate kind does not include argument");
					}
					local.emplace(*nit++, argument);
				}
			}
			else if (!kind.optional())
			{
				throw dis(_token.report() + "strange::function::operate not passed enough arguments");
			}
			else
			{
				if (!def.kinds_().has_(kind))
				{
					throw dis(_token.report() + "strange::function::operate kind does not include default");
				}
				local.emplace(*nit++, def);
			}
		}
		try
		{
			return _expression.operate(local_shoal, list);
		}
		catch (typename expression_t<>::return_e& ret)
		{
			return ret.result;
		}
		catch (typename expression_t<>::break_e&)
		{
			throw dis(_token.report() + "strange::function::operate break caught trying to escape");
		}
		catch (typename expression_t<>::continue_e&)
		{
			throw dis(_token.report() + "strange::function::operate continue caught trying to escape");
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
			throw dis(_token.report() + "strange::function::assign passed non-function operation");
		}
#endif
		auto const& other = static_cast<function_t<> const&>(operation.extract_thing());
		_kinds = other._kinds;
		_defaults = other._defaults;
		_expression = other._expression;
	}

protected:
	token_a<> const _token;
	symbol_a<> const _scope;
	flock_a<> _kinds;
	flock_a<> _defaults;
	expression_a<> _expression;
	any_a<> _aspects;
	unordered_shoal_a<> const _shared;

	friend class any_a<>;

	inline function_t(token_a<> const& token, symbol_a<> const& scope, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
		: operation_t<___ego___>(expression.pure(), names)
		, _token{ token }
		, _scope{ scope }
		, _kinds{ kinds }
		, _defaults{ defaults }
		, _expression{ expression }
		, _aspects{ no() }
		, _shared{ unordered_shoal_t<any_a<>, any_a<>, true>::create_() }
	{}
};

} // namespace strange

#endif
