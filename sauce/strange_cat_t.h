#ifndef COM_ONEISH_STRANGE_CAT_T_H
#define COM_ONEISH_STRANGE_CAT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = cat_a>
class cat_t : public symbol_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline cat_a val(any_a const& range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline cat_a val_(any_a const& thing = nothing_t<>::val_())
	{
		return cat_a{ cat_t{} };
	}

	static inline cat_a ref(any_a const& range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline cat_a ref_(any_a const& thing = nothing_t<>::val_())
	{
		return cat_a(cat_t{}, true);
	}

	// reflection
	static inline symbol_a type_()
	{
		static symbol_a TYPE = sym__("strange::cat");
		return TYPE;
	}

	// cat
	inline symbol_a name(any_a const& _) const
	{
		return name_();
	}

	inline symbol_a name_() const
	{
		return _name;
	}

	inline any_a arguments(any_a const& _) const
	{
		return arguments_();
	}

	inline any_a arguments_() const
	{
		return _arguments;
	}

	inline any_a parameters(any_a const& _) const
	{
		return parameters_();
	}

	inline any_a parameters_() const
	{
		return _parameters;
	}

	inline cat_a result(any_a const& _) const
	{
		return result_();
	}

	inline cat_a result_() const
	{
		return check_<cat_a>(_result) ? cast_<cat_a>(_result) : val_();
	}

	inline any_a includes(any_a const& range) const
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::cat::includes passed empty range");
		}
		return includes_(*it);
	}

	inline any_a includes_(any_a const& thing) const
	{
		return _boole_(includes__(thing));
	}

	inline bool includes__(any_a const& thing) const
	{
		return false;
	}

	static inline any_a conforms(any_a const& range)
	{
		any_a it = range.cbegin();
		if (it == range.cend())
		{
			throw dis__("strange::cat::conforms passed empty range");
		}
		any_a thing = *it;
		if (++it == range.cend())
		{
			throw dis__("strange::cat::conforms passed short range");
		}
		return conforms_(std::move(thing), *it);
	}

	static inline any_a conforms_(any_a const& thing, any_a const& cat_or_herd)
	{
		return _boole_(conforms__(thing, cat_or_herd));
	}

	static inline bool conforms__(any_a const& thing, any_a const& cat_or_herd)
	{
		if (check_<cat_a>(cat_or_herd))
		{
			return cast_<cat_a>(cat_or_herd).includes_(thing);
		}
		/*
		if (check_<herd_>(cat_or_herd))
		{
			//TODO call includes_ for each cat in the herd
		}
		*/
		return false;
	}

protected:
	symbol_a const _name;
	any_a const _arguments;
	any_a const _parameters;
	any_a const _result;

	inline cat_t()
		: symbol_t{ _symbol_() }
		, _name{ sym__("") }
		, _arguments{ nothing_t<>::val_() }
		, _parameters{ nothing_t<>::val_() }
		, _result{ nothing_t<>::val_() }
	{}

	static inline std::string const _symbol_()
	{
		return "";
	}
};

} // namespace strange

#endif
