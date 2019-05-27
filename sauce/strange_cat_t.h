#ifndef COM_ONEISH_STRANGE_CAT_T_H
#define COM_ONEISH_STRANGE_CAT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = cat_a<>>
class cat_t : public symbol_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
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
		any_a<> arguments = *it;
		if (!check<flock_a<>>(arguments))
		{
			throw dis("strange::cat::val passed non-flock arguments");
		}
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(arguments));
		}
		any_a<> parameters = *it;
		if (!check<flock_a<>>(parameters))
		{
			throw dis("strange::cat::val passed non-flock parameters");
		}
		if (++it == range.cend_())
		{
			return val_(cast<symbol_a<>>(name), cast<flock_a<>>(arguments), cast<flock_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<symbol_a<>>(result))
		{
			throw dis("strange::cat::val passed non-symbol result");
		}
		return val_(cast<symbol_a<>>(name), cast<flock_a<>>(arguments), cast<flock_a<>>(parameters), cast<symbol_a<>>(result));
	}

	static inline cat_a<> val_()
	{
		static cat_a<> ANY = val("");
		return ANY;
	}

	static inline cat_a<> val_(symbol_a<> const& name, flock_a<> const& arguments = flock_t<>::val_(), flock_a<> const& parameters = flock_t<>::val_(), symbol_a<> const& result = sym(""))
	{
		return cat_a<>{ cat_t(name, arguments, parameters, result) };
	}

	static inline cat_a<> val(std::string const& name, flock_a<> const& arguments = flock_t<>::val_(), flock_a<> const& parameters = flock_t<>::val_(), symbol_a<> const& result = sym(""))
	{
		return val_(sym(name), arguments, parameters, result);
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
		return _arguments == cat.arguments_() && _parameters == cat.parameters_() && result_() == cat.result_();
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

	inline any_a<> arguments__(range_a<> const& _) const
	{
		return arguments_();
	}

	inline flock_a<> arguments_() const
	{
		return _arguments;
	}

	inline any_a<> parameters__(range_a<> const& _) const
	{
		return parameters_();
	}

	inline flock_a<> parameters_() const
	{
		return _parameters;
	}

	inline any_a<> result__(range_a<> const& _) const
	{
		return result_();
	}

	inline cat_a<> result_() const
	{
		return check<cat_a<>>(_result) ? cast<cat_a<>>(_result) : val_();
	}

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

protected:
	bool const _symbolic; // recursively true if all of the cats below are symbolic and there are no non-cat arguments
	symbol_a<> const _name;
	flock_a<> const _arguments;
	flock_a<> const _parameters;
	symbol_a<> const _result;

	inline cat_t(symbol_a<> const& name, flock_a<> const& arguments, flock_a<> const& parameters, symbol_a<> const& result)
		: symbol_t{ _symbol_(name, arguments, parameters, result) }
		, _symbolic{ _symbolic_(arguments, parameters, result) }
		, _name{ name }
		, _arguments{ arguments }
		, _parameters{ parameters }
		, _result{ _result_(result) }
	{}

	static inline std::string const _symbol_(symbol_a<> const& name, flock_a<> const& arguments, flock_a<> const& parameters, symbol_a<> const& result)
	{
		std::string symbol = "<" + name.to_string();

		bool any = false;
		int64_t anys = 0;
		for (auto const& argument : arguments)
		{
			bool const is_cat = check<cat_a<>>(argument);
			cat_a<> cat;
			if (is_cat)
			{
				cat = cast<cat_a<>>(argument);
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
				symbol += "#" + std::to_string(argument.hash());
			}
		}
		if (any)
		{
			symbol += "]";
			any = false;
		}

		anys = 0;
		for (auto const& parameter : parameters)
		{
			cat_a<> const cat = cast<cat_a<>>(parameter);
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

	static inline bool _symbolic_(flock_a<> const& arguments, flock_a<> const& parameters, symbol_a<> const& result)
	{
		if (check<cat_a<>>(result) && !cast<cat_a<>>(result).symbolic())
		{
			return false;
		}
		for (auto const& argument : arguments)
		{
			if (!check<cat_a<>>(argument) || !cast<cat_a<>>(argument).symbolic())
			{
				return false;
			}
		}
		for (auto const& parameter : parameters)
		{
			if (!cast<cat_a<>>(parameter).symbolic())
			{
				return false;
			}
		}
		return true;
	}

	static inline symbol_a<> _result_(symbol_a<> const& result)
	{
		return (check<cat_a<>>(result) && result.to_string() != "<>") ? result : sym("<>");
	}
};

} // namespace strange

#endif
