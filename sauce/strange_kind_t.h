#ifndef COM_ONEISH_STRANGE_KIND_T_H
#define COM_ONEISH_STRANGE_KIND_T_H

namespace strange
{

// template <typename ___ego___ = kind_a<>>
template <typename ___ego___>
class kind_t : public cat_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			return create_();
		}
		any_a<> order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis("strange::kind::create passed non-int-64 order");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order));
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis("strange::kind::create passed non-symbol name");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name));
		}
		any_a<> dimensions = *it;
		if (!check<flock_a<>>(dimensions))
		{
			throw dis("strange::kind::create passed non-flock dimensions");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions));
		}
		any_a<> aspects = *it;
		if (!check<flock_a<>>(aspects))
		{
			throw dis("strange::kind::create passed non-flock aspects");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(aspects));
		}
		any_a<> parameters = *it;
		if (!check<flock_a<>>(parameters))
		{
			throw dis("strange::kind::create passed non-flock parameters");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(aspects), fast<flock_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<symbol_a<>>(result))
		{
			throw dis("strange::kind::create passed non-symbol result");
		}
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(aspects), fast<flock_a<>>(parameters), fast<symbol_a<>>(result));
		}
		any_a<> fixed = *it;
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(aspects), fast<flock_a<>>(parameters), fast<symbol_a<>>(result), fixed);
		}
		any_a<> reference = *it;
		if (++it == range.extract_end_())
		{
			return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(aspects), fast<flock_a<>>(parameters), fast<symbol_a<>>(result), fixed, reference);
		}
		return create_(fast<number_data_a<int64_t>>(order), fast<symbol_a<>>(name), fast<flock_a<>>(dimensions), fast<flock_a<>>(aspects), fast<flock_a<>>(parameters), fast<symbol_a<>>(result), fixed, reference, *it);
	}

	static inline kind_a<> create_()
	{
		static kind_a<> VAL = kind_t<>::create(1);
		return VAL;
	}

	static inline kind_a<> create_(number_data_a<int64_t> const& order, symbol_a<> const& name = sym(""), flock_a<> const& dimensions = flock_create(), flock_a<> const& aspects = flock_create(), flock_a<> const& parameters = flock_create(), symbol_a<> const& result = cat_t<___ego___>::any_sym(), any_a<> const& fixed = no(), any_a<> const& reference = no(), any_a<> const& optional = no())
	{
		if (name.is("strange::any"))
		{
			return kind_a<>::create<kind_t<>>(order.extract_primitive(), sym(""), dimensions, aspects, parameters, result, fixed, reference, optional);
		}
		return kind_a<>::create<kind_t<>>(order.extract_primitive(), name, dimensions, aspects, parameters, result, fixed, reference, optional);
	}

	static inline kind_a<> create(int64_t order, std_string const& name = "", flock_a<> const& dimensions = flock_create(), flock_a<> const& aspects = flock_create(), flock_a<> const& parameters = flock_create(), symbol_a<> const& result = cat_t<___ego___>::any_sym(), bool fixed = false, bool reference = false, bool optional = false)
	{
		if (name == "strange::any")
		{
			return kind_a<>::create<kind_t<>>(order, sym(""), dimensions, aspects, parameters, result, fixed, reference, optional);
		}
		return kind_a<>::create<kind_t<>>(order, sym(name), dimensions, aspects, parameters, result, fixed, reference, optional);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::kind");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::kind::create"), native_function_create(&kind_t<>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		if (!check<kind_a<>>(thing))
		{
			return cat_t<___ego___>::same_(thing);
		}
		auto const kind = fast<kind_a<>>(thing);
		if (cat_t<___ego___>::_symbolic != kind.symbolic() || cat_t<___ego___>::_hash != kind.hash())
		{
			return false;
		}
		bool const same = kind.to_string() == cat_t<___ego___>::_string;
		if (cat_t<___ego___>::_symbolic || !same)
		{
			return same;
		}
		return cat_t<___ego___>::_dimensions == kind.dimensions_() && _aspects == kind.aspects_() && cat_t<___ego___>::_parameters == kind.parameters_() && cat_t<___ego___>::result_() == kind.result_();
	}

	// cat
	inline std_string code() const
	{
		std_string code = cat_t<___ego___>::_name.to_string();
		if (code.empty())
		{
			code = "strange::any";
		}

		code += "_a<";
		bool any = false;
		for (auto const& aspect : _aspects)
		{
			if (any)
			{
				code += ", ";
			}
			else
			{
				any = true;
			}
			if (check<cat_a<>>(aspect))
			{
				code += fast<cat_a<>>(aspect).code();
			}
			else
			{
				code += "#" + std::to_string(aspect.hash()); //TODO
			}
		}
		code += ">";
		return code;
	}

	// kind
	inline flock_a<> aspects_() const
	{
		return _aspects;
	}

	inline any_a<> fixed_() const
	{
		return boole(fixed());
	}

	inline bool fixed() const
	{
		return _fixed;
	}

	inline any_a<> reference_() const
	{
		return boole(reference());
	}

	inline bool reference() const
	{
		return _reference;
	}

	inline any_a<> optional_() const
	{
		return boole(optional());
	}

	inline bool optional() const
	{
		return _optional;
	}

