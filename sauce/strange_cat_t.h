#ifndef COM_ONEISH_STRANGE_CAT_T_H
#define COM_ONEISH_STRANGE_CAT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = cat_a<>>
class cat_t : public symbol_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<cat_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return val_();
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis("strange::cat::val passed non-symbol name");
		}
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name));
		}
		any_a<> args = *it;
		if (!check<flock_a<>>(args))
		{
			throw dis("strange::cat::val passed non-flock args");
		}
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args));
		}
		any_a<> params = *it;
		if (!check<flock_a<>>(params))
		{
			throw dis("strange::cat::val passed non-flock params");
		}
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params));
		}
		any_a<> result = *it;
		if (!check<symbol_a<>>(result))
		{
			throw dis("strange::cat::val passed non-symbol result");
		}
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result));
		}
		any_a<> ref = *it;
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result), ref);
		}
		any_a<> subs = *it;
		if (!check<herd_a<>>(subs))
		{
			throw dis("strange::cat::val passed non-herd subs");
		}
		return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result), ref, cast<herd_a<>>(subs));
	}

	static inline cat_a<> val_()
	{
		static cat_a<> VAL = val("");
		return VAL;
	}

	static inline cat_a<> val_(symbol_a<> const& name, flock_a<> const& args = flock_t<>::val_(), flock_a<> const& params = flock_t<>::val_(), symbol_a<> const& result = any_sym(), bool const ref = false, herd_a<> const& subs = unordered_herd_t<>::val_())
	{
		return cat_a<>{ over{ cat_t<>(name, args, params, result, ref, subs) } };
	}

	static inline cat_a<> val(std::string const& name, flock_a<> const& args = flock_t<>::val_(), flock_a<> const& params = flock_t<>::val_(), symbol_a<> const& result = any_sym(), bool const ref = false, herd_a<> const& subs = unordered_herd_t<>::val_())
	{
		return val_(sym(name), args, params, result, ref, subs);
	}

	static inline symbol_a<> any_sym()
	{
		static symbol_a<> ANY = sym("<>");
		return ANY;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<cat_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<cat_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<cat_a<>>(thing))
		{
			return false;
		}
		auto cat = cast<cat_a<>>(thing);
		if (_symbolic != cat.symbolic() || _hash != cat.hash())
		{
			return false;
		}
		bool const same = symbol_t<_ABSTRACTION_>::operator==(thing);
		if (_symbolic || !same)
		{
			return same;
		}
		return _args == cat.args_() && _params == cat.params_() && result_() == cat.result_();
	}

	// cat
	inline any_a<> symbolic__(range_a<> const& _) const
	{
		return symbolic_();
	}

	inline any_a<> symbolic_() const
	{
		return boole(symbolic());
	}

	inline bool symbolic() const
	{
		return _symbolic;
	}

	inline any_a<> name__(range_a<> const& _) const
	{
		return name_();
	}

	inline symbol_a<> name_() const
	{
		return _name;
	}

	inline any_a<> args__(range_a<> const& _) const
	{
		return args_();
	}

	inline flock_a<> args_() const
	{
		return _args;
	}

	inline any_a<> params__(range_a<> const& _) const
	{
		return params_();
	}

	inline flock_a<> params_() const
	{
		return _params;
	}

	inline any_a<> result__(range_a<> const& _) const
	{
		return result_();
	}

	inline cat_a<> result_() const
	{
		return check<cat_a<>>(_result) ? cast<cat_a<>>(_result) : val_();
	}

	inline any_a<> ref__(range_a<> const& _) const
	{
		return ref_();
	}

	inline any_a<> ref_() const
	{
		return boole(ref());
	}

	inline bool ref() const
	{
		return _ref;
	}

	inline any_a<> subs__(range_a<> const& _) const
	{
		return subs_();
	}

	inline herd_a<> subs_() const
	{
		return _subs;
	}
	/*
	inline any_a<> includes__(range_a<> const& range) const
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::cat::includes passed empty range");
		}
		return includes_(*it);
	}

	inline any_a<> includes_(any_a<> const& thing) const
	{
		return boole(includes(thing));
	}

	inline bool includes(any_a<> const& thing) const
	{
		return thing.cats_().has_(me_());
	}

	static inline any_a<> conforms__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::cat::conforms passed empty range");
		}
		any_a<> thing = *it;
		if (++it == range.cend_())
		{
			throw dis("strange::cat::conforms passed short range");
		}
		return conforms_(thing, *it);
	}

	static inline any_a<> conforms_(any_a<> const& thing, any_a<> const& cat_or_cats)
	{
		return boole(conforms(thing, cat_or_cats));
	}

	static inline bool conforms(any_a<> const& thing, any_a<> const& cat_or_cats)
	{
		auto cats = thing.cats_();
		if (check<cat_a<>>(cat_or_cats))
		{
			return cats.has_(cat_or_cats);
		}
		if (check<range_a<>>(cat_or_cats))
		{
			for (auto const& cat : cast<range_a<>>(cat_or_cats))
			{
				if (cats.has_(cat))
				{
					return true;
				}
			}
			return false;
		}
		throw dis("strange::cat:conforms passed non-cat-or-cats");
	}
*/
	inline any_a<> code__(range_a<> const& _) const
	{
		return code_();
	}

	inline lake_a<int8_t> code_() const
	{
		return lake_from_string(code());
	}

	inline std::string code() const
	{
		return _name.to_string() + "_a<>";
	}

