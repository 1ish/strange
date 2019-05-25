#ifndef COM_ONEISH_STRANGE_OPERATION_T_H
#define COM_ONEISH_STRANGE_OPERATION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = any_a<>>
class operation_t : public thing_t<_ABSTRACTION_>
{
public:
	// comparison
	static inline any_a<> operation__(range_a<> const&)
	{
		return operation_();
	}

	static inline any_a<> operation_()
	{
		return yes();
	}

	static inline bool operation()
	{
		return true;
	}

protected:
	inline operation_t()
		: thing_t{}
	{}
};

} // namespace strange

#endif
