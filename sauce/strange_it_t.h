#ifndef COM_ONEISH_STRANGE_IT_T_H
#define COM_ONEISH_STRANGE_IT_T_H

namespace strange
{

template <typename ___ego___ = forward_const_iterator_a<>>
class it_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<it_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const&)
	{
		return create_();
	}

	static inline forward_const_iterator_a<> create_()
	{
		static forward_const_iterator_a<> VAL = forward_const_iterator_a<>{ over{ it_t<>{} } };
		return VAL;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		return reflection<it_t<>>::type();
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<it_t<>>::share(shoal);
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return check<forward_const_iterator_a<>>(thing);
	}

	inline std::size_t hash() const
	{
		return _thing.hash();
	}

	// forward iterator
	inline any_a<> get__(range_a<> const&) const
	{
		return get_();
	}
	
	inline any_a<> get_() const
	{
		return _thing;
	}

	inline any_a<> const* operator->() const
	{
		return &operator*();
	}

	inline any_a<> const& operator*() const
	{
		return _thing;
	}

	inline ___ego___ increment__(range_a<> const&)
	{
		return increment_();
	}

	inline ___ego___ increment_()
	{
		return me_();
	}

	inline it_t& operator++()
	{
		return *this;
	}

	inline it_t operator++(int)
	{
		return *this;
	}

protected:
	any_a<> const _thing; // stashing iterator

	inline it_t()
		: thing_t{}
		, _thing{ no() }
	{}

private:
	static bool const ___share___;
	friend class ___it_t_share___;
};

template <typename ___ego___>
bool const it_t<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	it_t<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