protected:
	bool const _symbolic; // recursively true if all of the cats below are symbolic and there are no non-cat args
	symbol_a<> const _name;
	flock_a<> const _args;
	flock_a<> const _params;
	symbol_a<> const _result;
	bool const _ref;
	herd_a<> const _subs;

	inline cat_t(symbol_a<> const& name, flock_a<> const& args, flock_a<> const& params, symbol_a<> const& result, bool const ref, herd_a<> const& subs)
		: symbol_t{ _symbol_(name, args, params, result) }
		, _symbolic{ _symbolic_(args, params, result) }
		, _name{ name }
		, _args{ args }
		, _params{ params }
		, _result{ _result_(result) }
		, _ref{ ref }
		, _subs{ subs }
	{}

	static inline std::string const _symbol_(symbol_a<> const& name, flock_a<> const& args, flock_a<> const& params, symbol_a<> const& result)
	{
		std::string symbol = "<" + name.to_string();

		bool any = false;
		int64_t anys = 0;
		for (auto const& arg : args)
		{
			bool const is_cat = check<cat_a<>>(arg);
			cat_a<> cat;
			if (is_cat)
			{
				cat = cast<cat_a<>>(arg);
			}
			std::string str;
			if (is_cat && (str = cat.to_string()) == "<>")
			{
				++anys;
				continue;
			}
			if (any)
			{
				symbol += ",";
			}
			else
			{
				symbol += "[";
				any = true;
			}
			while (anys)
			{
				symbol += "<>,";
				--anys;
			}
			if (is_cat)
			{
				symbol += str;
			}
			else
			{
				symbol += "#" + std::to_string(arg.hash());
			}
		}
		if (any)
		{
			symbol += "]";
			any = false;
		}

		anys = 0;
		for (auto const& param : params)
		{
			cat_a<> const cat = cast<cat_a<>>(param);
			std::string const str = cat.to_string();
			if (str == "<>")
			{
				++anys;
				continue;
			}
			if (any)
			{
				symbol += ",";
			}
			else
			{
				symbol += "(";
				any = true;
			}
			while (anys)
			{
				symbol += "<>,";
				--anys;
			}
			symbol += str;
		}
		if (any)
		{
			symbol += ")";
		}

		if (check<cat_a<>>(result))
		{
			std::string const& str = result.to_string();
			if (str != "<>")
			{
				symbol += str;
			}
		}

		symbol += ">";
		return symbol;
	}

	static inline bool _symbolic_(flock_a<> const& args, flock_a<> const& params, symbol_a<> const& result)
	{
		if (check<cat_a<>>(result) && !cast<cat_a<>>(result).symbolic())
		{
			return false;
		}
		for (auto const& arg : args)
		{
			if (!check<cat_a<>>(arg) || !cast<cat_a<>>(arg).symbolic())
			{
				return false;
			}
		}
		for (auto const& param : params)
		{
			if (!cast<cat_a<>>(param).symbolic())
			{
				return false;
			}
		}
		return true;
	}

	static inline symbol_a<> _result_(symbol_a<> const& result)
	{
		return (check<cat_a<>>(result) && result.to_string() != "<>") ? result : any_sym();
	}

private:
	static bool const ___share___;
	friend class ___cat_t_share___;
};

template <typename _ABSTRACTION_>
bool const cat_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	cat_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

class ___cat_t_share___
{
	static inline bool ___share___()
	{
		return cat_t<>::___share___;
	}
};

} // namespace strange

#endif
