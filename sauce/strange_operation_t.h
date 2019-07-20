#ifndef COM_ONEISH_STRANGE_OPERATION_T_H
#define COM_ONEISH_STRANGE_OPERATION_T_H

namespace strange
{

template <typename _ABSTRACTION_ = operation_a<>>
class operation_t : public thing_t<_ABSTRACTION_>
{
public:
	// operation
	inline any_a<> pure__(range_a<> const&) const
	{
		return pure_();
	}

	inline any_a<> pure_() const
	{
		return boole(pure());
	}

	inline bool pure() const
	{
		return _pure;
	}

	inline any_a<> literal__(range_a<> const&) const
	{
		return literal_();
	}

	inline any_a<> literal_() const
	{
		return boole(literal());
	}

	inline bool literal() const
	{
		return _literal;
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
