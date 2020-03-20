#ifndef COM_ONEISH_STRANGE_OPERATION_C_H
#define COM_ONEISH_STRANGE_OPERATION_C_H

namespace strange
{

// template <typename ___ego___ = operation_a<>>
template <typename ___ego___>
class operation_c : public any_c<___ego___>
{
public:
	// construction
	static inline any_a<> animate__(range_a<> const& range)
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::operation>::animate passed empty range");
		}
		any_a<> conception = *it;
		if (!check<shoal_a<>>(conception))
		{
			throw dis("<strange::operation>::animate passed non-shoal conception");
		}
		return animate_(fast<shoal_a<>>(conception));
	}

	static inline operation_a<> animate_(shoal_a<> const& conception)
	{
		return operation_a<>{operation_c{ conception } };
	}

	// reflection
	inline any_a<> type__(range_a<> const& range) const
	{
		auto const op = any_c<___ego___>::_operations.at_string("type");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			return op.operate(thing, range);
		}
		static symbol_a<> TYPE = sym("<strange::operation>");
		return TYPE;
	}

	inline symbol_a<> type_() const
	{
		auto const op = any_c<___ego___>::_operations.at_string("type");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<symbol_a<>>(result))
			{
				throw dis("<strange::operation>::type returned non-symbol");
			}
			return fast<symbol_a<>>(result);
		}
		static symbol_a<> TYPE = sym("<strange::operation>");
		return TYPE;
	}

	inline any_a<> shared__(range_a<> const& range) const
	{
		auto const op = any_c<___ego___>::_operations.at_string("shared");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			return op.operate(thing, range);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	inline unordered_shoal_a<> shared_() const
	{
		auto const op = any_c<___ego___>::_operations.at_string("shared");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("<strange::operation>::shared returned non-unordered-shoal");
			}
			return fast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("<strange::operation>::animate", native_function_create(&operation_c<>::animate__));
	}

	// operation
	inline any_a<> pure__(range_a<> const& range) const
	{
		auto const op = any_c<___ego___>::_operations.at_string("pure");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			return op.operate(thing, range);
		}
		auto const oper = any_c<___ego___>::_operations.at_string("operate");
		if (check<operation_a<>>(oper))
		{
			return fast<operation_a<>>(oper).pure_();
		}
		return no();
	}

	inline any_a<> pure_() const
	{
		auto const op = any_c<___ego___>::_operations.at_string("pure");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			return op.operate(thing, range_t<>::create_());
		}
		auto const oper = any_c<___ego___>::_operations.at_string("operate");
		if (check<operation_a<>>(oper))
		{
			return fast<operation_a<>>(oper).pure_();
		}
		return no();
	}

	inline bool pure() const
	{
		auto const op = any_c<___ego___>::_operations.at_string("pure");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			return op.operate(thing, range_t<>::create_());
		}
		auto const oper = any_c<___ego___>::_operations.at_string("operate");
		if (check<operation_a<>>(oper))
		{
			return fast<operation_a<>>(oper).pure();
		}
		return false;
	}

	static inline void aspects(unordered_shoal_a<> const&)
	{}

	static inline void assign(operation_a<> const&)
	{}

	inline any_a<> names__(range_a<> const& range) const
	{
		auto const op = any_c<___ego___>::_operations.at_string("names");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			return op.operate(thing, range);
		}
		return flock_t<>::create_();
	}

	inline flock_a<> names_() const
	{
		auto const op = any_c<___ego___>::_operations.at_string("names");
		if (op)
		{
			any_a<> thing = any_c<___ego___>::me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<flock_a<>>(result))
			{
				throw dis("<strange::operation>::names returned non-flock");
			}
			return fast<flock_a<>>(result);
		}
		return flock_t<>::create_();
	}

protected:
	// construction
	inline operation_c(shoal_a<> const& conception)
		: any_c<___ego___>{ conception }
	{}

private:
	static bool const ___share___;
	friend class ___operation_c_share___;
};

template <typename ___ego___>
bool const operation_c<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	operation_c<___ego___>::share(shoal);
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
