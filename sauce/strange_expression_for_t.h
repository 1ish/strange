#ifndef COM_ONEISH_STRANGE_EXPRESSION_FOR_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FOR_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_for_t : public expression_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& list)
	{
		return expression_t<___ego___>::template create_expression<expression_for_t<___ego___>>(list);
	}

	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		auto it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create not passed any terms");
		}
		any_a<> scope = *it;
		if (!check<symbol_a<>>(scope))
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create passed non-symbol scope");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create passed too few terms");
		}
		any_a<> initialize = *it;
		if (!check<expression_a<>>(initialize))
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create passed non-expression initialize");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create not passed sufficient terms");
		}
		any_a<> condition = *it;
		if (!check<expression_a<>>(condition))
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create passed non-expression condition");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create not passed sufficient terms");
		}
		any_a<> next = *it;
		if (!check<expression_a<>>(next))
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create passed non-expression next");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create not passed sufficient terms");
		}
		any_a<> loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(__FILE__, __LINE__, token.report() + "strange::expression_for::create passed non-expression loop");
		}
		return expression_a<>::create<expression_for_t<>>(token, terms, fast<expression_a<>>(initialize), fast<expression_a<>>(condition), fast<expression_a<>>(next), fast<expression_a<>>(loop));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_for");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::expression_for::create"), native_function_create(&expression_for_t<>::create__));
		shoal.update(sym("for!"), native_function_create(&expression_for_t<>::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, list_a<> const& list) const
	{
		any_a<> local = any_a<>::val(thing); // new block scope
		any_a<> result = no();
		try
		{
			for (_initialize.operate(local, list); _condition.operate(local, list); _next.operate(local, list))
			{
				try
				{
					auto thing = any_a<>::val(local); // new scope each time round the loop
					result = _loop.operate(thing, list);
				}
				catch (typename expression_t<___ego___>::continue_e&)
				{}
			}
		}
		catch (typename expression_t<___ego___>::break_e&)
		{}
		return result;
	}

	// expression
	inline expression_a<> recreate_() const
	{
		return expression_t<___ego___>::template recreate_expression<expression_for_t<___ego___>>(expression_t<___ego___>::me_());
	}

	inline any_a<> evaluate_() const
	{
		auto local = unordered_shoal_create();
		local.insert(sym("$"), unordered_shoal_create<any_a<>, any_a<>, true>());
		return operate(local, list_create());
	}

	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline any_a<> generate_(number_data_a<int64_t> const& version, number_data_a<int64_t> const& indent, river_a<>& river) const
	{
		generate(version.extract_primitive(), indent.extract_primitive(), river);
		return river;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" for(");
		_initialize.generate(version, indent, river);
		river.write_string(", ");
		_condition.generate(version, indent, river);
		river.write_string(", ");
		_next.generate(version, indent, river);
		river.write_string(", ");
		_loop.generate(version, indent, river);
		river.write_string(")\n");
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
			_initialize.generate_cpp(version, indent, river, declare, define);
			_condition.generate_cpp(version, indent, river, declare, define);
			_next.generate_cpp(version, indent, river, declare, define);
			_loop.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(__FILE__, __LINE__, expression_t<___ego___>::_token.report() + "strange::expression_for::generate_cpp called for wrong type of expression");
		}
		river.write_string(" for(");
		_initialize.generate_cpp(version, indent, river, declare, define);
		river.write_string(";");
		_condition.generate_cpp(version, indent, river, declare, define);
		river.write_string(";");
		_next.generate_cpp(version, indent, river, declare, define);
		river.write_string(")\n{");
		_loop.generate_cpp(version, indent, river, declare, define);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	expression_a<> const _initialize;
	expression_a<> const _condition;
	expression_a<> const _next;
	expression_a<> const _loop;

	friend class any_a<>;

	inline expression_for_t(token_a<> const& token, flock_a<> const& terms, expression_a<> const& initialize, expression_a<> const& condition, expression_a<> const& next, expression_a<> const& loop)
		: expression_t<___ego___>(token, expression_t<___ego___>::pure_literal_terms(token, terms))
		, _terms{ terms }
		, _initialize{ initialize }
		, _condition{ condition }
		, _next{ next }
		, _loop{ loop }
	{}

private:
	static bool const ___share___;
	friend class ___expression_for_t_share___;
};

template <typename ___ego___>
bool const expression_for_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_for_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_for_t_share___
{
	static inline bool ___share___()
	{
		return expression_for_t<>::___share___;
	}
};

} // namespace strange

#endif
