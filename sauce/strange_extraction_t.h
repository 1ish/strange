#ifndef COM_ONEISH_STRANGE_EXTRACTION_T_H
#define COM_ONEISH_STRANGE_EXTRACTION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class extraction_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<extraction_t<>>;

	// construction
	static inline operation_a<> create_(token_a<> const& token, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
	{
		return operation_a<>{ over{ extraction_t<>(token, names, kinds, defaults, expression) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::extraction");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{}

	inline any_a<> eater__(range_a<> const&) const
	{
		return eater_();
	}

	inline range_a<> eater_() const
	{
		return _names;
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto local_shoal = check<unordered_shoal_a<>>(_aspects)
			? cast<unordered_shoal_a<>>(_aspects)
			: unordered_shoal_t<>::create_();
		local_shoal.mutate_thing();
		auto& local = local_shoal.reference();
		local.emplace(sym("$"), _shared);
		local.emplace(sym("^"), thing);
		forward_const_iterator_a<> ait = range.cbegin_();
		auto nit = _names.extract().cbegin();
		auto kit = _kinds.extract().cbegin();
		for (auto const& def : _defaults.extract())
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
					throw dis(_token.report() + "strange::extraction::operate kind expression evaluation error") + misunderstanding;
				}
			}
			if (!check<kind_a<>>(kind))
			{
				throw dis(_token.report() + "strange::extraction::operate non-kind parameter kind");
			}

			bool const more = ait != range.cend_();
			if (!more && !cast<kind_a<>>(kind).optional())
			{
				throw dis(_token.report() + "strange::extraction::operate not passed enough arguments");
			}
			any_a<> const argument = more ? (*ait++) : def;
			if (!argument.kinds_().has_(kind))
			{
				throw dis(_token.report() + "strange::extraction::operate kind does not include argument");
			}
			local.emplace(*nit++, argument);
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

protected:
	token_a<> const _token;
	flock_a<> const _names;
	flock_a<> const _kinds;
	flock_a<> const _defaults;
	expression_a<> const _expression;
	any_a<> _aspects;
	unordered_shoal_a<> const _shared;

	inline extraction_t(token_a<> const& token, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
		: operation_t(expression.pure(), expression.literal())
		, _token{ token }
		, _names{ names }
		, _kinds{ kinds }
		, _defaults{ defaults }
		, _expression{ expression }
		, _aspects{ no() }
		, _shared{ unordered_shoal_t<true>::create_() }
	{}
};

} // namespace strange

#endif
