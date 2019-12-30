#ifndef COM_ONEISH_STRANGE_EXPRESSION_FOR_RANGE_T_H
#define COM_ONEISH_STRANGE_EXPRESSION_FOR_RANGE_T_H

namespace strange
{

template <typename ___ego___ = expression_a<>>
class expression_for_range_t : public expression_t<___ego___>
{
public:
	// override
	using over = expression_o<expression_for_range_t<>>;

	// construction
	static inline expression_a<> create_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for_range::create not passed any terms");
		}
		any_a<> term = *it;
		if (!check<expression_a<>>(term))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-expression term");
		}
		if (!term.type_().is("strange::expression_local_insert"))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed invalid parameter term");
		}
		auto const subterms = cast<expression_a<>>(term).terms_();
		if (subterms.size() != 3)
		{
			throw dis(token.report() + "strange::expression_for_range::create passed invalid parameter term");
		}
		auto const name = subterms.at_index(0);
		if (!check<symbol_a<>>(name))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-symbol parameter name");
		}
		auto const kind = subterms.at_index(1);
		if (!check<kind_a<>>(kind) && !check<expression_a<>>(kind))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-kind/expression parameter kind");
		}
		auto const range = subterms.at_index(2);
		if (!check<expression_a<>>(range))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-expression parameter default");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for_range::create not passed sufficient terms");
		}
		auto const loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_for_range::create passed non-expression loop");
		}
		return expression_a<>{ over{ expression_for_range_t<>( token, terms, cast<symbol_a<>>(name), kind, cast<expression_a<>>(range), cast<expression_a<>>(loop)) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<expression_for_range_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<expression_for_range_t<>>::share(shoal);
	}

	// function
	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
#ifdef STRANGE_CHECK_STATIC_CASTS
		if (!check<unordered_shoal_a<>>(thing))
		{
			throw dis(_token.report() + "strange::expression_for_range::operate passed non-unordered-shoal local");
		}
#endif
		auto local_shoal = cast<unordered_shoal_a<>>(thing);
		auto& local = local_shoal.reference();
		auto kind = _kind;
		if (check<expression_a<>>(kind))
		{
			try
			{
				kind = cast<expression_a<>>(kind).operate(local_shoal, range);
			}
			catch (misunderstanding_a<>& misunderstanding)
			{
				throw dis(_token.report() + "strange::expression_for_range::operate kind expression evaluation error") + misunderstanding;
			}
		}
		if (!check<kind_a<>>(kind))
		{
			throw dis(_token.report() + "strange::expression_for_range::operate non-kind parameter kind");
		}
		auto it = local.emplace(_name, no()).first;
		any_a<> result = no();
		auto const for_range = _range.operate(thing, range);
		if (!check<range_a<>>(for_range))
		{
			throw dis(_token.report() + "strange::expression_for_range::operate expression returned non-range");
		}
		auto read_lock = check<collection_a<>>(for_range) ? cast<collection_a<>>(for_range).read_lock_() : no();
		try
		{
			for (auto const& for_thing : cast<range_a<> const>(for_range))
			{
				if (!for_thing.kinds_().has_(kind))
				{
					throw dis(_token.report() + "strange::expression_for_range::operate kind does not include value");
				}
				it->second = for_thing;
				try
				{
					result = _loop.operate(local_shoal, range); //TODO needs to match parser/cpp scope
				}
				catch (continue_i&)
				{}
			}
		}
		catch (break_i&)
		{}
		return result;
	}

	// expression
	inline flock_a<> terms_() const
	{
		return _terms;
	}

	inline void generate(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" for_range_(");
		bool first = true;
		for (auto const& term : _terms.extract())
		{
			if (first)
			{
				first = false;
			}
			else
			{
				river.write_string(",");
			}
			if (!check<expression_a<>>(term))
			{
				throw dis(_token.report() + "strange::expression_for_range::generate with non-expression term");
			}
			cast<expression_a<>>(term).generate(version, indent, river);
		}
		river.write_string(") ");
	}

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river, bool type = false) const
	{
		if (type)
		{
			throw dis(_token.report() + "strange::expression_for_range::generate_cpp called for wrong type of expression");
		}
		//river.write_string(" for(" + _kind.code() + " const& " + _name.to_string() + " : ");
		_range.generate_cpp(version, indent, river);
		river.write_string(")\n{\n");
		_loop.generate_cpp(version, indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _name;
	any_a<> const _kind;
	expression_a<> const _range;
	expression_a<> const _loop;

	inline expression_for_range_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& name, any_a<> const& kind, expression_a<> const& range, expression_a<> const& loop)
		: expression_t(token, pure_literal_terms(token, terms)) //TODO pure literal
		, _terms{ terms }
		, _name{ name }
		, _kind{ kind }
		, _range{ range }
		, _loop{ loop }
	{}

private:
	static bool const ___share___;
	friend class ___expression_for_range_t_share___;
};

template <typename ___ego___>
bool const expression_for_range_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	expression_for_range_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