protected:
	flock_a<> const _aspects;
	bool const _fixed;
	bool const _reference;
	bool const _optional;

	friend class any_a<>;

	inline kind_t(int64_t order, symbol_a<> const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool fixed, bool reference, bool optional)
		: cat_t<___ego___>{ order, name, dimensions, aspects, parameters, result }
		, _aspects{ aspects }
		, _fixed{ fixed }
		, _reference{ reference }
		, _optional{ optional }
	{}

private:
	static bool const ___share___;
	friend class ___kind_t_share___;
};

template <typename ___ego___>
bool const kind_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	kind_t<___ego___>::share(shoal);
	return shoal;
}();

class ___kind_t_share___
{
	static inline bool ___share___()
	{
		return kind_t<>::___share___;
	}
};

//inline kind_a<> kind_create(int64_t order = 1, std_string const& name = "");
template <typename ___kind_a___>
inline ___kind_a___ kind_create(int64_t order, std_string const& name)
{
	return kind_t<>::create(order, name);
}

template <typename ___kind_a___>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions)
{
	return kind_t<>::create(order, name, dimensions);
}

template <typename ___kind_a___>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& aspects)
{
	return kind_t<>::create(order, name, dimensions, aspects);
}

template <typename ___kind_a___>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters)
{
	return kind_t<>::create(order, name, dimensions, aspects, parameters);
}

//inline kind_a<> kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool fixed = false, bool reference = false, bool optional = false);
template <typename ___kind_a___>
inline ___kind_a___ kind_create(int64_t order, std_string const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool fixed, bool reference, bool optional)
{
	return kind_t<>::create(order, name, dimensions, aspects, parameters, result, fixed, reference, optional);
}

// cat conversion
inline kind_a<> kind_from_cat(cat_a<> const& cat)
{
	return kind_t<>::create_(cat.order_(), cat.name_(), cat.dimensions_(), flock_t<>::create_(), cat.parameters_(), cat.result_(), no(), no(), no());
}

inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects)
{
	return kind_t<>::create_(cat.order_(), cat.name_(), cat.dimensions_(), aspects, cat.parameters_(), cat.result_(), no(), no(), no());
}

inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional)
{
	return kind_t<>::create_(cat.order_(), cat.name_(), cat.dimensions_(), aspects, cat.parameters_(), cat.result_(), fixed, reference, optional);
}

inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats)
{
	auto result = unordered_herd_t<>::create_();
	for (auto const& cat : cats)
	{
		if (!check<cat_a<>>(cat))
		{
			throw dis("strange::kinds_from_cats passed non-cat");
		}
		result.insert_thing(kind_from_cat(fast<cat_a<>>(cat)));
	}
	return result;
}

inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects, any_a<> const& fixed, any_a<> const& reference, any_a<> const& optional)
{
	auto result = unordered_herd_t<>::create_();
	for (auto const& cat : cats)
	{
		if (!check<cat_a<>>(cat))
		{
			throw dis("strange::kinds_from_cats passed non-cat");
		}
		result.insert_thing(kind_from_cat(fast<cat_a<>>(cat), aspects, fixed, reference, optional));
	}
	return result;
}

inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects)
{
	auto result = unordered_herd_t<>::create_();
	for (auto const& cat : cats)
	{
		if (!check<cat_a<>>(cat))
		{
			throw dis("strange::kinds_from_cats passed non-cat");
		}
		result.insert_thing(kind_from_cat(fast<cat_a<>>(cat), aspects));
	}
	return result;
}

inline cat_a<> kind_to_cat(kind_a<> const& kind)
{
	return cat_t<>::create_(kind.order_(), kind.name_(), kind.dimensions_(), kind.parameters_(), kind.result_());
}

inline unordered_herd_a<> kinds_to_cats(unordered_herd_a<> const& kinds)
{
	auto result = unordered_herd_t<>::create_();
	for (auto const& kind : kinds)
	{
		if (!check<kind_a<>>(kind))
		{
			throw dis("strange::kinds_to_cats passed non-kind");
		}
		result.insert_thing(kind_to_cat(fast<kind_a<>>(kind)));
	}
	return result;
}

template <typename ___TTT___>
inline kind_a<> kind_of()
{
	return ___TTT___::___kind___();
}

template <>
inline kind_a<> kind_of<int8_t>()
{
	return kind_create(1, "\"int8_t\"");
}

template <>
inline kind_a<> kind_of<uint8_t>()
{
	return kind_create(1, "\"uint8_t\"");
}

template <>
inline kind_a<> kind_of<int16_t>()
{
	return kind_create(1, "\"int16_t\"");
}

template <>
inline kind_a<> kind_of<uint16_t>()
{
	return kind_create(1, "\"uint16_t\"");
}

template <>
inline kind_a<> kind_of<int32_t>()
{
	return kind_create(1, "\"int32_t\"");
}

template <>
inline kind_a<> kind_of<uint32_t>()
{
	return kind_create(1, "\"uint32_t\"");
}

template <>
inline kind_a<> kind_of<int64_t>()
{
	return kind_create(1, "\"int64_t\"");
}

template <>
inline kind_a<> kind_of<uint64_t>()
{
	return kind_create(1, "\"uint64_t\"");
}

template <>
inline kind_a<> kind_of<float>()
{
	return kind_create(1, "\"float\"");
}

template <>
inline kind_a<> kind_of<double>()
{
	return kind_create(1, "\"double\"");
}

template <>
inline kind_a<> kind_of<std::shared_ptr<strange::concurrent_u<false>::read_lock>>()
{
	return kind_create(1, "\"std::shared_ptr<strange::concurrent_u<false>::read_lock>\"");
}

template <>
inline kind_a<> kind_of<std::shared_ptr<strange::concurrent_u<false>::write_lock>>()
{
	return kind_create(1, "\"std::shared_ptr<strange::concurrent_u<false>::write_lock>\"");
}

template <>
inline kind_a<> kind_of<std::shared_ptr<strange::concurrent_u<true>::read_lock>>()
{
	return kind_create(1, "\"std::shared_ptr<strange::concurrent_u<true>::read_lock>\"");
}

template <>
inline kind_a<> kind_of<std::shared_ptr<strange::concurrent_u<true>::write_lock>>()
{
	return kind_create(1, "\"std::shared_ptr<strange::concurrent_u<true>::write_lock>\"");
}

template <>
inline kind_a<> kind_of<std::istreambuf_iterator<char>>()
{
	return kind_create(1, "\"std::istreambuf_iterator<char>\"");
}

