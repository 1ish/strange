#ifndef COM_ONEISH_STRANGE_EXPRESSION_LITERAL_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LITERAL_T_H

namespace strange
{

template <typename _ABSTRACTION_ = expression_a<>>
class expression_literal_t : public expression_t<_ABSTRACTION_>
{
public:
	// override
	using over = expression_o<expression_literal_t<>>;

	// construction
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_literal::val not passed any terms");
		}
		return val(token, terms, *it);
	}

	static inline expression_a<> val(token_a<> const& token, flock_a<> const& terms, any_a<> const& literal)
	{
		return expression_a<>{ over{ expression_literal_t<>{ token, terms, literal } } };
	}

	// validation
	static inline any_a<> validate__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::expression_literal::validate passed empty range");
		}
		return validate_(*it);
	}

	static inline any_a<> validate_(any_a<> const& literal)
	{
		return boole(validate(literal));
	}

	static inline bool validate(any_a<> const& literal)
	{
		return literal.type_() == symbol_t<>::type_() ||
			literal.type_() == lake_int_8_t<>::type_() ||
			literal.type_() == number_int_8_t<>::type_() ||
			literal.type_() == number_uint_8_t<>::type_() ||
			literal.type_() == number_int_16_t<>::type_() ||
			literal.type_() == number_uint_16_t<>::type_() ||
			literal.type_() == number_int_32_t<>::type_() ||
			literal.type_() == number_uint_32_t<>::type_() ||
			literal.type_() == number_int_64_t<>::type_() ||
			literal.type_() == number_uint_64_t<>::type_() ||
			literal.type_() == number_float_32_t<>::type_() ||
			literal.type_() == number_float_64_t<>::type_();
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_literal_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_literal_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate_(any_a<>& thing, range_a<> const& range) const
	{
		return _literal;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		if (_literal.type_() == symbol_t<>::type_())
		{
			river.write_string(" '" + cast<symbol_a<>>(_literal).to_string() + "' ");
		}
		else if (_literal.type_() == lake_int_8_t<>::type_())
		{
			river.write_string(" \"" + lake_to_string(cast<lake_a<int8_t>>(_literal)) + "\" ");
		}
		else if (_token.literal_() == _literal)
		{
			river.write_string(" " + _token.symbol() + " ");
		}
		else if (_literal.type_() == number_int_8_t<>::type_())
		{
			river.write_string(" $$strange::number_int_8::val[" + std::to_string(cast<number_data_a<int8_t>>(_literal).extract()) + "] ");
		}
		else if	(_literal.type_() == number_uint_8_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_8::val[" + std::to_string(cast<number_data_a<uint8_t>>(_literal).extract()) + "] ");
		}
		else if (_literal.type_() == number_int_16_t<>::type_())
		{
			river.write_string(" $$strange::number_int_16::val[" + std::to_string(cast<number_data_a<int16_t>>(_literal).extract()) + "] ");
		}
		else if (_literal.type_() == number_uint_16_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_16::val[" + std::to_string(cast<number_data_a<uint16_t>>(_literal).extract()) + "] ");
		}
		else if (_literal.type_() == number_int_32_t<>::type_())
		{
			river.write_string(" $$strange::number_int_32::val[" + std::to_string(cast<number_data_a<int32_t>>(_literal).extract()) + "] ");
		}
		else if (_literal.type_() == number_uint_32_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_32::val[" + std::to_string(cast<number_data_a<uint32_t>>(_literal).extract()) + "] ");
		}
		else if (_literal.type_() == number_int_64_t<>::type_())
		{
			river.write_string(" " + std::to_string(cast<number_data_a<int64_t>>(_literal).extract()) + " ");
		}
		else if (_literal.type_() == number_uint_64_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_64::val[" + std::to_string(cast<number_data_a<uint64_t>>(_literal).extract()) + "] ");
		}
		else if (_literal.type_() == number_float_32_t<>::type_())
		{
			river.write_string(" $$strange::number_float_32::val[" + std::to_string(cast<number_data_a<float>>(_literal).extract()) + "] ");
		}
		else if (_literal.type_() == number_float_64_t<>::type_())
		{
			river.write_string(" " + std::to_string(cast<number_data_a<double>>(_literal).extract()) + " ");
		}
		else
		{
			throw dis(_token.report() + "strange::expression_literal::generate with invalid literal");
		}
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		if (_literal.type_() == symbol_t<>::type_())
		{
			river.write_string(" strange::sym(\"" + cast<symbol_a<>>(_literal).to_string() + "\") ");
		}
		else if (_literal.type_() == lake_int_8_t<>::type_())
		{
			river.write_string(" strange::lake_from_string(\"" + lake_to_string(cast<lake_a<int8_t>>(_literal)) + "\") ");
		}
		else if (_literal.type_() == number_int_8_t<>::type_())
		{
			river.write_string(" strange::number_int_8::val(" + std::to_string(cast<number_data_a<int8_t>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_uint_8_t<>::type_())
		{
			river.write_string(" strange::number_uint_8::val(" + std::to_string(cast<number_data_a<uint8_t>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_int_16_t<>::type_())
		{
			river.write_string(" strange::number_int_16::val(" + std::to_string(cast<number_data_a<int16_t>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_uint_16_t<>::type_())
		{
			river.write_string(" strange::number_uint_16::val(" + std::to_string(cast<number_data_a<uint16_t>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_int_32_t<>::type_())
		{
			river.write_string(" strange::number_int_32::val(" + std::to_string(cast<number_data_a<int32_t>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_uint_32_t<>::type_())
		{
			river.write_string(" strange::number_uint_32::val(" + std::to_string(cast<number_data_a<uint32_t>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_int_64_t<>::type_())
		{
			if (_token.literal_() == _literal)
			{
				river.write_string(" strange::number_int_64::val(" + _token.symbol() + ") ");
			}
			else
			{
				river.write_string(" strange::number_int_64::val(" + std::to_string(cast<number_data_a<int64_t>>(_literal).extract()) + ") ");
			}
		}
		else if (_literal.type_() == number_uint_64_t<>::type_())
		{
			river.write_string(" strange::number_uint_64::val(" + std::to_string(cast<number_data_a<uint64_t>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_float_32_t<>::type_())
		{
			river.write_string(" strange::number_float_32::val(" + std::to_string(cast<number_data_a<float>>(_literal).extract()) + ") ");
		}
		else if (_literal.type_() == number_float_64_t<>::type_())
		{
			if (_token.literal_() == _literal)
			{
				river.write_string(" strange::number_float_64::val(" + _token.symbol() + ") ");
			}
			else
			{
				river.write_string(" strange::number_float_64::val(" + std::to_string(cast<number_data_a<double>>(_literal).extract()) + ") ");
			}
		}
		else
		{
			throw dis(_token.report() + "strange::expression_literal::generate_cpp with invalid literal");
		}
	}

protected:
	flock_a<> const _terms;
	any_a<> const _literal;

	inline expression_literal_t(token_a<> const& token, flock_a<> const& terms, any_a<> const& literal)
		: expression_t(token, true, true) // pure, literal
		, _terms{ terms }
		, _literal{ literal }
	{}

private:
	static bool const ___share___;
	friend class ___expression_literal_t_share___;
};

template <typename _ABSTRACTION_>
bool const expression_literal_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_literal_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
