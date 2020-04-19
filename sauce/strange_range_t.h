#ifndef COM_ONEISH_STRANGE_RANGE_T_H
#define COM_ONEISH_STRANGE_RANGE_T_H

namespace strange
{

// template <typename _element = any_a<>, typename ___ego___ = range_a<_element>>
template <typename _element, typename ___ego___>
class range_t : public thing_t<___ego___>
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
		any_a<> begin = *it;
		if (!check<forward_extractor_a<_element>>(begin))
		{
			throw dis("strange::range::create passed non-mutator begin");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::range::create passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_extractor_a<_element>>(end))
		{
			throw dis("strange::range::create passed non-mutator end");
		}
		return create_(fast<forward_extractor_a<_element>>(begin), fast<forward_extractor_a<_element>>(end));
	}

	static inline range_a<_element> create_()
	{
		static auto VAL = range_t<_element>::create_(it_t<_element>::create_(), it_t<_element>::create_());
		return VAL;
	}

	static inline range_a<_element> create_(forward_extractor_a<_element> const& begin, forward_extractor_a<_element> const& end)
	{
		return range_a<_element>::template create<range_t<_element>>(begin, end);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::range" + 
			kind_of<_element>().to_string());
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym(type_().to_string() + "::create"), native_function_create(&range_t<_element>::create__));
	}

	// range
	inline forward_extractor_a<_element> extract_begin_() const
	{
		return _begin;
	}

	inline forward_extractor_a<_element> extract_end_() const
	{
		return _end;
	}

	inline range_a<> to_range_any_() const
	{
		return range_t<>::create_(_begin.to_extractor_any_(), _end.to_extractor_any_());
	}

protected:
	forward_extractor_a<_element> _begin;
	forward_extractor_a<_element> _end;

	friend class any_a<>;

	inline range_t(forward_extractor_a<_element> const& begin, forward_extractor_a<_element> const& end)
		: thing_t<___ego___>{}
		, _begin(begin)
		, _end(end)
	{}

private:
	static bool const ___share___;
	friend class ___range_t_share___;
};

template <typename _element, typename ___ego___>
bool const range_t<_element, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	range_t<_element, ___ego___>::share(shoal);
	return shoal;
}();

class ___range_t_share___
{
	static inline bool ___share___()
	{
		return range_t<>::___share___;
	}
};

// template <typename _element = any_a<>>
template <typename _element>
inline range_a<_element> range_create()
{
	return range_t<_element>::create_();
}

// template <typename _element = any_a<>>
template <typename _element>
inline range_a<_element> range_create(forward_extractor_a<_element> const& begin, forward_extractor_a<_element> const& end)
{
	return range_t<_element>::create_(begin, end);
}

} // namespace strange

#endif
