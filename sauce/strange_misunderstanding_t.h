#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = misunderstanding_a<>>
class misunderstanding_t : public nothing_t<_ABSTRACTION_>
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
		return misunderstanding_a<>{ misunderstanding_t{ std::forward<F>(s) } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::misunderstanding");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check<misunderstanding_a<>>(thing) && cast<misunderstanding_a<>>(thing).to_string() == _string;
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !check<misunderstanding_a<>>(thing) || cast<misunderstanding_a<>>(thing).to_string() != _string;
	}

	inline std::size_t hash() const
	{
		return std::hash<std::string>{}(_string);
	}

	// misunderstanding
	inline std::string const& to_string() const
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
		return misunderstanding_a<>{ misunderstanding_t{ std::move(s) } };
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		return operator+(misunderstanding);
	}

	inline misunderstanding_a<> operator+(misunderstanding_a<> const& misunderstanding) const
	{
		return misunderstanding_a<>{ misunderstanding_t{ _string + misunderstanding.to_string() } };
	}

protected:
	std::string const _string;

	template <typename F>
	inline misunderstanding_t(F&& s)
		: nothing_t{}
		, _string{ std::forward<F>(s) }
	{}
};

template <typename F>
inline misunderstanding_a<> mis(F&& s)
{
	return misunderstanding_t<>::val(std::forward<F>(s));
}

} // namespace strange

#endif
