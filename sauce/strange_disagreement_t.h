#ifndef COM_ONEISH_STRANGE_DISAGREEMENT_T_H
#define COM_ONEISH_STRANGE_DISAGREEMENT_T_H

namespace strange
{

template <typename ___ego___ = misunderstanding_a<>>
class disagreement_t : public nothing_t<___ego___>
{
public:
	// override
	using over = thing_o<disagreement_t<>>;

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
		return misunderstanding_a<>::create<over>(disagreement_t<>{ std::forward<F>(s) });
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::disagreement");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::disagreement::create", native_function_create(&disagreement_t<>::create__));
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
		return _string;
	}

	inline misunderstanding_a<> add_(misunderstanding_a<> const& misunderstanding) const
	{
		return disagreement_t<>::create(to_string() + "\n" + misunderstanding.to_string());
	}

protected:
	std::string const _string;

	template <typename F>
	inline disagreement_t(F&& s)
		: nothing_t<___ego___>{}
		, _string{ std::forward<F>(s) }
	{}

private:
	static bool const ___share___;
	friend class ___disagreement_t_share___;
};

template <typename ___ego___>
bool const disagreement_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	disagreement_t<___ego___>::share(shoal);
	return shoal;
}();

class ___disagreement_t_share___
{
	static inline bool ___share___()
	{
		return disagreement_t<>::___share___;
	}
};

template <typename F>
inline misunderstanding_a<> dis(F&& s)
{
	return disagreement_t<>::create(std::forward<F>(s));
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
