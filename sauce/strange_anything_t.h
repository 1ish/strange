#ifndef COM_ONEISH_STRANGE_ANYTHING_T_H
#define COM_ONEISH_STRANGE_ANYTHING_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class anything_t : public thing_t<_ABSTRACTION_>
{
public:
	// function
	inline any_a<> operator()(any_a<> const& thing, range_a<> const& range) const
	{
		//TODO
		// operation = thing.operations_().at(range.1st);
		// return operate_(thing, operation, range.2nd...);
		return nothing_t<>::val_();
	}

	// comparison
	static inline any_a<> anything__(range_a<> const&)
	{
		return anything_();
	}

	static inline any_a<> anything_()
	{
		return something_t<>::val_();
	}

	static inline bool anything()
	{
		return true;
	}

protected:
	inline anything_t()
		: thing_t{}
	{}
};

} // namespace strange

#endif
