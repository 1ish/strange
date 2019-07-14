#ifndef COM_ONEISH_STRANGE_EXPRESSION_C_H
#define COM_ONEISH_STRANGE_EXPRESSION_C_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_c : public operation_c<_ABSTRACTION_>
{
public:
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::expression creature val passed empty range");
		}
		any_a<> creation = *it;
		if (!check<shoal_a<>>(creation))
		{
			throw dis("strange::expression creature val passed non-shoal creation");
		}
		return val_(cast<shoal_a<>>(creation));
	}

	static inline any_a<> val_(shoal_a<> const& creation)
	{
		return any_a<>{ expression_c{ creation } };
	}

	// expression
	inline any_a<> evaluate__(range_a<> const& range) const
	{
		auto op = _operations.at_string("evaluate");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		auto local = unordered_shoal_t<>::val_();
		local.insert_string("$", unordered_shoal_t<true>::val_());
		return operate_(local, range_t<>::val_());
	}

	inline any_a<> evaluate_() const
	{
		auto op = _operations.at_string("evaluate");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		auto local = unordered_shoal_t<>::val_();
		local.insert_string("$", unordered_shoal_t<true>::val_());
		return operate_(local, range_t<>::val_());
	}

	inline any_a<> token__(range_a<> const& range) const
	{
		auto op = _operations.at_string("token");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return token_t<>::punctuation_val("", 0, 0, "");
	}

	inline token_a<> token_() const
	{
		auto op = _operations.at_string("token");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		return token_t<>::punctuation_val("", 0, 0, "");
	}

	inline any_a<> terms__(range_a<> const& range) const
	{
		auto op = _operations.at_string("terms");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return flock_t<>::val_();
	}

	inline flock_a<> terms_() const
	{
		auto op = _operations.at_string("terms");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		return flock_t<>::val_();
	}

	inline any_a<> generate__(range_a<> const& range) const
	{
		auto op = _operations.at_string("generate");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::expression creature generate passed empty range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("strange::expression creature generate passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::expression creature generate passed short range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("strange::expression creature generate passed non-river");
		}
		return river;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		auto op = _operations.at_string("generate");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), flock_t<>::val_(indent, river));
		}
		return river;
	}

	inline void generate(int64_t indent, river_a<>& river) const
	{
		auto op = _operations.at_string("generate");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), flock_t<>::val_(number_int_64_t<>::val(indent), river));
		}
		return river;
	}

	inline any_a<> generate_cpp__(range_a<> const& range) const
	{
		auto op = _operations.at_string("generate_cpp");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::expression creature generate_cpp passed empty range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("strange::expression creature generate_cpp passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::expression creature generate_cpp passed short range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("strange::expression creature generate_cpp passed non-river");
		}
		return river;
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		auto op = _operations.at_string("generate_cpp");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), flock_t<>::val_(indent, river));
		}
		return river;
	}

	inline void generate_cpp(int64_t indent, river_a<>& river) const
	{
		auto op = _operations.at_string("generate_cpp");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), flock_t<>::val_(number_int_64_t<>::val(indent), river));
		}
		return river;
	}

protected:
	// construction
	inline expression_c(shoal_a<> const& creation)
		: operation_c{ creation }
	{}
};

} // namespace strange

#endif
