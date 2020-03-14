#ifndef COM_ONEISH_STRANGE_EXPRESSION_SHARED_INSERT_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_SHARED_INSERT_T_H

namespace strange
{

// template <typename ___ego___ = expression_a<>>
template <typename ___ego___>
class expression_shared_insert_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_shared_insert_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_extractor_a<> it = terms.extract_begin_();
		if (it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_insert::create not passed any terms");
		}
		any_a<> key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_shared_insert::create passed non-symbol key");
		}
		if (++it == terms.extract_end_())
		{
			throw dis(token.report() + "strange::expression_shared_insert::create not passed sufficient terms");
		}
		any_a<> kind = *it;
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_shared_insert::create passed non-kind/expression");
		}
		if (++it == terms.extract_end_())
		{
			return expression_a<>{ over{ expression_shared_insert_t<>{ token, terms, fast<symbol_a<>>(key), kind, expression_t<>::create(token) } } };
		}
		any_a<> expression = *it;
		if (!check<expression_a<>>(expression))
		{
			throw dis(token.report() + "strange::expression_shared_insert::create passed non-expression");
		}
		return expression_a<>::create<over>(expression_shared_insert_t<>(token, terms, fast<symbol_a<>>(key), kind, fast<expression_a<>>(expression)));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::expression_shared_insert");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::expression_shared_insert::create", native_function_create(&expression_shared_insert_t<>::over::create__));
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_insert::operate passed non-unordered-shoal local");
		}
#endif
		auto& local = static_cast<unordered_shoal_a<>&>(thing).mutate_map();
		auto lit = local.find(sym("$"));
		if (lit == local.end())
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_insert::operate $ not found");
		}
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(lit->second))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_insert::operate passed non-unordered-shoal shared");
		}
#endif
		auto& shared = static_cast<unordered_shoal_a<>&>(lit->second);
		auto& unordered_map = shared.mutate_map();
		{
			auto const read_lock = shared.read_lock_();
			auto const read_it = unordered_map.find(_key);
			if (read_it != unordered_map.end())
			{
				return read_it->second;
			}
		}
		auto const write_lock = shared.write_lock_();
		auto const write_it = unordered_map.find(_key);
		if (write_it != unordered_map.end())
		{
			return write_it->second;
		}
		auto kind = _kind;
		if (check<expression_a<>>(kind))
		{
			try
			{
				kind = fast<expression_a<>>(kind).operate(thing, range);
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_insert::operate kind expression evaluation error") + misunderstanding;
			}
		}
		auto value = any_a<>::val(_expression.operate(thing, range));
		if (!value.kinds_().has_(kind))
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_insert::operate kind does not include value");
		}
		unordered_map.emplace(_key, value);
		return value;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const //TODO
	{
		// river.write_string(" " + fast<symbol_a<>>(_key).to_string() + " :" + _kind.to_string() + "=");
		_expression.generate(version, indent, river);
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool declare, bool define, bool type = false) const //TODO
	{
		if (declare || define)
		{
			_expression.generate_cpp(version, indent, river, declare, define);
			return;
		}
		if (type)
		{
			throw dis(expression_t<___ego___>::_token.report() + "strange::expression_shared_insert::generate_cpp called for wrong type of expression");
		}
		//TODO remove $ prefix
		// river.write_string(" static " + _kind.code() + " " + fast<symbol_a<>>(_key).to_string() + " =");
		_expression.generate_cpp(version, indent, river, declare, define);
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _key;
	any_a<> const _kind;
	expression_a<> const _expression;

	inline expression_shared_insert_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& key, any_a<> const& kind, expression_a<> const& expression)
		: expression_t<___ego___>{ token }
		, _terms{ terms }
		, _key{ key }
		, _kind{ kind }
		, _expression{ expression }
	{}

private:
	static bool const ___share___;
	friend class ___expression_shared_insert_t_share___;
};

template <typename ___ego___>
bool const expression_shared_insert_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	expression_shared_insert_t<___ego___>::share(shoal);
	return shoal;
}();

class ___expression_shared_insert_t_share___
{
	static inline bool ___share___()
	{
		return expression_shared_insert_t<>::___share___;
	}
};

} // namespace strange

#endif
