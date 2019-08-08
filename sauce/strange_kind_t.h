#ifndef COM_ONEISH_STRANGE_KIND_T_H
#define COM_ONEISH_STRANGE_KIND_T_H

namespace strange
{

template <typename _ABSTRACTION_ = kind_a<>>
class kind_t : public cat_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<kind_t<>>;

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
			throw dis("strange::kind::val passed non-int-64 order");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order));
		}
		any_a<> name = *it;
		if (!check<symbol_a<>>(name))
		{
			throw dis("strange::kind::val passed non-symbol name");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name));
		}
		any_a<> dimensions = *it;
		if (!check<flock_a<>>(dimensions))
		{
			throw dis("strange::kind::val passed non-flock dimensions");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions));
		}
		any_a<> aspects = *it;
		if (!check<flock_a<>>(aspects))
		{
			throw dis("strange::kind::val passed non-flock aspects");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects));
		}
		any_a<> parameters = *it;
		if (!check<flock_a<>>(parameters))
		{
			throw dis("strange::kind::val passed non-flock parameters");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters));
		}
		any_a<> result = *it;
		if (!check<symbol_a<>>(result))
		{
			throw dis("strange::kind::val passed non-symbol result");
		}
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result));
		}
		any_a<> reference = *it;
		if (++it == range.cend_())
		{
			return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), reference);
		}
		return val_(cast<number_data_a<int64_t>>(order), cast<symbol_a<>>(name), cast<flock_a<>>(dimensions), cast<flock_a<>>(aspects), cast<flock_a<>>(parameters), cast<symbol_a<>>(result), reference, *it);
	}

	static inline kind_a<> val_()
	{
		static kind_a<> VAL = kind_t<>::val(1);
		return VAL;
	}

	static inline kind_a<> val_(number_data_a<int64_t> const& order, symbol_a<> const& name = sym(""), flock_a<> const& dimensions = flock_t<>::val_(), flock_a<> const& aspects = flock_t<>::val_(), flock_a<> const& parameters = flock_t<>::val_(), symbol_a<> const& result = any_sym(), any_a<> const& reference = no(), any_a<> const& optional = no())
	{
		return kind_a<>{ over{ kind_t<>(order.extract(), name, dimensions, aspects, parameters, result, reference, optional) } };
	}

	static inline kind_a<> val(int64_t order, std::string const& name = "", flock_a<> const& dimensions = flock_t<>::val_(), flock_a<> const& aspects = flock_t<>::val_(), flock_a<> const& parameters = flock_t<>::val_(), symbol_a<> const& result = any_sym(), bool reference = false, bool optional = false)
	{
		return kind_a<>{ over{ kind_t<>(order, sym(name), dimensions, aspects, parameters, result, reference, optional) } };
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
			return false;
		}
		auto const kind = cast<kind_a<>>(thing);
		if (_symbolic != kind.symbolic() || _hash != kind.hash())
		{
			return false;
		}
		bool const same = symbol_t<_ABSTRACTION_>::operator==(thing);
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

protected:
	flock_a<> const _aspects;

	inline kind_t(int64_t order, symbol_a<> const& name, flock_a<> const& dimensions, flock_a<> const& aspects, flock_a<> const& parameters, symbol_a<> const& result, bool reference, bool optional)
		: cat_t{ order, name, dimensions, aspects, parameters, result, reference, optional }
		, _aspects{ aspects }
	{}

private:
	static bool const ___share___;
	friend class ___kind_t_share___;
};

template <typename _ABSTRACTION_>
bool const kind_t<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	kind_t<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
