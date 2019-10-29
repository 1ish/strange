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
	static inline operation_a<> create_(token_a<> const& token, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
	{
		return operation_a<>{ over{ function_t<>(token, names, kinds, defaults, expression) } };
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
		return cats(_cat);
	}

	inline kind_a<> kind_() const
	{
		return _kind;
	}

	inline unordered_herd_a<> kinds_() const
	{
		return kinds(_kind);
	}

	inline any_a<> eater_() const
	{
		return _names;
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const& range) const
	{
		auto local_shoal = unordered_shoal_t<>::create_();
		auto& local = local_shoal.reference();
		local.emplace(sym("$"), _shared);
		forward_const_iterator_a<> ait = range.cbegin_();
		auto nit = _names.extract().cbegin();
		auto kit = _kinds.extract().cbegin();
		for (auto const& def : _defaults.extract())
		{
			auto const kind = cast<kind_a<>>(*kit++);
			bool const more = ait != range.cend_();
			if (!more && !kind.optional())
			{
				throw dis(_token.report() + "strange::function::operate not passed enough arguments");
			}
			any_a<> const argument = more ? (*ait++) : def;
			if (!argument.kinds_().has_(kind))
			{
				throw dis(_token.report() + "strange::function::operate kind does not include argument");
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
		catch (expression_t<>::break_i&)
		{
			throw dis(_token.report() + "strange::function::operate break caught trying to escape");
		}
		catch (expression_t<>::continue_i&)
		{
			throw dis(_token.report() + "strange::function::operate continue caught trying to escape");
		}
	}

protected:
	token_a<> const _token;
	flock_a<> const _names;
	flock_a<> const _kinds;
	flock_a<> const _defaults;
	expression_a<> const _expression;
	cat_a<> const _cat;
	kind_a<> const _kind;
	unordered_shoal_a<> const _shared;

	inline function_t(token_a<> const& token, flock_a<> const& names, flock_a<> const& kinds, flock_a<> const& defaults, expression_a<> const& expression)
		: operation_t(expression.pure(), expression.literal())
		, _token{ token }
		, _names{ names }
		, _kinds{ kinds }
		, _defaults{ defaults }
		, _expression{ expression }
		, _cat{ cat_t<>::create_(number_int_64_t<>::create(1), sym(""), flock_t<>::create_(), _kinds) }
		, _kind{ kind_from_cat(_cat) }
		, _shared{ unordered_shoal_t<true>::create_() }
	{}
};

} // namespace strange

#endif
