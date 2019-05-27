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
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis("strange::cat::val passed non-symbol name");
		}
		return val_(cast<symbol_a<>>(name));
	}

	static inline cat_a<> val_(symbol_a<> const& name = sym(""))
	{
		return cat_a<>{ cat_t(name, flock_t<>::val_(), flock_t<>::val_(), no()) };
	}

	static inline cat_a<> val(std::string const& name)
	{
		return cat_a<>{ cat_t(sym(name), flock_t<>::val_(), flock_t<>::val_(), no()) };
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
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
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
		return false;
	}

	static inline any_a<> conforms__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			throw dis("strange::cat::conforms passed empty range");
		}
		any_a<> thing = *it;
		if (++it == range.cend())
		{
			throw dis("strange::cat::conforms passed short range");
		}
		return conforms_(thing, *it);
	}

	static inline any_a<> conforms_(any_a<> const& thing, any_a<> const& cat_or_unordered_herd)
	{
		return boole(conforms(thing, cat_or_unordered_herd));
	}

	static inline bool conforms(any_a<> const& thing, any_a<> const& cat_or_unordered_herd)
	{
		if (check<cat_a<>>(cat_or_unordered_herd))
		{
			return cast<cat_a<>>(cat_or_unordered_herd).includes_(thing);
		}
		/*
		if (check<unordered_herd_>(cat_or_unordered_herd))
		{
			//TODO call includes_ for each cat in the unordered_herd
		}
		*/
		return false;
	}

protected:
	bool const _symbolic; // recursively true if all of the cats below are symbolic and there are no non-cat arguments
	symbol_a<> const _name;
	flock_a<> const _arguments;
	flock_a<> const _parameters;
	any_a<> const _result;

	inline cat_t(symbol_a<> const& name, flock_a<> const& arguments, flock_a<> const& parameters, any_a<> const& result)
		: symbol_t{ _symbol_(name, arguments, parameters, result) }
		, _symbolic{ _symbolic_(arguments, parameters, result) }
		, _name{ name }
		, _arguments{ arguments }
		, _parameters{ parameters }
		, _result{ result }
	{}

	static inline std::string const _symbol_(symbol_a<> const& name, flock_a<> const& arguments, flock_a<> const& parameters, any_a<> const& result)
	{
		std::string symbol = "<" + name.to_string();

		bool any = false;
		int64_t anys = 0;
		for (auto const& argument : cast<range_a<>>(arguments)) //TODO no cast
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
				symbol += "*";
			}
		}
		if (any)
		{
			symbol += "]";
			any = false;
		}

		anys = 0;
		for (auto const& parameter : cast<range_a<>>(parameters)) //TODO no cast
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
			std::string const str = cast<cat_a<>>(result).to_string();
			if (str != "<>")
			{
				symbol += str;
			}
		}

		symbol += ">";
		return symbol;
	}

	static inline bool _symbolic_(flock_a<> const& arguments, flock_a<> const& parameters, any_a<> const& result)
	{
		if (check<cat_a<>>(result) && !cast<cat_a<>>(result).symbolic())
		{
			return false;
		}
		for (auto const& argument : cast<range_a<>>(arguments)) //TODO no cast
		{
			if (!check<cat_a<>>(argument) || !cast<cat_a<>>(argument).symbolic())
			{
				return false;
			}
		}
		for (auto const& parameter : cast<range_a<>>(parameters)) //TODO no cast
		{
			if (!cast<cat_a<>>(parameter).symbolic())
			{
				return false;
			}
		}
		return true;
	}
};

} // namespace strange

#endif
