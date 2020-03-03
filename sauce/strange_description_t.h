#ifndef COM_ONEISH_STRANGE_DESCRIPTION_T_H
#define COM_ONEISH_STRANGE_DESCRIPTION_T_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class description_t : public operation_t<___ego___>
{
public:
	// override
	using over = thing_o<description_t<>>;

	// construction
	static inline operation_a<> create_()
	{
		return operation_a<>::create<over>(description_t<>());
	}

	// reflection
	static inline symbol_a<> type_()
	{
		static symbol_a<> TYPE = sym("strange::description");
		return TYPE;
	}

	static inline void share(shoal_a<>&)
	{}

	inline any_a<> cat__(range_a<> const&) const
	{
		return cat_();
	}

	inline cat_a<> cat_() const
	{
		return _cat;
	}

	inline any_a<> cats__(range_a<> const&) const
	{
		return cats_();
	}

	inline unordered_herd_a<> cats_() const
	{
		return _cats;
	}

	inline any_a<> kind__(range_a<> const&) const
	{
		return kind_();
	}

	inline kind_a<> kind_() const
	{
		return _kind;
	}

	inline any_a<> kinds__(range_a<> const&) const
	{
		return kinds_();
	}

	inline unordered_herd_a<> kinds_() const
	{
		return _kinds;
	}

	// function
	inline any_a<> operate(any_a<>&, range_a<> const&) const
	{
		throw dis("strange::description::operate should not be called");
	}

protected:
	kind_a<> const _kind;
	unordered_herd_a<> const _kinds;
	cat_a<> const _cat;
	unordered_herd_a<> const _cats;

	inline description_t()
		: operation_t<___ego___>{}
		, _kind{ kind_create() }
		, _kinds{ operation_t<___ego___>::kinds(_kind) }
		, _cat{ kind_to_cat(_kind) }
		, _cats{ operation_t<___ego___>::cats(_cat) }
	{}
};

} // namespace strange

#endif
