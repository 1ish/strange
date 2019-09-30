#ifndef COM_ONEISH_STRANGE_DISAGREEMENT_T_H
#define COM_ONEISH_STRANGE_DISAGREEMENT_T_H

namespace strange
{

template <typename ___ego___ = misunderstanding_a<>>
class disagreement_t : public nothing_t<___ego___>, public std::logic_error
{
public:
	// override
	using over = thing_o<disagreement_t<>>;

	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
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
		return misunderstanding_a<>{ over{ disagreement_t<>{ std::forward<F>(s) } } };
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

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check<misunderstanding_a<>>(thing) && cast<misunderstanding_a<>>(thing).to_string() == to_string();
	}

	inline std::size_t hash() const
	{
		return std::hash<std::string>{}(to_string());
	}

	// misunderstanding
	inline std::string to_string() const
	{
		return what();
	}

	inline misunderstanding_a<> add__(range_a<> const& range) const
	{
		std::string s = to_string();
		for (any_a<> const& thing : range)
		{
			if (check<misunderstanding_a<>>(thing))
			{
				s += cast<misunderstanding_a<>>(thing).to_string();
			}
		}
		return disagreement_t<>::val(std::move(s));
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		return operator+(misunderstanding);
	}

	inline misunderstanding_a<> operator+(misunderstanding_a<> const& misunderstanding) const
	{
		return disagreement_t<>::val(to_string() + "\n" + misunderstanding.to_string());
	}

protected:
	template <typename F>
	inline disagreement_t(F&& s)
		: nothing_t{}
		, std::logic_error{ std::forward<F>(s) }
	{}

private:
	static bool const ___share___;
	friend class ___disagreement_t_share___;
};

template <typename ___ego___>
bool const disagreement_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	disagreement_t<___ego___>::share(shoal);
	return shoal;
}();

template <typename F>
inline misunderstanding_a<> dis(F&& s)
{
	return disagreement_t<>::val(std::forward<F>(s));
}

inline misunderstanding_a<> operator+(std::exception const& e, misunderstanding_a<> const& m)
{
	return dis(e.what()) + m;
}

inline misunderstanding_a<> operator+(misunderstanding_a<> const& m, std::exception const& e)
{
	return m + mis(e.what());
}

} // namespace strange

#endif
