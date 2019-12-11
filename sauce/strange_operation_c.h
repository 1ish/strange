#ifndef COM_ONEISH_STRANGE_OPERATION_C_H
#define COM_ONEISH_STRANGE_OPERATION_C_H

namespace strange
{

template <typename ___ego___ = operation_a<>>
class operation_c : public any_c<___ego___>
{
public:
	// construction
	static inline any_a<> animate__(range_a<> const& range)
	{
		forward_const_iterator_a<> it = range.cbegin_();
		if (it == range.cend_())
		{
			throw dis("<strange::operation>::animate passed empty range");
		}
		any_a<> conception = *it;
		if (!check<shoal_a<>>(conception))
		{
			throw dis("<strange::operation>::animate passed non-shoal conception");
		}
		return animate_(cast<shoal_a<>>(conception));
	}

	static inline operation_a<> animate_(shoal_a<> const& conception)
	{
		return operation_a<>{operation_c{ conception } };
	}

	// reflection
	inline any_a<> type__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("type");
		if (op)
		{
			return op.operate(any_a<>(me_(), true), range);
		}
		return reflection<operation_c<>>::type();
	}

	inline symbol_a<> type_() const
	{
		auto const op = _operations.at_string("type");
		if (op)
		{
			auto const result = op.operate(any_a<>(me_(), true), range_t<>::create_());
			if (!check<symbol_a<>>(result))
			{
				throw dis("<strange::operation>::type returned non-symbol");
			}
			return cast<symbol_a<>>(result);
		}
		return reflection<operation_c<>>::type();
	}

	inline any_a<> shared__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("shared");
		if (op)
		{
			return op.operate(any_a<>(me_(), true), range);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	inline unordered_shoal_a<> shared_() const
	{
		auto const op = _operations.at_string("shared");
		if (op)
		{
			auto const result = op.operate(any_a<>(me_(), true), range_t<>::create_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("<strange::operation>::shared returned non-unordered-shoal");
			}
			return cast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	static inline void share(shoal_a<>& shoal)
	{
		reflection<operation_c<>>::share(shoal);
	}

	// operation
	inline any_a<> pure__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("pure");
		if (op)
		{
			return op.operate(any_a<>(me_(), true), range);
		}
		auto const oper = _operations.at_string("operate");
		if (check<operation_a<>>(oper))
		{
			return cast<operation_a<>>(oper).pure_();
		}
		return no();
	}

	inline any_a<> pure_() const
	{
		auto const op = _operations.at_string("pure");
		if (op)
		{
			return op.operate(any_a<>(me_(), true), range_t<>::create_());
		}
		auto const oper = _operations.at_string("operate");
		if (check<operation_a<>>(oper))
		{
			return cast<operation_a<>>(oper).pure_();
		}
		return no();
	}

	inline bool pure() const
	{
		auto const op = _operations.at_string("pure");
		if (op)
		{
			return op.operate(any_a<>(me_(), true), range_t<>::create_());
		}
		auto const oper = _operations.at_string("operate");
		if (check<operation_a<>>(oper))
		{
			return cast<operation_a<>>(oper).pure();
		}
		return false;
	}

	static inline void aspects(unordered_shoal_a<> const&)
	{}

	inline any_a<> names__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("names");
		if (op)
		{
			return op.operate(any_a<>(me_(), true), range);
		}
		return flock_t<>::create_();
	}

	inline flock_a<> names_() const
	{
		auto const op = _operations.at_string("names");
		if (op)
		{
			auto const result = op.operate(any_a<>(me_(), true), range_t<>::create_());
			if (!check<flock_a<>>(result))
			{
				throw dis("<strange::operation>::names returned non-flock");
			}
			return cast<flock_a<>>(result);
		}
		return flock_t<>::create_();
	}

protected:
	// construction
	inline operation_c(shoal_a<> const& conception)
		: any_c{ conception }
	{}

private:
	static bool const ___share___;
	friend class ___operation_c_share___;
};

template <typename ___ego___>
bool const operation_c<___ego___>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	operation_c<___ego___>::share(shoal);
	return shoal;
}();

} // namespace strange

#endif
