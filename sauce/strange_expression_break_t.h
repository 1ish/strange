#ifndef COM_ONEISH_STRANGE_EXPRESSION_BREAK_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_BREAK_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_break_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_break_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		return expression_a<>::create<over>(expression_break_t<>{ token });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_break");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_break::create", native_function_create(&expression_break_t<>::over::create__));
		shoal.update_string("break!", native_function_create(&expression_break_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		throw typename expression_t<___ego___>::break_i{};
	}

	// expression
	inline any_a<> evaluate_() const
	{
		any_a<> null;
		return operate(null, range_a<>{});
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		// break()
		river.write_string(" break() ");
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		generate_cpp(version.extract_primitive(), indent.extract_primitive(), river, declare, define, type);
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		if (declare || define)
		{
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_break::generate_cpp called for wrong type of expression");
		}
		river.write_string(" break; ");
	}

protected:
	inline expression_break_t(token_a<> const& token)
		: expression_t<___ego___>(token, true, true) // pure, literal
	{}

private:
	static bool const ___share___;
	friend class ___expression_break_t_share___;
};

template <typename ___ego___>
bool const expression_break_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_break_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_break_t_share___
{
	static inline bool ___share___()
	{
		return expression_break_t<>::___share___;
	}
};

} // namespace strange

#endif
