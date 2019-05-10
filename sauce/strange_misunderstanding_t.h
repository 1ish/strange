#ifndef COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H
#define COM_ONEISH_STRANGE_MISUNDERSTANDING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = misunderstanding_a<>>
class misunderstanding_t : public something_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline misunderstanding_a<> val(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
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
		return misunderstanding_a<>{ misunderstanding_t{ std::forward<F>(s) } };
	}

	static inline misunderstanding_a<> ref(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin();
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
		return misunderstanding_a<>(misunderstanding_t{ std::forward<F>(s) }, true);
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym__("strange::misunderstanding");
		return TYPE;
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check_<misunderstanding_a<>>(thing) && cast_<misunderstanding_a<>>(thing).to_string__() == _string;
	}

	inline bool operator!=(any_a<> const& thing) const
	{
		return !check_<misunderstanding_a<>>(thing) || cast_<misunderstanding_a<>>(thing).to_string__() != _string;
	}

	inline std::size_t hash__() const
	{
		return std::hash<std::string>{}(_string);
	}

	// misunderstanding
	inline std::string const& to_string__() const
	{
		return _string;
	}

	inline misunderstanding_a<> add(range_a<> const& range) const
	{
		std::string s = _string;
		for (any_a<> const& thing : range)
		{
			if (check_<misunderstanding_a<>>(thing))
			{
				s += cast_<misunderstanding_a<>>(thing).to_string__();
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
		return misunderstanding_a<>{ misunderstanding_t{ _string + misunderstanding.to_string__() } };
	}

protected:
	std::string const _string;

	template <typename F>
	inline misunderstanding_t(F&& s)
		: something_t{}
		, _string{ std::forward<F>(s) }
	{}
};

template <typename F>
inline misunderstanding_a<> mis__(F&& s)
{
	return misunderstanding_t<>::val__(std::forward<F>(s));
}

} // namespace strange

#endif
