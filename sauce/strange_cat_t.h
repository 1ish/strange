#ifndef COM_ONEISH_STRANGE_CAT_T_H
#define COM_ONEISH_STRANGE_CAT_T_H

namespace strange
{

template <typename ___ego___ = cat_a<>>
class cat_t : public symbol_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			return create_();
		}
		any_a<> order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis("strange::cat::create passed non-int-64 order");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order));
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis("strange::cat::create passed non-symbol name");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name));
		}
		any_a<> dimensions = *it;
		if (!check<flock_a<>>(dimensions))
		{
			throw dis("strange::cat::create passed non-flock dimensions");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions));
		}
		any_a<> parameters = *it;
		if (!check<flock_a<>>(parameters))
		{
			throw dis("strange::cat::create passed non-flock parameters");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<symbol_a<>>(result))
		{
			throw dis("strange::cat::create passed non-symbol result");
		}
		return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(parameters), fast<symbol_a<>>(result));
	}

	static inline cat_a<> create_()
	{
		static cat_a<> VAL = cat_t<>::create(1);
		return VAL;
	}

	static inline cat_a<> create_(number_data_a<int64_t> const& order, symbol_a<> const& name = sym(""), flock_a<> const& dimensions = flock_t<>::create_(), flock_a<> const& parameters = flock_t<>::create_(), symbol_a<> const& result = any_sym())
	{
		if (name.is("strange::any"))
		{
			return cat_a<>::create<cat_t<>>(order.extract_primitive(), sym(""), dimensions, flock_t<>::create_(), parameters, result);
		}
		return cat_a<>::create<cat_t<>>(order.extract_primitive(), name, dimensions, flock_t<>::create_(), parameters, result);
	}

	static inline cat_a<> create(int64_t order, std::string const& name = "", flock_a<> const& dimensions = flock_t<>::create_(), flock_a<> const& parameters = flock_t<>::create_(), symbol_a<> const& result = any_sym())
	{
		if (name == "strange::any")
		{
			return cat_a<>::create<cat_t<>>(order, sym(""), dimensions, flock_t<>::create_(), parameters, result);
		}
		return cat_a<>::create<cat_t<>>(order, sym(name), dimensions, flock_t<>::create_(), parameters, result);
	}

	static inline symbol_a<> any_sym()
	{
		static symbol_a<> ANY = sym("<>");
		return ANY;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::cat");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::cat::create", native_function_create(&cat_t<>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<cat_a<>>(thing))
		{
			return symbol_t<___ego___>::same_(thing);
		}
		auto const cat = fast<cat_a<>>(thing);
		if (_symbolic != cat.symbolic() || symbol_t<___ego___>::_hash != cat.hash())
		{
			return false;
		}
		bool const same = cat.to_string() == symbol_t<___ego___>::_string;
		if (_symbolic || !same)
		{
			return same;
		}
		return _dimensions == cat.dimensions_() && _parameters == cat.parameters_() && result_() == cat.result_();
	}

	// cat
	inline any_a<> symbolic_() const
	{
		return boole(symbolic());
	}

	inline bool symbolic() const
	{
		return _symbolic;
	}

	inline number_data_a<int64_t> order_() const
	{
		return number_int_64_t<>::create(order());
	}

	inline int64_t order() const
	{
		return _order;
	}

	inline symbol_a<> name_() const
	{
		return _name;
	}

	inline std::string name() const
	{
		return _name.to_string();
	}

	inline flock_a<> dimensions_() const
	{
		return _dimensions;
	}

	inline flock_a<> parameters_() const
	{
		return _parameters;
	}

	inline cat_a<> result_() const
	{
		return check<cat_a<>>(_result) ? fast<cat_a<>>(_result) : create_();
	}

	inline lake_a<int8_t> code_() const
	{
		return lake_from_string(code());
	}

	inline std::string code() const
	{
		auto const name = _name.to_string();
		return (name.empty() ? std::string("strange::any") : name) + "_a<>"; //TODO
	}

protected:
	bool const _symbolic; // recursively true if all of the cats below are symbolic
	int64_t const _order;
	symbol_a<> const _name;
	flock_a<> const _dimensions;
	flock_a<> const _parameters;
	symbol_a<> const _result;

	friend class any_a<>;

	inline cat_t(int64_t order, symbol_a<> const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result)
		: symbol_t<___ego___>{ _symbol_(order, name, dimensions, aspects, parameters, result) }
		, _symbolic{ _symbolic_(dimensions, aspects, parameters, result) }
		, _order{ order }
		, _name{ name }
		, _dimensions{ dimensions }
		, _parameters{ parameters }
		, _result{ _result_(result) }
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
			cat_a<> const cat = fast<cat_a<>>(dimension);
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
				cat = fast<cat_a<>>(aspect);
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
			cat_a<> const cat = fast<cat_a<>>(parameter);
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
			std::string const str = result.to_string();
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
		if (check<cat_a<>>(result) && !fast<cat_a<>>(result).symbolic())
		{
			return false;
		}
		for (auto const& dimension : dimensions)
		{
			if (!fast<cat_a<>>(dimension).symbolic())
			{
				return false;
			}
		}
		for (auto const& aspect : aspects)
		{
			if (!check<cat_a<>>(aspect) || !fast<cat_a<>>(aspect).symbolic())
			{
				return false;
			}
		}
		for (auto const& parameter : parameters)
		{
			if (!fast<cat_a<>>(parameter).symbolic())
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

template <typename ___ego___>
bool const cat_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	cat_t<___ego___>::share(shoal);
	return shoal;
}();

class ___cat_t_share___
{
	static inline bool ___share___()
	{
		return cat_t<>::___share___;
	}
};

template <typename ___cat_a___>
inline ___cat_a___ cat_create(int64_t order, std::string const& name)
{
	return cat_t<>::create(order, name);
}

template <typename ___cat_a___>
inline ___cat_a___ cat_create(int64_t order, std::string const& name, flock_a<> const& dimensions)
{
	return cat_t<>::create(order, name, dimensions);
}

template <typename ___cat_a___>
inline ___cat_a___ cat_create(int64_t order, std::string const& name, flock_a<> const& dimensions, flock_a<> const& parameters, symbol_a<> const& result)
{
	return cat_t<>::create(order, name, dimensions, parameters, result);
}

} // namespace strange

#endif
