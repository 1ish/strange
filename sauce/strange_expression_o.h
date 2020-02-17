#ifndef COM_ONEISH_STRANGE_EXPRESSION_O_H
#define COM_ONEISH_STRANGE_EXPRESSION_O_H

namespace strange
{

template <typename _OVERRIDDEN_>
class expression_o : public thing_o<_OVERRIDDEN_>
{
public:
	inline expression_o(_OVERRIDDEN_&& overridden)
		: thing_o<_OVERRIDDEN_>{ std::move(overridden) }
	{}

	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[expression] create passed empty range");
		}
		any_a<> token = *it;
		if (!check<token_a<>>(token))
		{
			throw dis("[expression] create passed non-token");
		}
		if (++it == range.cend_())
		{
			throw dis("[expression] create passed short range");
		}
		any_a<> terms = *it;
		if (!check<flock_a<>>(terms))
		{
			throw dis("[expression] create passed non-flock terms");
		}
		return _OVERRIDDEN_::create_(cast<token_a<>>(token), cast<flock_a<>>(terms));
	}

	inline any_a<> recreate__(range_a<> const&) const
	{
		return recreate_();
	}

	inline expression_a<> recreate_() const
	{
		auto terms = _OVERRIDDEN_::terms_();
		std::vector<any_a<>>& vector = const_cast<std::vector<any_a<>>&>(terms.extract_vector());
		for (auto& term : vector)
		{
			if (check<expression_a<>>(term))
			{
				term = cast<expression_a<>>(term).recreate_();
			}
		}
		auto const expression = _OVERRIDDEN_::create_(_OVERRIDDEN_::_token, terms);
		_OVERRIDDEN_::recreated(expression);
		return expression;
	}

	inline any_a<> cat__(range_a<> const&) const
	{
		return _OVERRIDDEN_::cat_();
	}

	inline any_a<> cats__(range_a<> const&) const
	{
		return _OVERRIDDEN_::cats_();
	}

	inline any_a<> kind__(range_a<> const&) const
	{
		return _OVERRIDDEN_::kind_();
	}

	inline any_a<> kinds__(range_a<> const&) const
	{
		return _OVERRIDDEN_::kinds_();
	}

	inline any_a<> literal__(range_a<> const&) const
	{
		return literal_();
	}

	inline any_a<> literal_() const
	{
		return boole(_OVERRIDDEN_::literal());
	}

	inline any_a<> evaluate__(range_a<> const&) const
	{
		return evaluate_();
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert_string("$", unordered_shoal_create<true>());
		return _OVERRIDDEN_::operate(local, range_create());
	}

	inline any_a<> token__(range_a<> const&) const
	{
		return _OVERRIDDEN_::token_();
	}

	inline any_a<> terms__(range_a<> const&) const
	{
		return _OVERRIDDEN_::terms_();
	}

	inline any_a<> generate__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[expression]::generate passed empty range");
		}
		any_a<> version = *it;
		if (!check<number_data_a<int64_t>>(version))
		{
			throw dis("[expression]::generate passed non-int-64 version");
		}
		if (++it == range.cend_())
		{
			throw dis("[expression]::generate passed short range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("[expression]::generate passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("[expression]::generate passed short range");
		}
		any_a<> any_river = any_a<>::dup(const_cast<any_a<>&>(*it));
		if (!check<river_a<>>(any_river))
		{
			throw dis("[expression]::generate passed non-river");
		}
		auto river = cast_dup<river_a<>>(any_river);
		return generate_(cast<number_data_a<int64_t>>(version), cast<number_data_a<int64_t>>(indent), river);
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		_OVERRIDDEN_::generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline any_a<> generate_cpp__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[expression]::generate_cpp passed empty range");
		}
		any_a<> version = *it;
		if (!check<number_data_a<int64_t>>(version))
		{
			throw dis("[expression]::generate_cpp passed non-int-64 version");
		}
		if (++it == range.cend_())
		{
			throw dis("[expression]::generate_cpp passed short range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("[expression]::generate_cpp passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("[expression]::generate_cpp passed short range");
		}
		any_a<> any_river = any_a<>::dup(const_cast<any_a<>&>(*it));
		if (!check<river_a<>>(any_river))
		{
			throw dis("[expression]::generate_cpp passed non-river");
		}
		auto river = cast_dup<river_a<>>(any_river);
		if (++it == range.cend_())
		{
			throw dis("[expression]::generate_cpp passed short range");
		}
		any_a<> declare = *it;
		if (++it == range.cend_())
		{
			throw dis("[expression]::generate_cpp passed short range");
		}
		any_a<> define = *it;
		if (++it == range.cend_())
		{
			return generate_cpp_(cast<number_data_a<int64_t>>(version), cast<number_data_a<int64_t>>(indent), river, declare, define);
		}
		return generate_cpp_(cast<number_data_a<int64_t>>(version), cast<number_data_a<int64_t>>(indent), river, declare, define, *it);
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		_OVERRIDDEN_::generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}
};

} // namespace strange

#endif
