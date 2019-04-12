#ifndef COM_ONEISH_STRANGE_CAT_H
#define COM_ONEISH_STRANGE_CAT_H

namespace strange
{

template <typename CAT = cat_>
class Cat : public Symbol<CAT>
{
public: ___THING___
	// construction
	static inline cat_ val(thing_ range)
	{
		thing_ it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline cat_ val_(thing_ thing = Nothing<>::val_())
	{
		return cat_{ Cat{} };
	}

	static inline cat_ ref(thing_ range)
	{
		thing_ it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline cat_ ref_(thing_ thing = Nothing<>::val_())
	{
		return cat_(Cat{}, true);
	}

	// cat
	static inline thing_ conform(thing_ range)
	{
		thing_ it = range.cbegin();
		assert(it != range.cend()); //TODO
		thing_ thing = *it;
		assert(++it != range.cend()); //TODO
		thing_ cat_or_herd = *it;
		return conform_(thing, cat_or_herd);
	}

	static inline thing_ conform_(thing_ thing, thing_ cat_or_herd)
	{
		return _boole_(conform__(thing, cat_or_herd));
	}

	static inline bool conform__(thing_ thing, thing_ cat_or_herd)
	{
		return false;
	}

	inline thing_ name(thing_ _) const
	{
		return name_();
	}

	inline symbol_ name_() const
	{
		return _name;
	}

	inline thing_ arguments(thing_ _) const
	{
		return arguments_();
	}

	inline thing_ arguments_() const
	{
		return _arguments;
	}

	inline thing_ parameters(thing_ _) const
	{
		return parameters_();
	}

	inline thing_ parameters_() const
	{
		return _parameters;
	}

	inline thing_ result(thing_ _) const
	{
		return result_();
	}

	inline cat_ result_() const
	{
		return check_<cat_>(_result) ? cast_<cat_>(_result) : val_();
	}

protected:
	const symbol_ _name;
	const thing_ _arguments;
	const thing_ _parameters;
	const thing_ _result;

	inline Cat()
		: Symbol{ _symbol_() }
		, _name{ sym__("") }
		, _arguments{ Nothing<>::val_() }
		, _parameters{ Nothing<>::val_() }
		, _result{ Nothing<>::val_() }
	{}

	static inline const std::string _symbol_()
	{
		return "";
	}
};

} // namespace strange

#endif
