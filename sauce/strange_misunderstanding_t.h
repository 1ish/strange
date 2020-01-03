#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H

namespace strange
{

template <typename ___ego___ = misunderstanding_a<>>
class misunderstanding_t : public nothing_t<___ego___>
{
public:
	// override
	using over = thing_o<misunderstanding_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			return create_();
		}
		return create_(*it);
	}

	static inline misunderstanding_a<> create_(any_a<> const& thing = no())
	{
		return create("");
	}

	template <typename F>
	static inline misunderstanding_a<> create(F&& s)
	{
		return misunderstanding_a<>{ over{ misunderstanding_t<>{ std::forward<F>(s) } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<misunderstanding_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<misunderstanding_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check<misunderstanding_a<>>(thing) && cast<misunderstanding_a<>>(thing).to_string() == _string;
	}

	inline std::size_t hash() const
	{
		return std::hash<std::string>{}(_string);
	}

	// misunderstanding
	inline std::string to_string() const
	{
		return _string;
	}

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
		return misunderstanding_t<>::create(std::move(s));
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		return operator+(misunderstanding);
	}

	inline misunderstanding_a<> operator+(misunderstanding_a<> const& misunderstanding) const
	{
		return misunderstanding_t<>::create(_string + "\n" + misunderstanding.to_string());
	}

protected:
	std::string const _string;

	template <typename F>
	inline misunderstanding_t(F&& s)
		: nothing_t{}
		, _string{ std::forward<F>(s) }
	{}

private:
	static bool const ___share___;
	friend class ___misunderstanding_t_share___;
};

template <typename ___ego___>
bool const misunderstanding_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	misunderstanding_t<___ego___>::share(shoal);
	return shoal.something();
}();

template <typename F>
inline misunderstanding_a<> mis(F&& s)
{
	return misunderstanding_t<>::create(std::forward<F>(s));
}

} // namespace strange

#endif
