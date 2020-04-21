#ifndef COM_ONEISH_STRANGE_EXPRESSION_C_H
#define COM_ONEISH_STRANGE_EXPRESSION_C_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_c : public operation_c<___ego___>
{
public:
	// construction
	static inline any_a<> animate__(list_a<> const& list)
	{
		auto it = list.begin_();
		if (it == list.end_())
		{
			throw dis("<strange::expression>::animate passed empty list");
		}
		any_a<> conception = *it;
		if (!check<shoal_a<>>(conception))
		{
			throw dis("<strange::expression>::animate passed non-shoal conception");
		}
		return animate_(fast<shoal_a<>>(conception));
	}

	static inline expression_a<> animate_(shoal_a<> const& conception)
	{
		return expression_a<>{ expression_c{ conception } };
	}

	// reflection
	inline any_a<> type__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("type"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		static symbol_a<> TYPE = sym("<strange::expression>");
		return TYPE;
	}

	inline symbol_a<> type_() const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("type"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			auto const result = op.operate(thing, list_create());
			if (!check<symbol_a<>>(result))
			{
				throw dis("<strange::expression>::type returned non-symbol");
			}
			return fast<symbol_a<>>(result);
		}
		static symbol_a<> TYPE = sym("<strange::expression>");
		return TYPE;
	}

	inline any_a<> shared__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("shared"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	inline unordered_shoal_a<> shared_() const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("shared"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			auto const result = op.operate(thing, list_create());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("<strange::expression>::shared returned non-unordered-shoal");
			}
			return fast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("<strange::expression>::animate"), native_function_create(&expression_c<>::animate__));
	}

	// expression
	inline any_a<> recreate__(list_a<> const&) const // cannot be overridden
	{
		return recreate_();
	}

	inline expression_a<> recreate_() const // cannot be overridden
	{
		return operation_c<___ego___>::me_(); //TODO?
	}

	inline any_a<> literal__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("literal"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		return no();
	}

	inline any_a<> literal_() const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("literal"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list_create());
		}
		return no();
	}

	inline bool literal() const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("literal"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list_create());
		}
		return false;
	}

	inline any_a<> evaluate__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("evaluate"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		auto local = unordered_shoal_t<>::create_();
		local.insert(sym("$"), unordered_shoal_t<any_a<>, any_a<>, true>::create_());
		return operation_c<___ego___>::operate(local, list_create());
	}

	inline any_a<> evaluate_() const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("evaluate"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list_create());
		}
		auto local = unordered_shoal_t<>::create_();
		local.insert(sym("$"), unordered_shoal_t<any_a<>, any_a<>, true>::create_());
		return operation_c<___ego___>::operate(local, list_create());
	}

	inline any_a<> token__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("token"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		return token_t<>::create_punctuation_();
	}

	inline token_a<> token_() const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("token"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			auto const result = op.operate(thing, list_create());
			if (!check<token_a<>>(result))
			{
				throw dis("<strange::expression>::token returned non-token");
			}
			return fast<token_a<>>(result);
		}
		return token_t<>::create_punctuation_();
	}

	inline any_a<> terms__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("terms"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		return flock_t<>::create_();
	}

	inline flock_a<> terms_() const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("terms"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			auto const result = op.operate(thing, list_create());
			if (!check<flock_a<>>(result))
			{
				throw dis("<strange::expression>::terms returned non-flock");
			}
			return fast<flock_a<>>(result);
		}
		return flock_t<>::create_();
	}

	inline any_a<> generate__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("generate"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		auto it = list.begin_();
		if (it == list.end_())
		{
			throw dis("<strange::expression>::generate passed empty list");
		}
		any_a<> version = *it;
		if (!check<number_data_a<int64_t>>(version))
		{
			throw dis("<strange::expression>::generate passed non-int-64 version");
		}
		if (++it == list.end_())
		{
			throw dis("<strange::expression>::generate passed short list");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("<strange::expression>::generate passed non-int-64 indent");
		}
		if (++it == list.end_())
		{
			throw dis("<strange::expression>::generate passed short list");
		}
		any_a<> river = fast_dup(*it);
		if (!check<river_a<>>(river))
		{
			throw dis("<strange::expression>::generate passed non-river");
		}
		return river;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("generate"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, flock_t<>::create_(version, indent, river));
		}
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("generate"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			op.operate(thing, flock_t<>::create_(number_int_64_t<>::create(version), number_int_64_t<>::create(indent), river));
		}
	}

	inline any_a<> generate_cpp__(list_a<> const& list) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("generate_cpp"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, list);
		}
		auto it = list.begin_();
		if (it == list.end_())
		{
			throw dis("<strange::expression>::generate_cpp passed empty list");
		}
		any_a<> version = *it;
		if (!check<number_data_a<int64_t>>(version))
		{
			throw dis("<strange::expression>::generate_cpp passed non-int-64 version");
		}
		if (++it == list.end_())
		{
			throw dis("<strange::expression>::generate_cpp passed short list");
		}
		any_a<> indent = *it;
		if (!check<number_data_a<int64_t>>(indent))
		{
			throw dis("<strange::expression>::generate_cpp passed non-int-64 indent");
		}
		if (++it == list.end_())
		{
			throw dis("<strange::expression>::generate_cpp passed short list");
		}
		any_a<> river = fast_dup(*it);
		if (!check<river_a<>>(river))
		{
			throw dis("<strange::expression>::generate_cpp passed non-river");
		}
		return river;
	}

	inline any_a<> generate_cpp_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river, any_a<> const& declare, any_a<> const& define, any_a<> const& type = no()) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("generate_cpp"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			return op.operate(thing, flock_t<>::create_(version, indent, river, declare, define, type));
		}
		return river;
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const
	{
		auto const op = operation_c<___ego___>::_operations.at_(sym("generate_cpp"));
		if (op)
		{
			any_a<> thing = operation_c<___ego___>::me_();
			op.operate(thing, flock_t<>::create_(number_int_64_t<>::create(version), number_int_64_t<>::create(indent), river, boole(declare), boole(define), boole(type)));
		}
	}

protected:
	// construction
	inline expression_c(shoal_a<> const& conception)
		: operation_c<___ego___>{ conception }
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
	return shoal;
}();

class ___expression_c_share___
{
	static inline bool ___share___()
	{
		return expression_c<>::___share___;
	}
};

} // namespace strange

#endif
