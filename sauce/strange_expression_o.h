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

	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("[expression] val passed empty range");
		}
		any_a<> token = *it;
		if (!check<token_a<>>(token))
		{
			throw dis("[expression] val passed non-token");
		}
		return val_(cast<token_a<>>(token), flock_t<>::val_() += range_t<>::val_(++it, range.cend_()));
	}

	inline any_a<> cat__(range_a<> const&) const
	{
		return cat_();
	}

	inline any_a<> cats__(range_a<> const&) const
	{
		return cats_();
	}

	inline any_a<> kind__(range_a<> const&) const
	{
		return kind_();
	}

	inline any_a<> kinds__(range_a<> const&) const
	{
		return kinds_();
	}

	inline any_a<> evaluate__(range_a<> const&) const
	{
		return evaluate_();
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_t<>::val_();
		local.insert_string("$", unordered_shoal_t<true>::val_());
		return operate(local, range_t<>::val_());
	}

	inline any_a<> token__(range_a<> const&) const
	{
		return token_();
	}

	inline any_a<> terms__(range_a<> const&) const
	{
		return terms_();
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
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("[expression]::generate passed non-river");
		}
		return generate_(cast<number_data_a<int64_t>>(version), cast<number_data_a<int64_t>>(indent), cast<river_a<>>(river, true));
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract(), indent.extract(), river);
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
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("[expression]::generate_cpp passed non-river");
		}
		return generate_cpp_(cast<number_data_a<int64_t>>(version), cast<number_data_a<int64_t>>(indent), cast<river_a<>>(river, true));
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate_cpp(version.extract(), indent.extract(), river);
		return river;
	}
};

} // namespace strange

#endif
