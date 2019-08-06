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
		any_a<> order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis("strange::cat::val passed non-int-64 order");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order));
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis("strange::cat::val passed non-symbol name");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name));
		}
		any_a<> dimensions = *it;
		if (!check<flock_a<>>(dimensions))
		{
			throw dis("strange::cat::val passed non-flock dimensions");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions));
		}
		any_a<> parameters = *it;
		if (!check<flock_a<>>(parameters))
		{
			throw dis("strange::cat::val passed non-flock parameters");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<symbol_a<>>(result))
		{
			throw dis("strange::cat::val passed non-symbol result");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(parameters), cast<symbol_a<>>(result));
		}
		any_a<> reference = *it;
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), reference);
		}
		return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), reference, *it);
	}

	static inline cat_a<> val_()
	{
		static cat_a<> VAL = val(1);
		return VAL;
	}

	static inline cat_a<> val_(number_data_a<int64_t> const& order, symbol_a<> const& name = sym(""), flock_a<> const& dimensions = flock_t<>::val_(), flock_a<> const& parameters = flock_t<>::val_(), symbol_a<> const& result = any_sym(), any_a<> const& reference = no(), any_a<> const& optional = no())
	{
		return cat_a<>{ over{ cat_t<>(order.extract(), name, dimensions, flock_t<>::val_(), parameters, result, reference, optional) } };
	}

	static inline cat_a<> val(int64_t order, std::string const& name = "", flock_a<> const& dimensions = flock_t<>::val_(), flock_a<> const& parameters = flock_t<>::val_(), symbol_a<> const& result = any_sym(), bool reference = false, bool optional = false)
	{
		return cat_a<>{ over{ cat_t<>(order, sym(name), dimensions, flock_t<>::val_(), parameters, result, reference, optional) } };
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
		return _dimensions == cat.dimensions_() && _parameters == cat.parameters_() && result_() == cat.result_();
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

	inline any_a<> name__(range_a<> const&) const
	{
		return name_();
	}

	inline symbol_a<> name_() const
	{
		return _name;
	}

	inline any_a<> dimensions__(range_a<> const&) const
	{
		return dimensions_();
	}

	inline flock_a<> dimensions_() const
	{
		return _dimensions;
	}

	inline any_a<> parameters__(range_a<> const&) const
	{
		return parameters_();
	}

	inline flock_a<> parameters_() const
	{
		return _parameters;
	}

	inline any_a<> result__(range_a<> const&) const
	{
		return result_();
	}

	inline cat_a<> result_() const
	{
		return check<cat_a<>>(_result) ? cast<cat_a<>>(_result) : val_();
	}

	inline any_a<> reference__(range_a<> const&) const
	{
		return reference_();
	}

	inline any_a<> reference_() const
	{
		return boole(reference());
	}

	inline bool reference() const
	{
		return _reference;
	}

	inline any_a<> optional__(range_a<> const&) const
	{
		return optional_();
	}

	inline any_a<> optional_() const
	{
		return boole(optional());
	}

	inline bool optional() const
	{
		return _optional;
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
	bool const _symbolic; // recursively true if all of the cats below are symbolic
	int64_t const _order;
	symbol_a<> const _name;
	flock_a<> const _dimensions;
	flock_a<> const _parameters;
	symbol_a<> const _result;
	bool const _reference;
	bool const _optional;

	inline cat_t(int64_t order, symbol_a<> const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool reference, bool optional)
		: symbol_t{ _symbol_(order, name, dimensions, aspects, parameters, result) }
		, _symbolic{ _symbolic_(dimensions, aspects, parameters, result) }
		, _order{ order }
		, _name{ name }
		, _dimensions{ dimensions }
		, _parameters{ parameters }
		, _result{ _result_(result) }
		, _reference{ reference }
		, _optional{ optional }
	{}

	static inline std::string const _symbol_(int64_t order, symbol_a<> const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result)
	{
		std::string symbol;
		for (int64_t o = 0; o < order; ++o)
		{
			symbol += "<";
		}

		symbol += name.to_string();

		bool any = false;
		int64_t anys = 0;
		for (auto const& dimension : dimensions)
		{
			cat_a<> const cat = cast<cat_a<>>(dimension);
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
				symbol += "{";
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
			symbol += "}";
			any = false;
		}

		anys = 0;
		for (auto const& aspect : aspects)
		{
			bool const is_cat = check<cat_a<>>(aspect);
			cat_a<> cat;
			if (is_cat)
			{
				cat = cast<cat_a<>>(aspect);
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
				symbol += "#" + std::to_string(aspect.hash());
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
				symbol += ":" + str;
			}
		}

		for (int64_t o = 0; o < order; ++o)
		{
			symbol += ">";
		}
		return symbol;
	}

	static inline bool _symbolic_(flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result)
	{
		if (check<cat_a<>>(result) && !cast<cat_a<>>(result).symbolic())
		{
			return false;
		}
		for (auto const& dimension : dimensions)
		{
			if (!cast<cat_a<>>(dimension).symbolic())
			{
				return false;
			}
		}
		for (auto const& aspect : aspects)
		{
			if (!check<cat_a<>>(aspect) || !cast<cat_a<>>(aspect).symbolic())
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
