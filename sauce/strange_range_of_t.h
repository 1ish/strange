#ifndef COM_ONEISH_STRANGE_RANGE_OF_T_H
#define COM_ONEISH_STRANGE_RANGE_OF_T_H

namespace strange
{

template <typename _element_ = any_a<>, typename ___ego___ = range_of_a<_element_>>
class range_of_t : public thing_t<___ego___>
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
		if (!check<forward_extractor_a<_element_>>(begin))
		{
			throw dis("strange::range_of::create passed non-mutator begin");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::range_of::create passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_extractor_a<_element_>>(end))
		{
			throw dis("strange::range_of::create passed non-mutator end");
		}
		return create_(fast<forward_extractor_a<_element_>>(begin), fast<forward_extractor_a<_element_>>(end));
	}

	static inline range_of_a<_element_> create_()
	{
		static range_of_a<_element_> VAL = range_of_t<_element_>::create_(it_t<>::create_(), it_t<>::create_());
		return VAL;
	}

	static inline range_of_a<_element_> create_(forward_extractor_a<_element_> const& begin, forward_extractor_a<_element_> const& end)
	{
		return range_of_a<_element_>::template create<range_of_t<_element_>>(begin, end);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::range_of" + kind_of<_element_>().to_string());
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string(type_().to_string() + "::create", native_function_create(&range_of_t<_element_>::create__));
	}

	// range
	inline forward_extractor_a<_element_> extract_begin_() const
	{
		return _begin;
	}

	inline forward_extractor_a<_element_> extract_end_() const
	{
		return _end;
	}

protected:
	forward_extractor_a<_element_> _begin;
	forward_extractor_a<_element_> _end;

	friend class any_a<>;

	inline range_of_t(forward_extractor_a<_element_> const& begin, forward_extractor_a<_element_> const& end)
		: thing_t<___ego___>{}
		, _begin(begin)
		, _end(end)
	{}

private:
	static bool const ___share___;
	friend class ___range_of_t_share___;
};

template <typename _element_, typename ___ego___>
bool const range_of_t<_element_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	range_of_t<_element_, ___ego___>::share(shoal);
	return shoal;
}();

class ___range_of_t_share___
{
	static inline bool ___share___()
	{
		return range_of_t<>::___share___;
	}
};

} // namespace strange

#endif
