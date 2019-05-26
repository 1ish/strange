#ifndef COM_ONEISH_STRANGE_DISAGREEMENT_T_H
#define COM_ONEISH_STRANGE_DISAGREEMENT_T_H

namespace strange
{

template <typename _ABSTRACTION_ = misunderstanding_a<>>
class disagreement_t : public misunderstanding_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
		if (it == range.cend())
		{
			return val_();
		}
		return val_(*it);
	}

	static inline misunderstanding_a<> val_(any_a<> const& thing = no())
	{
		return val("");
	}

	template <typename F>
	static inline misunderstanding_a<> val(F&& s)
	{
		return misunderstanding_a<>{ disagreement_t{ std::forward<F>(s) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<disagreement_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<disagreement_t<>>::share(shoal);
	}

	// misunderstanding
	inline misunderstanding_a<> add__(range_a<> const& range) const
	{
		std::string s = _string;
		for (any_a<> const& thing : range)
		{
			if (check<misunderstanding_a<>>(thing))
			{
				s += cast<misunderstanding_a<>>(thing).to_string();
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
		return misunderstanding_a<>{ disagreement_t{ _string + misunderstanding.to_string() } };
	}

protected:
	template <typename F>
	inline disagreement_t(F&& s)
		: misunderstanding_t{ std::forward<F>(s) }
	{}
};

template <typename F>
inline misunderstanding_a<> dis(F&& s)
{
	return disagreement_t<>::val(std::forward<F>(s));
}

} // namespace strange

#endif
