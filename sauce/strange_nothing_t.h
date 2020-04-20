#ifndef COM_ONEISH_STRANGE_NOTHING_T_H
#define COM_ONEISH_STRANGE_NOTHING_T_H

namespace strange
{

template <typename ___ego___ = any_a<>>
class nothing_t : public thing_t<___ego___>
{
public:
	// construction
	static inline any_a<> create__(list_a<> const& _)
	{
		return create_();
	}

	static inline any_a<> create_()
	{
		static any_a<> VAL = any_a<>::create<nothing_t<>>();
		return VAL;
	}

	// conversion
	inline operator bool() const
	{
		return something();
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::nothing");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update(sym("strange::nothing::create"), native_function_create(&nothing_t<>::create__));
	}

	// comparison
	static inline any_a<> nothing_()
	{
		return yes();
	}

	static inline bool nothing()
	{
		return true;
	}

	static inline any_a<> something_()
	{
		return no();
	}

	static inline bool something()
	{
		return false;
	}

	inline bool same_(any_a<> const& thing) const
	{
		return thing.nothing();
	}

	inline number_data_a<uint64_t> hash_() const
	{
		return num(uint64_t(hash()));
	}

	inline std_size_t hash() const
	{
		static std_size_t const HASH = std::hash<int64_t>{}(0);
		return HASH;
	}

protected:
	friend class any_a<>;

	inline nothing_t()
		: thing_t<___ego___>{}
	{}

private:
	static bool const ___share___;
	friend class ___nothing_t_share___;
};

template <typename ___ego___>
bool const nothing_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	nothing_t<___ego___>::share(shoal);
	return shoal;
}();

class ___nothing_t_share___
{
	static inline bool ___share___()
	{
		return nothing_t<>::___share___;
	}
};

} // namespace strange

#endif
