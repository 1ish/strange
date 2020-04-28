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
	static inline any_a<> create__(list_a<> const& list)
	{
		auto it = list.begin_();
		auto end = list.end_();
		if (it == end)
		{
			return create_();
		}
		any_a<> beginning = *it;
		if (!check<forward_extractor_a<_element>>(beginning))
		{
			throw dis(__FILE__, __LINE__, "strange::range::create passed non-extractor begin");
		}
		if (++it == end)
		{
			throw dis(__FILE__, __LINE__, "strange::range::create passed short list");
		}
		any_a<> ending = *it;
		if (!check<forward_extractor_a<_element>>(ending))
		{
			throw dis(__FILE__, __LINE__, "strange::range::create passed non-extractor end");
		}
		return create_(fast<forward_extractor_a<_element>>(beginning), fast<forward_extractor_a<_element>>(ending));
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

	// list
	inline forward_extractor_a<any_a<>> begin_() const
	{
		return _begin.to_extractor_any_();
	}

	inline forward_extractor_a<any_a<>> end_() const
	{
		return _end.to_extractor_any_();
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
