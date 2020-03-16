#ifndef COM_ONEISH_STRANGE_EXPRESSION_LITERAL_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_LITERAL_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_literal_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_literal_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_extractor_a<> it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_literal::create not passed any terms");
		}
		return create(token, terms, *it);
	}

	static inline expression_a<> create(token_a<> const& token, flock_a<> const& terms, any_a<> const& thing)
	{
		return expression_a<>::create<over>(expression_literal_t<>{ token, terms, thing });
	}

	// validation
	static inline any_a<> validate__(range_a<> const& range)
	{
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("strange::expression_literal::validate passed empty range");
		}
		return validate_(*it);
	}

	static inline any_a<> validate_(any_a<> const& thing)
	{
		return boole(validate(thing));
	}

	static inline bool validate(any_a<> const& thing)
	{
		return !check<any_a<>>(thing) ||
			thing.type_() == nothing_t<>::type_() ||
			thing.type_() == something_t<>::type_() ||
			thing.type_() == symbol_t<>::type_() ||
			thing.type_() == lake_int_8_t<>::type_() ||
			thing.type_() == number_int_8_t<>::type_() ||
			thing.type_() == number_uint_8_t<>::type_() ||
			thing.type_() == number_int_16_t<>::type_() ||
			thing.type_() == number_uint_16_t<>::type_() ||
			thing.type_() == number_int_32_t<>::type_() ||
			thing.type_() == number_uint_32_t<>::type_() ||
			thing.type_() == number_int_64_t<>::type_() ||
			thing.type_() == number_uint_64_t<>::type_() ||
			thing.type_() == number_float_32_t<>::type_() ||
			thing.type_() == number_float_64_t<>::type_();
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_literal");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_literal::create", native_function_create(&expression_literal_t<>::over::create__));
		shoal.update_string("strange::expression_literal::validate", native_function_create(&expression_literal_t<>::over::validate__));
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		return _thing;
	}

	// expression
	inline any_a<> evaluate_() const
	{
		any_a<> null;
		return operate(null, range_a<>{});
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		if (!check<any_a<>>(_thing))
		{
			river.write_string(" null ");
		}
		else if (_thing.type_() == nothing_t<>::type_())
		{
			river.write_string(" false ");
		}
		else if (_thing.type_() == something_t<>::type_())
		{
			river.write_string(" true ");
		}
		else if (_thing.type_() == symbol_t<>::type_())
		{
			river.write_string(" '" + fast<symbol_a<>>(_thing).to_string() + "' ");
		}
		else if (_thing.type_() == lake_int_8_t<>::type_())
		{
			river.write_string(" \"" + lake_to_string(fast<lake_a<int8_t>>(_thing)) + "\" ");
		}
		else if (expression_t<___ego___>::_token.literal_() == _thing)
		{
			river.write_string(" " + expression_t<___ego___>::_token.symbol() + " ");
		}
		else if (_thing.type_() == number_int_8_t<>::type_())
		{
			river.write_string(" $$strange::number_int_8::create[" + std::to_string(fast<number_data_a<int8_t>>(_thing).extract_primitive()) + "] ");
		}
		else if	(_thing.type_() == number_uint_8_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_8::create[" + std::to_string(fast<number_data_a<uint8_t>>(_thing).extract_primitive()) + "] ");
		}
		else if (_thing.type_() == number_int_16_t<>::type_())
		{
			river.write_string(" $$strange::number_int_16::create[" + std::to_string(fast<number_data_a<int16_t>>(_thing).extract_primitive()) + "] ");
		}
		else if (_thing.type_() == number_uint_16_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_16::create[" + std::to_string(fast<number_data_a<uint16_t>>(_thing).extract_primitive()) + "] ");
		}
		else if (_thing.type_() == number_int_32_t<>::type_())
		{
			river.write_string(" $$strange::number_int_32::create[" + std::to_string(fast<number_data_a<int32_t>>(_thing).extract_primitive()) + "] ");
		}
		else if (_thing.type_() == number_uint_32_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_32::create[" + std::to_string(fast<number_data_a<uint32_t>>(_thing).extract_primitive()) + "] ");
		}
		else if (_thing.type_() == number_int_64_t<>::type_())
		{
			river.write_string(" " + std::to_string(fast<number_data_a<int64_t>>(_thing).extract_primitive()) + " ");
		}
		else if (_thing.type_() == number_uint_64_t<>::type_())
		{
			river.write_string(" $$strange::number_uint_64::create[" + std::to_string(fast<number_data_a<uint64_t>>(_thing).extract_primitive()) + "] ");
		}
		else if (_thing.type_() == number_float_32_t<>::type_())
		{
			river.write_string(" $$strange::number_float_32::create[" + std::to_string(fast<number_data_a<float>>(_thing).extract_primitive()) + "] ");
		}
		else if (_thing.type_() == number_float_64_t<>::type_())
		{
			river.write_string(" " + std::to_string(fast<number_data_a<double>>(_thing).extract_primitive()) + " ");
		}
		else
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_literal::generate with invalid thing");
		}
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_literal::generate_cpp called for wrong type of expression");
		}
		if (!check<any_a<>>(_thing))
		{
			river.write_string(" strange::any_a<>{} ");
		}
		else if (_thing.type_() == nothing_t<>::type_())
		{
			river.write_string(" strange::no() ");
		}
		else if (_thing.type_() == something_t<>::type_())
		{
			river.write_string(" strange::yes() ");
		}
		else if (_thing.type_() == symbol_t<>::type_())
		{
			river.write_string(" strange::sym(\"" + fast<symbol_a<>>(_thing).to_string() + "\") ");
		}
		else if (_thing.type_() == lake_int_8_t<>::type_())
		{
			river.write_string(" strange::lake_from_string(\"" + lake_to_string(fast<lake_a<int8_t>>(_thing)) + "\") ");
		}
		else if (_thing.type_() == number_int_8_t<>::type_())
		{
			river.write_string(" strange::number_int_8::create(" + std::to_string(fast<number_data_a<int8_t>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_uint_8_t<>::type_())
		{
			river.write_string(" strange::number_uint_8::create(" + std::to_string(fast<number_data_a<uint8_t>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_int_16_t<>::type_())
		{
			river.write_string(" strange::number_int_16::create(" + std::to_string(fast<number_data_a<int16_t>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_uint_16_t<>::type_())
		{
			river.write_string(" strange::number_uint_16::create(" + std::to_string(fast<number_data_a<uint16_t>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_int_32_t<>::type_())
		{
			river.write_string(" strange::number_int_32::create(" + std::to_string(fast<number_data_a<int32_t>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_uint_32_t<>::type_())
		{
			river.write_string(" strange::number_uint_32::create(" + std::to_string(fast<number_data_a<uint32_t>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_int_64_t<>::type_())
		{
			if (expression_t<___ego___>::_token.literal_() == _thing)
			{
				river.write_string(" strange::number_int_64::create(" + expression_t<___ego___>::_token.symbol() + ") ");
			}
			else
			{
				river.write_string(" strange::number_int_64::create(" + std::to_string(fast<number_data_a<int64_t>>(_thing).extract_primitive()) + ") ");
			}
		}
		else if (_thing.type_() == number_uint_64_t<>::type_())
		{
			river.write_string(" strange::number_uint_64::create(" + std::to_string(fast<number_data_a<uint64_t>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_float_32_t<>::type_())
		{
			river.write_string(" strange::number_float_32::create(" + std::to_string(fast<number_data_a<float>>(_thing).extract_primitive()) + ") ");
		}
		else if (_thing.type_() == number_float_64_t<>::type_())
		{
			if (expression_t<___ego___>::_token.literal_() == _thing)
			{
				river.write_string(" strange::number_float_64::create(" + expression_t<___ego___>::_token.symbol() + ") ");
			}
			else
			{
				river.write_string(" strange::number_float_64::create(" + std::to_string(fast<number_data_a<double>>(_thing).extract_primitive()) + ") ");
			}
		}
		else
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_literal::generate_cpp with invalid thing");
		}
	}

protected:
	flock_a<> const _terms;
	any_a<> const _thing;

	inline expression_literal_t(token_a<> const& token, flock_a<> const& terms, any_a<> const& thing)
		: expression_t<___ego___>(token, true, true) // pure, literal
		, _terms{ terms }
		, _thing{ thing }
	{}

private:
	static bool const ___share___;
	friend class ___expression_literal_t_share___;
};

template <typename ___ego___>
bool const expression_literal_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_literal_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_literal_t_share___
{
	static inline bool ___share___()
	{
		return expression_literal_t<>::___share___;
	}
};

} // namespace strange

#endif
