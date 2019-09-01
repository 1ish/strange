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
	static inline expression_a<> val_(token_a<> const& token, flock_a<> const& terms)
	{
		forward_const_iterator_a<> it = terms.cbegin_();
		if (it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for_range::val not passed any terms");
		}
		any_a<> key = *it;
		if (!check<symbol_a<>>(key))
		{
			throw dis(token.report() + "strange::expression_for_range::val passed non-symbol key");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for_range::val not passed sufficient terms");
		}
		any_a<> cat = *it;
		if (!check<cat_a<>>(cat))
		{
			throw dis(token.report() + "strange::expression_for_range::val passed non-cat");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for_range::val not passed sufficient terms");
		}
		any_a<> range = *it;
		if (!check<expression_a<>>(range))
		{
			throw dis(token.report() + "strange::expression_for_range::val passed non-expression range");
		}
		if (++it == terms.cend_())
		{
			throw dis(token.report() + "strange::expression_for_range::val not passed sufficient terms");
		}
		any_a<> loop = *it;
		if (!check<expression_a<>>(loop))
		{
			throw dis(token.report() + "strange::expression_for_range::val passed non-expression loop");
		}
		return expression_a<>{ over{ expression_for_range_t<>( token, terms, cast<symbol_a<>>(key), cast<cat_a<>>(cat), cast<expression_a<>>(range), cast<expression_a<>>(loop)) } };
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
		auto& local = static_cast<unordered_shoal_a<>&>(thing).reference();
		auto it = local.emplace(_key, no()).first;
		any_a<> result = no();
		try
		{
			auto for_range = _range.operate(thing, range);
			if (!check<range_a<>>(for_range))
			{
				throw dis(_token.report() + "strange::expression_for_range::operate expression returned non-range");
			}
			for (auto const& for_thing : cast<range_a<>>(for_range))
			{
				if (!for_thing.cats_().has_(_cat))
				{
					throw dis(_token.report() + "strange::expression_for_range::operate cat does not include value");
				}
				it->second = for_thing;
				try
				{
					result = _loop.operate(thing, range);
				}
				catch (continue_i&)
				{
				}
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
		for (auto const& term : _terms)
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

	inline void generate_cpp(int64_t version, int64_t indent, river_a<>& river) const
	{
		river.write_string(" for(" + _cat.code() + " const& " + _key.to_string() + " : ");
		_range.generate_cpp(version, indent, river);
		river.write_string(")\n{\n");
		_loop.generate_cpp(version, indent, river);
		river.write_string("}\n");
	}

protected:
	flock_a<> const _terms;
	symbol_a<> const _key;
	cat_a<> const _cat;
	expression_a<> const _range;
	expression_a<> const _loop;

	inline expression_for_range_t(token_a<> const& token, flock_a<> const& terms, symbol_a<> const& key, cat_a<> const& cat, expression_a<> const& range, expression_a<> const& loop)
		: expression_t(token, pure_literal_terms(token, terms))
		, _terms{ terms }
		, _key{ key }
		, _cat{ cat }
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
