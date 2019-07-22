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
			throw dis("strange::expression_creature::val passed empty range");
		}
		any_a<> creation = *it;
		if (!check<shoal_a<>>(creation))
		{
			throw dis("strange::expression_creature::val passed non-shoal creation");
		}
		return val_(cast<shoal_a<>>(creation));
	}

	static inline expression_a<> val_(shoal_a<> const& creation)
	{
		return expression_a<>{ expression_c{ creation } };
	}

	// reflection
	inline any_a<> type__(range_a<> const& range) const
	{
		auto op = _operations.at_string("type");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return reflection<expression_c<>>::type();
	}

	inline symbol_a<> type_() const
	{
		auto op = _operations.at_string("type");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<symbol_a<>>(result))
			{
				throw dis("strange::expression_creature::type returned non-symbol");
			}
			return cast<symbol_a<>>(result);
		}
		return reflection<expression_c<>>::type();
	}

	inline any_a<> shared__(range_a<> const& range) const
	{
		auto op = _operations.at_string("shared");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::val_();
		share(shoal);
		return shoal;
	}

	inline unordered_shoal_a<> shared_() const
	{
		auto op = _operations.at_string("shared");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("strange::expression_creature::shared returned non-unordered-shoal");
			}
			return cast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::val_();
		share(shoal);
		return shoal;
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_c<>>::share(shoal);
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
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<token_a<>>(result))
			{
				throw dis("strange::expression_creature::token returned non-token");
			}
			return cast<token_a<>>(result);
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
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<flock_a<>>(result))
			{
				throw dis("strange::expression_creature::terms returned non-flock");
			}
			return cast<flock_a<>>(result);
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
			throw dis("strange::expression_creature::generate passed empty range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("strange::expression_creature::generate passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::expression_creature::generate passed short range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("strange::expression_creature::generate passed non-river");
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
			op.operate_(any_a<>(me_(), true), flock_t<>::val_(number_int_64_t<>::val(indent), river));
		}
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
			throw dis("strange::expression_creature::generate_cpp passed empty range");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("strange::expression_creature::generate_cpp passed non-int-64 indent");
		}
		if (++it == range.cend_())
		{
			throw dis("strange::expression_creature::generate_cpp passed short range");
		}
		any_a<> river = *it;
		if (!check<river_a<>>(river))
		{
			throw dis("strange::expression_creature::generate_cpp passed non-river");
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
			op.operate_(any_a<>(me_(), true), flock_t<>::val_(number_int_64_t<>::val(indent), river));
		}
	}

protected:
	// construction
	inline expression_c(shoal_a<> const& creation)
		: operation_c{ creation }
	{}

private:
	static bool const ___share___;
	friend class ___expression_c_share___;
};

template <typename _ABSTRACTION_>
bool const expression_c<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_c<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
