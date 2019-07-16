#ifndef COM_ONEISH_STRANGE_OPERATION_C_H
#define COM_ONEISH_STRANGE_OPERATION_C_H

namespace strange
{

template <typename _ABSTRACTION_ = operation_a<>>
class operation_c : public any_c<_ABSTRACTION_>
{
public:
	// construction
	static inline any_a<> val__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("strange::operation_creature::val passed empty range");
		}
		any_a<> creation = *it;
		if (!check<shoal_a<>>(creation))
		{
			throw dis("strange::operation_creature::val passed non-shoal creation");
		}
		return val_(cast<shoal_a<>>(creation));
	}

	static inline operation_a<> val_(shoal_a<> const& creation)
	{
		return operation_a<>{operation_c{ creation } };
	}

	// operation
	inline any_a<> pure__(range_a<> const& range) const
	{
		auto op = _operations.at_string("pure");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return no();
	}

	inline any_a<> pure_() const
	{
		auto op = _operations.at_string("pure");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		return no();
	}

	inline bool pure() const
	{
		auto op = _operations.at_string("pure");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		return false;
	}

	inline any_a<> literal__(range_a<> const& range) const
	{
		auto op = _operations.at_string("literal");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return no();
	}

	inline any_a<> literal_() const
	{
		auto op = _operations.at_string("literal");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		return no();
	}

	inline bool literal() const
	{
		auto op = _operations.at_string("literal");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range_t<>::val_());
		}
		return false;
	}

protected:
	// construction
	inline operation_c(shoal_a<> const& creation)
		: any_c{ creation }
	{}
};

} // namespace strange

#endif
