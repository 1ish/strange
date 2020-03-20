#ifndef COM_ONEISH_STRANGE_ANY_C_H
#define COM_ONEISH_STRANGE_ANY_C_H

namespace strange
{

// template <typename ___ego___ = any_a<>>
template <typename ___ego___>
class any_c : public one_t
{
public:
	// construction
	static inline any_a<> animate__(range_a<> const& range)
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::animate passed empty range");
		}
		any_a<> conception = *it;
		if (!check<shoal_a<>>(conception))
		{
			throw dis("<strange::any>::animate passed non-shoal conception");
		}
		return animate_(fast<shoal_a<>>(conception));
	}

	static inline any_a<> animate_(shoal_a<> const& conception)
	{
		return any_a<>{ any_c{ conception } };
	}

	// erasure
	inline ___ego___ const me_() const
	{
		return ___ego___{ _meek.lock() };
	}

	inline ___ego___ me_()
	{
		return ___ego___{ _meek.lock() };
	}

	// reflection
	inline any_a<> type__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("type");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		static symbol_a<> TYPE = sym("<strange::any>");
		return TYPE;
	}

	inline symbol_a<> type_() const
	{
		auto const op = _operations.at_string("type");
		if (op)
		{
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<symbol_a<>>(result))
			{
				throw dis("<strange::any>::type returned non-symbol");
			}
			return fast<symbol_a<>>(result);
		}
		static symbol_a<> TYPE = sym("<strange::any>");
		return TYPE;
	}

	inline any_a<> shared__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("shared");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
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
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<unordered_shoal_a<>>(result))
			{
				throw dis("<strange::any>::shared returned non-unordered-shoal");
			}
			return fast<unordered_shoal_a<>>(result);
		}
		unordered_shoal_a<> shoal = unordered_shoal_t<>::create_();
		share(shoal);
		return shoal;
	}

	static inline void share(shoal_a<>& shoal)
	{
		shoal.update_string("<strange::any>::animate", native_function_create(&any_c<>::animate__));
	}

	inline any_a<> cat__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("cat");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		return ___ego___::___cat___();
	}
	
	inline cat_a<> cat_() const
	{
		auto const op = _operations.at_string("cat");
		if (op)
		{
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<cat_a<>>(result))
			{
				throw dis("<strange::any>::cat returned non-cat");
			}
			return fast<cat_a<>>(result);
		}
		return ___ego___::___cat___();
	}

	inline any_a<> cats__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("cats");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		return ___ego___::___cats___();
	}

	inline unordered_herd_a<> cats_() const
	{
		auto const op = _operations.at_string("cats");
		if (op)
		{
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<unordered_herd_a<>>(result))
			{
				throw dis("<strange::any>::cats returned non-unordered-herd");
			}
			return fast<unordered_herd_a<>>(result);
		}
		return ___ego___::___cats___();
	}

	inline any_a<> kind__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("kind");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		return ___ego___::___kind___();
	}

	inline kind_a<> kind_() const
	{
		auto const op = _operations.at_string("kind");
		if (op)
		{
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<kind_a<>>(result))
			{
				throw dis("<strange::any>::kind returned non-kind");
			}
			return fast<kind_a<>>(result);
		}
		return ___ego___::___kind___();
	}

	inline any_a<> kinds__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("kinds");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		return ___ego___::___kinds___();
	}

	inline unordered_herd_a<> kinds_() const
	{
		auto const op = _operations.at_string("kinds");
		if (op)
		{
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<unordered_herd_a<>>(result))
			{
				throw dis("<strange::any>::kinds returned non-unordered-herd");
			}
			return fast<unordered_herd_a<>>(result);
		}
		return ___ego___::___kinds___();
	}

	inline any_a<> operations__(range_a<> const& range) const // cannot be overridden
	{
		return _operations;
	}
	
	inline unordered_shoal_a<> operations_() const
	{
		return _operations;
	}

	// visitor pattern
	inline any_a<> visit__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("visit");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		return thing_t<>::operate__(range); //TODO
	}

	inline any_a<> visit_(inventory_a<>& inventory) const
	{
		return visit__(inventory); //TODO
	}

	// function
	inline any_a<> invoke(any_a<>& thing, range_a<> const& range) const
	{
		auto const op = _operations.at_string("invoke");
		if (op)
		{
			any_a<> thing = me_();
			op.operate(thing, flock_t<>::create_(thing) += range);
		}
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::invoke passed short range");
		}
		any_a<> member = *it;
		if (!thing.operations_().has_(member))
		{
			throw dis("<strange::any>::invoke passed non-existent member");
		}
		return thing.operations_().at_(member).operate(thing, range_t<>::create_(++it, range.extract_end_()));
	}

	inline any_a<> operate(any_a<>& thing, range_a<> const& range) const
	{
		auto const op = _operations.at_string("operate");
		if (op)
		{
			any_a<> thing = me_();
			op.operate(thing, flock_t<>::create_(thing) += range);
		}
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::operate passed short range");
		}
		any_a<> operation = *it;
		return operation.operate(thing, range_t<>::create_(++it, range.extract_end_()));
	}

	// identification
	inline any_a<> identity__(range_a<> const&) const // cannot be overridden
	{
		return identity_();
	}

	inline number_data_a<uint64_t> identity_() const
	{
		return number_uint_64_t<>::create(uint64_t(identity()));
	}

	inline any_a<> identical__(range_a<> const& range) const // cannot be overridden
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::identical passed empty range");
		}
		return identical_(*it);
	}

	inline any_a<> identical_(any_a<> const& thing) const
	{
		return boole(identical(thing));
	}

	// comparison
	inline any_a<> nothing__(range_a<> const&) const // cannot be overridden
	{
		return nothing_();
	}

	inline any_a<> nothing_() const
	{
		return no();
	}

	inline any_a<> something__(range_a<> const&) const // cannot be overridden
	{
		return something_();
	}

	inline any_a<> something_() const
	{
		return yes();
	}

	inline any_a<> same__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("same");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::same passed empty range");
		}
		return identical_(*it);
	}

	inline bool same_(any_a<> const& thing) const
	{
		auto const op = _operations.at_string("same");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, flock_t<>::create_(thing));
		}
		return identical_(thing);
	}

	inline any_a<> different__(range_a<> const& range) const // cannot be overridden
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::different passed empty range");
		}
		return boole(different_(*it));
	}

	inline bool different_(any_a<> const& thing) const
	{
		return !same_(thing);
	}

	inline any_a<> hash__(range_a<> const& range) const
	{
		auto const op = _operations.at_string("hash");
		if (op)
		{
			any_a<> thing = me_();
			return op.operate(thing, range);
		}
		return number_uint_64_t<>::create(uint64_t(std::hash<void const*>{}(identity())));
	}

	inline number_data_a<uint64_t> hash_() const
	{
		auto const op = _operations.at_string("hash");
		if (op)
		{
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<number_data_a<uint64_t>>(result))
			{
				throw dis("<strange::any>::hash returned non-number-uint64");
			}
			return fast<number_data_a<uint64_t>>(result);
		}
		return number_uint_64_t<>::create(uint64_t(std::hash<void const*>{}(identity())));
	}

	inline std::size_t hash() const
	{
		auto const op = _operations.at_string("hash");
		if (op)
		{
			any_a<> thing = me_();
			auto const result = op.operate(thing, range_t<>::create_());
			if (!check<number_data_a<uint64_t>>(result))
			{
				throw dis("<strange::any>::hash returned non-number-uint64");
			}
			return fast<number_data_a<uint64_t>>(result).extract_primitive();
		}
		return std::hash<void const*>{}(identity());
	}

	// creature
	static inline any_a<> intimate__(range_a<> const& range)
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::intimate passed empty range");
		}
		any_a<> thing = fast_dup(*it);
		if (++it == range.extract_end_())
		{
			throw dis("<strange::any>::intimate passed short range");
		}
		any_a<> member = *it;
		return intimate(thing, member, range_t<>::create_(++it, range.extract_end_()));
	}

	static inline any_a<> intimate_(any_a<>& thing, range_a<> const& range)
	{
		auto it = range.extract_begin_();
		if (it == range.extract_end_())
		{
			throw dis("<strange::any>::intimate passed short range");
		}
		any_a<> member = *it;
		return intimate(thing, member, range_t<>::create_(++it, range.extract_end_()));
	}

	static inline any_a<> intimate(any_a<>& thing, any_a<> const& member, range_a<> const& range)
	{
		auto const& conception = static_cast<any_c<> const&>(thing.extract_thing())._conception;
		if (!conception.has_(member))
		{
			throw dis("<strange::any>::intimate passed non-existent member");
		}
		return conception.at_(member).operate(thing, range);
	}

	static inline any_a<> intimate_member(any_a<>& thing, any_a<> const& member)
	{
		auto const& conception = static_cast<any_c<> const&>(thing.extract_thing())._conception;
		if (!conception.has_(member))
		{
			throw dis("<strange::any>::intimate_member passed non-existent member");
		}
		return conception.at_(member);
	}

	inline void mutate_attribute(symbol_a<> const& name, operation_a<> const& attribute_mutation)
	{
		_conception.update_(name, attribute_mutation);
		if (name.first_character() != '_')
		{
			_operations.update_(name, attribute_mutation);
		}
	}

protected:
	shoal_a<> _conception;
	unordered_shoal_a<> _operations;

	// construction
	inline any_c(shoal_a<> const& conception)
		: one_t{}
		, _conception{ conception }
		, _operations{ _operations_(_conception) }
	{}

	static inline unordered_shoal_a<> _operations_(shoal_a<> const& conception)
	{
		unordered_shoal_a<> operations = ___ego___::___operations___();
		for (auto const& op : conception)
		{
			auto const flop = fast<flock_a<>>(op);
			auto const key = flop.at_index(0);
			if (!check<symbol_a<>>(key))
			{
				throw dis("<strange::any>::animate passed conception with non-symbol key");
			}
			if (fast<symbol_a<>>(key).first_character() == '_')
			{
				continue;
			}
			operations.update(key, flop.at_index(1));
		}
		return operations;
	}

private:
	static bool const ___share___;
	friend class ___any_c_share___;
};

template <typename ___ego___>
bool const any_c<___ego___>::___share___ = []()
{
	auto& shoal = shared();
	any_c<___ego___>::share(shoal);
	return shoal;
}();

class ___any_c_share___
{
	static inline bool ___share___()
	{
		return any_c<>::___share___;
	}
};

} // namespace strange

#endif
