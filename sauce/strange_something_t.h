#ifndef COM_ONEISH_STRANGE_SOMETHING_T_H
#define COM_ONEISH_STRANGE_SOMETHING_T_H

namespace strange
{

template <typename ___ego___ = any_a<>>
class something_t : public thing_t<___ego___>
{
public:
	// override
	using over = thing_o<something_t<>>;

	// construction
	static inline any_a<> create__(range_a<> const& _)
	{
		return create_();
	}

	static inline any_a<> create_()
	{
		static any_a<> VAL = any_a<>::template create<over>(something_t<>{});
		return VAL;
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::something");
		return TYPE;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("strange::something::create", native_function_create(&something_t<>::create__));
	}

	// comparison
	inline bool operator==(any_a<> const& thing) const
	{
		return thing.something();
	}

	inline std::size_t hash() const
	{
		static std::size_t const HASH = std::hash<int64_t>{}(1);
		return HASH;
	}

protected:
	inline something_t()
		: thing_t<___ego___>{}
	{}

private:
	static bool const ___share___;
	friend class ___something_t_share___;
};

template <typename ___ego___>
bool const something_t<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	something_t<___ego___>::share(shoal);
	return shoal;
}();

class ___something_t_share___
{
	static inline bool ___share___()
	{
		return something_t<>::___share___;
	}
};

} // namespace strange

#endif
