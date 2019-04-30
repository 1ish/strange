#ifndef COM_ONEISH_STRANGE_SOMETHING_T_H
#define COM_ONEISH_STRANGE_SOMETHING_T_H

namespace strange
{

template <typename _ABSTRACTION_>
class something_t : public thing_t<_ABSTRACTION_>
{
public:
	// function
	inline any_a<> operator()(any_a<> const& thing, any_a<> const& range) const
	{
		//TODO
		// operation = thing.operations_().at(range.1st);
		// return operate_(thing, operation, range.2nd...);
		return nothing_t<>::val_();
	}

	// comparison
	static inline any_a<> something(any_a<> const&)
	{
		return something_();
	}

	static inline any_a<> something_()
	{
		return everything_t<>::val_();
	}

	static inline bool something__()
	{
		return true;
	}

protected:
	inline something_t()
		: thing_t{}
	{}
};

} // namespace strange

#endif
