#ifndef COM_ONEISH_STRANGE_KIND_T_H
#define COM_ONEISH_STRANGE_KIND_T_H

namespace strange
{

template <typename ___ego___ = kind_a<>>
class kind_t : public cat_t<___ego___>
{
public:
	// override
	using over = thing_o<kind_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return create_();
		}
		any_a<> order = *it;
		if (!check<number_data_a<int64_t>>(order))
		{
			throw dis("strange::kind::create passed non-int-64 order");
		}
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order));
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis("strange::kind::create passed non-symbol name");
		}
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name));
		}
		any_a<> dimensions = *it;
		if (!check<flock_a<>>(dimensions))
		{
			throw dis("strange::kind::create passed non-flock dimensions");
		}
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions));
		}
		any_a<> aspects = *it;
		if (!check<flock_a<>>(aspects))
		{
			throw dis("strange::kind::create passed non-flock aspects");
		}
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects));
		}
		any_a<> parameters = *it;
		if (!check<flock_a<>>(parameters))
		{
			throw dis("strange::kind::create passed non-flock parameters");
		}
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<symbol_a<>>(result))
		{
			throw dis("strange::kind::create passed non-symbol result");
		}
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result));
		}
		any_a<> fixed = *it;
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), fixed);
		}
		any_a<> reference = *it;
		if (++it == range.cend_())
		{
			return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), fixed, reference);
		}
		return create_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), fixed, reference, *it);
	}

	static inline kind_a<> create_()
	{
		static kind_a<> VAL = kind_t<>::create(1);
		return VAL;
	}

	static inline kind_a<> create_(number_data_a<int64_t> const& order, symbol_a<> const& name = sym(""), flock_a<> const& dimensions = flock_t<>::create_(), flock_a<> const& aspects = flock_t<>::create_(), flock_a<> const& parameters = flock_t<>::create_(), symbol_a<> const& result = any_sym(), any_a<> const& fixed = no(), any_a<> const& reference = no(), any_a<> const& optional = no())
	{
		if (name.is("strange::any"))
		{
			return kind_a<>{ over{ kind_t<>(order.extract_primitive(), sym(""), dimensions, aspects, parameters, result, fixed, reference, optional) } };
		}
		return kind_a<>{ over{ kind_t<>(order.extract_primitive(), name, dimensions, aspects, parameters, result, fixed, reference, optional) } };
	}

	static inline kind_a<> create(int64_t order, std::string const& name = "", flock_a<> const& dimensions = flock_t<>::create_(), flock_a<> const& aspects = flock_t<>::create_(), flock_a<> const& parameters = flock_t<>::create_(), symbol_a<> const& result = any_sym(), bool fixed = false, bool reference = false, bool optional = false)
	{
		if (name == "strange::any")
		{
			return kind_a<>{ over{ kind_t<>(order, sym(""), dimensions, aspects, parameters, result, fixed, reference, optional) } };
		}
		return kind_a<>{ over{ kind_t<>(order, sym(name), dimensions, aspects, parameters, result, fixed, reference, optional) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<kind_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<kind_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<kind_a<>>(thing))
		{
			return cat_t::operator==(thing);
		}
		auto const kind = cast<kind_a<>>(thing);
		if (_symbolic != kind.symbolic() || _hash != kind.hash())
		{
			return false;
		}
		bool const same = kind.to_string() == _string;
		if (_symbolic || !same)
		{
			return same;
		}
		return _dimensions == kind.dimensions_() && _aspects == kind.aspects_() && _parameters == kind.parameters_() && result_() == kind.result_();
	}

	// kind
	inline any_a<> aspects__(range_a<> const&) const
	{
		return aspects_();
	}

	inline flock_a<> aspects_() const
	{
		return _aspects;
	}

	inline any_a<> fixed__(range_a<> const&) const
	{
		return fixed_();
	}

	inline any_a<> fixed_() const
	{
		return boole(fixed());
	}

	inline bool fixed() const
	{
		return _fixed;
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

protected:
	flock_a<> const _aspects;
	bool const _fixed;
	bool const _reference;
	bool const _optional;

	inline kind_t(int64_t order, symbol_a<> const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool fixed, bool reference, bool optional)
		: cat_t{ order, name, dimensions, aspects, parameters, result }
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
	return shoal.something();
}();

// cat conversion
inline kind_a<> kind_from_cat(cat_a<> const& cat, flock_a<> const& aspects = flock_t<>::create_(), any_a<> const& fixed = no(), any_a<> const& reference = no(), any_a<> const& optional = no())
{
	return kind_t<>::create_(cat.order_(), cat.name_(), cat.dimensions_(), aspects, cat.parameters_(), cat.result_(), fixed, reference, optional);
}

inline unordered_herd_a<> kinds_from_cats(unordered_herd_a<> const& cats, flock_a<> const& aspects = flock_t<>::create_(), any_a<> const& fixed = no(), any_a<> const& reference = no(), any_a<> const& optional = no())
{
	auto result = unordered_herd_t<>::create_();
	for (auto const& cat : cats)
	{
		if (!check<cat_a<>>(cat))
		{
			throw dis("strange::kinds_from_cats passed non-cat");
		}
		result.insert(kind_from_cat(cast<cat_a<>>(cat), aspects, fixed, reference, optional));
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
		result.insert(kind_to_cat(cast<kind_a<>>(kind)));
	}
	return result;
}

} // namespace strange

#endif
