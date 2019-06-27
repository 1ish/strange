#ifndef COM_ONEISH_STRANGE_DATA_T_H
#define COM_ONEISH_STRANGE_DATA_T_H

namespace strange
{

template <typename DATA, typename _ABSTRACTION_ = data_a<DATA>>
class data_t : public thing_t<_ABSTRACTION_>
{
public:
	// override
	using over = thing_o<data_t<DATA>>;

	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline data_a<DATA> val_()
	{
		return val(DATA{});
	}

	static inline data_a<DATA> val(DATA primitive)
	{
		return data_a<DATA>{ over{ data_t<DATA>{ primitive } } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<data_t<DATA>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<data_t<DATA>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<data_a<DATA>>(thing))
		{
			return false;
		}
		return _data == cast<data_a<DATA>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		return std::hash<DATA>{}(_data);
	}

	// data
	inline DATA const& extract() const
	{
		return _data;
	}

	inline void mutate(DATA const& data)
	{
		_data = data;
	}

	inline DATA& reference()
	{
		return _data;
	}

protected:
	DATA _data;

	inline data_t(DATA data)
		: thing_t{}
		, _data(data)
	{}
};

} // namespace strange

#endif
