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
		any_a<> def = *it;
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result), def);
		}
		any_a<> ref = *it;
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result), def, ref);
		}
		any_a<> kind = *it;
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result), def, ref, kind);
		}
		any_a<> order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis("strange::cat::val passed non-int-64 order");
		}
		return val_(cast<symbol_a<>>(name), cast<flock_a<>>(args), cast<flock_a<>>(params), cast<symbol_a<>>(result), def, ref, kind, cast<number_data_a<int64_t>>(order));
	}

	static inline cat_a<> val_()
	{
		static cat_a<> VAL = val("");
		return VAL;
	}

	static inline cat_a<> val_(symbol_a<> const& name, flock_a<> const& args = flock_t<>::val_(), flock_a<> const& params = flock_t<>::val_(), symbol_a<> const& result = any_sym(), bool const def = false, bool const ref = false, bool const kind = false, int64_t const order = 1)
	{
		return cat_a<>{ over{ cat_t<>(name, args, params, result, def, ref, kind, order) } };
	}

	static inline cat_a<> val(std::string const& name, flock_a<> const& args = flock_t<>::val_(), flock_a<> const& params = flock_t<>::val_(), symbol_a<> const& result = any_sym(), bool const def = false, bool const ref = false, bool const kind = false, int64_t const order = 1)
	{
		return val_(sym(name), args, params, result, def, ref, kind, order);
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
	inline any_a<> symbolic__(range_a<> const&) const
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

	inline any_a<> name__(range_a<> const&) const
	{
		return name_();
	}

	inline symbol_a<> name_() const
	{
		return _name;
	}

	inline any_a<> args__(range_a<> const&) const
	{
		return args_();
	}

	inline flock_a<> args_() const
	{
		return _args;
	}

	inline any_a<> params__(range_a<> const&) const
	{
		return params_();
	}

	inline flock_a<> params_() const
	{
		return _params;
	}

	inline any_a<> result__(range_a<> const&) const
	{
		return result_();
	}

	inline cat_a<> result_() const
	{
		return check<cat_a<>>(_result) ? cast<cat_a<>>(_result) : val_();
	}

	inline any_a<> def__(range_a<> const&) const
	{
		return def_();
	}

	inline any_a<> def_() const
	{
		return boole(def());
	}

	inline bool def() const
	{
		return _def;
	}

	inline any_a<> ref__(range_a<> const&) const
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

	inline any_a<> kind__(range_a<> const&) const
	{
		return kind_();
	}

	inline any_a<> kind_() const
	{
		return boole(kind());
	}

	inline bool kind() const
	{
		return _kind;
	}

	inline any_a<> order__(range_a<> const&) const
	{
		return order_();
	}

	inline number_data_a<int64_t> order_() const
	{
		return number_int_64_t<>::val(order());
	}

	inline int64_t order() const
	{
		return _order;
	}

	inline any_a<> code__(range_a<> const&) const
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
	bool const _def;
	bool const _ref;
	bool const _kind;
	int64_t const _order;

	inline cat_t(symbol_a<> const& name, flock_a<> const& args, flock_a<> const& params, symbol_a<> const& result, bool const def, bool const ref, bool const kind, int64_t const order)
		: symbol_t{ _symbol_(name, args, params, result, kind, order) }
		, _symbolic{ _symbolic_(args, params, result) }
		, _name{ name }
		, _args{ args }
		, _params{ params }
		, _result{ _result_(result) }
		, _def{ def }
		, _ref{ ref }
		, _kind{ kind }
		, _order{ order }
	{}

	static inline std::string const _symbol_(symbol_a<> const& name, flock_a<> const& args, flock_a<> const& params, symbol_a<> const& result, bool const kind, int64_t const order)
	{
		std::string symbol;
		for (int64_t o = 0; o < order; ++o)
		{
			symbol += "<";
		}

		symbol += name.to_string();

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
				symbol += kind ? "{" : "[";
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
			symbol += kind ? "}" : "]";
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
				symbol += ":" + str;
			}
		}

		for (int64_t o = 0; o < order; ++o)
		{
			symbol += ">";
		}
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

} // namespace strange

#endif
