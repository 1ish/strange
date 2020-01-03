#ifndef COM_ONEISH_STRANGE_DATA_T_H
#define COM_ONEISH_STRANGE_DATA_T_H

namespace strange
{

template <typename _data_, typename ___ego___ = data_a<_data_>>
class data_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<data_t<_data_>>;

	// construction
	static inline any_a<> create__(range_a<> const& _)
	{
		return create_();
	}

	static inline data_a<_data_> create_()
	{
		return create(_data_{});
	}

	static inline data_a<_data_> create(_data_ primitive)
	{
		return data_a<_data_>{ over{ data_t<_data_>{ primitive } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<data_t<_data_>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<data_t<_data_>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<data_a<_data_>>(thing))
		{
			return false;
		}
		return _data == cast<data_a<_data_>>(thing).extract_data();
	}

	inline std::size_t hash() const
	{
		return std::hash<_data_>{}(_data);
	}

	// data
	inline _data_ const& extract_data() const
	{
		return _data;
	}

	inline _data_& mutate_data()
	{
		return _data;
	}

protected:
	_data_ _data;

	inline data_t(_data_ data)
		: thing_t{}
		, _data(data)
	{}

private:
	static bool const ___share___;
	friend class ___data_t_share___;
};

template <typename _data_, typename ___ego___>
bool const data_t<_data_, ___ego___>::___share___ = []()
{
	auto& shoal = shared();
	data_t<_data_, ___ego___>::share(shoal);
	return shoal.something();
}();

} // namespace strange

#endif
