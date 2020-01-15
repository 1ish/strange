#ifndef COM_ONEISH_STRANGE_EXPRESSION_C_H
#define COM_ONEISH_STRANGE_EXPRESSION_C_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_c : public operation_c<___ego___>
{
public:
	// construction
	static inline any_a<> animate__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("<strange::expression>::animate passed empty range");
		}
		any_a<> conception = *it;
		if (!check<shoal_a<>>(conception))
		{
			throw dis("<strange::expression>::animate passed non-shoal conception");
		}
		return animate_(cast<shoal_a<>>(conception));
	}

	static inline expression_a<> animate_(shoal_a<> const& conception)
	{
		return expression_a<>{ expression_c{ conception } };
	}

	// reflection
	inline any_a<> type__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("type");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		return reflection<expression_c<>>::type();
	}

	inline symbol_a<> type_() const
	{
		auto const op = _operations.at_string("type");
		if (op)
		{
			auto const result = op.operate(any_a<>{ me_() }, range_t<>::create_());
			if (!check<symbol_a<>>(result))
			{
				throw dis("<strange::expression>::type returned non-symbol");
			}
			return cast<symbol_a<>>(result);
		}
		return reflection<expression_c<>>::type();
	}

	inline any_a<> shared__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("shared");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	inline unordered_shoal_a<> shared_() const
	{
		auto const op = _operations.at_string("shared");
		if (op)
		{
			auto const result = op.operate(any_a<>{ me_() }, range_t<>::create_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("<strange::expression>::shared returned non-unordered-shoal");
			}
			return cast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_c<>>::share(shoal);
	}

	// expression
	inline any_a<> recreate__(range_a<> const&) const // cannot be overridden
	{
		return recreate_();
	}

	inline expression_a<> recreate_() const // cannot be overridden
	{
		return me_(); //TODO?
	}

	inline void recreated(expression_a<> const& expression) const
	{}

	inline any_a<> literal__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("literal");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		return no();
	}

	inline any_a<> literal_() const
	{
		auto const op = _operations.at_string("literal");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range_t<>::create_());
		}
		return no();
	}

	inline bool literal() const
	{
		auto const op = _operations.at_string("literal");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range_t<>::create_());
		}
		return false;
	}

	inline any_a<> evaluate__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("evaluate");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		auto local = unordered_shoal_t<>::create_();
		local.insert_string("$", unordered_shoal_t<true>::create_());
		return operate(local, range_t<>::create_());
	}

	inline any_a<> evaluate_() const
	{
		auto const op = _operations.at_string("evaluate");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range_t<>::create_());
		}
		auto local = unordered_shoal_t<>::create_();
		local.insert_string("$", unordered_shoal_t<true>::create_());
		return operate(local, range_t<>::create_());
	}

	inline any_a<> token__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("token");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		return token_t<>::create_punctuation_();
	}

	inline token_a<> token_() const
	{
		auto const op = _operations.at_string("token");
		if (op)
		{
			auto const result = op.operate(any_a<>{ me_() }, range_t<>::create_());
			if (!check<token_a<>>(result))
			{
				throw dis("<strange::expression>::token returned non-token");
			}
			return cast<token_a<>>(result);
		}
		return token_t<>::create_punctuation_();
	}

	inline any_a<> terms__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("terms");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		return flock_t<>::create_();
	}

	inline flock_a<> terms_() const
	{
		auto const op = _operations.at_string("terms");
		if (op)
		{
			auto const result = op.operate(any_a<>{ me_() }, range_t<>::create_());
			if (!check<flock_a<>>(result))
			{
				throw dis("<strange::expression>::terms returned non-flock");
			}
			return cast<flock_a<>>(result);
		}
		return flock_t<>::create_();
	}

	inline any_a<> generate__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("generate");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("<strange::expression>::generate passed empty range");
		}
		any_a<> version = *it;
		if (!check<number_data_a<int64_t>>(version))
		{
			throw dis("<strange::expression>::generate passed non-int-64 version");
		}
		if (++it == range.cend_())
		{
			throw dis("<strange::expression>::generate passed short range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("<strange::expression>::generate passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("<strange::expression>::generate passed short range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("<strange::expression>::generate passed non-river");
		}
		return river;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		auto const op = _operations.at_string("generate");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, flock_t<>::create_(version, indent, river));
		}
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		auto const op = _operations.at_string("generate");
		if (op)
		{
			op.operate(any_a<>{ me_() }, flock_t<>::create_(number_int_64_t<>::create(version), number_int_64_t<>::create(indent), river));
		}
	}

	inline any_a<> generate_cpp__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("generate_cpp");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, range);
		}
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("<strange::expression>::generate_cpp passed empty range");
		}
		any_a<> version = *it;
		if (!check<number_data_a<int64_t>>(version))
		{
			throw dis("<strange::expression>::generate_cpp passed non-int-64 version");
		}
		if (++it == range.cend_())
		{
			throw dis("<strange::expression>::generate_cpp passed short range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("<strange::expression>::generate_cpp passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("<strange::expression>::generate_cpp passed short range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("<strange::expression>::generate_cpp passed non-river");
		}
		return river;
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& def, any_a<> const& type = no()) const
	{
		auto const op = _operations.at_string("generate_cpp");
		if (op)
		{
			return op.operate(any_a<>{ me_() }, flock_t<>::create_(version, indent, river, def, type));
		}
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool def, bool type = false) const
	{
		auto const op = _operations.at_string("generate_cpp");
		if (op)
		{
			op.operate(any_a<>{ me_() }, flock_t<>::create_(number_int_64_t<>::create(version), number_int_64_t<>::create(indent), river, boole(def), boole(type)));
		}
	}

protected:
	// construction
	inline expression_c(shoal_a<> const& conception)
		: operation_c{ conception }
	{}

private:
	static bool const ___share___;
	friend class ___expression_c_share___;
};

template <typename ___ego___>
bool const expression_c<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_c<___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
