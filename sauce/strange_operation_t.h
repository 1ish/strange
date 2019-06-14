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
	bool const _pure;
	bool const _literal;

	inline operation_t(bool pure = false, bool literal = false)
		: thing_t{}
		, _pure(pure)
		, _literal(literal)
	{}
};

} // namespace strange

#endif
