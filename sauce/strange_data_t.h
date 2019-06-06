#ifndef COM_ONEISH_STRANGE_DATA_T_H
#define COM_ONEISH_STRANGE_DATA_T_H

namespace strange
{

template <typename PRIMITIVE = bool, typename _ABSTRACTION_ = data_a<PRIMITIVE>>
class data_t : public thing_t<_ABSTRACTION_>
{
public: ___STRANGE_THING___
	// construction
	static inline any_a<> val__(range_a<> const& _)
	{
		return val_();
	}

	static inline data_a<PRIMITIVE> val_()
	{
		return val(PRIMITIVE{});
	}

	static inline data_a<PRIMITIVE> val(PRIMITIVE primitive)
	{
		return data_a<PRIMITIVE>{ data_t<PRIMITIVE, _ABSTRACTION_>{ primitive } };
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<data_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<data_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		if (!check<data_a<PRIMITIVE>>(thing))
		{
			return false;
		}
		return _data == cast<data_a<PRIMITIVE>>(thing).extract();
	}

	inline std::size_t hash() const
	{
		return std::hash<PRIMITIVE>{}(_data);
	}

	// data
	inline PRIMITIVE const& extract() const
	{
		return _data;
	}

	inline void mutate(PRIMITIVE const& data)
	{
		_data = data;
	}

	inline PRIMITIVE& reference()
	{
		return _data;
	}

protected:
	PRIMITIVE _data;

	inline data_t(PRIMITIVE data)
		: thing_t{}
		, _data(data)
	{}
};

} // namespace strange

#endif
