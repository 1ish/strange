#ifndef COM_ONEISH_STRANGE_ABSTRACTION_T_H
#define COM_ONEISH_STRANGE_ABSTRACTION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class abstraction_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<abstraction_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::abstraction::create passed empty range");
		}
		auto const token = *it;
		if (!check<token_a<>>(token))
		{
			throw dis("strange::abstraction::create passed non-token");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-symbol scope");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const names = *it;
		if (!check<flock_a<>>(names))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock dimension names");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const dimension_kinds = *it;
		if (!check<flock_a<>>(dimension_kinds))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock dimension kinds");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const dimension_defaults = *it;
		if (!check<flock_a<>>(dimension_defaults))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock dimension defaults");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::abstraction::create passed short range");
		}
		auto const parent_expressions = *it;
		if (!check<flock_a<>>(parent_expressions))
		{
			throw dis(cast<token_a<>>(token).report() + "strange::abstraction::create passed non-flock parent expressions");
		}
		return create_(cast<token_a<>>(token), cast<symbol_a<>>(scope), cast<flock_a<>>(names), cast<flock_a<>>(dimension_kinds), cast<flock_a<>>(dimension_defaults), cast<flock_a<>>(parent_expressions));
	}

	static inline operation_a<> create_(token_a<> const& token, symbol_a<> const& scope, flock_a<> const& names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_defaults, flock_a<> const& parent_expressions)
	{
		return operation_a<>{ over{ abstraction_t<>(token, scope, names, dimension_kinds, dimension_defaults, parent_expressions) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<abstraction_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<abstraction_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const& range) const
	{
		//TODO cache range -> child
		auto aspects_shoal = unordered_shoal_t<>::create_();
		auto& aspects = aspects_shoal.mutate_map();
		auto local_shoal = unordered_shoal_t<>::create_();
		auto& local = local_shoal.mutate_map();
		forward_const_iterator_a<> ait = range.cbegin_();
		auto nit = _names.extract_vector().cbegin();
		auto kit = _dimension_kinds.extract_vector().cbegin();
		for (auto const& def : _dimension_defaults.extract_vector())
		{
			auto any_kind = *kit++;
			if (check<expression_a<>>(any_kind))
			{
				try
				{
					any_kind = cast<expression_a<>>(any_kind).operate(local_shoal, range);
				}
				catch (misunderstanding_a<>& misunderstanding)
				{
					throw dis(_token.report() + "strange::abstraction::operate kind expression evaluation error") + misunderstanding;
				}
			}
			if (!check<kind_a<>>(any_kind))
			{
				throw dis(_token.report() + "strange::abstraction::operate non-kind dimension kind");
			}
			auto const kind = cast<kind_a<>>(any_kind);

			auto const name = *nit++;
			if (ait != range.cend_())
			{
				auto const argument = *ait++;
				if (!argument.kinds_().has_(kind))
				{
					throw dis(_token.report() + "strange::abstraction::operate kind does not include argument");
				}
				aspects.emplace(name, argument);
				local.emplace(name, argument);
			}
			else if (!kind.optional())
			{
				throw dis(_token.report() + "strange::abstraction::operate not passed enough arguments");
			}
			else
			{
				if (!def.kinds_().has_(kind))
				{
					throw dis(_token.report() + "strange::abstraction::operate kind does not include argument");
				}
				aspects.emplace(name, def);
				local.emplace(name, def);
			}
		}
		auto child = unordered_shoal_t<>::create_();
		for (auto const& expression : _parent_expressions.extract_vector())
		{
			any_a<> parent;
			try
			{
				parent = expression.operate(local_shoal, range);
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis("strange::abstraction::operate parent shoal evaluation error:") + _token.report_() + misunderstanding;
			}
			if (!check<unordered_shoal_a<>>(parent))
			{
				throw dis("strange::abstraction::operate parent expression returned non-unordered-shoal");
			}
			_merge(cast<unordered_shoal_a<>>(parent), child, aspects_shoal);
		}
		child.insert_string("#", aspects_shoal);
		return child;
	}

	// operation
	inline void assign(operation_a<> const& operation)
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (operation.type_() != type_())
		{
			throw dis(_token.report() + "strange::abstraction::assign passed non-abstraction operation");
		}
#endif
		auto const& other = static_cast<abstraction_t<> const&>(operation.extract_thing());
		_dimension_kinds = other._dimension_kinds;
		_dimension_defaults = other._dimension_defaults;
		_parent_expressions = other._parent_expressions;
	}

protected:
	token_a<> const _token;
	symbol_a<> const _scope;
	flock_a<> const _names;
	flock_a<> _dimension_kinds;
	flock_a<> _dimension_defaults;
	flock_a<> _parent_expressions;

	inline abstraction_t(token_a<> const& token, symbol_a<> const& scope, flock_a<> const& names, flock_a<> const& dimension_kinds, flock_a<> const& dimension_defaults, flock_a<> const& parent_expressions)
		: operation_t<___ego___>(false, names) //TODO pure
		, _token{ token }
		, _scope{ scope }
		, _dimension_kinds{ dimension_kinds }
		, _dimension_defaults{ dimension_defaults }
		, _parent_expressions{ parent_expressions }
	{}

	static inline void _merge(unordered_shoal_a<> const& parent, unordered_shoal_a<>& child, any_a<> aspects)
	{
		auto& map = child.mutate_map();
		if (parent.has_string("#"))
		{
			aspects = parent.at_string("#");
		}
		bool const aspects_unordered_shoal = check<unordered_shoal_a<>>(aspects);
		for (auto const& member : parent.extract_map())
		{
			if (member.first.is("#"))
			{
				continue;
			}
			if (map.find(member.first) != map.cend())
			{
				// no overrides
				throw dis("strange::abstraction::create merge invalid override");
			}
			if (aspects_unordered_shoal && check<operation_a<>>(member.second))
			{
				auto operation = cast<operation_a<>>(member.second);
				operation.aspects(cast<unordered_shoal_a<>>(aspects));
				map.emplace(member.first, operation);
			}
			else
			{
				map.emplace(member);
			}
		}
	}

private:
	static bool const ___share___;
	friend class ___abstraction_t_share___;
};

template <typename ___ego___>
bool const abstraction_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	abstraction_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
