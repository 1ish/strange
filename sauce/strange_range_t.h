#ifndef COM_ONEISH_STRANGE_RANGE_T_H
#define COM_ONEISH_STRANGE_RANGE_T_H

namespace strange
{

// template <typename ___ego___ = range_a<>>
template <typename ___ego___>
class range_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<range_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_extractor_a<> it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			return create_();
		}
		any_a<> begin = *it;
		if (!check<forward_extractor_a<>>(begin))
		{
			throw dis("strange::range::create passed non-mutator begin");
		}
		if (++it == range.extract_end_())
		{
			throw dis("strange::range::create passed short range");
		}
		any_a<> end = *it;
		if (!check<forward_extractor_a<>>(end))
		{
			throw dis("strange::range::create passed non-mutator end");
		}
		return create_(cast<forward_extractor_a<>>(begin), cast<forward_extractor_a<>>(end));
	}

	static inline range_a<> create_()
	{
		static range_a<> VAL = range_t<>::create_(it_t<>::create_(), it_t<>::create_());
		return VAL;
	}

	static inline range_a<> create_(forward_extractor_a<> const& begin, forward_extractor_a<> const& end)
	{
		return range_a<>::create<over>(range_t<>(begin, end));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::range");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::range::create", native_function_create(&range_t<>::create__));
	}

	// range
	inline forward_extractor_a<> extract_begin_() const
	{
		return _begin;
	}

	inline forward_extractor_a<> extract_end_() const
	{
		return _end;
	}

protected:
	forward_extractor_a<> _begin;
	forward_extractor_a<> _end;

	inline range_t(forward_extractor_a<> const& begin, forward_extractor_a<> const& end)
		: thing_t<___ego___>{}
		, _begin(begin)
		, _end(end)
	{}

private:
	static bool const ___share___;
	friend class ___range_t_share___;
};

template <typename ___ego___>
bool const range_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	range_t<___ego___>::share(shoal);
	return shoal;
}();

class ___range_t_share___
{
	static inline bool ___share___()
	{
		return range_t<>::___share___;
	}
};

inline range_a<> range_create()
{
	return range_t<>::create_();
}

inline range_a<> range_create(forward_extractor_a<> const& begin, forward_extractor_a<> const& end)
{
	return range_t<>::create_(begin, end);
}

} // namespace strange

#endif
