#ifndef COM_ONEISH_STRANGE_EXPRESSION_O_H
#define COM_ONEISH_STRANGE_EXPRESSION_O_H

namespace strange
{

template <typename _OVERRIDDEN_>
class expression_o : public _OVERRIDDEN_
{
public:
	inline expression_o(_OVERRIDDEN_&& overridden)
		: _OVERRIDDEN_{ std::move(overridden) }
	{}

	static inline any_a<> create__(range_a<> const& range)
	{
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("[expression] create passed empty range");
		}
		any_a<> token = *it;
		if (!check<token_a<>>(token))
		{
			throw dis("[expression] create passed non-token");
		}
		if (++it == range.extract_end_())
		{
			throw dis("[expression] create passed short range");
		}
		any_a<> terms = *it;
		if (!check<flock_a<>>(terms))
		{
			throw dis("[expression] create passed non-flock terms");
		}
		return _OVERRIDDEN_::create_(fast<token_a<>>(token), fast<flock_a<>>(terms));
	}

	inline expression_a<> recreate_() const
	{
		auto terms = _OVERRIDDEN_::terms_();
		std::vector<any_a<>>& vector = const_cast<std::vector<any_a<>>&>(terms.extract_vector());
		for (auto& term : vector)
		{
			if (check<expression_a<>>(term))
			{
				term = fast<expression_a<>>(term).recreate_();
			}
		}
		auto const expression = _OVERRIDDEN_::create_(_OVERRIDDEN_::_token, terms);
		_OVERRIDDEN_::recreated(expression);
		return expression;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		_OVERRIDDEN_::generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		_OVERRIDDEN_::generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}
};

} // namespace strange

#endif
