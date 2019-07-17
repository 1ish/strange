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

	// reflection
	inline any_a<> type__(range_a<> const& range) const
	{
		auto op = _operations.at_string("type");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		return reflection<operation_c<>>::type();
	}

	inline symbol_a<> type_() const
	{
		auto op = _operations.at_string("type");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<symbol_a<>>(result))
			{
				throw dis("strange::operation_creature::type returned non-symbol");
			}
			return cast<symbol_a<>>(result);
		}
		return reflection<operation_c<>>::type();
	}

	inline any_a<> shared__(range_a<> const& range) const
	{
		auto op = _operations.at_string("shared");
		if (op)
		{
			return op.operate_(any_a<>(me_(), true), range);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::val_();
		share(shoal);
		return shoal;
	}

	inline unordered_shoal_a<> shared_() const
	{
		auto op = _operations.at_string("shared");
		if (op)
		{
			auto result = op.operate_(any_a<>(me_(), true), range_t<>::val_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("strange::operation_creature::shared returned non-unordered-shoal");
			}
			return cast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::val_();
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

private:
	static bool const ___share___;
	friend class ___operation_c_share___;
};

template <typename _ABSTRACTION_>
bool const operation_c<_ABSTRACTION_>::___share___ = []()
{
	auto shoal = shoal_a<>(shared(), true);
	operation_c<_ABSTRACTION_>::share(shoal);
	return shoal;
}();

class ___operation_c_share___
{
	static inline bool ___share___()
	{
		return operation_c<>::___share___;
	}
};

} // namespace strange

#endif
