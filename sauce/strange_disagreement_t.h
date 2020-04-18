#ifndef COM_ONEISH_STRANGE_DISAGREEMENT_T_H
#define COM_ONEISH_STRANGE_DISAGREEMENT_T_H

namespace strange
{

template <typename ___ego___ = misunderstanding_a<>>
class disagreement_t : public nothing_t<___ego___>
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
		return create_(*it);
	}

	static inline misunderstanding_a<> create_(any_a<> const& thing = no())
	{
		return create("");
	}

	template <typename F>
	static inline misunderstanding_a<> create(F&& s)
	{
		return misunderstanding_a<>::create<disagreement_t<>>(std::forward<F>(s));
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::disagreement");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::disagreement::create"), native_function_create(&disagreement_t<>::create__));
	}

	// comparison
	inline bool same_(any_a<> const& thing) const
	{
		return check<misunderstanding_a<>>(thing) &&
			fast<misunderstanding_a<>>(thing).to_string() == to_string();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std_size_t hash() const
	{
		return std::hash<std::string>{}(to_string());
	}

	// misunderstanding
	inline lake_a<int8_t> to_lake_() const
	{
		return lake_from_string(_string);
	}

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

	friend class any_a<>;

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
