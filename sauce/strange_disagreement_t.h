#ifndef COM_ONEISH_STRANGE_DISAGREEMENT_T_H
#define COM_ONEISH_STRANGE_DISAGREEMENT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = misunderstanding_a<>>
class disagreement_t : public misunderstanding_t<_ABSTRACTION_>
{
public: ___THING___
	// construction
	static inline misunderstanding_a<> val(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline misunderstanding_a<> val_(any_a<> const& thing = nothing_t<>::val_())
	{
		return val__("");
	}

	template <typename F>
	static inline misunderstanding_a<> val__(F&& s)
	{
		return misunderstanding_a<>{ disagreement_t{ std::forward<F>(s) } };
	}

	static inline misunderstanding_a<> ref(any_a<> const& range)
	{
		forward_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return ref_();
		}
		return ref_(*it);
	}

	static inline misunderstanding_a<> ref_(any_a<> const& thing = nothing_t<>::val_())
	{
		return ref__("");
	}

	template <typename F>
	static inline misunderstanding_a<> ref__(F&& s)
	{
		return misunderstanding_a<>(disagreement_t{ std::forward<F>(s) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::disagreement");
		return TYPE;
	}

	// misunderstanding
	inline misunderstanding_a<> add(any_a<> const& range) const
	{
		std::string s = _string;
		for (any_a<> const& thing : range)
		{
			if (check_<misunderstanding_a<>>(thing))
			{
				s += cast_<misunderstanding_a<>>(thing).to_string__();
			}
		}
		return misunderstanding_a<>{ disagreement_t{ std::move(s) } };
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		return operator+(misunderstanding);
	}

	inline misunderstanding_a<> operator+(misunderstanding_a<> const& misunderstanding) const
	{
		return misunderstanding_a<>{ disagreement_t{ _string + misunderstanding.to_string__() } };
	}

protected:
	template <typename F>
	inline disagreement_t(F&& s)
		: misunderstanding_t{ std::forward<F>(s) }
	{}
};

template <typename F>
inline misunderstanding_a<> dis__(F&& s)
{
	return disagreement_t<>::val__(std::forward<F>(s));
}

} // namespace strange

#endif
