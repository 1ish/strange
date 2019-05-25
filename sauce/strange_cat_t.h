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
		return val_(*it);
	}

	static inline cat_a<> val_(any_a<> const& thing = no())
	{
		return cat_a<>{ cat_t{} };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<cat_t<>>::type();
	}

	static inline void share(shoal_a<> const& shoal)
	{
		reflection<cat_t<>>::share(shoal);
	}

	// cat
	inline symbol_a<> name__(range_a<> const& _) const
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

	inline any_a<> arguments_() const
	{
		return _arguments;
	}

	inline any_a<> parameters__(range_a<> const& _) const
	{
		return parameters_();
	}

	inline any_a<> parameters_() const
	{
		return _parameters;
	}

	inline cat_a<> result__(range_a<> const& _) const
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
	symbol_a<> const _name;
	any_a<> const _arguments;
	any_a<> const _parameters;
	any_a<> const _result;

	inline cat_t()
		: symbol_t{ _symbol_() }
		, _name{ sym("") }
		, _arguments{ no() }
		, _parameters{ no() }
		, _result{ no() }
	{}

	static inline std::string const _symbol_()
	{
		return "";
	}
};

} // namespace strange

#endif