template <>
inline kind_a<> kind_of<std_vector<int8_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<int8_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int8_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<int8_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint8_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<uint8_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint8_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<uint8_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<int16_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<int16_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int16_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<int16_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint16_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<uint16_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint16_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<uint16_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<int32_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<int32_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int32_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<int32_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint32_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<uint32_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint32_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<uint32_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<int64_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<int64_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int64_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<int64_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint64_t>::const_iterator>()
{
	return kind_create(1, "\"std_vector<uint64_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint64_t>::const_iterator>()
{
	return kind_create(1, "\"std_deque<uint64_t>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<float>::const_iterator>()
{
	return kind_create(1, "\"std_vector<float>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<float>::const_iterator>()
{
	return kind_create(1, "\"std_deque<float>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<double>::const_iterator>()
{
	return kind_create(1, "\"std_vector<double>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<double>::const_iterator>()
{
	return kind_create(1, "\"std_deque<double>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<int8_t>::iterator>()
{
	return kind_create(1, "\"std_vector<int8_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int8_t>::iterator>()
{
	return kind_create(1, "\"std_deque<int8_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint8_t>::iterator>()
{
	return kind_create(1, "\"std_vector<uint8_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint8_t>::iterator>()
{
	return kind_create(1, "\"std_deque<uint8_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<int16_t>::iterator>()
{
	return kind_create(1, "\"std_vector<int16_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int16_t>::iterator>()
{
	return kind_create(1, "\"std_deque<int16_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint16_t>::iterator>()
{
	return kind_create(1, "\"std_vector<uint16_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint16_t>::iterator>()
{
	return kind_create(1, "\"std_deque<uint16_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<int32_t>::iterator>()
{
	return kind_create(1, "\"std_vector<int32_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int32_t>::iterator>()
{
	return kind_create(1, "\"std_deque<int32_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint32_t>::iterator>()
{
	return kind_create(1, "\"std_vector<uint32_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint32_t>::iterator>()
{
	return kind_create(1, "\"std_deque<uint32_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<int64_t>::iterator>()
{
	return kind_create(1, "\"std_vector<int64_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<int64_t>::iterator>()
{
	return kind_create(1, "\"std_deque<int64_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<uint64_t>::iterator>()
{
	return kind_create(1, "\"std_vector<uint64_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<uint64_t>::iterator>()
{
	return kind_create(1, "\"std_deque<uint64_t>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<float>::iterator>()
{
	return kind_create(1, "\"std_vector<float>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<float>::iterator>()
{
	return kind_create(1, "\"std_deque<float>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<double>::iterator>()
{
	return kind_create(1, "\"std_vector<double>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<double>::iterator>()
{
	return kind_create(1, "\"std_deque<double>::iterator\"");
}

template <>
inline kind_a<> kind_of<dart_packet::iterator>()
{
	return kind_create(1, "\"dart_packet::iterator\"");
}

template <>
inline kind_a<> kind_of<std_set<any_a<>>::const_iterator>()
{
	return kind_create(1, "\"std_set<any_a<>>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std::map<any_a<>, any_a<>>::const_iterator>()
{
	return kind_create(1, "\"std::map<any_a<>, any_a<>>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std::map<any_a<>, any_a<>>::iterator>()
{
	return kind_create(1, "\"std::map<any_a<>, any_a<>>::iterator\"");
}

template <>
inline kind_a<> kind_of<std::unordered_set<any_a<>>::const_iterator>()
{
	return kind_create(1, "\"std::unordered_set<any_a<>>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std::unordered_map<any_a<>, any_a<>>::const_iterator>()
{
	return kind_create(1, "\"std::unordered_map<any_a<>, any_a<>>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std::unordered_map<any_a<>, any_a<>>::iterator>()
{
	return kind_create(1, "\"std::unordered_map<any_a<>, any_a<>>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<any_a<>>::const_iterator>()
{
	return kind_create(1, "\"std_vector<any_a<>>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<any_a<>>::const_iterator>()
{
	return kind_create(1, "\"<std_deque<any_a<>>::const_iterator\"");
}

template <>
inline kind_a<> kind_of<std_vector<any_a<>>::iterator>()
{
	return kind_create(1, "\"std_vector<any_a<>>::iterator\"");
}

template <>
inline kind_a<> kind_of<std_deque<any_a<>>::iterator>()
{
	return kind_create(1, "\"std_deque<any_a<>>::iterator\"");
}

} // namespace strange

#endif
